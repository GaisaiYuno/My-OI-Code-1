#include <iostream>
#include <cstdio>
using namespace std;
int a,b,c,ans;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
    cin>>a;
    cin>>b;
    cin>>c;
    ans=a/5+b/10*3+c/2;
    cout<<ans;
	return 0;
}
