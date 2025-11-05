// Que 1
#include<iostream>
using namespace std;
class Node{
public:
int data;
Node*next;
Node(int value){
    data = value;
    next = nullptr;
}
};
class circularLinkedList{
    private:
    Node*head;
    public:
    circularLinkedList(){
        head = nullptr;
    }
    void display(){
        if(head==nullptr){
            cout<<"List is empty!"<<endl;
            return;
        }
        Node*temp = head;
        do{
            cout<<temp->data<<"->";
            temp=temp->next;
        }while(temp!=head);
        cout<<"Back to head"<<endl;
    }
    void insertAtBeginning(int value){
        Node*newNode = new Node(value);
        if(head==nullptr){
            newNode->next = newNode;
            head = newNode;
            return;
        }
        Node*temp =head;
        while(temp->next!=head){
      temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
    void insertionAtEnd(int value){
        Node*newNode = new Node(value);
        if(head==nullptr){
          
            newNode->next = newNode;
            head = newNode;
            return;
        }
        Node*temp = head;
        while(temp->next!=head){
            temp = temp->next;

        }
       
        temp->next = newNode;
        newNode->next = head;
        

    }
    void insertAfter(int key,int value){
        if(head==nullptr){
            cout<<"List is empty"<<endl;
            return;
        }
        Node*temp = head;
        do{
            if(temp->data==key){
              Node*newNode = new Node(value);
              newNode->next = temp->next;
              temp->next = newNode;
              return;  
            }
            temp = temp->next;
        }while(temp!=head);
        cout<<"Node with the given key not found!!"<<endl;
    }
    void deleteAtBeginning(){
        if(head==nullptr){
            cout<<"List is empty: Nothing to eat!!"<<endl;
            return;
        }
        if(head->next == head){
            delete head;
            head = nullptr;
            return;
        }
        Node*temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        Node*temp2 = head;
        temp->next = head->next;
        head = head->next;
        delete temp2;
    }
    void deleteAtEnd(){
        if(head == nullptr){
            cout<<"List is empty!!"<<endl;
            return;
        }
        if(head->next == head){
            delete head;
            head = nullptr;
            return;
        }
        Node*temp = head;
        while(temp->next->next!=head){
            temp = temp->next;
        }
            Node*temp2 = temp->next;
        delete temp2;
        temp->next = head;

    }
    void deleteAtSpecific(int key){
        if(head==nullptr){
            cout<<"List is empty"<<endl;
            return;
        }
        if(head->data ==key){
         if(head->next==head){
            delete head;
            head = nullptr;
            return;
         }   
         Node*temp = head;
         while(temp->next!=head){
            temp = temp->next;
         }
         Node*temp2=head;
         temp->next = head->next;
         head = head->next;
         delete temp2;
         return;

        }
        Node*curr = head;
        Node*prev = nullptr;
        do{
           
            if(curr->data ==key){
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }while(curr!=head);
    }
    void search(int key){
        Node*temp = head;
        if(head == nullptr){
            cout<<"List is empty!!"<<endl;
            return;
        }
        int count = 1;
        bool found = false;
        do {
            if(temp->data == key){
                found = true;
                break;
            }
            temp = temp->next;
            count++;
        }while(temp!=head);
        if(found){
            cout<<"Key found at "<<count<<endl;
        }
        else 
        cout<<"Key not found!!"<<endl;
    }
};
int main(){
    circularLinkedList cll;
    
    int choice, value, key;

    do {
        cout << "\n========== Circular Linked List Menu ==========\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After a Key\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete by Key\n";
        cout << "7. Search for a Key\n";
        cout << "8. Display List\n";
       cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert at beginning: ";
            cin >> value;
            cll.insertAtBeginning(value);
            break;

        case 2:
            cout << "Enter value to insert at end: ";
            cin >> value;
            cll.insertionAtEnd(value);
            break;

        case 3:
            cout << "Enter key after which to insert: ";
            cin >> key;
            cout << "Enter value to insert: ";
            cin >> value;
            cll.insertAfter(key, value);
            break;

        case 4:
            cll.deleteAtBeginning();
            break;

        case 5:
            cll.deleteAtEnd();
            break;

        case 6:
            cout << "Enter key to delete: ";
            cin >> key;
            cll.deleteAtSpecific(key);
            break;

        case 7:
            cout << "Enter key to search: ";
            cin >> key;
            cll.search(key);
            break;

        case 8:
            cll.display();
            break;

       

        default:
            cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 8);

    return 0;
}
// QUE 2
#include<iostream>
using namespace std;
class Node{
public:
int data;
Node*next;
Node(int value){
    data = value;
    next = nullptr;
}
};  
class circularLinkedList{
    private:
    Node*head;
    public:
    circularLinkedList(){
        head = nullptr;
    }
 void insertAtBeginning(int value){
        Node*newNode = new Node(value);
        if(head==nullptr){
            newNode->next = newNode;
            head = newNode;
            return;
        }
        Node*temp =head;
        while(temp->next!=head){
      temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
     void insertionAtEnd(int value){
        Node*newNode = new Node(value);
        if(head==nullptr){
          
            newNode->next = newNode;
            head = newNode;
            return;
        }
        Node*temp = head;
        while(temp->next!=head){
            temp = temp->next;

        }
       
        temp->next = newNode;
        newNode->next = head;
        

    }
    void show(){
        if(head == nullptr){
            cout<<"List is empty"<<endl;
            return;
        }
        Node*temp = head;
        do{
            cout<<temp->data<<" ";
            temp = temp->next;
        }while(temp!=head);
        cout<<head->data<<endl;
        
    }


};
int main(){
  circularLinkedList cll;
  cll.insertAtBeginning(20);
  cll.insertionAtEnd(100);
  cll.insertionAtEnd(40);
  cll.insertionAtEnd(80);
  cll.insertionAtEnd(60);
  

  cll.show();
  return 0;
}
// que 3
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node(int value){
        data = value;
        next = nullptr;
    }
};
class circularLinkedList{
Node*head;
public:
circularLinkedList(){
head = nullptr;
}
int findSize(){
    if(head == nullptr){
   cout<<"List is empty!!"<<endl;
   return -1;
    }
    Node*temp = head;
    int count =0;
    do{
        temp=temp->next;
        count++;
    }while(temp!=head);
    return count;
}
void insertAtBeginning(int value){
        Node*newNode = new Node(value);
        if(head==nullptr){
            newNode->next = newNode;
            head = newNode;
            return;
        }
        Node*temp =head;
        while(temp->next!=head){
      temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }
     void insertionAtEnd(int value){
        Node*newNode = new Node(value);
        if(head==nullptr){
          
            newNode->next = newNode;
            head = newNode;
            return;
        }
        Node*temp = head;
        while(temp->next!=head){
            temp = temp->next;

        }
       
        temp->next = newNode;
        newNode->next = head;
        

    }
     void show(){
        if(head == nullptr){
            cout<<"List is empty"<<endl;
            return;
        }
        Node*temp = head;
        do{
            cout<<temp->data<<" ";
            temp = temp->next;
        }while(temp!=head);
        cout<<head->data<<endl;
        
    }
};
int main(){
    circularLinkedList cll;
    cll.insertAtBeginning(20);
    cll.insertionAtEnd(100);
    cll.insertionAtEnd(40);
    cll.insertionAtEnd(80);
    cll.insertionAtEnd(60);
    cll.show();
    cout<<cll.findSize();
    return 0;
    
    
}
// Que 5:
