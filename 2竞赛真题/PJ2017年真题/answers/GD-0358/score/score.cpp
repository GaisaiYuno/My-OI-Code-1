# include<iostream>
# include<cstdio>
# include<cstdlib>
# include<algorithm>
# include<cmath>
# include<string>
# include<cstring>
using namespace std;
int main()
{
	int z,xx,q;
	
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	
	cin>>z>>xx>>q;
	cout<<z*0.2+xx*0.3+q*0.5;
	return 0;
}
