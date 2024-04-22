# include <iostream>
using namespace std;

int main()
{
    int l;
    cout<<"Enter length of array: ";
    cin>>l;
    int arr[l];
    for(int i = 0; i < l; i++)
    {
        cout<<"Enter element "<<(i+1)<<": ";
        cin>>arr[i];
    }
    int i = 0;
    for(int j = 1; j < l; j++)
    {
        int key = arr[j];
        i = j-1;
        while((i >= 0)&&(arr[i] > key))
        {
            arr[i+1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }
    for(int i = 0; i < l; i++)
    {
        if(i != l-1)
        {
            cout<<arr[i]<<", ";
        }
        else
        {
            cout<<arr[i];
        }
    }
    return 0;
}