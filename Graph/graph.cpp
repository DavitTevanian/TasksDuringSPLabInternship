#include "graph.h"
#include <iostream>
 
const int INFINITE = 1 << 10;

Graph::Graph ( int vertexCount ) {

  vector < int > row ( vertexCount, 0 );
  for ( int i = 0; i < vertexCount; ++i )
      _graph.push_back ( row );
  
}

Graph::~Graph () {}

void Graph::AddEdge ( int vert1, int vert2, int distance ) {
  
  if ( (vert1 >= _graph.size()) || (vert2 >= _graph.size()) || (vert1 < 0) || (vert2 < 0) ) 
    cout<<"Graph don't contain such vertex\n";
  else if ( vert1 == vert2 ) 
    cout<<"Please enter differ vertex\n"; 
  else {
    _graph[vert1][vert2] = distance;
    _graph[vert2][vert1] = distance;
  }

}

void Graph::PrintMatrix () {
  
  cout<<endl;
  for ( size_t i = 0; i < _graph.size(); ++i ) {
    for ( size_t j = 0; j < _graph[i].size(); ++j )
      cout<<" "<<_graph[i][j]<<" ";
    cout<<"\n";
  }
  cout<<endl;

}

void Graph::Distance ( int vert1, int vert2 ) {

  int size = _graph.size();
  vector < int > dist ( size, INFINITE  );
  vector < bool > visit ( size, false );

  dist[vert1] = 0;

  for(int i = 0; i < size; ++i) {
    int curr = -1;
    for(int j = 0; j < size; ++j)
      if ( !visit[j] && (curr == -1 || dist[j] < dist[curr]) ) 
        curr = j;

    visit[curr] = true;
    for(int j = 0; j < size; ++j) 
      if ( _graph[curr][j] )
        if( dist[curr] + _graph[curr][j] < dist[j] ) 
          dist[j] = dist[curr] + _graph[curr][j];
  }

 cout <<"Distance between "<<vert1<<" and "<<vert2<<" is "<< dist[vert2]<<endl;  

}

int main () {
  int count;
  cin>>count;
  Graph graph ( count );

  int vert1, vert2, distance;
  cout<<"If you don't want add edge, enter -1\n";
  while ( true ) {
    cin >> vert1;
    if ( vert1 == -1 )
      break;
    cin >> vert2 >> distance;
    graph.AddEdge ( vert1, vert2, distance );
  }

  graph.PrintMatrix ();
  
  while ( true ) {
    cin >> vert1;
    if (vert1 == -1 )
      break;
    cin >> vert2;
    graph.Distance ( vert1, vert2 );
  }
  return 0;
}
