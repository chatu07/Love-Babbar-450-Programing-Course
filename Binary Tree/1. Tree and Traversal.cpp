#include<bits/stdc++.h>
using namespace std;


typedef struct node
{
    node *left;
    int data;
    node *right;
}node;


void preOrderTraversal(node* treenode){
    if(treenode){
        cout<<treenode->data<<" ";
        preOrderTraversal(treenode->left);
        preOrderTraversal(treenode->right);
    }
}

void postOrderTraversal(node* treenode){
    if(treenode){
        postOrderTraversal(treenode->left);
        postOrderTraversal(treenode->right);
        cout<<treenode->data<<" ";
    }
}

void InOrderTraversal(node* treenode){
    if(treenode){
        InOrderTraversal(treenode->left);
        cout<<treenode->data<<" ";
        InOrderTraversal(treenode->right);
    }
}

int main(){
    node *root = NULL;
    bool pos = true;
    int *rootnode ;
    queue<node*> queue;
    cout<<"Root: ";
    int data;
    cin>>data;
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    root = newNode;
    queue.push(root);
    // cout<<queue.empty();
    while (!queue.empty())
    {
        node* reqNode = queue.front();
        node* leftNode = (node*)malloc(sizeof(node));
        cout<<"Enter Left Child for "<<reqNode->data<<" : ";
        cin>>data;
        if(data!=-1){
            // cout<<"data Inserted"<<endl;
            leftNode->data = data;
            leftNode->left = NULL;
            leftNode->right = NULL;
            reqNode->left = leftNode;
            queue.push(leftNode);
        }
        // fflush(stdin);
        node* rightNode = (node*)malloc(sizeof(node));
        cout<<"Enter Right Child for "<<reqNode->data<<" : ";
        cin>>data;
        if(data!=-1){
            // cout<<"data Inserted"<<endl;
            rightNode->data = data;
            rightNode->left = NULL;
            rightNode->right = NULL;
            reqNode->right = rightNode;
            queue.push(rightNode);
            // cout<<"data Inserted"<<endl;
        }
        queue.pop();
        // cout<<!queue.empty();

    }
    cout<<"Preorder Traversal: ";
    preOrderTraversal(root);
    cout<<"\nPostorder Traversal: ";
    postOrderTraversal(root);
    cout<<"\nInorder Traversal: ";
    InOrderTraversal(root);
    return 0;
}
