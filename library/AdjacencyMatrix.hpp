#ifndef ADJACENCY_MATRIX
#define ADJACENCY_MATRIX 1

#include "GraphAdjacencyBase.hpp"
#include "seqlinearlist.hpp"

#include <iostream>

using namespace std;

template<class Item>
class AdjacencyMatrix : public GraphAdjacencyBase {
private:
  LinearList<LinearList<int> > AdjMatrix;
  int v;
  int e;

public:
  AdjacencyMatrix();
  ~AdjacencyMatrix();
  void resizeAdjacencyMatrix(int V);
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
AdjacencyMatrix<Item>::AdjacencyMatrix(){
 v=0;
 e=0;
}

template<class Item>
AdjacencyMatrix<Item>::~ AdjacencyMatrix(){}

template<class Item>
void  AdjacencyMatrix<Item>::resizeAdjacencyMatrix(int V){
 AdjMatrix.resize(V);
 for(int k=0;k<V;k++){
   AdjMatrix[k].resize(V);
   for (int l = 0; l < V; l++) {
     AdjMatrix[k][l] = 0;
   }
 }
}

template<class Item>
bool  AdjacencyMatrix<Item>::edgeExists(int i, int j){
 if (AdjMatrix[i][j]==1) {
   return true;
 }
 else
   return false;
}

template<class Item>
int  AdjacencyMatrix<Item>::vertices(){
 return v;
}

template<class Item>
int  AdjacencyMatrix<Item>::edges(){
 return e;
}

template<class Item>
void  AdjacencyMatrix<Item>::add(int i, int j){
 if(!(this->edgeExists(i,j))){
   AdjMatrix[i][j]=1;
   e++;
 }
}

template<class Item>
void  AdjacencyMatrix<Item>::remove(int i, int j){
 if(this->edgeExists(i,j)){
   AdjMatrix[i][j]=0;
   e--;
 }
}

template<class Item>
int  AdjacencyMatrix<Item>::indegree(int i){
 int indeg = 0;
 for (int k = 0; k < v; k++){
   if (edgeExists(i,k)) {
     indeg++;
   }
 }
 return indeg;
}

template<class Item>
int  AdjacencyMatrix<Item>::outdegree(int i){
 int outdeg = 0;
 for (int k = 0; k < v; k++){
   if (edgeExists(i,k)) {
     outdeg++;
   }
 }
 return outdeg;
}

template<class Item>
void  AdjacencyMatrix<Item>::print(){
 for(int k = 0; k<v; k++){
   for(int l=0; l<v; l++){
     cout<<AdjMatrix[k][l]<<" ";
     cout << endl;
   }
 }
}

#endif /* ifndef ADJACENCY_MATRIX */
