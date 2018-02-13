#include <iostream>
#include <cmath>
#include <vector>
#include <stack>
using namespace std;


int main() {
    int n;
    double p, r;
    vector<int> node[100000];
    int level[100000];
    cin >> n >> p >> r;
    // vector<int> retailer;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        node[i].push_back(x);
        if (x == 0) {
            int count;
            cin >> count;
            node[i].push_back(count);
            continue;
        }
        for (int j = 0; j < x; j++) {
            int id;
            cin >> id;
            node[i].push_back(id);
        }
    }

    level[0] = 0;
    stack<int> st;
    st.push(0);
    double sum = 0.0;
    while (!st.empty()) {
        int x = st.top();
        st.pop();
        int count = node[x][0];
        if (count != 0) {
            for (int i = 1; i <= count; i++) {
                st.push(node[x][i]);
                level[node[x][i]] = level[x] + 1;
            }
        } else {
            int count = node[x][1];
            sum += p * pow(1 + r/100, level[x]) * count;
        }
    }

    printf("%.1lf\n", sum);

    return 0;
}
