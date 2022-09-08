#include <iostream>
using namespace std;

void merge(int start, int end,int mid,int arr[])
{
    int n1= mid-start+1;
    int n2= end-mid;
    int L[n1];
    int R[n2];
    for(int i=0;i<n1;i++)
    {
        L[i]=arr[start+i];
    }
    
    for (int j=0;j<n2;j++)
    {
        R[j]=arr[mid+1+j];
    }
    int k=start,i=0,j=0;
    while (i<n1 && j<n2)
    {
        if (L[i] <= R[j])
        {
            arr[k]=L[i];
            k++;
            i++;
        }
        else{
            arr[k]=R[j];
            j++;k++;
        }
    }
    while(i<n1)
    {arr[k]=L[i];k++;i++;}
    while(j<n2)
    {arr[k]=R[j];k++;j++;}

}
void merge_sort(int start, int end, int arr[])
{
    if(start < end)
    {
    int mid = ((start+end)/2);
    merge_sort(start,mid,arr);
    merge_sort(mid+1,end,arr);
    merge(start,end,mid,arr);
    }
    //return arr;
}

int main(){
        int size;
        cin>>size;
        int arr[size];
        for (int i=0;i<size;i++)
        {
            cin>>arr[i];
        }
      
        merge_sort(0,size-1,arr);
        for(int i=0;i<size;i++)
        {
            cout<<arr[i]<<"\n";
        }
        //cout<<(arr[size-1]-arr[0]);
        return 0;
    }
    