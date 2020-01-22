#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<map>
#include<algorithm>
#include<math.h>
int a,b,c;
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	cout<<a*0.2+b*0.3+c*0.5<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
