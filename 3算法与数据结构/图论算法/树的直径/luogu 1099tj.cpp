#include<iostream>
using namespace std;
int dis[1001][1001]; 
int maxx[1001],maxy[1001];
int m,l;
#define f(i,a,b) for(i=a;i<=b;i++) //�򻯴���
int main()
{
//	freopen("testdata (13).in","r",stdin);
    int n,s,i,j,k;
    cin>>n>>s;
    f(i,0,1000)
    {
        f(j,0,1000)
        {
            if(i!=j)dis[i][j]=99999999;
            else dis[i][j]=0;
        }
    }
    f(i,1,n-1)
    {
        int a,b,c;
        cin>>a>>b>>c;
        dis[a][b]=c;
        dis[b][a]=c;//����ͼ��ͼ
    }
    int maxn=0;
    f(k,1,n)
    {
        f(i,1,n)
        {
            f(j,1,n)if(dis[i][j]>dis[i][k]+dis[k][j])dis[i][j]=dis[i][k]+dis[k][j];
        }
    }//floyd��ֱ��
    f(i,1,n)
    {
        f(j,1,n)
        {
        //	printf("%d ",dis[i][j]);
            if(dis[i][j]!=99999999)
            {
                if(maxn<dis[i][j])maxn=dis[i][j];
            }
        }   
       // printf("\n");
    } //��Ϊ�ж���ֱ��������Ҫ��ֱ�������
   // printf("%d\n",maxn);
    f(i,1,n)
    {
        f(j,1,n)
        {
            if(maxn==dis[i][j])
            {
                m++;
                maxx[m]=i;
                maxy[m]=j;
//                printf("%d %d\n",i,j);
            }
        }   
    } //Ȼ������ж˵�ŵ�������,����ö��
 //   printf("%d",m);
    int minn=99999999;
    f(i,1,n)
    {
        f(j,1,n)//ö������������(��Ϊ���������Ŀ����˻���һ����,������������)
        {
            int ans=0;
            f(l,1,m)//ö��ֱ��
            {
                if(dis[i][j]!=99999999&&dis[i][j]<=s&&dis[maxx[l]][i]+dis[i][j]+dis[j][maxy[l]]==maxn)//�ж��߶��Ƿ���ֱ��l��
                {
                    f(k,1,n)//ö�����е��ƫ�ľ�
                    {
                        if(k!=i&&k!=j)//����
                        ans=max(ans,(dis[k][i]+dis[k][j]-dis[i][j])/2);//�жϵ�k���߶�(i,j)�ľ���
//                        printf("%d\n",ans); 
                    }
                    minn=min(minn,ans);//��Сƫ�ľ�
                }
            }
        }
    }
    cout<<minn;//~~���������~~
}
