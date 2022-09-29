# include <stdio.h>
# include  <string.h>
void swap(int a , int b)
{
    int temp = a;
    a=b;
    b=temp;
}
void merge(int arr[],int start,int mid,int end)
{
    int m=0,n=0,k=start;
    int n1 = mid-start+1;
    int n2 = end - mid ;
    int L [n1];
    int R[n2];
    for (int i= 0;i<n1;i++)
    {
        L[i] = arr[i+start];
    }  
    for (int i=0;i<n2;i++)
    {
        R[i]=arr[mid+i+1];
    }
    while (m<n1 && n<n2 )
    {
        if(L[m]<=R[n])
        {
            arr[k]=L[m];
            m++;
            k++;
        }
        else
        {
            arr[k]=R[n];
            n++;
            k++;
        }
    }
    while(m<n1)
    {
        arr[k]=L[m];
        m++;k++;
    }
    while(n<n2)
    {arr[k]=R[n];n++;k++;}

}
void merge_sort(int arr[],int start,int end)
{
    if (start < end)
    {
        int mid = ((start+end)/2);
        merge_sort(arr,start,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}
int partition (int arr[],int start,int end)
{
    int pivot = arr[end];
    int p=start;
    for(int i=start;i<end;i++)
    {
        if(arr[i] <= pivot)
        {
            //swap(arr[i],arr[p]);
            int temp= arr[i];
            arr[i]=arr[p];
            arr[p]=temp;
            p++;
        }
    }
    int temp= arr[p];
    arr[p]=arr[end];
    arr[end]=temp;
    //swap(arr[p],arr[end]);
    return p;

}
void quick_sort(int arr[],int start,int end)
{
    if(start<end)
    {
        int p = partition(arr,start,end);
        quick_sort(arr,start,p-1);
        quick_sort(arr,p+1,end);
    }
}
int binary_search(int k,int arr[],int start,int end)
{
    int mid = (start+end)/2;
    if (start<end)
    {
        if (arr[mid]==k)
        {
            return mid;
        }
        else if(arr[mid]<k)
        {
            return binary_search(k,arr,mid+1,end);
        }
        else
        {
            return binary_search(k,arr,start,mid-1);
        }
    }
    else 
    return -1;
}
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("___UNSORTED___\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    quick_sort(arr,0,n-1);
    printf("___SORTED___\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("Enter element to search:-");
    int srch;
    scanf("%d",&srch);
    printf("Element found at index : %d",binary_search(srch,arr,0,n-1));

}