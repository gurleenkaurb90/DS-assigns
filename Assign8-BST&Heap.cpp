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
//(a) Search non recursive:
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
//(b) Search recursive:
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
//(c) MAXIMUM ELEMENT OF THE BST:
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
//(d) MINIMUM ELEMENT OF THE BST:
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
//(e) INORDER SUCCESSOR OF A NODE:
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
//(f) INORDER PREDECESSOR OF A NODE:
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
// QUE : 3
//(a) Insert an element (no duplicates are allowed), 
Node*insert(Node*root,Node*newNode){
    if(root == nullptr){
        return newNode;
    }
    Node*curr = root;
    Node*prev = nullptr;
    while(curr!=nullptr){
        if(newNode->data < curr->data){
            prev = curr;
        curr = curr->left;}
        else if(newNode->data > curr->data){
            prev = curr;
        curr = curr->right;}
        else if(newNode->data == curr->data){
            cout<<"Duplicate node!!"<<endl;
            return root;
        }
    }
    curr = newNode;
    if(newNode->data > prev->data)
    prev->right = curr;
    else
    prev->left = curr;
    return root;
}
//(b)  Delete an existing element,  
Node*delete(Node*root,Node*node){
    if(root == nullptr){
        cout<<"Tree is empty: nothing to be deleted !!"<<endl;
        return nullptr;
    }
    Node*curr = root;
    Node*prev = nullptr;
    while(curr->data!=node->data || curr!=nullptr){
        prev = curr;
        if(node->data<prev->data)
        node = node->left;
        else if(node->data>prev->data)
        node = node->right;
    }
    if(curr == nullptr){
        cout<<"Node to be deleted not found!!"<<endl;
        return root;
    }
    if(curr->left == nullptr || curr->right == nullptr){
        if(prev->right == curr){
            prev->right = curr->right;
            delete curr;
            return root;
        }
       else if(prev->left = curr){
        prev->left =curr->left;
        delete curr;
        return root;}
    }
    Node*succ;
    if(curr->left!=nullptr&& curr->right!=nullptr){
        succ = Minimum(curr->right);
        if(prev->right = curr){
            prev->right = succ;
            delete succ;
            return root;
        }
        else if(prev->left = curr){
            prev->left = succ;
            delete succ;
            return root;
        }
    }
}
// (c) MAXIMUM DEPTH OF A TREE:
int maxDepth(Node*root){
    if(root == nullptr)
    return -1;
    int leftSubtree = maxDepth(root->left);
    int rightSubtree = maxDepth(root->right);
    int max ;
    if(leftSubtree>rightSubtree)
    max = leftSubtree;
    else
    max = rightSubtree;
    return 1+max;
}
// (d) MINIMUM DEPTH OF A TREE:
int minDepth(Node*root){
    if(root == nullptr)
    return -1;
    if(root->left == nullptr && root->right == nullptr){
        return 0;
    }
    int leftSubtree = minDepth(root->left);
    int rightSubtree = minDepth(root->right);
    if(root->left == nullptr)
    return 1+rightSubtree;
    else if(root->right == nullptr)
    return 1+ leftSubtree;
    int min;
    else{
    if(leftSubtree <rightSubtree)
    min = leftSubtree;
    else 
    min = rightSubtree;
    return 1+min;
 }
 
}
// QUE 4:
bool isBST(Node*root, int min= INT_MIN, int max= INT_max){
    if (root == nullptr)
    return true;
    if(root->data<min || root->data>max)
    return false;
    return isBST(root->left, min, root->data - 1) &&
           isBST(root->right, root->data + 1, max);
}
// QUE 5 :


    
