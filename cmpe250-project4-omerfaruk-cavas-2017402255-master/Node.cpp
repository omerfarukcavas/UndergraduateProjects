//
// Created by student on 07.12.2018.
//

#include "Node.h"

Node::Node() {
    x=0;
    y=0;
    height=0;
    shortestLadder=0;
}

Node::~Node() {

}



bool Node::operator>(const Node& rhs) const{

    return shortestLadder>rhs.shortestLadder;

}