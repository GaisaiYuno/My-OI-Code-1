//洛谷 【模板】并查集
//无优化 O(n) 
//会TLE 洛谷 5728ms 
#include<iostream>
#define maxn 10005
using namespace std;
int n,m;
int a[maxn];
int FIND(int x){
	if(a[x]==x) return x;
	else FIND(a[x]);
}
void UNION(int x,int y){
	a[x]=y;
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
