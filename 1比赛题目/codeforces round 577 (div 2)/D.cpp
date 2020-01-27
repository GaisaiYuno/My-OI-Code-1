#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 200000 
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n,m,k,q;
vector<int>a[maxn+5];
int lb[maxn+5],rb[maxn+5];
int col[maxn+5]; 
ll dp[maxn+5][2];//�ߵ������/���Ҳ���� 
ll calc(int y1,int y2,int line){
	return (ll)abs(y1-line)+abs(y2-line);
}
ll dist(int x1,int y1,int x2,int y2){
	ll distx=abs(x1-x2);
	ll disty=min(min(calc(y1,y2,lb[y1]),calc(y1,y2,lb[y2])),min(calc(y1,y2,rb[y1]),calc(y1,y2,rb[y2])));
	return distx+disty;
}
int main(){
	int x,y;
	scanf("%d %d %d %d",&n,&m,&k,&q);
	for(int i=1;i<=k;i++){
		scanf("%d %d",&x,&y);
		a[x].push_back(y); 
	}
	for(int i=1;i<=q;i++){
		scanf("%d",&col[i]);
	}
	sort(col+1,col+1+q);
	col[0]=-INF;
	col[q+1]=INF;
	for(int i=1;i<=m;i++){
		lb[i]=col[lower_bound(col+1,col+1+q,i)-col-1];
		rb[i]=col[lower_bound(col+1,col+1+q,i)-col];
	} 
	
	sort(a[1].begin(),a[1].end());
	if(!a[1].empty()){
		dp[1][0]=dp[1][1]=a[1].back()-1;
		a[1][0]=a[1].back();
		//��һ�б�������һ���ؼ��������ߣ�������߲������йؼ��� 
	}else{
		a[1].push_back(1);
		dp[1][0]=dp[1][1]=0;
	}
	int last=1;
	for(int i=2;i<=n;i++){
		if(!a[i].empty()){
			sort(a[i].begin(),a[i].end());
			ll l_to_l=dp[last][0]+dist(last,a[last].front(),i,a[i].front());
			ll r_to_l=dp[last][1]+dist(last,a[last].back(),i,a[i].front()); 
			ll l_to_r=dp[last][0]+dist(last,a[last].front(),i,a[i].back());
			ll r_to_r=dp[last][1]+dist(last,a[last].back(),i,a[i].back());
			ll now=a[i].back()-a[i].front();//���굱ǰ�еĴ��� 
			dp[i][0]=min(l_to_r,r_to_r)+now;//���ߵ����Ҳ࣬�ٻص���� 
			dp[i][1]=min(l_to_l,r_to_l)+now;
			last=i;
		}
	} 
	printf("%I64d\n",min(dp[last][0],dp[last][1]));
	
}

