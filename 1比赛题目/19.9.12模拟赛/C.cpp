#include<iostream>
#include<cstdio>
#include<set>
#include<map>
#define maxn 500000
using namespace std;
typedef long long ll;
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

ll ans=0;
int n,m,k;
map<int,ll>a[maxn+5];
map<int,ll>tmp;
pair<int,int>oper[maxn+5];
pair<int,int>seq[maxn+5];
void merge(int x,int y){
	for(int i=1;i<=k;i++){
		int p=seq[i].first;
		int q=seq[i].second;
		if(a[x].count(p)&&a[y].count(q)){
			if(a[x][p]==0||a[y][q]==0) continue;
			if(a[x][p]<a[y][q]){
				a[y][q]-=a[x][p];
				ans+=a[x][p]*2;
				a[x][p]=0;
			}else{
				a[x][p]-=a[y][q];
				ans+=a[y][q]*2;
				a[y][q]=0;
			}
		}else if(a[x].count(q)&&a[y].count(p)){
			swap(p,q);
			if(a[x][p]==0||a[y][q]==0) continue;
			if(a[x][p]<a[y][q]){
				a[y][q]-=a[x][p];
				ans+=a[x][p]*2;
				a[x][p]=0;
			}else{
				a[x][p]-=a[y][q];
				ans+=a[y][q]*2;
				a[y][q]=0;
			}
		}
	}
	for(map<int,ll>::iterator it=a[x].begin();it!=a[x].end();it++){
		if(it->second!=0) tmp[it->first]+=it->second;
	}
	for(map<int,ll>::iterator it=a[y].begin();it!=a[y].end();it++){
		if(it->second!=0) tmp[it->first]+=it->second;
	}
	a[x].clear();
	a[y].clear();
	for(map<int,ll>::iterator it=tmp.begin();it!=tmp.end();it++){
		a[y][it->first]=it->second;
	}
	tmp.clear();
}
int main(){
	int x;
	qread(n);
	qread(m);
	qread(k);
	for(int i=1;i<=n;i++){
		qread(x);
		a[i][i]=x;
	}
	for(int i=1;i<=m;i++){
		qread(oper[i].first);
		qread(oper[i].second);
	}
	for(int i=1;i<=k;i++){
		qread(seq[i].first);
		qread(seq[i].second);
	}
	for(int i=1;i<=m;i++){
		merge(oper[i].first,oper[i].second);
	}
	printf("%lld\n",ans);
}
