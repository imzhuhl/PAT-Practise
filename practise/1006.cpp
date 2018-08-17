#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct People {
	char name[20];
	int inhh, inmm, inss;
	int outhh, outmm, outss;
};

bool cmp1(const People &a, const People &b) {
	if (a.inhh == b.inhh) {
		if (a.inmm == b.inmm) {
			return a.inss < b.inss;
		}
		return a.inmm < b.inmm;
	}
	return a.inhh < b.inhh;
}
bool cmp2(const People &a, const People &b) {
	if (a.outhh == b.outhh) {
		if (a.outmm == b.outmm) {
			return a.outss > b.outss;
		}
		return a.outmm > b.outmm;
	}
	return a.outhh > b.outhh;
}

int m;
vector<People> record;

int main() {
	scanf("%d", &m);
	getchar();
	record.resize(m);
	for (int i = 0; i < m; i++) {
		int hh, mm, ss;
		scanf("%s", record[i].name);
		scanf("%d:%d:%d", &hh, &mm, &ss);
		record[i].inhh = hh;
		record[i].inmm = mm;
		record[i].inss = ss;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		record[i].outhh = hh;
		record[i].outmm = mm;
		record[i].outss = ss;
	}
	sort(record.begin(), record.end(), cmp1);
	printf("%s ", record[0].name);
	sort(record.begin(), record.end(), cmp2);
	printf("%s\n", record[0].name);
	
	
	return 0;
}