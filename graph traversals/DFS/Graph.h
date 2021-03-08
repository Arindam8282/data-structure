#include"Stack.h"
class GraphNode{
  public:
  int data;
  GraphNode* next;
  GraphNode(int dt) {
    data = dt;
    next = NULL;
  }
};
class Graph{
  public:
  GraphNode *graph[100];
  Stack *visited;
  int vertices;
  Graph(int v) {
    vertices = v;
    GraphNode *graph[vertices];
    visited = new Stack();
  }
  void add_edge(int src,int data) {
    GraphNode *node = new GraphNode(data);
    node->next =  graph[src];
    graph[src] = node;
    // cout<<"\n\n"<<src<<"->"<<GraphNode->data;

    node = new GraphNode(src);
    node->next = graph[data];
    graph[data] = node;
    // cout<<"\n\n"<<data<<"<-"<<GraphNode->data;
  }
 
  void DFSUtil(int v) {
    GraphNode *iterator;
    if(!visited->contains(v)) visited->push(v);
    visited->display();
    for(iterator=graph[v];iterator!=NULL;iterator=iterator->next) {
      if(!visited->contains(iterator->data)) DFSUtil(iterator->data);
    }
  }
  void DFS(int v){
    cout<<"DFS traversal : ";
    DFSUtil(v);
  }
 
        
  void print(GraphNode *trav) {
    if(trav!=NULL) print(trav->next);
    else return;
    cout<<trav->data<<"->";
  }
  void print_graph() {
    for(int i = 0;i<vertices;i++) {
      cout<<"\n\n"<<"Adjacency list of Vertex "<<i<<endl<<"head -> ";
      print(graph[i]);
    }
      
  }
};