#include<iostream>
#include<cstdio>
#include<cstring> 
#include<vector>
#include<algorithm>
#include<cmath>
#define maxn 2500
using namespace std;
typedef long long ll;
int n;
struct Vector{
	ll x;
	ll y;
	Vector(){
		
	}
	Vector(ll _x,ll _y){
		x=_x;
		y=_y;
	}
	friend Vector operator + (Vector p,Vector q){
		return Vector(p.x+q.x,p.y+q.y);
	} 
	friend Vector operator - (Vector p,Vector q){
		return Vector(p.x-q.x,p.y-q.y);
	}
	pair<ll,ll> to_pair(){
		return make_pair(x,y);
	} 
	void print(){
		printf("%I64d %I64d\n",x,y);
	}
}a[maxn+5];
ll dot(Vector p,Vector q){
	return p.x*q.x+p.y*q.y;
}
ll cross(Vector p,Vector q){
	return p.x*q.y-p.y*q.x;
}
bool cmp(Vector p,Vector q){
//	ll x=cross(p,q);
//	if(x==0) return dot(p,p)<dot(q,q);
//	else return x>0;
	bool f1=p.to_pair()<make_pair(0ll,0ll);
	bool f2=q.to_pair()<make_pair(0ll,0ll);
	if(f1!=f2) return f1<f2;
	return cross(p,q)>0;
}

ll C(int n,int m){
	ll ans=1;
	for(int i=0;i<m;i++){
		ans*=(n-i);
		ans/=(i+1);
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%I64d %I64d",&a[i].x,&a[i].y);
	ll sum=0;
	for(int i=1;i<=n;i++){
		vector<Vector>v;
		for(int j=1;j<=n;j++){
			if(i!=j) v.push_back(a[j]-a[i]);
		}
		sort(v.begin(),v.end(),cmp);
//		for(auto pt : v) pt.print();
//		printf("----\n");
		int rb=0;
		for(int j=0;j<(int)v.size();j++){
			while(rb<j+v.size()&&cross(v[j],v[rb%v.size()])>=0) rb++;
			sum+=C(rb-j-1,3);
//			printf("p=%d\n",rb);
		}
	}
	printf("%I64d\n",5*C(n,5)-sum);
}
/*
8
0 0
0 1
1 0
1 1
2 4
4 2
6 4
4 6
*/
