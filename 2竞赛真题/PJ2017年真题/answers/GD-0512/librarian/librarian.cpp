#include<fstream>
using namespace std;
ifstream fin("librarian.in");
ofstream fout("librarian.out");
int n,q,minn,kq[1005];
int num[1005];
int nnum[1005];
int w(int a)
{
    int ans=1;
    for(int i=0;i<a;i++)
    {
        ans*=10;
    }
    return ans;
}
int main()
{
    fin>>n>>q;
    for(int i=0;i<n;i++)
    {
        fin>>num[i];
    }
    for(int i=0;i<q;i++)
    {
        fin>>kq[i];
        fin>>nnum[i];
        minn=10000005;
        for(int j=0;j<n;j++)
        {
            if((num[j]-nnum[i])%w(kq[i])==0&&num[j]<minn)
            minn=num[j];
        }
        if(minn!=10000005)
        fout<<minn<<endl;
        else
        fout<<-1<<endl;
    }
    return 0;
}
