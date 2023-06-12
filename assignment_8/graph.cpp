/*graph.cpp
this file includes the implementation of the Graph class

further documentation included in design.md
*/

#include "graph.h"

Graph::Graph() {
    // do nothing for now for now
}

Graph::~Graph(){
    for (auto node : nodes){
        delete node;
    }
    nodes.clear();
}

// Add a node using name, returns true if the node is added, false otherwise
bool Graph::addNode(string newName) {
    if (nodeExists(newName)) {return false;}// checks if node name already exists and returns false if duplicate
    // create a node
    GraphNode *newNode = new GraphNode(newName);
    //add to nodes list
    nodes.push_back(newNode);
    return true;
}

// Add an edge using source and destination as names of nodes to connect, returns true if the edge is added, false otherwise
// adds undirected edges
bool Graph::addEdge(string sourceName, string destinationName, int weight) {
    if ((nodeExists(sourceName) && nodeExists(destinationName)) == false) {return false;}
    
    // find and create pointers to source and destination
    GraphNode *source = findNodeHelper(sourceName);
    GraphNode *destination = findNodeHelper(destinationName);
    
    // create a new edge with proper parameters
    source->addEdge(destination, weight);
    destination->addEdge(source, weight);

    return true;
}

// // Remove a node if it exists, returns true if a node is removed, false otherwise
// bool Graph::removeNode(string name) {

// }

// // Remove an edge if it exists, returns true if an edge is removed, false otherwise
// bool Graph::removeEdge(string source, string destination) {
    
//     GraphNode* source_node = findNodeHelper(source);

//     // GraphNode* source_node = findNodeHelper(destination);

// }

// Check if a node exists with the given name, returns true if node exists, false otherwise...
bool Graph::nodeExists(string name) {
    if (findNodeHelper(name) == nullptr) {
        return false;
    }
    return true;
}

// Check if an edge exists with the given name, returns true if edge exists, false otherwise...
bool Graph::edgeExists(string source, string destination) {
    GraphNode* sourceNode = findNodeHelper(source);
    if (sourceNode == nullptr) {return false;}
    if (travelEdge(sourceNode, destination) == nullptr) {return false;}
    return true;
}

/* Print out all nodes and edges in the form:
    a -> b, c, e
    b -> d, q
    c -> a, b, e, q
    ...
*/
void Graph::toString() {// testing function to verify everything is being stored properly
//prints all nodes and their neighbors
    for (auto node : nodes) {
        cout << node->getValue() << " -> ";
        for (auto edge : node->getNeighbors()) {
            cout << edge->destination->getValue() << ", ";
        }
        cout << endl;
    }
    cout << endl;
}

void Graph::graphPrint() {// prints a string representation of all nodes in the graph
            for (auto node : nodes) {
                cout << node->getValue() << ", ";
            }
            cout << endl;
        }

GraphNode* Graph::travelEdge(GraphNode* source, string destination) {// travels from the source to the destination of the edge by walking over the edge
    for (auto edge : source->getNeighbors()) {
        if (edge->destination->getValue() == destination) {// compare the value of the edge destination to destination argument
            return edge->destination;
        }
    }
    return nullptr;
}

// // Find shortest path from node with name to each other node that can be reached, returns a string with that information
// string Graph::shortestPath(string name) {// Dijkstras algorithm implementation

// }

// // Find a minimum spanning tree and return it.
// string Graph::minimumSpanningTree() {

// }


// // Start of private functions
// Finds the node with name, return pointer to that node
GraphNode *Graph::findNodeHelper(string name) {
    for (auto node : nodes) {// iterates through the list of nodes
        if (node->getValue() == name) {// checks for equivalence with string input
            return node;
        }
    }
    return nullptr;
}

// Finds the edge with named source and destination, return pointer to that edge
edge *Graph::findEdgeHelper(string source, string destination) {
    if ((nodeExists(source) && nodeExists(destination)) == false) {return nullptr;}// returns null if the node does not exist
    GraphNode *sourceNode = findNodeHelper(source);
    for (auto edge : sourceNode->getNeighbors())// iterates through neighbors list
        if (edge->destination->getValue() == destination) {
            return edge;
        }
    return nullptr;
}

