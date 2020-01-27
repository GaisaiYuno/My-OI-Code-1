#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<set>
#define maxn 500000
using namespace std;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}


int n;
int a[maxn+5];
multiset<int>S; 


int main(){
//	freopen("decrease3.in","r",stdin);
	freopen("decrease.in","r",stdin);
	freopen("decrease.out","w",stdout);
	qread(n);
	for(int i=1;i<=n;i++) qread(a[i]);
	sort(a+1,a+1+n);
	int mid=lower_bound(a+1,a+1+n,a[n]/2)-a;
	if(a[mid]*2>a[n]) mid--;
	for(int i=1;i<=n;i++) S.insert(a[i]);
	int ans=0;
	for(int i=mid;i>=1;i--){
		multiset<int>::iterator it=--S.end();
		if(a[i]*2<=(*it)&&S.count(a[i])){
			S.erase(it);
			S.erase(S.find(a[i]));
			ans++;
		} 
	}
	printf("%d\n",n-ans);
}
