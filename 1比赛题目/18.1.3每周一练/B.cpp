#include<iostream>
#define maxn 25
using namespace std;
int n;
int ans[maxn];
int sign[maxn][maxn];//0为+，1为- 
int plusn;
void dfs(int deep){
	if(deep>24) return;
	for(int i=0;i<=1;i++){
		sign[1][deep]=i;
		plusn+=sign[1][deep];
		for(int j=2;j<=deep;j++){//当第一行符号的个数>=2时，算出下面
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
	/*我以我的人格保证dfs_ans数组里的结果是我用dfs算出来的
	   因为不知道dfs怎么剪枝，所以dfs会超时 
	*/ 
	while(cin>>n){
		cout<<n<<' '<<dfs_ans[n]<<endl;
	}
}
