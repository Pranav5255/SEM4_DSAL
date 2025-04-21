#include<iostream>
#include<stack>
using namespace std;

class Node {
    int data;
    Node *left, *right;
    
    Node() {
        data=0;
        left=right=nullptr;
    }
    
    Node(int d) {
        data=d;
        left=right=nullptr;
    }
    
    friend class BST;
};

class BST{
    Node *root=nullptr;
    
    int height(Node *node){
        if(node==nullptr)
            return 0;
        
        int l = height(node->left);
        int r = height(node->right);
        return max(l,r)+1;
    }
    
    void swapNodes(Node *node){
        if(node==nullptr)
            return;
        
        if(node->left or node->right){
            Node *temp = node->left;
            node->left=node->right;
            node->right=temp;
        }
        
        swapNodes(node->right);
        swapNodes(node->left);
    }
    
    void preorder() {
        Node *curr=root;
        stack<Node*> Stack;
        
        while(!Stack.empty() or curr != nullptr){
            while(curr!=nullptr){
                Stack.push(curr);
                curr=curr->left;
            }
            curr=Stack.top();
            Stack.pop();
            cout<<curr->data<<" ";
            curr=curr->right;
        }
    }
    
    Node* minValueNode(Node* node){
        Node *curr=node;
        while(curr->left!=nullptr)
            curr=curr->left;
        
        return curr;
    }
    
    Node* deletesubTree(Node *root, int key){
        if(key > root->data)
            root->right=deletesubTree(root->right, key);
        else if(key < root->data)
            root->left=deletesubTree(root->left, key);
        else{
            if(root->right==nullptr or root->left==nullptr){
                Node *temp=root->left ? root->left:root->right;
                
                if(temp==nullptr){
                    temp=root;
                    root=nullptr;
                }
                
                else{
                    root->data=temp->data;
                    root->left=root->right=nullptr;
                }
                
                delete temp;
            }
            
            else{
                Node *temp=minValueNode(root->right);
                root->data=temp->data;
                
                root->right=deletesubTree(root->right, temp->data);
            }
        }
        
        return root;
    }
    
    public:
    void insert(int d){
        Node *curr=root, *prev =nullptr;
        
        if(curr==nullptr){
            root=new Node(d);
        }
        
        else{
            while(curr!=nullptr){
                if(d>curr->data){
                    prev=curr;
                    curr=curr->right;
                }
                else if(d<curr->data){
                    prev=curr;
                    curr=curr->left;
                }
                else{
                    cout<<"Node already exists"<<endl;
                    return;
                }
            }
            
            if(d>prev->data){
                Node *temp=new Node(d);
                prev->right=temp;
            }
            
            else{
                Node *temp=new Node(d);
                prev->left=temp;
            }
        }
    }
    
    void search(int d){
        Node *curr=root;
        while(curr!=nullptr){
            if(d>curr->data)
                curr=curr->right;
            else if(d<curr->data)
                curr=curr->left;
            else{
                cout<<"\nNode found"<<endl;
                return;
            }
        }
        cout<<"\nNode doesn't exist"<<endl;
    }
    void del(int key){
        root=deletesubTree(root, key);
    }
    
    void getheight(){
        cout<<"\nNumber of nodes in the longest path: "<<height(root)+1<<endl;
    }
    
    void getminValue(){
        cout<<"\nMinimum value in the tree: "<<minValueNode(root)->data<<endl;
    }
    void getAscending(){
        cout<<"\nValues in ascending order are: ";
        preorder();
    }
    void printSwapped(){
        swapNodes(root);
        cout<<"\nTrees are swapped:"<<endl;
        preorder();
    }
};

int main(){
    BST tree;
    
    tree.insert(50);
    tree.insert(51);
    tree.insert(68);
    tree.insert(37);
    tree.insert(100);
    tree.insert(29);
    
    tree.getAscending();
    
    tree.del(37);
    
    tree.getAscending();
    tree.getheight();
    
    return 0;
}
