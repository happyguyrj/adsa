// Purpose: ADSA lab
// Author: Raul Jain
// Date of Creation: 30 april 2017
//type: library file
// Bugs:

#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH 1
/*
 * A class to represent an UnUnDirectedGraph
 * Subclasses AbstractGraph
 */
 #include ".stack.hpp"
 #include "queue.hpp"
 #include "AdjacencyList.hpp"
 #include "AbstractGraph.hpp"

class UnUnDirectedGraph : AbstractGraph {

 private:
  AdjacencyList graphlist;

 public:
  /*
   * Constructor: UnUnDirectedGraph
   *
   * Parameters: mode
   * Used to decide which representation to use
   * 'm' for AdjacencyMatrix
   * 'l' for AdjacencyList
   */
  UnUnDirectedGraph(int vertices);
  /*
   * Returns the degree of the vertex.
   */
  int degree(int i);

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
  UnDirectedGraph<T>::UnDirectedGraph(int numVertices){
    graphlist.resAdjacencyList(numVertices)
  }

template<class T>
  void UnDirectedGraph<T>::degree(int i){
    graphlist.outdegree(i);
  }

template<class T>
  void UnDirectedGraph<T>::edgeExists(int i, int j){
    graphlist.edgeExists(i,j);
  }

template<class T>
  void UnDirectedGraph<T>::vertices(){
    graphlist.vertices();
  }

template<class T>
  void UnDirectedGraph<T>::edges(){
    graphlist.edges()/2;
  }

template<class T>
  void UnDirectedGraph<T>::add(int i, int j){
    graphlist.add(i,j);
    graphlist.add(j,i);
  }

template<class T>
  void UnDirectedGraph<T>::remove(int i, int j){
    graphlist.remove(i,j);
    graphlist.remove(j,i);

  }

template<class T>
  void UnDirectedGraph<T>::print(){
    graphlist.print();
  }

template<class T>
  void UnDirectedGraph<T>::dfs(void (*work)(int&),int src){
  }

template<class T>
  void UnDirectedGraph<T>::bfs(void (*work)(int&),int src){
  }
}

#endif /* ifndef UNDIRECTED_GRAPH */
