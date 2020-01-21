#include <iostream>
#include <cstring>
using namespace std;
string s;
int ans,n;
int find(int x)
{
    int cnt=0;
    char front=s[x];
    char back=s[x+1];
    for(int i=x;i>=x-n;i--)//往前看和往后
    {
        if(s[i]==front) cnt++;
        else if(s[i]=='w') cnt++;
        else break;
    }
    for(int i=x+1;i<=x+1+n;i++)
    {
        if(s[i]==back)cnt++;
        else if(s[i]=='w') cnt++;
        else break;
    }
    return cnt;
}
int main()
{
    ans=-1;
    cin>>n;
	cin>>s;
    s=s+s+s;
    for(int i=n;i<2*n;i++)//三段 从中间那一段开始处理,枚举断开位置 
    {
        if(s[i]==s[i+1])//特判 
            continue;
        if(s[i]=='w')
        {
            s[i]='r';
            ans=max(ans,find(i));
            s[i]='b';
            ans=max(ans,find(i));
            s[i]='w';
        }
        ans=max(ans,find(i));
    }
    ans=min(ans,n);
    if(ans==-1)ans=n;//特判 全部都是一种颜色 
    cout<<ans;
    return 0;
}
