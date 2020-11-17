// LEETCODE PROBLEM
// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
#include<bits/stdc++.h>
using namespace std;

 typedef struct Node{
     Node* left;
     Node* right;
     int data;
     Node(int x){
        data = x;
        left = right = NULL;
    }
}Node;

vector< vector<int> >  zigZagOrderTraversal(Node* tree){
    vector< vector<int> >  ans;
    if(!tree){
        return ans;
    }
    stack <Node*> st1;
    stack <Node*> st2;  
    vector<int> temp;
    ans.push_back(temp);
    st1.push(tree);
    cout<<tree->data<<endl;
    bool flag = true;
    while(!st1.empty() || !st2.empty()){
        vector<int> row;
        flag = !flag;
        if(!flag){

            while(!st1.empty()){
                Node* node_prev = st1.top();
                st1.pop();
                
                if(node_prev->right){
                    row.push_back(node_prev->right->data);
                    st2.push(node_prev->right);
                }
                if(node_prev->left){
                    row.push_back(node_prev->left->data);
                    st2.push(node_prev->left);
                }
            }

        }
        else{
            while(!st2.empty()){
                Node* node_prev = st2.top();
                st2.pop();
                // cout<<node_prev->data<<" ";
                if(node_prev->left){
                    row.push_back(node_prev->left->data);
                    st1.push(node_prev->left);
                }
                if(node_prev->right){
                    row.push_back(node_prev->right->data);
                    st1.push(node_prev->right);
                }
            }

        }
        if(row.size())
            ans.push_back(row);
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> vct(n);

    for(int i = 0;i<n;i++){
        cin>>vct[i];
    }
    queue<Node*> queue;

    Node *tree = new Node(vct[0]);
    queue.push(tree);
    bool flag = false;

    for(int i = 1;i<n;i+=2){
        Node* prev_node = queue.front();
        Node* left = new Node(vct[i]);
        prev_node->left = left;
        queue.push(left);
        if(i+1<=n-1){
            Node* right = new Node(vct[i+1]);
            prev_node->right = right;
            queue.push(right);
        }
        queue.pop();
    }

    cout<<"Zig Zag Order Traversal: \n";
    vector< vector<int> > data = zigZagOrderTraversal(tree);
    for(int i = 0;i<data.size();i++){
        for(int j = 0;j<data[i].size();j++){
            cout<<data[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}