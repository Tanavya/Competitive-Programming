#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <assert.h>
#include <set>
#include <bitset>
#include <stack>
#include <map>

using namespace std;

#define LET(x, a)  __typeof(a) x(a)
#define TR(v, it) for(LET(it, v.begin()); it != v.end(); it++)
#define si(x) scanf("%d",&x)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF 1000000000
#define MOD 1000000007
#define SET(x,y) memset(x,y,sizeof(x));
#define LL long long int
#define ULL unsigned LL
#define PII pair<int, int>
#define MAXN 100004
#define LOGMAXN 19
#define ASC 0
#define DESC 1
int P[2 * MAXN][LOGMAXN];
vector<int> v[2 * MAXN];
stack<PII> st1, st2;
int a[MAXN];
int old[MAXN];
int L[2 * MAXN];
map<int, int> mp;
class Seg {
    int *a;
    struct node {
        node *l, *r;
        int rmin, rmax;
        node() {
            l = r = NULL;
            rmin = INF;
            rmax = -1;
        }
        void recal() {
            rmin = INF;
            rmax = -1;
            if (l) {
                rmin = min(rmin, l->rmin);
                rmax = max(rmax, l->rmax);
            }
            if (r) {
                rmin = min(rmin, r->rmin);
                rmax = max(rmax, r->rmax);
            }
        }
    };
    void init(node *&cur, int cl, int cr) {
        if (cl > cr)
            return;
        if (cur == NULL)
            cur = new node();
        if (cl == cr) {
            cur->rmin = cur->rmax = a[cl];
            return;
        }
        int mid = (cl + cr) / 2;
        init(cur->l, cl, mid);
        init(cur->r, mid + 1, cr);
        cur->recal();
    }
    int ngt(node *cur, int cl, int cr, int st, int minval) {
        if (cur->rmax <= minval || cr < st)
            return INF;
        int mid = (cl + cr) / 2;
        if (cl == cr)
            return cl;
        int lloc = ngt(cur->l, cl, mid, st, minval);
        if (lloc >= INF)
            lloc = ngt(cur->r, mid + 1, cr, st, minval);
        return lloc;
    }
    int nlt(node *cur, int cl, int cr, int st, int maxval) {
        if (cur->rmin >= maxval || cr < st)
            return INF;
        int mid = (cl + cr) / 2;
        if (cl == cr)
            return cl;
        int lloc = nlt(cur->l, cl, mid, st, maxval);
        if (lloc >= INF)
            lloc = nlt(cur->r, mid + 1, cr, st, maxval);
        return lloc;
    }

    void update(node *&cur, int cl, int cr, int loc, int val) {
        if (loc < cl || loc > cr)
            return;
        if (cur == NULL)
            cur = new node();
        if (cl == cr) {
            cur->rmin = cur->rmax = val;
            return;
        }
        int mid = (cl + cr) / 2;
        update(cur->l, cl, mid, loc, val);
        update(cur->r, mid + 1, cr, loc, val);
        cur->recal();
    }
public:
    int N;
    node *top;
    Seg(int *a, int N) {
        this->N = N;
        this->a = a;
        top = NULL;
        init(top, 0, N - 1);
    }
    int next_greater_pos(int st, int minval) {
        return ngt(top, 0, N - 1, st, minval);
    }
    int next_lesser_pos(int st, int maxval) {
        return nlt(top, 0, N - 1, st, maxval);
    }
    void update(int loc, int val) {
        update(top, 0, N - 1, loc, val);
    }
};
int n;
int get_actual_loc(int x) {
    if (x >= n)
        return x - n;
    return x;
}
int get_direction(int loc) {
    return loc / n;
}

int get_lca(int p, int q) {
    if (p >= INF || q >= INF)
        return INF;
    int tmp, log, i;
    //if p is situated on a higher level than q then we swap them
    if (L[p] < L[q])
        tmp = p, p = q, q = tmp;

    //we compute the value of [log(L[p)]
    for (log = 1; 1 << log <= L[p]; log++);
    log--;

    //we find the ancestor of node p situated on the same level
    //with q using the values in P
    for (i = log; i >= 0; i--)
        if (L[p] - (1 << i) >= L[q])
            p = P[p][i];

    if (p == q)
        return p;

    //we compute LCA(p, q) using the values in P
    for (i = log; i >= 0; i--)
        if (P[p][i] != -1 && P[p][i] != P[q][i])
            p = P[p][i], q = P[q][i];
    return P[p][0];
}

Seg *seg;
int find_next(int loc) {
    if (get_direction(loc) == ASC) {
        return seg->next_greater_pos(get_actual_loc(loc) + 1, a[get_actual_loc(loc)]) + n;

    } else {
        return seg->next_lesser_pos(get_actual_loc(loc) + 1, a[get_actual_loc(loc)]);
    }
}

int get_successor_before(int loc, int before, int last_update) {
    while (get_actual_loc(loc) <= last_update) {
        int nloc = find_next(loc);
        if (get_actual_loc(nloc) >= before)
            return loc;
        loc = nloc;
    }
    for (int i = LOGMAXN - 1; i >= 0; i--) {
        if (get_actual_loc(P[loc][i]) < before) {
            loc = P[loc][i];
        }
    }
    return loc;
}
PII get_successor_before_distance(int loc, int before, int last_update) {
    int ele = 0, PREV;
    while (get_actual_loc(loc) <= last_update) {
        int nloc = find_next(loc);
        assert(get_actual_loc(nloc) > get_actual_loc(loc));
        if (get_actual_loc(nloc) >= before)
            return MP(loc, ele);
        ele++;
        PREV = loc;
        loc = nloc;
    }
    if (ele == 2) assert(PREV == last_update);
    else assert(ele <= 1);

    for (int i = LOGMAXN - 1; i >= 0; i--) {
        if (get_actual_loc(P[loc][i]) < before) {
            ele += (1 << i);
            loc = P[loc][i];
        }
    }
    //int nloc = find_next(loc);
    //assert(get_actual_loc(nloc) >= before);
    return MP(loc, ele);
}


int get_path_length(int x) {
    if (x >= n + n)
        return 0;
    /*
    int cnt = 0;
    while (get_actual_loc(x) < n) {
        cnt ++;
        x = find_next(x);
    }*/
    map<int, int> ::iterator it;
    int prv = 0;
    int cnt = 1;
    for (it = mp.begin(); it != mp.end(); it++) {
        PII nxt = get_successor_before_distance(x, it->first, prv);
        prv = it->first;
        cnt += nxt.second;
        x = nxt.first;
        if (x < it->first) {
            int dir = get_direction(x);
            if (dir == ASC && it->second > a[get_actual_loc(x)]) {
                x = it->first + n;
                cnt++;
            } else if (dir == DESC && it->second < a[get_actual_loc(x)]) {
                x = it->first;
                cnt++;
            }
        }
    }
    return get_successor_before_distance(x, n, prv).second + cnt;
}
void dfs(int cnode, int clev = 0) {
    L[cnode] = clev;
    for (int i = 0; i < (int)v[cnode].size(); i++) {
        dfs(v[cnode][i], clev + 1);
    }
}
int get_common_path(int l1, int l2) {
    if (get_actual_loc(l1) > get_actual_loc(l2))
        swap(l1, l2);
    if (l2 >= n + n || l1 >= n + n)
        return 0;
    int prv = 0;
    map<int, int> ::iterator it;
    for (it = mp.begin(); it != mp.end(); it++) {
        int tl1 = get_successor_before(l1, it->first, prv);
        int tl2 = get_successor_before(l2, it->first, prv);
        if (tl1 == tl2) {
            if (get_actual_loc(l1) > get_actual_loc(l2)) {
                swap(l1, l2);
            }
            l1 = find_next(l1);
            while (get_actual_loc(l2) <= prv)
                l2 = find_next(l2);
            return get_path_length(get_lca(l1, l2));
        }
        l1 = tl1;
        l2 = tl2;
        if (get_actual_loc(l1) < it->first) {
            int d1 = get_direction(l1);
            if (d1 == ASC && it->second > a[get_actual_loc(l1)]) {
                l1 = it->first + n;
            } else if (d1 == DESC && it->second < a[get_actual_loc(l1)]) {
                l1 = it->first;
            }
        }
        if (get_actual_loc(l2) < it->first) {
            int d2 = get_direction(l2);
            if (d2 == ASC && it->second > a[get_actual_loc(l2)]) {
                l2 = it->first + n;
            } else if (d2 == DESC && it->second < a[get_actual_loc(l2)]) {
                l2 = it->first;
            }
        }
        if (get_actual_loc(l1) == get_actual_loc(l2)) {
            return get_path_length(l1);
        }
        prv = it->first;
    }
    if (get_actual_loc(l1) != get_actual_loc(l2)) {
        if (get_actual_loc(l1) <= mp.rbegin()->first)
            l1 = find_next(l1);
        if (get_actual_loc(l2) <= mp.rbegin()->first)
            l2 = find_next(l2);
        return get_path_length(get_lca(l1, l2));
    }
}
int check_path_to(int l1, int l2) {
    map<int, int> ::iterator it;
    // while (get_actual_loc(l1) < l2) {
    // l1 = find_next(l1);
    // }
    int prv = 0;
    for (it = mp.begin(); it != mp.end(); it++) {
        if (it->first >= l2) {
            l1 = find_next(get_successor_before(l1, l2, prv));
            if (get_actual_loc(l1) == get_actual_loc(l2)) {
                return l1;
            }
            return -1;
        }
        l1 = get_successor_before(l1, it->first, prv);
        prv = it->first;
    }
    l1 = find_next(get_successor_before(l1, l2, prv));
    if (get_actual_loc(l1) == get_actual_loc(l2)) {
        return l1;
    }
    return -1;

}
int main() {
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int q, i, j, k;
    cin >> n >> q;
    for (i = 0; i < LOGMAXN; i++) {
        for (j = 0; j <= n + n; j++) {
            P[j][i] = n + n;
        }
    }
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    seg = new Seg(a, n);
    for (i = n - 1; i >= 0; i--) {
        while (!st1.empty() && a[i] > st1.top().first)
            st1.pop();
        while (!st2.empty() && a[i] < st2.top().first)
            st2.pop();
        if (!st1.empty()) {
            P[i][0] = st1.top().second + n;
        }
        if (!st2.empty()) {
            P[n + i][0] = st2.top().second;
        }
        st1.push(MP(a[i], i));
        st2.push(MP(a[i], i));
    }
    for (i = 1; i < LOGMAXN; i++) {
        for (j = 0; j < n + n; j++) {
            P[j][i] = P[P[j][i - 1]][i - 1];
        }
    }
    for (i = 0; i < n + n; i++) {
        v[P[i][0]].PB(i);
    }
    dfs(n + n);
    int loc, nh;
    int cs = 0;
    while (q--) {
        map<int, int> ::iterator it;
        int l1, l2, ans = 0;
        scanf("%d %d", &l1, &l2);
        scanf("%d", &k);
        mp.clear();
        for (i = 0; i < k; i++) {
            scanf("%d %d", &loc, &nh);
            loc --;
            mp[loc] = nh;
            old[loc] = a[loc];
            a[loc] = nh;
            seg->update(loc, nh);
        }
        l1 --;
        l2 --;
        if (l1 > l2)
            swap(l1, l2);
        if (l1 == l2) {
            printf("%d\n", get_path_length(l1));
        } else {
            int reach_point_l2 = check_path_to(l1, l2);
            if (reach_point_l2 == l2) {
                printf("%d\n", get_path_length(l2));
            } else if (get_actual_loc(reach_point_l2) == l2) {
                printf("%d\n", 1 + get_common_path(find_next(l2), find_next(l2 + n)));
            } else {
                printf("%d\n", get_common_path(l1, l2));
            }
        }
        for (it = mp.begin(); it != mp.end(); it++) {
            seg->update(it->first, old[it->first]);
            a[it->first] = old[it->first];
        }
    }
    return 0;
}
