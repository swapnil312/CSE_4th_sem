# include <iostream>
using namespace std;

void maxHeapify(int arr[], int i, int size){
    int largest = i;
    int left = 2*i;
    int right = (2*i)+1;
    if((i>size)||(left>size)||(right>size)) return;
    if(arr[left] > arr[largest]) largest = left;
    if(arr[right] > arr[largest]) largest = right;
    // cout<<"i = "<<i<<"\tleft = "<<left<<"\t"<<"right = "<<right<<"\tlargest = "<<largest<<endl;
    // cout<<"Executing"<<endl;
    if(largest != i){
        int t = arr[i];
        arr[i] = arr[largest];
        arr[largest] = t;
        // for(int i = 1; i <= 9; i++){
        // cout<<arr[i]<<"\t";
        // }
        maxHeapify(arr,largest,size);
    }
    return;
}
void minHeapify(int arr[], int i, int size){
    int smallest = i;
    int left = 2*i;
    int right = (2*i)+1;
    if((i>size)||(left>size)||(right>size)) return;
    if(arr[left] < arr[smallest]) smallest = left;
    if(arr[right] > arr[smallest]) smallest = right;
    // cout<<"i = "<<i<<"\tleft = "<<left<<"\t"<<"right = "<<right<<"\tlargest = "<<largest<<endl;
    // cout<<"Executing"<<endl;
    if(smallest != i){
        int t = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = t;
        // for(int i = 1; i <= 9; i++){
        // cout<<arr[i]<<"\t";
        // }
        minHeapify(arr,smallest,size);
    }
    return;
}

void buildMaxHeap(int arr[], int size){
    for(int i = (size/2); i >= 1; i--){
        maxHeapify(arr,i,size);
    }
}
void buildMinHeap(int arr[], int size){
    for(int i = (size/2); i >= 1; i--){
        minHeapify(arr,i,size);
    }
}

void heapSortAscending(int arr[], int size){
    int x = size-1;
    buildMaxHeap(arr,size);
    // for(int i = 1; i <= 9; i++){
    //     cout<<arr[i]<<"\t";
    // }
    // cout<<endl;
    for(int i = size; i >= 2; i--){
        int t = arr[i];
        arr[i] = arr[1];
        arr[1] = t;
        // for(int i = 1; i <= 9; i++){
        // cout<<arr[i]<<"\t";
        // }
        // cout<<endl;
        maxHeapify(arr,1,x--);
        // for(int i = 1; i <= 9; i++){
        // cout<<arr[i]<<"\t";
        // }
        // cout<<endl;

    }
}
void heapSortDescending(int arr[], int size){
    int x = size-1;
    buildMinHeap(arr,size);
    // for(int i = 1; i <= 9; i++){
    //     cout<<arr[i]<<"\t";
    // }
    // cout<<endl;
    for(int i = size; i >= 2; i--){
        int t = arr[i];
        arr[i] = arr[1];
        arr[1] = t;
        // for(int i = 1; i <= 9; i++){
        // cout<<arr[i]<<"\t";
        // }
        // cout<<endl;
        minHeapify(arr,1,x--);
        // for(int i = 1; i <= 9; i++){
        // cout<<arr[i]<<"\t";
        // }
        // cout<<endl;

    }
}

int main(){
    int arr1[10] = {-1,9,8,7,6,5,4,3,2,2};
    heapSortAscending(arr1,9);
    int arr2[10] = {-1,1,2,3,4,5,6,7,8,9};
    heapSortDescending(arr2,9);
    cout<<endl<<"Array(ascending)..."<<endl;
    for(int i = 1; i <= 9; i++){
        cout<<arr1[i]<<"\t";
    }
    cout<<endl<<"Array(descending)..."<<endl;
    for(int i = 1; i <= 9; i++){
        cout<<arr2[i]<<"\t";
    }
    return 0;
}