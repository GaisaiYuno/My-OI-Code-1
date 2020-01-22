#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;
int n,m,a[1010];

void read(int &x){
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
}

bool check(int a,int b){
	while(a&&b){
		if(a%10!=b%10) return false;
		a/=10;
		b/=10;
	}
	if(b) return false;
	else return true;
}

int main(){
	#ifndef ONLINE_JUDGE
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++) printf("      %d\n",a[i]);
	for(int i=1;i<=m;i++){
		bool che=false;
		int x,y;
		read(x);
		read(y);
		for(int i=1;i<=n;i++){
			if(check(a[i],y)){
				printf("%d\n",a[i]);
				che=true;
				break;
			}
		}
		if(!che) puts("-1");
	}
	return 0;
}
