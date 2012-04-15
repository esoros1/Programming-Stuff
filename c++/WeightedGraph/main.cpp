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
#include "QuickestPath.h"

//make a new graph which is n by n
void makeNewGraph(int n, WeightedGraph& g)
{
    //set the terminal node
    g.setTerminalNode((n-1) * 10 + (n-1));
    
    //make a vector of nodes that need to be added
    std::vector<int> graphNodes;
    for(int i = 0; i < n* 10; i += 10)
    {
        for(int j = 0; j < n; ++j)
        {
            g.addNewNode(i+j);
            graphNodes.push_back(i+j);
        }
    }

    //all of the nodes that aren't on the right or top get the next one above and
    //to the right added. The ones all the way on the right get only the top added.
    //the ones on the top only get the one to the right added
    for(int i = 0; i < graphNodes.size(); ++i)
    {
        int node = graphNodes[i];
        
        //check to see if it is on the top
        //if so, add only the one to the right
        if(node/10 == n-1)
        {
            //check to see if it is the top
            if(node != (n-1) * 10 + (n-1))
               g.addEdge(node,Edge(node+1,0));
        }
        //else it is not in the top row. check to see if it is on the right
        //if it is, only add the one above. Else, add both the right and the top
        else 
        {
            //check for the right
            if(node % 10 == (n-1))
            {
                g.addEdge(node, Edge(node+10,0));
            }
            //else add both
            else
            {
                g.addEdge(node, Edge(node+10,0));
                g.addEdge(node, Edge(node+1,0));
            }
        }
    }
}


int main (int argc, const char * argv[])
{
    WeightedGraph g;
    makeNewGraph(3, g);
    
    g.changeWeight(0, 1,  100);
    g.changeWeight(0, 10, 100);
    g.changeWeight(1, 2,  100);
    g.changeWeight(1, 11, 100);
    g.changeWeight(2, 12, 100);
    g.changeWeight(10, 11, 10);
    g.changeWeight(10, 20, 100);
    g.changeWeight(11, 12, 100);
    g.changeWeight(11, 21, 10);
    g.changeWeight(12, 22, 100);
    g.changeWeight(20, 21, 100);
    g.changeWeight(21, 22, 100);
    
    std::cout << g << std::endl;
        
    processGrid(g, 0,0, vector<Edge>(), std::cout);
    quickestPath(g, 0, 22);
}

