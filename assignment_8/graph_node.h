/*graph_node.h
header file for graph_node.cpp

further documentation included in design.md
*/

#pragma once

#include "edge.h"
#include <algorithm>
#include <string>
#include <vector>

using std::pair;
using std::string;
using std::vector;
using std::min;
using std::max;
using std::sort;

class GraphNode {
public:
    GraphNode(string newName);
    ~GraphNode();
    
    // public variables
    bool visited;// temp bool value for dijkstras algorithm: defaults to false
    int dWeight;// temp weight for djkstras algorithm and temp value to represent the sets in min spanning tree algorithm
    GraphNode* dParent;// temp parent for dijkstras algorithm
    // vector<GraphNode*> setNodes;
    // public variable functions
    bool nodeInSet(GraphNode* node);// checks whether a node is in setNodes
    void resetPubs();// resets the public variables to default values
    
    

    //  primary functions
    void addEdge(GraphNode * destination, int weight);// add an edge

    // helper functions
    vector<edge *> getNeighbors(); // get neighbors as a list of pointers
    bool edgeExists(edge* edgePointer);// checks to see if an edge already exists
    bool isVisited();// helper function for dijkstras algorithm to determine whether the node has been visited
    GraphNode* getDParent();// returns dParent value
    int getDWeight();// returns dWeight value
    string getValue();// returns Value
    
    //testing functions
    void printNeighbors();// prints out values of all adjacent nodes

private:
    // private variables
    string value; // stored value
    vector<edge *> neighbors; // reference to neigbors
    

};