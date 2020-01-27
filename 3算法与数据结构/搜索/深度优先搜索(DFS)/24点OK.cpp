#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;
double a[4];
bool vis[4];
bool dfs(int step)
{
    int i,j;
    if(step == 4){   
        for(i = 0; i < 4; ++i)      
            if(!vis[i])          
                if(fabs(a[i] - 24) < 0.0001) return true;
        return false;
    }
    else{   
        for(i = 0; i < 4; ++i)      
            if(!vis[i])       
                for(j = i + 1; j < 4; ++j)              
                    if(!vis[j])
                    {
                        double tmpi = a[i];
                        double tmpj = a[j];
                        vis[j] = true;

                        a[i] = tmpi + tmpj;
                        if(dfs(step+1)) return true;

                        a[i] = tmpi*tmpj;
                        if(dfs(step+1)) return true;

                        a[i] = tmpi-tmpj;
                        if(dfs(step+1)) return true;

                        a[i] = tmpj-tmpi;
                        if(dfs(step+1)) return true;

                        a[i] = tmpi/tmpj;
                        if(dfs(step+1)) return true;

                        a[i] = tmpj/tmpi;
                        if(dfs(step+1)) return true;

                        a[i] = tmpi;
                        vis[j] = false;
                    }               
    }
    return false;
}


int main(){
    cin>>a[0]>>a[1]>>a[2]>>a[3];
    while(a[0]+a[1]+a[2]+a[3]>1){    
        memset(vis,0,sizeof(vis));
        if(dfs(1)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        cin>>a[0]>>a[1]>>a[2]>>a[3];
    }
    return 0;
}
