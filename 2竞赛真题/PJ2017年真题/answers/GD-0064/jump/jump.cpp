#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
int n,d,k,x[500010],s[500010],f[500010];

void read(int &x){
	x=0;
	bool che=true;
	char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') che=false;
	else x=x*10+ch-'0';
	ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	if(!che) x*=-1;
}

bool check(int mm){
	memset(f,-127,sizeof(f));
	int ll=max(d-mm,1);
	int rr=d+mm;
	f[0]=0;
	for(register int i=0;i<n;i++){
		if(f[i]>=k) return true;
		for(register int j=i+1;j<=n;j++){
			if(x[j]-x[i]>=ll&&x[j]-x[i]<=rr){
				f[j]=max(f[j],f[i]+s[j]);
				if(f[j]>=k) return true;
			}else if(x[j]-x[i]>rr) break;
		}
	}
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	#endif
	int maxn=0;
	read(n);
	read(d);
	read(k);
	for(int i=1;i<=n;i++) read(x[i]),read(s[i]),maxn=max(maxn,maxn+s[i]);
	if(maxn<k){
		puts("-1");
		return 0;
	}
	x[0]=f[0]=0;
	int l=x[1],r=x[n];
	while(l<r){
		int mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	if(check(l)) printf("%d\n",l);
	else puts("-1");
	return 0;
}
