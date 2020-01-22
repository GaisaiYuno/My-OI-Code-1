/*某校大门外长度为L的马路上有一排树，每两棵相邻的树之间的间隔都是1米。
我们可以把马路看成一个数轴，马路的一端在数轴0的位置，另一端在L的位置；
数轴上的每个整数点，即0，1，2，……，L，都种有一棵树。
由于马路上有一些区域要用来建地铁。这些区域用它们在数轴上的起始点和终止点表示。
已知任一区域的起始点和终止点的坐标都是整数，区域之间可能有重合的部分。
现在要把这些区域中的树（包括区域端点处的两棵树）移走。
你的任务是计算将这些树都移走后，马路上还有多少棵树。*/
#include<iostream>
#include<cstring>
using namespace std;
int clean(int road2[],int start2[],int end2[]){
  int m,n;
  int out=0;
  for(int i=0;i<sizeof(start2);i++){
    m=start2[i];
   n=end2[i];
     for(int k=m;i<=n;k++){
       if(road2[k]==0) break;
       else road2[k]==0;
    }
  for(int p=0;p<sizeof(road2);p++){
   if(road2[p]==1) out=out+1;
   }
  }
  return out;
}
int main (){
int l;
int m;
int a,b;
int ans;
//freopen("tree.in.txt","r",stdout);
//freopen("tree.out.txt","w",stdout);
cin>>l>>m;
int road[l-1];
int start[m-1];
int end[m-1];
//memset(road,1,sizeof(road));
for(int q=0;q<l;q++){
  road[q]=1;
}
for(int i=0;i<m;i++){
 cin>>a;
 start[i]=a;
 cin>>b;
 end[i]=b;
}
ans=clean(road,start,end);
cout<<ans;
return 0;
}
