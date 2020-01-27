//hdu 1518 
//递归写法 
#include<iostream>
#include<cstring>
#include<algorithm>
#define maxn 25
using namespace std;
int n,m,sum;
int l[maxn],used[maxn];
bool dfs(int edge_cnt,int stick_cnt,int total/*当前处理的边已经完成的长度*/){
	if(edge_cnt==3) return true;//优化,因为总和为4的倍数，做三边就可以了 
	for(int i=stick_cnt;i<=m;i++){
		if(used[i]==0){
			if(total+l[i]<sum/4){
				used[i]=1;
				//printf("dfs(%d,%d,%d)",edge_cnt,i+1,total+l[i]);
				if(dfs(edge_cnt,i+1,total+l[i])) return true;
				else used[i]=0;
			}
			else if(total+l[i]==sum/4){
				used[i]=1;
				//printf("dfs(%d,%d,%d)",edge_cnt+1,i+1,0);
				if(dfs(edge_cnt+1,0,0)) return true;
				else used[i]=0;
			}
			else continue;
		}
	}
	return false;
}
int main(){
	cin>>n;
	while(n--){
		sum=0; 
		cin>>m;
		for(int i=1;i<=m;i++) {
		   cin>>l[i];
		   sum+=l[i];
		} 
		sort(l+1,l+1+m);
		memset(used,0,sizeof(used));
		if(sum%4!=0||l[m]>sum/4)cout<<"no"<<endl; 
		else if(dfs(0,1,0)) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}
