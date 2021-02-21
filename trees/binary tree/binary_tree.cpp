#include<iostream>
using namespace std;
class Node{
  public:
  int data;
  Node *left,*right;
};
Node* create() {
  int x;
  Node* newNode = new Node();
  cout<<"Enter Data : ";
  cin>>x;
  if(x==-1) return 0;
  newNode->data = x;
  cout<<"Enter left node data : ";
  newNode->left = create();
  cout<<"Enter right node data : ";
  newNode->right = create();
  return newNode;
}
void Inorder(Node *root) {
  if(root==NULL) return;
  Inorder(root->left);
  cout<<root->data;
  Inorder(root->right);
}
void Preorder(Node *root) {
  if(root==NULL) return;
  Preorder(root->left);
  Preorder(root->right);
  cout<<root->data;
}
void Postorder(Node *root) {
  if(root==NULL) return;
  cout<<root->data;
  Postorder(root->left);
  Postorder(root->right);
}
int main() {
  Node* root;
  root = create();
  Node *trav;
  trav = root;
  Inorder(trav);
  cout<<endl;
  Preorder(trav);
  cout<<endl;
  Postorder(trav);
}