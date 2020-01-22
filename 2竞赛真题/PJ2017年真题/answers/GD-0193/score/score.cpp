#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
using namespace std;
int a,b,c;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
    
    scanf("%d%d%d",&a,&b,&c);
    
    a/=10,b/=10,c/=10;
    
    int ans=a*2+b*3+c*5;
    
    cout<<ans;
    
	return 0;
}

