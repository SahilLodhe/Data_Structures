#include <iostream>
#include <climits>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

void print(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int occurence(Node *head, int num)
{
    Node *temp = head;
    int count = 0;
    while (temp)
    {
        if (temp->data == num)
        {
            count++;
        }
        temp = temp->next;
    }
    return count;
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
int length_by_recursion(Node *head) //time complexity = O(n)
{
    if (head == NULL)
    {
        return 0;
    }                                           //base case
    return 1 + length_by_recursion(head->next); //recursive and calculative step
}
int sum(Node *head)
{

    int sum = 0;
    Node *temp = head;
    while (temp)
    {
        sum = sum + temp->data;
        temp = temp->next;
    }

    return sum;
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
        /* code */
        temp = temp->next;
        count++;
    }
    cout << "The data for the ith node is ";
    cout << temp->data << endl;
    return 0;
}

Node *insert_at_end(Node *head, int data)
{
    Node *temp = head;
    Node *n = new Node(data);
    while (temp->next)// OR while(temp)
    {
        temp = temp->next;
    }
    temp->next = n;

    return head;
}

Node *insert_at_beginning(Node *head, int data)
{
    Node *temp;
    temp->data = data;
    temp->next = head;
    head = temp; //head ka next will be the frst element of the previous linked list
    return head;
}

Node *insert_ith_position(Node *head, int pos, int data)
{
    Node *temp = head;
    int count = 1;
    if (pos == length(head))
    {
        Node *temp = head;
        Node *n = new Node(data);
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = n;

        return head;
    }
    if (pos < 0 || pos > (length(head)))
    {
        cout << "The element cannot be added!" << endl;
        return head;
    }
    if (pos == 0)
    { //then insert at head

        Node *n = new Node(data); //the head ka next will be the first element of the previous second element of the linked list,
        n->next = temp;           //first , we will point it to the
        temp = n;
        return head;
    }

    while (count <= (pos - 1) && head) //head or head!= NULL
    {
        /* code */
        temp = temp->next;
        count++;
    }
    if (head)
    {
        Node *n = new Node(data);
        n->next = temp->next;
        temp->next = n;
        return head;
    }

    return head;
}

Node *takeInput()
{
    int data;
    int count = 0;
    cout << "How many elements do you want in your linked list? " << endl;
    int elem;
    cin >> elem;
    Node *head = NULL;
    Node *tail = NULL;
    while (count < elem)
    {

        cin >> data;
        Node *n = new Node(data);
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
Node *takeInput_rev()
{ //to print in reverse
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL; //it is always the best practice to take a temporary pointer so that the head remains pointed to the beginning of the linked list
    while (data != -1)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            n->next = head;
            head = n;
        }
        cin >> data;
    }
    return head;
}

Node *delete_ith_node(Node *head, int pos)
{
    Node *curr = head;
    if (pos < 0 && pos > (length(head) - 1))
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

//Node *delete_from_end(Node *head, int pos)
//{
//    Node *temp = head;
//    if (pos > (length(head) - 1) && pos < 0)
//    {
//        cout << "element cannot be deleted " << endl;
//        return head;
//    }
//    if (pos == (length(head - 1)) && head)
//    {
//        return head->next;
//    }
//    int count = 0;
//    while (count <= (length(head) - pos - 2) && temp)
//    {
//        temp - temp->next;
//        count++;
//    }
//    if (temp && temp->next)
//    {
//        temp->next = temp->next->next;
//        return head;
//    }
//    return head;
//}

Node *replace_index_element(Node *head, int pos, int num)
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
    temp->data = num;
    cout << temp->data << endl;
    return head;
}

bool check_element(Node *head, int data)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == data)
        {
            cout << "element is present " << endl;
            return true;
        }
        temp = temp->next;
    }
    cout << "element isn't present " << endl;
    return false;
}
bool check_element_through_recursion(Node *head, int data)
{
    //base case
    if (head == NULL)
    {
        cout << "element isn't present (by the use of recursion) " << endl;
        return false;
    }
    if (head->data == data)
    {
        cout << "the element is present (by the use of recursion)" << endl;
        return true;
    }
    //recursive case
    bool is_present = check_element_through_recursion(head->next, data);
    //calculative step
    return is_present;
}
Node *middle_element(Node *head)
{
    Node *temp = head;
    int count = 1;
    while (count <= (length(head) / 2) && head)
    {
        temp = temp->next;
        count++;
    }
    cout << "the middle node is : " << endl;
    cout << temp->data << endl;
    return head;
}

int main()
{

    Node *head1;
    //cout << "Make your linked list, enter -1 as the last element of the linked list! " << endl;
    Node *head = takeInput();
    cout << "Your list is : " << endl;
    print(head);
    cout << endl;

    cout << "press 1 for getting the length of the linked list" << endl;
    cout << "press 2 for getting the displaying the ith node of the linked list" << endl;
    cout << "press 3 for inserting an element in the ith position of the linked list" << endl;
    cout << "press 4 for deleting the ith node of the linked list(indexing starts from 0)" << endl;
    cout << "press 5 for displaying the sum of the linked list" << endl;
    cout << "press 6 for printing linked list in the reverse order" << endl;
    cout << "press 7 for getting the occurence of an element " << endl;
    cout << "press 8 for replacing the element in the linked list " << endl;
    cout << "press 9 for knowing whether an element is present or not " << endl;
    cout << "press 10 for finding the middle element of the linked list " << endl;
    //cout << "press 11 for deleting an element of the linked list from the end " << endl;

    cout << endl;

    int k = 0;
    while (k < INT_MAX)
    {
        cout << "Enter your choice :" << endl;
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "The length of the linked list by recursion is : ";
            cout << length_by_recursion(head);
            cout << endl;
            cout << "The length of the linked list without recursion is : ";
            cout << length(head);
            break;
        case 2:
            cout << "Enter the ith position for the data you want to know " << endl;
            int pos_know;
            cin >> pos_know;
            print_ith_node(head, pos_know);
            cout << endl;
            break;
        case 3:
            cout << "Enter the position and data(first element indexed 0) for which you want to insert an element " << endl;
            cout << "Enter position ";
            int pos_insert, data_insert;
            cin >> pos_insert;
            cout << endl;
            cout << "Enter data ";
            cin >> data_insert;
            //if (pos_insert == length(head))
            //{
            //    head = insert_at_end(head, data_insert);
            //    cout << "Your updated linked list is : " << endl;
            //    print(head);
            //}
            if (pos_insert != 0)
            {
                head = insert_ith_position(head, pos_insert, data_insert);
                cout << "Your updated linked list is : " << endl;
                print(head);
            }
            if (pos_insert == 0)
            {
                cout << "Your updated linked list is : " << endl;
                head = insert_at_beginning(head, data_insert);
                print(head);
            }
            cout << endl;
            break;
        case 4:
            cout << "Enter the position of the node which you want to delete" << endl;
            int pos_del;
            cin >> pos_del;
            head = delete_ith_node(head, pos_del);
            cout << endl;
            cout << "Your updated linked list is : " << endl;
            print(head);
            cout << endl;
            break;
        case 5:
            cout << "The sum of the elements in the linked list is : " << endl;
            cout << sum(head);
            cout << endl;
            break;
        case 6:
            cout << "Make your linked list!! insert -1 of you want to end it " << endl;
            head1 = takeInput_rev();
            print(head1);
            cout << endl;
            break;
        case 7:
            cout << "Enter the number for which you want to it's occurence" << endl;
            int num;
            cin >> num;
            cout << "the occurence of the number " << num << " is " << occurence(head, num) << " times" << endl;
            break;
        case 8:
            cout << "enter the index of the element of the linked list which you want to change " << endl;
            int pos_replace;
            cin >> pos_replace;
            cout << "enter the value you want to replace the previous value with " << endl;
            int data_replace;
            cin >> data_replace;
            cout << replace_index_element(head, pos_replace, data_replace) << endl;
            cout << "your updated linked list is : " << endl;
            print(head);
            break;
        case 9:
            cout << "enter the number which you want to check " << endl;
            int num_is_present;
            cin >> num_is_present;
            check_element(head, num_is_present);
            cout << endl;
            check_element_through_recursion(head, num_is_present);
            cout << endl;
            break;
        case 10:
            cout << "the middle element of the linked list is : " << endl;
            middle_element(head);
            break;
            //case 11:
            //    cout << "enter the position of the node which you want to delete from the end " << endl;
            //    int pos_del_from_end;
            //    cin >> pos_del_from_end;
            //    delete_from_end(head, pos_del_from_end);
            //    cout << "your update linked list is : " << endl;
            //    print(head);
            //    break;

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
