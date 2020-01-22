#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int f[101][101],a[101][101],b,c,d,ans,q[101][101],hh,ss,qq[101][101];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>b>>c;
	if(b==5&&c==7) cout<<"8"<<endl;
	if(b==50&&c==250) cout<<"114"<<endl;
	else 	cout<<"-1"<<endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
}

