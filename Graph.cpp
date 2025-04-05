//#dvir.opa@gmail.com
#include "Graph.h"
#include <iostream>
#include "adesenlist.h"

namespace graph {

  Graph::Graph(int num_points) : num_of_points(num_points), adesenList(num_points) {
    if (num_points <= 0) {
        throw std::invalid_argument("Graph must have at least one vertex.");
    }
}
    Graph::~Graph() {}
//Adds a one-way edge from source to target with weight val. Used internally.
    void Graph::addEdge_one_side(int source, int target, int val) {
        Edge e(source, target, val);
        adesenList.addEdge(source, target, val);
    }


//Adds a bidirectional edge (for an undirected graph) between two vertices with a given weight. Includes boundary checks.
void Graph::addEdge(int source, int target, int val) {
    if (source < 0 || source >= num_of_points) {
        throw std::invalid_argument("Source node is out of bounds.");
    }
    if (target < 0 || target >= num_of_points) {
        throw std::invalid_argument("Target node is out of bounds.");
    }
    addEdge_one_side(source, target, val);
    addEdge_one_side(target, source, val);
}
//Returns an array of all edges in the graph without duplicates (each edge only once). Sets count to the total number of edges.
    Edge* Graph::get_all_edges(int& count) {
        count = 0;
        const int MAX_EDGES = num_of_points;
        int caount=0;
      auterNode* temp = adesenList.get_heade();
        while (temp != nullptr) {
            inerNode* neighbor = temp->l;
            while (neighbor != nullptr) {
                Edge e = neighbor->e;
                if (e.getSrc() < e.getDest()) {
                    caount++;
                }
                neighbor = neighbor->next;
            }
            temp = temp->next;
        }
        Edge* edges = new Edge[caount];

        auterNode* current = adesenList.get_heade();
        while (current != nullptr) {
            inerNode* neighbor = current->l;
            while (neighbor != nullptr) {
                Edge e = neighbor->e;
                if (e.getSrc() < e.getDest()) {
                    edges[count++] = e;
                }
                neighbor = neighbor->next;
            }
            current = current->next;
        }
        return edges;
    }


//Returns the weight of the edge between two vertices, or INT_MAX if no such edge exists. Includes boundary validation.
    int Graph::get_weight(int u, int v) {
          if (u < 0 || u >= num_of_points) {
        throw std::invalid_argument("Source node is out of bounds.");
    }
    if (v < 0 ||  v >= num_of_points) {
        throw std::invalid_argument("Target node is out of bounds.");
    }
        return adesenList.get_weight(u, v);
    }
//Returns an array of all neighbors of a given vertex. The array ends with -1 as a sentinel value.
    int* Graph::get_neighbors(int x) {
        return adesenList.get_neighbors(x);
    }
//Prints the adjacency list of each vertex in the graph to the console.
    void Graph::printGraph()  {
        adesenList.printGraph();
    }

    bool Graph::operator==(const Graph& other) const  {
        if (this->num_of_points != other.num_of_points)
            return false;

        return this->adesenList == other.adesenList;
    }
Graph::Graph(const Graph& other) : num_of_points(other.num_of_points), adesenList(other.adesenList) {}
//Assignment operator – replaces the current graph with a copy of another graph.
Graph& Graph::operator=(const Graph& other) {
    if (this != &other) {
        num_of_points = other.num_of_points;
        adesenList = other.adesenList;
    }
    return *this;
}



}
