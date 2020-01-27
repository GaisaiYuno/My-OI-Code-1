#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000005
using namespace std;
inline int fread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'||c<='9'){
		x=x*10+c-'0';
		c=getchar(); 
	}
	return x*sign;
}
int n,m,l,r,ans;
int a[maxn];
bool used[2*maxn];
int main(){
	freopen("yzbt.in","r",stdin);
	freopen("yzbt.out","w",stdout); 
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	while(m--){
		cin>>l>>r;
		ans=0;
		for(int s=l;s<=r;s++){
			memset(used,0,sizeof(used));
			int j=0;
			for(j=s;j<=r;j++){
				int t=a[j];
				if(t<0) t=-2*a[j];
				if(used[t]){
					ans=max(ans,j-s);
					break;
				}
				else used[t]=1;
			}
			if(ans==0) ans=r-s+1;
		} 
		cout<<ans<<endl;
	}
}

