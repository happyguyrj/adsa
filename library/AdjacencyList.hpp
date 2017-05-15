#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST 1

#include "GraphAdjacencyBase.hpp"
#include "list.hpp"
#include "seqlinearlist.hpp"

using namespace std;

class AdjacencyList : public GraphAdjacencyBase {

private:
  LinearList< list <int> > Adjlist;
  int v, e;

public:
  AdjacencyList();
  LinearList< list <int> >  AdjaList();
  ~AdjacencyList();
  void resizeAdjacencyList(int V);
  bool edgeExists(int i, int j);
  int vertices();
  int edges();
  void add(int i, int j);
  void remove(int i, int j);
  int indegree(int i);
  int outdegree(int i);
  void print();
};

AdjacencyList::AdjacencyList(){
  v=0;
  e=0;
}

LinearList < list <int> > AdjacencyList::AdjaList(){
  return Adjlist;
}

AdjacencyList::~AdjacencyList(){}

void AdjacencyList::resizeAdjacencyList(int V){
  //Adjlist.resize(V);
  v=V;
  e=0;
}

bool AdjacencyList::edgeExists(int i, int j){
  return Adjlist[i].find(j);
}

int AdjacencyList::vertices(){
  return v;
}

int AdjacencyList::edges(){
  return e;
}

void AdjacencyList::add(int i, int j){
  if(!(this->edgeExists(i,j))){
    Adjlist[i].append(j);
    e++;
  }
}

void AdjacencyList::remove(int i, int j){
  if(this->edgeExists(i,j)){
    Adjlist[i].remove(j);
    e--;
  }
}

int AdjacencyList::indegree(int i){
  int indeg = 0;
  for (int k = 0; k < v; k++){
      if (Adjlist[k].find(i)) {
        indeg++;
      }
   }
}

int AdjacencyList::outdegree(int i){
  return Adjlist[i].length();
}

void AdjacencyList::print(){
  for(int k = 0; k<v; k++){
    cout << k <<" :";
    Adjlist[k].print();
    cout << endl;
  }
}

#endif /* ifndef ADJACENCY_LIST */
