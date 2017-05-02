// Purpose: ADSA lab
// Author: Raul Jain
// Date of Creation: 30 april 2017
//type: library file
// Bugs:

#ifndef DIRECTED_GRAPH
#define DIRECTED_GRAPH 1

#include "stack.hpp"
#include "queue.hpp"
#include "AdjacencyList.hpp"
#include "AbstractGraph.hpp"
/*
 * A class to represent a directed graph.
 */
class DirectedGraph : AbstractGraph {

private:
   AdjacencyList graphlist;
   AdjacencyMatrix graphmatrix;
   char mode;

 public:
  /*
   * Constructor: DirectedGraph
   *
   * Parameters: mode
   * Used to decide which representation to use
   * 'm' for AdjacencyMatrix
   * 'l' for AdjacencyList
   */
  DirectedGraph(int numVertices, char mode);
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

  
  DirectedGraph<T>::DirectedGraph(int numVertices, char mode){
    if(mode=='m'){
      graphmatrix.resAdjacencyMatrix(numVertices);
    }
    else if(mode == 'l'){
      graphlist.resAdjacencyList(numVertices);
    }
  }


  void DirectedGraph<T>::indegree(int i){
    if(mode=='m'){
      return graphmatrix.indegree(i);
    }
    else if(mode == 'l'){
      return graphlist.indegree(i);
    }
  }


  void DirectedGraph<T>::outdegree(int i){
    if(mode=='m'){
      return graphmatrix.outdegree(i);
    }
    else if(mode == 'l'){
      return graphlist.outdegree(i);
    }
  }


  void DirectedGraph<T>::edgeExists(int i, int j){
    if(mode=='m'){
      return graphmatrix.edgeExists(i,j);
    }
    else if(mode == 'l'){
      return graphlist.edgeExists(i,j);
    }
  }


  void DirectedGraph<T>::vertices(){
    if(mode=='m'){
      return graphmatrix.vertices();
    }
    else if(mode == 'l'){
      return graphlist.vertices();
    }
  }


  void DirectedGraph<T>::edges(){
    if(mode=='m'){
      return graphmatrix.edges();
    }
    else if(mode == 'l'){
     return graphlist.edges();
    }
  }


  void DirectedGraph<T>::add(int i, int j){
    if(mode=='m'){
      graphmatrix.add(i,j);
    }
    else if(mode == 'l'){
     graphlist.add(i,j);
    }
  }


  void DirectedGraph<T>::remove(int i, int j){
    if(mode=='m'){
      graphmatrix.remove(i,j);
    }
    else if(mode == 'l'){
      graphlist.remove(i,j);
    }
  }


  void DirectedGraph<T>::print(){
    if(mode=='m'){
      graphmatrix.print();
    }
    else if(mode == 'l'){
      graphlist.print();
    }
  }

//
//   void DirectedGraph<T>::dfs(void (*work)(int&),int src){
//
//     int ver = this->vertices();             // number of vertices
//     Color colour[ver];                        //colour of node
//
//     for(i=0;i<ver;i++){
//       colour[i] = WHITE;
//     }
//
//     stack<int> stack;
//     stack.push(src);
//
//     while (!stack.empty()) {
//       int j=stack.pop();
//       if(colour[j]==WHITE){
//         work(j);
//         colour[j]=GRAY;
//
//         listnode<int>* temp = (graphlist.AdjList()[i].getfirst());
//         while (temp!=NULL) {
//           int k = temp->getdata();
//           if(colour[k]==WHITE){
//             stack.push(k);
//           }
//           temp=temp->getlink();
//         }
//         colour[i]=BLACK;
//       }
//     }
//   }


//
//   void DirectedGraph<T>::bfs(void (*work)(int&),int src){
//
//     int ver = this->vertices();             // number of vertices
//     Color colour[ver];                        //colour of node
//
//     for(int i=0;i<ver;i++){
//       colour[i] = WHITE;
//     }
//
//     queue<int> queue;
//     stack.push(src);
//
//     colour[src]=GRAY;
//     work(src);
//
//     while (!queue.empty()) {
//       int j=queue.pop();
//
//       listnode <int>* temp = (graphlist.AdjList()[j].getfirst());
//       while (temp!=NULL){
//         int k=temp->getdata();
//         if(colour[k]==WHITE){
//           queue.push(k);
//           colour[k]=GRAY;
//           work(k);
//           temp=temp->getlink();
//         }
//       }
//       colour[j]=BLACK;
//     }
//   }
}
#endif /* ifndef DIRECTED_GRAPH */
