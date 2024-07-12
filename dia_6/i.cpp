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
// typedef unordered_map<int,int> umpii;
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
  

vector<long long> trial_division1(long long n) {
    vector<long long> factorization;
    for (long long d = 2; d * d <= n; d++) {
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

void solve(){
    ll n; cin>>n;
    vector<long long> fact = trial_division1(n);
    ll x=1, y=1;
    
    if(fact.size()>3){
    forn(i,(fact.size()/2)-1){
        if (i%2==0){
            x *= fact[i]*fact[fact.size()-i-1];
        }
        else{
            y *= fact[i]*fact[fact.size()-i-1];
        }
    }
    if(fact.size()%2==1){
        if(x<=y){ 
            x*=fact[fact.size()/2];
        }
        else{
            y*=fact[fact.size()/2];
        }
    }
    else{
       
        x*=fact[fact.size()/2-1];
    
        y*=fact[fact.size()/2];
        
    }
    }
    else{
        // cout<<"entro"<<el;
        x=1e18;y=1e18;}
    ll x1=1,y1=1;
    forn(i,fact.size()-1){
            x1*=fact[i];
            // cout<<fact[i]<<el;
    }
    y1= fact[fact.size()-1];
    
    
    cout<<x1<<" "<<y1<<el;
    cout<<x<<" "<<y<<el;

    ll dis = abs(x-1)+ abs(y-1);

    ll dis2 = abs(x1-1)+ abs(y1-1);

    cout<<dis<<" "<<dis2<<el;
    cout<<min(dis,dis2)<<el;
    
}

int main(){
    ios_base::sync_with_stdio(false),
    cin.tie(NULL);
    precision(20);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t=1; 
    // cin>>t;
    cases(t) solve();
    return 0;
}

//Compile: 
//g++ --std=c++17 B.cpp -o a
//How to run the file in any terminal
//./D
//How pass the input in the file
// Input data
//./D < input.txt 
// Input data and generate output file
//./D < input.txt > output.txt