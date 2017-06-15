#ifndef _GRAPH_
#define _GRAPH_

#include <vector>
using namespace std;

class Graph {

  public:
    Graph ( int vertexCount );
    ~Graph ();
    void AddEdge ( int vert1, int vert2, int distance );
    void Distance ( int vert1, int vert2 );
    void PrintMatrix ();
  private:
    vector < vector < int > > _graph;
};

#endif //_GRAPH_
