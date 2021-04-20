#include <cassert> // assert
#include <iostream>

#include "adjacency_matrix_graph.hpp"

using namespace itis;

int main(int argc, char **argv) {
  // creating a graph with 4 disconnected vertices
  AdjacencyMatrixGraph graph{4};
  graph.Print(std::cout);
  std::cout << '\n';

  // adding a new vertex to the graph
  std::cout << "New vertex ID = " << graph.AddVertex() << '\n';
  graph.Print(std::cout);
  std::cout << '\n';

  // printing the number of edges and vertices
  std::cout << "Graph edges: " << graph.numEdges() << '\n';
  std::cout << "Graph vertices: " << graph.numVertices() << '\n';
  std::cout << '\n';

  // adding edges to the graph
  graph.AddEdge(0, 1, 10);
  graph.AddEdge(0, 4, 15);
  graph.AddEdge(1, 3, 2);
  graph.AddEdge(4, 1, 21);
  graph.AddEdge(1, 2, 7);
  graph.AddEdge(2, 3, 1);

  graph.Print(std::cout);
  std::cout << '\n';

  return 0;
}