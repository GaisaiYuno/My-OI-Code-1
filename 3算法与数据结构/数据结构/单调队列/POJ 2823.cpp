// Vjudge Sliding Window(POJ 2823)
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000005
#define INF 0x7f7f7f7f
using namespace std;
int n,k;
int a[maxn];
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
struct node {
	int value;
	int index;
};
node q1[maxn], q2[maxn];
int head1,head2,tail1,tail2;
int ans1[maxn],ans2[maxn];
void push1(int v,int i) {
	while(v>q1[tail1-1].value&&head1<tail1) tail1--;
	q1[tail1].index=i;
	q1[tail1++].value=v;
}
void push2(int v,int i) {
	while(v<q2[tail2-1].value&&head2<tail2) tail2--;
	q2[tail2].index=i;
	q2[tail2++].value=v;
}
int main() {
	int mina,maxa;
	mina=INF;
	maxa=-INF;
	while(cin>>n>>k) {
		head1=head2=tail1=tail2=0;
		memset(q1,0,sizeof(q1));
		memset(q2,0,sizeof(q2));
		for(int i=0; i<n; i++) a[i]=fread();
		for(int i=0; i<n; i++) {
			push1(a[i],i);
			while(i-q1[head1].index>=k&&head1<tail1) head1++;
			ans1[i]=q1[head1].value;
			
			push2(a[i],i);
			while(i-q2[head2].index>=k&&head2<tail2) head2++;
			ans2[i]=q2[head2].value;
			//debug();
		}
		for(int i=k-1;i<n;i++) {
			if(i!=k-1) cout<<' ';
			cout<<ans2[i];
		}
		cout<<endl;
		for(int i=k-1;i<n;i++) {
			if(i!=k-1) cout<<' ';
			cout<<ans1[i];
		}
		cout<<endl;
	}
}
