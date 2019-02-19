//
// Created by student on 21.11.2018.
//

#ifndef PROJECT3_MANAGER_H
#define PROJECT3_MANAGER_H

#include <iostream>
#include <stack>

using namespace std;


class Manager {

public:


    int numberOfNodes;

    int** AdjList;


  //  unordered_set<int> keys[]:

    int* NumberOfToosArray;  // herbir node un to sayisini tutan array
    int* IDsArray;
    int* LowLinkArray;
    bool* OnStackArray;

 //   int* BreakLowLinks;  // LowLinksofNodesToBeBrokenArray.
 //   int* BreakNodes;  // nodesToBeBrokenArray.

    bool* FinalBreakNodes;  // breakORnot
    int* arrayTemp;

    int id;
    int sccCount;
    int numberOfBrokenNodes;

    stack <int> s;


    Manager(int noOfNodes);

    ~Manager();

    void CreateNodes();

    void findSccs();

    void dfs(int at);



};


#endif //PROJECT3_MANAGER_H
