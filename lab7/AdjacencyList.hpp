// Purpose: ADSA lab
// Author: Raul Jain
// Date of Creation: 30 april 2017
//type: library file
// Bugs:

#include <iostream>
using namespace std;

#include "seqLinearList.hpp"
#include "list.hpp"
#include "GraphAdjacencyBase.hpp"

#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST 1


using namespace std;

  class AdjacencyList : public GraphAdjacencyBase {

  private:
    LinearList< list<int> > AdList;
    int v;
    int e;

  public:
    AdjacencyList();
    LinearList< list <int> >  AdjList();
    ~AdjacencyList();
    void resizeAdList(int V);
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


    LinearList< list <int> > AdjacencyList::AdjList(){
      return AdList;
    }


    AdjacencyList::~AdjacencyList(){

    }


    void AdjacencyList::resizeAdList(int V){
      AdList.resize(V);
      v=V;
      e=0;
    }


    bool AdjacencyList::edgeExists(int i, int j){
      return AdList[i].find(j);
    }


    int AdjacencyList::vertices(){
      return v;
    }


    int AdjacencyList::edges(){
      return e;
    }


    void AdjacencyList::add(int i, int j){
      if(!(this->edgeExists(i,j))){
        AdList[i].append(j);
        e++;
      }
    }


    void AdjacencyList::remove(int i, int j){
      if(this->edgeExists(i,j)){
        AdList[i].remove(j);
        e--;
      }
    }


    int AdjacencyList::indegree(int i){
      int indeg = 0;
      for (int k = 0; k < v; k++){
          if (AdList[k].find(i)) {
            indeg++;
          }
      }
    }


    int AdjacencyList::outdegree(int i){
      return AdList[i].length();
    }


    void AdjacencyList::print(){
      for(int k = 0; k<v; k++){
        cout << k <<" :";
        AdList[k].print();
        cout << endl;
      }
    }


#endif /* ifndef ADJACENCY_LIST */
