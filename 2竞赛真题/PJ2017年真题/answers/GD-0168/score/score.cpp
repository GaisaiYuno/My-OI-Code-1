#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
#define ll long long
#define in(a) scanf("%d",&a)
#define out(a) printf("%d\n",a);
#define FOR(a,b,c) for(int a=b;a<=c;a++)
int main(){
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	in(a);in(b);in(c);
	a/=10;b/=10;c/=10;
	int ans=a*2+b*3+c*5;
	out(ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
