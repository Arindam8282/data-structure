#include<iostream>
#include<conio.h>
using namespace std;
class Node{
  public:
  int data;
  Node* next; 
  Node(int num) {
    data = num;
    next = NULL;
  }
};
class LinkedList{
  public:
  Node* head = NULL;
  Node* trav = NULL;

  void push(int data) {
    if(head==NULL) {
      head = new Node(data);
    }
    else {
      trav = head;
      while(trav->next!=NULL) trav=trav->next;
      trav->next = new Node(data);   
    } 
    cout<<data<<" pushed succefully";
  }

  void pop() {
    trav = head;
    if(trav == NULL) cout<<"stack is empty";
    else if(head->next == NULL){
      cout<<head->data<<" poped successfully \n";
      head = NULL;
    } 
    else{
      while(trav->next->next != NULL) trav=trav->next;
      cout<<trav->next->data<<" poped successfully \n";
      trav->next = NULL;
    }
    
  }
  void display(){
    trav = head;
    if(trav==NULL) 
      cout<<"empty stack";
    else
      while (trav != NULL) { 
          cout <<trav<<" pointer : "<< trav->data << " \n"; 
          trav = trav->next; 
      } 
  }
};

int main() {
  LinkedList obj;
  // obj->push(3);
  // obj->push(4);
  int key = 0,data;
  while(key!=4) {
    data = 0;
    cout<<"\n\t1.Push\n\t2.Pop\n\t3.Display\n\t4.Exit\n Enter Key - ";
    cin>>key;
    switch(key) {
      case 1:
      cout<<"Enter data - ";
      cin>>data;
      obj.push(data);
      break;
      case 2:
      obj.pop();
      break;
      case 3:
      obj.display();
      break;
      case 4:
      cout<<"stack closed";
      break;
      default:
      cout<<"wrong input";
      break;
    }
  } 
  return 0;
}