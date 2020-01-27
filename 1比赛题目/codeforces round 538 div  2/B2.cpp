#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
#define maxn 200005
using namespace std;
typedef long long ll;
int n,m,k;
struct node{
	int x;
	int id;	
}a[maxn];
int mark[maxn];
int cmp(node a,node b){
	return a.x>b.x;
}
vector<int>res;
map<int,int>cnt;
int main(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].x);
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	ll ans=0;
	for(int i=1;i<=m*k;i++){
		ans+=a[i].x;
		mark[a[i].id]=1;
	}
	int ptr=1;
	for(int i=1;i<k;i++){
		int len=0;
		while(ptr<=n){
			if(mark[ptr]){
				len++;
			}
			if(len==m) break;
			ptr++;
		}
		res.push_back(ptr);
		ptr++; 
	}
	printf("%lld\n",ans);
	for(int x : res){
		printf("%d ",x);
	}
}


