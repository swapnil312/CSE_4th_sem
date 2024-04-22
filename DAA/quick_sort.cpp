# include <iostream>
using namespace std;

int partition(int *a, int p, int r)
{
    int pivot = p;
    int left = p;
    int right = r;
    while(left < right)
    {
        while((a[left] <= a[pivot])&&(left <= r-1))
        {
            left++;
        }
        while((a[right] > a[pivot])&&(right >= p+1))
        {
            right--;
        }
        if(left < right)
        {
            int temp = a[left];
            a[left] = a[right];
            a[right] = temp;
        }
        
    }
    int temp = a[right];
    a[right] = a[pivot];
    a[pivot] = temp;
    return right;
}

void quickSort(int a[], int p, int r)
{
    // if(p < r)
    // {
    // int q = partition(a, p, r);
    // quickSort(a,p,q-1);
    // quickSort(a,q+1,r);
    // }
    if(p>=r) return;
    int q = partition(a, p, r);
    quickSort(a,p,q-1);
    quickSort(a,q+1,r);
}
int main()
{
    int l;
    int a[10] = {3,56,32,67,3,-2,87,3,6,89};
    l = 10;
    quickSort(a,0,l-1);
    for(int i = 0; i < l; i++)
    {
        cout<<a[i]<<" ";
    }
    return 0;
}