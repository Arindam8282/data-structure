#include<iostream>
#include<conio.h>
using namespace std;
class Node{
  public:
  int data;
  Node* next;
  Node* prev; 
  Node(int num) {
    data = num;
    next = NULL;
    prev = NULL;
  }
};
class LinkedList{
  public:
  Node* head = NULL;
  Node* trav = NULL;
 
  void insertAfter(int data,int pos = 0) {
    if(pos>length() || pos<1 || head==NULL) {
      cout<<"invalid position \ntotal length : "<<length();
      return;
    }
    else if(pos==length()) {
      push(data);
      return;
    }
    else{
      trav = head;
      for(int i=0;i<pos-1;i++,trav=trav->next);
      Node* holder = new Node(data);
      holder->prev=trav;
      holder->next=trav->next;
      trav->next->prev=holder;
      trav->next=holder;
    }
    cout<<data<<" pushed successfully";
  }
  void insertBefore(int data,int pos = 1){
    if(pos>length() || pos<1 || head ==NULL) {
      cout<<"invalid position \ntotal length : "<<length();
      return;
    }
    else if(pos==1) {
      pushFront(data);
      return;
    }
    else{
      trav = head;
      for(int i=0;i<pos-1;i++,trav=trav->next);
      Node* holder = new Node(data);
      holder->prev = trav->prev;
      holder->next = trav;
      trav->prev->next = holder;
      trav->prev = holder;

    }
      cout<<data<<" pushed successfully";
  }
  void deleteNode(int pos=1) {
    int data;
    if(pos>length() || pos<1 || head ==NULL) {
      cout<<"invalid node \ntotal length : "<<length();
      return;
    }
    else if(pos==length()) {
      pop();
      return;
    }
    else if(pos==1) {
      data = head->data;
      head = head->next;
      head->prev = NULL;
    }
    else{
      trav = head;
      for(int i=0;i<pos-1;i++,trav=trav->next);
      trav->prev->next = trav->next;
      trav->next->prev = trav->prev;
      data = trav->data;
    }
    cout<<data<<" deleted successfully";
  }
  void push(int data) {
    if(head==NULL) {
      head = new Node(data);
    }
    else {
      trav = head;
      while(trav->next!=NULL) trav=trav->next;
      trav->next = new Node(data);   
      trav->next->prev = trav;
    } 
    cout<<data<<" pushed successfully";
  }
  void pushFront(int data) {
    if(head==NULL) {
      push(data);
      return;
    }
    else{
      Node* holder = new Node(data);
      head->prev = holder;
      holder->next = head;
      head = holder;
    }
    cout<<data<<" pushed successfully";
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
  int length(){
    Node* check = head;
    int i=0;
    for(i=0;check!=NULL;i++,check = check->next) ;
    return i;
  }
  void display(){
    trav = head;
    if(trav==NULL) 
      cout<<"empty stack";
    else {
      cout<<"List length : "<<length()<<"\nList Data : \n\t";
      while (trav != NULL) { 
        cout<<trav<<" pointer : data -> "<< trav->data<<" next -> "<<trav->next<<" prev-> "<<trav->prev<<" \n\t"; 
        trav = trav->next; 
      } 
    }
    
  }
};

int main() {
  LinkedList obj;
  int key = 0,data,pos;
  while(key!=8) {
    data = 0;
    cout<<"\n\t1.Push\n\t2.Pop\n\t3.Display\n\t4.Insert from front\n\t5.Insert After\n\t6.Insert Before\n\t7.Delete Node\n\t8.Exit\n Enter Key - ";
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
      cout<<"Enter data - ";
      cin>>data;
      obj.pushFront(data);
      break;
      case 5:
      cout<<"Enter data - ";
      cin>>data;
      cout<<"Enter Position - ";
      cin>>pos;
      obj.insertAfter(data,pos);
      break;
      case 6:
      cout<<"Enter data - ";
      cin>>data;
      cout<<"Enter Position - ";
      cin>>pos;
      obj.insertBefore(data,pos);
      break;
      case 7:
      cout<<"Enter Position - ";
      cin>>pos;
      obj.deleteNode(pos);
      break;
      case 8:
      cout<<"stack closed";
      break;
      default:
      cout<<"wrong input";
      break;
    }
  } 
  return 0;
}