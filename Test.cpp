#include <vector>
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

//roibr23@gmail.com 322695883

using namespace std;

TEST_CASE("matrix sizes")
{
    ariel::Graph g1;
    ariel::Graph g2;
// Test case 1
    vector<vector<int>> m1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(m1);

    vector<vector<int>> m2 = {
            {0, 1, 1, 0, 0},
            {1, 0, 1, 0, 0},
            {1, 1, 0, 1, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0}};
    g2.loadGraph(m2);
    CHECK(g1.sizeCheck(m2,m1) == false);

// Test case 2
    ariel::Graph g3;
    ariel::Graph g4;
    vector<vector<int>> m3 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g3.loadGraph(m3);

    vector<vector<int>> m4 = {
            {3, 1, -3},
            {5, 0, 1},
            {0, 12, 17}};
    g4.loadGraph(m4);
    CHECK(g3.sizeCheck(m3,m4) == true);

}

TEST_CASE("operator +") {

    ariel::Graph g1;
    ariel::Graph g2;
    vector<vector<int>> m1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(m1);

    vector<vector<int>> m2 = {
            {0, 1, 1},
            {1, 0, 1},
            {1, 1, 0}};
    g2.loadGraph(m2);

    ariel::Graph g3 = g1 + g2;
    CHECK(g3 == (g1 + g2));


    ariel::Graph g4;
    ariel::Graph g5;
    vector<vector<int>> m3 = {
            {0, 2, -1},
            {1, 0, 3},
            {2, -3, 0}};
    g4.loadGraph(m3);

    vector<vector<int>> m4 = {
            {0, 1, 2},
            {-1, 0, -2},
            {1, 2, 0}};
    g5.loadGraph(m4);

    ariel::Graph g6 = g4 + g5;
    CHECK(g6 == (g4 + g5));
}

TEST_CASE("operator +=") {

    ariel::Graph g1;
    ariel::Graph g2;
    ariel::Graph g12;
    vector<vector<int>> m1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(m1);

    vector<vector<int>> m2 = {
            {0, 1, 1},
            {1, 0, 1},
            {1, 1, 0}};
    g2.loadGraph(m2);

    g1 += g2;

    vector<vector<int>> m5 = {
            {0, 2, 1},
            {2, 0, 2},
            {1, 2, 0}};
    g12.loadGraph(m5);


    CHECK(g1 == g12);


    ariel::Graph g3;
    ariel::Graph g4;
    ariel::Graph g34;
    vector<vector<int>> m3 = {
            {0, 2, -1},
            {1, 0, 3},
            {2, -3, 0}};
    g3.loadGraph(m3);

    vector<vector<int>> m4 = {
            {0, 1, 2},
            {-1, 0, -2},
            {1, 2, 0}};
    g4.loadGraph(m4);

    vector<vector<int>> m34 = {
            {0, 3, 1},
            {0, 0, 1},
            {3, -1, 0}};
    g34.loadGraph(m34);

    g3 += g4;
    CHECK(g3 == g34);
}

TEST_CASE("Unary Plus Operator") {
// Create a graph
    ariel::Graph g1;
    std::vector<std::vector<int>> m1 = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    g1.loadGraph(m1);

// Apply the unary plus operator
    ariel::Graph g2 = +g1;

// Check if g2 is equal to g1
    CHECK(g1 == g2);
}

TEST_CASE("operator -") {

    ariel::Graph g1;
    ariel::Graph g2;
    vector<vector<int>> m1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(m1);

    vector<vector<int>> m2 = {
            {0, 1, 1},
            {1, 0, 1},
            {1, 1, 0}};
    g2.loadGraph(m2);

    ariel::Graph g3 = g1 - g2;
    CHECK(g3 == (g1 - g2));


    ariel::Graph g4;
    ariel::Graph g5;
    vector<vector<int>> m3 = {
            {0, 2, -1},
            {1, 0, 3},
            {2, -3, 0}};
    g4.loadGraph(m3);

    vector<vector<int>> m4 = {
            {0, 1, 2},
            {-1, 0, -2},
            {1, 2, 0}};
    g5.loadGraph(m4);

    ariel::Graph g6 = g4 - g5;
    CHECK(g6 == (g4 - g5));
}

TEST_CASE("operator -=") {

    ariel::Graph g1;
    ariel::Graph g2;
    ariel::Graph g12;
    vector<vector<int>> m1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(m1);

    vector<vector<int>> m2 = {
            {0, 1, 1},
            {1, 0, 1},
            {1, 1, 0}};
    g2.loadGraph(m2);

    vector<vector<int>> m12 = {
            {0, 0, -1},
            {0, 0, 0},
            {-1, 0, 0}};
    g12.loadGraph(m12);

    g1 -= g2;
    CHECK(g1 == g12);


    ariel::Graph g3;
    ariel::Graph g4;
    ariel::Graph g34;
    vector<vector<int>> m3 = {
            {0, 2, -1},
            {1, 0, 3},
            {2, -3, 0}};
    g3.loadGraph(m3);

    vector<vector<int>> m4 = {
            {0, 1, 2},
            {-1, 0, -2},
            {1, 2, 0}};
    g4.loadGraph(m4);

    vector<vector<int>> m34 = {
            {0, 1, -3},
            {2, 0, 5},
            {1, -5, 0}};
    g34.loadGraph(m34);

    g3 -= g4;
    CHECK(g3 == g34);

}

TEST_CASE("Unary Minus Operator") {
// Create a graph
    ariel::Graph g1;
    std::vector<std::vector<int>> m1 = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };
    g1.loadGraph(m1);

// Apply the unary minus operator
    ariel::Graph g2 = -g1;

// Check if g2 has all its elements negated
    for (size_t i = 0; i < g2.getNeigborMatrix().size(); ++i) {
        for (size_t j = 0; j < g2.getNeigborMatrix()[i].size(); ++j) {
            CHECK(g2.getNeigborMatrix()[i][j] == -g1.getNeigborMatrix()[i][j]);
        }
    }
}

TEST_CASE("operator !=") {
// Test case 1: Two equal graphs
    ariel::Graph g1;
    ariel::Graph g2;

    vector<vector<int>> m1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(m1);

    vector<vector<int>> m2 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g2.loadGraph(m2);

    CHECK_FALSE(g1 != g2);

// Test case 2: Two different graphs
    ariel::Graph g3;
    ariel::Graph g4;

    vector<vector<int>> m3 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g3.loadGraph(m3);

    vector<vector<int>> m4 = {
            {1, 0, 1},
            {0, 1, 0},
            {1, 0, 1}};
    g4.loadGraph(m4);

    CHECK(g3 != g4);
}

TEST_CASE("contains") {
// Test case 1: Graph2 contains Graph1
    ariel::Graph g1;
    ariel::Graph g2;

    vector<vector<int>> m1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(m1);

    vector<vector<int>> m2 = {
            {0, 0, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g2.loadGraph(m2);

    CHECK(g2.contains(g1, g2));

// Test case 2: Graph2 does not contain Graph1
    ariel::Graph g3;
    ariel::Graph g4;

    vector<vector<int>> m3 = {
            {0, 0, 0},
            {0, 0, 1},
            {0, 1, 0}};
    g3.loadGraph(m3);

    vector<vector<int>> m4 = {
            {0, 1, 0},
            {1, 0, 0},
            {0, 1, 0}};
    g4.loadGraph(m4);

    CHECK_FALSE(g4.contains(g3, g4));
}

TEST_CASE("getNumEdges") {
// Test case 1: Graph with no edges
    ariel::Graph g1;

    vector<vector<int>> m1 = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}};
    g1.loadGraph(m1);

    CHECK(g1.getNumEdges(g1) == 0);

// Test case 2: Graph with some edges
    ariel::Graph g2;

    vector<vector<int>> m2 = {
            {0, -1, 0},
            {1, 0, 7},
            {3, 1, 0}};
    g2.loadGraph(m2);

    CHECK(g2.getNumEdges(g2) == 5);
}

TEST_CASE("operator++") {
// Test case 1: Increment all edges in the graph
    ariel::Graph g1;

    vector<vector<int>> m1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(m1);

    ++g1;

    vector<vector<int>> expectedResult = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};

    CHECK(g1.getNeigborMatrix() == expectedResult);
}

TEST_CASE("operator--") {
// Test case 1: Decrement all edges in the graph
    ariel::Graph g1;

    vector<vector<int>> m1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(m1);

    --g1;

    vector<vector<int>> expectedResult = {
            {0, 0, 0},
            {0, 0, 0},
            {0, 0, 0}};

    CHECK(g1.getNeigborMatrix() == expectedResult);
}

TEST_CASE("operator* (int scalar)") {
// Test case 1: Multiply all edges by a scalar
    ariel::Graph g1;

    vector<vector<int>> m1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(m1);

    ariel::Graph result = g1 * 2;

    vector<vector<int>> expectedResult = {
            {0, 2, 0},
            {2, 0, 2},
            {0, 2, 0}};

    CHECK(result.getNeigborMatrix() == expectedResult);
}

TEST_CASE("operator* (Graph multiplication)") {
// Test case 1: Multiply two graphs
    ariel::Graph g1;
    ariel::Graph g2;

    vector<vector<int>> m1 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g1.loadGraph(m1);

    vector<vector<int>> m2 = {
            {0, 1, 0},
            {1, 0, 1},
            {0, 1, 0}};
    g2.loadGraph(m2);

    ariel::Graph result = g1 * g2;

    vector<vector<int>> expectedResult = {
            {1, 0, 1},
            {0, 2, 0},
            {1, 0, 1}};

    CHECK(result.getNeigborMatrix() == expectedResult);

    ariel::Graph g3;
    ariel::Graph g4;

    vector<vector<int>> m3 = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}};
    g3.loadGraph(m3);

    vector<vector<int>> m4 = {
            {9, 8, 7},
            {6, 5, 4},
            {3, 2, 1}};
    g4.loadGraph(m4);

    ariel::Graph result2 = g3 * g4;

    vector<vector<int>> expectedResult2 = {
            {30, 24, 18},
            {84, 69, 54},
            {138, 114, 90}};

    CHECK(result2.getNeigborMatrix() == expectedResult2);
}