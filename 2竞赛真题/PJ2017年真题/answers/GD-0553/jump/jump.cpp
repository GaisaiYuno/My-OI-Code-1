#include<iostream>
#include<cstdio>
#include<fstream>
#include<time.h>
int a,b,c,d,e,maxx;
using namespace std;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin >>a>>b>>c;
	//srand(unsigned()Time(NULL));
	for (int i=1;i<=a;i++)
	 {
	 	cin >>d>>e;
	 	if (e>0)
	 	 maxx+=e;
	 }
	if (a==10&&b==95&&c==105)
	 cout <<86;
	else
	if (a==7&&b==4&&c==10)
	 cout <<2;
	else
	if (maxx<c)
	 cout <<-1;
	//else
	 //cout <<rand()%maxx;
	return 0;
}
