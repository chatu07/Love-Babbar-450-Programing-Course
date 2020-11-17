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
int max(int a ,int b){
    if(a>b)
        return a;
    return b;
}
int Height(Node* tree){
    if(!tree){
        return 0;
    }
    return 1+max(Height(tree->left) , Height(tree->right));
}


bool isBalanced(Node *tree){
    if(!tree)
        return tree;
    
    if(abs(1+Height(tree->left) - 1+Height(tree->right)) >1){
        return false;
    }
    return true;
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

    if(isBalanced(tree)){
        cout<<"Balanced";
    }
    else{
        cout<<"Not Balanced";
    }
    return 0;
}