//sum
#include<iostream>
#include<cstdio>
#define maxn 100005 
using namespace std;
long long sum1[maxn][2], sum2[maxn][2], sum3[maxn][2], sum4[maxn][2];
/*(x+z)*(number_x+number_z) = x number_x + x number_z + z number_x + z number_z

�������֪z����������x,p��ʾ�÷���ĸ���
��һ���֣�sum1
(x1 number_x1) + (x2 number_x2) + ... + (xp * number_xp)��
�ڶ����֣�sum2
����ţ�1��...��ţ�p����*(number_z)
�������� sum3
��number_1...number_p��* (z )
���Ĳ��� sum4
p*��z * number_z��
*/
struct block{
	long long num;
	long long color;
}a[maxn];
int n,m;
long long ans,p,q;
int main(){
	//freopen("sum.in","r",stdin);
	//freopen("sum.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i].num;
	for(int i=1;i<=n;i++) cin>>a[i].color;
	ans=0;
    for(int i=1;i<=n;i++){
    	p=a[i].color;
    	q=i%2;
    	ans+=sum1[p][q]%10007;
    	ans+=(sum2[p][q]*a[i].num)%10007;
    	ans+=(sum3[p][q]*i)%10007;
    	ans+=(((sum4[p][q]*i)%10007)*a[i].num) % 10007;
    	ans%=10007;
    	sum1[p][q]+=(i*a[i].num)%10007;
        sum1[p][q]%=10007;
        sum2[p][q]+=i;
        sum2[p][q]%=10007;
        sum3[p][q]+=a[i].num;
        sum3[p][q]%=10007;
        sum4[p][q]++;
        sum4[p][q]%=10007;
	}
	cout<<ans%10007;
	return 0; 
} 
