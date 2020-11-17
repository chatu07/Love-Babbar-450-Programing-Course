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

void inOrderTraversal(Node* tree){
    if(tree){
        inOrderTraversal(tree->left);
        cout<<tree->data<<" ";
        inOrderTraversal(tree->right);
    }
}

void VerticalView(Node* tree){

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
    cout<<"Traversal: ";
    inOrderTraversal(tree);
    cout<<endl;
    VerticalView(tree);

    return 0;
}