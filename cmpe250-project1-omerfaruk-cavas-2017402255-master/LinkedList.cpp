#include "LinkedList.h"

LinkedList::LinkedList(){

    this->length=0;
    this->head= nullptr;
    this->tail= nullptr;

}

LinkedList::LinkedList(const LinkedList &list) {


    this->length=list.length;
    if(list.head){
        this->head = new Node(*(list.head));

    }

    if(list.tail){
        this->tail=new Node(*(list.tail));

    }

}

LinkedList& LinkedList::operator=(const LinkedList& list){


    this->length=list.length;

    if(list.head) {
        delete this->head;
        this->head = new Node(*(list.head));
    }

    if(list.tail) {
        delete this->tail;
        this->tail = new Node(*(list.tail));
    }


    return *this;

}

LinkedList::LinkedList(LinkedList&& list){


    this->length = move(list.length);
    this->head = move(list.head);
    this->tail = move(list.tail);

    list.length =0;
    list.head= nullptr;
    list.tail= nullptr;


}


LinkedList& LinkedList::operator=(LinkedList&& list){
    this->length = move(list.length);
    delete this->head;
    this->head = move(list.head);
    delete this->tail;
    this->tail=move(list.tail);

    list.length = 0;
    list.head = nullptr;
    list.tail= nullptr;
    return *this;
}

void LinkedList::pushTail(string _name, float _amount){

    (this->tail)->next=new Node(_name,_amount);

}

void LinkedList::updateNode(string _name, float _amount){


    Node*temp;
    temp=this->head;
    while(temp){

        if(_name==temp->name){
            temp->amount=_amount;

            break;
        }

        temp=temp->next;
    }



}


LinkedList::~LinkedList(){

    if(this->head){
        delete this->head;
    }
}









