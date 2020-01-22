#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int read()
{
	int x=0,f=1; char c=getchar();
	while (c>'9'||c<'0') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
	return x*f;
}
int n,d,k,x[510000],s[510000],l,r,mid;
bool check(int g)
{
	int now=0,t;
	bool p=1;
	long long sum=0;
	if (g<d) {
		while(sum<k&&p) {
			int Max=-1e7;
			for (int i=1; i<=n; i++) {
				if (d-g>=1&&now+d-g<=x[i]&&now+d+g>=x[i]&&s[i]>Max) {
					Max=s[i];
					t=x[i];
				}
				if (now+d+g>=x[n]&&Max<0&&sum<k) p=0;
			}
			sum+=Max;
			now=t;
		}
	}
	else {
		while(sum<k&&p) {
			int Max=-1e7;
			for (int i=1; i<=n; i++) {
				if (now+1<=x[i]&&now+d+g>=x[i]&&s[i]>Max) {
					Max=s[i];
					t=x[i];
				}
				if (now+d+g>=x[n]&&Max<0&&sum<k) p=0;
			}
			sum+=Max;
			now=t;
		}
	}
	if (sum>k) return 1;
	else return 0;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	long long pan=0;
	n=read(); d=read(); k=read();
	for (int i=1; i<=n; i++) {
		x[i]=read(); s[i]=read();
		if (s[i]>0) pan+=s[i];
	}
	if (pan<k) {
		cout<<-1;
		return 0;
	}
	l=1; r=x[n];
	while (l<r) {
		mid=(l+r)/2;
		if (check(mid)) r=mid; else l=mid+1;
	}
	cout<<r;
	fclose(stdin); fclose(stdout);
	return 0;
}
