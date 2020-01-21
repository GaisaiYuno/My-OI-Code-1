//¬Âπ» ∑‚À¯—Ùπ‚¥Û—ß 
 #include<iostream> 
#include<vector> 
#define maxn 1000000
using namespace std;
vector <int> ZHH[maxn];
int Flag[maxn];
int m,n,q,d;
int x,y,ans;
bool dfs(int u){ 
    d++;
    for(int i=0;i<ZHH[u].size();i++){
         int v=ZHH[u][i];
         if(!Flag[v]){
             Flag[v]=3-Flag[u];
             if(Flag[v]==1) q++;
             if(!dfs(v)) return false;
         }
         else if(Flag[u]==Flag[v]) return false;
    }
    return true;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        ZHH[x].push_back(y);
        ZHH[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        if(!Flag[i]){
            q=1;
            d=0;
            Flag[i]=1;
            if(!dfs(i)){
                cout<<"Impossible";
                return 0;
            }
            if(d>1) ans+=min(q,d-q);
        }
    }
    cout<<ans;
    return 0;
}
