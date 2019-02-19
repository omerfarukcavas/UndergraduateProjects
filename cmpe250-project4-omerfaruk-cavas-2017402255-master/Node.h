//
// Created by student on 07.12.2018.
//

#ifndef PROJECT4_NODE_H
#define PROJECT4_NODE_H


class Node {

public:

    int x,y;
    int height;
    int shortestLadder;

    Node();
    ~Node();

    bool operator>(const Node& rhs) const;

};


#endif //PROJECT4_NODE_H
