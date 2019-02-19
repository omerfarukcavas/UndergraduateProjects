//
// Created by student on 09.11.2018.
//

#ifndef PROJECT2_MANAGER_H
#define PROJECT2_MANAGER_H

#include <iostream>
#include "Customer.h"

using namespace std;



class Manager {

public:


    int NumberOfCustomers;
    int LuggageCounters;
    int SecurityCounters;


    int clock;

    int numberOfPersonsInTheSystem;         //to understand next arriving customer
    int numberofCustomersLeftTheSystem;     // to end simulation

    //Statistics

    int totalWaitingTime;
    double AvgWaitingTime;
    int numberOfPersonsLate;

    //final statistics
    double AvgWaitingTimes[8];
    int numberOfPersonsLates[8];


    Customer* Customers[5000];
    Customer* Luggages[20];
    Customer* Securities[20];


    Manager();
    Manager(int customers,int luggages,int securities);
    ~Manager();


    void CreateCustomers(int arrivalTime,int flightTime,int luggageServiceTime,int securityServiceTime,bool VIP,bool luggage,int index);
    void Run();
    void RunSimulation(bool FirstFlight,bool Vip, bool online );



};


#endif //PROJECT2_MANAGER_H
