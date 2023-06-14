/*graph.h
header file for graph.cpp

further documentation included in design.md
*/

#pragma once
#include "graph_node.h"
// #include "dijkstra_table.h"


class Graph {
    public:
        Graph();
        ~Graph();

        // primary functions
        // start----------------------------------------------------------------------------------------
        
        // adds a GraphNode
        bool addNode(string name);
        
        // potentially add an add edges function?
        bool addEdge(string source, string destination, int weight);

        // Check if a node exists with the given name, returns true if node exists, false otherwise
        bool nodeExists(string name);
        
        // determines whether an edge exists between two nodes
        bool edgeExists(string source, string destination);
        
        // single-source shortest path
        string shortestPath(string source, string destination);

        // finds the minimum spanning tree of the graph
        string minimumSpanningTree();
        // end primary functions_________________________________________________________________________
        
        // generic helper functions
        // start----------------------------------------------------------------------------------------
        
        // finds an edge by checking the nodes
        edge *findEdgeHelper(string source, string destination);
        
        // finds a node by name
        GraphNode *findNodeHelper(string name);
        
        // travels from the source to the destination of the edge
        GraphNode* travelEdge(GraphNode* source, string destination);
        
        // returns the index of a node in the graph based on the name of a node
        int getNodeIndex(string value);
        
        //returns the node list
        vector<GraphNode *> getNodes();
        
        // resets all node's public variables
        void resetNodePubs();
        // end generic helper functions_________________________________________________________________________
        
        // testing/print out functions
        // start----------------------------------------------------------------------------------------
            
            /*
            prints out a string representation of the each node and its neighbors in this format:
                a -> b, c, e
                b -> d, q
                c -> a, b, e, q
                ...
            */
        void toString();
        
        // prints out names of all nodes in the graph
        void graphPrint();
        // end test functions_________________________________________________________________________
        
        
    
        // private variables
        vector<GraphNode *> nodes;
        
        // private functions
        // shortest path specific helper functions
        // start----------------------------------------------------------------------------------------
        
        //returns the node with the current smallest weight that has not been visited by dijkstras algorithm
        GraphNode* minWeightNode();
        
        // converts the shortest path found using shortest path to a string
        string pathToString(GraphNode *destination);
        
        // exectutes dijkstras algorithm
        void dijkstrasAlgorithm(GraphNode *sourceNode, GraphNode *destinationNode);
        // end shortest path functions_________________________________________________________________________

        // minimum spanning tree specific functions
        // start----------------------------------------------------------------------------------------
        
        // builds a vector of edges sorted by weight
        vector<pair<int, edge*>> buildEdgeVector();
        
        // testing function to print out edges in buildEdgeVector's vector 
        void printEdges(vector<pair<int, edge*>> edges);
        
        // initializes dWeight variable to work with minimum spanning tree algorithm
        void initSets();
        
        // updates dweight in min spanning tree to the lowest value between all connected nodes
        // returns true if all nodes dWeight values are the same
        bool updateNodeSet(int source, int destination);

        
        // converts a list of edges to a string
        string spanToString(vector<edge*> spanningTree);
        // end minimum spanning tree functions_________________________________________________________________________

    private:
};
