#include <bits/stdc++.h>
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
void print(vector<vector<int>>&matrix){
    for(auto i : matrix){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
void print(vector<vector<string>>&matrix){
    for(auto i : matrix){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
void print(vector<int>&nums){
    for(auto i : nums){
        cout<<i<<" ";
    }
    cout<<endl;
}
void print(vector<string>&nums){
    for(auto i : nums){
        cout<<i<<" ";
    }
    cout<<endl;
}

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
    if (head->next == NULL)
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
Node*delete_duplicates(Node*head){
    if(!head || !head->next){
        return head;
    }
    Node*curr = head;
    Node*prev = NULL;
    while(curr && curr->next){
        if(curr->data == curr->next->data){
            while(curr->next && curr->data == curr->next->data){
                curr = curr->next;
            }
            if(prev){
                prev->next = curr->next;
                curr = curr->next;
            }
            else{
                head = curr->next;
                curr = curr->next;
            }
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

Node*reverse(Node*head){
    Node*prev = NULL;
    Node*curr = head;
    Node*temp;
    while(curr){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
    return head;
}

Node* removeDuplicates(Node*head){
    unordered_set<int>mp;
    Node*temp = head;
    Node*previous = head;
    if(head){
        while(temp){
            if(mp.find(temp->data) != mp.end()){
                previous->next = temp->next;
            }
            else{
                mp.insert(temp->data);
                previous = temp;
            }
            temp = temp->next;
        }
    }
    return head;
}

int Kth_from_last(Node*head,int k){
    if(!head){
        return -1;
    }
    int index = Kth_from_last(head->next,k) + 1;
    if(index == k){
        cout<<head->data<<endl;
    }
    return index;
}

Node* Kth_from_last_recursive(Node*head,int k,int &i){
    if(!head){
        return NULL;
    }
    Node*nd = Kth_from_last_recursive(head->next,k,i);
    i = i + 1;
    if(i == k){
        return head;
    }
    return nd;
}

Node*partition(Node*head, int part){
    Node*beforeStart = NULL;
    Node*beforeEnd = NULL;
    Node*afterStart = NULL;
    Node*afterEnd = NULL;
    Node*temp = head;
    if(!head){
        return NULL;
    }
    while(temp){
        if(temp->data < part){
            if(!beforeStart){
                beforeStart = temp;
                beforeEnd = beforeStart;
            }
            else{
                beforeEnd->next = temp;
                beforeEnd = temp;
            }
        }
        else{
            if(!afterStart){
                afterStart = temp;
                afterEnd = afterStart;
            }
            else{
                afterEnd->next = temp;
                afterEnd = temp;
            }
        }
        temp = temp->next;
    }
    if(!beforeStart){
        return afterStart;
    }
    beforeEnd->next = afterStart;
    afterEnd->next = NULL;
    return beforeStart;
}

bool checkPalindrome(Node*head){
    Node*slow = head;
    Node*fast = head;
    stack<int>stk;
    while(fast && fast->next){
        stk.push(slow->data);
        slow = slow->next;
        fast = fast->next->next;
    }
    if(!fast){ // if there are odd number of elements
        slow = slow->next;
    }
    while(slow){
        int cmp = stk.top();
        stk.pop();
        if(cmp != slow->data){
            return false;
        }
        slow = slow->next;
    }
    return true;
}
int pairSum(Node*head){
    deque<int>dq;
    Node*temp = head;
    while(temp){
        dq.push_back(temp->data);
        temp = temp->next;
    }
    int mx = 0;
    while(!dq.empty()){
        int s = dq.front();
        dq.pop_front();
        int e = dq.back();
        dq.pop_back();
        int sum = s + e;
        mx = max(mx,sum);
    }
    return mx;
}

// 2487. Remove Nodes From Linked List
// 5 2 13 3 8
Node* removeNodes(Node* head) {
    if(!head){
        return NULL;
    }
    if(!head->next){
        return head;
    }
    head = reverse(head);
    Node*temp = head;
    Node*slider = temp->next;
    while(slider){
        if(!slider->next){
            temp->next = NULL;
            return head;
        }
        if(slider->data > temp->data){
            temp->next = slider;
            temp = slider;
        }
        slider = slider->next;
    }
    return reverse(head);
}

// 2487. Remove Nodes From Linked List ENDS

// Reverse Linked List II

void reverseBetween(Node* head, int left, int right) {
    if(left == right){
        return;
    }
    if(!head || !head->next){
        return;
    }
    Node*leftBegin = head;
    Node*rightBegin = head;
    int i = 1;
    while(i<left){
        leftBegin = leftBegin->next;
        rightBegin = rightBegin->next;
        i++;
    }
    while(i<right){
        rightBegin = rightBegin->next;
        i++;
    }
    Node* afterRight = rightBegin->next;
    cout<<leftBegin->data<<endl;
    cout<<rightBegin->data<<endl;
    
}
// Reverse Linked List II ENDS

// LEETCODE SPIRAL MATRIX IV
vector<vector<int>> spiralMatrix(int m, int n, Node* head) {
    vector<vector<int>>result(m,vector<int>(n,-1));
    int row_start = 0;
    int col_start = 0;
    int col_end = n - 1;
    int row_end = m - 1;
    Node*temp = head;
    while(row_start<=row_end && temp){
        for(int i = col_start;i<=col_end;i++){
            result[row_start][i] = temp->data;
            temp = temp->next;
            if(!temp){
                return result;
            }
        }
        row_start++;
        for(int i = row_start;i<=row_end;i++){
            result[i][col_end] = temp->data;
            temp = temp->next;
            if(!temp){
                return result;
            }
        }
        col_end--;
        for(int i = col_end;i>=col_start;i--){
            result[row_end][i] = temp->data;
            temp = temp->next;
            if(!temp){
                return result;
            }
        }
        row_end--;
        for(int i = row_end;i>=row_start;i--){
            result[i][col_start] = temp->data;
            temp = temp->next;
            if(!temp){
                return result;
            }
        }
        col_start++;
    }
    return result;
}
// LEETCODE SPIRAL MATRIX IV ENDS

// 817. Linked List Components

bool isPresent(vector<int>&nums,int temp){
    for(int i = 0;i<nums.size();i++){
        if(temp == nums[i]){
            return true;
        }
    }
    return false;
}
int numComponents(Node* head, vector<int>& nums) {
    int finalCtr = 0;
    Node*temp = head;
    while(temp){
        bool flag = false;
        while(temp && isPresent(nums,temp->data)){
            flag = true;
            temp = temp->next;
        }
        if(flag){
            finalCtr++;
        }
        if(temp && temp->next){
            temp = temp->next;
        }
        else{
            break;
        }
    }
    return finalCtr;
}

// 817. Linked List Components ENDS
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
    cout << "press 10 for reversing the linked list " << endl;
    cout << "press 11 for finding the middle element of the linked list " << endl;
    cout << "press 12 for getting an list with unique elements " << endl;
    cout << "press 13 for getting the Kth number from the last " << endl;
    cout << "press 14 for partitioning a linked list about a number " << endl;
    cout << "press 15 for checking whether the linked list is a palindrome " << endl;
    cout << "press 16 for getting the maximum twin sum (length of linked list must be EVEN) " << endl;
    cout << "press 17 for getting the answer of Q 2487 LEETCODE " << endl;
    cout << "press 18 for reversing a part of the linked list "<<endl;
    cout << "press 19 for spiral matrix IV " << endl;
    cout << "press 20 for linked list components " << endl;
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
            head = reverse(head);
            cout<<"The reversed linked list is : "<<endl;
            print(head);
            break;
        case 11:
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
        case 12:
            head = removeDuplicates(head);
            cout<<"The linked list with the unique elements is : "<<endl;
            print(head);
            break;
        case 13:
            int k;
            cout<<"Enter the value of position from the last which you want to print"<<endl;
            cin>>k;
            cout<<Kth_from_last(head,k);
            break;
        case 14:
            int part;
            cout<<"Enter the partiton number you want to partition the linked list about"<<endl;
            cin>>part;
            head = partition(head,part);
            print(head);
            break;
        case 15:
            if(checkPalindrome(head)){
                cout<<"The linked list is a palindrome"<<endl;
            }
            else{
                cout<<"The linked list is not a palindrome"<<endl;
            }
            break;
        case 16:
            cout<<"The maximum twin sum value is : "<<pairSum(head)<<endl;
            break;
        case 17:
            // cout<<"2487. Remove Nodes From Linked List : "<<removeNodes(head)<<endl;
            head = removeNodes(head); // 5 2 13 3 8
            print(head);
            break;
        case 18:
            cout<<"Enter the beginning position"<<endl;
            cout<<"Enter the ending position"<<endl;
            int left;
            int right;
            cin>>left;
            cin>>right;
            // head = reverseBetween(head,left,right);
            reverseBetween(head,left,right);
            print(head);
            break;
        case 19:
        {
            cout<<"Enter the number of rows : "<<endl;
            int m;
            cin>>m;
            cout<<"Enter the number of columns : "<<endl;
            int n;
            cin>>n;
            cout<<"The spiral matrx is : "<<endl;
            vector<vector<int>>result = spiralMatrix(m,n,head);
            print(result);
            break;
        }
        case 20:
        {
            vector<int>nums = {0,3,1,4};
            int result = numComponents(head,nums);
            cout<<result<<endl;
            break;
        }
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