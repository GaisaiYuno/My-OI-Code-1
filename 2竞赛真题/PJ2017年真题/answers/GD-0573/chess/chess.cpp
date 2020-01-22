#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
int map[110][110],x[1110],y[1110],f[110][110];
int fx[4]={1,0,0,-1},fy[4]={0,1,-1,0};
queue<bool> qb;
queue<int> qx,qy,qd,pre;
int m,n,ans=0x7fff1fff;
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;++i){
		int xx,yy,c;
		cin>>xx>>yy>>c;
		map[xx][yy]=c+1;
	}
	qx.push(1),qy.push(1),qd.push(0);
	qb.push(1);
	for(register int i=1;i<=m;++i)for(register int j=1;j<=m;++j) f[i][j]=99999999;
	while(!qx.empty()){
		int x2=qx.front(),y2=qy.front(),d2=qd.front(),p2=pre.front();
		bool b2=qb.front();
		qx.pop(),qy.pop(),qb.pop(),qd.pop(),pre.pop();
		if(f[x2][y2]>d2)f[x2][y2]=d2;
		else continue;
		if(b2)
		for(int i=0;i<4;++i){
			int x3=x2+fx[i],y3=y2+fy[i];
			if(x3>m||y3>m||x3<1||y3<1) continue;
			if(map[x3][y3]&&map[x3][y3]==map[x2][y2]){
				qx.push(x3);
				qy.push(y3);
				qb.push(1);
				qd.push(d2);
				pre.push(map[x2][y2]);
			}
			if(map[x3][y3]&&map[x3][y3]!=map[x2][y2]){
				qx.push(x3);
				qy.push(y3);
				qb.push(1);
				qd.push(d2+1);
				pre.push(map[x2][y2]);
			}
			if(!map[x3][y3]&&b2){
				qx.push(x3);
				qy.push(y3);
				qb.push(0);
				qd.push(d2+2);
				pre.push(map[x2][y2]);
			}
		}
		else{
			for(int i=0;i<=3;++i){
				int x3=x2+fx[i],y3=y2+fy[i];
				if(!map[x3][y3]) continue;
				if(map[x3][y3]==p2&&d2<f[x3][y3]){
					qx.push(x3);
					qy.push(y3);
					qb.push(1);
					qd.push(d2);
					pre.push(map[x2][y2]);
				}
				if(map[x3][y3]&&d2+1<f[x3][y3]){
					qx.push(x3);
					qy.push(y3);
					qb.push(1);
					qd.push(d2+1);
					pre.push(map[x2][y2]);
				}
			}
		}
	}
	if(f[m][m]!=99999999)cout<<f[m][m];
	else cout<<-1;
	return 0;
}
