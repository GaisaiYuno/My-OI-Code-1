#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
#define INF 0x7f7f7f7f7f7f
using namespace std;
long long n,k,sum;
long long e[maxn],dp[maxn]; 
inline long long fread() {
	long long x=0,sign=1;
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
int head=0;
int tail=0;
struct node{
	long long value;
	int index;
}q[maxn];
void push(long long v /*int v*/,int i) {
	while(v<q[tail-1].value&&head<tail) tail--;
	q[tail].value=v;
	q[tail++].index=i;
}
void pop(int i){
	while(q[head].index<=i-k&&head<tail)head++;
}
int main(){
	cin>>n>>k;
	sum=0;
	for(int i=1;i<=n;i++){
	    e[i]=fread();
	    sum+=e[i];
	} 
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=k;i++){
    	dp[i]=0;
    	push(e[i],i);
    	cout<<e[i]<<endl;
	}
	for(int i=k+1;i<=n;i++){
		dp[i]=q[head].value;
		push(dp[i-1]+e[i],i);
		pop(i);
    }
	cout<<sum-dp[n]<<endl;
}

