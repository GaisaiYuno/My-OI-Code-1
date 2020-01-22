#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
    float a,b,c;
    cin>>a>>b>>c;
    a=a*0.2;
    b=b*0.3;
    c=c*0.5;
    cout<<a+b+c;
    return 0;
}
