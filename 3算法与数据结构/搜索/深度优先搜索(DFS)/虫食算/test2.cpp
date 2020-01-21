#include<iostream>
using namespace std;
int n,x[26]={0},m[26]={0};
bool usednum[26]={0},usedlet[26]={0},ans=0;
char s1[26],s2[26],s3[26],sums[78];
bool ok(int now){
    if(now%3!=2) return true;
    int cons=now/3*3,sum=x[sums[cons]-65]+x[sums[cons+1]-65]+m[now/3];
    int temp=sum;
    sum=sum%n;
    if(sum==x[sums[cons+2]-65]){
        m[now/3+1]=temp/n;
        return true;
    }
    else return false;
}
void dfs(int now){
    if(ans) return;
    if(!ok(now-1)) return;
    if(now==3*n){
        ans=1;
        for(int i=0;i<n;i++) cout<<x[i]<<" ";
        return;
    }
    if(!usedlet[sums[now]-65]){
        for(int i=n-1;i>=0;i--){
            if(!usednum[i]){
                int tempm=m[now/3];
                x[sums[now]-65]=i;
                usednum[i]=1;
                usedlet[sums[now]-65]=1;
                dfs(now+1);
                m[now/3]=tempm;
                usednum[i]=0;
                usedlet[sums[now]-65]=0;
            }
        }
    }
    else dfs(now+1);
    return;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s1[i];
        sums[3*(n-1-i)]=s1[i];
    }
    for(int i=0;i<n;i++){
        cin>>s2[i];
        sums[3*(n-1-i)+1]=s2[i];
    }
    for(int i=0;i<n;i++){
        cin>>s3[i];
        sums[3*(n-1-i)+2]=s3[i];
    }
    dfs(0);
    return 0;
}
