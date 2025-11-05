// QUESTION : 1
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*right;
    Node*left;
   
    Node(int value){
        
        data = value;
        right = nullptr;
        left = nullptr;
    }
};
void PreOrder(Node*root){
    if(root == nullptr)
    return;
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}
void InOrder(Node*root){
    if(root==nullptr)
    return;
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}
void PostOrder(Node*root){
    if(root == nullptr)
    return;
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}
int main(){
    Node*root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout<<"Pre-order traversal of the tree : "<<endl;
    PreOrder(root);
    cout<<endl;
    cout<<"In-order traversal of the tree:  "<<endl;
    InOrder(root);
    cout<<endl;
    cout<<"Post-order traversal of the tree: "<<endl;
    PostOrder(root);
    cout<<endl;
    return 0;
}
