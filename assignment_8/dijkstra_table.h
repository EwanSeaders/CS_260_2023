/*dijkstra_table.h
this file contains the struct for the table used in Graph.cpp's implementation of dijkstras algorithm
*/


#pragma once
#include "graph.h"
#include <vector>
#include <iostream>

class Graph;


class DijkstraTable{
public: 
    vector<GraphNode*> nodeList;
    vector<GraphNode*> predecessorList;
    vector<int> currWeight;
    
};