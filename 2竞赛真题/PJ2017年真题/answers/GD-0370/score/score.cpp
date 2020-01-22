#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int zy,xc,qm,ans;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&zy,&xc,&qm);
	ans=zy*2/10+xc*3/10+qm*5/10;
	cout<<ans<<endl;
	fclose(stdin);fclose(stdout);
	return 0;
}
