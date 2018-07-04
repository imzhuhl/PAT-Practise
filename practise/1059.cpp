#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> info;
int nmax = 100000;

void generate() {
	info.push_back(2);
	int num = 3;
	int cnt = 1;
	while (cnt < nmax) {
		bool prime = true;
		int sq = (int) sqrt(num * 1.0);
		for (int i = 0; i < info.size(); i++) {
			if (sq > info[i])  break;
			if (num % info[i] == 0) {
				prime = false;
				break;
			}
		}
		if (prime) {
			info.push_back(num);
			cnt++;
		}
		num++;
	}
}


int main() {
	int n;
	scanf("%d", &n);
	printf("%d=", n);
	if (n == 1) {
		printf("1\n");
		return 0;
	}
	generate();
	int first = 0;
	for (int i = 0; i < info.size(); i++) {
		int cnt = 0;
		while (n % info[i] == 0) {
			cnt++;
			n /= info[i];
		}
		if (cnt != 0) {
			if (first) printf("*");
			else first = 1;
			printf("%d", info[i]);
		}
		if (cnt > 1) {
			printf("^%d", cnt);
		}
	}
	if (n != 1) {
		if (first == 0) printf("*");
		printf("%d", n);
	}
	printf("\n");
	return 0;
}