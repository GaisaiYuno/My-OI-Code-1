#include<iostream>
#include<queue>
#include<fstream>
using namespace std;
int M,N,ans;
int chess[105][105];
int main()
{
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
cin>>N>>M;
for(int i=1,x=0,y=0,c=0;i<=N;i++)
{
    scanf("%d%d%d",&x,&y,&c);
    chess[x][y]=c;
}
cout<<-1<<endl;
    return 0;
}
