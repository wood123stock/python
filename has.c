#include<stdio.h>
#include<stdlib.h>
//void merge(int l, int up, int mid, int m, int A[m] );
//void merge_sort(int l, int u,int n, int a[n]);
void swap(int *a, int *b)
{
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;

}
int count01 = 0;
void sort_Array( int *m , int * a)
{
   for(int i = 0; i < *m; i++)
   {
    for(int j = 0; j < *m - 1; j++)
    {
        if(a[j] > a[j + 1])
        swap(&a[j], &a[j + 1]);
        else if( a[j] == a[j + 1])
        {
            a[j+ 1] = 999999;
            *m--;
        }
        
    }
   } 
   a = realloc(a,(*m)*sizeof(int));
}

int main()
{
    int n;
    scanf("%d", &n);
    int * Arr;
    Arr = (int *)malloc( n * sizeof(int));
    for(int i = 0; i < n; i++)
    {
        scanf("%d", Arr + i);
    }
    sort_Array(&n, Arr);
    printf("%d\t%d\n", n, count01);
    for(int i = 0; i < n; i++)
    {
        printf("%d ", *(Arr + i));
    }

}
