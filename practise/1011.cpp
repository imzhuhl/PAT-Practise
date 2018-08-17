#include <iostream>

using namespace std;

int main() {
	double sum = 1.0;
	for (int i = 0; i < 3; i++) {
		double w, t, l;
		scanf("%lf%lf%lf", &w, &t, &l);
		if (w > t && w > l) {
			sum *= w;
			printf("W ");
		} else if (t > w && t > l) {
			sum *= t;
			printf("T ");
		} else {
			sum *= l;
			printf("L ");
		}
	}
	sum = (sum * 0.65 - 1) * 2;
	printf("%.2lf\n", sum);
	return 0;
}