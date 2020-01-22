#include<iostream>
#include<fstream>
using namespace std;
double a,b,c;
double ans;
int main()
{
    freopen("score.in","r",stdin);
    freopen("score.out","w",stdout);
    cin>>a>>b>>c;
    ans=a*2/10+b*3/10+c*5/10;
    cout<<int(ans)<<endl;
    return 0;
}
