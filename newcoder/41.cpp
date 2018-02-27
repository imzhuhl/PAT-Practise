#include <iostream>
#include <map>
using namespace std;

int main() {
    int N, head;
    cin >> N >> head;
    int next[100000];
    int num[100000];
    map<int, int> rst;

    for (int i = 0; i < N; i++) {
        int id;
        cin >> id;
        cin >> num[id] >> next[id];
    }
    if (head == -1) {
        printf("0 -1\n");
        return 0;
    }
    rst[num[head]] = head;
    int n = next[head];
    while (n != -1) {
        rst[num[n]] = n;
        n = next[n];
    }


    map<int, int>::iterator it1, it2;
    it1 = rst.begin();
    printf("%lu %05d\n", rst.size() , it1->second);
    printf("%05d %d ", it1->second, it1->first);
    it1++;
    while (it1 != rst.end()) {
        printf("%05d\n", it1->second);
        printf("%05d %d ", it1->second, it1->first);
        it1++;
    }
    printf("-1\n");

    return 0;
}