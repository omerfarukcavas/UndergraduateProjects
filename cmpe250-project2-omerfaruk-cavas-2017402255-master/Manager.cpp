//
// Created by student on 09.11.2018.
//

#include "Manager.h"
#include <queue>

Manager::Manager() {

    NumberOfCustomers=0;
    LuggageCounters=0;
    SecurityCounters=0;
    clock=0;
}

Manager::Manager(int customers,int luggages,int securities) {

    NumberOfCustomers=customers;
    LuggageCounters=luggages;
    SecurityCounters=securities;

    clock=0;

    numberOfPersonsInTheSystem=0;
    numberofCustomersLeftTheSystem=0;



    totalWaitingTime=0;
    AvgWaitingTime=0;
    numberOfPersonsLate=0;

    int i;
    for(i=0;i<20;i++){
        Luggages[i]= nullptr;
        Securities[i]= nullptr;
    }





}

Manager::~Manager() {

    int i;
    for(i=0;i<NumberOfCustomers;i++){
        delete Customers[i];
    }


}


void Manager::CreateCustomers(int arrivalTime,int flightTime,int luggageServiceTime,int securityServiceTime,bool VIP,bool luggage,int index) {

    Customers[index]=new Customer(arrivalTime,flightTime,luggageServiceTime,securityServiceTime,VIP,luggage);

}

void Manager::Run(){


    // --------------------------------------  0
    RunSimulation(false,false,false);
    AvgWaitingTimes[0]=AvgWaitingTime;
    numberOfPersonsLates[0]=numberOfPersonsLate;

    totalWaitingTime=0;
    AvgWaitingTime=0;
    numberOfPersonsLate=0;

    clock=0;
    numberOfPersonsInTheSystem=0;
    numberofCustomersLeftTheSystem=0;

    int i;

    for(i=0;i<NumberOfCustomers;i++){

        Customers[i]->CurrentService_1_time=0;
        Customers[i]->CurrentService_2_time=0;

    }


    // --------------------------------------  1
    RunSimulation(true,false,false);

    AvgWaitingTimes[1]=AvgWaitingTime;
    numberOfPersonsLates[1]=numberOfPersonsLate;

    totalWaitingTime=0;
    AvgWaitingTime=0;
    numberOfPersonsLate=0;

    clock=0;
    numberOfPersonsInTheSystem=0;
    numberofCustomersLeftTheSystem=0;



    for(i=0;i<NumberOfCustomers;i++){

        Customers[i]->CurrentService_1_time=0;
        Customers[i]->CurrentService_2_time=0;

    }

    // --------------------------------------  2

    RunSimulation(false,true,false);


    AvgWaitingTimes[2]=AvgWaitingTime;
    numberOfPersonsLates[2]=numberOfPersonsLate;

    totalWaitingTime=0;
    AvgWaitingTime=0;
    numberOfPersonsLate=0;

    clock=0;
    numberOfPersonsInTheSystem=0;
    numberofCustomersLeftTheSystem=0;



    for(i=0;i<NumberOfCustomers;i++){

        Customers[i]->CurrentService_1_time=0;
        Customers[i]->CurrentService_2_time=0;

    }

    // --------------------------------------  3


    RunSimulation(true,true,false);

    AvgWaitingTimes[3]=AvgWaitingTime;
    numberOfPersonsLates[3]=numberOfPersonsLate;

    totalWaitingTime=0;
    AvgWaitingTime=0;
    numberOfPersonsLate=0;

    clock=0;
    numberOfPersonsInTheSystem=0;
    numberofCustomersLeftTheSystem=0;



    for(i=0;i<NumberOfCustomers;i++){

        Customers[i]->CurrentService_1_time=0;
        Customers[i]->CurrentService_2_time=0;

    }

    // --------------------------------------  4


    RunSimulation(false,false,true);

    AvgWaitingTimes[4]=AvgWaitingTime;
    numberOfPersonsLates[4]=numberOfPersonsLate;

    totalWaitingTime=0;
    AvgWaitingTime=0;
    numberOfPersonsLate=0;

    clock=0;
    numberOfPersonsInTheSystem=0;
    numberofCustomersLeftTheSystem=0;



    for(i=0;i<NumberOfCustomers;i++){

        Customers[i]->CurrentService_1_time=0;
        Customers[i]->CurrentService_2_time=0;

    }

    // --------------------------------------  5

    RunSimulation(true,false,true);

    AvgWaitingTimes[5]=AvgWaitingTime;
    numberOfPersonsLates[5]=numberOfPersonsLate;

    totalWaitingTime=0;
    AvgWaitingTime=0;
    numberOfPersonsLate=0;

    clock=0;
    numberOfPersonsInTheSystem=0;
    numberofCustomersLeftTheSystem=0;



    for(i=0;i<NumberOfCustomers;i++){

        Customers[i]->CurrentService_1_time=0;
        Customers[i]->CurrentService_2_time=0;

    }

    // --------------------------------------  6

    RunSimulation(false,true,true);

    AvgWaitingTimes[6]=AvgWaitingTime;
    numberOfPersonsLates[6]=numberOfPersonsLate;

    totalWaitingTime=0;
    AvgWaitingTime=0;
    numberOfPersonsLate=0;

    clock=0;
    numberOfPersonsInTheSystem=0;
    numberofCustomersLeftTheSystem=0;



    for(i=0;i<NumberOfCustomers;i++){

        Customers[i]->CurrentService_1_time=0;
        Customers[i]->CurrentService_2_time=0;

    }

    // --------------------------------------  7

    RunSimulation(true,true,true);

    AvgWaitingTimes[7]=AvgWaitingTime;
    numberOfPersonsLates[7]=numberOfPersonsLate;

    totalWaitingTime=0;
    AvgWaitingTime=0;
    numberOfPersonsLate=0;

    clock=0;
    numberOfPersonsInTheSystem=0;
    numberofCustomersLeftTheSystem=0;



    for(i=0;i<NumberOfCustomers;i++){

        Customers[i]->CurrentService_1_time=0;
        Customers[i]->CurrentService_2_time=0;

    }



}
void Manager::RunSimulation(bool FirstFlight,bool Vip, bool online ){

        // firstflight varsa asagida bunlar cagrilacak
        priority_queue <Customer,vector<Customer>, greater<Customer> > PQ1;     // Asagida queue dan cikarma ve eklemlerde PQ ve Q icin ayri kod yazilacak
        priority_queue <Customer,vector<Customer>, greater<Customer> > PQ2;

        // ..yoksa bunlar
        queue <Customer> Q1;
        queue <Customer> Q2;


    while(true) {


        //  first event in Security  is calculated---------------------------------------------------

        int MinOfSecurity = 50001;

        int i;
        for (i = 0; i < SecurityCounters; i++) {

            if (Securities[i] != nullptr) {
               // cout<<"**************";
                if (MinOfSecurity > Securities[i]->securityServiceTime - Securities[i]->CurrentService_2_time) {

                    MinOfSecurity = Securities[i]->securityServiceTime - Securities[i]->CurrentService_2_time;

                }
            }

        }

        //  first event in luggage  is calculated-------------------------------------------------------

        int MinOfLuggage = 50001;


        int j;
        for (j = 0; j < LuggageCounters; j++) {

            if (Luggages[j] != nullptr) {
                // cout<<"***************/";
                if (MinOfLuggage > Luggages[j]->luggageServiceTime - Luggages[j]->CurrentService_1_time) {

                    MinOfLuggage = Luggages[j]->luggageServiceTime - Luggages[j]->CurrentService_1_time;

                }
            }

        }

        // first next arrival is calculated
        int abidin=numberOfPersonsInTheSystem;

        int MinNextArrival;
        if(numberOfPersonsInTheSystem==NumberOfCustomers){      // sistemde son kisi varken bir sonraki arrival a bakma
            MinNextArrival=500001;
        }
        else{
            MinNextArrival = Customers[numberOfPersonsInTheSystem]->arrivalTime - clock;        // array sifirdan basladigi icin arrayde 0.kisi aslinda 1 inci kisi.

        }


        // TIME AT WHICH CLOCK WILL BE PROGRESSED IS CALCULATED-------------------------------

        int TimeProgress = 0;     // how much clock will be progressed


        if ( MinOfSecurity <= MinOfLuggage && MinOfSecurity <= MinNextArrival) {
            //cout<<"--------------";

            TimeProgress = MinOfSecurity;
        } else if ( MinOfLuggage <= MinOfSecurity && MinOfLuggage <= MinNextArrival) {
            //cout<<"***************";
            TimeProgress = MinOfLuggage;
        } else {
            TimeProgress = MinNextArrival;

        }


        clock += TimeProgress;

        //cout << "Time Progress " << TimeProgress << endl;
        //cout << "Clock " << clock << endl;


        // Updates for next time

        int x;

        for (x = 0; x < SecurityCounters; x++) {

            if (Securities[x] != nullptr) {

                Securities[x]->CurrentService_2_time += TimeProgress;

            }

        }

        int y;

        for (y = 0; y < LuggageCounters; y++) {

            if (Luggages[y] != nullptr) {

                Luggages[y]->CurrentService_1_time += TimeProgress;

            }

        }


        // When the time progress is made , events will happen


        //  1)  Departure from Security---------

        int a;

        priority_queue<Customer> pq;


        for (a = 0; a < SecurityCounters; a++) {

            if (Securities[a] != nullptr &&
                Securities[a]->CurrentService_2_time == Securities[a]->securityServiceTime) {

                pq.push(*Securities[a]);    // servis suresi biten objeleri arrival time i erken olana gore pq ya soktuk
                Securities[a] = nullptr;     // cikan objeler security de  null olacak.
                // bundan once secirty nin tuttugu obje silinebilir memory leak olmasin diye!!
            }

        }


        while (pq.empty() == false) {

            totalWaitingTime += clock - pq.top().arrivalTime;
            if (pq.top().flightTime < clock) {
                numberOfPersonsLate++;
            }
            numberofCustomersLeftTheSystem++;

            pq.pop();

        }


        // Departure from security sonrasi PQ2 yi kontrol edip security e sokma

        int indexForNullptr;

        if (FirstFlight) {    // PQ2 den cikar

            if (PQ2.empty() == false) {

                for (indexForNullptr = 0; indexForNullptr < SecurityCounters; indexForNullptr++) {

                    if (Securities[indexForNullptr] == nullptr && PQ2.empty() == false) {    // tum null security lerde dolasacam eger pq2 bossa cikartmaya calismicam

                        Customer temp = PQ2.top();
                        Securities[indexForNullptr] = new Customer(temp);
                        PQ2.pop();
                        // break;  birden cok yer bossa birden cok customer girer
                    }

                }

            }


        } else {       //Q2 den cikar

            if (Q2.empty() == false) {

                for (indexForNullptr = 0; indexForNullptr < SecurityCounters; indexForNullptr++) {

                    if (Securities[indexForNullptr] == nullptr && Q2.empty() == false) {

                        Customer temp = Q2.front();
                        Securities[indexForNullptr] = new Customer(temp);
                        Q2.pop();
                        // break;
                    }

                }

            }


        }


        //  2)  Departure from Luggage---------


        int b;

        priority_queue<Customer> pqL;      // luggage den cikanlari koydugum pq


        for (b = 0; b < LuggageCounters; b++) {

            if (Luggages[b] != nullptr && Luggages[b]->CurrentService_1_time == Luggages[b]->luggageServiceTime) {

                pqL.push(*Luggages[b]);    // servis suresi biten objeleri arrival time i erken olana gore pq ya soktuk
                Luggages[b] = nullptr;     // cikan objeler security de  null olacak.

            }

        }

        while (pqL.empty() == false) {      // luggage den cikan objeler 3 e ayrilir, hespi icin kontrol edildi


            if (pqL.top().VIP && Vip) {       // adam vip ve vip uygulaniyorsa direkt cikacak

                totalWaitingTime += clock - pqL.top().arrivalTime;
                if (pqL.top().flightTime < clock) {
                    numberOfPersonsLate++;
                }
                numberofCustomersLeftTheSystem++;
                pqL.pop();
            } else {      // adam vip degilse veya vip yoksa

                int i;
                bool CustomerEnterSecurity = false;
                for (i = 0; i < SecurityCounters; i++) {        // securityde yer varsa security e girecek

                    if (Securities[i] == nullptr) {

                        Customer temp = pqL.top();
                        Securities[i] = new Customer(temp);
                        pqL.pop();
                        CustomerEnterSecurity = true;
                        break;

                    }

                }

                if (CustomerEnterSecurity == false) {        // security de yer yoksa PQ2 ye girecek


                    if (FirstFlight) {

                        PQ2.push(pqL.top());
                        pqL.pop();
                    } else {

                        Q2.push(pqL.top());
                        pqL.pop();
                    }

                }


            }


        }


        // Departure from luggage den sonra PQ1 de birileri varsa luggage ye girecek (luggage de birden cok yer olabilir ve/ya pq1 de bekleyen birden cok kisi olabilir)

        int indexForNullptrLuggage;

        if (FirstFlight) {    // PQ1 den cikar

            if (PQ1.empty() == false) {

                for (indexForNullptrLuggage = 0; indexForNullptrLuggage < LuggageCounters; indexForNullptrLuggage++) {

                    if (Luggages[indexForNullptrLuggage] == nullptr && PQ1.empty() == false) {

                        Customer temp = PQ1.top();
                        Luggages[indexForNullptrLuggage] = new Customer(temp);
                        PQ1.pop();

                    }

                }

            }


        } else {       //Q1 den cikar

            if (Q1.empty() == false) {

                for (indexForNullptrLuggage = 0; indexForNullptrLuggage < LuggageCounters; indexForNullptrLuggage++) {

                    if (Luggages[indexForNullptrLuggage] == nullptr && Q1.empty() == false) {

                        Customer temp = Q1.front();
                        Luggages[indexForNullptrLuggage] = new Customer(temp);
                        Q1.pop();

                    }

                }

            }


        }



        // 3) Arrival

        if(numberOfPersonsInTheSystem!=NumberOfCustomers){      // son eleman girince bu yeni arrival kontrol etmicez

            if (Customers[numberOfPersonsInTheSystem]->arrivalTime ==
                clock) {      // numberOfPersonsInTheSystem: sisteme gelecek yeni kisinin indexi(index sifirdan basladigi icin)

                if (online &&
                    Customers[numberOfPersonsInTheSystem]->luggage == false) {       //Online var, adamda luggage yok


                    if (Customers[numberOfPersonsInTheSystem]->VIP && Vip) {         // direkt sistemden cikacak

                        //totalWaitingTime += clock - Customers[numberOfPersonsInTheSystem]->arrivalTime;
                        if (Customers[numberOfPersonsInTheSystem]->flightTime < clock) {
                            numberOfPersonsLate++;
                        }
                        numberofCustomersLeftTheSystem++;


                    } else {

                        int i;
                        bool CustomerEnterSecurity = false;
                        for (i = 0; i < SecurityCounters; i++) {        // securityde yer varsa security e girecek

                            if (Securities[i] == nullptr) {

                                Securities[i] = new Customer(*Customers[numberOfPersonsInTheSystem]);
                                CustomerEnterSecurity = true;
                                break;

                            }

                        }

                        if (CustomerEnterSecurity == false) {        // security de yer yoksa PQ2 ye girecek


                            if (FirstFlight) {

                                PQ2.push(*Customers[numberOfPersonsInTheSystem]);

                            } else {

                                Q2.push(*Customers[numberOfPersonsInTheSystem]);

                            }

                        }


                    }


                } else {


                    int i;
                    bool CustomerEnterLuggage = false;
                    for (i = 0; i < LuggageCounters; i++) {        // luggage de yer varsa luggage e girecek

                        if (Luggages[i] == nullptr) {

                            Luggages[i] = new Customer(*Customers[numberOfPersonsInTheSystem]);
                            CustomerEnterLuggage = true;
                            break;

                        }

                    }

                    if (CustomerEnterLuggage == false) {        // luggage de yer yoksa PQ1 e girecek


                        if (FirstFlight) {

                            PQ1.push(*Customers[numberOfPersonsInTheSystem]);

                        } else {

                            Q1.push(*Customers[numberOfPersonsInTheSystem]);

                        }

                    }


                }


                numberOfPersonsInTheSystem++;       // arrival oldu .
            }

        }





        if(numberofCustomersLeftTheSystem>=NumberOfCustomers){

            AvgWaitingTime=(double)totalWaitingTime/NumberOfCustomers;


            break;
        }

    }




}


