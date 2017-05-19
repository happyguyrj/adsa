#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX 1

#include "GraphAdjacencyBase.hpp"
#include "seqlinearlist.hpp"

#include <iostream>
using namespace std;


class AdjacencyMatrix : public GraphAdjacencyBase {

private:
  LinearList<LinearList<int> > AdMatrix;
  int v;
  int e;

public:
  AdjacencyMatrix();
  ~AdjacencyMatrix();
  void resAdjacencyMatrix(int V);
  bool edgeExists(int i, int j);
  int vertices();
  int edges();
  void add(int i, int j);
  void remove(int i, int j);
  int indegree(int i);
  int outdegree(int i);
  void print();
};


   AdjacencyMatrix::AdjacencyMatrix(){
    v=0;
    e=0;
  }


   AdjacencyMatrix::~ AdjacencyMatrix(){

  }


  void  AdjacencyMatrix::resAdjacencyMatrix(int V){
    AdMatrix.resize(V);
    for(int k=0;k<V;k++){
      AdMatrix[k].resize(V);
      AdMatrix[k].fill(0);
    }
  }


  bool  AdjacencyMatrix::edgeExists(int i, int j){
    if (AdMatrix[i][j]==1) {
      return true;
    }
    else
      return false;
  }


  int  AdjacencyMatrix::vertices(){
    return v;
  }


  int  AdjacencyMatrix::edges(){
    return e;
  }


  void  AdjacencyMatrix::add(int i, int j){
    if(!(this->edgeExists(i,j))){
      AdMatrix[i][j]=1;
      e++;
    }
  }


  void  AdjacencyMatrix::remove(int i, int j){
    if(this->edgeExists(i,j)){
      AdMatrix[i][j]=0;
      e--;
    }
  }


  int  AdjacencyMatrix::indegree(int i){
    int indeg = 0;
    for (int k = 0; k < v; k++){
        if (edgeExists(i,k)) {
          indeg++;
        }
    }
    return indeg;
  }


  int  AdjacencyMatrix::outdegree(int i){
    int outdeg = 0;
    for (int k = 0; k < v; k++){
        if (edgeExists(i,k)) {
          outdeg++;
        }
    }
    return outdeg;
  }


  void  AdjacencyMatrix::print(){
    for(int k = 0; k<v; k++){
      for(int l=0; l<v; l++){
          cout<<AdMatrix[k][l]<<" ";
          cout << endl;
      }
    }
  }

#endif /* ifndef ADJACENCY_MATRIX */
