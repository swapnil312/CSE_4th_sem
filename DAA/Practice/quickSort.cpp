# include <bits/stdc++.h>
using namespace std;

int partition(int *arr, int l, int h){
    int pivot = l;
    int left = l;
    int right = h;

    while(left < right){
        while((arr[left] <= arr[pivot])&&(left <= h-1)){
            left++;
        }
        while((arr[right] > arr[pivot])&&(right >= l+1)){
            right--;
        }
        if(left<right){
            int temp = arr[right];
            arr[right] = arr[left];
            arr[left] = temp;
        }
    }

    int temp = arr[right];
    arr[right] = arr[pivot];
    arr[pivot] = temp;
    return right;
}

void quickSort(int *arr, int l, int h){
    if(l>=h) return;
    int p = partition(arr,l,h);
    quickSort(arr,l,p-1);
    quickSort(arr,p+1,h);
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
    quickSort(arr, 0, n-1);
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<"\t";
    }
    return 0;
}