#include "Graph.h"
using namespace graph;

int main() {
    Graph g(5);

    g.addEdge(0, 1, 3);
    g.addEdge(1, 2, 4);
    g.addEdge(0, 4, 2);
    g.printGraph();

    int count = 0;
    Edge* edges = g.get_all_edges(count);
    std::cout << "All edges (" << count << "):\n";
    for (int i = 0; i < count; ++i) {
        std::cout << edges[i].getSrc() << " -> " << edges[i].getDest()
                  << " (w=" << edges[i].getWeight() << ")\n";
    }
    delete[] edges;

    return 0;
}
