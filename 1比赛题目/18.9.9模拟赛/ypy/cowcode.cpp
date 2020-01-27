#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
char ans[5000005];
char s[35];
long long table[105];
long long n;
long long fast_pow(long long x,long long k) {
	long long ans=1;
	while(k) {
		if(k&1) ans=ans*x;
		x=x*x;
		k>>=1;
	}
	return ans;
}
long long len;
int sz;
int bin_search(int l,int r,long long x) {
	int mid;
	int ans=0;
	while(l<=r) {
		mid=(l+r)>>1;
		if(table[mid]<=x) {
			l=mid+1;
		} else {

			ans=mid;
			r=mid-1;
		}
	}
	return ans;

}
char solve(long long n) {
	if(n<=len) return s[n];
	if(n==len+1) return s[len];
	long long tmp=bin_search(1,sz,n)-1;
	long long mid=table[tmp];
//	printf("%d %d %d\n",n,tmp,mid);
	if(n==mid||n==mid+1) {
		if(tmp%len) return s[len-tmp%len+1];
		else return s[1];
	} else {
		if(n<mid) return solve(n);
		else return solve(n-mid-1);
	}
}
int main() {
//	freopen("cowcode.in","r",stdin);
//	freopen("cowcode.out","w",stdout);
	scanf("%s ",s+1);
//		printf("%.10f\n",(double)sizeof(ans)/1024/1024);
	len=strlen(s+1);
	cin>>n;
	if(n<5000000) {
		for(int i=1; i<=len; i++) {
			ans[i]=s[i];
		}
		do {
			ans[len+1]=ans[len];
			for(int i=1; i<=len-1; i++) {
				ans[len+1+i]=ans[i];
			}
			len=2*len;
		} while(len/2<=n);
		printf("%c",ans[n]);
	} else {
		table[1]=len;
		for(long long i=2;; i++) {
			table[i]=table[i-1]*2;
			if(table[i]>n) {
				sz=i;
				break;
			}
		}
		printf("%c",solve(n));
	}

}
