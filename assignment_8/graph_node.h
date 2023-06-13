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
    //  primary functions
    void addEdge(GraphNode * destination, int weight);// add an edge
    vector<edge *> getNeighbors(); // get neighbors as a list of pointers

    // helper functions
    bool edgeExists(edge* edgePointer);// checks to see if an edge already exists
    bool isVisited();// helper function for dijkstras algorithm to determine whether the node has been visited
    GraphNode* getDParent();// returns dParent value
    int GraphNode::getDWeight();// returns dWeight value
    string getValue();// returns Value
    
    //testing functions
    void printNeighbors();// prints out values of all adjacent nodes

private:
    // private variables
    string value; // stored value
    vector<edge *> neighbors; // reference to neigbors
    bool visited;// temp bool value for dijkstras algorithm: defaults to false
    int dWeight;// temp weight for djkstras algorithm
    GraphNode* dParent;// temp parent for dijkstras algorithm

};