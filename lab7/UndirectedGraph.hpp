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
  void UnDirectedGraph<T>::bfs(void (*work)(int&),int src){
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

#endif /* ifndef UNDIRECTED_GRAPH */
