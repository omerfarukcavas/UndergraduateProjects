//
// Created by student on 09.11.2018.
//

#ifndef PROJECT2_CUSTOMER_H
#define PROJECT2_CUSTOMER_H

#include <iostream>
using namespace std;


class Customer {

public:

    int arrivalTime;
    int flightTime;
    int luggageServiceTime;
    int securityServiceTime;
    bool VIP;
    bool luggage;

    int CurrentService_1_time;
    int CurrentService_2_time;
    int DepartureTime; // kullanmadik




    Customer();
    Customer(int arrival_time,int flight_time,int luggage_service_time,int security_service_time,bool VIP,bool _luggage);
    ~Customer();
    Customer(const Customer& rhs);
    Customer&operator=(const Customer& rhs);

    bool operator<(const Customer& rhs) const;
    bool operator>(const Customer& rhs) const;


};


#endif //PROJECT2_CUSTOMER_H
