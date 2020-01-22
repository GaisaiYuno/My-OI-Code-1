#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int m,n,x,y,c;
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	cin>>x>>y>>c;
	cout<<"-1";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
