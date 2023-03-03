#include <bits/stdc++.h>
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
    b.print();
    BTNode<int>*head = b.convert_to_LL();
    BTNode<int>*tmp = head;
    while(tmp!=NULL){
        cout<<tmp->data<<"->";
        tmp = tmp->right;
    }
    cout<<"NULL";
    return 0;
}
