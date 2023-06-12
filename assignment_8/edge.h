/*edge.h
this file defines the edge struct

further documentation included in design.md
*/
#pragma once

#include "graph_node.h"
#include <iostream>
using std::cout;
using std::endl;

class GraphNode;

struct edge {
    // add name and update code to act more like nodes?
    GraphNode *source;
    GraphNode *destination;
    int weight;
};