// Purpose: ADSA lab
// Author: Raul Jain
// Date of Creation: 30 april 2017
//type: library file
// Bugs:

#ifndef UNDIRECTED_GRAPH
#define UNDIRECTED_GRAPH 1
/*
 * A class to represent an UnDirectedGraph
 * Subclasses AbstractGraph
 */
 #include "stack.hpp"
 #include "queue.hpp"
 #include "AdjacencyList.hpp"
 #include "AdjacencyMatrix.hpp"
 #include "AbstractGraph.hpp"

 #include <limits.h>
 #include "MinPriorityQueue.hpp"
 //#include "UFDS.hpp"


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

class UnDirectedGraph : AbstractGraph {

 private:
  AdjacencyList graphlist;
  AdjacencyMatrix graphmatrix;
  char mode;
  edge* mst;
  int num_edges;

 public:
  /*
   * Constructor: UnDirectedGraph
   *
   * Parameters: mode
   * Used to decide which representation to use
   * 'm' for AdjacencyMatrix
   * 'l' for AdjacencyList
   */
  UnDirectedGraph(int vertices, char mode);
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
  LinearList<DFSNode> void dfs(void (*work)(int&),int src);
  LinearList<BFSNode> void bfs(void (*work)(int&),int src);

  void printMST(){
   cout<<"Source\t Destination\tWeight"<<endl;
   for(int i=0;i<graphl.vertices()-1;i++){
     cout<<"  "<<mst[i].src<<"\t\t"<<mst[i].dest<<"\t  "<<mst[i].weight<<endl;
     }
  }

  edge* kruskal(){
    MinPriorityQueue<edge> qedges;

    int n=graphl.vertices(),i;
    UFDS dset(n);

    for(int i=0;i<n;i++){
          dset.make_set(i);
      }

    i=0;
    edge e;
    for(int i=0;i<n;i++){
      listnode<pair<int,int> > *tmp=(graphl.AdjList())[i].init;
      while ( tmp!= NULL ){
          e.src=i;
          e.dest=(tmp->getdata()).first;
          e.weight=(tmp->getdata()).second;
          qedges.insert(e);
          tmp = tmp->getlink();
        }
     }

    while(!qedges.empty()){
        e=qedges.extract_min();
        if(dset.find_set(e.src)!=dset.find_set(e.dest)){
            dset.union_set(e.src,e.dest);
            (this->mst)[i++]=e;
        }
      }
    return mst;
  }

  edge* prim(){
	   int n=graphl.vertices();
	   MinPriorityQueue<vertex> heap;

	   int i,u,key[n],parent[n],weight[n];
	   bool inheap[n];
	   vertex ve;

	   for(i=0;i<n;i++){
	   	inheap[i]=true;
	   	parent[i]=-1;
	   	weight[i]=INT_MAX;
	   	key[i]=INT_MAX;
	   	vertex vert(i,INT_MAX);
	   	heap.insert(vert);
	   }
	   vertex ver(0,0);
	   key[0]=0;
	   while(!heap.empty()){
	   	ve=heap.extract_min();
	   	inheap[ve.v]=false;

  		listnode<pair<int,int> >* tmp=(graphl.AdjList()[ve.v].getfirst());
  		while(tmp!=NULL){
  			int j=(tmp->getdata()).first;

  			vertex ver(j,(tmp->getdata()).second);
  		    if((tmp->getdata()).second < key[j] && inheap[j]){  		    	key[j]=(tmp->getdata()).second;
  		    	heap.heap_decrease_key(j,ver);
  		    	parent[j]=ve.v;
  		    	weight[j]=(tmp->getdata()).second;
		    }
			tmp=tmp->getlink();
			}
    }

    i=0;
    for(i=1;i<n;i++){
    	edge e(i,parent[i],weight[i]);
    	this->mst[i-1]=e;
    }
  return mst;
  }
};


  UnDirectedGraph::UnDirectedGraph(int numVertices,mode){
    if(mode=='m'){
      graphmatrix.resAdjacencyMatrix(numVertices);
    }
    else if(mode == 'l'){
      graphlist.resAdjacencyList(numVertices);
    }
    mst=new edge[vertices];
    repr=mode;
    num_edges=0;
  }


  void UnDirectedGraph::indegree(int i){
    if(mode=='m'){
      return graphmatrix.indegree(i);
    }
    else if(mode == 'l'){
      return graphlist.indegree(i);
    }
  }


  void UnDirectedGraph::outdegree(int i){
    if(mode=='m'){
      return graphmatrix.outdegree(i);
    }
    else if(mode == 'l'){
      return graphlist.outdegree(i);
    }
  }


  void UnDirectedGraph::edgeExists(int i, int j){
    if(mode=='m'){
      return graphmatrix.edgeExists(i,j);
    }
    else if(mode == 'l'){
      return graphlist.edgeExists(i,j);
    }
  }


  void UnDirectedGraph::vertices(){
    if(mode=='m'){
      return graphmatrix.vertices();
    }
    else if(mode == 'l'){
      return graphlist.vertices();
    }
  }


  void UnDirectedGraph::edges(){
    // if(mode=='m'){
    //   return graphmatrix.edges()/2;
    // }
    // else if(mode == 'l'){
    //  return graphlist.edges()/2;
    // }
    return num_edges;
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


  LinearList<DFSNode> UndirectedGraph::dfs(void (*work)(int&),int src){
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
              listnode<pair<int,int> >* tmp=(graphl.AdjList()[i].getfirst());
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
              listnode<pair<int,int> >* tmp=(graphl.AdjList()[i].getfirst());
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

  LinearList<BFSNode> UndirectedGraph::bfs(void (*work)(int&),int src)
  {

              int n=this->vertices();

        LinearList<BFSNode> tree(n);
        for(int i=0;i<n;i++)
        {
          tree[i].col=WHITE;
          tree[i].pred=make_pair(-1,0);
          tree[i].d=0;

        }

        queue<int> q;
        q.push(src);
        tree[src].col=GRAY;
        work(src);
        while(!q.empty())
        {
         int i=q.pop();
         tree[i].col=BLACK;
    if(repr=='m')
      {
          for(int j=0;j<n;j++)
          {
            if(this->edgeExists(i,j) && tree[j].col==WHITE)
            {
              q.push(j);
              tree[j].col=GRAY;

              tree[j].d=tree[i].d+1;
              tree[j].pred=make_pair(i,graphm.weight_of(i,j));
            work(j);
            }
          }
        }
        else
        {
          listnode<pair<int,int> >* tmp=(graphl.AdjList()[i].getfirst());
              while(tmp!=NULL)
              {
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

#endif /* ifndef UNDIRECTED_GRAPH */
