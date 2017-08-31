//Tutorial Link : https://www.topcoder.com/community/data-science/data-science-tutorials/geometry-concepts-basic-concepts/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <stdio.h>
#include <queue>
#include <set>
#include <list>
#include <cmath>
#include <assert.h>
#include <bitset>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip> //cout << setprecision(node) << fixed << num

#define mp make_pair
#define pb push_back
#define x first
#define y second
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << "\n";
#define all(V) V.begin(), V.end()
typedef long long int ll;
typedef long double ld;
typedef std::pair <int, int> ii;
typedef std::vector <int> vi;
typedef std::vector <ll> vll;
const int INF = int(1e9);
const ll INF64 = ll(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;


using namespace std;

bool equal(double a, double b) {
    return (fabs(a-b) < EPS);
}
double DEG_to_RAD(double theta) {
    return theta * PI / 180.0;
}
struct point {
    double x, y;
    point() { x = y = 0; }
    point(double _x, double _y) : x(_x), y(_y) {}
    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y;
    } 
    bool operator == (point other) const {
        return fabs(other.x - x) < EPS && fabs(other.y - y) < EPS;
    }
};
struct line { double a, b, c; };

double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}
point rotate(point p, double theta) {
    double rad = DEG_to_RAD(theta);
    return point(p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
}

void pointsToLine(point p1, point p2, line &l) {
    if (p1 == p2)
        l.a = 1.0, l.b = 0.0, l.c = -p1.x;
    else {
        l.a = -(p1.y - p2.y) / (p1.x - p2.x); //m = (y1 - y2) / (x1 - x2)
        l.b = 1.0;
        l.c = -(l.a * p1.x) - p1.y;
    }
}
bool areParallel(line l1, line l2) {
    return equal(l1.a, l1.a) && equal(l1.b, l2.b);
}
bool areSame(line l1, line l2) {
    return areParallel(l1, l2) && equal(l1.c, l2.c);
}
bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false;
    else {
        p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b); //(b2.c1 - b1.c2) / (a2.b1 - a1.b2);
        if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c); //substitute value of x into earlier eqn.
        else p.y = -(l2.a * p.x + l2.c); 
        return true;
    }
}
int main() {
    point p1(1, 3);
    point p2(5, 1);
    cout << dist(p1, p2) << endl;
    line l1;
    pointsToLine(p1, p2, l1);
    line l2 = l1;
}