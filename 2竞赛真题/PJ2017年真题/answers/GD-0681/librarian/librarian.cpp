#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,len,Book[10001],Pow[11],num;
int main()
{
    freopen("librarian.in","r",stdin);
    freopen("librarian.out","w",stdout);
    Pow[0]=1;
    for(int i=1;i<=10;i++)
      Pow[i]=Pow[i-1]*10;
    cin>>n>>q;
    for(int i=1;i<=n;i++)
      cin>>Book[i];
    sort(Book+1,Book+n+1);
    for(int i=1;i<=q;i++)
    {
        cin>>len>>num;
        for(int j=1;j<=n;j++)
        {
            if(Book[j]%Pow[len]==num)
            {
                cout<<Book[j]<<endl;
                break;
            }
            if(j==n) cout<<"-1"<<endl;
        }
    }
    return 0;
}
