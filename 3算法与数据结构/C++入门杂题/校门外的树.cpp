//洛谷 校门外的树
#include<iostream>
#define maxn 10000
#define maxm 1000
using namespace std;
int tree[maxn];
struct node{
	int s;
	int e;
}move[maxm];
int l,m,ans=0;
int main(){
	cin>>l>>m;
	for(int i=1;i<=m;i++) {
		cin>>move[i].s>>move[i].e;
		for(int j=move[i].s;j<=move[i].e;j++){
			if(tree[j]==0) tree[j]=1;
		}
	}
	for(int i=0;i<=l;i++) {
		if(tree[i]==0) ans++;
	}
	cout<<ans;
	return 0;
} 
