#include<iostream>
#include<cstdio>
#include<algorithm>
#include<math.h>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;
int a[1050];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,ch,xu,lz,s=0,p;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=q;i++){
		s=0;
		p=1;
		scanf("%d %d",&ch,&xu);
		for(int k=1;k<=ch;k++){
			p=p*10;
		}
		for(int j=1;j<=n;j++){
			if(a[j]>=xu){
				lz=a[j]-xu;
				if(lz%p==0){
					s=1;
					printf("%d",a[j]);
					break;
				}
			}
		}
		if(s==0) cout<<"-1";
		if(i!=q) cout<<endl;
	}
	return 0;
}
