# include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int l, int h){
    for(int i = 1; i <= h; i++){
        int key = arr[i];
        int j = i-1;
        while((j >= 0) && (arr[j] > key)){
            arr[j+1] = arr[j--];
        }
        arr[j+1] = key;
    }
}


int main(){
    int n;
    cout<<"Enter no of elements: ";
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cout<<"Enter element "<<(i+1)<<": ";
        cin>>arr[i];
    }
    insertionSort(arr, 0, n-1);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<"\t";
    }
    return 0;
}