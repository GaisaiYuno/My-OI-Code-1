#include <iostream>
using namespace std;
int n,m,map[111][111];
struct node
{
    int num1,num2; //���ﵱǰ��״̬��num1��������������������num2������num1��·����
}ss[111][111];
void add(int x,int y,int xx,int yy,int k) //�ӣ�x��y���ߵ���xx��yy����k����Ǵ˴��ƶ������Ƿ����
{
    if(ss[xx][yy].num1==ss[x][y].num1+k) //������·����������
    ss[xx][yy].num2+=ss[x][y].num2;
    if(ss[xx][yy].num1<ss[x][y].num1+k) //�����ǰ�߷��õ��ĺ����������������Ӷ�����º���������������·����
    {
        ss[xx][yy].num1=ss[x][y].num1+k;
        ss[xx][yy].num2=ss[x][y].num2;
    }
}
int main (void)
{
    int t,i,j,k,l,x,y,xx,yy,v;
    cin>>t;
    while(t--&&cin>>n>>m)
    {
        for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            cin>>map[i][j];
            ss[i][j].num1=ss[i][j].num2=0;
        }
        ss[1][1].num2=1;
        for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(!ss[i][j].num2)continue; //Ϊ���Ż���ֻҪ����ǰ������ĵ�����ƶ�����
            l=i+j+map[i][j]; //�жϵ�ǰ�����ߵ���Զ����
            if(!map[i][j]||i==n&&j==m)continue;  //�����ǰ������Ϊ0�������յ㣬��ô���ô���
            if(l>=n+m) //������ߵ���Զ������ڻ�����ߵ��յ�ľ��룬�����ߵ��յ�
            {
                add(i,j,n,m,(l==n+m)?1:0); //����ߵ��յ��������꣬����1
                continue;
            }
            for(k=i;k<=l;k++) //������ǰ�����·����ߵ�����Щ��
            {
                if(k<=n&&l-k<=m&&l-k>=j) //������
                {
                    add(i,j,k,l-k,1);
                }
            }
        }
        cout<<ss[n][m].num1<<" "<<ss[n][m].num2<<endl;
    }
    return 0;
}

