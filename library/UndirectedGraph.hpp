// Purpose: ADSA lab
// Author: Raul Jain
// Date of Creation: 30 april 2017
//type: library file
// Bugs:

#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH 1
/*
 * A class to represent an UndirectedGraph
 * Subclasses AbstractGraph
 */
 #include "stack.hpp"
 #include "queue.hpp"
 #include "AdjacencyList.hpp"
 #include "AdjacencyMatrix.hpp"
 #include "AbstractGraph.hpp"

 using namespace std;


class UndirectedGraph : AbstractGraph {
private:
  AdjacencyList graphlist;
  AdjacencyMatrix graphmatrix;
  char mode;

 public:
  /*
   * Constructor: UndirectedGraph
   *
   * Parameters: mode
   * Used to decide which representation to use
   * 'm' for AdjacencyMatrix
   * 'l' for AdjacencyList
   */
  UndirectedGraph(int vertices, char mode);
  /*
   * Returns the degree of the vertex.
   */
  int indegree(int i);
  int outdegree(int i);
  bool edgeExists(int i, int j);
  int vertices();
  int edges();
  void add(int i, int j);
  void remove(int i, int j);
  void print();
  void dfs(void (*work)(int&),int src);
  void bfs(void (*work)(int&),int src);
};


  UnDirectedGraph::UnDirectedGraph(int numVertices,mode){
    if(mode=='m'){
      graphmatrix.resizeAdjacencyMatrix(numVertices);
    }
    else if(mode == 'l'){
      graphlist.resizeAdjacencyList(numVertices);
    }
  }


  int UnDirectedGraph::indegree(int i){
    if(mode=='m'){
      return graphmatrix.indegree(i);
    }
    else if(mode == 'l'){
      return graphlist.indegree(i);
    }
  }


  int UnDirectedGraph::outdegree(int i){
    if(mode=='m'){
      return graphmatrix.outdegree(i);
    }
    else if(mode == 'l'){
      return graphlist.outdegree(i);
    }
  }


  bool UnDirectedGraph::edgeExists(int i, int j){
    if(mode=='m'){
      return graphmatrix.edgeExists(i,j);
    }
    else if(mode == 'l'){
      return graphlist.edgeExists(i,j);
    }
  }


  int UnDirectedGraph::vertices(){
    if(mode=='m'){
      return graphmatrix.vertices();
    }
    else if(mode == 'l'){
      return graphlist.vertices();
    }
  }


  int UnDirectedGraph::edges(){
    if(mode=='m'){
      return graphmatrix.edges()/2;
    }
    else if(mode == 'l'){
     return graphlist.edges()/2;
    }
  }


  void UnDirectedGraph::add(int i, int j){
    if(mode=='m'){
      graphmatrix.add(i,j);
      graphmatrix.add(j,i);
    }
    else if(mode == 'l'){
     graphlist.add(i,j);
     graphlist.add(j,i);
    }
  }


  void UnDirectedGraph::remove(int i, int j){
    if(mode=='m'){
      graphmatrix.remove(i,j);
      graphmatrix.remove(j,i);
    }
    else if(mode == 'l'){
      graphlist.remove(i,j);
      graphlist.remove(j,i);
    }
  }


  void UnDirectedGraph::print(){
    if(mode=='m'){
      graphmatrix.print();
    }
    else if(mode == 'l'){
      graphlist.print();
    }
  }


  void UnDirectedGraph::dfs(void (*work)(int&),int src){

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



  void UnDirectedGraph::bfs(void (*work)(int&),int src){

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
