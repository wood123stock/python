#include<stdio.h>
#include<stdlib.h>
int count01 = 0;

void swap(int *a, int *b)
{
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;
}
int * sort_Array( int m , int * a)
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
    int**A = (int**)malloc(sizeof(int*));
    int terminate = -1;
    int row = 0;
    while( 1)
    {
        int *temp = (int *)malloc(4 * sizeof(int));
        A[row] = temp;
        for( int i = 0; i < 4; i++)
        {                      
           if( i == 0 && terminate != -1 )
            {
                *(temp + i) = terminate;
                continue;               
            }
            scanf("%d", (temp + i));
        }
        scanf("%d", &terminate);
        if( terminate == -1)
        break;
        else
        {
            row++;
            A = realloc(A, (row + 1)*sizeof(int*));
        }

    }
    printf("rows %d\n", row);
    for( int i = 0; i < row; i++) 
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%d ", *(A[i] + j));
        }
        printf("\n");
    }

    return 0;
}
