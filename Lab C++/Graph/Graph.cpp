#include <iostream>

#include "Graph.hpp"

Graph::Graph() {
    vlist = std::vector<Vertex *>();
}

void Graph::addVertex(std::string name) {
    vlist.push_back(new Vertex(name));
}

Vertex *Graph::getVertex(std::string name) {
    for (int i = 0; i < vlist.size(); ++i) {
        if (vlist[i]->name == name) {
            return vlist[i];
        }
    }
    return NULL;
}

void Graph::addEdge(std::string from, std::string to, int weight) {
    Edge* myedge = new Edge(getVertex(from), getVertex(to), weight);
    Edge* myedge2 = new Edge(getVertex(to), getVertex(from), weight);
    getVertex(from)->adjlist.push_back(myedge);
    getVertex(to)->adjlist.push_back(myedge2);
}

Edge *Graph::getEdge(std::string from, std::string to) {
    for (int i = 0; i < getVertex(from)->adjlist.size(); ++i) {
        if (getVertex(from)->adjlist[i]->to == getVertex(to)) {
            return getVertex(from)->adjlist[i];
        }
    }
    return NULL;
}

void Graph::addup(int small) {
    myEdges.push_back(small);
    //std::cout << small << std::endl;
}

int Graph::MSTCost() {
    int graphTot = 0;
    
    for (int i = 0; i < myEdges.size(); ++i) {
        graphTot += myEdges[i];
    }
    
    return graphTot;
}

Graph *Graph::MST() {
    myEdges = std::vector<int>();
    Graph* mstGraph = new Graph();
    std::string fromName;
    std::string toName;

    if (vlist.size() > 0) {
        mstGraph -> vlist.push_back(vlist[0]);
        while (mstGraph -> vlist.size() < vlist.size()) {
            int smallest = 999;

            for (int i = 0; i < mstGraph -> vlist.size(); ++i) {
                

                for (int j = 0; j < mstGraph -> vlist[i] -> adjlist.size(); ++j) {
                    Vertex * tempV = mstGraph -> vlist[i];
                    int testWeight = tempV -> adjlist[j] -> weight;
                    

                    bool found = false;
                    for (int k = 0; k < myEdges.size(); ++k) {
                        if (testWeight == myEdges[k]) {
                            found = true;

                        }
                    }

                    if (!found && (testWeight < smallest)) {
                        smallest = testWeight;
                        std::string fromName = tempV -> adjlist[j] -> to -> name;
                        std::string toName = tempV -> adjlist[j] -> from -> name;
                    }
                }
            }

            mstGraph -> addVertex(fromName);
            mstGraph -> addEdge(fromName, toName, smallest);
            addup(smallest);

        }

    }
    return mstGraph;
}

int Graph::SPCost(std::string from, std::string to) {
  return -1;
}

Graph *Graph::SP(std::string from, std::string to) {
  return NULL;
}
