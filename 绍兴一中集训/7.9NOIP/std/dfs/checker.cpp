//============================================================================
// Author       : sunyaofeng
//============================================================================

//#pragma 	comment(linker, "/STACK:100240000,100240000")
//#include	<cstdio>
//#include	<cstdlib>
//#include	<cstring>
//#include	<algorithm>

#include	<bits/stdc++.h>

using	namespace	std;

#define DB		double
#define	lf		else if
#define I64		long long
#define	Rd()	(rand()<<15|rand())
#define For(i,a,b)	for(int i=a,lim=b;i<=lim;i++)
#define Rep(i,a,b)	for(int i=a,lim=b;i>=lim;i--)

//#define	min(a,b)	((a)<(b)?(a):(b))
//#define	max(a,b)	((a)<(b)?(b):(a))

#define	CH	(ch=getchar())
int		IN()	{
		int x= 0, f= 0, ch;
		for	(; CH < '0' || ch > '9';)	f= (ch == '-');
		for	(; ch >= '0' && ch <= '9'; CH)	x= x*10 + ch -'0';
		return	f? -x : x;
}

char	File[105];

FILE	*Fin, *Fsub, *Fres;

void	Return(DB x, const char* s)	{
		fprintf(Fres, "%.12lf\n", x);
		fprintf(Fres, "%s\n", s);
		exit(0);
}

#define n	100005

int		A, B, C, D, gt, V[n], sta[n], L[n];

int		N;

vector<int>	E[n];

map<int, int>	G;

void	DFS(int u)	{
		V[u]= 1;
		sta[u]= 1;
		L[u]= ++ *L;
		
		For(i, 1, E[u].size())	{
			int v= E[u][i-1];
			
			if	(! V[v])	{
				A--;	DFS(v);
			}
			lf	(sta[v])	B--;
			lf	(L[u] <= L[v])	C--;
				else	D--;
		}
		
		sta[u]= 0;
}

int		main(int argc, char* argv[]){
		Fin= fopen("dfs.in", "r");
		Fsub= fopen("dfs.out", "r");
		Fres= fopen("res.txt", "w");

		fscanf(Fin, "%d%d%d%d", &A, &B, &C, &D);
		fscanf(Fsub, "%d", &N);
		
		if	(N != A+1)	Return(0, "The number of A is not correct!");
		
		int tot= 0;
		For(i, 1, N)	{
			int deg, x;
			fscanf(Fsub, "%d", &deg);
			
			if	(deg < 0 || deg >= N)	Return(0, "the degree should be supposed to be in [0, N)!");
			tot+= deg;
			
			if	(tot > A+B+C+D)	Return(0, "the number of total edges is greater than A+B+C+D");
			
			G.clear();
			For(j, 1, deg)	{
				fscanf(Fsub, "%d", &x);
				if	(x < 0 || x > N)	Return(0, "the edge (u, v) should be supposed to be in [1, N]");
			
				if	(x == i)	Return(0, "You are not supposed to output self-loop");
				if	(G.count(x))	Return(0, "You are not supposed to output multiple-edge");
				
				E[i].push_back(x);
				G[x]= 1;
			}
		}
		
		DFS(1);
		sprintf(File, "A : %d, B : %d, C : %d, D : %d\n", A,B,C,D);
		
		if	(A != 0 || B != 0 || C != 0 || D != 0)	Return(0, File);
		Return(1, "you are right");
		
		return	0;
}