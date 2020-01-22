#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
int main() {
	ifstream infile;
	infile.open("librarian.in");
	ofstream outfile;
	outfile.open("librarian.out");
    int n,q;
    infile >> n >> q;
    int book[1001]={0};
    for (int i=1;i<=n;++i)
    	infile >> book[i];
    sort(book+1,book+n+1);
    for (int i=1;i<=q;++i)
    {
    	int size,need;bool have=false;
    	infile >> size >> need;
        int m=1;
        for (int j=1;j<=size;++j)
            m*=10;
    	for (int z=1;z<=n;++z)
    	{
    		if ((book[z]%m)==need)
    		{
    			outfile << book[z] << endl;
    			have=true;
    			break;
    		}
    	}
    	if (!have) outfile << -1 << endl;
    }
	infile.close();
	outfile.close();
	return 0;
}

