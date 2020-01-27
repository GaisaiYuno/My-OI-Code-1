#include<iostream>
#include<cstdio>
#define maxn 1000005
using namespace std;
struct node{
	int ans;
	int id;
}q[maxn]; 
int n,a,b;
int head,tail;
int main(){
	long long ans=1;
	long long s=1;
	while(scanf("%d %d %d",&n,&a,&b)!=EOF){
		head=tail=1;
		ans=s=1;
		for(int i=1;i<=n;i++){
			s=(s*a)%b;
			while(head<=tail&&q[tail-1].ans>s) tail--;
			q[tail].ans=s;
			q[tail++].id=i;
			while(head<=tail&&q[head].id+a<i) head++;
			ans=q[head].ans%b*ans;
			ans%=b;
		}
		printf("%I64d\n",ans);
	}
}
