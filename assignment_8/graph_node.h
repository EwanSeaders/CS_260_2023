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
    
    
    // public variable functions
    
    // resets the public variables to default values
    void resetPubs();// O(1)
    

    //  primary functions
    
    // add an edge
    void addEdge(GraphNode * destination, int weight);// O(1)

    // helper functions
    
    // get neighbors as a list of pointers
    vector<edge *> getNeighbors();// O(1)
    
    // checks to see if an edge already exists
    bool edgeExists(edge* edgePointer);// O(N)
    
    // helper function for dijkstras algorithm to determine whether the node has been visited
    bool isVisited();// O(1)
    
    // returns dParent value
    GraphNode* getDParent();// O(1)
    
    // returns dWeight value
    int getDWeight();// O(1)
    
    // returns Value
    string getValue();// O(1)
    
    
    //testing functions
    
    // prints out values of all adjacent nodes
    void printNeighbors();// O(N)

private:
    // private variables
    string value; // stored value
    vector<edge *> neighbors; // vector of neigbors
    
};