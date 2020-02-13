#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Vertex.hpp"
#include "Edge.hpp"

class Graph {
public:
  std::vector<Vertex *> vlist;
  Graph();
    void addup(int small);
    std::vector<int> myEdges;
    
  void addVertex(std::string);
  Vertex *getVertex(std::string);
  void addEdge(std::string, std::string, int);
  Edge *getEdge(std::string, std::string);
  int MSTCost();
  Graph *MST();
    Graph *mstGraph;
  int SPCost(std::string, std::string);
  Graph *SP(std::string, std::string);
};

#endif
