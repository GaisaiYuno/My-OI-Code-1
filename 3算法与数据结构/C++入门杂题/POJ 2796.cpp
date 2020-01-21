#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#define maxn 200005
using namespace std;
int n;
struct node {
	int x;
	int id;
	node() {

	}
	node(int value,int pos) {
		x=value;
		id=pos;
	}
};
stack<node>s;
int a[maxn];
int lbound[maxn],rbound[maxn];
long long sum[maxn];
void ini(){
	memset(sum,0,sizeof(sum));
	memset(a,0,sizeof(a));
	memset(lbound,0,sizeof(lbound));
	memset(rbound,0,sizeof(rbound));
	while(!s.empty()) s.pop();
}
int main() {
	while(scanf("%d",&n)!=EOF) {
		ini();
		for(int i=1; i<=n; i++) {
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}
		for(int i=1; i<=n; i++) {
			while(!s.empty()) {
				node now=s.top();
				if(now.x>a[i]) {
					s.pop();
					rbound[now.id]=i-1;
				} else break;
			}
			if(!s.empty()) {
				lbound[i]=s.top().id+1;
			} else lbound[i]=1;
			s.push(node(a[i],i));
		}
		while(!s.empty()) {
			node now=s.top();
			s.pop();
			rbound[now.id]=n;
		}
		long long ans=-1;
		int ansl,ansr;
		for(int i=1; i<=n; i++) {
			if(a[i]*(sum[rbound[i]]-sum[lbound[i]-1])>ans) {
				ans=a[i]*(sum[rbound[i]]-sum[lbound[i]-1]);
				ansl=lbound[i];
				ansr=rbound[i];
			}
		}
		cout<<ans<<endl<<ansl<<' '<<ansr<<endl;
	}
}
