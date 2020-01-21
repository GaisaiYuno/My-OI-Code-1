//洛谷 封锁阳光大学 
//已证明这个算法会MLE，应改用链表 
#include<iostream>
#include<cstring>
using namespace std;
#define max 10001
int map[max][max];
int color[max];//-1未染 1有hx 2没有hx
int n,m; 
int a1=0,a2=0;
int in1,in2;
int flag=0; 
void add_color(int now,int last){
	if(color[now]==-1) color[now]=3-last;
	if(color[now]==1) a1++;
	else a2++;
	for(int i=1;i<=map[now][0];i++){ 
         if(color[map[now][i]]==-1) add_color(map[now][i],color[now]);
         else if(color[map[now][i]]==color[now]){
		    flag=1;
		    return; 
        }
    }
    return;
}
int main(){
	memset(color,-1,sizeof(color));
	memset(map,0,sizeof(map));
	int i,ans=0;
	cin>>n>>m;
    for(i=0;i<m;i++){
		cin>>in1>>in2;
		map[in1][map[in1][0]++]=in2;
		map[in2][map[in2][0]++]=in1;
	}
	for(i=1;i<=n;i++){
	    if(color[i]==-1) add_color(i,2);
	    cout<<i<<' '<<flag<< endl;
	    for(int u=1;u<=n;u++) cout<<color[u]<<' ';
	    cout<<endl;
	    if(flag==1){
			cout<<"Impossible";
			return 0;
	    }
	    ans=ans+min(a1,a2);	
    }
	cout<<ans;
	return 0;
} 
