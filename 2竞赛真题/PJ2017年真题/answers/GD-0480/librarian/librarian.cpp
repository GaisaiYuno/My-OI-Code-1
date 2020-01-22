#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int a[2005],b[2005],c[2005];
int d[2005],e[2005];
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int i,j,k,m,n,s=0,p=0,q,u=0,r=-1,w;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	for(j=1;j<=m;j++){
		cin>>b[j]>>c[j];
	}
	for(i=1;i<=m;i++){
		k=c[i];
		s=0;
		while(k>0){
			s++;
			e[s]=k%10;
			k/=10;
		}
		w=s;
		for(j=1;j<=n;j++){
			s=0;
			k=a[j];
			while(k>0){
				s++;
				d[s]=k%10;
				k/=10;
			}
			for(q=1;q<=b[i];q++){
				if(e[q]!=d[q]) u=1;
			}
			if(u==0&&(a[j]<r||r==-1)) r=a[j];
			u=0;
			for(q=1;q<=s;q++) d[q]=0;
		}
		for(j=1;j<=w;j++) e[j]=0;
		cout<<r<<endl;
		r=-1;
	}
	return 0;
}
