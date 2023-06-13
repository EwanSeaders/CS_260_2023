/*graph.h
header file for graph.cpp

further documentation included in design.md
*/

#pragma once
#include "graph_node.h"

class Graph {
    public:
        Graph();
        ~Graph();

        bool addNode(string name);// adds a GraphNode
        bool addEdge(string source, string destination, int weight); // potentially add an add edges function?
        
        // maybe add an interactive add edge function that lists the node names that exist in the graph?
        bool removeNode(string name); // maybe also have it remove associated edges!
        bool removeEdge(string source, string destination);

        bool nodeExists(string name); // call to helper!
        bool edgeExists(string source, string destination);
        
        GraphNode* travelEdge(GraphNode* source, string destination);// travels from the source to the destination of the edge

        void toString();// prints out a string representation of the each node and its neighbors
            /*
                a -> b, c, e
                b -> d, q
                c -> a, b, e, q
                ...
            */
           

        string shortestPath(string name); // single-source shortest path
        string minimumSpanningTree();

        void graphPrint();

        edge *findEdgeHelper(string source, string destination);// finds an edge by checking the nodes
        GraphNode *findNodeHelper(string name);

        int getNodeIndex(string value);// returns the index of a node in the graph based on the name of a node
        
    private:
        vector<GraphNode *> nodes;
        
};