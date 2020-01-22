#include<iostream>
#include<cstdio>
#define maxn 300000
using namespace std;
typedef long long ll;
int n;
int a[maxn+5];
int main(){
	ll b=0,w=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int x=a[i]/2,y=a[i]-a[i]/2;
		if(i%2==0){
			w+=x;
			b+=y;
		}else{
			w+=y;
			b+=x;
		}
	}
	printf("%I64d\n",min(w,b));
}

