// GFG PROBLEM
// https://www.geeksforgeeks.org/diagonal-traversal-of-binary-tree/


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



map<int, vector<int> > distance_map;

void preOrderDistance(Node *tree,int distance){
    if(tree){
        distance_map[distance].push_back(tree->data);
        preOrderDistance(tree->left,distance+1);
        preOrderDistance(tree->right,distance);
    }
}
vector<int>  boundryTraversal(Node* tree){

    vector<int> ans;
    preOrderDistance(tree,0);
    

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
        if(vct[i]!=0){
            // cout<<" Node "<<vct[i]<<" left"<<endl;
            Node* left = new Node(vct[i]);
            prev_node->left = left;
            queue.push(left);
        }
        if(i+1<=n-1 && vct[i+1]!=0){
            // cout<<" Node "<<vct[i+1]<<" right"<<endl;
            Node* right = new Node(vct[i+1]);
            prev_node->right = right;
            queue.push(right);
        }
        queue.pop();
    }

    cout<<"Boundry Order Traversal: \n";
    vector<int> ans = boundryTraversal(tree);
    
        for(int j = 0;j<ans.size();j++){
            cout<<ans[j]<<" ";
        }
        cout<<endl;
    
    return 0;
}