#include<stdio.h>
void merge(int l, int up, int mid, int m, int A[m] );
void merge_sort(int l, int u,int n, int a[n]);
void swap(int *a, int *b)
{
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;

}
int count01 = 0;
void sort_Array( int m , int * a)
{
   for(int i = 0; i < m; i++)
   {
    for(int j = 0; j < m - i - 1; j++)
    {
        if(a[j] > a[j + 1])
        swap(&a[j], &a[j + 1]);
        else if( a[j] == a[j + 1])
        {
            a[j+ 1] = 999999;
            count01++;
        }
        
    }
   } 
}

int main()
{
    int n;
    scanf("%d", &n);
    int Arr[n];
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &Arr[i]);
    }
    sort_Array(n, Arr);
    //merge_sort(0, n - 1, n, Arr);
    for(int i = 0; i < n; i++)
    {
        printf("%d ", Arr[i]);
    }
}
 void merge_sort(int l, int u,int n, int a[n])
 {
    if( l == u)
    return;
    int mid = (l + u)/2;
    merge_sort(l, mid, n, a);
    merge_sort(mid + 1, u, n ,a);
    merge(l,u,mid,n,a);
 }
 void merge(int l, int up, int mid, int m, int A[m] )
 {
      int i = 0, j = (mid + 1), k = 0;
      int Arr[up - l + 1];

    while (i <= mid && j <= up) {
        if (A[i] < A[j]) {
            Arr[k++] = A[i++];
        } else {
            Arr[k++] = A[j++];
        }
    }

    while (i <= mid) {
        Arr[k++] = A[i++];
    }

    while (j <= up) {
        Arr[k++] = A[j++];
    }

    for (int x = 0; x < k; x++) {
        A[l + x] = Arr[x];
    }
} 
   