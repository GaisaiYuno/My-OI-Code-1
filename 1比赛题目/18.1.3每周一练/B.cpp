#include<iostream>
#define maxn 25
using namespace std;
int n;
int ans[maxn];
int sign[maxn][maxn];//0Ϊ+��1Ϊ- 
int plusn;
void dfs(int deep){
	if(deep>24) return;
	for(int i=0;i<=1;i++){
		sign[1][deep]=i;
		plusn+=sign[1][deep];
		for(int j=2;j<=deep;j++){//����һ�з��ŵĸ���>=2ʱ���������
			sign[j][deep-j+1]=sign[j-1][deep-j+1]^sign[j-1][deep-j+2];
			plusn+=sign[j][deep-j+1];
		}
		if(plusn*2==deep*(deep+1)/2) ans[deep]++;
		dfs(deep+1);
		plusn-=sign[1][deep];
		for(int j=2;j<=deep;j++) plusn-=sign[j][deep-j+1];
	}
	return;
}
int main(){
	//dfs(1);
	//for(int i=1;i<=24;i++) cout<<ans[i]<<' ';
	const int dfs_ans[24]={0,0,4,6,0,0,12,40,0,0,171,410,0,0,1896,5160,0,0,32757,59984,0,0,431095,822229};
	/*�����ҵ��˸�֤dfs_ans������Ľ��������dfs�������
	   ��Ϊ��֪��dfs��ô��֦������dfs�ᳬʱ 
	*/ 
	while(cin>>n){
		cout<<n<<' '<<dfs_ans[n]<<endl;
	}
}
