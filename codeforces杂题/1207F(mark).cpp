//��ά�����¼ģ��<=sqrt(n)��ʱ��Ĵ𰸣�a[x][y]��ʾ%x=y�Ĵ𰸣�O(sqrt(n))�޸ģ�O(1)��ѯ 
//ģ��>=sqrt(n)��ʱ������O(sqrt(n))��ѯ 
#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 500000
#define maxb 720
using namespace std;
typedef long long ll;
int n;
int m;
int a[maxn+5];
ll sum[maxb+5][maxb+5];
int main(){
	int op,x,y;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&op,&x,&y);
		if(op==1){
			a[x]+=y;
			for(int i=1;i<=maxb;i++){
				sum[i][x%i]+=y;
			}
		}else{
			if(x<=maxb) printf("%I64d\n",sum[x][y]);
			else{
				ll ans=0;
				for(int i=0;x*i+y<=maxn;i++) ans+=a[x*i+y];
				printf("%I64d\n",ans);
			}
		} 
	}
}

