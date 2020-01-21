//¬Âπ» –ﬁ¿Ì≈£≈Ô 1209
#include<iostream>
#include<algorithm> 
#define maxn 200
using namespace std;
int cow[maxn];
int gap[maxn];
int comp(int x,int y){
	return x>y;
}
int main(){
	int m,s,c,sum,ans=0;
	cin>>m>>s>>c;
	for(int i=0;i<c;i++){
		cin>>cow[i];
	} 
	sort(cow,cow+c);
	for(int j=0;j<c-1;j++){
		gap[j]=cow[j+1]-cow[j]-1;
	}
	sort(gap,gap+c-1,comp);
	sum=cow[c-1]-cow[0]+1; 
	for(int k=0;k<m-1;k++){
		if(sum-gap[k]>=0)sum-=gap[k];

	}
	cout<<sum;
	return 0;
}
