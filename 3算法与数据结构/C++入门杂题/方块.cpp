//Ве№И ·Ѕїй 
#include<iostream>
#define maxn 100
using namespace std;
char sq1[maxn][maxn];
char sq2[maxn][maxn];
/*void print(){
	cout<<t;
	ans=1;
	t++;
} */
int main(){
	int i,j,n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(j=0;j<n;j++) cin>>sq1[i][j];
	}
	for(int i=0;i<n;i++){
		for(j=0;j<n;j++) cin>>sq2[i][j];
	}
	
	bool ans=1;
	for(int i=0;i<n;i++){
		for(j=0;j<n;j++) 
		if(sq1[i][j]!=sq2[j][n-1-i]) ans=0;
	}
	if(ans) {
	cout<<1;
	return 0;
	} 
	
	ans=1;
	for(int i=0;i<n;i++){
		for(j=0;j<n;j++) 
		if(sq1[i][j]!=sq2[n-1-i][n-1-j]) ans=0;
	}
    if(ans) {
	cout<<2;
	return 0;
	} 
	
	ans=1;
	for(int i=0;i<n;i++){
		for(j=0;j<n;j++) 
		if(sq1[i][j]!=sq2[n-1-j][i]) ans=0;
	}
	if(ans) {
	cout<<3;
	return 0;
	} 
	
	ans=1;
	for(int i=0;i<n;i++){
		for(j=0;j<n;j++) 
		if(sq1[i][j]!=sq2[i][n-1-j]) ans=0;
	}
	if(ans) {
	cout<<4;
	return 0;
	} 
	
	ans=1;
	for(int i=0;i<n;i++){
		for(j=0;j<(n+1)/2;j++) 
		{
            int temp=sq1[i][j];
            sq1[i][j]=sq1[i][n-1-j];
            sq1[i][n-1-j]=temp;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(sq1[i][j]!=sq2[n-1-i][n-1-j])ans=0;
        }
    }
    if(ans){
        cout<<5;
        return 0;
    }
    ans=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(sq1[i][j]!=sq2[n-1-j][i])ans=0;
        }
    }
    if(ans){
        cout<<5;
        return 0;
    }
    ans=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(sq1[i][j]!=sq2[j][n-1-i])ans=0;
        }
    }
    if(ans){
        cout<<5;
        return 0;
    }
    
    ans=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(sq1[i][j]!=sq2[i][j])ans=0;
        }
    }
    if(ans){
        cout<<6;
        return 0;
    }
    cout<<7;
	return 0;		
}
