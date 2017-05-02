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
/*
 * A class to modeesent a directed graph.
 */
class DirectedGraph : AbstractGraph {

private:

   AdjacencyMatrix graphmatrix;
   AdjacencyList graphlist;
   char mode;

 public:
  /*
   * Constructor: DirectedGraph
   *
   * Parameters: mode
   * Used to decide which modeesentation to use
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
};


  DirectedGraph  ::DirectedGraph(int numVertices, char mode){
    if(mode=='m'){
      graphmatrix.resAdjacencyMatrix(numVertices);
    }
    else if(mode == 'l'){
      graphlist.resAdjacencyList(numVertices);
    }
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


  bool DirectedGraph  ::edgeExists(int i, int j){
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


LinearList<DFSNode> DirectedGraph::dfs(void (*work)(int&),int src)
{
      int n=this->vertices(),time=0;
      LinearList<DFSNode> tree(n);

      for(int i=0;i<n;i++)
      {
        tree[i].col=WHITE;
        tree[i].pred=-1;
      }

      stack<int> s;
      s.push(src);

        while(!s.empty())
        {
           int i=s.top();
           if(tree[i].col==BLACK)
           {
            s.pop();
           }
           else if(tree[i].col==GRAY)
           {
            s.pop();
            tree[i].col=BLACK;
            time++;
            tree[i].ft=time;
           }
           else if(tree[i].col==WHITE)
           {
               tree[i].col=GRAY;
               work(i);
               time++;
               tree[i].dt=time;

                if(mode=='m')
                {
                     for(int j=0;j<n;j++)
                     {
                      if(this->edgeExists(i,j) && tree[j].col==WHITE )
                      {
                        s.push(j);
                        tree[j].pred=i;
                      }
                     }
                }
                else
                  {
                    listnode<int>* tmp=(graphlist.AdjList()[i].getfirst());
                    while(tmp!=NULL)
                    {
                      int j=tmp->getdata();
                      if(tree[j].col==WHITE)
                      {
                        s.push(j);
                        tree[j].pred=i;
                      }
                      tmp=tmp->getlink();
                    }

                  }
            }
          }

            for(int k=0;k<n;k++)
            {

            if(tree[k].col==WHITE)
            {
              s.push(k);
            }

           while(!s.empty())
           {
           int i=s.top();

              if(tree[i].col==BLACK) s.pop();

              else if(tree[i].col==GRAY)
              {
              s.pop();
              tree[i].col=BLACK;
              time++;
              tree[i].ft=time;
                }

              else if(tree[i].col==WHITE)
              {
                  work(i);
                  tree[i].col=GRAY;
                  time++;
                  tree[i].dt=time;


                if(mode=='m')
                {
                     for(int j=0;j<n;j++)
                     {
                      if(this->edgeExists(i,j) && tree[j].col==WHITE )
                      {
                        s.push(j);
                        tree[j].pred=i;
                      }
                     }
                  }
                  else
                  {
                    listnode<int>* tmp=(graphlist.AdjList()[i].getfirst());
                    while(tmp!=NULL)
                    {
                      int j=tmp->getdata();
                      if(tree[j].col==WHITE)
                      {
                        s.push(j);
                        tree[j].pred=i;
                    }
                      tmp=tmp->getlink();
                    }
                  }
             }
          }
        }
return tree;
}

LinearList<BFSNode> DirectedGraph::bfs(void (*work)(int&),int src)
{
            int n=this->vertices();

      LinearList<BFSNode> tree(n);
      for(int i=0;i<n;i++)
      {
        tree[i].col=WHITE;
        tree[i].pred=-1;
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
  if(mode=='m')
    {
        for(int j=0;j<n;j++)
        {
          if(this->edgeExists(i,j) && tree[j].col==WHITE)
          {
            q.push(j);
            tree[j].col=GRAY;

            tree[j].d=tree[i].d+1;
            tree[j].pred=i;
          work(j);
          }
        }
      }
      else
      {
        listnode<int>* tmp=(graphlist.AdjList()[i].getfirst());
            while(tmp!=NULL)
            {
              int j=tmp->getdata();
              if(tree[j].col==WHITE)
              {
                q.push(j);
                tree[j].col=GRAY;
                tree[j].d=tree[i].d+1;
                tree[j].pred=i;
                work(j);
              }
              tmp=tmp->getlink();
            }
      }


      }
      return tree;
}


#endif /* ifndef DIRECTED_GRAPH */
