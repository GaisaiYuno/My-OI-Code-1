#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std;
int n,q;
int N[1005],Q[3][1005],NL[1005];
long pows(int x){
	long tem=1;
	for(int i=1;i<=x;i++)
		tem*=10;
	return tem;
}
void check_N(int x){
	int c=0,i=N[x];
	while(i>0){
		i/=10;
		c++;
	}
	NL[x]=c;
}
void work(int x){
	int mins=10000000,mini=0;
	for(int i=1;i<=n;i++){
		if(Q[1][x]>NL[i])
			continue;
		else if(Q[1][x]==NL[i] && Q[2][x]==N[i]){
			printf("%d\n",N[i]);
			return ;
		}
		else if(Q[1][x]<NL[i]){
			int tem=N[i]%pows(NL[i]-(NL[i]-Q[1][x]));
//						cout<<"tem:"<<tem<<endl;
//						cout<<"N[i]:"<<N[i]<<endl;
//						cout<<"NL[i]:"<<NL[i]<<endl;
//						cout<<"Q[2][x]:"<<Q[2][x]<<endl;
//						cout<<"Q[1][x]:"<<Q[1][x]<<endl<<endl;
			if(tem==Q[2][x] && N[i]<mins){
				mins=N[i];
				mini=i;
			}
		}
	}
	if(mini==0 && mins==10000000)
		cout<<-1<<endl;
	else
		printf("%d\n",N[mini]);
}
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		scanf("%lld",&N[i]);
	sort(N+1,N+n+1);
	for(int i=1;i<=n;i++)
		check_N(i);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&Q[1][i],&Q[2][i]);
		work(i);
	}
//	for(int i=1;i<=n;i++)
//		cout<<"N[i]:"<<N[i]<<' '<<"NL[i]:"<<NL[i]<<endl;
	return 0;
}

