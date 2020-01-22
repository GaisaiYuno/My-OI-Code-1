#include<bits/stdc++.h>
using namespace std;

const int maxn=1005;

int N,A,B;
int ans[maxn][maxn];

int main(){
	cin>>N>>A>>B;
	if(A!=1&&B!=1) {
		cout<<"NO"<<'\n';
	}
	else if(N<=3&&N>=2&&A==1&&B==1) {
		cout<<"NO"<<'\n';
	}
	else{
		int c=max(A,B);
		for(int i=c;i<N;i++){
			ans[i][i+1]=ans[i+1][i]=1;
		}
		cout<<"YES"<<'\n';
		if(A==1){
			for(int i=1;i<=N;i++){
				for(int j=1;j<=N;j++){
					cout<<(i==j?0:!ans[i][j]);
				}
				cout<<'\n';
			}
		}
		else{
			for(int i=1;i<=N;i++){
				for(int j=1;j<=N;j++){
					cout<<ans[i][j];
				}
				cout<<'\n';
			}
		}
	}
	return 0;
}

