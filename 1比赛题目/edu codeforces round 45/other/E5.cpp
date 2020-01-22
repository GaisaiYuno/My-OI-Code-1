#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1005;
int n, a, b;
int mat[MAXN][MAXN];
int main()
{
    scanf("%d%d%d", &n, &a, &b);
    if (min(a, b) != 1)
    {
        printf("NO\n");
        return 0;
    }
    if (max(a, b) == 1)
    {
        if (n == 2 || n == 3) printf("NO\n");
        else
        {
            printf("YES\n");
            for (int i = 1; i < n; i ++)
                mat[i][i + 1] = mat[i + 1][i] = 1;
            for (int i = 1; i <= n; i ++)
            {
                for (int j = 1; j <= n; j ++)
                    printf("%d", mat[i][j]);
                printf("\n");
            }
        }
        return 0;
    }
    int rev = 0;
    if (b > a)
    {
        rev = 1;
        swap(a, b);
    }
    for (int i = 1; i <= n - a; i ++)
        mat[1][i + 1] = mat[i + 1][1] = 1;
    printf("YES\n");
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            if (i != j) mat[i][j] ^= rev;
            printf("%d", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
