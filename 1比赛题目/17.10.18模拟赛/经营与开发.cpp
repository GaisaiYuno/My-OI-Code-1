//��� ��Ӫ�뿪�� 
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
/*������ſ���������⣬�ó�i-n������1���;ö����ܻ�õ�������棬
�Ӻ���ǰdp���ó����ֵ����w���Ǵ�*/
