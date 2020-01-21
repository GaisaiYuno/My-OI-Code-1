//东风谷早苗 
#include<iostream>
#include<cstdio>
using namespace std;
string s;
int t,len,a,b,x,y;
int main(){
	cin>>s;
	cin>>t;
	len=s.length();
	for(int i=0;i<len;i++)
    {
        if(s[i]=='E') x++;
        if(s[i]=='W') x--;
        if(s[i]=='N') y++;
        if(s[i]=='S') y--;
    }
    x=x*(t/len);
    y=y*(t/len);
    for(int i=0;i<t%len;i++)//模拟剩下的步数
    {
        if(s[i]=='E') x++;
        if(s[i]=='W') x--;
        if(s[i]=='N') y++;
        if(s[i]=='S') y--;
    }
    cout<<x<<' '<<y;
    return 0;
} 
