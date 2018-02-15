#include <iostream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

void findprime(vector<int> &prime, int N) {
    prime.push_back(2);
    for (int i = 3; i * i < N + 1; i++) {
        int flag = 0;
        for (int j = 0; j < prime.size(); j++) {
            if (i % prime[j] == 0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            prime.push_back(i);
        }
    }
}

int main() {
    int N;
    cin >> N;

    vector<int> prime;
    findprime(prime, N);
    int num = N;
    map<int, int>rst;
    int factor = 0;
    while (num > 1) {
        if (factor >= prime.size())
            break;
        while (num % prime[factor] == 0) {
            if (rst.find(prime[factor]) == rst.end()) {
                rst.insert(pair<int, int>(prime[factor], 1));
            } else {
                rst[prime[factor]]++;
            }
            num = num / prime[factor];
        }
        factor++;
    }

    if (num != 1) {
        rst[num] = 1;
    }
    if (N == 1) {
        rst[1] = 1;
    }


    map<int, int>::iterator it = rst.begin();
    printf("%d=", N);
    for (int i = 0; it != rst.end(); it++, i++) {
        if (i) printf("*");
        if (it->second == 1) {
            printf("%d", it->first);
        } else {
            printf("%d^%d", it->first, it->second);
        }
    }
    printf("\n");

    return 0;
}