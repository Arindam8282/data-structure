#include<iostream>
using namespace std;
class Node{
  public:
  int data;
  Node *left,*right;
};
class BST{
  public:
  Node *head;
  void Inorder(Node *root) {
    if(root==NULL) return;
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
  }
  void Preorder(Node *root) {
    if(root==NULL) return;
    Preorder(root->left);
    Preorder(root->right);
    cout<<root->data<<" ";
  }
  void Postorder(Node *root) {
    if(root==NULL) return;
    cout<<root->data<<" ";
    Postorder(root->left);
    Postorder(root->right);
  }
  void display() {
    cout<<"\nInorder data : ";
    Inorder(head);
    cout<<"\nPreorder data : ";
    Preorder(head);
    cout<<"\nPostorder data : ";
    Postorder(head);
  }
  void BSTinsert(Node *root=NULL,int dt=0) {
    if(head==NULL){
      root = new Node();
      root->data = dt;
      head = root;
    } 
    else if(dt<root->data && root->left!=NULL) BSTinsert(root->left,dt);
    else if(dt>root->data && root->right!=NULL) BSTinsert(root->right,dt);
    else if(dt<root->data){
      root->left = new Node();
      root->left->data = dt;
    } 
    else if(dt>root->data){
      root->right = new Node();
      root->right->data = dt;
      return;
    } 
    else {
      cout<<"Bug found";
      return;
    } 
  }
};

int main() {
  int key=0,data;
  BST *list = new BST();
  while(key!=3) {
    cout<<"\n\t1.insert\n\t2.display\n\t3.exit\nEnter key : ";
    cin>>key;
    switch(key) {
      case 1:
      cout<<"Enter data : ";
      cin>>data;
      list->BSTinsert(list->head,data);
      break;
      case 2:
      list->display();
      break;
      default:
      break;
    }
  }
}