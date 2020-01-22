#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;
int a,b,c;
int main()
{
    freopen("score.in","r",stdin);
    freopen("score.out","w",stdout);
    cin>>a>>b>>c;
    cout<<a*0.2+b*0.3+c*0.5<<endl;
    return 0;
}
