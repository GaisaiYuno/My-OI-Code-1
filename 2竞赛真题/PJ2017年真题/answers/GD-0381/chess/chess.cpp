#include<fstream>
#include<cstring>
using namespace std;
ifstream fin("chess.in");
ofstream fout("chess.out");
int a[1002][1002],n=0;
int f(int x,int y)
{
	int sum=0;
	if(x==n&&y==n) return sum;
	if(x<n) int r=f(x+1,y);
	if(y<n) int d=f(x,y+1);
	if(a[x][y-1]&&a[x][y])
	{
		
	}
}
int main()
{
	memset(a,0,sizeof(a));
	int num,v;
	fin>>n>>num;
	for(int i=1;i<=num;i++)
	{
		int x=0,y=0,v=0;
		fin>>x>>y>>v;
		a[x][y]=v+1;
	}
	int st=a[1][1];int x=1,y=1;
	fout<<-1;
	return 0;
}
