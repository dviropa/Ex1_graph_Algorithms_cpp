#include "Graph.h"
#include <iostream>
#include "adesenlist.h"

namespace graph {

  Graph::Graph(int num_points) : num_of_points(num_points), adesenlist(num_points) {
    if (num_points <= 0) {
        throw std::invalid_argument("Graph must have at least one vertex.");
    }
}
    Graph::~Graph() {}

    void Graph::addEdge_one_side(int source, int target, int val) {
        Edge e(source, target, val);
        adesenlist.addEdge(source, target, val);
    }

    void Graph::removeEdgeFromNode(int source, int target) {
        adesenlist.removeEdge(source, target);
    }

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

    Edge* Graph::get_all_edges(int& count) {
        count = 0;
        const int MAX_EDGES = 1000;
        Edge* edges = new Edge[MAX_EDGES];

        auterNode* current = adesenlist.get_heade();
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

    void Graph::removeEdge(int source, int target) {
        removeEdgeFromNode(source, target);
        removeEdgeFromNode(target, source);
    }

    int Graph::get_weight(int u, int v) {
        return adesenlist.get_weight(u, v);
    }

    int* Graph::get_neighbors(int x) {
        return adesenlist.get_neighbors(x);
    }

    void Graph::printGraph()  {
        adesenlist.printGraph();
    }

    bool Graph::operator==(const Graph& other) const  {
        if (this->num_of_points != other.num_of_points)
            return false;

        return this->adesenlist == other.adesenlist;
    }



} // namespace graph
