#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int M,N,X,Y,C,A[105][105],Q[105][105],Dt[105][105]={0},Zf[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
bool Tf=true,W=false;
void dg(int Xa,int Ya)
{
	int i,Xk,Yk;
	for(i=0;i<=3;i++)
	{
		Xk=Xa+Zf[i][0];
		Yk=Ya+Zf[i][1];
		if(Xk==0 || Yk==0 || Xk==M+1 || Yk==M+1)
			continue;
		if(Dt[Xk][Yk])
			continue;
		else if(Xk==M && Yk==M)
		{
			if(A[Xk][Yk]==0 && Tf)
			{
				W=true;
				if(Q[Xk][Yk])
					Q[Xk][Yk]=min(Q[Xk][Yk],Q[Xa][Ya]+2);
				else
					Q[Xk][Yk]=Q[Xa][Ya]+2;
			}
			else if(A[Xk][Yk]==A[Xa][Ya])
			{
				W=true;
				Tf=true;
				if(Q[Xk][Yk])
					Q[Xk][Yk]=min(Q[Xk][Yk],Q[Xa][Ya]);
				else
					Q[Xk][Yk]=Q[Xa][Ya];
			}
			else if(A[Xk][Yk])
			{
				W=true;
				Tf=true;
				if(Q[Xk][Yk])
					Q[Xk][Yk]=min(Q[Xk][Yk],Q[Xa][Ya]+1);
				else
					Q[Xk][Yk]=Q[Xa][Ya]+1;
			}
		}
		else if(A[Xk][Yk]==0 && Tf)
		{
			Tf=false;
			A[Xk][Yk]=A[Xa][Ya];
			Q[Xk][Yk]=Q[Xa][Ya]+2;
			Dt[Xk][Yk]=1;
			dg(Xk,Yk);
			Dt[Xk][Yk]=0;
			A[Xk][Yk]=0;
		}
		else if(A[Xk][Yk]==A[Xa][Ya])
		{
			Tf=true;
			Q[Xk][Yk]=Q[Xa][Ya];
			Dt[Xk][Yk]=1;
			dg(Xk,Yk);
			Dt[Xk][Yk]=0;
		}
		else if(A[Xk][Yk])
		{
			Tf=true;
			Q[Xk][Yk]=Q[Xa][Ya]+1;
			Dt[Xk][Yk]=1;
			dg(Xk,Yk);
			Dt[Xk][Yk]=0;
		}
	}
	return;
}
int main()
{
	int i;
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&M,&N);
	memset(A,0,sizeof(A));
	memset(Q,0,sizeof(Q));
	for(i=1;i<=N;i++)
	{
		scanf("%d%d%d",&X,&Y,&C);
		A[X][Y]=C+1;
	}
	Dt[1][1]=1;
	dg(1,1);
	if(W)
		printf("%d",Q[M][M]);
	else
		printf("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
