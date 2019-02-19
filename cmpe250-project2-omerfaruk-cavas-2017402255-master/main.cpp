#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include<iterator>

#include "Manager.h"


using namespace std;



int main(int argc, char* argv[]) {
    // below reads the input file
    clock_t start;

    start = clock();

    if (argc != 3) {
        cout << "Run the code with the following command: ./project1 [input_file] [output_file]" << endl;
        return 1;
    }

    cout << "input file: " << argv[1] << endl;
    cout << "output file: " << argv[2] << endl;


    // here, perform the input operation. in other words,
    // read the file named <argv[1]>

    ifstream infile(argv[1]);

    int NumberOfCustomers;

    int LuggageCounters;

    int SecurityCounters;

    infile >> NumberOfCustomers;
    infile >> LuggageCounters;
    infile >> SecurityCounters;


    cout << "number of customers: " << NumberOfCustomers << endl;
    cout << "number of luggage counters: " << LuggageCounters << endl;
    cout << "number of security counters: " << SecurityCounters << endl;

    Manager MyManager(NumberOfCustomers,LuggageCounters,SecurityCounters);


    for (int i=0; i<NumberOfCustomers; i++) {


        int arrival;
        int flight;
        int luggageService;
        int securityService;
        char VIP;
        char luggage;

        infile >> arrival;
        infile >> flight;
        infile >> luggageService;
        infile >> securityService;
        infile >> VIP;
        infile >> luggage;


        MyManager.CreateCustomers(arrival,flight,luggageService,securityService,VIP=='V',luggage=='L',i);

      //  cout <<i<< "th customer :"<< MyManager.Customers[i]->arrivalTime <<" "<< MyManager.Customers[i]->flightTime<<" " << MyManager.Customers[i]->luggageServiceTime<<" " <<MyManager.Customers[i]->securityServiceTime<<" " <<MyManager.Customers[i]->VIP <<" "<<MyManager.Customers[i]->luggage<<" " <<endl;

    }
    infile.close();
    cout << "input file has been read" << endl;

     MyManager.Run();

    // here, perform the output operation. in other words,
    // print your results into the file named <argv[2]>
    ofstream myfile;
    myfile.open (argv[2]);

    cout << MyManager.AvgWaitingTimes[0] << " " << MyManager.numberOfPersonsLates[0] << endl;
    myfile << MyManager.AvgWaitingTimes[0] << " " << MyManager.numberOfPersonsLates[0] << " "<<endl;

    cout << MyManager.AvgWaitingTimes[1] << " " << MyManager.numberOfPersonsLates[1] << endl;
    myfile << MyManager.AvgWaitingTimes[1] << " " << MyManager.numberOfPersonsLates[1] << " "<<endl;

    cout << MyManager.AvgWaitingTimes[2] << " " << MyManager.numberOfPersonsLates[2] << endl;
    myfile << MyManager.AvgWaitingTimes[2] << " " << MyManager.numberOfPersonsLates[2] << " "<<endl;

    cout << MyManager.AvgWaitingTimes[3] << " " << MyManager.numberOfPersonsLates[3] << endl;
    myfile << MyManager.AvgWaitingTimes[3] << " " << MyManager.numberOfPersonsLates[3] << " "<<endl;

    cout << MyManager.AvgWaitingTimes[4] << " " << MyManager.numberOfPersonsLates[4] << endl;
    myfile << MyManager.AvgWaitingTimes[4] << " " << MyManager.numberOfPersonsLates[4] << " "<<endl;

    cout << MyManager.AvgWaitingTimes[5] << " " << MyManager.numberOfPersonsLates[5] << endl;
    myfile << MyManager.AvgWaitingTimes[5] << " " << MyManager.numberOfPersonsLates[5] << " "<<endl;

    cout << MyManager.AvgWaitingTimes[6] << " " << MyManager.numberOfPersonsLates[6] << endl;
    myfile << MyManager.AvgWaitingTimes[6] << " " << MyManager.numberOfPersonsLates[6] << " "<<endl;

    cout << MyManager.AvgWaitingTimes[7] << " " << MyManager.numberOfPersonsLates[7] << endl;
    myfile << MyManager.AvgWaitingTimes[7] << " " << MyManager.numberOfPersonsLates[7] << " "<<endl;


    //cout << avg1 << " " << late1 << endl;
    //myfile << avg1 << " " << late1 << " "<<endl;



    myfile.close();

    cout << "output file has been written" << endl;
    cout << "time: " << (clock() - start) / ((double) (CLOCKS_PER_SEC)) << endl;


    return 0;
}