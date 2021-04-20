#include <cassert> // assert
#include <iomanip>
#include <iostream>
#include <ostream>
#include <vector>

// type alias
using Array2d = std::vector<std::vector<int>>;

struct Graph {
  virtual ~Graph() = default;

  /**
   * @return кол-во ребер в графе
   */
  virtual int numEdges() const = 0;

  /**
   * @return кол-во узлов в графе
   */
  virtual int numVertices() const = 0;

  /**
   * Проверка наличия узла в графе.
   * @param v - индекс узла
   * @return true - при наличии узла, false - иначе
   */
  virtual bool Exists(int v) const = 0;

  /**
   * Проверка наличия ребра в графе.
   * @param u - индекс начального узла
   * @param v - индекс конечного узла
   * @return true - при наличии ребра, false - иначе
   */
  virtual bool Exists(int u, int v) const = 0;

  /**
   * Добавление нового узла в граф.
   * @return неотрицательный целочисленный индекс созданного узла
   */
  virtual int AddVertex() = 0;

  /**
   * Удаление узла из графа.
   * @param v - индекс удаляемого узла
   * @return true - при успешном удалении, false - иначе
   */
  virtual bool RemoveVertex(int v) = 0;

  /**
   * Добавление ребра в граф.
   * @param u - индекс начального узла
   * @param v - индекс конечного узла
   * @param weight - вес ребра (payload)
   * @return true - при успешном добавлении, false - иначе
   */
  virtual bool AddEdge(int u, int v, int weight) = 0;

  /**
   * Удаление ребра из графа.
   * @param u - индекс начального узла
   * @param v - индекс конечного узла
   * @return true - при успешном удалении, false - иначе
   */
  virtual bool RemoveEdge(int u, int v) = 0;

  /**
   * Вывод графа в выходной поток.
   */
  virtual void Print(std::ostream &) const = 0;
};

// Note: this is a directed graph implementation
struct AdjacencyMatrixGraph : Graph {
private:
  static constexpr auto NO_EDGE = 0;
  static constexpr auto DEFAULT_NUM_VERTICES = 5;

  Array2d matrix_;
  int num_edges_{0};

public:
  explicit AdjacencyMatrixGraph(int num_vertices = DEFAULT_NUM_VERTICES) {
    matrix_.resize(num_vertices);

    for (auto &matrix_row : matrix_) {
      matrix_row.resize(num_vertices);
    }
  }

  int numEdges() const override { return num_edges_; }

  int numVertices() const override { return static_cast<int>(matrix_.size()); }

  bool Exists(int u, int v) const override {
    return Exists(u) && Exists(v) && matrix_[u][v] != NO_EDGE;
  }

  bool Exists(int v) const override { return v >= 0 && v < numVertices(); }

  int AddVertex() override {
    const auto new_size = static_cast<int>(numVertices()) + 1;

    // add a new row
    matrix_.resize(new_size);

    // add a new column
    for (auto &matrix_row : matrix_) {
      matrix_row.resize(new_size);
    }

    return new_size - 1; // because, index = size - 1
  }

  bool RemoveVertex(int v) override {
    if (!Exists(v)) {
      return false;
    }

    // TODO: implement me, pls

    return true;
  }

  bool AddEdge(int u, int v, int weight) override {
    if (Exists(u) && Exists(v)) {
      matrix_[u][v] = weight;
      return true;
    }

    return false;
  }

  bool RemoveEdge(int u, int v) override {
    // TODO: implement me, pls
    return false;
  }

  void Print(std::ostream &os) const override {
    for (int row_index = 0; row_index < matrix_.size(); row_index++) {
      for (int col_index = 0; col_index < matrix_.size(); ++col_index) {
        os << std::left << std::setw(3);
        os << matrix_[row_index][col_index] << " ";
      }
      os << '\n';
    }
  }
};

int main(int argc, char **argv) {
  // creating a graph with 3 disconnected vertices
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