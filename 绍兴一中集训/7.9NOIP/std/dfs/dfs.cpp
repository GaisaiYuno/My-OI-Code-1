//============================================================================
// Author       : Sun YaoFeng
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

#define	fi	first
#define se	second
#define MK	make_pair
#define PA	pair<int, int>

//#define	min(a,b)	((a)<(b)?(a):(b))
//#define	max(a,b)	((a)<(b)?(b):(a))

#define	CH	(ch=getchar())
int		IN()	{
		int x= 0, f= 0, ch;
		for	(; CH < '0' || ch > '9';)	f= (ch == '-');
		for	(; ch >= '0' && ch <= '9'; CH)	x= x*10 + ch -'0';
		return	f? -x : x;
}

#define n	100005

int		N, A, B, C, D, ID[n], F[n], G[n];

vector<int>	E[n], Ans[n];

void	Link(int u, int v)	{
		E[u].push_back(v);
		Ans[u].push_back(v);
}

void	DFS(int u)	{
		For(i, 1, E[u].size())	{
			int v= E[u][i-1];
			F[v]= u;
			
			if	(C)	{
				for (int x= F[u]; x; x= F[x])	{
					Ans[x].push_back(v);
					C--;
					
					if	(! C)	break;
				}
			}
			
			if	(B)	{
				for (int x= u; x; x= F[x])	{
					Ans[v].push_back(x);
					B--;
					
					if	(! B)	break;
				}
			}
			
			if	(D)	{
				For(j, 1, *G)	{
					Ans[v].push_back(G[j]);
					D--;
					
					if	(! D)	break;
				}
			}
			
			DFS(v);
		}
		
		G[++ *G]= u;
}

void	Out(int x)	{
		if	(x < 10)	{
			putchar('0' + x);	return;
		}
		Out(x/10);
		putchar('0' + x%10);
}

int		main(int argc, char* argv[]){
		freopen("dfs.in", "r", stdin);
		freopen("dfs.out", "w", stdout);
	
		A= IN();
		B= IN();
		C= IN();
		D= IN();
		N= A+1;
		
		I64	MinSum= max(B, A + C),
			MaxSum= 1ll*N*(N-1)/2 - D;
		
		if	(MinSum > MaxSum)	return	puts("-1"), 0;
		
		int	Sum= MinSum, Max= 0;
		ID[0]= 1;
		
		For(i, 2, N)	{
			if	(Sum >= Max+1 + N-i)	{
				Link(ID[Max], i);
				Max++;
				
				Sum-= Max;
				ID[Max]= i;
			}
			else	{
				int t= Sum - (N-i);
				Link(ID[t-1], i);
				
				Sum-= t;
			}
		}
		
		DFS(1);
		
		printf("%d\n", N);
		For(i, 1, N)	{
			printf("%d ", int(Ans[i].size()));
			For(j, 1, Ans[i].size())	Out(Ans[i][j-1]), putchar(' ');
			putchar('\n');
		}
		
		return	0;
}