//洛谷 【模板】并查集
//路径压缩优化 O(1) 
//洛谷 772ms 
#include<iostream>
#define maxn 10005
using namespace std;
int n,m;
int a[maxn];
int FIND(int x){
	if(a[x]==x){
		return x; 
	} 
	else a[x]=FIND(a[x]);//路径压缩的关键 
	return a[x];
}
void UNION(int x,int y){
	int fx=FIND(x);
	int fy=FIND(y);
	a[fx]=fy;
}
int main(){
	int x,y,z; 
	cin>>n>>m;
	for(int i=1;i<=n;i++) a[i]=i;
	for(int i=1;i<=m;i++){
		cin>>z>>x>>y;
		if(z==1) UNION(x,y);
		if(z==2){
			if(FIND(x)==FIND(y)) cout<<"Y\n";
			else cout<<"N\n"; 
		}
	}
	return 0;
}
