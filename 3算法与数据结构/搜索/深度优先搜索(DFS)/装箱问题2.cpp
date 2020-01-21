#include<iostream>
#include<algorithm>
using namespace std;
int huo[100],used[100];
int min1,tot,n,sum=0;
void dfs(int rest,int last){
    if(rest<min1) {
        min1=rest;
        for(int i=0;i<n;i++) cout<<used[i]<<' ';
        cout<<endl;
    }
    for(int i=last+1;i<n;i++){
        if(rest>=huo[i]){
            used[i]=1;
            dfs(rest-huo[i],i);
            used[i]=0;
        }
    }
}
int main(){
    cin>>tot>>n;
    min1=tot;
    for(int i=0;i<n;i++){
        cin>>huo[i];
        sum+=huo[i];
    } 
    sort(huo,huo+n);
    if(tot>=sum) cout<<tot-sum;
    else{
        dfs(tot,-1);
        cout<<min1;
    }
}
