#include <iostream>
#include <stack>
#include <limits>
#include <sstream>
#include <queue>
#include "Graph.hpp"
#include "Algorithms.hpp"
//roibr23@gmail.com 322695883
#define white 0
#define gray 1
#define black 2
using namespace std;
using namespace ariel;

bool Algorithms::isConnected(const Graph& graph) {
    // Get the adjacency matrix of the graph
    const vector<vector<int>>& neighborMatrix = graph.getNeigborMatrix();

    // first all vertices are unvisited
    vector<bool> visited(neighborMatrix.size(), false);

    // use DFS algorithm
    stack<size_t> s; // Use size_t for stack
    s.push(0); // first vertex we check
    visited[0] = true; //this vertex now visited

    // run DFS for every vertex
    while (!s.empty()) {
        size_t current = s.top(); // Use size_t for current vertex
        s.pop();
        // visits all neighbors of the current vertex
        for (size_t i = 0; i < neighborMatrix[current].size(); ++i) {
            if (neighborMatrix[current][i] != 0 && !visited[i]) {
                s.push(i);
                visited[i] = true; //change it to visited
            }
        }
    }
    // now we see if all our vertices are visited, if they are so the graph is connected
    for (bool visit : visited) {
        if (!visit) {
            return false; // we found a vertex we couldn't reach
        }
    }
    return true; // all vertices are reachable
}


//here we use Berman Ford Algorithm to deal with negative weights on edges
// here I got help to implement the algorithm with ChatGPT
string Algorithms::shortestPath(const Graph& graph, size_t start, size_t end) {
    const vector<vector<int>>& neighborMatrix = graph.getNeigborMatrix();
    size_t numVertices = neighborMatrix.size(); // Use size_t for the number of vertices
    const int INF = numeric_limits<int>::max(); // infinity value

    // init distances of all vertices to infinity and predecessors to null (-1)
    vector<int> distance(numVertices, INF);
    vector<int> predecessor(numVertices, -1);

    // distance vertex start with zero
    distance[start] = 0;

    // using "Relax" for the number of the vertices
    for (size_t i = 0; i < numVertices - 1; ++i) {
        for (size_t u = 0; u < numVertices; ++u) {
            for (size_t v = 0; v < numVertices; ++v) {
                if (neighborMatrix[u][v] != 0) {
                    if (distance[u] != INF && distance[u] + neighborMatrix[u][v] < distance[v]) {
                        // Relax the edge
                        distance[v] = distance[u] + neighborMatrix[u][v];
                        predecessor[v] = u;
                    }
                }
            }
        }
    }

    // check for negative cycles using our helper method
    if (negativeCycle(graph)) {
        return "-1"; // There is a negative cycle
    }

    // check if there is a path from start to end
    if (distance[end] == INF) {
        return "-1"; // There is no path from start to end
    }

    // Reconstruct the shortest path
    std::stringstream path;
    size_t current = end;
    std::stack<size_t> reversePath; // Use size_t for the stack

    while (current != static_cast<size_t>(-1)) {
        reversePath.push(current);
        current = static_cast<size_t>(predecessor[current]);
    }

    while (!reversePath.empty()) {
        path << reversePath.top();
        reversePath.pop();
        if (!reversePath.empty()) {
            path << "->";
        }
    }

    return path.str(); // return the shortest path as a string
}

bool Algorithms::negativeCycle(const Graph& graph) {
    const vector<vector<int>>& neighborMatrix = graph.getNeigborMatrix();
    size_t numVertices = neighborMatrix.size(); // Use size_t for the number of vertices
    const int INF = numeric_limits<int>::max();

    vector<int> distance(numVertices, 0); // Initialize distance to 0
    for (size_t i = 0; i < numVertices - 1; ++i) {
        for (size_t u = 0; u < numVertices; ++u) {
            for (size_t v = 0; v < numVertices; ++v) {
                if (neighborMatrix[u][v] != 0) {
                    if (distance[u] != INF && distance[u] + neighborMatrix[u][v] < distance[v]) {
                        // there is negative cycle
                        return true;
                    }
                }
            }
        }
    }

    return false; // no negative cycle
}


//check if the graph contains a cycle by use DFS algorithm
bool Algorithms::isContainsCycle(const Graph& graph) {
    const vector<vector<int>> &neighborMatrix = graph.getNeigborMatrix();
    size_t graph_size = neighborMatrix.size();
    //initial the prev to -1
    vector<int> prev(graph_size, -1);
    //init all vertexes to be white
    vector<int> colors(graph_size, white);
    for (size_t i=0; i < graph_size; i++)
    {
        //make sure i vertex didnt found yet
        if(colors[i]==white)
            if(isContainsCycleRec(neighborMatrix, graph_size, prev, colors, i))
                return true;
    }
    return false;
}


bool isContainsCycleRec(const vector<vector<int>> &neighborMatrix, size_t graph_size, vector<int> &prev,
                        vector<int> &colors, size_t current) {

//helper method that find if there is a cycle in recursive way

    //we visit current so make him gray
    colors[current]=gray;
    for(size_t i=0; i<graph_size;i++)
    {
        //if they neighbors
        if(neighborMatrix[current][i]!=0)
        {
            //if it white than go to the neighbor
            if(colors[i]==white)
            {
                prev[i]=current;
                return isContainsCycleRec(neighborMatrix,graph_size,prev,colors,i);
            }
                //make sure his ancsesor but not my father
            else if(colors[i]==gray && prev[current]!=i)
            {
                //we found cycle
                return true;
            }

        }
    }
    //we finished work with current
    colors[current]=black;
    //we couldnt find a cycle
    return false;

}

//here we will get help from BFS algorithm
string Algorithms::isBipartite(const Graph& graph) {
    const vector<vector<int>>& neighborMatrix = graph.getNeigborMatrix();
    size_t numVertices = neighborMatrix.size(); // Use size_t for the number of vertices
    // We will split vertices like this: not visited (-1) group A (0) Group B (1)
    vector<int> split(numVertices, -1); // First, all unvisited
    vector<int> visited(numVertices, 0); // Init visited array

    // Using BFS algorithm
    for (size_t i = 0; i < numVertices; ++i) {
        if (visited[i] == 0) { // If vertex not visited
            queue<size_t> q;
            q.push(i);
            split[i] = 0; // Move to group A

            while (!q.empty()) {
                size_t current = q.front();
                q.pop();

                for (size_t j = 0; j < numVertices; ++j) {
                    if (neighborMatrix[current][j] != 0 || neighborMatrix[j][current] != 0) { // If there is an edge in at least one direction
                        if (split[j] == -1) { // If vertex j is not visited
                            split[j] = 1 - split[current]; // Move to the opposite group
                            q.push(j);
                        } else if (split[j] == split[current]) { // If adjacent vertices are in the same group
                            return "0"; // Graph is not bipartite
                        }
                    }
                }
                visited[current] = 1; // Current vertex is visited
            }
        }
    }

    // Construct groups A and B
    vector<size_t> groupA, groupB;
    for (size_t i = 0; i < numVertices; ++i) {
        if (split[i] == 0) {
            groupA.push_back(i);
        } else {
            groupB.push_back(i);
        }
    }

    // Construct the output string
    string output = "The graph is bipartite: A={";
    for (size_t i = 0; i < groupA.size(); ++i) {
        output += to_string(groupA[i]);
        if (i < groupA.size() - 1) {
            output += ", ";
        }
    }
    output += "}, B={";
    for (size_t i = 0; i < groupB.size(); ++i) {
        output += to_string(groupB[i]);
        if (i < groupB.size() - 1) {
            output += ", ";
        }
    }
    output += "}";

    return output; // Return the bipartite groups
}