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
        bool addNode(string name);// O(N)
        
        // potentially add an add edges function?
        bool addEdge(string source, string destination, int weight);// O(N)

        // Check if a node exists with the given name, returns true if node exists, false otherwise
        bool nodeExists(string name);// O(N)
        
        // determines whether an edge exists between two nodes
        bool edgeExists(string source, string destination);// O(N)
        
        // single-source shortest path
        string shortestPath(string source, string destination);// O(N**2)

        // finds the minimum spanning tree of the graph
        string minimumSpanningTree();// O(N**2)
        // end primary functions_________________________________________________________________________
        
        // generic helper functions
        // start----------------------------------------------------------------------------------------
        
        // finds an edge by checking the nodes
        edge *findEdgeHelper(string source, string destination);// O(N)
        
        // finds a node by name
        GraphNode *findNodeHelper(string name);// O(N)
        
        // travels from the source to the destination of the edge
        GraphNode* travelEdge(GraphNode* source, string destination);// O(N)
        
        // returns the index of a node in the graph based on the name of a node
        int getNodeIndex(string value);// O(N)
        
        //returns the node list
        vector<GraphNode *> getNodes();// O(1)
        
        // resets all node's public variables
        void resetNodePubs();// O(N)
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
        void toString();// O(N**2)
        
        // prints out names of all nodes in the graph
        void graphPrint();// O(N)
        // end test functions_________________________________________________________________________
        
        
    private:
    
        // private variables
        vector<GraphNode *> nodes;// stores all nodes in the graph
        
        // private functions
        // shortest path specific helper functions
        // start----------------------------------------------------------------------------------------
        
        //returns the node with the current smallest weight that has not been visited by dijkstras algorithm
        GraphNode* minWeightNode();// O(N)
        
        // converts the shortest path found using shortest path to a string
        string pathToString(GraphNode *destination);// O(N)
        
        // exectutes dijkstras algorithm
        void dijkstrasAlgorithm(GraphNode *sourceNode, GraphNode *destinationNode);// O(N**2)
        // end shortest path functions_________________________________________________________________________

        // minimum spanning tree specific functions
        // start----------------------------------------------------------------------------------------
        
        // builds a vector of edges sorted by weight
        vector<pair<int, edge*>> buildEdgeVector();// O(N**2)
        
        // testing function to print out edges in buildEdgeVector's vector 
        void printEdges(vector<pair<int, edge*>> edges);// O(N)
        
        // initializes dWeight variable to work with minimum spanning tree algorithm
        void initSets();// O(N)
        
        // updates dweight in min spanning tree to the lowest value between all connected nodes
        // returns true if all nodes dWeight values are the same
        bool updateNodeSet(int source, int destination);// O(N)

        // converts a list of edges to a string
        string spanToString(vector<edge*> spanningTree);// O(N)
        // end minimum spanning tree functions_________________________________________________________________________

};
