#include<iostream>
using namespace std;
class AVLNode {
  public:
  int data;
  AVLNode *left,*right;
  int height;
};
class AVLTree{
  public:
  AVLNode *root;
  int height(AVLNode *N) { 
    if (N == NULL) 
        return 0; 
    return N->height; 
  } 
  int getBalance(AVLNode *N) { 
    if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right); 
  } 
  int max(int a, int b) { 
    return (a > b)? a : b; 
  } 
  AVLNode* newNode(int key) { 
    AVLNode* node = new AVLNode();
    node->data = key; 
    node->left = NULL; 
    node->right = NULL; 
    node->height = 1; 
    return(node); 
  } 
  AVLNode *rightRotate(AVLNode *y) { 
    AVLNode *x = y->left; 
    AVLNode *T2 = x->right; 
 
    x->right = y; 
    y->left = T2; 
 
    y->height = max(height(y->left),
                    height(y->right)) + 1; 
    x->height = max(height(x->left),
                    height(x->right)) + 1; 
 
    return x; 
  }
  AVLNode *leftRotate(AVLNode *x) { 
    AVLNode *y = x->right; 
    AVLNode *T2 = y->left; 
 
    y->left = x; 
    x->right = T2; 
 
    x->height = max(height(x->left),    
                    height(x->right)) + 1; 
    y->height = max(height(y->left), 
                    height(y->right)) + 1; 
 
    return y; 
  } 

  AVLNode* insert(AVLNode *node,int key) {
    if (node == NULL) {
      root = newNode(key);
      return root;
    }
     
 
    if (key < node->data) 
        node->left = insert(node->left, key); 
    else if (key > node->data) 
        node->right = insert(node->right, key); 
    else 
        return node; 
 
    node->height = 1 + max(height(node->left),height(node->right)); 
 
    int balance = getBalance(node); 
  
    if (balance > 1 && key < node->left->data) 
        return rightRotate(node); 
 
    if (balance < -1 && key > node->right->data) 
        return leftRotate(node); 
 
    if (balance > 1 && key > node->left->data) { 
        node->left = leftRotate(node->left); 
        return rightRotate(node); 
    } 
 
    if (balance < -1 && key < node->right->data) { 
        node->right = rightRotate(node->right); 
        return leftRotate(node); 
    } 
 
    root = node;
    return root; 
  }
  void Inorder(AVLNode *rt) {
    if(rt==NULL) return;
    Inorder(rt->left);
    cout<<rt->data<<" ";
    Inorder(rt->right);
  }
  void Preorder(AVLNode *rt) {
    if(rt==NULL) return;
    Preorder(rt->left);
    Preorder(rt->right);
    cout<<rt->data<<" ";
  }
  void Postorder(AVLNode *rt) {
    if(rt==NULL) return;
    cout<<rt->data<<" ";
    Postorder(rt->left);
    Postorder(rt->right);
  }
  void display(){
    Inorder(root);
    cout<<endl;
    Preorder(root);
    cout<<endl;
    Postorder(root);
  }
};

 
int main() {
  AVLTree *tree = new AVLTree();
  int key=0,data;
  while(key!=3) {
    cout<<"\n\t1.insert\n\t2.display\n\t3.exit\nEnter key : ";
    cin>>key;
    switch(key) {
      case 1:
      cout<<"Enter data : ";
      cin>>data;
      tree->insert(tree->root,data);
      break;
      case 2:
      tree->display();
      break;
      default:
      break;
    }
  }
}