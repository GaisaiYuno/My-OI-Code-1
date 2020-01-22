#include <iostream>
#include <stdio.h>
#include <algorithm>

int n,q;
int books[1001];
int readers[1001];
int length[1001];

int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	std::cin >> n >> q;
	for(int i = 0;i < n;i++){
		std::cin >> books[i];
	}
	for(int i = 0;i < q;i++){
		std::cin >> length[i];
		std::cin >> readers[i];
	}
	std::sort(books,books + n);
	for(int i = 0;i < q;i++){
		int flag = 0;
		for(int j = 0;j < n;j++){
			int cache = 1;
			for(int k = 0;k < length[i];k++){
				cache *= 10;
			}
			int tmp = books[j] % cache;
			if(tmp == readers[i]){
				std::cout << books[j] << std::endl;
				flag = 1;
				break;
			}
		}
		if(flag == 0){
			std::cout << "-1" << std::endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
