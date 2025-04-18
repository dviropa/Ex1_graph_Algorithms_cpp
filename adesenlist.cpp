//#dvir.opa@gmail.com

#include "adesenlist.h"
#include "Edge.h"
#include "auterNode.h"
#include <stdexcept>
#include <climits>


//adjacency list implementation for representing a graph.
//It consists of a linked list of primary nodes (auterNode)
//Each auterNode represents a vertex and stores its number (num)
//Each auterNode points to a linked list of neighbors (inerNode)
//Each inerNode contains a single edge that originates from the auterNode


namespace graph {

        adesenlist::adesenlist(int num) {
                list = nullptr;
                size=num;
                for (int i = num - 1; i >= 0; --i) {
                        auterNode* newNode = new auterNode(i);
                        newNode->next = list;
                        list = newNode;
                }
        }
        auterNode* adesenlist::get_heade() {
                return this->list;
        }

        adesenlist::~adesenlist() {
                auterNode* curr = list;
                while (curr) {
                        auterNode* temp = curr;
                        curr = curr->next;
                        delete temp;
                }
        }


        void adesenlist::addEdge(int s, int t, int v) {
                Edge e = {s, t, v};
                auterNode* curr = list;

                while (curr != nullptr) {
                        if (curr->num == s) {
                                curr->addEdge(e);
                                return;
                        }
                        curr = curr->next;
                }
                throw std::invalid_argument("Source node not found in adjacency list");
        }


        void adesenlist:: printGraph()  {
                auterNode* curr = this->list;
                while (curr) {
                        curr->printEdges();

                    curr = curr->next;
                }

        }
int adesenlist::get_weight(int u, int v) {
    auterNode* curr = this->list;
    while (curr) {
        if (curr->num == u) {
            return curr->get_weight(u, v);
        }
        curr = curr->next;
    }
    return INT_MAX; // צומת לא נמצא
}

int* adesenlist::get_neighbors(int x) {
    auterNode* curr = this->list;
    while (curr && curr->num != x) {
        curr = curr->next;
    }

    if (!curr || !curr->l) {
        int* arr = new int[1];
        arr[0] = -1;
        return arr;
    }

    int count = 0;
    inerNode* edgeIter = curr->l;
    while (edgeIter) {
        count++;
        edgeIter = edgeIter->next;
    }

    int* arr = new int[count + 1];
    edgeIter = curr->l;
    int i = 0;
    while (edgeIter) {
        arr[i++] = edgeIter->e.getDest();
        edgeIter = edgeIter->next;
    }
    arr[i] = -1;
    return arr;
}


        Edge* adesenlist::get_all_edges(int& count) {
                count = 0;
        int caount=0;
            auterNode* temp = list;

                while (temp) {
                        inerNode* edgeIter = temp->l;
                        while (edgeIter) {
                                caount++;
                                edgeIter = edgeIter->next;
                        }
                        temp = temp->next;
                }
                Edge* edges = new Edge[caount];

                auterNode* currNode = list;

                while (currNode) {
                        inerNode* edgeIter = currNode->l;
                        while (edgeIter) {
                                Edge e = edgeIter->e;
                                int src = e.getSrc();
                                int dest = e.getDest();
                                if (src < dest) {
                                	if (count >= caount) {
    									delete[] edges;
    									throw std::overflow_error("Too many edges");
									}

                                    edges[count++] = e;
                                }
                                edgeIter = edgeIter->next;
                        }
                        currNode = currNode->next;
                }
                return edges;
        }


        bool adesenlist::operator==(const adesenlist& other) const {
                auterNode* curr1 = this->list;
                auterNode* curr2 = other.list;

                while (curr1 && curr2) {
                        if (!(*curr1 == *curr2)) {
                                return false;
                        }
                        curr1 = curr1->next;
                        curr2 = curr2->next;
                }

                return (curr1 == nullptr && curr2 == nullptr);
        }
}