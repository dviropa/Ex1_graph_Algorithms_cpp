//#dvir.opa@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "../Graph.h"
#include <climits>

using namespace graph;

TEST_CASE("Testing graph creation and adding edges") {
    Graph g(5);

    Graph g2(5);

    g.addEdge(0, 1, 3);
    g.addEdge(1, 2, 4);
    g.addEdge(2, 3, 5);

    g2.addEdge(0, 1, 3);
    g2.addEdge(1, 2, 4);
    g2.addEdge(2, 3, 5);

    CHECK_THROWS(g2 = Graph(-1));

    CHECK(g.get_weight(0, 1) == 3);
    CHECK(g.get_weight(1, 2) == 4);
    CHECK(g.get_weight(2, 3) == 5);

    CHECK(g == g2);
}


TEST_CASE("Graph comparison") {
    Graph g1(4), g2(4);

    g1.addEdge(0, 1, 1);
    g1.addEdge(2, 3, 2);

    g2.addEdge(1, 0, 1);
    g2.addEdge(3, 2, 2);

    CHECK(g1 == g2);
}



TEST_CASE("Graph get_neighbors returns correct neighbors") {
    Graph g(4);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 2, 3);

    int* neighbors = g.get_neighbors(0);
    CHECK((neighbors[0] == 1 || neighbors[0] == 2));
    CHECK((neighbors[1] == 1 || neighbors[1] == 2));
    CHECK(neighbors[0] != neighbors[1]);
    delete[] neighbors;
}

TEST_CASE("Graph get_all_edges returns correct edge list") {
    Graph g(3);
    g.addEdge(0, 1, 7);
    g.addEdge(1, 2, 8);
    int count = 0;
    Edge* edges = g.get_all_edges(count);
    CHECK(count == 2);

    bool found_01 = false, found_12 = false;
    for (int i = 0; i < count; i++) {
        if ((edges[i].getSrc() == 0 && edges[i].getDest() == 1) ||
            (edges[i].getSrc() == 1 && edges[i].getDest() == 0))
            found_01 = true;
        if ((edges[i].getSrc() == 1 && edges[i].getDest() == 2) ||
            (edges[i].getSrc() == 2 && edges[i].getDest() == 1))
            found_12 = true;
    }
    CHECK(found_01);
    CHECK(found_12);
    delete[] edges;
}



TEST_CASE("Graph operator== fails for unequal graphs") {
    Graph g1(3);
    Graph g2(3);

    g1.addEdge(0, 1, 4);
    g2.addEdge(0, 1, 5); // different weight

    CHECK_FALSE(g1 == g2);
}