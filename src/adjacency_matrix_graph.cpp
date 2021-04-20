#include "adjacency_matrix_graph.hpp"

#include <cassert> // assert
#include <iomanip> // setw

namespace itis {

AdjacencyMatrixGraph::AdjacencyMatrixGraph(int num_vertices) {
  assert(num_vertices >= 0);

  matrix_.resize(num_vertices);

  for (auto &matrix_row : matrix_) {
    matrix_row.resize(num_vertices, NO_EDGE_WEIGHT);
  }
}

AdjacencyMatrixGraph::AdjacencyMatrixGraph(const Array2d &matrix) {
  // TODO: implement me, pls
}

int AdjacencyMatrixGraph::numEdges() const { return num_edges_; }

int AdjacencyMatrixGraph::numVertices() const {
  return static_cast<int>(matrix_.size());
}

bool AdjacencyMatrixGraph::Exists(int u, int v) const {
  return Exists(u) && Exists(v) && matrix_[u][v] != NO_EDGE_WEIGHT;
}

bool AdjacencyMatrixGraph::Exists(int v) const {
  return v >= 0 && v < numVertices();
}

int AdjacencyMatrixGraph::AddVertex() {
  const auto new_size = static_cast<int>(numVertices()) + 1;

  // add a new row
  matrix_.resize(new_size);

  // add a new column
  for (auto &matrix_row : matrix_) {
    matrix_row.resize(new_size);
  }

  return new_size - 1; // because, index = size - 1
}

bool AdjacencyMatrixGraph::RemoveVertex(int v) {
  if (!Exists(v)) {
    return false;
  }

  // TODO: implement me, pls

  return true;
}

bool AdjacencyMatrixGraph::AddEdge(int u, int v, int weight) {
  if (Exists(u) && Exists(v)) {
    matrix_[u][v] = weight;
    return true;
  }

  return false;
}

bool AdjacencyMatrixGraph::RemoveEdge(int u, int v) {
  // TODO: implement me, pls
  return false;
}

int AdjacencyMatrixGraph::weight(int u, int v) const {
  if (Exists(u, v)) {
    return matrix_[u][v];
  }
  return NO_EDGE_WEIGHT;
}

int AdjacencyMatrixGraph::outDegree(int v) const {
  // TODO: implement me, pls
  return 0;
}

int AdjacencyMatrixGraph::inDegree(int v) const {
  // TODO: implement me, pls
  return 0;
}

void AdjacencyMatrixGraph::Print(std::ostream &os) const {
  for (int row_index = 0; row_index < matrix_.size(); row_index++) {
    for (int col_index = 0; col_index < matrix_.size(); ++col_index) {
      os << std::left << std::setw(3);
      os << matrix_[row_index][col_index] << '\t';
    }
    os << '\n';
  }
}

} // namespace itis