#include<iostream>
using namespace std;
int numb[21];
int used[21];
int ans[101];
int x=0;
int  dfs(int m,int step,int sum) {
	//cout<<"step,m,sum£º"<<step<<' '<<m<<' '<<sum<<endl;
	if(step==3) return 1;
	x=0;
	for(int i=0; i<m; i++) {
		//cout<<"numb:"<<numb[i]<<endl;
		//cout<<"x:"<<x<<endl;
		//cout<<sum/4<<' '<<used[i]<<endl;
		if(used[i]==0&&x<=sum/4) {
			x=x+numb[i];
			//cout<<"x:"<<x<<endl;
			used[i]=1;
			if(x==sum/4) dfs(m,step+1,sum);
		}
	}
	return 0;
}
int main() {
	int n,m;
	cin>>n;
	for(int p=0; p<n; p++) {
		cin>>m; 
		int sum=0;
		for(int q=0; q<m; q++) {
			cin>>numb[q];
			sum=sum+numb[q];
		}
		if(sum%4!=0) ans[p]=0;
		else {
			if(dfs(m,0,sum)) ans[p]=1;
		}
	}
	for(int k=0; k<n; k++) {
		if(ans[k]==1) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
}
