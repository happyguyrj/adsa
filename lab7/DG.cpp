#include "DirectedGraph.hpp"

#include <cstring>
#include <string>
#include <fstream>

void work(int& i){
  cout<<" "<<i<<" ";
}

int int main(int argc, char const *argv[]) {
  int number=0, k;

  if (argc==3) {
    string filename = argv[1];
    char mode = argv[2][0];

    string line;
    ifstream myfile;
    myfile.open(filename.c_str());

    if (myfile.is_open()) {
      while (myfile.is_open()) {
        getline(myfile,line);
        number++;
      }
      number--;
      myfile.close();

      DirectedGraph graph(number,mode);
      myfile.open(filename.c_str());

      for(int k=0;k<number;k++){
        for(int l=0;l<number;l++){
          myfile>>val;
          if(val){
            graph.add(i,j);
          }
        }
      }
      myfile.close();
      cout<<endl;
      graph.print();
      cout<<endl;

      int ch,source,dest;
      while (1) {
        cout<<"1. Add edge between given vertices"<<endl;
        cout<<"2. Remove edge between given vertices"<<endl;
        cout<<"3. Check if edge exists between given vertices"<<endl;
        cout<<"4. Print Graph(Adjacency List or Adjacency Matrix)"<<endl;
        cout<<"5. Number of Edges"<<endl;
        cout<<"6. Number of Vertices"<<endl;
        cout<<"7. InDegree of a given vertex"<<endl;
        cout<<"8. OutDegree of a given vertex"<<endl;
        cout<<"9. BFS from a given vertex"<<endl;
        cout<<"10. DFS from a given vertex"<<endl;
        cout<<"11. Exit"<<endl
        cout<<"DirectedGraph << ";

        cin>>c;
        cout<<endl;

        switch (c) {
          case 1: cout<<"Enter source:"
                  cin>>source;

                  cout<<"Enter source:"
                  cin>>dest;

                  if (source<graph.vertices() && dest<graph.vertices()) {
                    graph.add(source,dest);
                    cout<<"Edge inserted"<<endl;
                  }
                  break;

          case 2: cout<<"Enter source:"
                  cin>>source;

                  cout<<"Enter source:"
                  cin>>dest;

                  if (source<graph.vertices() && dest<graph.vertices()) {
                    graph.remove(source,dest);
                    cout<<"Edge removed"<<endl;
                  }
                  break;

          case 3: cout<<"Enter source:"
                  cin>>source;

                  cout<<"Enter source:"
                  cin>>dest;

                  if (source<graph.vertices() && dest<graph.vertices()) && graph.edgeExists(source,dest) {
                    cout<<"Edge present"<<endl;
                  }
                  else{
                    cout<<"Edge absent"<<endl;
                  }
                  break;

          case 4: graph.print();
                  break;

          case 5: cout<<"Graph has "<<graph.edges()<<" edge(s)"<<endl;
                  break;
          case 6: cout<<"Graph has "<<graph.vertices()<<" vertice(s)"<<endl;
                  break;

          case 7: cout<<"Enter vertex: ";
                  cin>>source;
                  if(source<graph.vertices()){
                    cout<<"InDegree of "<<source<<" is "<<graph.indegree()<<end;
                  }
                  break;

          case 8: cout<<"Enter vertex: ";
                  cin>>source;
                  if(source<graph.vertices()){
                    cout<<"OutDegree of "<<source<<" is "<<graph.outdegree()<<end;
                  }
                  break;

          case 9: cout<<"Enter vertex: ";
                  cin>>source;
                  if(source<graph.vertices()){
                    cout<<"BFS of "<<source<<" is "<<end;
                    graph.bfs(work,source);
                  }
                  break;

          case 10: cout<<"Enter vertex: ";
                  cin>>source;
                  if(source<graph.vertices()){
                    cout<<"DFS of "<<source<<" is "<<end;
                    graph.dfs(work,source);
                  }
                  break;

          case 11: return 0;

          default: cout<<"Enter valid number"<<endl
        }
      }
    }
  }

  return 0;
}
