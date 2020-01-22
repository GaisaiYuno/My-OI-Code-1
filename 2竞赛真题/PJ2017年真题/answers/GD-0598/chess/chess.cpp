#include <iostream>
#include <fstream>
using namespace std;
int main(){
    int i,k=0,m,n,x[1010],y[1010],c[1010];
    ifstream fin("chess.in");
    fin>>m>>n;
    for(i=1;i<n;i++){
    	fin>>x[i]>>y[i]>>c[i];
    	if(x[i]==y[i]&&x[i]!=1) k=k+1;
    }
    fin.close();
    ofstream fout("chess.out");
    if(k<5) fout<<-1;
    fout.close();
}
