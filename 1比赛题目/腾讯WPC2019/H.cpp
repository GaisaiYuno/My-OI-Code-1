#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector> 
#define maxn 100
using namespace std;

int n,m,d;
typedef long double db;
vector<db> h[maxn+5],x[maxn+5];
db val[maxn+5][maxn+5];
db multiply(vector<db> &x,vector<db>& y){
	db ans=0;
	for(int i=0;i<x.size();i++){
		ans+=x[i]*y[i]; 
	}
	return ans;
}

db alpha(int t,int s){
	db up=val[t][s];
	db down=0;
	for(int ss=1;ss<=n;ss++) down+=val[t][ss];
	return up/down;
}

vector<db>ans;
int main(){
	db v;
	scanf("%d %d %d",&n,&m,&d);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=d;j++){
			scanf("%Lf",&v);
			x[i].push_back(v);	
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=d;j++){
			scanf("%Lf",&v);
			h[i].push_back(v);	
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			val[i][j]=exp(multiply(h[i],x[j]));
		}
	}
	for(int i=1;i<=m;i++){
		ans.resize(d);
		for(int j=0;j<d;j++) ans[j]=0;
		for(int j=1;j<=n;j++){
			db ats=alpha(i,j);
			for(int k=0;k<d;k++){
				ans[k]+=x[j][k]*ats;
			}
		}
		for(int j=0;j<=d-1;j++) printf("%.6Lf ",ans[j]);
//		printf("%.6lf",ans[d-1]);
		if(i!=m)printf("\n");
	}
}

