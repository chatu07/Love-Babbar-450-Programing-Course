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

void preorderTraversal(Node* root){
    if(root){
        cout<<root->data<<" ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int main(){
    string str;
    cin>>str;

    //CODE FOR CONVERTING STRING TO BINARY TREE

    stack<Node*> brackets;
    int n = str.length();

    Node* root = new Node(str[0]-'0');
    brackets.push(root);

    for(int i = 1;i<n;i++){
        if(str[i] == '('){
            if(!brackets.top()->left){
                Node* newnode = new Node(str[i+1]-'0');
                brackets.top()->left = newnode;
                brackets.push(newnode);
                i=i+1;
            }
            else if(!brackets.top()->right){
                Node* newnode = new Node(str[i+1]-'0');
                brackets.top()->right = newnode;
                brackets.push(newnode);
                i=i+1;
            }
        }
        else if(str[i]== ')'){
            brackets.pop();
        }
    }

    cout<<"Preorder Traversal: ";
    preorderTraversal(root);

    return 0;
}
