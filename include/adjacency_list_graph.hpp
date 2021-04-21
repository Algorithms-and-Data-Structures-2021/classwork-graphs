#pragma once

#include <list>
#include <vector>

#include "graph.hpp"

namespace itis {

struct AdjacencyListGraph : Graph {
private:
  using AdjacencyList = std::vector<std::list<int>>;

  // vertices and a corresponding list of adjacent vertices (i.e. edges)
  std::vector<std::list<int>> adjacent_vertices;

  int num_edges_{0};
  int num_vertices_{0};

public:

  int AddVertex() override;

  bool RemoveVertex(int v) override;

  bool AddEdge(int u, int v, int weight) override;

  bool RemoveEdge(int u, int v) override;

  bool Exists(int v) const override;

  bool Exists(int u, int v) const override;

  int numEdges() const override;

  int numVertices() const override;

  int weight(int u, int v) const override;

  int outDegree(int v) const override;

  int inDegree(int v) const override;

  void Print(std::ostream &ostream) const override;
};

} // namespace itis