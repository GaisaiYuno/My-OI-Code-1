//��� a-b���ԣ���ǿ�棩 
//δ�����Ż���ʱ�临�Ӷ�O(n^2) 
#include<iostream>
#define maxn 100000
using namespace std;
int n,c,ans=0;
int num[maxn];
int main(){
    cin>>n>>c;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(num[i]-num[j]==c||num[j]-num[i]==c)
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
