#include<iostream>
using namespace std;
int a,b,c,d=1;
int main()
{
freopen("score.in","r".stdin);
freopen("score.out","w".stdout);

cin>>a>>b>>c;
a=a*0.2;
b=b*0.3;
c=c*0.5;
d+=a;
d+=b;
d+=c;
cout<<d;return 0;
}

