#include<iostream>
#include<fstream>
using namespace std;
int a[1005],b[1005][2];
int mins;
int n,q;
int main()
{
    freopen("librarian.in","r",stdin);
    freopen("librarian.out","w",stdout);
    cin>>n>>q;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=q;i++)
    {
        int k;
        cin>>k>>b[i][2];
        b[i][1]=1;
        for (int j=1;j<=k;j++)
        b[i][1]=b[i][1]*10;
    } 
    int k;       
    for (int i=1;i<=q;i++)
    {
        mins=100000000;
        for (int j=1;j<=n;j++)
        {
            k=a[j]%b[i][1];
            if (k==b[i][2])
                if (a[j]<mins)
                    mins=a[j];
        }
        if (mins!=100000000)
           cout<<mins<<endl;
        else 
           cout<<-1<<endl;
    }
    return 0;
}
