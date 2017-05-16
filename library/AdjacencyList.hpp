#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST 1

#include "GraphAdjacencyBase.hpp"
#include "list.hpp"
#include "seqlinearlist.hpp"

using namespace std;

template<class Item>
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

template<class Item>
AdjacencyList<Item>::AdjacencyList(){
  v=0;
  e=0;
}

template<class Item>
LinearList < list <int> > AdjacencyList<Item>::AdjaList(){
  return Adjlist;
}

template<class Item>
AdjacencyList<Item>::~AdjacencyList(){}

template<class Item>
void AdjacencyList<Item>::resizeAdjacencyList(int V){
  //Adjlist.resize(V);
  v=V;
  e=0;
}

template<class Item>
bool AdjacencyList<Item>::edgeExists(int i, int j){
  return Adjlist[i].find(j);
}

template<class Item>
int AdjacencyList<Item>::vertices(){
  return v;
}

template<class Item>
int AdjacencyList<Item>::edges(){
  return e;
}

template<class Item>
void AdjacencyList<Item>::add(int i, int j){
  if(!(this->edgeExists(i,j))){
    Adjlist[i].append(j);
    e++;
  }
}

template<class Item>
void AdjacencyList<Item>::remove(int i, int j){
  if(this->edgeExists(i,j)){
    Adjlist[i].remove(j);
    e--;
  }
}

template<class Item>
int AdjacencyList<Item>::indegree(int i){
  int indeg = 0;
  for (int k = 0; k < v; k++){
      if (Adjlist[k].find(i)) {
        indeg++;
      }
   }
}

template<class Item>
int AdjacencyList<Item>::outdegree(int i){
  return Adjlist[i].length();
}

template<class Item>
void AdjacencyList<Item>::print(){
  for(int k = 0; k<v; k++){
    cout << k <<" :";
    Adjlist[k].print();
    cout << endl;
  }
}

#endif /* ifndef ADJACENCY_LIST */
