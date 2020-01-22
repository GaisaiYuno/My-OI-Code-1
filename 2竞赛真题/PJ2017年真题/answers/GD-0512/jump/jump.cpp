#include<fstream>
using namespace std;
ifstream fin("jump.in");
ofstream fout("jump.out");
int n,d,k;
int x[500005],s[500005];
long long a[10000005],b[10000005];
int maxx;
int head,tail,sta,stan;
int mon;
bool d1,d2;
int maxxx;
int r(int a)
{
    if(a>0)
    return a;
    return -a;
}
int main()
{
    fin>>n>>d>>k;
    for(int i=0;i<10000005;i++)
    a[i]=0;
    maxx=maxxx=0;
    for(int i=0;i<n;i++)
    {
        fin>>x[i]>>s[i];
        if(s[i]>0)
        maxxx+=s[i];
        if(x[i]>maxx)
        maxx=x[i];
    }
    if(maxxx<k)
    {
        fout<<-1;
        return 0;
    }
    for(int i=0;i<maxx;i+=d)
    {
        for(int j=0;j<n;j++)
        {
            if(x[j]>i)
            {
                sta=s[j];
                head=j;
                tail=j;
            }
        }    
        
        d1=d2=1;
        for(;d1||d2;)
        {
            if(head>=n)d1=0;
            if(tail<0)d2=0;
            if((x[head]+1>x[tail-1]||!d2)&&d1)
            {
                
                if(s[head+1]>sta)
                {
                    a[r(x[head+1]-i)]+=s[head+1]-sta;
                    sta=s[head+1];
                }
                head++;
            }
            else
            {
                if(s[tail-1]>sta)
                {
                    a[r(x[tail-1]-i)]+=s[tail-1]-sta;
                    sta=s[head+1];
                }
                tail--;
            }
        }
    }
    mon=0;
    for(int i=0;i<maxx;i++)
    {
        mon+=a[i];
        if(mon>k)
        {
            fout<<i;
            break;
        }
        
    }
    return 0;
}
