#include <bits/stdc++.h>

#define el '\n'
#define fi first
#define se second
#define forn(i,n) for(int i=0; i< (int)n; ++i)
#define for1(i,n) for(int i=1; i<= (int)n; ++i)
#define rforn(i,n) for(int i =(int)(n) - 1; i>= 0; --i)
#define fora(i,x,n) for(int i=(int)x; i< (int)n; ++i)
#define rfora(i,x,n) for(int i=(int)x; i>= (int)n; --i)
#define pb push_back
#define pob pop_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(v) ((int)v.size())
#define CYN(x) cout << (x ? "YES" : "NO" ) <<endl; 
#define cases(t) while(t--)
#define mem(v, val) memset(v, (val), sizeof(v))
#define D(x) cout << #x << ": " << x << endl;
#define precision(x) cout<<setprecision(x)<<fixed;

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<char,int> pci;
// typedef tuple<int, int, int> tiii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<pii> vii;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef map<int,int> mpii;
typedef unordered_map<char,int> umpii;
typedef set<int> seti;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pqll;

const int inf = 1e9;
const int nax = 1e5+200;
const ld pi = acos(-1);
const ld eps = 1e-9;

int dr[] = {1,-1,0,0,1,-1,-1,1};
int dc[] = {0,0,1,-1,1,1,-1,-1};

ll gcd(ll a, ll b) { return !a ? b : gcd(b % a, a); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll mod(ll a, ll b) { return (((a % b) + b) % b); }

void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int ph = n/11;
    int oc = 0;
    forn(i,n){
        if(s[i]=='8'){
            oc=oc+1;
        }
    }
    if(oc<=ph){
        cout<<oc;
    }else{
        cout<<ph;
    }
}

int main(){
    ios_base::sync_with_stdio(false),
    cin.tie(NULL);
    precision(20);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
     solve();
    return 0;
}
