#include <bits/stdc++.h>
using namespace std;
long long dx[4]={1,-1,0,0};
long long dy[4]={0,0,1,-1};
long long m,n,mp=0; 
long long a[1050][1050]={0};
long long sum=0,ans=100000000;
void dfs(long x,long y){
	int q=0;
	if(x==m&&y==m){
		ans=min(ans,sum);
	    return;
	}
	if(a[x+dx[1]][y+dy[1]]&&x+dx[1]<=m){
		if(a[x+dx[1]][y+dy[1]]&&a[x][y]){
		if(a[x+dx[1]][y+dy[1]]==a[x][y]){if(mp)mp=0,q=1;  dfs(x+dx[1],y+dy[1]);if(q)mp=1;q=0;}
		else {
			if(mp)mp=0,q=1;
			sum+=1;
			dfs(x+dx[1],y+dy[1]);
			sum-=1;
			if(q)mp=1;
			q=0;
		}}
	}else {
		if(!mp&&x+dx[1]<=m){
			mp=1;
			sum+=2;
			dfs(x+dx[1],y+dy[1]);
			sum-=2;
			mp=0;
			}
	}
	//////////////
		if(a[x+dx[2]][y+dy[2]]&&x+dx[2]>=1){
			if(a[x+dx[2]][y+dy[2]]&&a[x][y]){
		if(a[x+dx[2]][y+dy[2]]==a[x][y]){if(mp)mp=0,q=1;  dfs(x+dx[2],y+dy[2]);if(q)mp=1;q=0;}
		else {
			if(mp)mp=0;
			sum++;
			dfs(x+dx[2],y+dy[2]);
			sum--;
			if(q)mp=1;
			q=0;
		}}
	}else {
		if(!mp&&x+dx[2]>=1){
			mp=1;
			sum+=2;
			dfs(x+dx[2],y+dy[2]);
			sum-=2;
			mp=0;
		}
	}
	///////////////		
	    if(a[x+dx[3]][y+dy[3]]&&y+dy[3]<=m){
	    	if(a[x+dx[3]][y+dy[3]]&&a[x][y]){
		if(a[x+dx[3]][y+dy[3]]==a[x][y]){if(mp)mp=0,q=1;  dfs(x+dx[3],y+dy[3]);if(q)mp=1;q=0;}
		else {
			if(mp)mp=0,q=1;
			sum++;
			dfs(x+dx[3],y+dy[3]);
			sum--;
			if(q)mp=1;
			q=0;
		}}
	}else {
		if(!mp&&y+dy[3]<=m){
			mp=1;
			sum+=2;
			dfs(x+dx[3],y+dy[3]);
			sum-=2;
			mp=0;
		}
	}
	///////////////////
		if(a[x][y-1]&&y-1>=1){
			if(a[x][y-1]&&a[x][y]){
		if(a[x][y-1]==a[x][y]){if(mp)mp=0,q=1;  dfs(x,y-1);if(q)mp=1;q=0;}
		else {
			if(mp)mp=0,q=1;
			sum++;
			dfs(x,y-1);
			sum--;
			if(q)mp=1;
			q=0;
		}}
	}else {
		if(!mp&&y+dy[4]>=1){
			mp=1;
			sum+=2;
			dfs(x,y-1);
			sum-=2;
			mp=0;
		}
	}
	return;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chee.out","w",stdout);
	cin>>m>>n;
	long long bb,b,c,i;
	for(i=1;i<=n;i++){
		cin>>bb>>b>>c;
		a[bb][b]=c;
	}
	dfs(1,1);
	if(ans==100000000)cout<<-1<<endl;
	else cout<<ans<<endl;
	return 0; 
}