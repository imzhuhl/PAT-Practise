#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
	int sum = 0;
	string num;
	cin >> num;
	for (int i = 0; i < num.size(); i++) {
		sum += num[i] - '0';
	}
	string a = to_string(sum);
	string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	for (int i = 0; i < a.size(); i++) {
		if(i) printf(" ");
		printf("%s", arr[a[i] - '0'].c_str());
	}
	printf("\n");
	
	
	return 0;
}