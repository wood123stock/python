#include<stdio.h>
void max( int p, int q, int a[p][q])
{
    int max = a[0][0];
    for(int i = 0; i < p; i++)
    {
        for( int j = 0; j < q; j++)
        {
            if( max < a[i][j])
            {
                max = a[i][j];
            }
        }
    }
    printf("%d\n",max);
    return;
}
int main()
{
    int n, m;

    scanf("%d %d", &n, &m);
    int arr[n][m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    max(arr, n,m);
    return 0;
}
