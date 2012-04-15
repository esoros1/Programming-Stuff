//
//  WeightedGraph.cpp
//  WeightedGraph
//
//  Created by Eric Soros on 11/22/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include "WeightedGraph.h"
#include <cassert>
using std::vector;
using std::map;
void WeightedGraph::addNewNode(int node)
{
    //add a new node with no edges
    //graph[node] will equal a blank vector
    graph[node] = vector<Edge>();
}

//add a new edge to an existing node
void WeightedGraph::addEdge(int node, const Edge& e)
{
    //check to see if node is in the graph
    size_t check = graph.count(node);
    assert(check == 1);
    
    graph[node].push_back(e);
    //check to see if e.node is in the graph
    if(graph.count(e.node) == 0)
        graph[e.node] = vector<Edge>();
    graph[e.node].push_back(Edge(node,e.speedLimt));
}

//print all of the adjacent nodes
void WeightedGraph::printAdjacent(int node)
{
    vector<Edge> adjacent = graph[node];
    for(size_t i = 0; i < adjacent.size(); ++i)
    {
        std::cout << " node: " << adjacent[i].node <<" weight: " << adjacent[i].speedLimt;
    }
     
}

std::ostream& operator<<(std::ostream& out, const WeightedGraph& g)
{
    out <<"vertices "<< g.vertices <<" edges " << g.edges << std::endl;
    //iterate through the nodes, and print out all of the adjacent nodes
    map<int, vector<Edge> >::const_iterator it;
    for ( it = g.graph.begin() ; it != g.graph.end(); it++ )
    {
        out << (*it).first <<": ";
        //iterate through and print the adjacent nodes
        vector<Edge> adjacent = (*it).second;
        for(size_t i = 0; i < adjacent.size(); ++i)
            out << adjacent[i].node <<" ";
        
        out << std::endl;
    }
    return out;
}

std::istream& operator>>(std::istream& in, WeightedGraph& g)
{
    //get vertices
    in >> g.vertices;
    //get number of edges
    in >> g.edges;
    
    //loop through the number of edges, and create the map
    //one edge per line
    for(int i = 0; i < g.edges; ++i)
    {
        int node1, node2;
        in >> node1;
        in >> node2;
        
        //check to see if edge1 and edge2 are not in the graph
        if(g.graph.count(node1) == 0)
        {
            g.graph[node1] = vector<Edge>();
        }
    
        if(g.graph.count(node2) == 0)
        {
            g.graph[node2] = vector<Edge>();
        }
        //add the nodes to each other;s vectors
        g.graph[node1].push_back(Edge(node2,0));
        g.graph[node2].push_back(Edge(node1,0));
    }
    
    return in;
}
    
//return a vector of adjacent nodes
vector<Edge> WeightedGraph::getAdjacent(int node)
{
    return graph[node];
}
//return a set of all the nodes in the graph
set<int> WeightedGraph::getNodes()
{
    set<int> result;
    
    map<int, vector<Edge> >::const_iterator it;
    for(it = graph.begin(); it != graph.end(); ++it)
    {
        result.insert((*it).first);
    }
    
    return result;
}

//change the weight that connects the two nodes to weight
void WeightedGraph::changeWeight(int node1, int node2, int weight)
{
    //change the edge from node1 - node2
    vector<Edge>::iterator it = graph[node1].begin();
    for(; it != graph[node1].end(); ++it)
    {
        if(it->node == node2)
        {
            it->speedLimt = weight;
            //no need to check the rest of the vector
            break;
        }
    }
    //change the value from node2 - node1
    it = graph[node2].begin();
    for(; it != graph[node2].end(); ++it)
    {
        if(it->node == node1)
        {
            it->speedLimt = weight;
            //again, no need to go any further
            break;
        }
    }
}
