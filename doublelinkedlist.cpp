#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node*next;
    Node*prev;
    Node(int data){
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

Node*insert_at_beginning(Node*head,int data){
    Node*n = new Node(data);
    n->next = head;
    head->prev = n;
    head = n;
    return head;
}

Node*insert_at_end(Node*head,int data){
    Node*n = new Node(data);
    Node*start = head;
    while (start->next){
        start = start->next;
    }
    start->next = n;
    n->prev = start;
    return head;   
}
void print(Node*head){
    Node*temp = head;
    while (temp){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}
    Node*takeinput(){
    Node*head = NULL;
    Node*tail = NULL;
    int data;
    int count = 0;
    int elem;
    cout<<"how many elements do you want in your linked list? "<<endl;
    cin>>elem;
    
    while (count<elem)
    {
        cin>>data;
        Node*n = new Node(data);
        if(head == NULL){
            head = n;
            tail = n;
        }
        else{
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
        count++;
    }
    return head;
}
int main(){
    Node*head;
    head = takeinput();
    print(head);
    head = insert_at_beginning(head,56);
    print(head);
    head = insert_at_end(head,67);
    print(head);

    return 0;
}