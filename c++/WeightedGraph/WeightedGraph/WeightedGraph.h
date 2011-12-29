//
//  WeightedGraph.h
//  WeightedGraph
//
//  Created by Eric Soros on 11/22/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#ifndef WeightedGraph_WeightedGraph_h
#define WeightedGraph_WeightedGraph_h

#include <vector>
#include <map>
using std::map;
using std::vector;
//edge class that connects Nodes on the graph
class  Edge
{
    public:
        //what node the edge connects
        int node;
        //the weight
        int weight;
        Edge(): node(), weight() {};
        Edge(int t_node, int t_weight): node(t_node), weight(t_weight) {};
};


using std::vector;

class WeightedGraph
{
    private:
        //a graph of vectos that represent all of the nodes that 
        //connect to the node at a certain point.
        //graph[0] will be a list of edges, which contain the
        //node it is connected to and it's weight
        map<int, vector<Edge> > graph;
        int vertices;
        int edges;
    public:
        //default constructor
        WeightedGraph(): graph(), vertices(), edges() {};
        //add a new node, with no edges
        void addNewNode(int);
        //add a new edge. 
        //graph[node] will connect to edge
        void addEdge(int, const Edge&);
        //print all of the nodes that are adjacent to n
        void printAdjacent(int);
        void setEdges(int t_edges) {edges = t_edges;};
    void setVertices(int t_vertices) {vertices = t_vertices;};
    
        //return an iterator to the adjacency vector
    vector<Edge> getAdjacent(int);
            
    friend std::ostream& operator<<(std::ostream&, const WeightedGraph&);
    friend std::istream& operator>>(std::istream&,WeightedGraph& g);
};

#endif
