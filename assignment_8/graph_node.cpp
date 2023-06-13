/*graph_node.cpp
this file includes the implementation of the GraphNode class

further documentation included in design.md
*/

#include "graph_node.h"

GraphNode::GraphNode(string newName) {
    value = newName;
    visited = false;
}

GraphNode::~GraphNode() {// deletes node
    for(auto neighbor : neighbors){
        delete neighbor;
    }
    neighbors.clear();
}

void GraphNode::addEdge(GraphNode *destination, int weight) {
    edge *newEdge = new edge{this, destination, weight};
    neighbors.push_back(newEdge);
}

string GraphNode::getValue() {
    return value;
}

vector<edge *> GraphNode::getNeighbors() {
    return neighbors;
}

void GraphNode::printNeighbors() {// prints the names of the neigboring nodes
    vector<edge *> iterate = this->getNeighbors();
    for(int i=0; i < iterate.size(); i++ ) {
        cout << iterate[i]->destination->getValue() << ", ";
    }
    cout << endl;
}

bool GraphNode::isVisited(){return visited;}// helper function for dijkstras algorithm to determine whether the node has been visited

bool GraphNode::edgeExists(edge* edgePointer) {// checks to see if an edge already exists
        for (auto edge : neighbors ) {
            if (edge == edgePointer) {return true;}
        }
        return false;
    }