#include<iostream>
#include<cstdio>
#include<cstring>
#include<climits>
using namespace std;

double _home,_test,_exam;
double ans;

int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	
	cin>>_home>>_test>>_exam;
	ans=(_home*20/100)+(_test*30/100)+(_exam*50/100);
	cout<<ans<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
