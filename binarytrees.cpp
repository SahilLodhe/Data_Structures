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
    if(root->data == -1){
        return;
    }
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

//int count_nodes(BTnode*root){
//    if(root == NULL){
//        return 0;
//    }
//    else{
//        return 1;
//    }
//    int a = count_nodes(root->left);
//    int b = count_nodes(root->right);
//    return a + b;
//}
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

// bool getPath(BTnode*root,vector<int>&path,int key){
    
// }
int minDepth(BTnode* root) {
    if(!root){
        return 0;
    }
    if(!root->left){
        return 1 + minDepth(root->right);
    }
    if(!root->right){
        return 1 + minDepth(root->left);
    }
    return 1 + min(minDepth(root->left),minDepth(root->right));
}
int maxDepth(BTnode* root) {
    if(!root){
        return 0;
    }
    if(!root->left){
        return 1 + maxDepth(root->right);
    }
    if(!root->right){
        return 1 + maxDepth(root->left);
    }
    return 1 + max(maxDepth(root->left),maxDepth(root->right));
}
// map<BTnode*,int> storeLevel;
// void printSpecificLevel(BTnode*root,int depth){
//     if(!root || depth < 1){
//         return;
//     }
//     if(depth == 1){
//         storeLevel[root] = root->data;
//     }
//    printSpecificLevel(root->left,depth - 1);
//    printSpecificLevel(root->right,depth - 1);
//     // if(level == 1){
//     //     BTnode*temp = new BTnode
//     // }
//     // return root;
// }
// BTnode* helper(BTnode*root,int depth,int curr_lvl,int val){
//     if(!root || depth < 1){
//         return NULL;
//     }
//     if(curr_lvl = depth - 1){
//         // cout<<root->data<<" ";
//         storeLevel[root] = root->data;
//         return root;
//     }
//     root->left = helper(root->left,depth,curr_lvl + 1,val);
//     root->right = helper(root->right,depth,curr_lvl + 1,val);
//     return root;
// }
// BTnode* addOneRow(BTnode* root, int val, int depth) {
//     if(!root){
//         return NULL;
//     }
//     if(depth == 1){
//         BTnode*temp = new BTnode(val);
//         temp->left = root;
//         // temp->right = root;
//         return temp;
//     }
//     int curr_lvl = 1;
//     root = helper(root,depth,curr_lvl,val);
//     return root;

// }

// LEETCODE QUESTION ADDONEROW
map<BTnode*,bool>storeLevel;
void markAll(BTnode*root,int level,int depth){
    if(!root){
        return;
    }
    if(level == depth - 1){
        storeLevel[root] = true;
        return;
    }
    
    markAll(root->left,level + 1,depth);
    markAll(root->right,level + 1,depth);
}
BTnode* helper(BTnode*root,int val){
    if(!root){
        return NULL;
    }
    if(storeLevel.find(root)!=storeLevel.end()){
        // cout<<root->data<<" ";
        BTnode*templeft = new BTnode(val);
        BTnode*tempright = new BTnode(val);
        templeft->left = root->left;
        tempright->right = root->right;
        root->left = templeft;
        root->right = tempright;
    }
    root->left = helper(root->left,val);
    root->right = helper(root->right,val);
    return root;
}
BTnode*addOneRow(BTnode*root,int val,int depth){
    if(!root){
        return NULL;
    }
    if(depth == 1){
        BTnode*temp  = new BTnode(val);
        temp->left = root;
        return temp;
    }
    int level = 1;
    markAll(root,level,depth);
    root = helper(root,val);
    return root;
}
// LEETCODE QUESTION ADDONEROW ENDS

// LEETCODE QUESTION Binary Tree Zigzag Level Order Traversal
vector<vector<int>> zigzagLevelOrder(BTnode* root){
    vector<vector<int>>result;
    if(!root){
        return result;
    }
    queue<BTnode*>q;
    vector<int>temp;
    q.push(root);
    q.push(NULL);
    // temp.push_back(root->data);
    // result.push_back(temp);
    bool flag = false;
    temp.clear();
    while(!q.empty()){
        BTnode*f = q.front();
        q.pop();
        if(!f){
            if(flag){
                reverse(temp.begin(),temp.end());
                flag = false;
            }
            else{
                flag = true;
            }
            result.push_back(temp);
            temp.clear();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            temp.push_back(f->data);
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return result;
}
// LEETCODE QUESTION Binary Tree Zigzag Level Order Traversal ENDS

// LEETCODE QUESTION find the number with the highest frequency
unordered_map<int,int>mp;
void helper1(BTnode*root){
    if(!root){
        return;
    }
    if(root->data != -1){
        mp[root->data]++;
    }
    helper1(root->left);
    helper1(root->right);
}
vector<int> findMode(BTnode* root) {
    vector<int>result;
    helper1(root);
    int mx = 0;
    int final_ans = 0;
    priority_queue <int, vector<int>, greater<int>> gq;
    for(auto i : mp){
        gq.push(i.second);
    }
    // mp.erase(mp[final_ans]);
    int a = gq.top();
    if(gq.size() >= 1){
        gq.pop();
    }
    else{
        result.push_back(a);
        return result;
    }
    while(a == gq.top() && !gq.empty()){
        result.push_back(gq.top());
        gq.pop();
    }
    return result;
}
// LEETCODE QUESTION find the number with the highest frequency END

// LEETCODE QUESTION Binary Tree Right Side View
unordered_map<int,int>storeFirstLevel;
void helper2(BTnode*root,vector<int>&vec,int depth){
    if(!root){
        return;
    }
    if(depth < 1){
        return;
    }
    if(storeFirstLevel.find(depth)==storeFirstLevel.end()){
        storeFirstLevel[depth] = root->data;
        vec.push_back(storeFirstLevel[depth]);
    }
    helper2(root->right,vec,depth + 1);
    helper2(root->left,vec,depth + 1);
    
    // vec.push_back(root->data);
    // if(root->right){
    //     helper2(root->right,vec);
    // }
    // else if(root->left){
    //     helper2(root->left,vec);
    // }
    
}
vector<int> rightSideView(BTnode* root) {
    vector<int>vec;
    if(!root){
        return vec;
    }
    // vec.push_back(root->data);
    helper2(root,vec,1);
    return vec;
}
// LEETCODE QUESTION Binary Tree Right Side View END

// LEETCODE QUESTION Balanced Binary Tree

int helper3(BTnode*root){
    if(!root){
        return 0;   
    }
    int leftSubTree = helper3(root->left);
    if(leftSubTree == -1){
        return -1;
    }
    int rightSubTree = helper3(root->right);
    if(rightSubTree == -1){
        return -1;
    }
    if(abs(leftSubTree - rightSubTree) > 1){
        return -1;
    }
    return max(leftSubTree,rightSubTree) + 1;

}
bool isBalanced(BTnode* root) {
    return helper3(root) != -1;
    // isBalanced(root->left);
    // cout<<maxDepth(root)<<endl;
    // isBalanced(root->right);
    
}
// LEETCODE QUESTION Balanced Binary Tree ENDS

// LEETCODE QUESTION Deepest Leaves Sum
void helper4(BTnode*root,int curr_depth,int depth,int& sum){
    if(!root){
        return;
    }
    if(curr_depth == depth){
        sum += root->data;
    }
    helper4(root->left,curr_depth + 1,depth,sum);
    helper4(root->right,curr_depth + 1,depth,sum);
}
int deepestLeavesSum(BTnode* root) {
    int maxD = maxDepth(root);
    int sum = 0;
    helper4(root,1,maxD,sum);
    return sum;
}

// LEETCODE QUESTION Deepest Leaves Sum ENDS

// LEETCODE QUESTION Sum of Nodes with Even-Valued Grandparent
int sum_1315;
void getsGrandchildren(BTnode*root,int curr_depth){
    if(!root){
        return;
    }
    if(curr_depth == 3){
        sum_1315 += root->data;
    }
    getsGrandchildren(root->left,curr_depth + 1);
    getsGrandchildren(root->right,curr_depth + 1);
}
void helper5(BTnode*root){
    if(!root){
        return;
    }
    if(root->data%2 == 0){
        getsGrandchildren(root,1);
    }
    helper5(root->left);
    helper5(root->right);
}
int sumEvenGrandparent(BTnode* root) {
    sum_1315 = 0;
    helper5(root);
    return sum_1315;
}

// LEETCODE QUESTION Sum of Nodes with Even-Valued Grandparent ENDS

// Binary Search Tree to Greater Sum Tree

void getSum(BTnode*root,int& sum){
    if(!root){
        return;
    }
    sum += root->data;
    getSum(root->left,sum);
    getSum(root->right,sum);
}
BTnode*convertTree(BTnode*root,int& summation){
    if(!root){
        return NULL;
    }
    root->left = convertTree(root->left,summation);
    int oldRootData = root->data;
    root->data = summation;
    summation -= oldRootData;
    root->right = convertTree(root->right,summation);
    return root;
}
BTnode* bstToGst(BTnode* root) {
    int sumGST = 0;
    getSum(root,sumGST);
    // return sumGST;
    root = convertTree(root,sumGST);
    return root;
}

// Binary Search Tree to Greater Sum Tree ENDS

// Binary Tree Level Order Traversal II

vector<vector<int>> levelOrderBottom(BTnode* root) {
    vector<vector<int>>result;
    if(!root){
        return result;
    }
    vector<int>temp;
    queue<BTnode*>q;
    q.push(root);
    q.push(NULL);
    temp.clear();
    while(!q.empty()){
        BTnode*f = q.front();
        q.pop();
        if(!f){
            result.push_back(temp);
            temp.clear();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            temp.push_back(f->data);
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    reverse(result.begin(),result.end());
    return result;
}
void print(vector<vector<int>> result){
    for(int i = 0;i<result.size();i++){
        for(int j = 0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}
void print(vector<int>result){
    for(auto i : result){
        cout<<i<<" ";
    }
}
// Binary Tree Level Order Traversal II ENDS

// Most Frequent Subtree Sum
unordered_map<int,int>q6;
int getSum6(BTnode*root){
    if(!root){
        return 0;
    }
    return root->data + getSum6(root->left) + getSum6(root->right);
}
void helper6(BTnode*root){
    if(!root){
        return;
    }
    // int sum = getSum6(root);
    q6[getSum6(root)]++;
    helper6(root->left);
    helper6(root->right);
}
void getAllElements(BTnode*root,vector<int>&result){
    if(!root){
        return;
    }
    result.push_back(root->data);
    getAllElements(root->left,result);
    getAllElements(root->right,result);
}
vector<int> findFrequentTreeSum(BTnode* root) {
    vector<int>result; 
    unordered_map<int,int>q6;
    helper6(root);
    int mx = 0;
    for(auto i : q6){
        mx = max(mx,i.second);
    }
    int counter = 0;
    int final1 = 0;
    for(auto i : q6){
        if(i.second == mx){
            counter++;
        }
        if(counter > 1){
            getAllElements(root,result);
            return result;
        }
    }
    if(counter <= 1){
        for(auto i : q6){
            if(i.second == mx){
                result.push_back(i.first);
                return result;
            }
        }
    }
    return result;
}

// Most Frequent Subtree Sum ENDS

//4 1 6 0 2 5 7 -1 -1 -1 3 -1 -1 -1 8 -1 -1 -1 -1
// LEETCODE QUESTION Convert BST to Greater Tree

BTnode*helper7(BTnode*root,int& sumGST7){
    if(!root){
        return NULL;
    }
    root->left = helper7(root->left,sumGST7);
    int oldRootData = root->data;
    root->data = sumGST7;
    sumGST7 -= oldRootData;
    root->right = helper7(root->right,sumGST7);
    return root;
}
BTnode* convertBST(BTnode* root) {
    int sumGST7;
    getSum(root,sumGST7);
    root = helper7(root,sumGST7);

}

// LEETCODE QUESTION Convert BST to Greater Tree ENDS

// LEETCODE find largest value in each row

vector<int> largestValues(BTnode* root) {
    vector<int>result;
    queue<BTnode*>q;
    q.push(root);
    q.push(NULL);
    int mx = INT_MIN;
    while(!q.empty()){
        BTnode*f = q.front();
        q.pop();
        if(f){
            mx = max(mx,f->data);
        }
        if(!f){
            result.push_back(mx);
            mx = INT_MIN;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            if(f->left){
                q.push(f->left);
            }
            if(f->right){
                q.push(f->right);
            }
        }
    }
    return result;
}
// void print(vector<int>vec){
//     for(auto i : vec){
//         cout<<i<<" ";
//     }
//     cout<<endl;
// }
// LEETCODE find largest value in each row ends
void solve(BTnode*root,int targetSum,vector<vector<int>>&result,vector<int>&path,int currSum){
    if(!root){
        return;
    }
    path.push_back(root->data);
    currSum = root->data + currSum;
    if(!root->left && !root->right){
        if(currSum == targetSum){
            result.push_back(path);
        }
    }
    solve(root->left,targetSum,result,path,currSum);
    solve(root->right,targetSum,result,path,currSum);
    path.pop_back();
    // currSum = root->data - currSum;
}
vector<vector<int>>pathSum(BTnode*root,int targetSum){
    vector<vector<int>>result;
    vector<int>temp;
    int currSum = 0;
    solve(root,targetSum,result,temp,currSum);
    return result;
}
int main(){
    BTnode*root = take_Input_levelwise();
    print_level_order_traversal(root);
    // print_level_order_traversal(root);
    cout<<endl;
    cout<<endl;
    cout<<endl;
    // vector<int>vec = largestValues(root);
    vector<vector<int>>result;
    int targetSum = 22;
    result = pathSum(root,targetSum);
    print(result);
    // print(findFrequentTreeSum(root));
    // cout<<getSum6(root)<<endl;
    // vector<vector<int>> result = levelOrderBottom(root);
    // print(result);
    // root = bstToGst(root);
    // cout<<endl;
    // cout<<endl;
    // cout<<endl;
    // print_level_order_traversal(root);
    // cout<<sumEvenGrandparent(root)<<endl;
    // cout<<deepestLeavesSum(root)<<endl;
    // vector<int>result = rightSideView(root);
    //     for(auto i : result){
    //     cout<<i<<" ";
    // }
    // if(isBalanced(root)){
    //     cout<<"Tree is balanced"<<endl;
    // }
    // else{
    //     cout<<"Tree isn't balanced"<<endl;
    // }
    // cout<<maxDepth(root->left);
    // vector<int>result = findMode(root);
    // for(auto i : mp){
    //     cout<<i.first<<i.second<<" ";
    // }
    // vector<vector<int>>result;
    // result = zigzagLevelOrder(root);
    // for(int i = 0;i<result.size();i++){
    //     for(int j = 0;j<result[i].size();j++){
    //         cout<<result[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // cout<<endl;
    // // print_level_order_traversal(root);
    // cout<<endl;
    // // printSpecificLevel(root,1);
    // root = addOneRow(root,1,3);
    // cout<<endl;
    // cout<<endl;
    // cout<<endl;
    
    // // printSpecificLevel(root,4);
    // for(auto i : storeLevel){
    //     cout<<i.first->data<<" ";
    // }
    // cout<<endl;
    // cout<<endl;
    // cout<<endl;
    // print_level_order_traversal(root);
    // cout<<minDepth(root);
    // cout<<max_distance_between_two_nodes(root);
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
    // vector<int>ans;
    // int key = 9;
    //cout<<"The path for the binary tree (1 2 5 3 4 6 7 -1 -1 -1 -1 8 9 -1 -1 10 -1 -1 11 -1 -1 -1 -1) is : "<<endl;
    
    // if(getPath(root,key,ans)){
    //     cout<<"The path for reaching the element "<<key<<"is : ";
    //     for(int i = 0;i<ans.size();i++){
    //         cout<<ans[i]<<" ";
    //     }
    // }
    // else{
    //     cout<<"The path does not exist because the element is not found"<<endl;
    // }
    // cout<<endl;
    //cout<<"The left most value of the tree is : "<<left_most_value(root)<<endl;
    //cout<<"The right most value of the tree is : "<<right_most_value(root)<<endl;
    // cout<<"The number of nodes are : "<<count_nodes(root);
    return 0;
}
//1 2 5 3 4 6 7 -1 -1 -1 -1 8 9 -1 -1 10 -1 -1 11 -1 -1 -1 -1    -> Binary Tree input
//^                                                         ^