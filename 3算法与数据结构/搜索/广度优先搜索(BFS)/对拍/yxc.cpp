#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1048577
using namespace std;
string str;
int queue[maxn];
short int lev[maxn];
bool done[maxn];
int main(){
	//freopen("testdata.txt","r",stdin);
    while(cin>>str){
        memset(queue,0,sizeof(queue));
        memset(lev,0,sizeof(lev));
        memset(done,0,sizeof(done));
        if(str=="1"){
        	cout<<1<<endl;
        	continue;
		} 
        int head=0,tail=1;
        int len=str.length();
        for(int i=0;i<len;i++){
            queue[1]*=2;
            queue[1]+=str[i]-'0';
        }
//        cout<<queue[1]<<endl;
        while(head<tail){
//            cout<<queue[head]<<endl;
            head++;
            if(queue[head]==0){
                cout<<lev[head]<<endl;
                break;
            }
            for(int i=1;i<len-1;i++){
                int a=queue[head]^(7<<(i-1));
                if(done[a])continue;
                done[a]=1;
                tail++;
                queue[tail]=a;
                lev[tail]=lev[head]+1;
            }
            int a=queue[head]^(3<<(len-2));
            if(!done[a]){
                done[a]=1;
                tail++;
                queue[tail]=a;
                lev[tail]=lev[head]+1;
            }
//            hhh
            a=queue[head]^3;
            if(!done[a]){
                done[a]=1;
                tail++;
                queue[tail]=queue[head]^3;
                lev[tail]=lev[head]+1;
            }
        }
        if(queue[head]!=0){
            cout<<"NO\n";
        }
    }
}
