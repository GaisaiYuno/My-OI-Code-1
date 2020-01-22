#include<iostream>
#include<cstring> 
#include<cstdio>
#include<algorithm>
#define maxn 200000
using namespace std;
int n,q,l,r,ans;
int a[maxn],tmp[maxn];
int my_read() {
	int x = 0;
	char c;
	int sign = 1;
	do {
		c = getchar();
		if(c == '-') sign = -1;
	} while(c < '0' || c > '9');
	do {
		x = x*10 + c - '0';
		c = getchar();
	} while(c <= '9' && c >= '0');
	x *= sign;
	return x;
}
int main(){
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout); 
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		a[i]=my_read(); 
	}
	for(int m=0;m<q;m++){
		ans=0;
		cin>>l>>r;
		memset(tmp,0,sizeof(tmp));
		for(int i=l;i<=r;i++) tmp[i]=a[i];
		sort(tmp+l,tmp+r+1);
		if(tmp[l]!=0) ans=0;
		else{
			for(int j=l;j<=r;j++){
				if(tmp[j+1]-tmp[j]>1) ans=tmp[j]+1;
			}
			if(ans==0) ans=tmp[r]+1;
		}
		cout<<ans<<endl;
	}
}
