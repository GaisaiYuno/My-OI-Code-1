#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#define MAXN 255
using namespace std;
struct nd{
	int W,T;
};
bool operator < (const nd &A,const nd &B){
	return (A.T*B.W)>(A.W*B.T);
}
nd num[MAXN];
int minw,maxans,n;
struct node{
	int sumw,sumt;
	int used;
};
bool operator < (const node &A,const node &B){
	return (A.sumt*B.sumw)<(A.sumw*B.sumt);
}
int lastans;
int cnt;
void bfs(){
	priority_queue<node>Q;
	node temp;
	temp.sumt=temp.sumw=0;
	temp.used=0;
	Q.push(temp);
	while (Q.size()){
		node fa=Q.top();
		Q.pop();
		if (fa.sumw>=minw){
//			lastans=maxans;
			maxans=max(maxans,1000*fa.sumt/fa.sumw);
			cnt++;
			if (cnt==n*500){
				printf("%d\n",maxans);
				exit(0);
			}
		}
		if (fa.used==n){
			continue;
		}
		node ch;
		ch.sumt=fa.sumt+num[fa.used+1].T;
		ch.sumw=fa.sumw+num[fa.used+1].W;
		ch.used=fa.used+1;
		Q.push(ch);
		ch.sumt-=num[fa.used+1].T;
		ch.sumw-=num[fa.used+1].W;
		Q.push(ch);
	}
}
//void dfs(int sumw,int sumt,int i){
////	printf("%d %d %d\n",sumw,sumt,i);
//	if (i==n+1){
//		printf("%d %d\n",sumw,sumt);
//		maxans=max(maxans,1000*sumt/sumw);
//		return ;
//	}
//	dfs(sumw,sumt,i+1);
//	dfs(sumw+W[i],sumt+T[i],i+1);
//}
int main(){
	freopen("talent.in","r",stdin);
	freopen("talent.out","w",stdout);
	scanf("%d%d",&n,&minw);
	for (register int i=1;i<=n;++i){
		scanf("%d%d",&num[i].W,&num[i].T);
	}
//	sort(num+1,num+1+n);
	maxans=0;
	bfs();
	printf("%d\n",maxans);
}
