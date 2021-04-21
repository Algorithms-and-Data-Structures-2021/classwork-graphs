#pragma once

#include <ostream>

namespace itis {

/**
 * Интерфейс графа.
 */
struct Graph {

  virtual ~Graph() = default;

  /**
   * Добавление нового узла в граф.
   * @return неотрицательный индекс созданного узла
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
   * @return кол-во ребер в графе
   */
  virtual int numEdges() const = 0;

  /**
   * @return кол-во узлов в графе
   */
  virtual int numVertices() const = 0;

  /**
   * Получение веса ребра в графе.
   * @param u - индекс начального узла
   * @param v - индекс конечного узла
   * @return значение веса ребра
   */
  virtual int weight(int u, int v) const = 0;

  /**
   * Количество входящих в узел ребер.
   * @param v - индекс узла
   * @return число входных ребер
   */
  virtual int outDegree(int v) const = 0;

  /**
   * Количество выходящих ребер из узла.
   * @param v - индекс узла
   * @return число выходных ребер
   */
  virtual int inDegree(int v) const = 0;

  /**
   * Вывод графа в выходной поток.
   */
  virtual void Print(std::ostream &) const = 0;
};

} // namespace itis
