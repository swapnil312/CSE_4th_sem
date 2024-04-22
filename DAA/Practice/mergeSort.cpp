# include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int l, int mid, int h){
    int i = l;
    int j = mid+1;
    int k = 0;
    int merged[h-l+1];
    while((i <= mid)&&(j <= h)){
        if(arr[i] <= arr[j]){
            merged[k++] = arr[i++];
        }
        if(arr[j] < arr[i]){
            merged[k++] = arr[j++];
        }
    }
    while(i<=mid){
        merged[k++] = arr[i++];
    }
    while(j<=h){
        merged[k++] = arr[j++];
    }
    k = 0;
    for(int i = l; i <= h; i++)arr[i] = merged[k++];
}

void mergeSort(int *arr, int l, int h){
    if(l>=h) return;
    int mid = (l+h)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,h);
    merge(arr,l,mid,h);
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
    mergeSort(arr, 0, n-1);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<"\t";
    }
    return 0;
}