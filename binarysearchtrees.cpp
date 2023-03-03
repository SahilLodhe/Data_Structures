#include <bits/stdc++.h>
using namespace std;
//
//class BSTNode
//{
//    public:
//
//    int data;
//    BSTNode*root;
//    BSTNode *left;
//    BSTNode *right;
//    BSTNode(){
//        root = NULL;
//    }
//    BSTNode(int data)
//    {
//        this->data = data;
//        left = NULL;
//        right = NULL;
//    }
//    ~BSTNode(){
//        delete left;
//        delete right;
//    }
//    bool hasData(BSTNode*node, int data)
//    {
//        if (node == NULL)
//        {
//            return false;
//        }
//        if (node->data == data)
//        {
//            return true;
//        }
//
//        if (node->data > data)
//        {
//            return hasData(node->left, data);
//        }
//        else
//        {
//            return hasData(node->right, data);
//        }
//    }
//};
//
//
//
//
//BSTNode *make_BST(vector arr, int start, int end)
//{
//    //base case
//    if (start > end)
//    {
//        return NULL;
//    }
//    int mid = (start + end) / 2;
//    BSTNode *root = new BSTNode(arr[mid]);
//    root->left = make_BST(arr, start, mid - 1);
//    root->right = make_BST(arr, mid + 1, end);
//    return root;
//}
//BSTNode *sortedarray(vector &nums)
//{
//    int n = nums.size();
//    return make_BST(nums, 0, n - 1);
//}
//void bst_print(BSTNode *root)
//{
//    queue<BSTNode *> q;
//    q.push(root);
//    q.push(NULL);
//    while (!q.empty())
//    {
//        BSTNode *f = q.front();
//        q.pop();
//        if (f == NULL)
//        {
//            cout << endl;
//            if (!q.empty())
//            {
//                q.push(NULL);
//            }
//        }
//        else
//        {
//            cout << f->data << " ";
//            if (f->left)
//            {
//                q.push(f->left);
//            }
//            if (f->right)
//            {
//                q.push(f->right);
//            }
//        }
//    }
//}
//void print_recursive(BSTNode *root)
//{
//    if (root == NULL)
//    { //in case of binary tree, it is mandatory to write the base case ..... in generic tree, there were vectors, they acted as base cases because their size would be zero
//        return;
//    }
//    cout << root->data << " -> "; //prints the nodes first
//    if (root->left != NULL)
//    {
//        cout << "Left : " << root->left->data;
//    }
//    cout << " ";
//    if (root->right != NULL)
//    {
//        cout << "Right : " << root->right->data;
//    }
//    cout << endl;
//    print_recursive(root->left);
//    print_recursive(root->right);
//}

//void  {
//    queue<BST*>q;//take a queue and print it
//    q.push(root);
//    q.push(NULL);
//    while(!q.empty()){
//        BST*f = q.front();
//        q.pop();
//        if(f == NULL){
//            cout<<endl;
//            if(!q.empty()){
//                q.push(NULL);
//            }
//        }
//        else{
//            cout<<f->data<<" ";
//            if(f->left){
//                q.push(f->left);
//            }
//            if(f->right){
//                q.push(f->right);
//            }
//        }
//    }
//}

//#include <iostream>
//using namespace std;
//
//template <typename T>
//class BST
//{
//public:
//    T data;
//    BST *left;
//    BST *right;
//
//    BST(T data)
//    {
//        this->data = data;
//        left = NULL;
//        right = NULL;
//    }
//    ~BST()
//    {
//        delete left;
//        delete right;
//    }
//};

#include <iostream>
using namespace std;

template <typename T>
class BTNode
{
public:
    T data;
    BTNode *left;
    BTNode *right;

    BTNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BTNode()
    {
        delete left;
        delete right;
    }
};

class Pair
{
public:
    BTNode<int> *head;
    BTNode<int> *tail;
};

class BST
{
    BTNode<int> *root;

    void printTree(BTNode<int> *root)
    {
        if (root == NULL)
        { /// base case
            return;
        }

        //cout << root->data << ": ";
        //if (root->left != NULL)
        //{
        //    cout << "L" << root->left->data;
        //}
//
        //if (root->right != NULL)
        //{
        //    cout << "R" << root->right->data;
        //}
        //cout << endl;

        printTree(root->left);
        cout << root->data << ": ";
        printTree(root->right);
    }
    bool hasData(BTNode<int> *node, int data)
    {
        if (node == NULL)
        {
            return false;
        }
        if (node->data == data)
        {
            return true;
        }

        if (node->data > data)
        {
            return hasData(node->left, data);
        }
        else
        {
            return hasData(node->right, data);
        }
    }
    
    BTNode<int> *insert(BTNode<int> *node, int data)
    {
        if (node == NULL)
        {
            BTNode<int> *n = new BTNode<int>(data);
            return n;
        }
        if (data < node->data)
        {
            node->left = insert(node->left, data);
        }
        else
        {
            node->right = insert(node->right, data);
        }
        return node;
    }

    BTNode<int> *deleteData(BTNode<int> *node, int data)
    {
        if (node == NULL)
        {
            return NULL;
        }
        if (data > node->data)
        {
            node->right = deleteData(node->right, data);
        }
        else if (data < node->data)
        {
            node->left = deleteData(node->left, data);
        }
        else
        {
            if (node->left == NULL && node->right == NULL)
            {
                delete node;
                return NULL;
            }
            else if (node->right == NULL)
            {
                BTNode<int> *temp = node->left;
                node->left = NULL;
                delete node;
                return temp;
            }
            else if (node->left == NULL)
            {
                BTNode<int> *temp = node->right;
                node->right = NULL;
                delete node;
                return temp;
            }
            else
            {
                BTNode<int> *minNode = node->right;
                while (minNode->left != NULL)
                {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                node->data = rightMin;
                node->right = deleteData(node->right, rightMin);
            }
        }
        return node;
    }

    Pair convert_to_LL(BTNode<int> *root)
    {
        if (root->left == NULL && root->right == NULL)
        {
            Pair p;
            p.head = root;
            p.tail = root;
            return p;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            Pair LeftLL = convert_to_LL(root->left);
            LeftLL.tail->right = root;
            Pair ans;
            ans.head = LeftLL.head;
            ans.tail = root;
            return ans;
        }
        if (root->left == NULL && root->right != NULL)
        {
            Pair RightLL = convert_to_LL(root->right);
            root->right = RightLL.head;
            Pair ans;
            ans.head = root;
            ans.tail = RightLL.tail;
            return ans;
        }
        else
        {
            Pair LeftLL = convert_to_LL(root->left);
            Pair RightLL = convert_to_LL(root->right);
            Pair ans;
            LeftLL.tail->right = root;
            root->right = RightLL.head;
            ans.head = LeftLL.head;
            ans.tail = RightLL.tail;
            return ans;
        }
    }

public:
    BST()
    {
        root = NULL;
    }
    ~BST()
    {
        delete root;
    }

    void deleteData(int data)
    {
        root = deleteData(root, data);
    }
    void insert(int data)
    {
        root = insert(root, data);
    }
    bool hasData(int data)
    {
        return hasData(root, data);
    }
    void print()
    {
        printTree(root);
    }
    BTNode<int> *convert_to_LL()
    {
        Pair p = convert_to_LL(root);
        BTNode<int>*tmp = p.head;
        while(tmp!=NULL){
            tmp->left = NULL;
            tmp = tmp->right;
        }
        return p.head;
    }
};

int main()
{
    BST b;
    b.insert(10);
    b.insert(5);
    b.insert(20);
    b.insert(7);
    b.insert(3);
    b.insert(15);
//
    b.print();
//
    //b.deleteData(10);
    //cout << endl;
//
    //b.print();
    //b.deleteData(5);
    //cout << endl;
//
    //b.print();
    //b.deleteData(100);
    //cout << endl;
    //b.print();
//
    //cout << "deleting 7" << endl;
    //b.deleteData(7);
    //cout << endl;
    //b.print();
//
    //cout << "deleting 20" << endl;
    //b.deleteData(20);
    //cout << endl;
    //b.print();
    BTNode<int>*head = b.convert_to_LL();
    BTNode<int>*tmp = head;
    while(tmp!=NULL){
        cout<<tmp->data<<"->";
        tmp = tmp->right;
    }
    cout<<"NULL";
    return 0;
}

//int main()
//{
//    int n = 11;
//    vector arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    BSTNode *root = sortedarray(arr);
//    bst_print(root);
//    return 0;
//}