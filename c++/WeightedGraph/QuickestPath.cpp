//
//  QuickestPath.cpp
//  WeightedGraph
//
//  Created by Eric Soros on 12/10/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "QuickestPath.h"
#include "WeightedGraph.h"
#include <vector>
#include <stack>
#include <map>
#include <string>
#include <sstream>

using std::string;
using std::vector;
using std::stack;
using std::map;

//convert a int to a string
string intToString(int i)
{
    std::stringstream str;
    str << i;
    return str.str();
}

//calculate the time that it would take to go a segment at speed
float timeTaken(int speedLimit)
{
    return (float)SEGMENT / speedLimit;
}

//find the node that has the smallest time that has not been visited. 
//if all of the nodes have been visitied, return -1
int findSmallest(map<int,float>& distance, map<int,bool>& visited)
{
    int smallestNode = -1;
    int smallestValue = (float)INFINITY;    
    
    map<int,float>::const_iterator it = distance.begin();
    for(; it != distance.end(); ++it)
    {
        int node = it->first;        
        if ( (!visited[node]) && distance[node] <= smallestValue )
        {
            smallestNode = node;
            smallestValue = distance[node];
        }
    }

    return smallestNode;
}

//find the quickest time from node src to all of the
//other nodes
//THANKS DIJKSTRA!
void quickestPath(WeightedGraph& g, int src, int destination)
{
    set<int> unvisitedNodes = g.getNodes();
    //maps the node to the distance to the node from the src node. 
    map<int,float> distanceToNode;
    for(set<int>::iterator it = unvisitedNodes.begin(); it != unvisitedNodes.end(); ++it)
        distanceToNode[*it] = (float)INFINITY;
    
    //maps the node to weither or not it has been visited yet
    map<int,bool> hasBeenVisited;
    for(set<int>::iterator it = unvisitedNodes.begin(); it!= unvisitedNodes.end(); ++it)
        hasBeenVisited[*it] = false;

    //maps a node to the nodes that it could havecome from when doing the shortest path algorithm
    //this is to generate all of the possible shortest paths.
    //if there are no previous nodes, than the vector will be empty. 
    map<int, vector<int> > previousNodes;
    for(set<int>::iterator it = unvisitedNodes.begin(); it != unvisitedNodes.end(); ++it)
        previousNodes[*it] = vector<int>();
    
    
    distanceToNode[src] = 0;
    int currentNode = src;

    //while unvisted nodes is not empty, Dijkstra's
    while(!unvisitedNodes.empty())
    {
        
        //set the distance to all nodes adjacent to current that have not been vistied, if the
        //distance is smaller
        vector<Edge> adj = g.getAdjacent(currentNode);
        
        for(vector<Edge>::const_iterator it = adj.begin();it != adj.end(); ++it)
        {
            if(!hasBeenVisited[(*it).node])
            {
                Edge e = *it;
                //if it's less than the current fastest time, we have to delete all the nodes in the
                //vector, and put the current node as 0th element of previous node. 
                float shortestDistance = distanceToNode[e.node];
                float checkDistance = distanceToNode[currentNode] + timeTaken(e.speedLimt);
                
                if(shortestDistance > checkDistance)
                {
                    distanceToNode[e.node] = checkDistance;
                    previousNodes[e.node].clear();
                    previousNodes[e.node].push_back(currentNode);
                    
                }
                //else if it's equal, we can keep the distanceToNode the same, and just add a node to the previousNodes
                else if (shortestDistance == checkDistance)
                {  
                    previousNodes[e.node].push_back(currentNode);
                }
            }
        }
        //mark the current node as visited, remove from unvisted list
        hasBeenVisited[currentNode] = true;
        set<int>::iterator it = unvisitedNodes.find(currentNode);
        
        //make sure that the unvisitied nodes isn't empty. It never should be at this point
        unvisitedNodes.erase(it);
        
        //visit the next node that has the shortest path to src that hasn't been visited
        currentNode = findSmallest(distanceToNode, hasBeenVisited);
    }
    
    printAllShortestPaths(previousNodes,destination,stack<int>());
    std::cout << " time taken: " << distanceToNode[destination];
}

//given the vector of previous nodes, the current node, and the destinatoin node,
//print out the shortest path
//DEPRECATED
void printSmallestPath(map<int,int>& previousNode, int destination)
{
    stack<int> nodes;
    float totalTime = 0.0;
    
    nodes.push(destination);
    while (previousNode[nodes.top()] != -1)
        nodes.push(previousNode[nodes.top()]);
    
    while(nodes.size() != 1)
    {
        std::cout << nodes.top() << " - ";
        nodes.pop();
    }
    std::cout << nodes.top();

}

//recursively print all of the shortest paths
//send in an empty stack for the first call. 
void printAllShortestPaths(map<int, vector<int> >& previousNodes, int currentNode, stack<int> nodes)
{
    nodes.push(currentNode);
    
    const vector<int>& previous = previousNodes[currentNode];
    //base case, if no more nodes, than we are done. 
    //because the nodes are backwards in the order of the path, we can
    //just pop them off the stack, so they will be in the correct order
    if(previous.empty())
    {
        while(nodes.size() > 1)
        {
            std::cout << nodes.top() << " - ";
            nodes.pop();
        }
        std::cout << nodes.top();
        std::cout << std::endl;
    }
    else
    {
        vector<int>::const_iterator it = previous.begin();
        for(; it != previous.end(); ++it)
            printAllShortestPaths(previousNodes, *it, nodes);
    }
}
