#include<iostream>
#include<cstdio>
using namespace std;
int n,m,v[30],sv[30],g[20][30],s[20],top;
int as[20],sum=1000000000;
void dfs(int k,int cnt)//��k��Ե�k�����Ͼ��Ѵ���cnt��¼��ѡ�����ϵ����� 
{
    if(k>n) //����n�����ϴ�����Ϳ��Խ��и����� 
    {
        bool flag=true;
        for(register int i=1;i<=m;++i)
        if(sv[i]<v[i]){flag=false;break;}//�ж��Ƿ�ι��ţ 
        if(flag)
        if(cnt<sum)//��Ϊ�����Ǵӵ�һ�����Ͽ�ʼ��㴦������
        {           //���Դ��Ǵ��ֵ���С�Ŀ�ʼ���� 
            sum=cnt;
            for(register int i=1;i<=n;++i)//��һ�����д洢�� 
            as[i]=s[i];
        }
        return;
    }
    s[++top]=k;//���д洢�������� 
    for(register int i=1;i<=m;++i)sv[i]+=g[k][i];//sv[i]��Ŀǰά�������� 
    dfs(k+1,cnt+1);//ѡȡ 
    for(register int i=1;i<=m;++i)sv[i]-=g[k][i];
    --top;//���� 
    dfs(k+1,cnt);//��ѡȡ 
}
int main()
{
scanf("%d",&m);
    for(register int i=1;i<=m;++i)
    scanf("%d",&v[i]);
    scanf("%d",&n);
    for(register int i=1;i<=n;++i)
    for(register int j=1;j<=m;++j)
    scanf("%d",&g[i][j]);
    dfs(1,0);
    printf("%d ",sum);
    for(register int i=1;i<=sum;++i)
    printf("%d ",as[i]);
    return 0;
}	
