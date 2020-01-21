//HDU 3530
#include<iostream>
#include<cstdio>
#include<cmath>
#define ForMyLove return 0;
#define maxn 1000005
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
int n,m,k;
int a[maxn],qmin[maxn],qmax[maxn];
int head1,tail1,head2,tail2;
int front,back;
int ans,now;
int maxa,mina;
void push1(int x){
	while(head1<tail1&&qmin[tail1-1]>x)tail1--;
	qmin[tail1++]=x;
} 
void push2(int x){
	 while(head2<tail2&&qmax[tail2-1]<x)tail2--;
	qmax[tail2++]=x;
}
int main() {
	while(cin>>n>>m>>k) {
		head1=tail1=head2=tail2=0;
		front=back=0;
		ans=0;
		maxa=mina=0;
		for(int i=1; i<=n; i++) a[i]=fread();
		while(front<=n) {
			if(maxa-mina<=k) {
				if(maxa-mina>=m) {
					ans=max(ans,abs(back-front));
				}
				front++;
				push1(a[front]);
				push2(a[front]);
				mina=qmin[head1];
				maxa=qmax[head2];
			}
			else{
				back++;
				if(qmin[head1]==a[back]){
					head1++;
					mina=qmin[head1];
				} 
				if(qmax[head2]==a[back]){
					head2++;
					maxa=qmax[head2];
				} 
			}
		}
		cout<<ans<<endl;
	}
	ForMyLove
}
