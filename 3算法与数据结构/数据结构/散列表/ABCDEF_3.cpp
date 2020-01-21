
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map> 
#define maxn 100
using namespace std;
int n,m;
long long s[maxn+5];

const int c=133331;
struct myhash {
	struct node {
		long long v;
		long long cnt; 
		node* next;
	};
	node a[200005];
	void set0(){
		for(int i=0;i<maxn;i++){
			a[i].v=0;
			a[i].next=NULL;
		}
	}
	void push(long long x) {
		long long t;
		if(x<0) t=-x;
		else t=x;
		node *tmp=a[t%c].next;
		if(tmp==NULL){
			tmp=new node();
			tmp->v=x;
			tmp->cnt=1;
			tmp->next=NULL; 
			a[t%c].next=tmp;
			return;
		}
		while(tmp!=NULL){
			if(tmp->v==x){
				tmp->cnt++;
				return;
			} 
			tmp=tmp->next;
		}
		if(tmp==NULL){ 
			node *tmp=new node();
			tmp->v=x;
			tmp->cnt=1;
			tmp->next=a[t%c].next;
			a[t%c].next=tmp;
		} 
	}
	long long count(long long x) {
		long long t;
		if(x<0) t=-x;
		else t=x;
		if(a[t%c].next==NULL) return 0;
		else {
			node* tmp=a[t%c].next;
			while(tmp!=NULL) {
				if(tmp->v==x) return tmp->cnt;
				tmp=tmp->next;
			}
			return 0;
		}
	}
};
myhash num;
int main(){
	int l,r;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&s[i]);
	}
	num.set0();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				num.push(s[i]*s[j]+s[k]);
			}
		}
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]==0) continue;
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){ 
				ans+=num.count(s[i]*(s[j]+s[k]));
			}
		}
	}
	printf("%lld\n",ans);
} 
