
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include<iterator>

#include "Node.h"
#include <limits.h>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;


template <class Container>
void split1(const string& str, Container& cont)
{
    istringstream iss(str);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(cont));
}




int main(int argc, char* argv[]) {

    clock_t start;
    start = clock();


    // below reads the input file
    ios_base::sync_with_stdio(false);
    if (argc != 3) {
        cout << "Run the code with the following command: ./project1 [input_file] [output_file]" << endl;
        return 1;
    }

    cout << "input file: " << argv[1] << endl;
    cout << "output file: " << argv[2] << endl;



    // here, perform the input operation. in other words,
    // read the file named <argv[1]>

    ifstream infile(argv[1]);
    string line;
    vector<string> input;


    getline(infile, line);
    vector<string> words;
    split1(line,words);
    int numberOfRows= stoi(words[0]);
    int numberOfColumns = stoi(words[1]);

    cout << "number of rows: " << numberOfRows << endl;
    cout << "number of columns: " << numberOfColumns << endl;


    Node** Nodes=new Node*[numberOfRows+1];   //
    bool** isFixed=new bool*[numberOfRows+1];       // the nodes whose shortest paths are founded, fixed

    int count=0;

    for(int i=1;i<=numberOfRows;i++){

        Nodes[i]=new Node[numberOfColumns+1];
        isFixed[i]=new bool[numberOfColumns+1];


        getline(infile, line);
        vector<string> words;
        split1(line,words);

        for(int j=1;j<=numberOfColumns;j++){

            Nodes[i][j].x=i;
            Nodes[i][j].y=j;
            Nodes[i][j].height=stoi(words[j-1]);
            Nodes[i][j].shortestLadder=INT_MAX;
            isFixed[i][j]=false;
        }

    }

    getline(infile, line);
    vector<string> Words;
    split1(line,Words);

    int numberOfQuery=stoi(Words[0]);

    cout<< numberOfQuery<<endl;

    getline(infile, line);
    vector<string> WOrds;
    split1(line,WOrds);

    int sourceX=stoi(WOrds[0]);     // source ve target ters girildi sure kisaldi uzadigi da oldu
    int sourceY=stoi(WOrds[1]);


    int targetX=stoi(WOrds[2]);
    int targetY=stoi(WOrds[3]);

    cout<< sourceX<< " "<<sourceY<< " "<<targetX<<" "<<targetY;

    cout <<endl<< "input file has been read" << endl;

    cout << (clock() - start) / (double) CLOCKS_PER_SEC << ": finished reading input" << endl;

    // do what to do --------------------------------------------------------------------------------------------------


    priority_queue <Node,vector<Node>, greater<Node> > PQ;

    Nodes[sourceX][sourceY].shortestLadder=0;

    PQ.push(Nodes[sourceX][sourceY]);

    Node as=PQ.top();
    cout<<" source::"<<as.x<<" "<< as.y<<" "<<as.height<<" "<<as.shortestLadder;

    while(!PQ.empty()){


        if(isFixed[targetX][targetY]){
            break;
        }


        /*
        if(count==numberOfColumns*numberOfRows){
            cout<<endl<<"COUNT ENDED"<<endl;
            break;
        }

        */

        /*
        while(!PQ.empty() && isFixed[PQ.top().x][PQ.top().y]){     // birden cok kez PQ ya giren objeleri tekrar isleme sokma. PQ dan cikar

            //  cout<<endl<<PQ.top().x<<" "<<PQ.top().y << " ";
            //  cout<< endl<< isFixed[PQ.top().x][PQ.top().y] ;

            PQ.pop();
            //  kontrol++;
            // cout<<endl<<kontrol;

            if(!isFixed[PQ.top().x][PQ.top().y]){
                break;
            }
        }

        */



        Node temp=PQ.top();
        PQ.pop();

        isFixed[temp.x][temp.y]=true;

        /*
        if(!isFixed[temp.x][temp.y]){   // normalde her turlu fix lemek gererkiyor. birden cok giren zaaten fixlenmis. count saymak icin yaptik
            count++;
            isFixed[temp.x][temp.y]=true;
        }
        */

        if(temp.x+1<=numberOfColumns && temp.x+1>=1){  // bir sagda biri varsa

            if(max(abs(temp.height-Nodes[temp.x+1][temp.y].height),temp.shortestLadder)<Nodes[temp.x+1][temp.y].shortestLadder){

                Nodes[temp.x+1][temp.y].shortestLadder=max(abs(temp.height-Nodes[temp.x+1][temp.y].height),temp.shortestLadder);
                PQ.push(Nodes[temp.x+1][temp.y]);
            }

        }

        if(temp.x-1<=numberOfColumns && temp.x-1>=1){       // bir solda biri varsa

            if(max(abs(temp.height-Nodes[temp.x-1][temp.y].height),temp.shortestLadder)<Nodes[temp.x-1][temp.y].shortestLadder){

                Nodes[temp.x-1][temp.y].shortestLadder=max(abs(temp.height-Nodes[temp.x-1][temp.y].height),temp.shortestLadder);
                PQ.push(Nodes[temp.x-1][temp.y]);
            }

        }


        if(temp.y+1<=numberOfRows && temp.y+1>=1){       // bir yukarida biri varsa

            if(max(abs(temp.height-Nodes[temp.x][temp.y+1].height),temp.shortestLadder)<Nodes[temp.x][temp.y+1].shortestLadder){

                Nodes[temp.x][temp.y+1].shortestLadder=max(abs(temp.height-Nodes[temp.x][temp.y+1].height),temp.shortestLadder);
                PQ.push(Nodes[temp.x][temp.y+1]);
            }

        }


        if(temp.y-1<=numberOfRows && temp.y-1>=1){       // bir asagida biri varsa

            if(max(abs(temp.height-Nodes[temp.x][temp.y-1].height),temp.shortestLadder)<Nodes[temp.x][temp.y-1].shortestLadder){

                Nodes[temp.x][temp.y-1].shortestLadder=max(abs(temp.height-Nodes[temp.x][temp.y-1].height),temp.shortestLadder);
                PQ.push(Nodes[temp.x][temp.y-1]);
            }

        }



    }


    // do what to do --------------------------------------------------------------------------------------------------


    cout<<endl<<Nodes[targetX][targetY].shortestLadder;

    ofstream myfile;
    myfile.open (argv[2]);

    myfile<<Nodes[targetX][targetY].shortestLadder;

    myfile.close();

    cout << endl<<"output file has been written" << endl;


    return 0;
}