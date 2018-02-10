#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, string> mymap;
    mymap.insert(pair<string, string>("hehe", "gg"));
    cout << mymap["hehe"] << endl;
}