//洛谷 书的复制 1281
#include<iostream>
using namespace std;
int m,k;
int page[1000];
int f[1000][1000];
void output(int x,int y,int z){
    if(!x) return;
    int k=0;
    while(k<y&&page[y]-page[y-k-1]<=z){
    	//cout<<page[y]-page[y-k-1]<<' '<<z<<endl;
	    k++;
	}
    output(x-1,y-k,z);
    cout<<y-k+1<<" "<<y<<endl;
}
int main(){
	cin>>m>>k;
	for(int a=1;a<=m;a++) cin>>page[a];
	for(int b=0;b<=m;b++){
		for(int c=0;c<=k;c++) f[b][c]=100000000;
	}
	for(int c=0;c<=k;c++) f[0][c]=0;
	page[0]=0;
	f[1][1]=page[1];
	for(int d=1;d<=m;d++) f[d][1]=f[d-1][1]+page[d];
	
	/*for(int u=0;u<=m;u++){
		for(int v=0;v<=k;v++) 	cout<<f[u][v]<<' ';
		cout<<endl;
	}*/
	for(int i=2;i<=k;i++){
		for(int j=1;j<=m;j++){
			for(int t=1;t<j;t++){
				f[j][i]=min(f[j][i],max(f[t][i-1],f[j][1]-f[t][1]));
			} 
		} 
	} 
    //	cout<<f[m][k]<<endl;
    for(int i=1;i<=m;i++) {
    	page[i]+=page[i-1];
    	//cout<<page[i]<<' ';
	}
	//cout<<endl;
	output(k,m,f[m][k]);//注意不要搞反 
	return 0;
} 
