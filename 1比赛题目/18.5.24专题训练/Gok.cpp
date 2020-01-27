#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char s1[500],s2[500],s3[500];
int dp[500][500];

int main()
{
    int t,i,j,k,len1,len2,len3,cas = 1 ;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s%s",s1+1,s2+1,s3+1);
        len1 = strlen(s1+1);
        len2 = strlen(s2+1);
        len3 = strlen(s3+1);
        memset(dp,0,sizeof(dp));
        for(i = 1; i<=len1; i++)
        {
            if(s1[i] == s3[i])
                dp[i][0] = 1;
            else break;
        }
        for(i = 1; i<=len2; i++)
        {
            if(s2[i] == s3[i])
                dp[0][i] = 1;
            else break;
        }
        for(i = 1; i<=len1; i++)
        {
            for(j = 1; j<=len2; j++)
            {
                if(s3[i+j] == s1[i] && dp[i-1][j])
                    dp[i][j] = 1;
                if(s3[i+j] == s2[j] && dp[i][j-1])
                    dp[i][j] = 1;
            }
        }
        printf("Data set %d: ",cas++);
        if(dp[len1][len2])
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}

