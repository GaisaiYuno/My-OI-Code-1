#include<iostream>
#define maxn 1000
using namespace std; 
int a[maxn];
int n;
/*两个指针a,b
a         b
42 28 64 32 84 53

交换 
a        b
32 28 64 42 84 53

      a  b
32 28 42 64 84 534
a==b结束 
*/ 
void qsort(int l,int r){
    int zj,i,j,p;
    i=l;
    j=r;
    zj=a[(l+r)/2];
    while(i<=j){
        while(a[i]<zj){
            i++;
        }
        while(a[j]>zj){
            j--;
        }
        if(i<=j){
            p=a[i];a[i]=a[j];a[j]=p;
            i++;j--;
        }
    }
    if(l<j) qsort(l,j);
    if(i<r) qsort(i,r);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    qsort(1,n);
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
