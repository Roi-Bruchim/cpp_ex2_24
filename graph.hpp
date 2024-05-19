#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include <iostream>

//roibr23@gmail.com 322695883

// create ariel name space
namespace ariel {
    class Graph {
    private:
        // the graph will be neighbor matrix
        std::vector<std::vector<int>> neighborMatrix;

    public:
        //constructor and distractor
        Graph();
        ~Graph();

        /**
         * First make sure that the matrix is square and than put her to the graph
         * @param matrix the given matrix
         */
        void loadGraph(const std::vector<std::vector<int>>& matrix);
        /**
         * print the graph as matrix of neighbors
         */
        void printGraph() const;
        /**
         *
         * @return the Neighbor matrix
         */
        const std::vector<std::vector<int>>& getNeigborMatrix() const;

        //*******************EX2**********************


        /**
         * Helper method that checks if 2 matrix's are the same size
         * @param matrix1 first matrix to compare
         * @param matrix2 second matrix to compare
         * @return if same size return true else return false
         */
        bool sizeCheck(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2) const;
        /**
         * This method adds two graphs together
         * @param graph2 the graph to be added
         * @return The resulting graph (graph3) after addition
         */
        Graph operator+(const Graph& graph2) const;
        /**
         * This method add to original graph, graph2
         * @param graph2 the graph to be added
         */
        void operator+=(const Graph& graph2);
        /**
         * This method will do unary plus to the graph
         */
        Graph operator+() const;
        /**
      * This method subtract two graphs
      * @param graph2 the graph to be subtracted
      * @return The resulting graph (graph3) after subtraction
      */
        Graph operator-(const Graph& graph2) const;
        /**
         * This method subtract the original graph with graph2
         * @param graph2 the graph that subtract original graph
         */
        void operator-=(const Graph& graph2);
        /**
         * This method will do unary minus to the graph
         */
        Graph operator-() const;
        /**
         * This method compares 2 graphs and check if they in same size and have the same weighs on their edges
         * @param graph2 the second graph we compare
         * @return true if they are equals and false if not
         */
        bool operator==(const Graph& graph2) const;
        /**
       * This method compares 2 graphs and check if they in same size and have the same weighs on their edges
       * @param graph2 the second graph we compare
       * @return true if they are  NOT equals and false if they are equals
       */
        bool operator!=(const Graph& graph2) const;
        /**
         * Helper method that check if every edge in the graph is also in graph2
         * @param graph1 first matrix to compare
         * @param graph2 second matrix to compare
         * @return true if g1 contains g2
         */
        bool contains(const Graph& graph1, const Graph& graph2) const;
        /**
         * Helper method that sum number of the graph edges
         * @param graph the given graph
         * @return number of edges
         */
        size_t getNumEdges(const Graph& graph) const;
        /**
         * This method check if graph is greater than graph2
         * @param graph2 second graph
         * @return true if the graph is greater than graph2
         */
        bool operator>(const Graph& graph2) const;
        /**
         * This method check if graph is greater or equal than graph2
         * @param graph2 second graph
         * @return true if the graph is greater or equal than graph2
         */
        bool operator>=(const Graph& graph2) const;
        /**
         * This method check if graph2 is greater than original graph
         * @param graph2 second graph
         * @return true if the graph2 is greater than original graph
         */
        bool operator<(const Graph& graph2) const;
        /**
         * This method check if graph2 is greater or equal than original graph
         * @param graph2 second graph
         * @return true if the graph2 is greater or equal than original graph
         */
        bool operator<=(const Graph& graph2) const;
        /**
         * This method will add 1 to all graph edges (only if the edge exist)
         */
        void operator++();
        /**
        * This method will subtract 1 to all graph edges (only if the edge exist)
        */
        void operator--();
        /**
         * This method will multiply all edges by given scalar
         * @param scalar the given scalar
         * @return multipleied graph by the scalar
         */
        Graph operator*(int scalar) const;
        /**
         *This method will multiply 2 matrix's
         * @param graph2 given graph to multiply with
         * @return result graph of multiplication matrix
         */
        Graph operator*(const Graph& graph2) const;
        /**
         * This method will print the graph as neighbor matrix
         * if there isn't an edge it will show 0 else shows the weigth of the edge
         * @param os The output stream
         * @param graph The graph to be printed
         */
        friend std::ostream& operator<<(std::ostream& os, const Graph& graph);



    };
    std::ostream& operator<<(std::ostream& os, const Graph& graph);
}

#endif // GRAPH_H