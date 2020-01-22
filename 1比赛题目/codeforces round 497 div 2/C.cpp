#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 100005
#define fu(a,b,c) for(int a=b;a<=c;a++)
#define fd(a,b,c) for(int a=b;a>=c;a--) 
using namespace std;
int n,xs=1,ds=1,ans,zb;
int a[maxn],b[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		while(a[i]==a[i+1]){
			xs++;
			i++;
		}
		if(i+1>n){
			cout<<0;
			return 0;
		}
		zb=i+1;
		break;
	}
	for(int i=zb;i<=n;i++){
		while(a[i]==a[i+1]){
			ds++;
			i++;
		}
		if(ds>=xs){
			ans+=xs;
			xs=ds;
			ds=1;
		}
		else{
			ans+=ds;
			ds=1;
		}
	}
	printf("%d\n",ans);
	return 0;
}
