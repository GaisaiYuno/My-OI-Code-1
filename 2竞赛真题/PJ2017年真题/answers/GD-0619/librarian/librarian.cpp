#include<bits/stdc++.h>
using namespace std;
int f[10001000],n,q,u,x,j,l,g,p;
int main(){
	freopen("librarian.in.txt","r",stdin);
	freopen("librarian.out.txt","w",stdout);
	cin>>n>>q;
	memset(f,-1,sizeof(f));
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		u=x; p=10;
		while(u){
			u/=10;
			if(f[x%p]==-1||f[x%p]>x) f[x%p]=x;
			p*=10;
		}
	} 
	for(int i=1;i<=q;i++){
		cin>>l>>g;
		printf("%d\n",f[g]);
	}
}
