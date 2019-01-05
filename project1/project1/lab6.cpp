

#include <iostream>

using namespace std;

struct Node{
    Node* next;
    Node* prev;
    int val;
};

class DoublyLinkedList{
private:
    Node *head,*tail;
public:
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    void addFirst(int val){
        Node *n = new Node();
        n->val = val;
        if(tail == NULL){
            head = tail = n;
        }
        else{
            n->next = head;
            head->prev = n;
            head = n;
        }
        this->traverseFront();
    }
    void addLast(int val){
        Node *n = new Node();
        n->val = val;
        if(head == NULL){
            head = tail = n;
        }
        else{
            n->prev = tail;
            tail->next = n;
            tail = n;
        }
        this->traverseFront();
    }
    int deleteFirst(){
        if(head == NULL)
            return -1;
        Node* tmp = head;
        if(head->next != NULL)
            head->next->prev = NULL;
        head = head->next;
        int val = tmp->val;
        delete tmp;
        return val;
    }
    int deleteLast(){
        if(tail == NULL)
            return -1;
        Node* tmp = tail;
        if(tail->prev != NULL)
            tail->prev->next = NULL;
        tail = tail->prev;
        int val = tmp->val;
        delete tmp;
        return val;
    }
    int getAtHead(){
        if(head == NULL)
            return -1;
        return head->val;
    }
    int getAtTail(){
        if(tail == NULL)
            return -1;
        return tail->val;
    }
    void traverseFront(){
        Node *tmp = head;
        if(tmp == NULL){
            cout<<"List is empty. Please add a value.";
            return;
        }
        while (tmp != NULL)
        {
            cout << tmp->val << " ";
            tmp = tmp->next;
        }
        cout<<endl;
    }
    void traverseReverse(){
        Node *tmp = tail;
        if(tmp == NULL){
            cout<<"List is empty. Please add a value.";
            return;
        }
        while (tmp != NULL)
        {
            cout << tmp->val << " ";
            tmp = tmp->prev;
        }
        cout<<endl;
    }
};

int main()
{
    char ch;
    DoublyLinkedList list;
    while(ch != '9'){
        cout<<"\n1.Add a new node to the head\n2.Add a new node to the tail\n3.Delete the first node in the list\n4.Delete the last node in the list\n5.Traverse the list reversely\n6.Traverse the list\n7.Value pointed by head\n8.Value pointed by tail\n9.Exit\n\nEnter Choice : ";
        cin>>ch;
        if(ch == '1' || ch=='2'){
            std::string str;
            int val;
            cout<<endl<<"Please enter the value:";
            cin>>str;
            try{
                val = std::stoi(str);
                if(ch == '1')
                    list.addFirst(val);
                else
                    list.addLast(val);
            }
            catch(...){
                cout<<"Please provide integer value.Operation aborted"<<endl;
            }
        }
        else if(ch == '3' || ch=='4'){
            int v;
            if(ch == '3')
                v = list.deleteFirst();
            else
                v = list.deleteLast();
            if(v == -1)
                cout<<"List is empty";
            else
                cout<<"Value with "<<v<<" deleted";
        }
        else if(ch == '5')
            list.traverseReverse();
        else if(ch == '6')
            list.traverseFront();
        else if(ch == '7'){
            int valueAtFront = list.getAtHead();
            if(valueAtFront == -1)
                cout<<"List is empty";
            else
                cout<<"Value of node head pointing to is "<<valueAtFront<<endl;
        }
        else if(ch == '8'){
            int valueAtTail = list.getAtTail();
            if(valueAtTail == -1)
                cout<<"List is empty";
            else
                cout<<"Value of node tail pointing to is "<<valueAtTail<<endl;
        }
    }
    return 0;
}

