// QUESTIONS RELATED TO DLL:
//QUE 1 (a)
#include<iostream>
using namespace std;
class Node{
public:
int data;
Node*next;
Node*prev ;
Node(int value){
    data = value;
    next = nullptr;
    prev = nullptr;
}
};
void insertAtHead(Node*&head,int value){
    Node*newNode = new Node(value);
    if(head == nullptr){
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}
void insertAtTail(Node*&head,int value){
    Node*newNode = new Node(value);
    if(head == nullptr){
        head = newNode;
    }
    Node*temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}
void insertBetween(Node*&head,int pos,int value){
 Node*newNode = new Node(value);
 if(pos==1||head ==nullptr){
    insertAtHead(head,value);
    return;
 }
 Node*temp = head;
 for(int i=1;i<pos-1&&temp!=nullptr;i++){
   temp = temp->next;
 }
 if(temp==nullptr||temp->next ==nullptr){
    insertAtTail(head,value);
    return;
 }
 newNode->next = temp->next;
 temp->next->prev = newNode;
 temp->next = newNode;
 newNode->prev = temp;
 
}

void show(Node*head){
    Node*temp = head;
    while(temp!=nullptr){
    cout<<temp->data<<"-> ";
    temp = temp->next;
    }
    cout<<"NULL";
}
void deleteHead(Node*&head){
    if(head ==nullptr){
        cout<<"List is empty!!"<<endl;
        return;
    }
    if(head->next ==nullptr){
        delete head;
        head = nullptr;
        return;
    }
    Node*temp = head;
    head = head->next;
    temp->next->prev = nullptr;
    temp->next = nullptr;
    delete temp;
}
void deleteTail(Node*&head){
    if(head == nullptr){
        cout<<"List is already empty";
        return;
    }
    
    Node*curr = head;
    Node*previous = nullptr;
    if(curr->next ==nullptr){
        delete curr;
        head = nullptr;
        return;
    }
    while(curr->next!=nullptr){
        previous = curr;
        curr = curr->next;
    }
    previous->next = nullptr;
    curr->prev = nullptr;
    delete curr;
    
  
  
}
void deleteBetween(Node*&head,int pos){
    if(head ==nullptr){
        cout<<"List is empty"<<endl;
        return;
    }
    if(pos==1){
        Node*temp = head;
        head = head->next;
        if(head!=nullptr){
            head->prev = nullptr;
        }
        delete temp;
        return;
    }
    Node*curr = head;
    Node*previous = nullptr;
    for(int i=0;i<pos-1&&curr!=nullptr;i++){
        previous = curr;
        curr = curr->next;
    }
    if(curr==nullptr){
        cout<<"Position is out of range"<<endl;
        return;
    }
    previous->next = curr->next;
    if(curr->next!=nullptr){
        curr->next->prev = curr->prev;
    }
    curr->next = nullptr;
    curr->prev = nullptr;
    delete curr;
void search(Node*head,int value){
    Node*temp = head;
    if(head == nullptr){
        cout<<"List is empty"<<endl;
        return;
    }
    int pos=1;
    while(temp->data!=value&&temp!=nullptr){
        temp = temp->next;
        pos++;
    }
    if(temp == nullptr){
        cout<<"Node not found!!"<<endl;
        return;
    }
    else
    cout<<"Node found at position: "<<pos<<endl;
