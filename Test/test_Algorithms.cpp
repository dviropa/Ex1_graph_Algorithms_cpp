#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "../Graph.h"
#include "../Algorithms.h"

using namespace graph;
a

// TEST_CASE("Dijkstra shortest paths") {
//     Graph g(6);
//     g.addEdge(0, 1, 5);
//     g.addEdge(0, 2, 1);
//     g.addEdge(0, 5, 1);
//     g.addEdge(5, 1, 1);
//     g.addEdge(1, 3, 1);
//     g.addEdge(3, 4, 2);
//     g.addEdge(2, 4, 10);
//     Graph shortestPaths = Algorithms::dijKstra(g, 0);

//     Graph expected(5);
//     expected.addEdge(0, 5, 1);
//     expected.addEdge(5, 1, 1);
//     expected.addEdge(1, 3, 1);
//     expected.addEdge(3, 4, 2);
//     expected.addEdge(0, 2, 1);


//     CHECK(shortestPaths == expected);
// }

// TEST_CASE("Prim MST") {
//     Graph g(5);
//     g.addEdge(0, 1, 2);
//     g.addEdge(0, 3, 6);
//     g.addEdge(1, 2, 3);
//     g.addEdge(1, 3, 8);
//     g.addEdge(1, 4, 5);
//     g.addEdge(2, 4, 7);
//     g.addEdge(3, 4, 9);

//     Graph mst = Algorithms::prim(g, 0);

//     Graph expected(5);
//     expected.addEdge(1, 2, 3);
//     expected.addEdge(1, 4, 5);
//     expected.addEdge(0, 1, 2);
//     expected.addEdge(0, 3, 6);

//     CHECK(mst == expected);
// }
// TEST_CASE("Kruskal MST") {
//     Graph g(4);
//     g.addEdge(0, 1, 2);
//     g.addEdge(0, 3, 6);
//     g.addEdge(1, 2, 3);
//     g.addEdge(1, 3, 8);
//     g.addEdge(1, 4, 5);
//     g.addEdge(2, 4, 7);
//     g.addEdge(3, 4, 9);

//     Graph mst = Algorithms::kruskal(g, 0);

//     Graph expected(4);
//     expected.addEdge(1, 2, 3);
//     expected.addEdge(1, 4, 5);
//     expected.addEdge(0, 1, 2);
//     expected.addEdge(0, 3, 6);


//     CHECK(mst == expected);
// }

// TEST_CASE("DFS tree") {
//     Graph g(5);
//     g.addEdge(0, 1, 1);
//     g.addEdge(0, 2, 1);
//     g.addEdge(1, 3, 1);
//     g.addEdge(1, 4, 1);

//     Graph dfsTree = Algorithms::dfs(g, 0);

//     Graph expected(5);
//     expected.addEdge(0, 2, 0);
//     expected.addEdge(0, 1, 0);
//     expected.addEdge(1, 4, 0);
//     expected.addEdge(1, 3, 0);

//     CHECK(dfsTree == expected);
// }

TEST_CASE("BFS tree generation") {
    Graph g(6);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    g.addEdge(1, 3, 1);
    g.addEdge(1, 4, 1);
    g.addEdge(2, 5, 1);

    Graph bfsTree = Algorithms::bfs(g, 0);

    Graph expected(6);
    expected.addEdge(0, 1, 0);
    expected.addEdge(0, 2, 0);
    expected.addEdge(1, 3, 0);
    expected.addEdge(1, 4, 0);
    expected.addEdge(2, 5, 0);

    CHECK(bfsTree == expected);
}
