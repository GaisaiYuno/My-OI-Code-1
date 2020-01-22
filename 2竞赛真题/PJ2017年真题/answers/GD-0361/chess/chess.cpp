#include<cstdio>
#include<windows.h>
using namespace std;
int m,n,_chess[1001][1001],tot,flag,ans=0x7fffffff;
int dx[5]={0,1,0,-1,0},
	dy[5]={0,0,1,0,-1};
bool _chess2[1001][1001];
void search(int x,int y,bool _magic){
	int t1=_chess[x][y];
	if (_magic==true) _chess[x][y]=0;
	if (tot>=ans) return ;
	if (x==m && y==m){
		ans=tot<ans? tot:ans;
		return ;
	}
	for (register int i=1;i<=4;i++){
		int nx=x+dx[i],ny=y+dy[i];
		if (nx>=1 && ny>=1 && nx<=m && ny<=m && (!_chess2[nx][ny])){
			if (_chess[nx][ny]!=0){
				int temp=_chess[nx][ny]==t1? 0:1;
				tot+=temp; _chess2[nx][ny]=true;
				search(nx,ny,false);
				tot-=temp; _chess2[nx][ny]=false;
			}
			else if (!_magic){
				tot+=2; _chess2[nx][ny]=true;
				_chess[nx][ny]=_chess[x][y];
				search(nx,ny,true);
				tot-=2; _chess2[nx][ny]=false;
			}
		}
	}
}
main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for (register int i=1;i<=n;i++){
		int x,y,c;
		scanf("%d%d%d",&x,&y,&c);
		_chess[x][y]=c+1;
	}
	_chess2[1][1]=true;
	search(1,1,false);
	if (ans!=0x7fffffff) printf("%d",ans);
	else printf("-1");
	fclose(stdin);fclose(stdout);
	return 0;
}
/*
5 7
1 1 0
1 2 0
2 2 1
3 3 1
3 4 0
4 4 1
5 5 0


5 5
1 1 0
1 2 0
2 2 1
3 3 1
5 5 0

*/
