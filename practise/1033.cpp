#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

double Cmax, D, Davg;
int N;
double maxdis;
map<double, double> station;
pair<double, double> oil[501];
int len = 0;
double dissum = 0.;
bool could = false;

double result = 0.0;

bool cmp(pair<double, double> &a, pair<double, double> &b) {
    return a.first > b.first;
}

bool use(double currdis) {
    double totalvol = (currdis - dissum) / Davg;
    if (totalvol == 0) return true;
    for (int i = 0; i < len; i++) {
        double vol = oil[i].second;
        double price = oil[i].first;
        // printf("(%lf,%lf) ", price, vol);
        if (totalvol >= vol) {
            result += price * vol;
            totalvol -= vol;
            oil[i].first = 0.0;
            oil[i].second = 0.0;
        } else {
            result += totalvol * price;
            oil[i].second = vol - totalvol;
            totalvol = 0.0;
            break;
        }
    }
    if (totalvol == 0.0) {
        dissum = currdis;
        return true;
    } else {
        dissum += Cmax * Davg;
        return false;
    }

}

void fill(double currdis) {
    sort(oil, oil + 500, cmp);
    double currprice = station[currdis];
    int cnt = 0;
    double havevol = 0.0;
    for (int i = 0; i < 500; i++) {
        if (oil[i].first > 0.0) {
            cnt++;
        }
    }
    int c = 0;
    for (int i = 0; i < cnt; i++) {
        if (oil[i].first >= currprice) {
            oil[i].first = 0.0;
            oil[i].second = 0.0;
            c++;
        } else {
            havevol += oil[i].second;
        }
    }
    oil[500].first = currprice;
    oil[500].second = Cmax - havevol;
    // printf("fill: %lf %lf\n", currprice, Cmax - havevol);
    sort(oil, oil + 501, cmp);
    sort(oil, oil + cnt - c + 1);
    len = cnt - c + 1;
    // printf("fill: %d %lf\n", len, oil[0].first);
}

int main() {
    scanf("%lf%lf%lf%d", &Cmax, &D, &Davg, &N);
    for (int i = 0; i < N; i++) {
        double dis, price;
        scanf("%lf%lf", &price, &dis);
        if (station.find(dis) != station.end()) {
            if (station[dis] > price)
                station[dis] = price;
        } else {
            station[dis] = price;
        }
    }
    station[D] = 0;
    N = station.size();
    // maxdis = Cmax * Davg;
    for (int i = 0; i < 501; i++) {
        oil[i].first = 0.0;
        oil[i].second = 0.0;
    }

    map<double, double>::iterator it = station.begin();
    for (; it != station.end(); it++) {
        double dis = it->first;
        double price = it->second;
        could = use(dis);
        if (could == false) {
            break;
        }
        fill(dis);
    } 

    if (could) {
        printf("%.2lf\n", result);
    } else {
        if (station.find(0.0) == station.end()) dissum = 0.0;
        printf("The maximum travel distance = %.2lf\n", dissum);
    }

    return 0;
}