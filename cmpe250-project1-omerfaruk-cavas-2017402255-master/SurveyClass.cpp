#include "SurveyClass.h"


SurveyClass::SurveyClass(){

    members= nullptr;

}
SurveyClass::SurveyClass(const SurveyClass& other){

    if(other.members){

        this->members=new LinkedList(*(other.members));

    }

}
SurveyClass& SurveyClass::operator=(const SurveyClass& list){


    if(list.members){

        delete this->members;
        this->members=new LinkedList(*(list.members));
    }
    return *this;
}
SurveyClass::SurveyClass(SurveyClass&& other){

    this->members = move(other.members);
    other.members= nullptr;


}
SurveyClass& SurveyClass::operator=(SurveyClass&& list){

    delete this->members;
    this->members = move(list.members);
    list.members= nullptr;
    return *this;

}
SurveyClass::~SurveyClass(){
    delete members;
}



void SurveyClass::handleNewRecord(string _name, float _amount){


    if(!members){       // first input is entered
        members=new LinkedList;

        members->head=new Node(_name,_amount);
        members->tail=members->head;
        members->length++;

       // members->pushTail(_name,_amount);

    }

    else if(members){       // other inputs

        Node*temp;
        temp=members->head;
        while(temp){

            if(_name==temp->name){
                members->updateNode(_name,_amount);
                break;
            }

            temp=temp->next;
        }

        if(!temp){  //if temp is null , it means no match is found. we should add to tail

            members->pushTail(_name,_amount);
            members->tail=(members->tail)->next;        // tail is updated

            members->length++;

        }



    }


}


float SurveyClass::calculateMinimumExpense(){

    Node*temp;
    temp=members->head;

    float min=temp->amount;
    temp=temp->next;



    while(temp)
    {
        if(temp->amount<min){
            min=temp->amount;
        }

        temp=temp->next;
    }

    min=min*100;
    int x=min;
    min=(float)x/100;


    return min;

};

float SurveyClass::calculateMaximumExpense(){

    Node*temp;
    temp=members->head;

    float max=temp->amount;
    temp=temp->next;



    while(temp)
    {
        if(temp->amount>max){
            max=temp->amount;
        }

        temp=temp->next;
    }

    max=max*100;
    int x=max;
    max=(float)x/100;



    return max;






};

float SurveyClass::calculateAverageExpense(){


    Node*temp;
    temp=members->head;

    float avg=0;


    while(temp)
    {
        avg+=temp->amount;
        temp=temp->next;
    }

    avg=avg/(members->length);

    // deleting after two decimals
    avg=avg*100;
    int x=avg;
    avg=(float)x/100;


    return avg;

};


