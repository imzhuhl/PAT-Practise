#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int n, m;
struct Student {
	int id;
	int c, m, e, a;
	int rc, rm, re, ra;
};
Student stu[2005];

bool byc(const Student &a, const Student &b) {
	return a.c > b.c;
}
bool bym(const Student &a, const Student &b) {
	return a.m > b.m;
}
bool bye(const Student &a, const Student &b) {
	return a.e > b.e;
}
bool bya(const Student &a, const Student &b) {
	return a.a > b.a;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &stu[i].id, &stu[i].c, &stu[i].m, &stu[i].e);
		stu[i].a = (stu[i].c + stu[i].m + stu[i].e) / 3;
	}
	sort(stu, stu + n, byc);
	stu[0].rc = 1;
	for (int i = 1; i < n; i++) {
		if (stu[i].c == stu[i - 1].c) {
			stu[i].rc = stu[i - 1].rc;
		} else {
			stu[i].rc = i + 1;
		}
	}
	sort(stu, stu + n, bym);
	stu[0].rm = 1;
	for (int i = 1; i < n; i++) {
		if (stu[i].m == stu[i - 1].m) {
			stu[i].rm = stu[i - 1].rm;
		} else {
			stu[i].rm = i + 1;
		}
	}
	sort(stu, stu + n, bye);
	stu[0].re = 1;
	for (int i = 1; i < n; i++) {
		if (stu[i].e == stu[i - 1].e) {
			stu[i].re = stu[i - 1].re;
		} else {
			stu[i].re = i + 1;
		}
	}
	sort(stu, stu + n, bya);
	stu[0].ra = 1;
	for (int i = 1; i < n; i++) {
		if (stu[i].a == stu[i - 1].a) {
			stu[i].ra = stu[i - 1].ra;
		} else {
			stu[i].ra = i + 1;
		}
	}
	
	// m lines
	for (int v = 0; v < m; v++) {
		int sid;
		scanf("%d", &sid);
		int idx = -1;
		for (int i = 0; i < n; i++) {
			if (sid == stu[i].id) {
				idx = i;
				break;
			}
		}
		if (idx == -1) {
			printf("N/A\n");
			continue;
		}
		Student *p = &stu[idx];
		if (p->ra <= p->rc && p->ra <= p->rm && p->ra <= p->re) {
			printf("%d A\n", p->ra);
		} else if (p->rc <= p->rm && p->rc <= p->re) {
			printf("%d C\n", p->rc);
		} else if (p->rm <= p->re) {
			printf("%d M\n", p->rm);
		} else {
			printf("%d E\n", p->re);
		}
		
	}
	
	
	return 0;
}