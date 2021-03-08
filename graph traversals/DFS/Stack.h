#include<string>
class Node{
  public:
  Node* next;
  Node* prev;
  int data;
  Node(int val=0){
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
    // cout<<data<<" pushed successfully into "<<name<<"\n";
  }
  bool contains(int dt) {
    Node *it;
    it = head;
    while(it!=NULL) {
      if(it->data == dt) return true;
      it = it->next;
    }
    return false;
  }
  int pop() {
    trav = head;
    int data;
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
    return 0;
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
  int top() {
    Node* ptr = head;
    if(head == NULL) return NULL;
    while(ptr->next!=NULL) ptr = ptr->next;
    return ptr->data;
  }
  // int getdata() {
  //   Node* ptr = head;
  //   int str;
  //   if(head==NULL) return "";
  //   else 
  //     while(ptr!=NULL) {
  //       str += ptr->data;
  //       ptr = ptr->next;
  //     }
  //   return str;
  // }
  bool isempty() {return (head==NULL)?true : false;}
  int length(){
    Node* check = head;
    int i=0;
    for(i=0;check!=NULL;i++,check = check->next) ;
    return i;
  }
};
