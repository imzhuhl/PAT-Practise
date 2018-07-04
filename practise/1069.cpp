#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	char a[10000], b[10000];
	int num, len;
	scanf("%d", &num);
	while (1) { 
		sprintf(b, "%04d", num);
		len = strlen(b);
		sort(b, b + len);
		for (int i = 0; i < len; i++) {
			a[i] = b[len - i - 1];
		}
		a[len] = '\0';
		printf("%s - %s = ", a, b);
		int an, bn;
		an = atoi(a);
		bn = atoi(b);
		num = an - bn;
		printf("%04d\n", num);
		if (num == 0 || num == 6174) {
			break;
		}
	}
	
	return 0;
}