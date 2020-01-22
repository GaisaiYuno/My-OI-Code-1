#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define zhh 1005
#define ll long long
using namespace std;
int n,q;
ll s[zhh],lin[zhh];
bool fl=false;
ll cf(int x){
	int res=1;
	for(int i=1;i<=x;i++){
		res*=10;
	}
	return res;
}
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
struct hehe{
	ll x,len;
}re[zhh];
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	n=read(),q=read();
	for(int i=1;i<=n;i++){
		s[i]=read();
	}
	for(int i=1;i<=q;i++){
		re[i].len=read(),re[i].x=read();
		memset(lin,0,sizeof(lin));
		fl=false;
		for(int j=1;j<=n;j++){
			int mds=cf(re[i].len);
			if(re[i].x==s[j]%mds){
				fl=true;
				lin[j]=s[j];
			}
		}
		sort(lin+1,lin+n+1);
		if(!fl){
			cout<<"-1"<<endl;
		}
		else{
			for(int j=1;j<=n;j++){
				if(lin[j]){
					cout<<lin[j]<<endl;
					break;
				}
			}
		}
	}
	return 0;
}
/*
1¡Ün¡Ü1,000£¬1¡Üq¡Ü1,000*/
