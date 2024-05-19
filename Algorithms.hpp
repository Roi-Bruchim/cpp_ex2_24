#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "Graph.hpp"
#include <string>
//roibr23@gmail.com 322695883
using namespace std;
bool isContainsCycleRec(const vector<vector<int>> &neighborMatrix,size_t graph_size,vector<int>&prev,vector<int>&colors,size_t current);
namespace ariel {
    class Algorithms {
    public:
        /**
         * This method make sure every vertex connected by at least one edge to the graph
         * @param graph the given graph
         * @return if the graph is connected return true else return false
         */
        static bool isConnected(const Graph& graph);
        /**
         * This method find the shortest route between 2 given vertex
         * using Berman Ford algorithm to deal with negative weights
         * @param graph the given graph
         * @param start start vertex
         * @param end end vertex
         * @return the method will return the shortest path if exist, if not return -1
         */
        static std::string shortestPath(const Graph& graph, size_t start, size_t end);
        /**
         * This method check if the graph has cycles
         * @param graph the given graph
         * @return if there is a cycle the method prints the cycle else return false
         */
        static bool isContainsCycle(const Graph& graph);
        /**
         * This method check if the graph is Bipartite
         * @param graph the given graph
         * @return if the graph is Bipartite returns the divided groups A and B else return 0
         */
        static std::string isBipartite(const Graph& graph);
        /**
         * This method is an helper method that check if graph has negative cycles
         * @param graph the given graph
         * @return if there is a negative cycle return true else return false
         */
        static bool negativeCycle(const Graph& graph);


    };
}
#endif // ALGORITHMS_H