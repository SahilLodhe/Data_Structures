#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    vector<TreeNode *> children;
    TreeNode(int data)
    {
        this->data = data;
    }
    ~TreeNode(){
        for(int i = 0;i<children.size();i++){
            delete children[i];
        }
    }
};
void print(TreeNode *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << endl;
    }
}
void printTree(TreeNode *root)
{
    cout << root->data << ": ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << " ";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
    cout << "end" << endl;
    cout << endl;
}

TreeNode *takeInput()
{
    cout << "Enter data" << endl;
    int rootData;
    cin >> rootData;
    TreeNode *root = new TreeNode(rootData);//you have to create a pointer object (treenode*) for creating a new object dynamically
    //how many children are there for the node
    cout << "Enter number of children of " << rootData << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode *child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

TreeNode *takeInput_Levelwise()
{                 //create,push,connect
    int rootData; //iterative method
    cout << "Enter the data" << endl;
    cin >> rootData;
    TreeNode *root = new TreeNode(rootData);
    queue<TreeNode *> q;
    q.push(root);
    //cout<<"How many children are there of root?"<<endl;
    //int n;
    //cin>>n;
    while (!q.empty())
    {
        TreeNode *f = q.front();
        q.pop();
        cout << "Enter the number of children of " << f->data << endl;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int childData;
            cout << "Enter the data for the " << i << "th child of " << f->data << endl;
            cin >> childData;
            TreeNode *child = new TreeNode(childData);
            q.push(child);
            f->children.push_back(child);
        }
    }
    return root;
}
void print_Levelwise(TreeNode *root)
{
    //cout<<root->data<<endl;
    queue<TreeNode *> q;
    q.push(root);
    cout << root->data << ": " << endl;
    while (!q.empty())
    {
        TreeNode *f = q.front();
        //cout<<f->data<<": "<<endl;
        q.pop();
        for (int i = 0; i < f->children.size(); i++)
        {
            cout << f->children[i]->data << " ";
        }
        cout << endl;
        for (int i = 0; i < f->children.size(); i++)
        {
            q.push(f->children[i]);
        }
    }
}
int countNodes(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += countNodes(root->children[i]);
    }
    return ans;
}
int height(TreeNode *root)
{
    int mx = 0; ///maximum height
    if (root == NULL)
    { //edge case
        return 0;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        //int smallheight = height(root->children[i]);
        //if(smallheight>mx){
        //    max = smallheight;
        //}
        mx = max(mx, height(root->children[i]));
    }
    return mx + 1;
}

void printNodesAtLevel(TreeNode *root, int k)
{
    if (k == 0)
    { //edge case
        cout << root->data << " ";
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    { //recursive case
        printNodesAtLevel(root->children[i], k - 1);
    }
}
int countLeafNodes(TreeNode *root)
{
    //int ans = 0;
    ////edge case
    if(root == NULL){
        return 0;
    }
    //for(int i = 0;i<root->children.size();i++){
    //    int smallans = countLeafNodes(root->children[i]);
    //    if(root->children.size() == 0)
    //}
    if(root->children.size() == 0){
        return 1;
    }
    int ans = 0;
    for(int i = 0;i<root->children.size();i++){
        ans += countLeafNodes(root->children[i]);
    }
    return ans;
}
void countLeafNodes2(TreeNode *root,int ans)
{
    //int ans = 0;
    ////edge case
    
    //for(int i = 0;i<root->children.size();i++){
    //    int smallans = countLeafNodes(root->children[i]);
    //    if(root->children.size() == 0)
    //}
    if(root->children.size() == 0){
        ans++;
        return;
    }
    for(int i = 0;i<root->children.size();i++){
        countLeafNodes2(root->children[i],ans);
    }
}
void preordertraversal(TreeNode*root){
    cout<<root->data<<" ";
    for(int i = 0;i<root->children.size();i++){ //VVVVIP
        preordertraversal(root->children[i]);
    }
}
void postordertraversal(TreeNode*root){
    for(int i = 0;i<root->children.size();i++){//VVVVIP
        postordertraversal(root);
    }
    cout<<root->data<<" ";
}
void deleteTree(TreeNode*root){
    if(root == NULL){
        return;
    }
    for(int i = 0;i<root->children.size();i++){ //postorder traversal concept
        deleteTree(root->children[i]);
    }
    delete root;
}

bool getPath(TreeNode*root,vector<int>&path,int key){
    if(!root){
        return NULL;
    }
    path.push_back(root->data);
    if(root->data == key){
        return true;
    }
    
}
int main()
{
    //TreeNode *root = new TreeNode(0);
    //TreeNode *n1 = new TreeNode(1);
    //TreeNode *n2 = new TreeNode(2);
    //TreeNode *n3 = new TreeNode(3);
    //TreeNode *n4 = new TreeNode(4);
    //TreeNode *n5 = new TreeNode(5);
    //TreeNode *n6 = new TreeNode(6);
    //TreeNode *n7 = new TreeNode(7);
    //TreeNode *n8 = new TreeNode(8);
    //TreeNode *n9 = new TreeNode(9);
    //TreeNode *n10 = new TreeNode(10);
    //TreeNode *n11 = new TreeNode(11);
    //TreeNode *n12 = new TreeNode(12);
    //TreeNode *m1 = new TreeNode(1);
    //root->children.push_back(n1);
    //root->children.push_back(n2);
    //root->children.push_back(n3);
    //root->children.push_back(n4);
    //root->children.push_back(n5);
    //root->children.push_back(n6);
    //root->children.push_back(n7);
    //root->children.push_back(n8);
    //root->children.push_back(n9);
    //root->children.push_back(n10);
    //root->children.push_back(n11);
    //root->children.push_back(n12);
    //root->children[0]->children.push_back(m1);
    //for (int i = 0; i < root->children.size(); i++)
    //{
    //    cout << root->children[i]->data << endl;
    //}
    //cout << endl;
    //cout << root->children[0]->children[0]->data;
    //cout << root->data << endl;
    //cout << endl;
    //print(root);
    //cout << endl;
    //cout << root->children[0]->children[0]->data;
    TreeNode *root = takeInput_Levelwise();
    // print_Levelwise(root);
    // cout << endl;
    //cout<<countNodes(root);
    // cout << height(root);
    // cout << endl;
    // printNodesAtLevel(root, 1);
    //int total_leaf_nodes = 0;
    // cout<<endl;
    // cout<<countLeafNodes(root);
    //countLeafNodes2(root,total_leaf_nodes);
    //cout<<"total leaf nodes is : "<<total_leaf_nodes<<endl;
    // cout<<endl;
    // preordertraversal(root);
    return 0;
}