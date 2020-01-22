#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a,b,ppp=0;
int QAQ,whh[1010]={0};
int x,y;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++){
		scanf("%d",&whh[i]);
	}
	sort(whh+1,whh+a+1);
	for(int i=1;i<=b;i++){
		scanf("%d%d", &x,&QAQ);
		y=1;
		for(int j=1;j<=x;j++)y*=10;
		for(int j=1;j<=a+1;j++)if(whh[j]%y==QAQ){
		    printf("%d\n",whh[j]);
			ppp=1;break;
			}
		if(ppp==0)printf("-1\n");
		ppp=0;
	}
	return 0;
}
