//
//  main.cpp
//  WeightedGraph
//
//  Created by Eric Soros on 11/22/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "WeightedGraph.h"
#include "DepthFirstSearch.h"

int main (int argc, const char * argv[])
{
    
    std::ifstream in;
    in.open(argv[1]);
    
    WeightedGraph g;
    in >> g;
    
    bool connected [10];
    depthFirstSearch(g, 0, connected);
    
    std::cout << g << std::endl;
    for(int i = 0; i < 10; ++i)
        std::cout << connected[i] << std::endl;
    
}

