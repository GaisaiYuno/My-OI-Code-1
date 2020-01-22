#include<fstream>
using namespace std;
ifstream fin("chess.in");
ofstream fout("chess.out");
int m,n;
char c[1005][1005];
bool b[1005][1005];
int x1,y1,c1,ans;
void pay(int x,int y,int mon,bool mag)
{
    if(x==m-1&&y==m-1)
    {
        if(mon<ans)
        ans=mon;
        return;
    }
    int monn;
    b[x][y]=1;
    int way1[4]={1,-1,0,0},way2[4]={0,0,1,-1};
    for(int i=0;i<4;i++)
    if(x+way1[i]>=0&&x+way1[i]<m&&y+way2[i]>=0&&y+way2[i]<m&&!b[x+way1[i]][y+way2[i]])
    {
        if(c[x+way1[i]][y+way2[i]]==2)
        {
            if(mag)
            {
                monn=mon+2;
                c[x+way1[i]][y+way2[i]]=c[x][y];
                pay(x+way1[i],y+way2[i],monn,0);
            }
            else
            continue;
        }
        else if(c[x+way1[i]][y+way2[i]]==c[x][y])
        {
            monn=mon;
            pay(x+way1[i],y+way2[i],monn,1);
        }
        else
        {
            monn=mon+1;
            pay(x+way1[i],y+way2[i],monn,1);
        }
    }
    b[x][y]=0;
    if(mag==0)
    c[x][y]=2;
}
int main()
{
    fin>>m>>n;
    ans=10000000;
    for(int i=0;i<m;i++)
    for(int j=0;j<m;j++)
    {
        c[i][j]=2;
        b[i][j]=0;
    }
    for(int i=0;i<n;i++)
    {
        fin>>x1>>y1>>c1;
        c[x1-1][y1-1]=c1;
    }
    pay(0,0,0,1);
    if(ans==10000000)
    fout<<-1;
    else
    fout<<ans;
    return 0;
}
