#include<cstring>
#include<iostream>
using namespace std;
int l,m,b,e,tree[100010];
int main()
{   int ans;
    memset(tree,1,sizeof(tree));
    cin>>l>>m;
    int x,y;
    for (int i=0;i<m;i++)
    {
        cin>>x>>y;
        for(int j=x;i<=y;i++) tree[i] = 0;
    }
    for(int k=0;k<l;k++)
       if(tree[k]) ans++;
    cout<<ans<<endl;
    return 0;
}
