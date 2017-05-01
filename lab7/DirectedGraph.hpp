// Purpose: ADSA lab
// Author: Raul Jain
// Date of Creation: 30 april 2017
//type: library file
// Bugs:

#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH 1

#include ".stack.hpp"
#include "queue.hpp"
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
    int ver = this->vertices();             // number of vertices
    Color colour[n];                        //colour of node

    for(i=0;i<ver;i++){
      colour[i] = WHITE;
    }

    stack<int> stack;
    s.push(src);

    while (!stack.empty()) {
      int j=stack.pop();
      if(colour[j]==WHITE){
        work(j);
        colour[j]=GRAY;

        listnode<int>* temp = (graphlist.AdjList()[i].getfirst());
        while (temp!=NULL) {
          int k = temp->getdata();
          if(colour[k]==WHITE){
            stack.push(k);
          }
          temp=temp->getlink();
        }
        colour[i]=BLACK;
      }
    }
  }

template<class T>
  void DirectedGraph<T>::bfs(void (*work)(int&),int src){
    int ver = this->vertices();             // number of vertices
    Color colour[n];                        //colour of node

    for(i=0;i<ver;i++){
      colour[i] = WHITE;
    }

    queue<int> queue;
    s.push(src);

    colour[src]=GRAY;
    work(src);

    while (!queue.empty()) {
      int j=queue.pop();

      listnode<int>* temp = (graphlist.AdjList()[j].getfirst());
      while (temp!=NULL){
        int k=temp->getdata();
        if(colour[k]==WHITE){
          queue.push(k);
          colour[k]=GRAY;
          work(k);
        }
        temp=temp->getlink();
      }
      colour[i]=BLACK;
    }
  }
}
#endif /* ifndef DIRECTED_GRAPH */
