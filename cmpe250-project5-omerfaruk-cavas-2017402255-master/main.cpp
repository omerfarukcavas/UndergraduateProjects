#include <iostream>


#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include<iterator>
#include <algorithm>


using namespace std;


template <class Container>
void split1(const string& str, Container& cont)
{
    istringstream iss(str);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(cont));
}


int max=0; // final result

string message;
int numberOfWords;
string** dictionary;
long long int** functions; // if a rec function is found its value is stored
int numberOfWordsLetter[26]={0}; // number of words in each letter group

bool IsInDictionary(string x){  // hash yapilabilir

    //  unordered set  kullanilabilir

    int letter=x.at(0)-97;


    for(int i=0;i<numberOfWordsLetter[letter];i++){

        if(dictionary[letter][i]==x){
            return true;
        }

    }

    return false;
}

int FindWord(int startIndex,int finalIndex, int stringEnd){   // startindex; arama yapilacak string basi finalindex:ilkbakilacak kelimenin son indexi stringEnd: nereye kadar bakilacak

    int wordIndex=-1; //bulunan word un bittigi index.eger bulunamadi ise -1 dondur


    for(int i=finalIndex;i<=stringEnd;i++){  // 0 ve startindex arasindaki substring ten baslayip kelime ariyor

        if(IsInDictionary(message.substr(startIndex,i-startIndex))){
            wordIndex=i;
            return wordIndex;
        }


    }

    return wordIndex;
}




long long int MaxSentence(int i,int j){       // main function

    if(functions[i][j]!=-1){        // onceden bulunan aralik direkt array den
        return functions[i][j];
    }


    long long int x=0;  //number of words btw i and j ************

    int IndexFoundWord=i; // ilk bas i ve i+1 arasindaki harften aricak.kelime bulunca bulunan indexten devam edecek

    while(true){    // kelime arama

        IndexFoundWord=FindWord(i,IndexFoundWord+1,j);    // ilk kelimeyi bul
        if(IndexFoundWord==-1){ // kelime bulunamadi
            break;
        }
        if(IndexFoundWord==j){  // kelime aranan string in tamami ise
            x++;
            break;
        }
        x+=MaxSentence(IndexFoundWord,j)%1000000007;               // recursive function call

    }





    functions[i][j]=x;      // bulunan araligi array e yaz
    return x;
}



//  A-B-C-D-E-F-G-H-I-J-K-  L-  M-  N-  O-  P- Q- R- S-  T-  U-  V-  W-  X-  Y-  Z
//  0 1 2 3 4 5 6 7 8 9 10  11  12  13 14  15 16 17  18  19 20  21  22   23  24  25

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

    ifstream infile(argv[1]);


    infile>>message;        //message is received
  //  cout<<message<<endl;

    infile>>numberOfWords;
    cout << "number of words: " << numberOfWords << endl;

    dictionary=new string*[26]; // 0 1 2 .....25
    for(int p=0;p<26;p++){      // a b c      z
        dictionary[p]=new string[1000]; // her harf yerinde 0 dan 999 a kadar kelime yeri var
    }


    for(int i=0;i<numberOfWords;i++){   // words in dictionary are takens

        string word;
        infile>>word;
        int x=word[0]-97;       // a ise 0 a b ise 1  e
        dictionary[x][numberOfWordsLetter[x]]=word;
        numberOfWordsLetter[x]++; // arraye bir sonrakini koyacagim indis

    }

    functions= new long long int*[message.length()];  // function values are stored

    for(int i=0;i<message.length();i++){        // functions arrayindeki tum degerler sifir atandi
        functions[i]=new long long int[message.length()+1];
        fill_n(functions[i], message.length()+1, -1); // default -1 values are assigned
    }


    infile.close();
    cout << "input file has been read" << endl;


    long long int result=MaxSentence(0,message.length())%1000000007;
    cout<<result<<endl;

    ofstream myfile;
    myfile.open (argv[2]);

    myfile<<result;

    myfile.close();
    cout << "output file has been written" << endl;

    return 0;
}