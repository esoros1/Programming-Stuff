//
//  DepthFirstSearch.cpp
//  WeightedGraph
//
//  Created by Eric Soros on 11/23/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include "WeightedGraph.h"
#include "DepthFirstSearch.h"

//pass in a Graph, a starting point, and a bool array
//mark off every part of the bool array that is connected
//to the source
void depthFirstSearch(WeightedGraph& graph, int src, bool marked[])
{
    std::vector<Edge> adj = graph.getAdjacent(src);
    std::cout << src << std::endl;
    for(int i = 0; i < adj.size(); ++i)
        std::cout << adj[i].node << std::endl;
    marked[src] = true;
    for(size_t i = 0; i < adj.size(); ++i)
    {
        if(marked[adj[i].node] == false)
            depthFirstSearch(graph, adj[i].node, marked);
    }
}
