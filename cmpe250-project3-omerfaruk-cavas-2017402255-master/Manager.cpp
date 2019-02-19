//
// Created by student on 21.11.2018.
//

#include <cstddef>
#include "Manager.h"


Manager::Manager(int noOfNodes) {
    numberOfNodes = noOfNodes;

    AdjList = nullptr;
    NumberOfToosArray = nullptr;  // herbir node un to sayisini tutan array
    IDsArray = nullptr;
    LowLinkArray = nullptr;
    OnStackArray = nullptr;
    id = 1;
    sccCount = 0;
    numberOfBrokenNodes = 0;
    //  BreakLowLinks= nullptr;
    //  BreakNodes= nullptr;
    FinalBreakNodes = nullptr;

}

Manager::~Manager() {

}

void Manager::CreateNodes() {

    AdjList = new int *[numberOfNodes + 1];    // int* tutan bir array.

    NumberOfToosArray = new int[numberOfNodes + 1];
    IDsArray = new int[numberOfNodes + 1];
    LowLinkArray = new int[numberOfNodes + 1];
    OnStackArray = new bool[numberOfNodes + 1];

    for (int i = 1; i <= numberOfNodes; i++) {

        OnStackArray[i] = false;

    }


//    BreakLowLinks=new int[numberOfNodes]; // max number of nodes broken is number of nodes
//    BreakNodes=new int[numberOfNodes];       // max number of nodes broken is number of nodes

    FinalBreakNodes = new bool[numberOfNodes + 1];

    for (int j = 1; j <= numberOfNodes; j++) {

        FinalBreakNodes[j] = false;

    }

    arrayTemp = new int[numberOfNodes + 1];     // to reach from lowlinks to roots



}

void Manager::findSccs() {
    int i;

    for (i = 1; i <= numberOfNodes; i++) {

        IDsArray[i] = -1; // unvisited

    }

    for (i = 1; i <= numberOfNodes; i++) {
        if (IDsArray[i] == -1) {
            dfs(i);

        }

    }


}

void Manager::dfs(int at) {

    s.push(at);
    OnStackArray[at] = true;
    IDsArray[at] = id;
    LowLinkArray[at] = id;
    id++;

    // Visit all neighbours & min low-link on call back

    int i;
    for (i = 0; i < NumberOfToosArray[at]; i++) {

        //   UPDATE ------------------------------------------------------

        if (OnStackArray[AdjList[at][i]] == false && IDsArray[AdjList[at][i]] != -1) {

            FinalBreakNodes[arrayTemp[LowLinkArray[AdjList[at][i]]]] = false;

            /*
            for(int j=0;j<sccCount;j++){
                if(LowLinkArray[AdjList[at][i]]==BreakLowLinks[j]){
                    BreakLowLinks[j]=-1;

                    break;
                }

            }

            */

        }



        //   UPDATE ------------------------------------------------------





        if (IDsArray[(AdjList[at])[i]] == -1) {            // to= AdjList[at][i]
            dfs(AdjList[at][i]);

            //   UPDATE ------------------------------------------------------

            if (OnStackArray[AdjList[at][i]] == false &&
                IDsArray[AdjList[at][i]] != -1) {    // asagidaki for silinecek duzenelenecek

                FinalBreakNodes[arrayTemp[LowLinkArray[AdjList[at][i]]]] = false;



                /*
                for(int j=0;j<sccCount;j++){
                    if(LowLinkArray[AdjList[at][i]]==BreakLowLinks[j]){
                        BreakLowLinks[j]=-1;

                        break;
                    }

                }
                */
            }

            //   UPDATE ------------------------------------------------------

        }

        if (OnStackArray[AdjList[at][i]]) {       // when call back is being executed

            if (LowLinkArray[at] >=
                LowLinkArray[AdjList[at][i]]) {    // to daki low link kucukse at deki to dakine esit olur
                LowLinkArray[at] = LowLinkArray[AdjList[at][i]];
            }

        }

    }


    if (IDsArray[at] == LowLinkArray[at]) {         // I have found a scc

        //   UPDATE ------------------------------------------------------

        FinalBreakNodes[at] = true;
        arrayTemp[LowLinkArray[at]] = at;

        //   BreakLowLinks[sccCount]=LowLinkArray[at];  // lowlink value of that SCC is inserted to array

        //   BreakNodes[sccCount]=at;

        //   UPDATE ------------------------------------------------------


        for (int node = s.top();; node = s.top()) {
            s.pop();
            OnStackArray[node] = false;
            LowLinkArray[node] = IDsArray[at];

            if (node == at) {
                break;
            }

        }


        sccCount++;
    }


}





