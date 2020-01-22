#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cmath>

using namespace std;
struct data{
	int x,y,s,f,c;
};
data opens[10000+5];
const int ax[4]={0,0,1,-1};
const int ay[4]={1,-1,0,0};
int head,tail,map[100+5][100+5],x,y,a,b,c,n,m,i,f[100+5][100+5],xx,yy,ff,j;
void ps(){
	head=1;
	tail=1;
	opens[head].x=1;
	opens[head].y=1;
	opens[head].s=0;
	opens[head].f=0;
	map[1][1]=1;
	while(head<=tail){
		x=opens[head].x;
		y=opens[head].y;
		ff=opens[head].f;
		for(i=0;i<=3;i++){
			xx=x+ax[i];
			yy=y+ay[i];
			if(xx>m||yy>m||xx<=0||yy<=0||map[xx][yy]==1) continue;
			if(f[xx][yy]==f[x][y]||(f[x][y]==3&&f[xx][yy]!=0)){
				if(f[x][y]==3&&opens[head].c==2) ff++;
				for(j=tail;j>=head;j--){
					if(ff<opens[j].f){
						opens[j+1].x=opens[j].x;
						opens[j+1].y=opens[j].y;
						opens[j+1].f=opens[j].f;
						opens[j+1].s=opens[j].s;
						opens[j+1].c=opens[j].c;
					}
					else{
						opens[j+1].x=xx;
						opens[j+1].y=yy;
						opens[j+1].f=ff;
						opens[j+1].s=0;
						break;
					}
				}
				tail++;
				map[xx][yy]=1;
				if(xx==m&&yy==m){
					printf("%d",ff);
					exit(0);
				}
				if(f[x][y]==3&&opens[head].c==2) ff--;
			}
			if((f[xx][yy]!=f[x][y]&&f[xx][yy]!=0)||(f[x][y]==3&&f[xx][yy]!=0)){
				if(opens[head].c==1&&f[x][y]==3) ff++;
				if(opens[head].c==2&&f[x][y]==3) ff--;
				for(j=tail;j>=head;j--){
					if(ff+1<opens[j].f){
						opens[j+1].x=opens[j].x;
						opens[j+1].y=opens[j].y;
						opens[j+1].f=opens[j].f;
						opens[j+1].s=opens[j].s;
						opens[j+1].c=opens[j].c;
					}
					else{
						opens[j+1].x=xx;
						opens[j+1].y=yy;
						opens[j+1].f=ff+1;
						opens[j+1].s=0;
						break;
					}
				}
				tail++;
				map[xx][yy]=1;
				if(xx==m&&yy==m){
					printf("%d",ff+1);
					exit(0);
				}
				if(opens[head].c==1&&f[x][y]==3) ff--;
				if(opens[head].c==2&&f[x][y]==3) ff++;
			}
			else if(f[xx][yy]==0&&opens[head].s==0){
				if(f[x][y]==2) ff++;
				for(j=tail;j>=head;j--){
					if(ff+2<opens[j].f){
						opens[j+1].x=opens[j].x;
						opens[j+1].y=opens[j].y;
						opens[j+1].f=opens[j].f;
						opens[j+1].s=opens[j].s;
						opens[j+1].c=opens[j].c;
					}
					else{
						opens[j+1].x=xx;
						opens[j+1].y=yy;
						opens[j+1].f=ff+2;
						opens[j+1].s=1;
						opens[j+1].c=1;
						break;
					}
				}
				tail++;
				map[xx][yy]=1;
				if(xx==m&&yy==m){
					printf("%d",ff+2);
					exit(0);
				}
				if(f[x][y]==2)ff--;
				if(f[x][y]==1) ff++;
				for(j=tail;j>=head;j--){
					if(ff+2<opens[j].f){
						opens[j+1].x=opens[j].x;
						opens[j+1].y=opens[j].y;
						opens[j+1].f=opens[j].f;
						opens[j+1].s=opens[j].s;
						opens[j+1].c=opens[j].c;
					}
					else{
						opens[j+1].x=xx;
						opens[j+1].y=yy;
						opens[j+1].f=ff+2;
						opens[j+1].s=1;
						opens[j+1].c=2;
						break;
					}
				}
				tail++;
				map[xx][yy]=1;
				if(xx==m&&yy==m){
					printf("%d",ff+2);
					exit(0);
				}
				f[xx][yy]=3;
				if(f[x][y]==1) ff--;
			}
		}
		head++;
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(i=1;i<=n;i++){
		scanf("%d%d%d",&a,&b,&c);
		f[a][b]=c+1;
	}
	ps();
	printf("-1");
	return 0;
}
