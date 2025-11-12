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
// QUE 2:
(a) Search non recursive:
void search(Node*root,int key){
    while(root!=nullptr&&root->data!=key){
        if(key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    if(root == nullptr){
        cout<<"Key not found"<<endl;
    }
    else
    cout<<"Key found"<<endl;
}
(b) Search recursive:
void searchRecursive(Node*root,int key){
    if(root ==nullptr){
        cout<<"Key not found"<<endl;
        return;
    }
    if(root->data == key){
        cout<<"Key found!!"<<endl;
        return;
    }
    if(key<root->data)
    searchRecursive(root->left,key);
    if(key>root->data)
    searchRecursive(root->right,key);
}
(c) MAXIMUM ELEMENT OF THE BST:
    void Maximum(Node*root){
    if(root == nullptr){
        cout<<"Tree is empty"<<endl;
        return;
    }
    while(root->right!=nullptr){
        root = root->right;
    }
    cout<<"Maximum element is "<<root->data<<endl;
    
}
(d) MINIMUM ELEMENT OF THE BST:
    void Minimum(Node*root){
    if(root == nullptr){
        cout<<"Tree is empty"<<endl;
        return;
    }
    while(root->left!=nullptr){
        root = root->left;
    }
    cout<<"Minimum element is"<<root->data<<endl;
}
(e) INORDER SUCCESSOR OF A NODE:
    Node*InorderSuccessor(Node*node){
    if(node == nullptr){
        return nullptr;
    }
    if(node->right!=nullptr){
        return treeMinimum(node->right);
    }
    Node*parent = node->parent;
    while(parent!=nullptr&&node == parent->right){
        node = parent;
        parent = parent->parent;
    }
    return parent;
}
(f) INORDER PREDECESSOR OF A NODE:
    ode*predecessor(Node*node){
    if(node == nullptr){
        cout<<"No node"<<endl;
        return nullptr;
    }
    if(node->left!=nullptr){
        node = node->left;
       
            while(node->right!=nullptr){
                node = node->right;
            }
            return node;
        
        
    }
    if(node->left == nullptr ){
        Node*parent = node->parent;
        while(parent!=nullptr && node==parent->left){
            node = parent;
            parent = parent->parent;
        }
       
        return parent;
    }
}
    
