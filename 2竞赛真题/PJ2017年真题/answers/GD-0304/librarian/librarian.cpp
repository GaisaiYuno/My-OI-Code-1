#include <iostream>
#include <cstdio>
#define oo 21474836
using namespace std;
int Min[1010],n,q,Pow[15],Num[1010],Len[1010],Need[1010],Mod_Num[1010];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=1005;i++) Min[i]=oo;
	for (int i=1;i<=n;i++) cin>>Num[i];
	for (int i=1;i<=q;i++) cin>>Len[i]>>Need[i];
	Pow[0]=1;
	for (int i=1;i<=10;i++) Pow[i]=Pow[i-1]*10;
	for (int i=1;i<=q;i++) 
	{
	  for (int j=1;j<=n;j++)
	  {
	     Mod_Num[j]=Num[j]%Pow[Len[i]];	  
	     if (Mod_Num[j]==Need[i]) Min[i]=min(Min[i],Num[j]);
	  }
    }
	for (int i=1;i<=q;i++)
	{
	  if (Min[i]==21474836) cout<<-1<<endl;
	  else
	  cout<<Min[i]<<endl; 
    }
 	return 0;
}
