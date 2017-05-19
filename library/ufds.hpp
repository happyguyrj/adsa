#ifndef UFDS_
#define UFDS_ 1

#include "seqlinearlist.hpp"

class UFDS {
  // Private attributes and functions for class
  // If you want to add any more variables, please add them
  // and give a valid reason for their use.
  // DO NOT DELETE ANY OF THE MEMBERS FROM BELOW
  // YOU NEED TO USE THEM ALL.

  // node in consideration for union find data structure
  // stores parent and rank for each vertex
  // You may add new members to the node, with explanation as to
  // why the members were necessary.
  class node {
    public:
      int parent;
      int rank;
  };

  LinearList<node> vertex;
  int size;

  public:
    // Create an empty union find data structure with N isolated sets.
    UFDS(const unsigned int& N);

    // Default constructor
    //~UFDS();

    // Make a new set with N vertices with all sets being disjoint
    void make_set (const unsigned int& N);

    // Return the representative / parent of set consisting of object x.
    int find_set (const unsigned int& x);

    // Unite sets containing objects x and y.
    void union_set (const unsigned int& x, const unsigned int& y);

    // Are objects x and y in the same set?
    bool is_same_set (const unsigned int& x, const unsigned int& y);

    // Return the number of disjoint sets.
    int num_disjoint_sets();

    // Return the size of the set containing object x.
    int size_set (const unsigned int& x);
  };

  UFDS::UFDS(const unsigned int& N)  :vertex(N){
    size = N;
    for(int i=0;i<N;i++){
      vertex[i].parent = i;
      vertex[i].rank = 0;
     }
   }

   int UFDS::find_set(const unsigned int& x){
    if(vertex[x].parent != x){
      vertex[x].parent = this->find_set(vertex[x].parent);
    }
    return vertex[x].parent;
  }

  void UFDS::union_set(const unsigned int& x, const unsigned int& y){

    int xroot = this->find_set(x);
    int yroot = this->find_set(y);

    if (vertex[xroot].rank < vertex[yroot].rank){
        vertex[xroot].parent = yroot;
      }
    else if (vertex[xroot].rank > vertex[yroot].rank){
        vertex[yroot].parent = xroot;
      }
    else{
       vertex[yroot].parent = xroot;
       vertex[xroot].rank++;
      }
  }

  bool UFDS::is_same_set (const unsigned int& x, const unsigned int& y){
    return vertex[x].parent == vertex[y].parent;
  }

  int UFDS::num_disjoint_sets(){
    bool check[size];
    int count =0;
    for(int i=0;i<size;i++){
      if(check[vertex[i].parent])
        count++;
        check[vertex[i].parent] = 0;
      }
    return count;
  }

  int UFDS::size_set (const unsigned int& x){
    int count =0;
    for(int i=0;i<size;i++){
      if(vertex[i].parent == vertex[x].parent)
        count++;
    }
    return count;
  }

  void UFDS::make_set (const unsigned int& N){
    vertex.resize(N);

    for(int i=0;i<N;i++){
      vertex[i].parent = i;
      vertex[i].rank = 0;
     }
  }

#endif  /* UFDS_ */
