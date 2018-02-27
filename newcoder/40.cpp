#include <iostream>
#include <stack>
using namespace std;

int main() {
    int M, N, K;
    cin >> M >> N >> K;

    for (int i = 0; i < K; i++) {
        bool mark = true;
        stack<int> st;
        int num = 1;
        for (int j = 0; j < N; j++) {
            int x;
            cin >> x;
            if (mark == false) 
                continue;
            while (st.empty() || st.top() != x) {
                if (st.size() >= M || num > N) {
                    mark = false;
                    break;
                }
                st.push(num);
                num++;
            }
            st.pop();
        }

        if (mark == false) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }

    return 0;
}