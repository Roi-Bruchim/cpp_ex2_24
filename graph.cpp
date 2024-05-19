//roibr23@gmail.com 322695883
#include "Graph.hpp"
#include <iostream>

//using relevant name spaces
using namespace std;
using namespace ariel;

// constructor
Graph::Graph() {}

// destructor
Graph::~Graph() {}

// load graph
void Graph::loadGraph(const vector<vector<int>>& matrix) {
    // make sure matrix is square
    size_t numRows = matrix.size();
    for (size_t i = 0; i < numRows; ++i) {
        if (matrix[i].size() != numRows) {
            throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
        }
    }

    // if it square than load it to the graph
    neighborMatrix = matrix;
}

// print the graph
void Graph::printGraph() const {
    for (size_t i = 0; i < neighborMatrix.size(); ++i) {
        for (size_t j = 0; j < neighborMatrix[i].size(); ++j) {
            cout << neighborMatrix[i][j] << " ";
        }
        cout << endl;
    }

}
//return the matrix
const vector<vector<int>>& Graph::getNeigborMatrix() const {
    return this->neighborMatrix;
}

// **************************** EX2 IMPLEMENTATION ****************************



//**** HELPER METHODS  ****

bool Graph::sizeCheck(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) const {
    // Check if the number of rows and columns are the same in both matrices
    return (matrix1.size() == matrix2.size() && (matrix1.empty() || matrix1[0].size() == matrix2[0].size()));
}




bool Graph::contains(const Graph& graph1, const Graph& graph2) const {
    // Check if each edge in graph2 exists in graph1
    for (size_t i = 0; i < graph2.neighborMatrix.size(); ++i) {
        for (size_t j = 0; j < graph2.neighborMatrix[i].size(); ++j) {
            // If an edge in graph2 does not exist in graph1, return false
            if (graph2.neighborMatrix[i][j] != 0 && graph1.neighborMatrix[i][j] != graph2.neighborMatrix[i][j]) {
                return false;
            }
        }
    }
    return true;
}


size_t Graph::getNumEdges(const Graph& graph) const {
    size_t numEdges = 0;
    for (const auto& row : graph.neighborMatrix) {
        for (int edge : row) {
            if (edge != 0) {
                numEdges++;
            }
        }
    }
    return numEdges;
}

//**** HELPER METHODS  ****

//****  OPERATORS  ****


Graph Graph::operator+(const Graph& graph2) const {

    //first make sure both matrix's are the same size
    if (!sizeCheck(neighborMatrix, graph2.neighborMatrix)) {
        throw std::invalid_argument("Matrix sizes are different");
    }
    //the result graph
    Graph graph3;
    //make sure graph 3 matrix has the same size of other 2
    graph3.neighborMatrix.resize(neighborMatrix.size());
    //add each cell the addition 2 cells in graphs 1 and 2
    for (size_t i = 0; i < neighborMatrix.size(); ++i) {
        graph3.neighborMatrix[i].resize(neighborMatrix[i].size());
        for (size_t j = 0; j < neighborMatrix[i].size(); ++j) {
            graph3.neighborMatrix[i][j] = neighborMatrix[i][j] + graph2.neighborMatrix[i][j];
        }
        }
     return graph3;
    }

void Graph::operator+=(const Graph& graph2) {
    //first make sure both matrix's are the same size
    if (!sizeCheck(neighborMatrix, graph2.neighborMatrix)) {
        throw std::invalid_argument("Matrix sizes are different");
    }
    //add to original matrix the graph 2 in each cell
    for (size_t i = 0; i < neighborMatrix.size(); ++i)
        for (size_t j = 0; j < neighborMatrix[i].size(); ++j)
            neighborMatrix[i][j] += graph2.neighborMatrix[i][j];

}

Graph Graph::operator+() const {
    return *this;
}

Graph Graph::operator-(const Graph& graph2) const {

    //first make sure both matrix's are the same size
    if (!sizeCheck(neighborMatrix, graph2.neighborMatrix)) {
        throw std::invalid_argument("Matrix sizes are different");
    }
    //the result graph
    Graph graph3;
    //make sure graph 3 matrix has the same size of other 2
    graph3.neighborMatrix.resize(neighborMatrix.size());
    //subtract each cell the addition 2 cells in graphs 1 and 2
    for (size_t i = 0; i < neighborMatrix.size(); ++i) {
        graph3.neighborMatrix[i].resize(neighborMatrix[i].size());
        for (size_t j = 0; j < neighborMatrix[i].size(); ++j) {
            graph3.neighborMatrix[i][j] = neighborMatrix[i][j] - graph2.neighborMatrix[i][j];
        }
    }
    return graph3;
}

void Graph::operator-=(const Graph& graph2) {
    //first make sure both matrix's are the same size
    if (!sizeCheck(neighborMatrix, graph2.neighborMatrix)) {
        throw std::invalid_argument("Matrix sizes are different");
    }
    //subtract the original matrix from graph 2 in each cell
    for (size_t i = 0; i < neighborMatrix.size(); ++i)
        for (size_t j = 0; j < neighborMatrix[i].size(); ++j)
            neighborMatrix[i][j] -= graph2.neighborMatrix[i][j];

}

Graph Graph::operator-() const {
    // negate all the elements of the graph
    Graph negatedGraph(*this); // Create a copy of the current graph
    for (size_t i = 0; i < negatedGraph.neighborMatrix.size(); ++i) {
        for (size_t j = 0; j < negatedGraph.neighborMatrix[i].size(); ++j) {
            negatedGraph.neighborMatrix[i][j] = -negatedGraph.neighborMatrix[i][j];
        }
    }
    return negatedGraph;
}


bool Graph::operator==(const Graph& graph2) const
{
    //first we will compare their size
    if (!sizeCheck(neighborMatrix, graph2.neighborMatrix)) {
        return false;
    }
    //now make sure all the weighs are the same
    for (size_t i = 0; i < neighborMatrix.size(); ++i)
        for (size_t j = 0; j < neighborMatrix[i].size(); ++j)
            if(neighborMatrix[i][j] != graph2.neighborMatrix[i][j])
                return false;

    //if all conditions are existed we will return true;
    return true;

}

bool Graph::operator!=(const Graph& graph2) const
{
    //make sure they not equal
    return !(*this==graph2);
}


bool Graph::operator>(const Graph& graph2) const {

    //if the graphs are equals it cant be true
    if((*this==graph2))
      return false;

    if (contains(graph2, *this)) {
        return false; // graph2 contains this graph, so this graph is not greater
    }
    // compare the number of edges
    size_t numEdges1 = getNumEdges(*this);
    size_t numEdges2 = getNumEdges(graph2);
    if (numEdges1 != numEdges2) {
        return numEdges2 > numEdges1; // return true if graph2 has more edges than this graph
    }

    // if the number of edges is the same, compare the order of the matrices
    if (graph2.neighborMatrix.size() == neighborMatrix.size()) {
        return graph2.neighborMatrix[0].size() > neighborMatrix[0].size();
    }

    // if all conditions fail, return false
    return false;

}

bool Graph::operator>=(const Graph& graph2) const {
    // Check if the graphs are equals
    if (*this == graph2) {
        return true;
    }
    // Check if this graph is greater than graph2
    return !(*this < graph2);
}

bool Graph::operator<(const Graph& graph2) const {
    // Check if the graphs are equal
    if (*this == graph2) {
        return false;
    }
    // Check if graph2 is greater than this graph
    return graph2 > *this;
}

bool Graph::operator<=(const Graph& graph2) const {
    // Check if the graphs are equals
    if (*this == graph2) {
        return true;
    }
    // Check if this graph is less than graph2
    return !(*this > graph2);
}

void Graph::operator++() {
    for (size_t i = 0; i < neighborMatrix.size(); ++i)
        for (size_t j = 0; j < neighborMatrix[i].size(); ++j)
            //make sure the edge exist
            if(this->neighborMatrix[i][j]!=0)
                //if exist add 1 to edge
                ++neighborMatrix[i][j];
}

void Graph::operator--() {
    for (size_t i = 0; i < neighborMatrix.size(); ++i)
        for (size_t j = 0; j < neighborMatrix[i].size(); ++j)
            //make sure the edge exist
            if(this->neighborMatrix[i][j]!=0)
                //if exist subtract 1 to edge
                --neighborMatrix[i][j];
}

Graph Graph::operator*(int scalar) const
{
    //the result graph
    Graph graph2;
    //make sure graph 2 matrix has the same size of the original
    graph2.neighborMatrix.resize(neighborMatrix.size());
    for (size_t i = 0; i < neighborMatrix.size(); ++i) {
        graph2.neighborMatrix[i].resize(neighborMatrix[i].size());
        for (size_t j = 0; j < neighborMatrix[i].size(); ++j) {
            //multiply every edge with scalar (dont need to check if exist because x*0=0)
            graph2.neighborMatrix[i][j] = neighborMatrix[i][j]*scalar;
        }
    }
    return graph2;
}

Graph Graph::operator*(const Graph& graph2) const
{
   //because both n*n matrix we just need sure they have same size (n)
    if (!sizeCheck(neighborMatrix, graph2.neighborMatrix)) {
        throw std::invalid_argument("Matrix sizes are different");
    }
    //result graph
    Graph graph3;
    //make sure graph 3 matrix has the same size of other 2
    graph3.neighborMatrix.resize(neighborMatrix.size());
    for (size_t i = 0; i < graph3.neighborMatrix.size(); ++i) {
        graph3.neighborMatrix[i].resize(graph2.neighborMatrix[0].size());
    }


    // Perform matrix multiplication
    for (size_t i = 0; i < neighborMatrix.size(); ++i) {
        for (size_t j = 0; j < graph2.neighborMatrix[0].size(); ++j) {
            int sum = 0;
            for (size_t k = 0; k < graph2.neighborMatrix.size(); ++k) {
                //graph[i][j]=sum of i row in graph 1 and j column in graph 2
                sum += neighborMatrix[i][k] * graph2.neighborMatrix[k][j];
            }
            graph3.neighborMatrix[i][j] = sum;
        }
    }

    return graph3;
}

namespace ariel {


    std::ostream &operator<<(std::ostream &os, const Graph &graph) {
        for (size_t i = 0; i < graph.neighborMatrix.size(); ++i) {
            for (size_t j = 0; j < graph.neighborMatrix[i].size(); ++j) {
                os << graph.neighborMatrix[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

}

//****  OPERATORS  ****