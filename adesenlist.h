//#dvir.opa@gmail.com
#ifndef ADESENLIST_H
#define ADESENLIST_H

#include <iostream>
#include "auterNode.h"
#include "Edge.h"

namespace graph {
    class adesenlist {
    private:
        int size;
        auterNode* list = nullptr;
    public:
        adesenlist(int num) ;

        ~adesenlist();
        void addEdge(int s, int t, int v);
        auterNode* get_heade();
        void printGraph() ;
        int get_weight(int u,int v);
        int* get_neighbors(int x);
        Edge* get_all_edges(int& count) ;
        bool operator==(const adesenlist& other) const;

    };
}
#endif
