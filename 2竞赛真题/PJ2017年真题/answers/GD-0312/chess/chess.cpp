#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int,bool> p1;
typedef pair<int,int> p2;
typedef pair<p1,p2> p3;
const int way[4][2]={{-1,0},{0,-1},{1,0},{0,1}};
int m,n,a[110][110]={0},f[110][110]={0};
bool chec[110][110]={false};
priority_queue<p3,vector<p3>,greater<p3> >q;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	while(!q.empty())
		q.pop();
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		a[x][y]=c+1;
	}
	chec[1][1]=true;
	q.push(make_pair(make_pair(0,true),make_pair(1,1)));
	while(!q.empty()){
		p3 p=q.top();
		p1 _p1=p.first;
		p2 _p2=p.second;
		int fr1=_p2.first,fr2=_p2.second;
		q.pop();
		if(fr1==m&&fr2==m){
			printf("%d\n",f[fr1][fr2]);
			fclose(stdin);
			fclose(stdout);
			return 0;
		}
		for(int k=0;k<4;k++){
			int to1=fr1+way[k][0],to2=fr2+way[k][1];
			if(to1<1||to1>m||to2<1||to2>m)
				continue;
			if(a[to1][to2]){
				int added=(a[to1][to2]!=a[fr1][fr2]);
				if(a[fr1][fr2]==3)
					added=0;
				if(!chec[to1][to2]){
					f[to1][to2]=f[fr1][fr2]+added;
					chec[to1][to2]=true;
					q.push(make_pair(make_pair(f[to1][to2],true),make_pair(to1,to2)));
				}
			}
			else{
				if(_p1.second==false)
					continue;
				if(chec[to1][to2]){
					if(f[to1][to2]==f[fr1][fr2]+2&&a[to1][to2]!=3&&a[fr1][fr2]!=a[to1][to2])
						a[to1][to2]=3;
				}
				else{
					f[to1][to2]=f[fr1][fr2]+2;
					a[to1][to2]=a[fr1][fr2];
					chec[to1][to2]=true;
					q.push(make_pair(make_pair(f[to1][to2],false),make_pair(to1,to2)));
				}
			}
		}
		if(_p1.second==false)
			a[fr1][fr2]=0;
	}
	puts("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
