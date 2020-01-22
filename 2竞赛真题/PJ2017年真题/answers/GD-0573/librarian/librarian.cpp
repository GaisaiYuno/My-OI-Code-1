#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
int s[1100],len[1100],qu[1100],n,q;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i){
		scanf("%d",&s[i]);
	}
	for(int i=1;i<=q;++i){
		scanf("%d",&len[i]);
		scanf("%d",&qu[i]);
	}
	for(int i=1;i<=q;++i){
		int minm=0x7fffffff;
		int mod=pow(10,len[i]);
		for(int j=1;j<=n;++j){
			if(s[j]%mod==qu[i]) minm=min(minm,s[j]);
		}
		if(minm!=0x7fffffff) cout<<minm<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
