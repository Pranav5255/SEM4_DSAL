#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Node{
    private:
        int data;
        Node *left, *right;
    public:
        Node(int val):data(val), left(NULL), right(NULL) {}
        friend class Heap;
};

class Heap{
    private:
        vector<Node*> arr;
    public:
        Heap(){
            int n, m;
            cout<<"Enter number of elements: ";
            cin>>n;
            for(int i=0; i<n; i++){
                cout<<"Enter data: ";
                cin>>m;
                arr.push_back(new Node(m));
            }
        }

        void createCBT(){
            int n=arr.size();
            for(int i=0;i<n;i++){
                if(2*i+1<n)
                    arr[i]->left=arr[2*i+1];
                if(2*1+2<n){
                    arr[i]->right=arr[2*1+2];
                }
            }
        }

        void heapify(int i, int n){
            int largest =i;
            int left=2*i+1;
            int right=2*i+2;

            if(left<n && arr[left]->data > arr[largest]->data)
                largest=left;
            if(right<n && arr[right]->data > arr[largest]->data)
                largest=right;
            if(largest!=i){
                swap(arr[i]->data, arr[largest]->data);
                heapify(largest, n);
            }
        }

        void builmaxheap(){
            int n=arr.size();
            for(int i=n/2-1; i>=0; i--){
                heapify(i,n);

            }
        }

        void minheapify(int i, int n){
            int lowest=i;
            int left=2*i+1;
            int right=2*i+2;

            if(left<n && arr[left]->data>arr[lowest]->data)
                lowest=left;
            if(right<n && arr[right]->data>arr[lowest]->data)
                lowest=right;
            if(lowest!=i){
                swap(arr[i]->data, arr[lowest]->data);
                minheapify(lowest, n);
            }
        }

        void buildminheap(){
            int n=arr.size();
            for(int i=n/2-1; i>=0; i--){
                minheapify(i,n);
            }
        }

        void printheap(){
            for(auto node:arr){
                cout<<node->data<<" ";
            }
            cout<<"\n";
        }

        void heapsortmax(){
            vector<int> v;
            int count=1;
            cout<<"Array elements are: ", printheap();
            cout<<"\n";
            while(arr.size()!=1){
                swap(arr[0]->data, arr[arr.size()-1]->data);
                v.push_back(arr[arr.size()-1]->data);
                arr.pop_back();
                builmaxheap();
                cout<<"Pass "<<count<<":",printheap();
                count+=1;
            }
            v.push_back(arr[arr.size()-1]->data);

            cout<<"\nSorted Array is: ";
            for(int i=v.size()-1;i>=0; i--){
                cout<<v[i]<<" ";
            }
            cout<<"\n";
        }

        void heapsortmin(){
            vector<int> v;
            int count=1;
            cout<<"Array elements are: ", printheap();
            cout<<"\n";
            while(arr.size()!=1){
                swap(arr[0]->data, arr[arr.size()-1]->data);
                v.push_back(arr[arr.size()-1]->data);
                arr.pop_back();
                buildminheap();
                cout<<"Pass"<<count<<":", printheap();
                count+=1;
            }
            v.push_back(arr[arr.size()-1]->data);

            cout<<"\nSorted array is: ";
            for(int i=v.size()-1; i++;){
                cout<<v[i]<<" ";
            }
            cout<<"\n";
        }
};

int main(){
    Heap heap;
    heap.createCBT();
    cout<<"Heap befor heapify: ";
    heap.printheap();
    heap.builmaxheap();
    cout<<"Max heap after heapify: ";
    heap.printheap();
    cout<<"\n";
    heap.heapsortmax();
    return 0;

}
