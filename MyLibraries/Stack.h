#include<iostream>
#include<string>
using namespace std;
class Node{
  public:
  Node* next;
  Node* prev;
  string data;
  Node(string val=" "){
    data = val;
    next = NULL;
    prev = NULL;
  }
};
//Stack to reuse the linked list 
class Stack{
 public:
  string name;
  Node* head = NULL;
  Node* trav = NULL;
  Stack(string nm="dummy") {
    name = nm + " stack";
    // cout<<name<<" created\n";
  }
  void push(string data) {
     if(head==NULL) {
      head = new Node(data);
    }
    else {
      trav = head;
      while(trav->next!=NULL) trav=trav->next;
      trav->next = new Node(data);   
      trav->next->prev = trav;
    } 
    // cout<<data<<" pushed successfully into "<<name<<"\n";
  }

  string pop() {
    trav = head;
    string data;
    if(trav == NULL) cout<<name<<" is empty";
    else if(head->next == NULL){
      // cout<<head->data<<" poped successfully from "<<name<<"\n";
      data = head->data;
      head = NULL;
      return data;
    } 
    else{
      while(trav->next->next != NULL) trav=trav->next;
      // cout<<trav->next->data<<" poped successfully from "<<name<<"\n";
      data = trav->next->data;
      trav->next = NULL;
      return data;
    }
    return "e";
  }
 
  void display(){
    trav = head;
    if(trav==NULL) 
      cout<<"empty "<<name;
    else {
      cout<<name<<" : ";
      while (trav != NULL) { 
          cout << trav->data ; 
          trav = trav->next; 
      } 
      cout<<endl;
    }
     
  }
  string top() {
    Node* ptr = head;
    if(head == NULL) return NULL;
    while(ptr->next!=NULL) ptr = ptr->next;
    return ptr->data;
  }
  string getdata() {
    Node* ptr = head;
    string str;
    if(head==NULL) return "";
    else 
      while(ptr!=NULL) {
        str += ptr->data;
        ptr = ptr->next;
      }
    return str;
  }
  bool isempty() {return (head==NULL)?true : false;}
  int length(){
    Node* check = head;
    int i=0;
    for(i=0;check!=NULL;i++,check = check->next) ;
    return i;
  }
};
