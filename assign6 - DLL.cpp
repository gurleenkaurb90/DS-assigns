// QUESTIONS RELATED TO DLL:
//QUE 1 :
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
int main(){
    Node*head = nullptr;
    cout<<"***MENU***"<<endl;
    cout<<"1.INSERT AT HEAD "<<endl;
    cout<<"2.INSERT AT TAIL "<<endl;
    cout<<"3.INSERT IN BETWEEN "<<endl;
    cout<<"4.DELETE AT HEAD "<<endl;
    cout<<"5.DELETE AT TAIL "<<endl;
    cout<<"6.DELETE IN BETWEEN "<<endl;
    cout<<"7.SEARCH "<<endl;
    cout<<"8.SHOW "<<endl;
    int choice;
    cout<<"Enter your choice: "<<edl;
    cin>>choice;
    switch(choice){
        case 1:{
        int value;
        cout<<"Enter the value you want to insert at head: "<<endl;
        cin>>value;
        insertAtHead(head,value);
        break;}
        case 2:{
            int value;
            cout<<"Enter value to insert at tail: "<<endl;
            cin>>value;
            insertAtTail(head,value);
            break;
        }
        case 3:
        {
            int value;
            cout<<"Enter the value to be inserted: "<<endl;
            cin>>value;
            int position;
            cout<<"Enter the position: "<<endl;
            cin>>position;
            insertBetween(head,position,value);
            break;
        }
        case 4:
        {
            deleteHead(head);
            break;
        }
        case 5:{
            deleteTail(head);
            break;
        }
        case 6:{
            int position;
            cout<<"Enter the position of the node to be deleted: "<<endl;
            cin>>position;
            deleteBetween(head,position);
            break;
        }
        case 7:{
            int value;
            cout<<"Enter the value to be searched: "<<endl;
            cin>>value;
            search(head,value);
            break;
        }
        case 8:{
            show(head);
            break;
        }

    }
    return 0;
    
    
}
// Que 3 :  Write a program to find size of 
//i. Doubly Linked List. 
#include<iostream>
using namespace std;
class Node{
public:
int data ;
Node*prev;
Node*next;
Node(int value){
    data = value;
    next = nullptr;
    prev = nullptr;
}
};
void sizeOfList(Node*head){
    Node*temp = head;
    if(head == nullptr){
        cout<<"List is empty,ie,size is 0"<<endl;
        return;
    }
    int count = 0;
    while(temp!=nullptr){
        temp = temp->next;
        count++;
    }
    cout<<"Size is : "<<count<<endl;
}
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
int main(){
    Node*head = nullptr;
insertAtHead(head,1);
insertAtTail(head,2);
insertAtTail(head,3);
insertAtTail(head,4);
insertAtTail(head,5);
sizeOfList(head);
return 0;
}
//QUE 4:
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*prev;
    Node(int value){
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
void pallindrome(Node*head){
    if(head == nullptr){
        cout<<"List is empty!!"<<endl;
        return;
    }
    if(head->next == nullptr){
        cout<<"Single Node!!"<<endl;
        return;
    }
    Node*temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    Node*tail = temp;
    bool IsPallindrome = true;
    while(head!=tail&&head->prev!=tail){
        if(head->data!=tail->data){
            IsPallindrome = false;
            break;
        }
        head = head->next;
        tail = tail->prev;
    }
    if(IsPallindrome){
        cout<<"TRUE"<<endl;

    }
    else
    cout<<"FALSE"<<endl;
}
void Insert(Node*&head,int value){
    Node*newNode = new Node(value);
    if(head == nullptr){
        head = newNode;
        return;
    }
    Node*temp = head;
    while(temp->next!=nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}
int main(){
    Node*head = nullptr;
    Insert(head,'l');
    Insert(head,'e');
    Insert(head,'v');
    Insert(head,'e');
    Insert(head,'l');
    pallindrome(head);
    return 0;
} 
