#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
#define maxn 100005
using namespace std;
int n,m;
struct node{
	int id;
	long long price;
	long long left;
	friend bool operator < (node p,node q){
		if(p.price==q.price) return p.id<q.id;
		else return p.price<q.price;
	}
}a[maxn];
int get_pos[maxn];
int ptr=1;
long long query(int type,long long num){
	int fir=get_pos[type];
	long long sum=0;
	if(num<a[fir].left){
		a[fir].left-=num;
		return num*a[fir].price;
	}else{
		sum+=a[fir].left*a[fir].price;
		num-=a[fir].left;
		a[fir].left=0;
		while(ptr<=n){
			if(num<a[ptr].left){
				sum+=num*a[ptr].price;
				a[ptr].left-=num;
				num=0;
				break;
			}else{
				sum+=a[ptr].left*a[ptr].price;
				num-=a[ptr].left;
				a[ptr].left=0;
				ptr++;
			}
		}
		if(num!=0) return 0;
		else return sum;
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i].left);
	for(int i=1;i<=n;i++) scanf("%I64d",&a[i].price);
	for(int i=1;i<=n;i++) a[i].id=i;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		get_pos[a[i].id]=i;
	}
	int t,d;
	for(int i=1;i<=m;i++){
		scanf("%d %d",&t,&d);
		printf("%I64d\n",query(t,d));
	}
}

