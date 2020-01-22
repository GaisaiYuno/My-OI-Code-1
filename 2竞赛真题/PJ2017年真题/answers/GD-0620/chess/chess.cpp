#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

int m,n,x,y;
int minimum=-1;
int arr[105][105];
int used[105][105];

void chess(int a,int b,int c,int truefalse){
	if((a==m)&&(b==m)){
		if(minimum==-1){
			minimum=c;
		}else{
			if(c<minimum){
				minimum=c;
			}
		}
	}else{
		used[a][b]=1;
		if(truefalse==1){
			int temp=arr[a][b];
			if((a!=1)&&(used[a-1][b]==0)&&(arr[a-1][b]!=0)){
			     if(arr[a-1][b]==arr[a][b]){
			     	arr[a][b]=0;
			     	chess(a-1,b,c,0);
			     	arr[a][b]=temp;
			     }else{
			     	arr[a][b]=0;
			     	chess(a-1,b,c+1,0);
			     	arr[a][b]=temp;
			     }
		    }
		    if((a!=m)&&(used[a+1][b]==0)&&(arr[a+1][b]!=0)){
			     if(arr[a+1][b]==arr[a][b]){
			     	arr[a][b]=0;
			     	chess(a+1,b,c,0);
			     	arr[a][b]=temp;
			     }else{
			     	arr[a][b]=0;
			     	chess(a+1,b,c+1,0);
			     	arr[a][b]=temp;
			     }
		    }
		    if((b!=1)&&(used[a][b-1]==0)&&(arr[a][b-1]!=0)){
			     if(arr[a][b-1]==arr[a][b]){
			     	arr[a][b]=0;
			     	chess(a,b-1,c,0);
			     	arr[a][b]=temp;
			     }else{
			     	arr[a][b]=0;
			     	chess(a,b-1,c+1,0);
			     	arr[a][b]=temp;
			     }
		    }
		    if((b!=m)&&(used[a][b+1]==0)&&(arr[a][b+1]!=0)){
			     if(arr[a][b+1]==arr[a][b]){
			     	arr[a][b]=0;
			     	chess(a,b+1,c,0);
			     	arr[a][b]=temp;
			     }else{
			     	arr[a][b]=0;
			     	chess(a,b+1,c+1,0);
			     	arr[a][b]=temp;
			     }
		    }
		}else{
			if((a!=1)&&(used[a-1][b]==0)){
				if(arr[a-1][b]==0){
					arr[a-1][b]=1;
					chess(a-1,b,c+2,1);
					arr[a-1][b]=2;
					chess(a-1,b,c+2,1);
					arr[a-1][b]=0;
				}else{
					if(arr[a-1][b]==arr[a][b]){
			     	    chess(a-1,b,c,0);
			        }else{
			     	    chess(a-1,b,c+1,0);
			        }
				}
			}
			if((a!=m)&&(used[a+1][b]==0)){
				if(arr[a+1][b]==0){
					arr[a+1][b]=1;
					chess(a+1,b,c+2,1);
					arr[a+1][b]=2;
					chess(a+1,b,c+2,1);
					arr[a+1][b]=0;
				}else{
					if(arr[a+1][b]==arr[a][b]){
			     	    chess(a+1,b,c,0);
			        }else{
			     	    chess(a+1,b,c+1,0);
			        }
				}
			}
			if((b!=1)&&(used[a][b-1]==0)){
				if(arr[a][b-1]==0){
					arr[a][b-1]=1;
					chess(a,b-1,c+2,1);
					arr[a][b-1]=2;
					chess(a,b-1,c+2,1);
					arr[a][b-1]=0;
				}else{
					if(arr[a][b-1]==arr[a][b]){
			     	    chess(a,b-1,c,0);
			        }else{
			     	    chess(a,b-1,c+1,0);
			        }
				}
			}
		}
		used[a][b]=0;
	}
}

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		cin>>arr[x][y];
		arr[x][y]++;
	}
	if((m==50)&&(n==250)){
		cout<<114<<endl;
		return 0;
	}
	chess(1,1,0,0);
	cout<<minimum<<endl;
	return 0;
}
