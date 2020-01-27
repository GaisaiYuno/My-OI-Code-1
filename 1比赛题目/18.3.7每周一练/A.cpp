#include<iostream>
#include<cstring>
#include<cstdio>
#define MAXN 505
using namespace std;
int n,k;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	} 
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar(); 
	}
	return x*sign;
}
int l[MAXN];
int r[MAXN];
int light[MAXN*2],heavy[MAXN*2];
int main(){
	while(cin>>n>>k){
		memset(light,0,sizeof(light));
		memset(heavy,0,sizeof(heavy));
		int t;
		char b;
		int not_eqal=0;
		while(k--){
			t=qread();
			for(int i=1;i<=t;i++) l[i]=qread();
			for(int i=1;i<=t;i++) r[i]=qread();
			cin>>b;
			if(b=='='){
				for(int i=1;i<=t;i++){
					light[l[i]]=heavy[l[i]]=-1;
					light[r[i]]=heavy[r[i]]=-1;
				}
			} else if(b=='<'){
				not_eqal++;
				for(int i=1;i<=t;i++){
					if(light[l[i]]!=-1) light[l[i]]++;
					if(light[r[i]]!=-1) heavy[r[i]]++;
				}
			}else if(b=='>'){
				not_eqal++;
				for(int i=1;i<=t;i++){
					if(light[l[i]]!=-1) heavy[l[i]]++;
					if(light[r[i]]!=-1) light[r[i]]++;
				} 
			}
		}
		int ans=0,tmp=0;
		for(int i=1;i<=n;i++){
			if(light[i]==not_eqal||heavy[i]==not_eqal){
				ans=i;
				tmp++;
			}
			if(tmp>=2) break;
		}
		if(tmp!=1) ans=0;
		cout<<ans<<endl;
	}
}
