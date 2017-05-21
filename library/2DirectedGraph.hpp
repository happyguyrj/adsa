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
#include "AdjacencyMatrix.hpp"
#include "AbstractGraph.hpp"
#include "MinPriorityQueue.hpp"
#include "UFDS.hpp"

#include <limits.h>

class vertex{

  public:
    int v;
    int value;

  vertex(){}
  vertex (int v,int value){
   this->v=v;
   this->value=value;
  }

  bool operator < (vertex RightSide){
    return this->value < RightSide.value;
  }

  bool operator > (vertex RightSide){
    return this->value > RightSide.value;
  }

  bool operator == (vertex RightSide){
    return (this->value == RightSide.value) && (this->v == RightSide.v);
  }

  void operator = (vertex RightSide){
    this->v = RightSide.v;
    this->value = RightSide.value;
  }
};

class edge{

  public:
    int src;
    int dest;
    int weight;

  edge(){}
  edge(int src,int dest,int weight){
    this->src = src;
    this->dest = dest;
    this->weight = weight;
  }

  bool operator < (edge rhs){
    return this->weight < rhs.weight;
  }

  bool operator > (edge rhs){
    return this->weight > rhs.weight;
  }

  bool operator == (edge rhs){
    return (this->weight == rhs.weight) && (this->src == rhs.src) && (this->dest == rhs.dest);
  }

  void operator = (edge rhs){
    this->src = rhs.src;
    this->dest = rhs.dest;
    this->weight = rhs.weight;
  }
};

/*
 * A class to represent a directed graph.
 */
class DirectedGraph : AbstractGraph {

private:
   AdjacencyMatrix graphmatrix;
   AdjacencyList graphlist;
   char mode;
   edge* mst;

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
  LinearList<DFSNode> dfs(void (*work)(int&),int src);
  LinearList<BFSNode> bfs(void (*work)(int&),int src);

  void printMST(){
   cout<<"Source\t Destination\tWeight"<<endl;
   for(int i=0;i<graphlist.vertices()-1;i++){
     cout<<"  "<<mst[i].src<<"\t\t"<<mst[i].dest<<"\t  "<<mst[i].weight<<endl;
     }
  }

  edge* kruskal(){
    MinPriorityQueue<edge> QueueEdges;

    int n=graphlist.vertices(),i;
    UFDS dset(n);

    for(int i=0;i<n;i++){
          dset.make_set(i);
      }

    i=0;
    edge e;
    for(int i=0;i<n;i++){
      listnode<pair<int,int> > *tmp=(graphlist.AdjList())[i].init;
      while ( tmp!= NULL ){
          e.src=i;
          e.dest=(tmp->getdata()).first;
          e.weight=(tmp->getdata()).second;
          QueueEdges.insert(e);
          tmp = tmp->getlink();
        }
     }

    while(!QueueEdges.empty()){
        e=QueueEdges.extract_min();
        if(dset.find_set(e.src)!=dset.find_set(e.dest)){
            dset.union_set(e.src,e.dest);
            (this->mst)[i++]=e;
        }
      }
    return mst;
  }

  edge* prim(){
	   int n=graphlist.vertices();
	   MinPriorityQueue<vertex> heap;

	   int i,u,key[n],parent[n],weight[n];
     bool inMST[n];

	   for(i=0;i<n;i++)
	   {
	   	inMST[i]=false;
	   	parent[i]=-1;
	   	weight[i]=INT_MAX;
	   	key[i]=INT_MAX;
	   }
	   vertex ver(0,0),u;
	   heap.insert(ver);
	   key[0]=0;


	   while(!heap.empty())
	   {
	   	u=heap.extract_min();

	    inMST[u.v]=true;

    	listnode<pair<int,int> >* tmp=(graphl.AdjList()[u.v].getfirst());
    	while(tmp!=NULL){
    		int j=(tmp->getdata()).first;
    		int wt=(tmp->getdata()).second;
    		vertex ver(j,wt);

  	    if( wt < key[j] &&!inMST[j]){
  	    	key[j]=wt;
  	    	weight[j]=wt;
  	    	parent[j]=u.v;
  	    	vertex ver1(j,wt);
  	    	heap.insert(ver1);
  	    }
    		tmp=tmp->getlink();
		  }
  		cout<<endl;
     }

     i=0;
     for(i=1;i<n;i++){
     	edge e(parent[i],i,weight[i]);
   	this->mst[i-1]=e;
    }
  return mst;
  }

};


  DirectedGraph  ::DirectedGraph(int numVertices, char mode){
    if(mode=='m'){
      graphmatrix.resAdjacencyMatrix(numVertices);
    }
    else if(mode == 'l'){
      graphlist.resAdjacencyList(numVertices);
    }
    mode = mode;
  }


  int DirectedGraph  ::indegree(int i){
    if(mode=='m'){
      return graphmatrix.indegree(i);
    }
    else if(mode == 'l'){
      return graphlist.indegree(i);
    }
  }


  int DirectedGraph  ::outdegree(int i){
    if(mode=='m'){
      return graphmatrix.outdegree(i);
    }
    else if(mode == 'l'){
      return graphlist.outdegree(i);
    }
  }


  void DirectedGraph  ::edgeExists(int i, int j){
    if(mode=='m'){
      return graphmatrix.edgeExists(i,j);
    }
    else if(mode == 'l'){
      return graphlist.edgeExists(i,j);
    }
  }


  int DirectedGraph  ::vertices(){
    if(mode=='m'){
      return graphmatrix.vertices();
    }
    else if(mode == 'l'){
      return graphlist.vertices();
    }
  }


  int DirectedGraph  ::edges(){
    if(mode=='m'){
      return graphmatrix.edges();
    }
    else if(mode == 'l'){
     return graphlist.edges();
    }
  }


  void DirectedGraph  ::add(int i, int j){
    if(mode=='m'){
      graphmatrix.add(i,j);
    }
    else if(mode == 'l'){
     graphlist.add(i,j);
    }
  }


  void DirectedGraph  ::remove(int i, int j){
    if(mode=='m'){
      graphmatrix.remove(i,j);
    }
    else if(mode == 'l'){
      graphlist.remove(i,j);
    }
  }


  void DirectedGraph  ::print(){
    if(mode=='m'){
      graphmatrix.print();
    }
    else if(mode == 'l'){
      graphlist.print();
    }
  }

  LinearList<DFSNode> DirectedGraph::dfs(void (*work)(int&),int src){
    int n=this->vertices(),time=0;
    LinearList<DFSNode> tree(n);

    for(int i=0;i<n;i++){
      tree[i].col=WHITE;
      tree[i].pred=make_pair(-1,0);
    }

    stack<int> s;
    s.push(src);

    while(!s.empty()){
     int i=s.top();

     if(tree[i].col==BLACK){
        s.pop();
       }
     else if(tree[i].col==GRAY){
        s.pop();
        tree[i].col=BLACK;
        time++;
        tree[i].ft=time;
       }
      else if(tree[i].col==WHITE){
         tree[i].col=GRAY;
         work(i);
         time++;
         tree[i].dt=time;

         if(repr=='m'){
           for(int j=0;j<n;j++){
            if(this->edgeExists(i,j) && tree[j].col==WHITE ){
              s.push(j);
              tree[j].pred=make_pair(i,graphm.weight_of(i,j));;
              }
            }
          }
          else{
            listnode<pair<int,int> >* tmp=(graphlist.AdjList()[i].getfirst());
            while(tmp!=NULL){
              int j=(tmp->getdata()).first;
              if(tree[j].col==WHITE){
                s.push(j);
                tree[j].pred=make_pair(i,(tmp->getdata()).second);
              }
              tmp=tmp->getlink();
            }
          }
        }
      }

      for(int k=0;k<n;k++){
        if(tree[k].col==WHITE){
          s.push(k);
        }

      while(!s.empty()){
        int i=s.top();

        if(tree[i].col==BLACK) s.pop();
        else if(tree[i].col==GRAY){
          s.pop();
          tree[i].col=BLACK;
          time++;
          tree[i].ft=time;
        }
        else if(tree[i].col==WHITE){
          work(i);
          tree[i].col=GRAY;
          time++;
          tree[i].dt=time;


          if(repr=='m'){
             for(int j=0;j<n;j++){
              if(this->edgeExists(i,j) && tree[j].col==WHITE ){
                s.push(j);
                tree[j].pred=make_pair(i,graphm.weight_of(i,j));
              }
            }
          }
          else{
            listnode<pair<int,int> >* tmp=(graphlist.AdjList()[i].getfirst());
            while(tmp!=NULL){
              int j=(tmp->getdata()).first;
              if(tree[j].col==WHITE){
                s.push(j);
                tree[j].pred=make_pair(i,(tmp->getdata()).second);
                }
              tmp=tmp->getlink();
            }
          }
       }
    }
  }
return tree;
}

   LinearList<BFSNode> DirectedGraph::bfs(void (*work)(int&),int src){
      int n=this->vertices();

      LinearList<BFSNode> tree(n);
      for(int i=0;i<n;i++){
        tree[i].col=WHITE;
        tree[i].pred=make_pair(-1,0);
        tree[i].d=0;
      }

      queue<int> q;
      q.push(src);
      tree[src].col=GRAY;
      work(src);
      while(!q.empty()){
       int i=q.pop();
       tree[i].col=BLACK;
       if(repr=='m'){
        for(int j=0;j<n;j++){
          if(this->edgeExists(i,j) && tree[j].col==WHITE){
            q.push(j);
            tree[j].col=GRAY;
            tree[j].d=tree[i].d+1;
            tree[j].pred=make_pair(i,graphm.weight_of(i,j));
          work(j);
          }
        }
      }
      else{
        listnode<pair<int,int> >* tmp=(graphlist.AdjList()[i].getfirst());
          while(tmp!=NULL){
            int j=(tmp->getdata()).first;
            if(tree[j].col==WHITE)
            {
              q.push(j);
              tree[j].col=GRAY;
              tree[j].d=tree[i].d+1;
              tree[j].pred=make_pair(i,(tmp->getdata()).second);
              work(j);
            }
            tmp=tmp->getlink();
          }
      }
    }
    return tree;
  }

#endif /* ifndef DIRECTED_GRAPH */
