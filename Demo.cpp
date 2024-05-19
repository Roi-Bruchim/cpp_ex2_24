#include "Graph.hpp"
#include "Algorithms.hpp"
using ariel::Algorithms;
//roibr23@gmail.com 322695883
#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{
//    ariel::Graph g;
//    // 3x3 matrix that represents a connected graph.
//    vector<vector<int>> graph = {
//            {0, 1, 0},
//            {1, 0, 1},
//            {0, 1, 0}};
//    g.loadGraph(graph); // Load the graph to the object.
//
//    g.printGraph();                                    // Should print: "Graph with 3 vertices and 4 edges."
//    cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
//    cout << Algorithms::shortestPath(g, 0, 2) << endl; // Should print: 0->1->2.
//    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
//    cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0, 2}, B={1}."
//
//    // 5x5 matrix that represents a non-connected graph with a cycle.
//    vector<vector<int>> graph2 = {
//            {0, 1, 1, 0, 0},
//            {1, 0, 1, 0, 0},
//            {1, 1, 0, 1, 0},
//            {0, 0, 1, 0, 0},
//            {0, 0, 0, 0, 0}};
//
//    g.loadGraph(graph2); // Load the graph to the object.
//
//    g.printGraph();                                    // Should print: "Graph with 5 vertices and 8 edges."
//    cout << Algorithms::isConnected(g) << endl;        // Should print: "0" (false).
//    cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: "-1" (there is no path between 0 and 4).
//    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "The cycle is: 0->1->2->0".
//    cout << Algorithms::isBipartite(g) << endl;        // Should print: "0" (false).
//
//    // 5x5 matrix that reprsents a connected weighted graph.
//    vector<vector<int>> graph3 = {
//            {0, 1, 0, 0, 0},
//            {1, 0, 3, 0, 0},
//            {0, 3, 0, 4, 0},
//            {0, 0, 4, 0, 5},
//            {0, 0, 0, 5, 0}};
//    g.loadGraph(graph3); // Load the graph to the object.
//
//    g.printGraph();                                    // Should print: "Graph with 5 vertices and 10 edges."
//    cout << Algorithms::isConnected(g) << endl;        // Should print: "1" (true).
//    cout << Algorithms::shortestPath(g, 0, 4) << endl; // Should print: 0->2->3->4.
//    cout << Algorithms::isContainsCycle(g) << endl;    // Should print: "0" (false).
//    cout << Algorithms::isBipartite(g) << endl;        // Should print: "The graph is bipartite: A={0, 2, 4}, B={1, 3}."
//
//    // 5x4 matrix that reprsents invalid graph.
//    vector<vector<int>> graph4 = {
//            {0, 1, 2, 0},
//            {1, 0, 3, 0},
//            {2, 3, 0, 4},
//            {0, 0, 4, 0},
//            {0, 0, 0, 5}};
//    try
//    {
//        g.loadGraph(graph4); // Load the graph to the object.
//    }
//    catch (const std::invalid_argument &e)
//    {
//        cout << e.what() << endl; // Should print: "Invalid graph: The graph is not a square matrix."
//    }

//    ariel::Graph g1;
//    ariel::Graph g2;
//    ariel::Graph g3;
//    vector<vector<int>> m1= {
//            {0, 1, 1, 0, 0},
//            {1, 0, 1, 0, 0},
//            {1, 1, 0, 1, 0},
//            {0, 0, 1, 0, 0},
//            {0, 0, 0, 0, 0}};
//
//    g1.loadGraph(m1);
//    vector<vector<int>> m2 = {
//            {0, 1, 0, 0, 0},
//            {1, 0, 3, 0, 0},
//            {0, 3, 0, 4, 0},
//            {0, 0, 4, 0, 5},
//            {0, 0, 0, 5, 0}};
//    g2.loadGraph(m2);
//    g3=g1+g2;
//    g3.printGraph();
//    g3+=g1;
//    cout<< endl;
//    g3.printGraph();
//    cout<< endl;
//    g3-=g1;
//    g3.printGraph();
//    g3=g3-g2;
//    cout<< endl;
//    g3.printGraph();
//    cout<< endl;
//    if(g3==g1)
//        cout <<":)";
//    cout<< endl;
//    if(g3!=g2)
//        cout <<":)";
//    if (g3 < g1) {
//        std::cout << "g3 is less than g1" << std::endl;
//    }
//
//    if (g3 <= g1) {
//        std::cout << "g3 is less than or equal to g1" << std::endl;
//    }
//
//    if (g3 > g2) {
//        std::cout << "g3 is greater than g2" << std::endl;
//    }
//
//    if (g3 >= g2) {
//        std::cout << "g3 is greater than or equal to g2" << std::endl;
//    }
//    cout<< endl;
//    ++g3;
//    g3.printGraph();
//    cout<< endl;
//    g3=g3*5;
//    g3.printGraph();
//    cout<< endl;
//    ariel::Graph g4;
//    ariel::Graph g5;
//    ariel::Graph g6;
//
//    vector<vector<int>> m3= {
//            {1, 2, 3},
//            {4, 5, 6},
//            {7, 8, 9}};
//
//    vector<vector<int>> m4 = {
//            {9, 8, 7},
//            {6, 5, 4},
//            {3, 2, 1}};
//    g4.loadGraph(m3);
//    g5.loadGraph(m4);
//    g6=g4*g5;
//    cout <<g6<<endl;
//    g6=g6+g6+g6;
//    cout <<g6;


// First graphs with algoritems before operators

    ariel::Graph g1;
    vector<vector<int>> m1= {
           {0, 3, 5},
           {3, 0, 1},
           {5, 1 ,0}};
    g1.loadGraph(m1);
    cout <<"before operator" << endl;
    cout <<g1 <<endl;
    cout << "connected?  "<<Algorithms::isConnected(g1) << endl;  // Yes he is connected
    cout << "shortest path  "<<Algorithms::shortestPath(g1, 0, 2) << endl;  //shortest path is 4 (0->1->2)
    cout << "isBipartite?  "<<Algorithms::isBipartite(g1) << endl  << endl;  //And not Bipartite

    //now we reduce every edge weight by 1
    --g1;
    cout <<"after operator (--graph)" << endl;

    //and lest see the difference
    cout <<g1 <<endl;
    cout << "connected?  "<<Algorithms::isConnected(g1) << endl;  //  still connected even after lose edge
    cout <<"shortest path  "<< Algorithms::shortestPath(g1, 0, 2) << endl;  //shortest path is now 4 but different routh (0->2)
    cout << "isBipartite?  "<<Algorithms::isBipartite(g1) << endl<< endl;  //Now we can divide the graph into 2 groups


    ariel::Graph g2;
    vector<vector<int>> m2 = {
            {0, 1, 0, 4},
            {1, 0, 1, 0},
            {0, 1, 0, 1},
            {4, 0, 1, 0}
    };
    g1.loadGraph(m2);

    cout << "Before operator" << endl;
    cout << g1 << endl;
    cout << "shortest path  "<< Algorithms::shortestPath(g1, 0, 3) << endl<< endl;   // best path now will be go by detour and do 1+1+1=3<4 (the directly routh)

// Now let's add another graph with all weights of 10
    ariel::Graph g3;
    vector<vector<int>> m3 = {
            {0, 10, 0, 10},
            {10, 0, 10, 0},
            {0, 10, 0, 10},
            {10, 0, 10, 0}
    };
    g2.loadGraph(m3);

// Now add the graphs
    g1 += g2;

    cout << "After operator (add to this graph another graph with same edges but with weight 10)" << endl;

// Let's see the difference
    cout << g1 << endl;
    cout << "shortest path  "<< Algorithms::shortestPath(g1, 0, 3) << endl<< endl;  // after every edge got 10 weight more its better go directly (11+11+11>14)


    ariel::Graph g4;
    vector<vector<int>> m4 = {
            {0, -2, -4, 0},
            {-2, 0, -3, 0},
            {-4, -3, 0, 0},
            {0, 0, 0, 0  }
    };
    g4.loadGraph(m4);
    cout <<"before operator" << endl;
    cout <<g4 <<endl;
    cout << "negative cycle?  "<< Algorithms::negativeCycle(g4) << endl<< endl; //has negative cycle

    //now multiply the edges by -5

    ariel::Graph g5=g4*-5;
    cout <<"after operators (first do graph*-5 than -graph)" << endl;
    cout <<g5 <<endl;
    cout << "negative cycle?  "<<Algorithms::negativeCycle(g5)<< endl<< endl; // now doesn't has negative cycles

    //now we do - operator to our graph
    g5= -g5;
    cout <<g5 <<endl;
    cout << "negative cycle?  "<<Algorithms::negativeCycle(g5)<< endl<< endl; // now has again

    ariel::Graph g6;
    vector<vector<int>> m6= {
            {0, -1},
            {-1, 0,},};
    g6.loadGraph(m6);
    cout <<"before operator" << endl;
    cout <<g6 <<endl;
    cout <<"connected?  "<< Algorithms::isConnected(g6) << endl<< endl;  // Yes he is connected
    //now we add 1 to our graph edges
    ++g6;
    cout <<"after operator (++graph)" << endl;
    cout <<g6 <<endl;
    cout <<"connected?  "<< Algorithms::isConnected(g6) << endl<< endl;  // Yes he is NOT connected









}