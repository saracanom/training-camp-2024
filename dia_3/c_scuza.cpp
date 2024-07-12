#include <bits/stdc++.h>

#define el '\n'
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define precision(x) cout << setprecision(x) << fixed

using namespace std;

typedef long long ll;
typedef vector<ll> vll;

void solve() {
    ll n, q;
    cin >> n >> q;
    vll heightDiff(n);
    forn(i, n) {
        cin >> heightDiff[i];
    }
    vll legLength(q);
    forn(i, q) {
        cin >> legLength[i];
    }

    // Pair each query with its index and sort by leg length
    vector<pair<ll, int>> queries;
    forn(i, q) {
        queries.push_back({legLength[i], i});
    }
    sort(queries.begin(), queries.end());

    vll prefixHeight(n + 1, 0);
    forn(i, n) {
        prefixHeight[i + 1] = prefixHeight[i] + heightDiff[i];
    }

    vll maxReachableHeight(n + 1, 0);
    ll maxHeight = 0;
    
    for (ll i = 1; i <= n; ++i) {
        maxReachableHeight[i] = max(maxReachableHeight[i - 1], prefixHeight[i]);
    }

    vll results(q, 0);
    int stairIndex = 0;

    for (const auto &query : queries) {
        ll leg = query.first;
        int idx = query.second;

        while (stairIndex < n && heightDiff[stairIndex] <= leg) {
            stairIndex++;
        }

        results[idx] = maxReachableHeight[stairIndex];
    }

    forn(i, q) {
        cout << results[i] << " ";
    }
    cout << el;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    precision(20);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
