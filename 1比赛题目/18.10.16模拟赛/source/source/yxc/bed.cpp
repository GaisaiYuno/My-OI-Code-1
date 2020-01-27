#include<iostream>
#include<cstring>
#include<cstdio>
#define maxn 300005
using namespace std;
struct min_q{
	int qq[maxn];
	int head,tail;
	min_q(){head=0,tail=-1;}
	void push(int x){
		while(head<=tail&&x<qq[tail]) tail--;
		qq[++tail]=x;
	}
	void pop(int x){
		if(qq[head]==x) head++;
	}
	int front(){return qq[head];}
} Q1;
struct max_q{
	int qq[maxn];
	int head,tail;
	max_q(){head=0,tail=-1;}
	void push(int x){
		while(head<=tail&&x>qq[tail]) tail--;
		qq[++tail]=x;
	}
	void pop(int x){
		if(qq[head]==x) head++;
	}
	int front(){return qq[head];}
} Q2;
int A[maxn];
int main(){
	freopen("bed.in","r",stdin);
	freopen("bed.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&A[i]);
	int ans=1;
	int cnt=1;
	Q1.push(A[1]);
	Q2.push(A[1]);
	int len=1;
	while(cnt<n){
		if(Q2.front()-Q1.front()<=k){
			ans=max(ans,len);
			cnt++;
			len++;
			Q1.push(A[cnt]);
			Q2.push(A[cnt]);
		}
		else{
			Q1.pop(A[cnt-len+1]);
			Q2.pop(A[cnt-len+1]);
			len--;
		}
	}
	if(Q2.front()-Q1.front()<=k) ans=max(ans,len);
	printf("%d\n",ans);
}
