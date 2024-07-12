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
/// HAY QUE HACERLO CON DP

int klaus(vvi kids, vector<vector<bool>>& visited, int n, int m, int& cont, int i, int j){
    if(i>=n || j>=m) return cont; // evito salirme
    else{ 
        if (visited[i][j] == false){
            visited[i][j] = true;
            cont+= kids[i][j];
            D(i);
            D(j);

            cout<<cont<<el;
            cont = klaus(kids, visited, n, m, cont, i+1, j) ;//abajo
            cont = klaus(kids, visited, n, m, cont, i, j+1); //derecha
            return cont;
        }
        return cont;
    }

}

void solve(){
    int n, m;
    cin>>n>>m;
    vvi kids(n, vi(m));
    vector<vector<bool> > visited(n, vector<bool> (m, false));
    forn(i,n){
        forn(j,m){
            cin>>kids[i][j];
        }
    }
    int cont=0;
    int gifts = klaus(kids, visited, n, m, cont, 0,0);
    cout<<gifts<<el;
    
}

int main(){
    ios_base::sync_with_stdio(false),
    cin.tie(NULL);
    precision(20);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t=1; 
    cin>>t;
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