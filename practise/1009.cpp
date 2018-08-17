#include <iostream>
#include <vector>
using namespace std;

int main() {
	float a[1002] = {0}, c[2002] = {0};
	vector<int> ahave;
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int id;
		scanf("%d", &id);
		scanf("%f", &a[id]);
		ahave.push_back(id);
	}
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		int id;
		float num;
		scanf("%d", &id);
		scanf("%f", &num);
		for (int i = 0; i < ahave.size(); i++) {
			int aid = ahave[i];
			c[aid + id] += num * a[aid];		
		}	
	}
	
	int cnt = 0;
	for (int i = 0; i <= 2000; i++) {
		if (c[i] != 0.0) {
			cnt++;
		}
	}
	printf("%d", cnt);
	for (int i = 2000; i >= 0; i--) {
		if (c[i] != 0.0) {
			printf(" %d %.1f", i, c[i]);
		}
	}
	
	return 0;
}