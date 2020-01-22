#include<cmath>
#include<map>
#include<fstream>

using namespace std;

ifstream cin ("librarian.in" ,ios::in );
ofstream cout("librarian.out",ios::out);

int main()
{
	map<long long,short> m;
	map<long long,short>::iterator mi;
	long long i,k,n,q,bigfor,length;
	cin>>n>>q;
	for(i=1;i<=n;++i)
		cin>>k,
		++m[k];
	for(bigfor=1;bigfor<=q;++bigfor)
	{
		cin>>length>>k;
		for(mi=m.begin();mi!=m.end();++mi)
			//cout<<"decode:"<<mi->first<<'\t'<<mi->second
			//	<<'\t'<<(mi->first-k)%(long long)pow(10,length)<<'\n';
			if(mi->first>=k
				&&(mi->first-k)%(long long)pow(10,length)==0)
			{
				cout<<mi->first<<'\n';
				mi->second==1?m.erase(mi),1:--mi->second;
				break;
			}
		mi==m.end() and cout<<"-1\n";
	}
	cin.clear();
	cout.clear();
	cin.close();
	cout.close();
	return 0;
}
/*
{
5 5
2123
1123
23
24
24
2 23
3 123
3 124
2 12
2 1
//
23
1123
-1
-1
-1
}
*/
