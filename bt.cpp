#include <iostream>
#include <stack>
using namespace std;

class Node{
  public:
  int data;
  Node *left, *right;
  Node(int val){
    data=val;
    left=right=NULL;
  }
};

class BT{
  private:
  Node *root;
  void insertNode(Node* &root, Node *tobeinserted){
    if (root == NULL){
        root = tobeinserted;
        return;
    }
    if(root->left==NULL){                                 //checks if left root is available or not
        insertNode(root->left, tobeinserted);
    } else if(root->left!=NULL && root->right==NULL){     //if left is not empty, send to right
        insertNode(root->right, tobeinserted);
    }
    else{                                               //send to left root anyways
        insertNode(root->left, tobeinserted);
    }
  }

  
  void inordertrav(Node *root){
    if(root==NULL){
      return;
    }
    inordertrav(root->left);
    cout<<root->data<<" ";
    inordertrav(root->right);
  }
  
  void preordertrav(Node *root){
    if(root==NULL){
      return;
    }
    
    cout<<root->data<<" ";
    preordertrav(root->left);
    preordertrav(root->right);
  }
  
  void postordertrav(Node *root){
    if(root==NULL){
      return;
    }
    postordertrav(root->left);
    postordertrav(root->right);
    cout<<root->data<<" ";
  }
  
  void swapchildren(Node *root){
    if(root==NULL){
      return;
    }
    swapchildren(root->left);
    swapchildren(root->right);
    swap(root->left, root->right);
  }
  
  int findheight(Node *root){
    if(root==NULL){
      return 0;
    }
    return 1+max(findheight(root->left), findheight(root->right));
  }
  
  void deletetree(Node *root){
    if(root==NULL){
      return;
    }
    deletetree(root->left);
    deletetree(root->right);
    delete root;
  }
  
  Node *copytree(Node *root){
    if(root==NULL){
      return NULL;
    }
    Node *copyRoot=new Node(root->data);
    copyRoot->left=copytree(root->left);
    copyRoot->right=copytree(root->right);
    return copyRoot;
  }
  
  void recur(Node *root, int &count, int flag){
    if(root==NULL){
      return;                   //return nothing
    }
    recur(root->left, count, flag);  //in left subtree
    
    if(flag==1 && (root->left!=NULL || root->right!=NULL)){
      count++;                 //increases count of internal nodes
    }
    else if(flag==-1 &&(root->left==NULL && root->right==NULL)){
      count++;                //increases count of leaf nodes
    }
    else if(flag==0){
      count++;               //increases count of every node.
    }
    recur(root->right, count, flag);
  }
  
  public:
  BT(){root=NULL;}
  BT(Node *root1){root=root1;}
  void insert(int val){
    Node *newNode=new Node(val);
    insertNode(root, newNode);
  }
  void inorder(){ inordertrav(root); }
  void preorder(){ preordertrav(root); }
  void postorder(){ postordertrav(root); }
  void swaptree(){ swapchildren(root); }
  int height(){ return findheight(root); }
  
  BT copy(){
    BT newTree;
    newTree.root=copytree(root);
    return newTree;
  }
  
  int countnodes(){
    int count=0;
    recur(root, count, 0);
    return count;
  }
  
  int countinternodes(){
    int count=0;
    recur(root, count, 1);
    return count;
  }
  
  int countleafnodes(){
    int count=0;
    recur(root, count, -1);
    return count;
  }
  
  void cleartree(){
    deletetree(root);
    root=NULL;
  }
  
  void insertarray(int arr[], int size){          //insert multiple nodes in single go.
    for(int i=0; i<size; i++){
      insert(arr[i]);
    }
  }
};

int main(){
  BT tree;
  int choice, val;
  
  do{
    cout<<"\nMenu: ";
    cout<<"\n1. Insert Node";
    cout<<"\n2. Insert Multiple Nodes";
    cout<<"\n3. Inorder Traversal";
    cout<<"\n4. Preorder Traversal";
    cout<<"\n5. Postorder Traversal";
    cout<<"\n6. Swap Tree";
    cout<<"\n7. Find Height";
    cout<<"\n8. Copy Tree";
    cout<<"\n9. Count all nodes";
    cout<<"\n10. Count internal nodes";
    cout << "\n11. Count Leaf Nodes";
    cout<<"\n12. Clear tree";
    cout<<"\n13. Exit";
    cout<<"\nEnter your choice: ";
    cin>>choice;
    
    switch(choice){
      case 1:
        cout<<"Enter value: ";
        cin>>val;
        tree.insert(val);
        cout<<"\n";
        tree.inorder();
        break;
        
        
      case 2:
      {
        int n, *arr;
        cout<<"Enter number of values to enter: ";
        cin>>n;
        arr= new int[n];
        cout<<"Enter "<<n<<" elements:";
        for (int i=0; i<n; i++){
          cin>>arr[i];
        }
        tree.insertarray(arr, n);
        cout<<"Elements entered successfuly";
        break;
      }
      
      case 3:
        cout<<"Inorder Traversal: ";
        tree.inorder();
        cout<<endl;
        break;
      
      case 4:
        cout<<"Preorder Traversal: ";
        tree.preorder();
        cout<<endl;
        break;
        
      case 5:
        cout<<"Postorder Traversal: ";
        tree.postorder();
        cout<<endl;
        break;
        
      
      case 6:
        tree.swaptree();
        cout<<"Tree Swapped."<<endl;
        break;
      
      case 7:
        cout<<"Height of tree: "<<tree.height()<<endl;
        break;
        
      case 8:
      {
        BT copiedTree=tree.copy();
        cout<<"Tree copied."<<endl;
        break;
      }
      case 9:
        cout<<"Total Nodes: "<<tree.countnodes()<<endl;
        break;
        
      case 10:
        cout<<"Internal nodes: "<<tree.countinternodes()<<endl;
        break;
        
      case 11:
        cout<<"Leaf nodes: "<<tree.countleafnodes()<<endl;
        break;
        
      case 12:
        tree.cleartree();
        cout<<"Tree cleared"<<endl;
        break;
        
      case 13:
        cout<<"Exiting Program."<<endl;
        break;
        
    default:
        cout<<"Invalid choice! Please try again."<<endl;
    }
  }while(choice != 13);
  
  return 0;
}
