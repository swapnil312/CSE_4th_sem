# include <iostream>
using namespace std;
void merge(int a[], int l, int mid, int h)
{
    int size = (h-l) + 1;
    int b[size];
    int i = l;
    int k = 0;
    int j = mid+1;
    while(i <= mid && j <= h)
    {
        if(a[i] <= a[j])
        {
            b[k++] = a[i++];
        }
        else
        {
            b[k++] = a[j++];
        }
    }
    while(i<=mid){
        b[k++] = a[i++];
    }
    while(j<=h){
        b[k++] = a[j++];
    }
    k = 0;
    for(int i = l; i <= h; i++)
    {
        a[i] = b[k++];
    }

}
void mergeSort(int a[], int l, int h)
{
    if(l == h) {return;}
    int mid = (l+h)/2;
    mergeSort(a, l, mid);
    mergeSort(a, mid+1, h);   
    merge(a, l, mid, h);
}
int main()
{
    int a[10] = {3,5,5,6,3,7,3,7,3,11};
    mergeSort(a,0,9);
    for(int i = 0; i < 10; i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}