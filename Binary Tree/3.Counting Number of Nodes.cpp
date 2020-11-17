#include<bits/stdc++.h>
using namespace std;

typedef struct node{
    node* left;
    int data;
    node* right;
}node;

int countTreeNodes(node *root){

    if(!root)
        return 0;
    return 1+countTreeNodes(root->left)+countTreeNodes(root->right);
}

void arrayToTree(vector<int> vct, int n){
    queue<node*> numbers;
    node *root = NULL;
    bool pos = true;
    int *rootnode ;
    queue<node*> queue;
    cout<<"Root: "<<vct[0]<<endl;
    int data = vct[0];
    node *newNode = (node*)malloc(sizeof(node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    root = newNode;
    queue.push(root);
    int flag = false;

    for(int i = 1;i<n;i++)
    {
        data = vct[i];
        node* reqNode = queue.front();

        if(!flag){
        // cout<<"Left: "<<data<<endl;
            node* leftNode = (node*)malloc(sizeof(node));
            leftNode->data = data;
            leftNode->left = NULL;
            leftNode->right = NULL;
            reqNode->left = leftNode;
            queue.push(leftNode);
        }

        if(flag){
            // cout<<"Right: "<<data<<endl;
            node* rightNode = (node*)malloc(sizeof(node));
            rightNode->data = data;
            rightNode->left = NULL;
            rightNode->right = NULL;
            reqNode->right = rightNode;
            queue.push(rightNode);
        }
        if(flag || i==n-1){
            queue.pop();
        }
        flag =!flag;
    }

    int count = countTreeNodes(root);
    cout<<"Total Number of nodes in the Tree are "<<count;
}

int main()
{
    int n;
    cin>>n;
    vector<int> vct(n);
    for(int i = 0;i<n;i++){
        cin>>vct[i];
    }
    arrayToTree(vct,n);

    return 0;
}
