#include<iostream>
using namespace std;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,mod=1,a,min1,b;
	int book[1001]={0},len[1001]={0},reader[1001]={0};
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>book[i];
	for(int i=1;i<=q;i++) cin>>len[i]>>reader[i]; 
	for(int i=1;i<=q;i++)
	{
		mod=1;
		min1=99999999;
		for(int j=1;j<=n;j++)
		{
			b=book[j];
			for(int k=1;k<=len[i];k++) mod=mod*10;
			b=b%mod;
			if(b==reader[i]) 
			{
				if(book[j]<min1) min1=book[j];
			}
		}
		if(min1==99999999) cout<<-1<<endl;
		else cout<<min1<<endl;
	}
	return 0;
}
