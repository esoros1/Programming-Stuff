//
//  QuickestPath.h
//  WeightedGraph
//
//  Created by Eric Soros on 12/10/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef WeightedGraph_QuickestPath_h
#define WeightedGraph_QuickestPath_h

#include "WeightedGraph.h"
#include <vector>
#include <map>
#include <string>
#include <stack>
#include "limits.h"
using std::vector;

const int INFINITY = INT_MAX;
//100 meters per segment
const int SEGMENT = 100; 

std::string intToString(int);
float timeTaken(int);
void quickestPath(WeightedGraph&, int, int);
int findSmallest(std::map<int,int>&, std::map<int,bool>&);
void printSmallestPath(std::map<int,int>&,int);
void printAllShortestPaths(std::map<int,vector<int> >&,int, std::stack<int>); 

#endif
