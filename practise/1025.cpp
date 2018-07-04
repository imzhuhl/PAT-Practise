#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct Testee
{
	char number[15];
	int score;
	int locnum;
	int localrank;
	int rank;
};
Testee testee[30000];

bool cmp(Testee &a, Testee &b) {
	if (a.score == b.score){
		return strcmp(a.number, b.number) < 0;
	}
	return a.score > b.score;
}

int main() {
	int n, top = 0;
	scanf("%d", &n);
	for (int v = 0; v < n; v++) {
		int k;
		scanf("%d", &k);
		for (int i = top; i < top + k; i++) {
			scanf("%s %d", testee[i].number, &testee[i].score);
			testee[i].locnum = v + 1;
		}
		sort(testee + top, testee + top + k, cmp);
		int cnt = 1;
		testee[top].localrank = 1;
		for (int i = top + 1; i < top + k; i++) {
			if (testee[i].score == testee[i - 1].score) {
				testee[i].localrank = testee[i - 1].localrank;
			} else {
				testee[i].localrank = cnt + 1;
			}
			cnt++;
		}
		top += k;
	}
	printf("%d\n", top);
	sort(testee, testee + top, cmp);
	int cnt = 1;
	testee[0].rank = 1;
	for (int i = 1; i < top; i++) {
		if (testee[i].score == testee[i - 1].score) {
			testee[i].rank = testee[i - 1].rank;
		} else {
			testee[i].rank = cnt + 1;
		}
		cnt++;
	}
	for (int i = 0; i < top; i++) {
		printf("%s %d %d %d\n", testee[i].number, testee[i].rank, testee[i].locnum, testee[i].localrank);
	}

	return 0;
}