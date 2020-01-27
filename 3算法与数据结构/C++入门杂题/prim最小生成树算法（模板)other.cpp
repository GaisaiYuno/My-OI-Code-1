/*��������һ�����ȶ����Ż���prime ���鿴֮ǰ��ѧϰ���ص�prime��Ȼ������������ѧ��򵥵�Kruskal��

prime��˼���ǰ���̰��

��������һ������dist ��ʾ���������������Ҫ���ӵ�Ȩֵ

��Ϊ��̰�� ����dist[ i ]ԽСԽ��

��ʼ״̬ ����distȫΪһ���ܴ�������ȷ�˵0x7f7ff)

Ȼ���������ѡ��һ���� ������dist��Ϊ0����ѡ�����1�Žڵ㣩����������ǣ���Ϊ��С������ÿ����ֻ����һ�Σ�

Ȼ�����Ǳ���������������ĵ� �����ǵ�dist���£�����Ϊ���ǵı�Ȩֵ��

���� ���ǵõ��˶��dist��Ϊ0x7f7ff�ĵ���

���� ����ѡ������dist��С�ĵ� ����� Ȼ���ٱ������������ĵ㣬�������ǵ�dist

���ϵ��ظ� �ظ� ֱ�����е㶼�����Ϊֹ

��Ȼ Ҳ����orz���������Ȼ���Ե㲢û��ORZ����� 23333�� ��ʱ ����ǵĵ��������С��n�ģ��Ӹ��жϾͺ���

���������ص�pirme ʱ�临�Ӷ�O��N^2��
*/
#include<bits/stdc++.h>
#define INF 0x7f7ff
using namespace std;
int n,m,dist[5010],head[5010],k,ans;
bool vis[5010];
struct node
{
    int to,next,w;
}edge[400010];
void add(int u,int v,int w)
{
    edge[++k].to=v;
    edge[k].w=w;
    edge[k].next=head[u];
    head[u]=k;
}
void Prime()
{
    fill(dist+1,dist+n+1,INF);
    dist[1]=0;
    for(int j=1;j<=n;j++)
    {
        int u=-1,minn=INF;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]<minn&&!vis[i])
            {
                u=i;
                minn=dist[i];
            }
        }
        if(u==-1)
        {
            ans=-1;
            return;
        }
        vis[u]=1;
        ans+=dist[u];
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].to;
            if(!vis[v]&&dist[v]>edge[i].w) dist[v]=edge[i].w;
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        add(a,b,c);
        add(b,a,c);
    }
    Prime();
    if(ans==-1) cout<<"orz"<<endl;
    else cout<<ans;
}
