#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
int n,q,cn,Tbook[10005];
int co;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	
	cin>>n>>q;
	for(int i=0;i<n;i++) cin>>Tbook[i];
	sort(Tbook,Tbook+n);
	for(int i=0;i<q;i++)
	{
		bool bo=false;
		cin>>cn>>co;
		int c=1;
		for(int j=0;j<cn;j++) c*=10;
		for(int j=0;j<n;j++)
		{
//			cout<<Tbook[j]<<' '<<Tbook[j]%c<<' '<<co<<endl;
			if(Tbook[j]%c==co)
			{
				bo=true;
				cout<<Tbook[j]<<endl;
				break;
			}
		}
		if(!bo) cout<<-1<<endl;
	}
	return 0;
}
