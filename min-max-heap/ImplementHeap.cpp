#include <bits/stdc++.h>
using namespace std;
class heap{
    public:
        int arr[100];
        int size;
    
    heap(){
        arr[0]=-1;
        size=0;
    }
    void insert(int val){
        size=size+1; // new size
        int index = size;//insert at this index
        arr[index]=val;
        
        while(index>1){
           int parent = index/2;
           
           if(arr[parent]<arr[index]){
               swap(arr[parent],arr[index]);
               index=parent;
           }
           else{
               return;
           }
        }
        
        
    }
    
    void deleteF(){
        if(size==0){
            cout<<"nothing to delete"<<endl;
            return;
        }
        
        int temp = arr[size];
        arr[1]=temp;
        size--;
        //arrange heap
        int i=1;
        while(i<size){
            int leftChildIdx = 2*i;
            int rightChildIdx = 2*i+1;
            
            if(arr[leftChildIdx]>arr[rightChildIdx] && arr[i]<arr[leftChildIdx]){
                swap(arr[i],arr[leftChildIdx]);
                i=leftChildIdx;
            }
            else if(arr[leftChildIdx]<arr[rightChildIdx] && arr[i]<arr[rightChildIdx]){
                swap(arr[i],arr[rightChildIdx]);
                i=rightChildIdx;
            }
            else
                return;
            
        }
        
    }
    
    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

    void heapify(int Arr[],int n,int i){
        // time complexity is O(n) and not O(nlogn)
        int largest = i;
        int left = 2*i;
        int right=2*i+1;
        
        if(left<=n && Arr[largest]<Arr[left]){
            largest=left;
        }
        if(right<=n && Arr[largest]<Arr[right]){
            largest=right;
        }
        
        //if node is updated
        if(largest!=i){
           swap(Arr[largest],Arr[i]);
           heapify(Arr,n,largest);
        }
    }
    
void heapSort(int arr[],int n){
    //time complexity: O(nlogn)
    int size=n;
    
    while(size>1){
        //step 1:swap
        swap(arr[1],arr[size]);

        size--;
                
        //step 2
        heapify(arr,n,1);
    }
}   

int main()
{
    heap h;
    h.insert(10);
    h.insert(5);
    h.insert(50);
    h.insert(22);
    h.insert(12);
    h.insert(90);
    h.print();
    h.deleteF();
    h.print();
    cout<<endl;
    //Performing heapify
    int Arr[6]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--){
        heapify(Arr,n,i);
    }
   
   //print sorted array 
    for(int i=1;i<=n;i++){
        cout<<Arr[i]<<" ";
    }
    cout<<endl;
    
    //heap sort 
    
    heapSort(arr,n);
    
   //print sorted array 
    for(int i=1;i<=n;i++){
        cout<<Arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}