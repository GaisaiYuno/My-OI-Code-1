#include<bits/stdc++.h>
using namespace std;
bool flag;
int singledog;
int f(int t,int j){
	if(j==0) return 1;
	else return (t*f(t,j-1));
}
struct od{
	int step,value,time;
}b[1100];
int avalue[1100];
int q,n;
int i,j;
int m,k;
int oj,ob;
int main(){
	freopen("librarian.in","r",stdin);
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++){
		scanf("%d",&avalue[i]);
	}
	for(i=1;i<=q;i++){
		scanf("%d%d",&b[i].step,&b[i].value);
	}
	sort(avalue+1,avalue+n+1);
	freopen("librarian.out","w",stdout);
	for(i=1;i<=q;i++){
		b[i].time=f(10,b[i].step+1);
		flag=false;
		for(j=n;j>=1;j--){
			k=b[i].value;
			m=avalue[j];
			m=m%b[i].time;
			if(m==k){
				flag==true;
				break;
			}
		}
		if(flag==true){
			singledog=q-j+1;
			scanf("%d",&singledog);
		}
		if(flag==false) scanf("-1");
		scanf("\n");
	}
	return 0;
}
