//洛谷 经营与开发 
#include<iostream>
#include<cstdio> 
#define maxn 100005
using namespace std;
int type[maxn];
int n;
double value[maxn];
double k,c,w;
double ans=0;
int main(){
	cin>>n>>k>>c>>w;
	for(int i=1;i<=n;i++) cin>>type[i]>>value[i]; 
    k=(1-0.01*k);
    c=(1+0.01*c);
    for(int i=n;i>=1;--i)
    {
        if(type[i]==1)ans=max(k*ans+value[i],ans);
        else ans=max(ans*c-value[i],ans);
    }
    printf("%.2f",ans*w);
    return 0;
}
/*如果倒着考虑这个问题，得出i-n的星球1点耐久度所能获得的最大收益，
从后往前dp，得出最大值最后乘w就是答案*/
