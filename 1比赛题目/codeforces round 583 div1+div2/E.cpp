#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define maxn 100000
using namespace std;
int n;
struct node{
	int val;
	int id;
	friend bool operator < (node p,node q){
		if(p.val==q.val) return p.id<q.id;
		else return p.val>q.val;
	}
}a[maxn+5]; 
vector<int>seq;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].val);
		a[i].id=i*2-1;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) seq.push_back(a[i].id);
	for(int i=1;i<n;i++){
		printf("%d %d\n",a[i].id,a[i+1].id);
	}
	for(int i=1;i<=n;i++){
		int from=i+a[i].val-1;
		printf("%d %d\n",seq[from-1],a[i].id+1);
		if(from-1==(int)seq.size()-1) seq.push_back(a[i].id+1);
	}
}

