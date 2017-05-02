// Purpose: ADSA lab
// Author: Raul Jain
// Date of Creation: 30 april 2017
//type: library file
// Bugs:

#include <iostream>
using namespace std;
#include "GraphAdjacencyBase.hpp"

#ifndef ADJACENCY_LIST
#define ADJACENCY_LIST 1

#include "seqLinearList.hpp"
#include "list.hpp"

using namespace cs202;
using namespace std;

namespace cs202{
  template<typename T>
  class AdjacencyList : public GraphAdjacencyBase {

  private:
    LinearList< list<int> > AdList;
    int v;
    int e;

  public:
    AdjacencyList();
    void AdjList();
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

  template<class T>
    AdjacencyList<T>::AdjacencyList(){
      v=0;
      e=0;
    }

  template<class T>
    void AdjacencyList<T>::AdjList(){
      return AdList;
    }

  template<class T>
    AdjacencyList<T>::~AdjacencyList(){

    }

  template<class T>
    void AdjacencyList<T>::resizeAdList(int V){
      AdList.resize(V);
      v=V;
      e=0;
    }

  template<class T>
    void AdjacencyList<T>::edgeExists(int i, int j){
      return AdList[i].find(j);
    }

  template<class T>
    void AdjacencyList<T>::vertices(){
      return v;
    }

  template<class T>
    void AdjacencyList<T>::edges(){
      return e;
    }

  template<class T>
    void AdjacencyList<T>::add(int i, int j){
      if(!(this->edgeExists(i,j))){
        AdList[i].append(j);
        e++;
      }
    }

  template<class T>
    void AdjacencyList<T>::remove(int i, int j){
      if(this->edgeExists(i,j)){
        AdList[i].remove(j);
        e--;
    }

  template<class T>
    void AdjacencyList<T>::indegree(int i){
      int indeg = 0;
      for (int k = 0; k < v; k++){
          if (AdList[j].find(i)) {
            indeg++;
          }
      }
    }

  template<class T>
    void AdjacencyList<T>::outdegree(int i){
      return AdList[i].length();
    }

  template<class T>
    void AdjacencyList<T>::print(){
      for(int k = 0; k<v; k++){
        cout << k <<" :";
        AdList[k].print();
        cout << endl;
      }
    }
}


#endif /* ifndef ADJACENCY_LIST */
