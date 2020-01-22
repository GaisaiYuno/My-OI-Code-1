#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

int n,d,k,sum,g,temp;
int arr[500005][2];

int jump(int place,int score){
	score+=arr[place][1];
	int maximum=0;
	if(g<d){
		int i=place+1;
		while((i<=n)&&((arr[i][0]-arr[place][0])>=d-g)&&((arr[i][0]-arr[place][0])<=d+g)){
			temp=jump(i,score);
			if(temp>maximum){
				maximum=temp;
			}
			i++;
		}
	}else{
		int i=place+1;
		while((i<=n)&&(arr[i][0]-arr[place][0]<=d+g)){
			temp=jump(i,score);
			if(temp>maximum){
				maximum=temp;
			}
			i++;
		}
	}
	return score+maximum;
}

int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(int i=1;i<=n;i++){
		cin>>arr[i][0]>>arr[i][1];
		if(arr[i][1]>0){
			sum+=arr[i][1];
		}
	}
	if(sum<k){
		cout<<-1<<endl;
		return 0;
	}
	while(jump(0,0)<k){
		g++;
	}
	cout<<g<<endl;
	return 0;
}
