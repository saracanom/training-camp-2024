#include <bits/stdc++.h>
#include <utility>

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
typedef vector<string> vs;
typedef map<int,int> mpii;
typedef unordered_map<int,int> umpii;
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

int C(int n, int k) {
    int res = 1;
    for (int i = n - k + 1; i <= n; ++i)
        res *= i;
    for (int i = 2; i <= k; ++i)
        res /= i;
    return int(res);
}

void solve(){
    string s; cin>>s;
    vector<int> count(10, 0); // Contador de dígitos en s
    for(char c : s){
        count[c - '0']++;
    }
    bool found = false;
    if(s.size() == 1){
        if(s != "8"){
            cout<<"No"<<el;
        }
        else{
            cout<<"Yes"<<el;
        }
    }
    else if(s.size() == 2){
        int num = stoi(s);
        if(num % 8 == 0){
            cout<<"Yes"<<el;
        }else{
            string f = s.substr(0,1);
            string l = s.substr(1,2);
            string news = l + f;
            int newnum = stoi(news);
            if(newnum % 8 == 0){
                cout<<"Yes"<<el;
            }
            else{
                cout<<"No"<<el;
            }
        }
    }
    else{
        for(int i = 104; i < 1000; i += 8){
            string perm = to_string(i);
            vector<int> permCount(10, 0);
            for(char c : perm){
                permCount[c - '0']++;
            }
        
            bool possible = true;
            for(int j = 0; j < 10; j++){
                if(permCount[j] > count[j]){
                    possible = false;
                    break;
                }
            }
            if(possible){
                found = true;
                break;
            }
        }
        if(found){
            cout<<"Yes"<<el;
        }else{
            cout<<"No"<<el;
        }
    }
    
}

int main(){
    ios_base::sync_with_stdio(false),
    cin.tie(NULL);
    precision(20);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    //int t=1; 
    ///cin>>t;
    //cases(t) 
    solve();
    return 0;
}
