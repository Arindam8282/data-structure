#include<iostream>
using namespace std;
#include"Graph.h"

int main() {
  int vertices=5;
  Graph *graph = new Graph(vertices);
  graph->add_edge(0, 1); 
  graph->add_edge(0, 2); 
  graph->add_edge(1, 2); 
  graph->add_edge(1, 3); 
  graph->add_edge(1, 4); 
  graph->add_edge(2, 3); 
  graph->add_edge(3, 4);
  graph->DFS(2);
  graph->print_graph();
}