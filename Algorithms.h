#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <stdexcept>

#include "Graph.h"
#include "Queue.h"
#include "Stack.h"
#include "UnionFind.h"
#include "Edge.h"

namespace graph {

    class Algorithms {
        static void sortEdges(Edge* edges, int edgeCount) {
            for (int i = 0; i < edgeCount - 1; ++i) {
                for (int j = 0; j < edgeCount - i - 1; ++j) {
                    if (edges[j].getWeight() > edges[j + 1].getWeight()) {
                        std::swap(edges[j], edges[j + 1]);
                    }
                }
            }
        }
        static void dfs_util(Graph& g,Graph& tree, int current, bool *visited);


    public:
        static Graph bfs(Graph& g, int s);
        static Graph dfs(Graph& g, int x);
        static Graph dijKstra(Graph& g, int s);
        static Graph prim(Graph& g,int s);
        static Graph kruskal(Graph& g);
    };

} // namespace graph

#endif // ALGORITHMS_H
