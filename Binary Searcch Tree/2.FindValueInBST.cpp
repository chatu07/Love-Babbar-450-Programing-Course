#include<bits/stdc++.h>
using namespace std;

typedef struct Node{
    Node* left = NULL;
    int data;
    Node* right = NULL;
    Node(int val){
        data = val;
    }
}Node;

bool findElement(Node* root,int value){
    bool elem = false;
    while(root){
        if(value == root->data){
            return true;
        }
        else if(value >=root->data){
            
        }
    }
    return false;
}
void insertNode(Node* root,int value){
    Node* node_Value=root;
    Node* prev_node;
    int flag = 1;
    // cout<<"Inside InsertNode"<<endl;
    while(node_Value!=NULL){
            // cout<<"Node Value: "<<node_Value->data<<endl;
        if(value>=node_Value->data){
            // cout<<"Greater Value"<<endl;
            prev_node = node_Value;
            node_Value = node_Value->right;
        }
        else{
            // cout<<"Lesser Value"<<endl;
            prev_node = node_Value;
            node_Value = node_Value->left;
        }
    }
    if(value>=prev_node->data){
        Node* newNode = new Node(value);
        prev_node->right = newNode;
    }
    else{
        Node* newNode = new Node(value);
        prev_node->left = newNode;
    }
    return;
}

void inorderTraversal(Node* root){
    if(root){
        inorderTraversal(root->left);
        cout<<root->data<<" ";
        inorderTraversal(root->right);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> vct(n);
    for(int i = 0;i<n;i++){
        cin>>vct[i];
    }

    Node *root = new Node(vct[0]);
    Node *ptr;
    for(int i = 1;i<n;i++){
        insertNode(root,vct[i]);
    }
    cout<<"Inorder Traversal: "<<endl;
    inorderTraversal(root);
    return 0;
}
