#include "Vertex.hpp"

Vertex::Vertex(std::string _name) {
    adjlist = std::vector<Edge *>();
    name = _name;
}
