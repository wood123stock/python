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
    A:
    if( n == 2)
    {
        return arr01[0][0];
    }
    return det( n - 1, arr01);

}

