//prim À„∑® 
//∂—”≈ªØ O(nlog2n)
#include<iostream>
#include<cstring> 
#define maxn 5005
#define INF 99999999
int n,m,ans;
int g[maxn][maxn]; 
int key[maxn];
struct node{
	int value;
	int pos;
}heap[maxn];
int used[maxn];
using namespace std;
void put(int x,int y){
	int now,next;
    heap[++heap[0].value].value=x;
    heap[++heap[0].value].pos=y;
    now=heap[0].value;
    while(now>1){
    	next=now/2;//’“∏∏«◊
		if(heap[now].value>heap[next].value) return;
		swap(heap[now],heap[next]);
		now=next;
	}
	return;
}
int del(){
	int now,next,num;
	num=heap[1].pos;
	heap[1].pos=heap[heap[0].value--].pos;
	now=1;
	while(now*2<=heap[0].value){
		next=now*2;
		if(next<heap[0].value&&heap[next+1].value<heap[next].value) next++;
		if(heap[now].value<=heap[next].value) return num;
		swap(heap[now],heap[next]);
		now=next;
	}
	return num;
} 
long long prim(){
    memset(key,0x7f,sizeof(key));	
    key[1]=0;
    memset(used,0,sizeof(used));
    for(int i=1;i<=n;i++){
        int k=0;
        //int min=INF;
        put(key[i],i);
		k=del();
		/*for(int j=1;j<=n;j++){
            if(used[j]==0&&key[j]<key[k])
              k=j;
        } */
        used[k]=1;
        for(int j=1;j<=n;j++){
        	if(used[j]==0&&g[k][j]<key[j])
        	    key[j]=g[k][j];
        }
    }
    long long sum=0;
    for(int u=1;u<=n;u++) sum+=key[u];
    return sum;
}
int main(){
    int a,b,c;
    //freopen("data.in","r",stdin);
    cin>>n>>m;
     for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){ 
            if(i==j)g[i][j]=0;
            else g[i][j]=INF;
        }
	} 
    for(int i=1;i<=m;i++){
   	     cin>>a>>b>>c;
   	    if(c<g[a][b])
   	     {
   	     	g[a][b]=g[b][a]=c;
        }
   	      
    }
    ans=prim();
    if(ans>=10000000)cout<<"orz"<<endl;
    else cout<<ans;
    return 0;
} 
