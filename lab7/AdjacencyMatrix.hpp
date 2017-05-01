#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX 1

#include "GraphAdjacencyBase.hpp"
#include "seqLinearList.hpp"

#include <iostream>
using namespace std;

template<class T>
class AdjacencyMatrix : public GraphAdjacencyBase {

private:
  LinearList<LinearList<int> > AdMatrix;
  int v;
  int e;

public:
  AdjacencyMatrix();
  ~AdjacencyMatrix();
  void resizeAdjMatrix(int V);
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
  AdjacencyList<T>::AdjacencyMatrix(){
    v=0;
    e=0;
  }

template<class T>
  AdjacencyList<T>::~AdjacencyList(){

  }

template<class T>
  void AdjacencyList<T>::resizeAdList(int V){
    AdMatrix.resize(V);
    for(int k=0;k<V;k++){
      AdMatrix[i].resize(V);
      AdMatrix[i].fill(0);
    }
  }

template<class T>
  void AdjacencyList<T>::edgeExists(int i, int j){
    if (AdMatrix[i][j]==1) {
      return true;
    }
    else
      return false;
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
      AdMatrix[i][j]=1;
      e++;
    }
  }

template<class T>
  void AdjacencyList<T>::remove(int i, int j){
    if(this->edgeExists(i,j)){
      AdMatrix[i][j]=0;
      e--;
  }

template<class T>
  void AdjacencyList<T>::indegree(int i){
    int indeg = 0;
    for (int k = 0; k < v; k++){
        if (edgeExists(i,k)) {
          indeg++;
        }
    }
    return indeg;
  }

template<class T>
  void AdjacencyList<T>::outdegree(int i){
    int outdeg = 0;
    for (int k = 0; k < v; k++){
        if (edgeExists(i,k)) {
          outdeg++;
        }
    }
    return outdeg;
  }

template<class T>
  void AdjacencyList<T>::print(){
    for(int k = 0; k<v; k++){
      for(l=0; l<v; l++){
          cout<<AdMatrix[k][l]<<" ";
          cout << endl;
      }
    }
  }
}

#endif /* ifndef ADJACENCY_MATRIX */
