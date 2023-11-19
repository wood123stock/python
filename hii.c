#include<stdio.h>
#include<math.h>
int n0;
int det(int m,int arr[m][m]);
int Major(int a, int b,int n, int arr_0[n][n]);
int main()
{
    printf("enter the order: ");
    scanf("%d",&n0);
    int matrix[n0][n0];
    for(int i = 0; i < n0; i++)
    {
        for(int j = 0; j < n0; j++)
        {
            scanf("%d",&matrix[i][j]);
        }
        //printf("\n");
    }
    printf("%d\n", det(n0, matrix));
    return 1;

}
int det(int m,int arr[m][m])
{
    int det01 = 0;
    for(int k = 0; k < m; k++)
    {
        det01 += (pow(-1,k)*(arr[0][k])*Major(0, k,m,arr));
        //printf("det01 = %d", det01);
    }
    return det01;
}
int Major(int a, int b,int n, int arr_0[n][n])
{

    int arr01[n - 1][n - 1];
    int i = 0,j = 0;
    for( int p = 0; p < n; p++)
    {
        for(int q = 0; q < n; q++)
        {
            if(p == a || q == b)
            {
                continue;
            }
        if( j == n - 1)
        {
            i++;
            j = 0;
            if( i == n  - 1)
            {
                goto A;
            }
        }
            arr01[i][j++] = arr_0[p][q];
        }
    }
    // /*for( int g = 0; g < n - 1; g++)
    // {
    //     for(int h = 0; h < n - 1; h++)
    //     {
    //         printf("%d ",arr01[g][h]);
    //     }
    //     printf("\n");
    // }*/
    A:
    if( n == 2)
    {
        return arr01[0][0];
    }
    return det( n - 1, arr01);

}

