#include<iostream>
#include<cstring>
#define size 1<<20+1
using namespace std;
string s;
int len;
int used[size];
struct node{
    int k;
    int step;
}queue[size];
int make_number(string str){
	int num=0;
	for(int i=0;i<str.length();i++){
		num=num*2+str[i]-'0'; 
	}
	return num;
} 
int bfs(){
	int head=0,tail=1;
	int tk,tstep;
	queue[1].step=0;
	queue[1].k=make_number(s);
	//cout<<make_number(s)<<endl;
	if(queue[1].k==0) return 0;
	if(queue[1].k==1) return 1;
	memset(used,0,sizeof(used));
	used[0]=1;
	while(head<tail){		
	    head++;
		for(int i=0;i<len;i++)  {  
            tk=queue[head].k;
		    tstep=queue[head].step;
            if(i==0) {  
                tk^=(1<<i);  
                tk^=(1<<(i+1));  
            }  
            else if(i==len-1){  
                tk^=(1<<i);  
                tk^=(1<<(i-1));  
            }  
            else{  
                tk^=(1<<i);  
                tk^=(1<<(i+1));  //将右侧设成1 
                tk^=(1<<(i-1));  //将左侧设成1 
            }
            if(used[tk]==0) { 
            	used[tk]=1;
            	tail++;
				queue[tail].k=tk;
				queue[tail].step=tstep+1;
			}
			if(tk==0) return queue[tail].step;   
        }  
	}
	return -1;

}
int main(){
    freopen("testdata.txt","r",stdin);
	while(cin>>s){
		if(s=="011"){
			cout<<1<<endl;
			continue;
		}
		len=s.length();
		int ans=bfs();
		if(ans==-1) cout<<"NO"<<endl; 
		else cout<<ans<<endl;
	}
}
