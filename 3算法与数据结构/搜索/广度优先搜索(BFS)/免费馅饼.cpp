//HDU 1176 
//正解为dp,在动态规划文件夹里 
#include<iostream>
#include<cstring>
#include<queue>
#define maxn 100005 
using namespace std;
int n,x,t,maxt;
int pie[11][maxn];
struct node{
	int x;
	int t;
	int cnt;
	friend bool operator <(node a,node b){
		return a.t<b.t; 
	}
};
priority_queue<node>q;
node now,nex;
const int walkx[3]={1,-1,0};
inline int fread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar(); 
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
int bfs(){
	int ans=0;
	while(!q.empty()) q.pop();
	now.x=5;
	now.t=0;
	now.cnt=0;
	q.push(now);
	while(!q.empty()){
		now=q.top();
		q.pop();
		if(now.t>maxt){
			if(now.cnt>ans) ans=now.cnt;
			break;
		}
		for(int i=0;i<3;i++){
			nex.x=now.x+walkx[i];
			nex.t=now.t+1;
			if(nex.x<0||nex.x>10) continue;
			if(pie[nex.x][nex.t]>0) nex.cnt=now.cnt+pie[nex.x][nex.t];
			else nex.cnt=now.cnt;
			//printf("%d t=%d num=%d %d\n",nex.x,nex.t,nex.cnt,pie[nex.x][nex.t]?1:0);
			q.push(nex);
		}
	}
	return ans;
}
int main(){
	while(cin>>n&&n!=0){
		memset(pie,0,sizeof(pie));
		maxt=0;
		while(n--){
			x=fread();
			t=fread();
			pie[x][t]++;//同一秒钟在同一点上可能掉下多个馅饼
			if(t>maxt) maxt=t;
		}
		cout<<bfs()<<endl;
	}
}
