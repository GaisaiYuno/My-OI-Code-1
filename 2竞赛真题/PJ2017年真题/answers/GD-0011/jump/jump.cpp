//#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<queue>
#include<deque>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>

using namespace std;
ifstream cin ("jump.in" ,ios::in );
ofstream cout("jump.out",ios::out);
int distancex[500001],score[500001],g,d,k,n;
#define minj (d-g<0?1:d-g)
#define maxj (d+g)

bool dfs(long long where,long long start,long long total)
{
	if(total>=k)
		return true;
	bool x=false;
	for(long long i=start;i<=n&&distancex[i]-where<=maxj&&!x;++i) 
		//cout<<g<<' '<<where<<' '<<total<<'\n';
		if(distancex[i]-where>=minj)
			x=dfs(distancex[i],i,total+score[i]);
	return x;
}

int main()
{
	int i;
	cin>>n>>d>>k;
	for(i=1;i<=n;++i)
		cin>>distancex[i]>>score[i];
	for(g=1;maxj<=distancex[n]&&!dfs(0,1,0);++g);
	cout<<(g>n?-1:g);
	cin.clear();
	cout.clear();
	cin.close();
	cout.close();
	return 0;
}
/*
10 95 105
9 46
34 -2
51 -22
100 -32
104 -30
147 -34
167 -46
214 -24
235 38
251 50

*/
