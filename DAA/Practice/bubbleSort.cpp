# include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cout<<"Enter no of elements: ";
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cout<<"Enter element "<<(i+1)<<": ";
        cin>>arr[i];
    }
    
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp; 
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout<<arr[i]<<"\t";
    }
    return 0;
}