#include "adjacency_list_graph.hpp"

namespace itis {

int AdjacencyListGraph::numEdges() const { return num_edges_; }

int AdjacencyListGraph::numVertices() const { return num_vertices_; }

bool AdjacencyListGraph::Exists(int v) const {
  // TODO: implement me, pls
  return false;
}

bool AdjacencyListGraph::Exists(int u, int v) const {
  // TODO: implement me, pls
  return false;
}

int AdjacencyListGraph::AddVertex() {
  // TODO: implement me, pls
  return 0;
}

bool AdjacencyListGraph::RemoveVertex(int v) {
  // TODO: implement me, pls
  return false;
}

bool AdjacencyListGraph::AddEdge(int u, int v, int weight) {
  // TODO: implement me, pls
  return false;
}

bool AdjacencyListGraph::RemoveEdge(int u, int v) {
  // TODO: implement me, pls
  return false;
}

int AdjacencyListGraph::weight(int u, int v) const {
  // TODO: implement me, pls
  return 0;
}

int AdjacencyListGraph::outDegree(int v) const {
  // TODO: implement me, pls
  return 0;
}

int AdjacencyListGraph::inDegree(int v) const {
  // TODO: implement me, pls
  return 0;
}

void AdjacencyListGraph::Print(std::ostream &ostream) const {
  // TODO: implement me, pls
}

} // namespace itis