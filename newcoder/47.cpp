#include <iostream>
#include <algorithm>
using namespace std;

struct station{
    double price, dis;
};

station s[505];
double cmax, d, davg;
int n;

double cost = 0.0;

bool cmp(station s1, station s2) {
    return s1.dis < s2.dis;
}

int main() {
    scanf("%lf%lf%lf%d", &cmax, &d, &davg, &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf%lf", &s[i].price, &s[i].dis);
    }
    sort(s, s + n, cmp);
    s[n].price = 0.0;
    s[n].dis = d;
    
    int now = 0;
    double oil = 0.0;
    for (; now <= n; ) {
        double currprice = s[now].price;
        double currdis = s[now].dis;
        double minprice = -1;
        int minidx = -1;
        // printf("%lf\n", s[now].dis);
        for (int i = now + 1; i <= n && s[i].dis <= currdis + cmax*davg; i++) {
            if (minprice > s[i].price || minprice < 0) {
                minprice = s[i].price;
                minidx = i;
                // printf("for: %lf\n", s[i].dis);
                if (minprice < currprice) {
                    break;
                }
            }
        }
        if (minidx == -1) {
            break;
        } else {
            if (minprice < currprice) {
                cost += (s[minidx].dis - currdis - oil * davg) / davg * currprice;
                // printf("cost: %lf\n", cost);
                oil = 0.0;
            } else {
                cost += currprice * (cmax - oil);
                oil = cmax - (s[minidx].dis - currdis) / davg;
            }
        }
        now = minidx;
    }

    if (now != n) {
        printf("The maximum travel distance = %.2lf\n", s[now].dis + davg * cmax);
    } else {
        printf("%.2lf\n", cost);
    }

    return 0;
}