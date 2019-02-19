#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include<iterator>

#include "Manager.h"


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
    // process first line
    /* getline(infile, line);
    int N = stoi(line);
    cout << "number of input lines: " << N << endl;     */

    getline(infile, line);
    vector<string> words;
    split1(line,words);
    int NumberOfNodes= stoi(words[0]);


    cout << "number of nodes: " << NumberOfNodes << endl;


    Manager MyManager(NumberOfNodes);
    MyManager.CreateNodes();

    for (int i=1; i<=NumberOfNodes; i++) {  // 1.indexten basliyoz input ona gore
        getline(infile, line);
        vector<string> words;
        split1(line,words);

        int NumberOfTos=stoi(words[0]); // to sayisi
        //cout<<NumberOfTos<<" ";

        MyManager.NumberOfToosArray[i]=NumberOfTos;
        //cout<< MyManager.NumberOfToosArray[i]<<" ";
        int j,k ;// j for stoi and k for temp

        MyManager.AdjList[i] =new int[NumberOfTos];


        for(j=1,k=0;j<=NumberOfTos;j++,k++){

            int to=stoi(words[j]);
            (MyManager.AdjList[i])[k]=to;
           // cout<<(MyManager.AdjList[i])[k]<<" ";
        }

        //cout<<endl;

    }
    cout << "input file has been read" << endl;

    MyManager.findSccs();


    // here, perform the output operation. in other words,
    // print your results into the file named <argv[2]>
    ofstream myfile;
    myfile.open (argv[2]);

    /*
    for(int a=1;a<=NumberOfNodes;a++){
        cout<<MyManager.LowLinkArray[a]<<" ";
    }
    */

    /*
    for(int b=0;b<MyManager.sccCount;b++){
        if(MyManager.BreakLowLinks[b]!=-1){
            MyManager.numberOfBrokenNodes++;
        }
    }

    myfile<<MyManager.numberOfBrokenNodes<<" ";

 //   cout<<MyManager.sccCount<<endl;

    for(int c=0;c<MyManager.sccCount;c++){
        if(MyManager.BreakLowLinks[c]!=-1){
            myfile<<MyManager.BreakNodes[c]<<" ";
        }

    }
    */

    for(int b=1;b<=MyManager.numberOfNodes;b++){
        if(MyManager.FinalBreakNodes[b]==true){
            MyManager.numberOfBrokenNodes++;
        }
    }

    myfile<<MyManager.numberOfBrokenNodes<<" ";

    for(int c=1;c<=MyManager.numberOfNodes;c++){
        if(MyManager.FinalBreakNodes[c]==true){
            myfile<<c<<" ";
        }
    }



    myfile.close();

    cout << "output file has been written" << endl;


    return 0;
}