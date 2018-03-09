#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

const int billion = 1000000000;
const int thousand = 1000;
const int million = 1000000;

bool cmp (pair<double, int> &a, pair<double, int> &b) {
    return a.first > b.first;
}

int main() {
    int n, d;
    scanf("%d%d", &n, &d);

    vector<double> amount;
    vector<double> price;
    pair<double, int> avgprice[1001];

    double x;
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x);
        amount.push_back(x);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x);
        avgprice[i].first = x / amount[i];
        // printf("%lf, ", x / amount[i]);
        avgprice[i].second = i;
        price.push_back(x);
    }

    sort(avgprice, avgprice + n, cmp);

    double need = d;
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        double perprice = avgprice[i].first;
        int id = avgprice[i].second;
        double have = amount[id];
        // printf("price: %lf\n", price[id]);
        if (have > need) {
            sum += need * perprice;
            break;
        } else if (have < need) {
            sum += price[id];
            need -= have;
        } else {
            sum += price[id];
            break;
        }
    }

    printf("%.2lf\n", sum);

    return 0;
}