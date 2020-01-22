#include<iostream>
using namespace std;
int main(){
 int n;
 int s1[100];
 int s2[100];
 for(int k=0;k<100;k++){
  s1[k]=0;
  s2[k]=0;
 } 
 cin>>n;
 for(int i=1;i<=n;i++){
        int temp=0;
        for(int j=0; j<100; j++) {
            s1[j]=s1[j]*i+temp
            if(s1[j]>=10) temp=s1[j]/10,s1[j]%=10;
            else  temp=0;
        }
        temp=0;
        for(int j=0; j<100; j++) {
            s2[j]=s2[j]+s1[j]+temp;
            if(s2[j]>=10) temp=s2[j]/10,s2[j]%=10;
            else temp=0;
        }
    for(int i=99; i>=0; i--) {
        if(s2[i]!=0) break;
    }
    for(; i>=0; i--) cout<<s2[i]
}
return 0;
}
