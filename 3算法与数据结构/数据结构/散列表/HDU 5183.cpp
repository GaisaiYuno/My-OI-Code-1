#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1000005
#define INF 0x7f7f7f7f7f
using namespace std;
inline int fread() {
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
int t,n,k;
int num[maxn];
const int c=1000007;
struct hashtable {
	struct node {
		long long v;
		node* next;
	};
	node a[c];//哈希表
	void init() {
		for(int i=0; i<c; i++) {
			a[i].v=INF;
			a[i].next=NULL;
		}
	}
	void push(long long x) {
		long long t;
		if(x<0) t=-x;
		else t=x;
		if(a[t%c].v==INF) {
			a[t%c].v=x;
		} else {
			node *tmp=new node();
			tmp->v=x;
			tmp->next=a[t%c].next;//此处相当于head
			a[t%c].next=tmp;
		}
	}
	int is_found(long long x) {
		long long t;
		if(x<0) t=-x;
		else t=x;
		if(a[t%c].v==x) return 1;
		if(a[t%c].v==INF) return 0;
		else {
			node* tmp=a[t%c].next;
			while(tmp!=NULL) {
				if(tmp->v==x) return 1;
				tmp=tmp->next;
			}
			return 0;
		}
	}
};
hashtable h1,h2;
int main() {
	long long sum;
	cin>>t;
	for(int u=1; u<=t; u++) {
		bool flag=false;
		sum=0;
		cin>>n>>k;
		for(int i=0; i<n; i++) num[i]=fread();
		h1.init();
		h2.init();
		h1.push(0);
		h2.push(0);
		for(int i=n-1; i>=0; i--) {
			if(i%2==1) sum-=num[i];  //i%2==1
			else sum+=num[i];
			if(i%2==0) {
				if(h1.is_found(sum-k)) flag=1;
			} else {
				if(h1.is_found(sum+k)) flag=1;
			}
			h1.push(sum);
			h2.push(-sum);
			if(flag) break;
		}
		printf("Case #%d: ",u);
		if(flag) cout<<"Yes."<<endl;
		else cout<<"No."<<endl;
	}
	return 0;
}






