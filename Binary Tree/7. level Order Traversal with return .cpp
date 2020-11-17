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

vector< vector<int> > levelOrderTraversal(node *root){
    vector< vector<int> > ans;
    if(!root){
        return ans;
    }
    queue<node*> levels;
    levels.push(root);
    cout<<root->data<<endl;
    vector<int> temp;
    temp.push_back(root->data);
    ans.push_back(temp);
    int size = 1;
    int next_size = 0;
    while(!levels.empty()){
            //cout<<"Inside While"<<endl;
        vector<int> row;
        for(int i = 0 ;i<size;i++){
            //cout<<"Inside For"<<endl;
            node *poped_elem = levels.front();
            // Push the Right Node
            if(poped_elem->left){
                levels.push(poped_elem->left);
                cout<<(poped_elem->left)->data<<" ";
                row.push_back((poped_elem->left)->data);
                next_size++;
            }
            // Push the Right Node
            if(poped_elem->right){
                levels.push(poped_elem->right);
                next_size++;
                cout<<(poped_elem->right)->data<<" ";
                row.push_back((poped_elem->right)->data);
            }
            levels.pop();
        }
        cout<<endl;
        // Reset The Size
        size = next_size;
        next_size = 0;
        if(row.size())
            ans.push_back(row);
    }
    return ans;
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
    vector< vector<int> > ans = levelOrderTraversal(root);
    for(int i = 0;i<ans.size();i++){
        for(int j = 0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
