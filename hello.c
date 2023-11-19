#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b)
{
    int temp;
    temp = *b;
    *b = *a;
    *a = temp;

}
/*int count_product(int a, int (*A)[4] )
{
    int count = 1;
    for(int i = 1; i < a; i++)
    {
        int flag = 1;
        for( int j = 0; j < i; j++)
        {
            if( A[0][i] == A[0][j])
            {
                flag = 0;
                break;
            }
        }
        if( flag == 1)
        count++;
    }
    return count;

}*/

/*int count_custmr(int m,int (*arr)[4])
{
    int unique = arr[0][0];
    int count = 1;
    for(int i = 1; i < m; i++)
    {
        if( arr[i][0] != unique)
        {
            unique = arr[i][0];
            count++;
        }
    }
    return count;
} */

int main()
{
    int (*matrix)[4];
    int terminate = -1;
    int *A = (int*)malloc(4*sizeof(int));
    if( A == NULL)
    return 1;
    int * temp;
    temp = A;
    matrix = (int (*)[4])temp;
    int row = 1;
    while( 1)
    {
        for(int i = 0; i < 4; i++)
        {
            if( i == 0 && terminate != -1 )
            {
                *(temp + i) = terminate;
                continue;               
            }
            scanf("%d", (temp + i));
        }
        //printf("\n");
        scanf("%d",&terminate);
        if( terminate == -1)
        {
            break; // matrix alllocation completed.
        }        
        else
        {
            row++;
            matrix = realloc(matrix, 4*row*sizeof(int) );
        }
        temp = (int(*))(matrix + row - 1);
    }
       for(int i = 0; i < row; i++)
        { 
            for(int j = 0; j < 4; j++)
            {
                printf("%d ", *(*(matrix + i) + j));
            }
            printf("\n");
            
        }    
    printf("%d\n",row);
    for(int j = 0; j < row; j++)
    {
        for(int i= 0; i < row - 1 ; i++)
        {
            if( matrix[i][0] > matrix[i + 1][0])
            {
                for(int k = 0; k < 4; k++)
                {
                    swap(&matrix[i][k], &matrix[i+1][k]);
                }
            }
            else if( matrix[i][0] == matrix[i+1][0])
            {
                if(matrix[i][1] > matrix[i + 1][1])
                {
                    for(int k = 0; k < 4; k++)
                    {
                        swap(&matrix[i][k], &matrix[i+1][k]);
                    }
                }
                else if (matrix[i][1] == matrix[i + 1][1] )
                {
                    int temp = (matrix[i + 1][2]* matrix[i + 1][3]);
                    int temp01 = (matrix[i][2]* matrix[i][3]);
                    matrix[i][2] = temp + temp01;
                    matrix[i][3] = 1;
                    for(int k = 0; k < 4; k++)
                    {
                        matrix[i + 1][k] = -2;
                    }
                }
            }
       
        }
    }
     for(int i = 0; i < row; i++)
        { 
            for(int j = 0; j < 4; j++)
            {
                printf("%d ", *(*(matrix + i) + j));
            }
            printf("\n");
            
        }

    for(int i = 0; i < row; i++)
    {
        if( matrix[i][0] == -2 )
        continue; 
        for(int j = 0; j < 4; j++)
        {            
            if( j < 2)
            {
                printf("%d ",matrix[i][j]);
            }
            else if( j = 2)
            {
                printf("%d ", (matrix[i][j] * matrix[i][j + 1]));
                break;
            }       
            
        }
        printf("\n");
    }

    
   return 0;
}
