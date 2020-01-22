#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

struct squ{
	int clr,xpos,ypos,tot;
	bool mgc;
	squ():clr(0),xpos(0),ypos(0),tot(0),mgc(false){}
	squ(int c,int x,int y,int t,bool m):clr(c),xpos(x),ypos(y),tot(t),mgc(m){}
	friend bool operator<(const squ& dt1,const squ& dt2){
		if(dt1.tot==dt2.tot)return dt1.xpos+dt1.ypos>dt2.xpos+dt2.ypos;
		return dt1.tot>dt2.tot;
	}
};

priority_queue<squ> q;
int m,n,x,y,c,a[101][101];
bool vst[101][101];

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d%d",&x,&y,&c);
		a[x][y]=c+1;
	}
	q.push(squ(a[1][1],1,1,0,false));
	while(!q.empty()){
		squ nw=q.top();
		q.pop();
		int nx=nw.xpos,ny=nw.ypos,cl=nw.clr,tl=nw.tot;
		if(nx==m&&ny==m){
			printf("%d",tl);
			return 0;
		}
		bool mg=nw.mgc;
		if(vst[nx][ny])continue;
		vst[nx][ny]=true;
		if(nx>1){
			if(a[nx-1][ny]==cl)q.push(squ(a[nx-1][ny],nx-1,ny,tl,false));
			else if(a[nx-1][ny])q.push(squ(a[nx-1][ny],nx-1,ny,tl+1,false));
			else if(!mg)q.push(squ(cl,nx-1,ny,tl+2,true));
		}
		if(ny>1){
			if(a[nx][ny-1]==cl)q.push(squ(a[nx][ny-1],nx,ny-1,tl,false));
			else if(a[nx][ny-1])q.push(squ(a[nx][ny-1],nx,ny-1,tl+1,false));
			else if(!mg)q.push(squ(cl,nx,ny-1,tl+2,true));
		}
		if(nx<m){
			if(a[nx+1][ny]==cl)q.push(squ(a[nx+1][ny],nx+1,ny,tl,false));
			else if(a[nx+1][ny])q.push(squ(a[nx+1][ny],nx+1,ny,tl+1,false));
			else if(!mg)q.push(squ(cl,nx+1,ny,tl+2,true));
		}
		if(ny<m){
			if(a[nx][ny+1]==cl)q.push(squ(a[nx][ny+1],nx,ny+1,tl,false));
			else if(a[nx][ny+1])q.push(squ(a[nx][ny+1],nx,ny+1,tl+1,false));
			else if(!mg)q.push(squ(cl,nx,ny+1,tl+2,true));
		}
	}
	puts("-1");
}
