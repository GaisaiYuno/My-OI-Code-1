//seat
#include<iostream>
#include<cstdio>
#include<algorithm> 
#define maxd 2005 
#define maxn 1005
using namespace std;
int m,n,k,l,d;
struct stu{
	int x;
	int y;
	int p;
	int q;
}a[maxd];
struct row{
	int num;//每条过道分开的学生数
	int pos;//位置 
}b1[maxn],b2[maxn];
int comp1(row u,row v){//按分开学生数排序 
	return u.num>v.num; 
}
int comp2(row u,row v){
	return u.pos<v.pos;
}
int main(){
	int i,temp;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n>>k>>l>>d;
	for(i=0;i<d;i++){
		cin>>a[i].x>>a[i].y>>a[i].p>>a[i].q;
	}
	for(i=0;i<d;i++){
		if(a[i].x==a[i].p) {//同一列 
		   temp=min(a[i].y,a[i].q);
		   b1[temp].num++;
		   b1[temp].pos=temp;
		} 
		if(a[i].y==a[i].q) {//同一行 
		   temp=min(a[i].x,a[i].p);
		   b2[temp].num++;
		   b2[temp].pos=temp;
		} 
	}
	sort(b1+1,b1+1+n,comp1);
	sort(b2+1,b2+1+m,comp1);
	sort(b1+1,b1+1+l,comp2);
	sort(b2+1,b2+1+k,comp2);
	for(i=1;i<=k;i++){
		if(b2[i].num!=0) {
			cout<<b2[i].pos;
			if(i!=k) cout<<' ';//防止行尾有空格 
		} 
	}
	cout<<endl;
	for(i=1;i<=l;i++){
		if(b1[i].num!=0) {
			cout<<b1[i].pos;
			if(i!=l) cout<<' ';
		} 
	}
	return 0;
}
