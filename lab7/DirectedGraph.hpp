// Purpose: ADSA lab
// Author: Raul Jain
// Date of Creation: 30 april 2017
//type: library file
// Bugs:

#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH 1

#include ".stack.hpp"
#include "queue.hpp"
#include "AdjacencyMatrix.hpp"
#include "AdjacencyList.hpp"
#include "AbstractGraph.hpp"
/*
 * A class to represent a directed graph.
 */
class DirectedGraph : AbstractGraph {

 private:
   AdjacencyList graphlist;

 public:
  /*
   * Constructor: DirectedGraph
   *
   * Parameters: mode
   * Used to decide which representation to use
   * 'm' for AdjacencyMatrix
   * 'l' for AdjacencyList
   */
  DirectedGraph(int numVertices);
  /*
   * Function: indegree
   * Returns the indegree of a vertex
   */
  int indegree(int i);
  /*
   * Function: outdegree
   * Returns the outdegree of a vertex.
   */
  int outdegree(int j);

  bool edgeExists(int i, int j);
  int vertices();
  int edges();
  void add(int i, int j);
  void remove(int i, int j);
  void print();
  void dfs(void (*work)(int&),int src);
  void bfs(void (*work)(int&),int src);
};

template<class T>
  DirectedGraph<T>::DirectedGraph(int numVertices){
    graphlist.resAdjacencyList(numVertices)
  }

template<class T>
  void DirectedGraph<T>::indegree(int i){
    graphlist.indegree(i);
  }

template<class T>
  void DirectedGraph<T>::outdegree(int i){
    graphlist.outdegree(i);
  }

template<class T>
  void DirectedGraph<T>::edgeExists(int i, int j){
    graphlist.edgeExists(i,j);
  }

template<class T>
  void DirectedGraph<T>::vertices(){
    graphlist.vertices();
  }

template<class T>
  void DirectedGraph<T>::edges(){
    graphlist.edges();
  }

template<class T>
  void DirectedGraph<T>::add(int i, int j){
    graphlist.add(i,j);
  }

template<class T>
  void DirectedGraph<T>::remove(int i, int j){
    graphlist.remove(i,j);
  }

template<class T>
  void DirectedGraph<T>::print(){
    graphlist.print();
  }

template<class T>
  void DirectedGraph<T>::dfs(void (*work)(int&),int src){
  }

template<class T>
  void DirectedGraph<T>::bfs(void (*work)(int&),int src){
  }
}
#endif /* ifndef DIRECTED_GRAPH */
