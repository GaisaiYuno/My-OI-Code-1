#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[10000],n,q,x,z;
int check(int x,int y,int z){
	int l=1;
	for(int i=1;i<=z;i++)l*=10;
	if(x%l==y)return 1;
	return 0;
}
int main(){
freopen("librarian.in","r",stdin);
freopen("librarian.out","w",stdout);	
scanf("%d%d",&n,&q);
for(int i=1;i<=n;i++){
	scanf("%d",&a[i]);
}
sort(a,a+n+1);
for(int i=1;i<=q;i++){
	scanf("%d%d",&z,&x);
	bool ch=0;
	for(int i1=1;i1<=n;i1++){
	if(check(a[i1],x,z)){
		printf("%d\n",a[i1]);ch=1;
		break;
	}
	}
	if(ch==0)printf("-1\n");
}	
} 
