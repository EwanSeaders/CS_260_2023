/*graph_node.cpp
this file includes the implementation of the GraphNode class

further documentation included in design.md
*/

#include "graph_node.h"

GraphNode::GraphNode(string newName) {
    value = newName;
    resetPubs();
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

bool GraphNode::edgeExists(edge* edgePointer) {// checks to see if an edge already exists
        for (auto edge : neighbors ) {
            if (edge == edgePointer) {return true;}
        }
        return false;
    }

bool GraphNode::isVisited(){return visited;}// helper function for dijkstras algorithm to determine whether the node has been visited

int GraphNode::getDWeight() {return dWeight;}



GraphNode* GraphNode::getDParent() {return dParent;}// returns dParent value

void GraphNode::resetPubs() {
    visited = false;
    dParent = nullptr;
    dWeight = 999999999;
}

// bool GraphNode::nodeInSet(GraphNode* node){// checks whether a node is in setNodes
//     for (auto elem : setNodes) {
//         if (elem == node) {return true;}
//     }
//     return false;
// }

