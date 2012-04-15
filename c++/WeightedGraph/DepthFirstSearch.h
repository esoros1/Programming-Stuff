//
//  DepthFirstSearch.h
//  WeightedGraph
//
//  Created by Eric Soros on 11/23/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef WeightedGraph_DepthFirstSearch_h
#define WeightedGraph_DepthFirstSearch_h

#include "WeightedGraph.h"
#include <set>
#include <vector>

const int SEGMENT_LENGTH = 100; 
void depthFirstSearch(WeightedGraph&, int, bool[]);
void processGrid(WeightedGraph&, int, int, vector<Edge>, std::ostream&);
bool isDeadEnd(const vector<Edge>&, const std::vector<Edge>&);
bool isNodeInVector(const std::vector<Edge>&, int);
int sumVector(const std::vector<Edge>&);

float calculateTimeTaken(const vector<Edge>&);

#endif
