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
int c[100];
int a[1010];
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q;
	c[1]=10;
	FOR(i,2,8)c[i]=c[i-1]*10;
	in(n);in(q);
	FOR(i,1,n)in(a[i]);
	while(q--){
		int c1,c2;
		in(c1);in(c2);
		int ans=-1;
		FOR(i,1,n){
			if(a[i]%c[c1]==c2&&(a[i]<ans||ans==-1)){
				ans=a[i];
			}
		}
		out(ans);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}

