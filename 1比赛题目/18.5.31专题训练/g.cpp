#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
struct data{
	int num;
	int cnt;
	int last_x;
	int last_y;
	int used;
	data(){
		
	}
	data(int numb,int count,int pre_x,int pre_y,int vis){
		num=numb;
		cnt=count;
		last_x=pre_x;
		last_y=pre_y;
		used=vis;
	}
};
data save[(1<<10)+5][1000+5];
struct status{
	int mod;
	int num;//10位状压用过的数字 
	status(){
		
	}
	status(int m,int d){
		mod=m;
		num=d;
	}
};
string bfs(int n,int m){
	queue<status>q;
	q.push(status(0,0));
	save[0][0]=data(0,0,-1,-1,1);
	while(!q.empty()){
		status now=q.front();
		q.pop();
		if(save[now.num][now.mod].cnt==m&&now.mod==0){
			string tmp;
			int xx=now.num;
			int yy=now.mod;
			while(save[xx][yy].last_x!=-1&&save[xx][yy].last_y!=-1){
				tmp+=(save[xx][yy].num+'0');
				int tx=xx;
				int ty=yy;
				xx=save[tx][ty].last_x;
				yy=save[tx][ty].last_y; 
			}
			reverse(tmp.begin(),tmp.end());
			return tmp;
		}
		for(int i=0;i<=9;i++){
			if(now.mod==0&&now.num==0&&i==0) continue;
			int mod=(now.mod*10+i)%n;
			int digit=now.num|(1<<i);
			if(save[digit][mod].used) continue;
			save[digit][mod]=data(i,save[now.num][now.mod].cnt+(!(now.num&(1<<i))),now.num,now.mod,1);
			if(save[digit][mod].cnt<=m) q.push(status(mod,digit)); 
		}
	} 
	return "Impossible";
}
string bignum_div(string a,int b){
	string ans;
	int i=0,sum=0;
	while(sum<b){
		sum=sum*10+a[i++]-'0';
	}
	ans+=sum/b+'0';
	while(i<a.length()){
		sum=(sum%b)*10+a[i++]-'0';
		ans+=sum/b+'0';
	} 
	return ans;
} 
int t,n,m;
int main(){
	scanf("%d",&t);
	while(t--){
		memset(save,0,sizeof(save));
		scanf("%d %d",&n,&m);
		string ans=bfs(n,m);
		if(ans=="Impossible") cout<<ans<<endl;
		else cout<<ans<<"="<<n<<"*"<<bignum_div(ans,n)<<endl;
	}
} 
