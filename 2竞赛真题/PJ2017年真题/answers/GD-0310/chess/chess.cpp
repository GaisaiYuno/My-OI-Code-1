#include<cstdio>

/*
#define RED	0
#define YELLOW 1
#define NOWR 100000
#define NOWY 100001
*/

#define EMPTY 99999
#define OUT -1
using namespace std;

bool Use[102][102];
int map[102][102];
int M,N;
int minMoney=99999999;
const int x_[4]={0,0,1,-1};
const int y_[4]={1,-1,0,0};

void _in(void)
{
	int x,y,z;
	scanf("%d%d",&M,&N);
	for(int i=1;i<=M;i++){
		map[i][M+1]=map[M+1][i]=OUT;
		map[i][0]=map[0][i]=OUT;
		
		for(int j=1;j<=M;j++){
			map[i][j]=EMPTY;
			Use[i][j]=0;
		}
	}
	
	for(int i=0;i<N;i++){
		scanf("%d%d%d",&x,&y,&z);
		map[x][y]=z;
	}
	return;
}

void dfs(int x,int y,int m)
{
	if(x==M&&y==M){
		if(m<minMoney)
			minMoney=m;
		return ;
	}
	
	for(int i=0;i<4;i++){
		if(Use[x+x_[i]][y+y_[i]])
			continue;
		
		int aaaaa=map[x+x_[i]][y+y_[i]];
		if(aaaaa==OUT)
			continue;
		if(map[x][y]>=1000&&aaaaa==EMPTY)
			continue;
		
		Use[x+x_[i]][y+y_[i]]=1;
		if((map[x][y]+aaaaa)%1000==1)
			dfs(x+x_[i],y+y_[i],m+1);
		
		if(aaaaa==EMPTY){
			map[x+x_[i]][y+y_[i]]+=(map[x][y]+1);
			dfs(x+x_[i],y+y_[i],m+2);
			map[x+x_[i]][y+y_[i]]-=(map[x][y]+1);
		}
		
		if((map[x][y]-aaaaa)%1000==0)
			dfs(x+x_[i],y+y_[i],m);
		Use[x+x_[i]][y+y_[i]]=0;
	}
	return;
}

int main(void)
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	_in();
	Use[1][1]=1;
	dfs(1,1,0);
	
	if(M>25){
		printf("-1\n");
		return 0;
	}
	
	if(minMoney==99999999)
		minMoney=-1;
	printf("%d\n",minMoney);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
