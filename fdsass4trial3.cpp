#include <iostream>
using namespace std;

/*
FDS assignment 4
Name : Sahil Lodhe
Roll Number - 224067
GR Number - 22010886
Div - D, Batch - D3
*/

struct Node
{
    int data;
    string name;
    string dob;
    string address;
    int empid;
    int sallary;
    Node *next;

    Node(int data, string name, string dob, string address, int empid, int sallary)
    {
        this->data = data;
        this->name = name;
        this->dob = dob;
        this->address = address;
        this->empid = empid;
        this->sallary = sallary;
        next = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        cout << temp->dob << " ";
        cout << temp->name << " ";
        cout << temp->address << " ";
        cout << temp->empid << " ";
        cout << temp->sallary << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int length(Node *head)
{

    int count = 0;
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        count++;
    }

    return count;
}

int print_ith_node(Node *head, int pos)
{
    Node *temp = head;
    if (pos < 0 || pos > (length(head) - 1))
    {
        cout << "The element does not exist!" << endl;
        return 0;
    }
    int count = 1;

    while (count <= pos && temp)
    {
        temp = temp->next;
        count++;
    }
    cout << "The data for the ith node is ";
    cout << temp->data << endl;
    return 0;
}

Node *insert_at_beginning(Node *head, int data, string name, string dob, string address, int empid, int sallary) //int data,string name,string dob,string address,int empid,int sallary
{
    Node *temp;
    temp->data = data;
    temp->name = name;
    temp->dob = dob;
    temp->address = address;
    temp->empid = empid;
    temp->sallary = sallary;
    temp->next = head;
    head = temp; //head ka next will be the frst element of the previous linked list
    return head;
}

Node *insert_at_end(Node *head, int data, string name, string dob, string address, int empid, int sallary)
{
    Node *temp = head;
    Node *n = new Node(data, name, dob, address, empid, sallary);
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = n;
    //temp->data = data;
    return head;
}

Node *insert_ith_position(Node *head, int pos, int data, string name, string dob, string address, int empid, int sallary)
{
    Node *temp = head;
    int count = 1;
    if (pos < 0 || pos > (length(head) - 1))
    {
        cout << "The element cannot be added!" << endl;
        return head;
    }
    //if (pos == 0)
    //{
    //
    //    Node *n = new Node(data,name,dob,address,empid,sallary); //the head ka next will be the first element of the previous second element of the linked list,
    //    n->next = temp;           //first , we will point it to the
    //    temp = n;
    //    return head;
    //}

    while (count <= (pos - 1) && head) //head or head!= NULL
    {
        temp = temp->next;
        count++;
    }
    if (head)
    {
        Node *n = new Node(data, name, dob, address, empid, sallary);
        n->next = temp->next;
        temp->next = n;
        return head;
    }

    return head;
}

Node *takeInput()
{
    int data;
    string name;
    string dob;
    string address;
    int empid;
    int sallary;
    int count = 0;
    cout << "How many elements do you want in your linked list? " << endl;
    int elem;
    cin >> elem;
    Node *head = NULL;
    Node *tail = NULL;
    while (count < elem)
    {
        cout << "enter data" << endl;
        cin >> data;
        cout << "enter name" << endl;
        cin >> name;
        cout << "enter dob" << endl;
        cin >> dob;
        cout << "enter address" << endl;
        cin >> address;
        cout << "enter empid" << endl;
        cin >> empid;
        cout << "enter sallary" << endl;
        cin >> sallary;
        Node *n = new Node(data, name, dob, address, empid, sallary);
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n; //inserting at tail
            tail = n;
        }
        count++;
    }
    return head;
}

Node *delete_node(Node *head, int pos)
{
    Node *curr = head;
    if (pos < 0 || pos > (length(head) - 1))
    {
        cout << "element does not exist! " << endl;
        return head;
    }
    if (pos == 0 && head)
    {
        return head->next;
    }
    int count = 1;
    while (count <= (pos - 1) && curr)
    {
        curr = curr->next;
        count++;
    }

    if (curr && curr->next)
    {
        curr->next = curr->next->next;
        return head;
    }
    return head;
}

Node *modify(Node *head, int pos, int data, string name, string dob, string address, int empid, int sallary)
{
    Node *temp = head;
    if (pos < 0 || pos > (length(head) - 1))
    {
        cout << "The element does not exist!" << endl;
        return head;
    }
    int count = 1;

    while (count <= pos && temp)
    {
        temp = temp->next;
        count++;
    }
    cout << "The data for the ith node is ";
    cout << data << endl;
    cout << name << endl;
    cout << dob << endl;
    cout << address << endl;
    cout << empid << endl;
    cout << sallary << endl;
    temp->data = data;
    temp->name = name;
    temp->dob = dob;
    temp->address = address;
    temp->empid = empid;
    temp->sallary = sallary;
    return head;
}

void search_element(Node *head, int data)
{
    Node *temp = head;
    int count = 0;
    while (temp)
    {

        if (temp->data == data)
        {
            cout << "element is present at index : " << count << endl;
            count++;
        }

        temp = temp->next;
    }
    if (count == 0)
    {
        cout << "element isn't present! " << endl;
    }
}

int main()
{

    Node *head1;
    cout << "Make your linked list " << endl;
    Node *head = takeInput();
    cout << "Your list is : " << endl;
    print(head);
    cout << endl;

    cout << "press 1 for inserting an element in the ith position of the linked list" << endl;
    cout << "press 2 for deleting the ith node of the linked list(indexing starts from 0)" << endl;
    cout << "press 3 for replacing the element in the linked list " << endl;
    cout << "press 4 for knowing whether an element is present or not " << endl;

    cout << endl;

    int k = 0;
    while (k < INT_MAX)
    {
        cout << "Enter your choice :" << endl;
        int choice;
        cin >> choice;
        switch(choice)
        {
        case 1:
            cout << "Enter the position and data(first element indexed 0) for which you want to insert an element " << endl;
            cout << "Enter position ";
            int pos_insert, data_insert;
            string name_insert;
            string dob_insert;
            string address_insert;
            int empid_insert;
            int sallary_insert;
            cin >> pos_insert;
            cout << endl;
            cout << "Enter data ";
            cin >> data_insert;
            cout << "Enter name" << endl;
            cin >> name_insert;
            cout << "Enter dob" << endl;
            cin >> dob_insert;
            cout << "Enter address" << endl;
            cin >> address_insert;
            cout << "Enter empid" << endl;
            cin >> empid_insert;
            cout << "Enter sallary" << endl;
            cin >> sallary_insert;
            if (pos_insert != 0)
            {
                head = insert_ith_position(head, pos_insert, data_insert, name_insert, dob_insert, address_insert, empid_insert, sallary_insert);
                cout << "Your updated linked list is : " << endl;
                print(head);
            }
            if (pos_insert == 0)
            {
                cout << "Your updated linked list is : " << endl;
                head = insert_at_beginning(head, data_insert, name_insert, dob_insert, address_insert, empid_insert, sallary_insert);
                print(head);
            }
            if (pos_insert == length(head))
            {
                cout << "Your updated linked list is : " << endl;
                head = insert_at_end(head, data_insert, name_insert, dob_insert, address_insert, empid_insert, sallary_insert);
                print(head);
            }
            cout << endl;
            break;
        case 2:
            cout << "Enter the position of the node which you want to delete" << endl;
            int pos_del;
            cin >> pos_del;
            head = delete_node(head, pos_del);
            cout << endl;
            cout << "Your updated linked list is : " << endl;
            print(head);
            cout << endl;
            break;

        case 3:
            cout << "enter the index of the element of the linked list which you want to change " << endl;
            int pos_replace;
            cin >> pos_replace;
            cout << "enter the value you want to replace the previous value with " << endl;
            int data_replace;
            cin >> data_replace;
            cout << "enter new name" << endl;
            string name_replace;
            cin >> name_replace;
            cout << "enter new dob" << endl;
            string dob_replace;
            cin >> dob_replace;
            cout << "enter new address" << endl;
            string address_replace;
            cin >> address_replace;
            cout << address_replace;
            cout << "enter new empid" << endl;
            int empid_replace;
            cin >> empid_replace;
            cout << "enter new sallary" << endl;
            int sallary_replace;
            cin >> sallary_replace;
            modify(head, pos_replace, data_replace, name_replace, dob_replace, address_replace, empid_replace, sallary_replace);
            cout << "your updated linked list is : " << endl; //Node *head, int pos, int data, string name, string dob, string address, int empid, int sallary
            print(head);
            break;
        case 4:
            cout << "enter the name of the employee which you want to check " << endl;
            int data_is_present;
            cin >> data_is_present;
            search_element(head, data_is_present);
            cout << endl;
            break;

        default:
            cout << "Enter a valid input!" << endl;
            cout << endl;
            break;
        }

        cout << endl;
        k++;
    }

    return 0;
}