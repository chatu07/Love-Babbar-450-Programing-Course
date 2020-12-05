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

Node* ins(){

}

Node* inPre(Node* root){
    while (root &&root->right!=NULL)
    {
        root = root->right;
    }
    return root;
}

Node* inScc(Node* root){
    while (root &&root->left!=NULL)
    {
        root = root->left;
    }
    return root;
}

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    1 + max(height(root->left),height(root->right));
}

Node* DeleteNode(Node* root,int key){
    // cout<<"\nInside Function";
    if(root== NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        // cout<<"\nKey Found\n";
        free(root);
        return NULL;
    }

    if(key > root->data){
        // cout<<"\nKey is Greater";
        DeleteNode(root->right,key);
    }else if(root->data < key){
        // cout<<"\nKey is Smaller";
        DeleteNode(root->left,key);
    }
    else{
        cout<<"Key Found: "<<endl;
        if(height(root->left) > height(root->right)){
            cout<<"Height Checked\n";
            Node* q = inScc(root->left);
            root->data = q->data;
            root->left = DeleteNode(root->left,q->data);
        }
        else{
                cout<<"Height Checked\n";
            Node* q = inScc(root->right);
            root->data = q->data;
            root->right = DeleteNode(root->right,q->data);
        }
    }
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
    cout<<"\nNode to Delete: ";
    int key;
    cin>>key;
    Node* DeketedNode = DeleteNode(root,key);
    cout<<"Inorder Traversal After Delete: "<<endl;
    inorderTraversal(root);
    return 0;
}
