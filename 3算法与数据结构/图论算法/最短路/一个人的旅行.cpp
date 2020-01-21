#include<iostream>
#include<cstring>
#define maxn 1005
#define INF 2139062143
using namespace std;
int ans=10000000;
int l[maxn][maxn];
int f[maxn];
int used[maxn];
int con[maxn];
int want[maxn];
int t,s,d,n=0;
/*void debug(int n,string name) {
	if(name=="f") {
		cout<<name<<":"; 
		for(int i=1; i<=n; i++) cout<<f[i]<<' ';
		cout<<endl;
	}
	if(name=="l") {
		cout<<name<<":"<<endl; 
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) cout<<l[i][j]<<' ';
			cout<<endl;
		}
	}
	if(name=="want"){
		cout<<name<<":"; 
		for(int i=1; i<=n; i++) cout<<want[i]<<' ';
		cout<<endl;
	} 
	if(name=="con"){
		cout<<name<<":"; 
		for(int i=1; i<=n; i++) cout<<con[i]<<' ';
		cout<<endl;
	}
}*/
inline int fastread() {
	int x=0,sign=1,c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
void dijkstra(int start) {
	int i,j,k,x;
	for(i=1; i<=n; i++) {
		if(i==start) f[i]=0;
		else if(l[start][i]!=INF) f[i]=l[start][i];
	}
	used[start]=1;
	for(i=1; i<n-1; i++) {
		x=INF;
		k=0;
		for(j=1; j<=n; j++) {
			if(used[j]==0&&f[j]<x&&f[j]!=-1) {
				x=f[j];
				k=j;
			}
		}
		if(k==0) continue;
		used[k]=1;
		for(j=1; j<=n; j++) {
			if(used[j]==0&&l[j][k]!=INF) { //一定要判断l[j][k]!=0
				if(f[j]==-1) f[j]=f[k]+l[k][j];
				else f[j]=min(f[k]+l[k][j],f[j]);
			}
		}
	}
}
int main() {
	while(cin>>t>>s>>d) {
		int i,j,a,b,time;
		memset(l,0x7f,sizeof(l));
		memset(f,-1,sizeof(f));
		memset(used,0,sizeof(used));
		memset(con,0,sizeof(con));
		memset(want,0,sizeof(want));
		for(i=1; i<=t; i++) {
			a=fastread();
			b=fastread();
			time=fastread();
			if(time<l[a][b])l[a][b]=l[b][a]=time;
			if(n<a) n=a;//算出节点数 
			if(n<b) n=b;
		}
		for(i=1; i<=s; i++) con[i]=fastread();
		for(i=1; i<=d; i++) want[i]=fastread();
		for(i=1; i<=s; i++) {
			dijkstra(con[i]);
			int tmp=INF;
			for(j=1; j<=d; j++) {
				if(f[want[j]]!=-1) tmp=min(tmp,f[want[j]]);
				//cout<<f[want[j]]<<endl;
			}
			ans=min(ans,tmp);
			memset(f,-1,sizeof(f));
			memset(used,0,sizeof(used));
			//cout<<i<<" "<<s<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}
