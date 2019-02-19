//
// Created by student on 09.11.2018.
//

#include "Customer.h"

Customer::Customer() {

     arrivalTime=0;
     flightTime=0;
     luggageServiceTime=0;
     securityServiceTime=0;
     VIP=0;
     luggage=0;


}

Customer::Customer(int arrival_time,int flight_time,int luggage_service_time,int security_service_time,bool _VIP,bool _luggage) {

    arrivalTime=arrival_time;
    flightTime=flight_time;
    luggageServiceTime=luggage_service_time;
    securityServiceTime=security_service_time;
    VIP=_VIP;
    luggage=_luggage;

     CurrentService_1_time=0;
     CurrentService_2_time=0;
     DepartureTime=0;



}

Customer::~Customer() {}

Customer::Customer(const Customer& rhs){

    this->arrivalTime=rhs.arrivalTime;
    this->flightTime=rhs.flightTime;
    this->luggageServiceTime=rhs.luggageServiceTime;
    this->securityServiceTime=rhs.securityServiceTime;
    this->VIP=rhs.VIP;
    this->luggage=rhs.luggage;

    this->CurrentService_1_time=rhs.CurrentService_1_time;
    this->CurrentService_2_time=rhs.CurrentService_2_time;
    this->DepartureTime=rhs.DepartureTime;

}

Customer&Customer::operator=(const Customer& rhs){


    this->arrivalTime=rhs.arrivalTime;
    this->flightTime=rhs.flightTime;
    this->luggageServiceTime=rhs.luggageServiceTime;
    this->securityServiceTime=rhs.securityServiceTime;
    this->VIP=rhs.VIP;
    this->luggage=rhs.luggage;

    this->CurrentService_1_time=rhs.CurrentService_1_time;
    this->CurrentService_2_time=rhs.CurrentService_2_time;
    this->DepartureTime=rhs.DepartureTime;

    return *this;
}

bool Customer::operator<(const Customer& rhs) const{        // luggage ve securty den ayni anda cikan max heap -> mean heap

    // if(this->flightTime==rhs.flightTime){
        return (this->arrivalTime)>rhs.arrivalTime;
    /*}
    else{
        return (this->flightTime)<rhs.flightTime;
    }*/

}

bool Customer::operator>(const Customer& rhs) const{        // PQ1 ve PQ2 icin yapilan min heap te kullanilacak

    if(this->flightTime==rhs.flightTime){
        return (this->arrivalTime)>rhs.arrivalTime;
    }
    else{
        return (this->flightTime)>rhs.flightTime;
    }
}


