#include<bits/stdc++.h>
using namespace std;


typedef struct node
{
    node *left;
    int data;
    node *right;
}node;

bool isPowerOfTwo(int n)
{
   if(n==0)
   return false;

   return (ceil(log2(n)) == floor(log2(n)));
}

void levelOrderTraversal(node *root){
    vector< vector<int> > ans;
    queue<node*> levels;
    int count = 0;
    int power= 1;
    levels.push(root);
    cout<<root->data<<"\n";
    while(!levels.empty()){
        node *temp = levels.front();
        if(temp->left){
            cout<<(temp->left)->data<<" ";
            levels.push(temp->left);
        }
        count++;
        if(temp->right){
            cout<<(temp->right)->data<<" ";
            levels.push(temp->right);
        }
        count++;
        levels.pop();
    }
    return;
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
        if(data!=0){
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
        if(data!=0){
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
    cout<<"Level Order Traversal: \n";
    levelOrderTraversal(root);
    return 0;
}
