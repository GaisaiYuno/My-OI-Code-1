#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct asd{
	int x;
	int c;
}a[501];
int main(){
	int i,j,d,h,g=0;
	int v=0;
	long long k,n;
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
    cin>>n>>d>>k;
    for(i=1;i<=n;i++){
    	scanf("%d",&a[i].x);
    	scanf("%d",&a[i].c);
    	if(a[i].c>0) h+=a[i].c;
    }
    if(h<k){
    	g=-1;
    	printf("%d",g);
    	return 0;
    }
	return 0;
}
