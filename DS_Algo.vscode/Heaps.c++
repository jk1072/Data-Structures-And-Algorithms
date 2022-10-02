#include <iostream>
using namespace std;
class heap{
    public:
    int arr[100];
    int size;
    
    heap(){
        size =0;
        arr[0]=-1;
    }
    void insert(int val){
        size =size+1;
        int index =size;
        arr[index]=val;
        while (index>1)
        {
            int parent =index/2;
            if(arr[parent]<arr[index]){          // O(log(n)) time complexity
                swap(arr[parent],arr[index]);
                index=parent;
            }
            else{
                return;
            }
        }
        
    }
    void print(){
        for (int i = 1; i < size+1; i++)
        {
            printf("%d ",arr[i]);
        }
        cout<<endl;
    }
    // first of all replace last node in array with the root node 
    // then delete the root node 
    // then perform compare the root node with its child 
    // until the required binary tree is formed 

    void deletefromHeap(){
        if (size==0){
            printf("Nothing to delete");
            return;
        }
        // put last element into the first index
        swap(arr[1],arr[size]);
        // remove last element
        size--;
        // take root node to it`s correct position
        int i=1;
        while(i<size){                      // time complexity- O(log(n))  
            int leftindex =2*i;
            int rightindex=2*i +1;

            
            if (leftindex< size && arr[i] < arr[leftindex]){
                swap(arr[i],arr[leftindex]);
                i =leftindex;
            }
            else if (rightindex< size && arr[i] < arr[rightindex]){
                swap(arr[i],arr[rightindex]);
                i =rightindex;
            }
            else{
                return;
            }
        }
    }
};
void heapify(int arr[],int size,int i){
    int largest =i;
    int left =2*i;
    int right =2*i+1;
    if (left <=size && arr[largest]< arr[left]){            // heapify algorith -By Inserting all elements:	O(NlogN)
                                                            //Using Heapify	O(N)	
        largest =left;
    }
    if (right <=size && arr[largest]< arr[right]){
        largest =right;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,size,largest);
    }
}
void heapSort(int arr[], int size){
    
    while(size>1){
        // step 1: swap
        swap(arr[size],arr[1]);
        // step 2:
        size--;
        // step 3: 
        heapify(arr,size,1);
    }
    
}
int main(){
    heap h;
    h.insert(50);h.insert(54);
    h.insert(55);
    h.insert(55);
    h.insert(53);
    h.insert(53);
    h.insert(52);
    
    h.insert(54);
    h.print();
    h.deletefromHeap();
    h.print();
    // int arr[7]= {-1,55,57,56,52,53,50};
    // int n=6;
    for (int i = n/2; i>0; i--)
    {heapify(arr,n,i);
        /* code */
    }
    // for (int i = 1; i <=n; i++)
    // {
    //     printf("%d,",arr[i]);
    // }
    // cout<<endl;
    // heapSort(arr,n);
    // for (int i = 1; i <=n; i++)
    // {
    //     printf("%d ",arr[i]);
    // }
    // maxheap
    
    return 0;
}