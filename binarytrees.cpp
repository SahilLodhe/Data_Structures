#include <bits/stdc++.h>
using namespace std;
class BTnode{
    public:
    int data;
    BTnode*left;
    BTnode*right;
    BTnode(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BTnode(){
        delete left;
        delete right;
    }
};

BTnode*take_Input_recursive(){// goes from root to the bottom most child of the tree
    int rootData;
    cout<<"Enter data"<<endl;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    BTnode*root = new BTnode(rootData);
    //BTnode*leftChild = take_Input_recursive();
    //BTnode*rightChild = take_Input_recursive();
    root->left = take_Input_recursive();//leftChild;
    root->right = take_Input_recursive();// rightChild;
    return root;
}
BTnode*take_Input_recursive1(){// goes from root to the bottom most child of the tree
    int rootData;
    cout<<"Enter data"<<endl;
    cin>>rootData;
    if(rootData==-1){
        return NULL;
    }
    BTnode*root = new BTnode(rootData);
    BTnode*leftChild = take_Input_recursive();
    BTnode*rightChild = take_Input_recursive();
    leftChild = take_Input_recursive();//leftChild;
    rightChild = take_Input_recursive();// rightChild;
    return root;
}
BTnode*take_Input_levelwise(){//uses a queue to store the level wise elements
    int rootData;
    cout<<"Enter data"<<endl;
    cin>>rootData;
    queue<BTnode*>q;
    BTnode*root = new BTnode(rootData);
    q.push(root);
    while(!q.empty()){//create,push,connect
        BTnode*f = q.front();
        q.pop();
        int leftChilddata;
        int rightChilddata;
        cout<<"Enter data for the left child of "<<f->data<<endl;
        cin>>leftChilddata;
        if(leftChilddata!=-1){
            BTnode*child = new BTnode(leftChilddata);
            q.push(child);
            f->left = child;
        }
        //else{
        //    root->left = NULL;
        //}
        cout<<"Enter data for the right child of "<<f->data<<endl;
        cin>>rightChilddata;
        if(rightChilddata!=-1){
            BTnode*child = new BTnode(rightChilddata);
            q.push(child);
            f->right = child;
        }
        //else{
        //    root->right = NULL;
        //}
    }
    return root;
}

void print_recursive(BTnode*root){
    if(root == NULL){//in case of binary tree, it is mandatory to write the base case ..... in generic tree, there were vectors, they acted as base cases because their size would be zero
        return;
    }
    cout<<root->data<<" -> "; //prints the nodes first
    if(root->left!=NULL){
        cout<<"Left : "<<root->left->data;
    }
    cout<<" ";
    if(root->right!=NULL){
        cout<<"Right : "<<root->right->data;
    }
    cout<<endl;
    print_recursive(root->left);
    print_recursive(root->right);
}

void print_level_order_traversal(BTnode*root){
    queue<BTnode*>q;//take a queue and print it
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        BTnode*f = q.front();
        q.pop();
        if(f == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<f->data<<" ";
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
}

int count_nodes(BTnode*root){//nodes are the number of elements
    if(root == NULL){
        return 0;
    }
    return count_nodes(root->left) + count_nodes(root->right) + 1;
}

void inorder(BTnode*root){
        if(root == NULL){
            return;
        }
        if(root->left)
        {inorder(root->left);}//left
        cout<<root->data<<" ";//data
        if(root->right)
        {inorder(root->right);}//right
}
void preordertraversal(BTnode*root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";//data
    if(root->left){
        preordertraversal(root->left);//left
    }
    if(root->right){
        preordertraversal(root->right);//right
    }
}
void postordertraversal(BTnode*root){
    if(root == NULL){
        return;
    }
    if(root->left){
        postordertraversal(root->left);//left
    }
    if(root->right){
        postordertraversal(root->right);//right
    }
    cout<<root->data<<" ";//data
}
bool find_node(BTnode*root,int data){
    if(root == NULL){
        return false;
    }
    if(root->data == data){
        return true;
    }
    return find_node(root->left,data) ||find_node(root->right,data);    
}
int min_value(BTnode*root){
    if(root == NULL){
        return INT_MAX;
    }
    int ans = root->data;
    int left_min = min_value(root->left);
    int right_min = min_value(root->right);
    return min(ans,min(left_min,right_min));
}
int min_value2(BTnode*root,int&ans){
    if(root == NULL){
        return INT_MAX;
    }
    ans = min(ans,root->data);
    min_value2(root->left,ans);
    min_value2(root->right,ans);
    return ans;
}
int max_value(BTnode*root){
    if(root == NULL){
        return INT_MIN;
    }
    int ans = root->data;
    int max_left = max_value(root->left);
    int max_right = max_value(root->right);
    return max(ans,max(max_left,max_right));
}
int max_value2(BTnode*root,int&ans){
    if(root == NULL){
        return 0;
    }
    ans = max(ans,root->data);
    max_value2(root->left,ans);
    max_value2(root->right,ans);
    return ans;
}

int count_leaf_nodes(BTnode*root){//nodes are the elements which do not have any children
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    return count_leaf_nodes(root->left) + count_leaf_nodes(root->right);
}
void count_leaf_nodes2(BTnode*root,int &ans){//here ans has to be equal to 0 for the function to calculate the correct number of nodes
    if(root  == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        ans++;
    }
    count_leaf_nodes2(root->left,ans);
    count_leaf_nodes2(root->right,ans);
}
int height_for_max_distance_between_two_nodes(BTnode*root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(height_for_max_distance_between_two_nodes(root->left),height_for_max_distance_between_two_nodes(root->right));
}
int max_distance_between_two_nodes(BTnode*root){
    if(root == NULL){
        return 0;
    }
    int option1 = height_for_max_distance_between_two_nodes(root->left) + height_for_max_distance_between_two_nodes(root->right);
    int option2 = max_distance_between_two_nodes(root->left);
    int option3 = max_distance_between_two_nodes(root->right);
    return max(option1,max(option2,option3));

}

bool getPath(BTnode*root,int key,vector<int>&ans){
    if(root == NULL){
        return false;
    }
    ans.push_back(root->data);
    if(root->data == key){
        return true;
    }
    //return getPath(root->left,key,ans) || getPath(root->right,key,ans);
    bool leftFound = getPath(root->left,key,ans);
    bool rightFound = getPath(root->right,key,ans);
    if(leftFound || rightFound){
        return true;
    }
    //if(getPath(root->left,key,ans) || getPath(root->right,key,ans)){      //WE CAN ALSO USE THE COMMENTED CODE!!
    //    return true;                                                      //BECAUSE WE NEED THE VALUES FROM THE LOWER BRANCHES OF THE TREE FOR GETING THE RESULT FOR THE ABOVE NODE'S FUNCTION....IN THIS CASE, WE CAN USE TWO SEPARATE BOOLS(LEFTFOUND AND RIGHTFOUND)
    //}
    ans.pop_back();
    return false;
}

//int left_most_value(BTnode*root){ //useful for finding the minimum element of the binary search tree
//    if(root == NULL){
//        return 0;
//    }
//    if(root->left==NULL){
//        return root->data;
//    }
//    left_most_value(root->left);
//}
//int right_most_value(BTnode*root){//useful for finding the maximum element of the binary search tree
//    if(root == NULL){
//        return 0;
//    }
//    if(root->right==NULL){
//        return root->data;
//    }
//    right_most_value(root->right);
//}
//bool helper_to_check_BST2(BTnode*root,long long minV = -10000000000, long long maxV = 10000000000){
//    if(root == NULL){
//        return true;
//    }
//    bool left = helper_to_check_BST2(root->left,minV,root->data);
//    bool left = helper_to_check_BST2(root->left,root->data,maxV);
//    if(left && right){
//        return true;
//    }
//    else{
//        return false;
//    }
//}
//bool check_BST2(BTnode*root){
//    return helper_to_check_BST2(root);
//}
//bool getPath(BTnode*root,int key,vector<int>&ans){
//    if(root == NULL){
//        return false;
//    }
//    if(root->left || root->right ){
//        ans.push_back(root->data);
//    }
//    if(root->data == key){
//        ans.push_back(root->data);
//        return true;
//    }
//    if((!root->left && !root->right) && root->data != key){
//        ans.pop_back();
//        return false;
//    }
//    if((!root->left || !root->right) && root->data == key){
//        ans.push_back(root->data);
//        return false;
//    }
//    return getPath(root->left,key,ans) || getPath(root->right,key,ans);
//    //ans.push_back(root->data);
//    //if(root == NULL){
//    //    return false;
//    //}
//    //if(root->data == key){
//    //    return true;
//    //}
//    //if(root->left == NULL && root->right == NULL && root->data!= key){
//    //    ans.pop_back();
//    //    return false;
//    //}
//    //if(root->left == NULL && root->right == NULL && root->data == key){
//    //    return true;
//    //}
//    //if(root->data == key){
//    //    return true;
//    //}
//    //return getPath(root->left,key,ans) || getPath(root->right,key,ans);
//}

//int max_distance(BTnode*root){
//    if(root == NULL){
//        return 0;
//    }
//    int option1 = max_distance(root->left) + max_distance(root->right);
//    return 1 + option1;
//}
//BTnode*create_pre_in_BT(vector<int>inOrder,vector<int>preOrder,int inS,int inE,int preS,int preE){
//    if(inS>inE){
//        return NULL;
//    }
//    int rootData = preOrder[preS];
//    //cin>>rootData;
//}
int main(){
    //BTnode*root = new BTnode(1);
    //BTnode*n1 = new BTnode(2);
    //BTnode*n2 = new BTnode(3);
    //BTnode*n3 = new BTnode(4);
    //BTnode*n4 = new BTnode(5);
    //root->left = n1;
    //root->right = n2;
    //root->right->left = n3;
    //root->right->right = n4;
    //BTnode*root = take_Input_recursive();
    BTnode*root = take_Input_levelwise();
    print_level_order_traversal(root);
    //cout<<"The number of nodes are : "<<count_nodes(root)<<endl;
    //cout<<"The inorder traversal for the binary tree is : ";
    //preordertraversal(root);
    //cout<<endl;
    //cout<<"searching for 3"<<endl;
    //if(find_node(root,3)){
    //    cout<<"found"<<endl;
    //}
    //else{
    //    cout<<"not found"<<endl;
    //}
    //cout<<"The minimum value of the element present in the binary tree is : "<<min_value(root)<<endl;
    //cout<<"The maximum value of the element present in the binary tree is : "<<max_value(root)<<endl;
    //cout<<"The number of leaf nodes present in the binary tree is : "<<count_leaf_nodes(root)<<endl;
    //int count = 0;
    //cout<<"The number of leaf nodes by the second method is : ";
    //count_leaf_nodes2(root,count);
    //cout<<count<<endl;
    //cout<<"The maximum distance between any two nodes of the tree is : "<<max_distance_between_two_nodes(root)<<endl;
    ////cout<<max_distance(root);
    vector<int>ans;
    int key = 9;
    //cout<<"The path for the binary tree (1 2 5 3 4 6 7 -1 -1 -1 -1 8 9 -1 -1 10 -1 -1 11 -1 -1 -1 -1) is : "<<endl;
    
    if(getPath(root,key,ans)){
        cout<<"The path for reaching the element "<<key<<"is : ";
        for(int i = 0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    }
    else{
        cout<<"The path does not exist because the element is not found"<<endl;
    }
    cout<<endl;
    //cout<<"The left most value of the tree is : "<<left_most_value(root)<<endl;
    //cout<<"The right most value of the tree is : "<<right_most_value(root)<<endl;
    return 0;
}
//1 2 5 3 4 6 7 -1 -1 -1 -1 8 9 -1 -1 10 -1 -1 11 -1 -1 -1 -1    -> Binary Tree input
//^                                                         ^