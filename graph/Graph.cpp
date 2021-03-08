#include<iostream>
using namespace std;
class Node{
  public:
  int data;
  Node* next;
  Node(int dt) {
    data = dt;
    next = NULL;
  }
};
class Graph{
  public:
  Node *graph[5];
  int vertices;
  Graph(int v) {
    vertices = v;
    Node *graph[vertices];

  }
  void add_edge(int src,int data) {
    Node *node = new Node(data);
    node->next =  graph[src];
    graph[src] = node;
    // cout<<"\n\n"<<src<<"->"<<node->data;

    node = new Node(src);
    node->next = graph[data];
    graph[data] = node;
    // cout<<"\n\n"<<data<<"<-"<<node->data;
  }
  void print(Node *trav) {
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
int main() {
  int V = 3;
  Graph *graph = new Graph(V); 
  graph->add_edge(0, 1); 
  graph->add_edge(0, 2); 
  graph->add_edge(1, 2); 
  // graph->add_edge(1, 3); 
  // graph->add_edge(1, 4); 
  // graph->add_edge(2, 3); 
  // graph->add_edge(3, 4);
  graph->print_graph();

}