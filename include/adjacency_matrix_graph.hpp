#pragma once

#include <vector>

#include "graph.hpp"

namespace itis {

struct AdjacencyMatrixGraph : Graph {
private:
  // type alias
  using AdjacencyMatrix = std::vector<std::vector<int>>;

  // constants
  static constexpr auto NO_EDGE_WEIGHT = 0;
  static constexpr auto DEFAULT_NUM_VERTICES = 1;

  // adjacency matrix storing edge weights
  AdjacencyMatrix matrix_;

  // number of edges in the graph
  int num_edges_{0};

public:
  explicit AdjacencyMatrixGraph(int num_vertices = DEFAULT_NUM_VERTICES);

  explicit AdjacencyMatrixGraph(const AdjacencyMatrix &matrix);

  int AddVertex() override;

  bool RemoveVertex(int v) override;

  bool AddEdge(int u, int v, int weight) override;

  bool RemoveEdge(int u, int v) override;

  bool Exists(int u, int v) const override;

  bool Exists(int v) const override;

  int weight(int u, int v) const override;

  int outDegree(int v) const override;

  int inDegree(int v) const override;

  int numEdges() const override;

  int numVertices() const override;

  void Print(std::ostream &) const override;
};

} // namespace itis