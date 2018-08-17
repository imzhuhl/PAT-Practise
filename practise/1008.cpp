#include <iostream>

using namespace std;


int main() {
	int n;
	scanf("%d", &n);
	int total = 0, floor = 0;
	for (int i = 0; i < n; i++) {
		int req;
		scanf("%d", &req);
		if (req > floor) {
			total += (req - floor) * 6 + 5;
			floor = req;
		} else {
			total += (floor - req) * 4 + 5;
			floor = req;
		}
	}
	printf("%d\n", total);
	
	
	return 0;
}