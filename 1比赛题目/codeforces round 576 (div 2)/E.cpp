#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 100000
using namespace std;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	} 
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(int x){
	if(x<0){
		putchar('-');
		qprint(-x); 
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x>=10) qprint(x/10);
		putchar('0'+x%10); 
	}
} 
int t;
int n,m;
vector<int>match;
vector<int>ind_set; 
int vis[maxn*3+5];
void ini(){
	match.clear();
	ind_set.clear();
	for(int i=1;i<=n*3;i++) vis[i]=0;
} 
int main(){
	int u,v;
	qread(t);
	while(t--){
		qread(n);
		qread(m);
		ini();
		for(int i=1;i<=m;i++){
			qread(u);
			qread(v);
			if(!vis[u]&&!vis[v]){
				match.push_back(i);
				vis[u]=1;
				vis[v]=1;
			} 
		}
		for(int i=1;i<=n*3;i++) if(!vis[i]) ind_set.push_back(i);
		if(match.size()>=n){
			puts("Matching");
			for(int i=0;i<n;i++){
				qprint(match[i]);
				putchar(' ');
			}
			putchar('\n'); 
		}else if(ind_set.size()>=n){
			puts("IndSet");
			for(int i=0;i<n;i++){
				qprint(ind_set[i]);
				putchar(' ');
			}
			putchar('\n');
		}else{
			puts("Impossible");
		} 
	}
}

