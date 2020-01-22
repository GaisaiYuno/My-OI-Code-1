#include<fstream>;
using namespace std;
ifstream fin("score.in");
ofstream fout("score.out");
int a,b,c;
int main()
{
    fin>>a>>b>>c;
    fout<<a/10*2+b/10*3+c/10*5;
    return 0;
}
