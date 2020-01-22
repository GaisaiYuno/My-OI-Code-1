#include<fstream>
using namespace std;
long long int sb[1002],dx[1002];
int main()
{
	ifstream fin("librarian.in");
	ofstream fout("librarian.out");
	long long sk,n,q,v,t,ven=1;
	fin>>n>>q;
	bool h=0;
	for(long long i=1;i<=q;i++) dx[i]=1e9;
	for(long long i=1;i<=n;i++) fin>>sb[i];
	for(long long i=1;i<=q;i++)
	{
		fin>>v>>t;
		ven=1;
		h=0;
		for(long long j=1;j<=v;j++) ven*=10;
		for(long long j=1;j<=n;j++)
		 if(sb[j]%ven==t&&sb[j]<=dx[i])
		  {
		  	dx[i]=sb[j];
		  	h=1;
		  }
		if(h==0) dx[i]=-1;
	}
	for(long long i=1;i<=q;i++) fout<<dx[i]<<endl;
	return 0;
}
