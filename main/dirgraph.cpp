#include "../library/DirectedGraph.hpp"

#include <cstring>
#include <string>
#include <fstream>

void work(int& i){
  cout<<" "<<i<<" ";
}

int main(int argc, char const *argv[]) {
  int number=0, val;

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

      DirectedGraph graphDir(number,mode);
      myfile.open(filename.c_str());

      for(int k=0;k<number;k++){
        for(int l=0;l<number;l++){
          myfile>>val;
          if(val){
            graphDir.add(k,l);
          }
        }
      }
      myfile.close();
      cout<<endl;
      graphDir.print();
      cout<<endl;

      int c,source,dest;
      while (1) {
        cout<<"Choose operation to be performed: ";
        cout<<"\t1. Add an edge between given vertices"<<endl;
        cout<<"\t2. Remove an edge between given vertices"<<endl;
        cout<<"\t3. Check if an edge exists between given vertices"<<endl;
        cout<<"\t4. Print Graph"<<endl;
        cout<<"\t5. Number of Edges"<<endl;
        cout<<"\t6. Number of Vertices"<<endl;
        cout<<"\t7. InDegree"<<endl;
        cout<<"\t8. OutDegree"<<endl;
        cout<<"\t9. BFS"<<endl;
        cout<<"\t10. DFS"<<endl;
        cout<<"\t11. Exit"<<endl;
        cout<<endl;
        cout<<"DirectedGraph << ";

        cin>>c;
        cout<<endl;

        switch (c) {
          case 1: cout<<"Enter source:";
                  cin>>source;

                  cout<<"Enter source:";
                  cin>>dest;

                  if (source<graphDir.vertices() && dest<graphDir.vertices()) {
                    graphDir.add(source,dest);
                    cout<<"Edge inserted"<<endl;
                  }
                  break;

          case 2: cout<<"Enter source:";
                  cin>>source;

                  cout<<"Enter source:";
                  cin>>dest;

                  if (source<graphDir.vertices() && dest<graphDir.vertices()) {
                    graphDir.remove(source,dest);
                    cout<<"Edge removed"<<endl;
                  }
                  break;

          case 3: cout<<"Enter source:";
                  cin>>source;

                  cout<<"Enter source:";
                  cin>>dest;

                  if (source<graphDir.vertices() && dest<graphDir.vertices() && graphDir.edgeExists(source,dest)) {
                    cout<<"Edge present"<<endl;
                  }
                  else{
                    cout<<"Edge absent"<<endl;
                  }
                  break;

          case 4: graphDir.print();
                  break;

          case 5: cout<<"Graph has "<<graphDir.edges()<<" edge(s)"<<endl;
                  break;
          case 6: cout<<"Graph has "<<graphDir.vertices()<<" vertice(s)"<<endl;
                  break;

          case 7: cout<<"Enter vertex: ";
                  cin>>source;
                  if(source<graphDir.vertices()){
                    cout<<"InDegree of "<<source<<" is "<<graphDir.indegree(source)<<endl;
                  }
                  break;

          case 8: cout<<"Enter vertex: ";
                  cin>>source;
                  if(source<graphDir.vertices()){
                    cout<<"OutDegree of "<<source<<" is "<<graphDir.outdegree(source)<<endl;
                  }
                  break;

          case 9: cout<<"Enter vertex: ";
                  cin>>source;
                  if(source<graphDir.vertices()){
                    cout<<"BFS of "<<source<<" is "<<endl;
                    graphDir.bfs(work,source);
                  }
                  break;

          case 10: cout<<"Enter vertex: ";
                  cin>>source;
                  if(source<graphDir.vertices()){
                    cout<<"DFS of "<<source<<" is "<<endl;
                    graphDir.dfs(work,source);
                  }
                  break;

          case 11: return 0;

          default: cout<<"Enter valid number"<<endl;
        }
      }
    }
  }

  else if(argc==2){
    char mode=argv[1][0];

    cout<<"Enter number of vertices: ";
    cin>>number;

    DirectedGraph graphDir(number, mode);

    cout<<"Enter Adjacency Matrix: "<<endl;
    for(int k=0;k<number;k++){
      for(int l=0;l<number;l++){
        cin >> val;
        if(val){
          graphDir.add(k,l);
        }
      }
    }
    cout<<endl;
    cout<<"Inserted graph is:"<<endl;
    graphDir.print();
    cout<<endl;

    int c,source,dest;
    while (1) {
      cout<<"Choose operation to be performed: ";
      cout<<"\t1. Add an edge between given vertices"<<endl;
      cout<<"\t2. Remove an edge between given vertices"<<endl;
      cout<<"\t3. Check if an edge exists between given vertices"<<endl;
      cout<<"\t4. Print Graph"<<endl;
      cout<<"\t5. Number of Edges"<<endl;
      cout<<"\t6. Number of Vertices"<<endl;
      cout<<"\t7. InDegree"<<endl;
      cout<<"\t8. OutDegree"<<endl;
      cout<<"\t9. BFS"<<endl;
      cout<<"\t10. DFS"<<endl;
      cout<<"\t11. Exit"<<endl;
      cout<<endl;
      cout<<"DirectedGraph << ";

      cin>>c;
      cout<<endl;

      switch (c) {
        case 1: cout<<"Enter source:";
                cin>>source;

                cout<<"Enter source:";
                cin>>dest;

                if (source<graphDir.vertices() && dest<graphDir.vertices()) {
                  graphDir.add(source,dest);
                  cout<<"Edge inserted"<<endl;
                }
                break;

        case 2: cout<<"Enter source:";
                cin>>source;

                cout<<"Enter source:";
                cin>>dest;

                if (source<graphDir.vertices() && dest<graphDir.vertices()) {
                  graphDir.remove(source,dest);
                  cout<<"Edge removed"<<endl;
                }
                break;

        case 3: cout<<"Enter source:";
                cin>>source;

                cout<<"Enter source:";
                cin>>dest;

                if (source<graphDir.vertices() && dest<graphDir.vertices() && graphDir.edgeExists(source,dest)) {
                  cout<<"Edge present"<<endl;
                }
                else{
                  cout<<"Edge absent"<<endl;
                }
                break;

        case 4: graphDir.print();
                break;

        case 5: cout<<"Graph has "<<graphDir.edges()<<" edge(s)"<<endl;
                break;
        case 6: cout<<"Graph has "<<graphDir.vertices()<<" vertice(s)"<<endl;
                break;

        case 7: cout<<"Enter vertex: ";
                cin>>source;
                if(source<graphDir.vertices()){
                  cout<<"InDegree of "<<source<<" is "<<graphDir.indegree(source)<<endl;
                }
                break;

        case 8: cout<<"Enter vertex: ";
                cin>>source;
                if(source<graphDir.vertices()){
                  cout<<"OutDegree of "<<source<<" is "<<graphDir.outdegree(source)<<endl;
                }
                break;

        case 9: cout<<"Enter vertex: ";
                cin>>source;
                if(source<graphDir.vertices()){
                  cout<<"BFS of "<<source<<" is "<<endl;
                  graphDir.bfs(work,source);
                }
                break;

        case 10: cout<<"Enter vertex: ";
                cin>>source;
                if(source<graphDir.vertices()){
                  cout<<"DFS of "<<source<<" is "<<endl;
                  graphDir.dfs(work,source);
                }
                break;

        case 11: return 0;

        default: cout<<"Enter valid number"<<endl;
      }
    }
  }
  return 0;
}
