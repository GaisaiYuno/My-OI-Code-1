#include <iostream>
#include <cstring>
#include <cstdio>


using namespace std;


const long int INF=0x3f3f3f3f; 

const int maxn=100000+5;
const int maxm=1000+5;

long int a[maxn],b[maxn];
long int k[maxm],p[maxm];
long int dp[maxm][15];//������Ϊi,���j���˺�����ʱ��������پ�ʯ




int main()
{
    int n,m;

     while(cin >> n >> m)
    {
        long int fen=0,max_p=0,life=0;
        for(int i=0; i<n; i++)
        {
           
            cin>>a[i]>>b[i];
            
            fen=max(fen,b[i]);
            life=max(life,a[i]);
        }

        for(int i=0; i<m; i++)
        {
           
            cin>>k[i]>>p[i];
            max_p=max(max_p,p[i]);
        }
        if(fen>=max_p)
        {
          //  printf("-1\n");
            cout<<-1<<endl;
            continue;
        }
        memset(dp,0,sizeof(dp));
        for(int i=0; i<=fen; i++)//����
        {
            for(int j=1;j<=life;j++)// ����ֵ 
            {
                dp[j][i]=INF;
                for(int u=0;u<m;u++)//��u������
                {
                    long int dmg=p[u]-i;//��u����������ɵ��˺�
                    if(dmg<=0)
                        continue;
                    if(dmg>=j)
                    {
                        dp[j][i]=min(dp[j][i],k[u]);
                    }
                    else
                    {
                        dp[j][i]=min(dp[j][i],dp[j-dmg][i]+k[u]);
                    }
                }
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=dp[a[i]][b[i]];
        }
        printf("%lld\n",ans);

    }
    return 0;
}

