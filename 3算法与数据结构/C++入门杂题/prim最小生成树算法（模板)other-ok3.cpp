#include<cstdio>
#include<cstdlib>
using namespace std;
#define MAXN 5000+5 
const int INF=99999999;
int n,m;
int dis[MAXN+1];
bool book[MAXN+1];//���һ�����Ƿ������С������ 
int sum;//������С�������ĳ���
int map[MAXN+1][MAXN+1],tot;
void Prim()
{
    int pos;//��¼��С�ı�����ĵ�ı�� 
    book[1]=true;//��1�Ŷ������//��true�ȽϺã���Ϊ��ʼ����false 
    tot++;
    while(tot<=n-1)//��n��ʱ��Ͳ����ٽ��мӵ�����ˣ���Ϊ��������
    {
        int min=INF;
        for(int i=1;i<=n;i++)
            if(book[i]==false && dis[i]<min){//ע���book���жϰ���������С�������ľͿ϶�������ȥ�ж� 
                min=dis[i];
                pos=i;
            }
        book[pos]=true;//ע��book�Ĳ��� 
        tot++;
        sum+=dis[pos];
        for(int k=1;k<=n;k++)//ö��pos������г��ߣ������ɳڲ��� 
        {
            if(book[k]==false && dis[k]>map[pos][k])//���pos���ܵ���k��Ҳ��������Ϊ����INF����С�ڵ�
                dis[k]=map[pos][k];
        }

}//��ô�ж����ͼ����ͨ��
    //Ҫ�е����orz 
}
int main() 
{
    scanf("%d%d",&n,&m);
    //�ǵó�ʼ��
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(i==j)
                map[i][j]=0;
            else
                map[i][j]=INF;
    //ע���ʼ��Ҫ�ڸ�ֵ֮ǰ 
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        /*if(edge[i].u==edge[i].v)
            continue;*///Ҳ��������ȥ�Ի� 
        if(w<map[u][v])//�����رߣ�����ĿҪ������С������������ȡ��С 

{//����֮ǰ�ĳ�ʼ�����б�Ҫ��
            map[u][v]=w;
            map[v][u]=w;
        }
    }
    //��ʼ��dis���� 
    //�����ʼĬ��Ϊ1�Ŷ���ΪԴ�㣬��ʼ��1�Ŷ��㵽��������ĳ�ʼ���룬��Ϊ��ʼ��С��������ֻ��1�� 
    for(int i=1;i<=n;i++)
        map[i][i]=0;//ȥ���������������ж�����һ����������� 
    for(int i=1;i<=n;i++)
        dis[i]=map[1][i];
    Prim();
    printf("%d",sum);
        return 0; 
}

