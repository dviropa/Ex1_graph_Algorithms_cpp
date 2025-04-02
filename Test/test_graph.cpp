#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"

#include "../Graph.h"
using namespace graph;

TEST_CASE("בדיקה של יצירת גרף והוספת צלעות") {
    Graph g(5);

    Graph g2(5);

    CHECK_NOTHROW(g.addEdge(0, 1, 3));
    CHECK_NOTHROW(g.addEdge(1, 2, 4));
    CHECK_NOTHROW(g.addEdge(2, 3, 5));

    CHECK_NOTHROW(g2.addEdge(0, 1, 3));
    CHECK_NOTHROW(g2.addEdge(1, 2, 4));
    CHECK_NOTHROW(g2.addEdge(2, 3, 5));

    CHECK_THROWS(g2 = Graph(-1));

    CHECK(g.get_weight(0, 1) == 3);
    CHECK(g.get_weight(1, 2) == 4);
    CHECK(g.get_weight(2, 3) == 5);

    CHECK(g == g2);
}


TEST_CASE("השוואת גרפים שווים") {
    Graph g1(4), g2(4);

    g1.addEdge(0, 1, 1);
    g1.addEdge(2, 3, 2);

    g2.addEdge(1, 0, 1); // הוספה הפוכה (לא משנה)
    g2.addEdge(3, 2, 2);

    CHECK(g1 == g2);
}

