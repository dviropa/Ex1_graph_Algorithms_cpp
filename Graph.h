//#dvir.opa@gmail.com

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <stdexcept>
#include "Edge.h"
#include "adesenlist.h"

namespace graph {
//https://github.com/BenjaminSaldman/CPP_EX1_25
    class Graph {
    private:
        adesenlist adesenList;
        int num_of_points;



        void addEdge_one_side(int source, int target, int val);
    public:
        explicit Graph(int num_points);

        ~Graph();
        int get_size() const { return num_of_points; }
        int  get_weight(int u,int v) ;

        int* get_neighbors(int x);
        void addEdge(int source, int target, int val);


        void printGraph() ;

        Edge *get_all_edges(int &count) ;
        bool operator==(const Graph& other) const ;
        Graph(const Graph& other);
		Graph& operator=(const Graph& other);


    };


}

#endif
