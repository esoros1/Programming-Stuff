//
//  DepthFirstSearch.cpp
//  WeightedGraph
//
//  Created by Eric Soros on 11/23/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>

#include "WeightedGraph.h"
#include "DepthFirstSearch.h"

using std::vector;

//try to see if the node is in the vector. I would use a set, but that puts the 
//elements in numerical order, and I need them in the ordere that they were put in.
bool isNodeInVector(const vector<Edge>& nodeVector, int node)
{
    vector<Edge>::const_iterator it = nodeVector.begin();
    for(; it != nodeVector.end(); ++it)
    {
        if((*it).node == node)
            return true;
    }
    return false;
}


//pass in a Graph, a starting point, and a bool array
//mark off every part of the bool array that is connected
//to the source
void depthFirstSearch(WeightedGraph& graph, int src, bool visited[])
{
    visited[src] = true;
    vector<Edge> adj = graph.getAdjacent(src);
    
    //visit all of the adjacent nodes that haven't already
    //been visited
    for(size_t i = 0; i < adj.size(); ++i)
    {
            if(visited[adj[i].node] == false)
                depthFirstSearch(graph, adj[i].node, visited);
    }
        
}
//recursively find all the paths to the end. 
void processGrid(WeightedGraph& g, int currentNode, int currentNodeSpeed, vector<Edge> visitedNodes, std::ostream& out)
{
    std::vector<Edge> adj = g.getAdjacent(currentNode);
    visitedNodes.push_back(Edge(currentNode,currentNodeSpeed));
    //we have reached the destination
    if(currentNode == g.getTerminalNode())
    {
        out << "Destionation reached " << std::endl;
        
        vector<Edge>::iterator it;
        for(it = visitedNodes.begin(); it != visitedNodes.end(); ++it)
            out << (*it).node << " - ";
        
        long distanceTraveled = (visitedNodes.size() * SEGMENT_LENGTH) - 100;
        out << "Distance Traveled: " << distanceTraveled << " Kilometers " << std::endl;
        float timeTaken = calculateTimeTaken(visitedNodes);
        out << "Time Taken: " << timeTaken << std::endl;      
        out << std::endl;
    }
    //we have no more moves left
    else if(isDeadEnd(visitedNodes, adj))
    {
        //out << "Dead End " << std::endl;
        
        //vector<Edge>::iterator it;
        //for(it = visitedNodes.begin(); it != visitedNodes.end(); ++it)
        //out << (*it).node << " - ";
        //out << std::endl << std::endl;    
    }
    //recursively visit all the adjacent nodes
    else
    {
        for(int i = 0; i < adj.size(); ++i)
        {
            if(!isNodeInVector(visitedNodes, adj[i].node))
            { 
                //std::cout << "Processing Node: " << adj[i].node << std::endl;
                processGrid(g, adj[i].node, adj[i].speedLimt, visitedNodes, out);
            }
        }
    }

}
//see if we have reached a "dead end", or all of the nodes in adjacent have
//been visited already. 
bool isDeadEnd(const vector<Edge>& visitedNodes, const std::vector<Edge>& adj)
{
    for(int i = 0; i < adj.size(); ++i)
    {
        int checkNode = adj[i].node;
        if (!isNodeInVector(visitedNodes,checkNode))
            return false;
    }
    return true;
}

int sumVector(const vector<Edge>& edgeVector)
{
    int result = 0;
    
    for(int i = 0; i < edgeVector.size(); ++i)
        result += edgeVector[i].speedLimt;
    return result;
}

float calculateTimeTaken(const vector<Edge>& edgeVector)
{
    float result = 0.0;
    
    for(int i = 1; i < edgeVector.size(); ++i)
    {
        result +=(float)SEGMENT_LENGTH/edgeVector[i].speedLimt;
        std::cout << edgeVector[i].speedLimt << std::endl;
    }
    return result;
}


