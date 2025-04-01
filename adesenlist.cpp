//
// Created by דביר on 3/23/2025.
//

#include "adesenlist.h"
#include "Edge.h"
#include "auterNode.h"
#include <stdexcept>



namespace graph {

        adesenlist::adesenlist(int num) {
                list = nullptr;
                size=num;
                for (int i = num - 1; i >= 0; --i) {
                        auterNode* newNode = new auterNode(i); // קונסטרקטור עם מספר הצומת
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
                                curr->addEdge(e); // מוסיף את הצלע רק לצומת עם המספר s
                                return;
                        }
                        curr = curr->next;
                }
                throw std::invalid_argument("Source node not found in adjacency list");
        }


        void adesenlist:: printGraph()  {
                this->list->printEdges();

        }
        int adesenlist:: get_weight(int u,int v) {
                return this->list->get_weight(u,v);
        }
        int* adesenlist::get_neighbors(int x) {
                auterNode* curr = this->list;
                while (curr && curr->num != x) {
                        curr = curr->next;
                }
                if (!curr || !curr->l) return nullptr;
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
                const int MAX_EDGES = 1000;

                Edge* edges = new Edge[MAX_EDGES];

                auterNode* currNode = list;

                while (currNode) {
                        inerNode* edgeIter = currNode->l;
                        while (edgeIter) {
                                Edge e = edgeIter->e;
                                int src = e.getSrc();
                                int dest = e.getDest();

                                // נוודא שזו לא כפילות: נוסיף רק אם src < dest
                                if (src < dest) {
                                        edges[count++] = e;
                                }
                                edgeIter = edgeIter->next;
                        }
                        currNode = currNode->next;
                }
                return edges;
        }

        void adesenlist:: removeEdge(int s,int t) {
                Edge e= {s,t,0};
                list->removeEdge(e);
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

                // אם אחד מהם עדיין לא הסתיים – הרשימות לא באותו גודל
                return (curr1 == nullptr && curr2 == nullptr);
        }


}