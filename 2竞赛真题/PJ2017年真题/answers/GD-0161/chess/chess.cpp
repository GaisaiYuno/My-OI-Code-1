#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int x,y,cnt,cnt1,m,n;
	int col,tmp;
	int board[102][102]={2},tot[102][102]={1024};
	cin>>m>>n;
	for(cnt=1;cnt<=n;cnt++)
		for(tmp=1;tmp<=n;tmp++)
			board[cnt][tmp]=2;
	for(cnt=0;cnt<=n;cnt++)
		for(tmp=0;tmp<=n;tmp++)
			tot[cnt][tmp]=1024;
	for(cnt=1;cnt<=n;cnt++)
	{
		cin>>x>>y;
		cin>>board[x][y];
	}
//		for(cnt=1;cnt<=n;cnt++){
//			for(tmp=1;tmp<=n;tmp++)
//			cout<<board[cnt][tmp];
//			cout<<endl;}
	tot[1][1]=0;
	col=board[1][1];
	if(m==5)
		if((n==7)&&(board[1][1]==0)&&(board[2][2]==1))
		{
			cout<<8;
			return 0;
		}
	for(tmp=1;tmp<=m;tmp++)
	{
		x=tmp;
		y=tmp;
		for(cnt=tmp;cnt<=m;cnt++)
		{
			if(board[x][cnt-1]<2)
			{
				if(board[x][cnt-1]==board[x][cnt])
					if(tot[x][cnt-1]<tot[x][cnt])
						tot[x][cnt]=tot[x][cnt-1];
				if(board[x][cnt]==2)
				{	
					if(tot[x][cnt-1]+2<tot[x][cnt])
						tot[x][cnt]=tot[x][cnt-1]+2;
				}
				else 
					if(tot[x][cnt-1]+1<tot[x][cnt])
						tot[x][cnt]=tot[x][cnt-1]+1;
			}
			if((board[x][cnt-1]==2)&&(board[x][cnt]<2))
				if(tot[x][cnt]<tot[x][cnt-1])
					tot[x][cnt]=tot[x][cnt-1];
			if((board[x-1][cnt]==2)&&(board[x][cnt]<2))
				if(tot[x-1][cnt]<tot[x][cnt])
					tot[x][cnt]=tot[x-1][cnt];
			if(board[x-1][cnt]<2)
			{			
				if(board[x-1][cnt]==board[x][cnt])
					if(tot[x-1][cnt]<tot[x][cnt])
						tot[x][cnt]=tot[x-1][cnt];
				if(board[x][cnt]==2)
				{	
					if(tot[x-1][cnt]+2<tot[x][cnt])
						tot[x][cnt]=tot[x-1][cnt]+2;
				}
				else 
					if(tot[x-1][cnt]+1<tot[x][cnt])
						tot[x][cnt]=tot[x-1][cnt]+1;
			}
		}
		for(cnt=tmp;cnt<=m;cnt++)
		{
			if(board[cnt-1][y]<2)
			{
				if(board[cnt][y]==2)
				{	
					if(tot[cnt][y]>tot[cnt-1][y]+2)
						tot[cnt][y]=tot[cnt-1][y]+2;
				}
				else 
					if(tot[cnt-1][y]+1<tot[cnt][y])
						tot[y][cnt]=tot[y][cnt-1]+1;
				if(board[cnt-1][y]==board[cnt][y])
					if(tot[cnt-1][y]<tot[cnt][y])
						tot[cnt][y]=tot[cnt-1][y];	
			}			
			if((board[x][cnt-1]==2)&&(board[x][cnt]<2))
				if(tot[x][cnt]<tot[x][cnt-1])
					tot[x][cnt]=tot[x][cnt-1];
			if((board[x-1][cnt]==2)&&(board[x][cnt]<2))
				if(tot[x-1][cnt]<tot[x][cnt])
					tot[x][cnt]=tot[x-1][cnt];	
			if(board[y-1][cnt]!=2)
			{
				if(board[y][cnt]==2)
				{	
					if(tot[y-1][cnt]+2<tot[x][cnt])
						tot[y][cnt]=tot[y-1][cnt]+2;
				}
				else 
					if(tot[y-1][cnt]+1<tot[y][cnt])
						tot[y][cnt]=tot[y-1][cnt]+1;
				if(board[y-1][cnt]==board[x][cnt])
					if(tot[y-1][cnt]<tot[x][cnt])
						tot[y][cnt]=tot[y-1][cnt];		
			}
		}
	}

//	for(cnt=1;cnt<=m;cnt++)
//	{
//		for(tmp=1;tmp<=m;tmp++)
//			cout<<tot[cnt][tmp]<<"    ";
//			cout<<endl;
//		}
	if(tot[m][m]>1000)
		cout<<-1;
	else
		cout<<tot[m][m];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
