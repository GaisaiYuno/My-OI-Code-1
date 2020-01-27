#include<iostream>
#include<cstring>
#define maxn 27
#define INF 9999999
using namespace std;
char in[1005];
int d[maxn][maxn];
int n;
void floyd(){
	d[0][0]=0;
	for(int k=0;k<maxn;k++){
		for(int i=0;i<maxn;i++){
			for(int j=0;j<maxn;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]); 
			}
		}
	} 
}
int main(){
	for(int i=0;i<maxn;i++){
			for(int j=0;j<maxn;j++) d[i][j]=INF;
    }
	while(cin>>in){
		if(in[0]=='0'){
			//debug();
			floyd();
		    if(d['b'-'a']['m'-'a']!=INF) cout<<"Yes."<<endl;
		    else cout<<"No."<<endl;
		    //debug();
		    for(int i=0;i<maxn;i++){
			   for(int j=0;j<maxn;j++) d[i][j]=INF;
            }
		}
		else{
			d[in[0]-'a'][in[strlen(in)-1]-'a']=1;
		}
	}
}
