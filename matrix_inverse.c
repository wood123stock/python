#include<stdio.h>
#include"header.h"
void mat_inv(int n, int arr[])
int main()
{
    int n0;
    printf("enter the order: ");
    scanf("%d",&n0);
    int matrix[n0][n0];
    for(int i = 0; i < n0; i++)
    {
        for(int j = 0; j < n0; j++)
        {
            scanf("%d",&matrix[i][j]);
        }
        mat_inv(n0, matrix[n0][n0]);
    }

}
