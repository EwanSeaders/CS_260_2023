/*graph_node.h
header file for graph_node.cpp

further documentation included in design.md
*/

#pragma once

#include <string>
#include <vector>

#include "edge.h"

using std::string;
using std::vector;

class GraphNode {
public:
    GraphNode(string newName);
    ~GraphNode();
    // add an edge
    void addEdge(GraphNode * destination, int weight);

    // get value
    string getValue();
    
    // get list of neighbors
    vector<edge *> getNeighbors(); // get neighbors as a list of pointers
    void printNeighbors();

    bool edgeExists(edge* edgePointer);// checks to see if an edge already exists
    bool isVisited();// helper function for dijkstras algorithm to determine whether the node has been visited

private:
    string value; // stored value
    vector<edge *> neighbors; // reference to neigbors
    bool visited;
};