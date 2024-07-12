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

void solve() {
    int n;
    cin>>n;
    vector<pair<double, double> > points(n);
    forn(i,n){
        int x,y;
        cin>>x>>y;
        points[i] = make_pair(x,y);
    }
    // tomamos los dos primeros puntos como iniciales
    double m ,mp, mp2;
    double b , bp;
    bool flag = false;
    sort(points.begin(),points.end());
    for (int i = 0; i < points.size(); i++)
    {
         for (int j = 0; j < points.size(); j++){
            // aca elijo los dos puntos
            //e itero el tercero
            bool vertical = false;
            if(points[i].fi ==points[j].fi) //recta vertical
            {
                vertical = true;
            }
            else{
                m = (points[j].second-points[i].second)/(points[j].first-points[i].first);
                b = points[j].second- m *points[j].first;
            }
           
            // cout<< "m: "<<m<<"b: "<<b<<el;
            forn(k,points.size()){
                mp = (points[k].second-points[j].second)/(points[k].first-points[j].first);
                bp = points[k].second-m*points[k].first;
                if(i!=j && i!=k && j!=k){
                    if(vertical ==true){
                        if (points[k].fi == points[j].fi){
                            flag = true;
                        }
                    }
                    else if((m == mp && bp ==b)){
                        flag = true;
                        // cout<<"mp: "<<mp<<" bp: "<<bp<<el;
                        // cout<<points[k].first<<points[k].se<<points[j].first<<points[j].se<<points[i].first<<points[i].se<<el;
                        // cout<<points[k].se-points[j].second<<" / "<<points[k].first-points[j].first<<el;
                        break;
                     }
                }
                
            }
        }
    }
        // if(x[l]==x[r]){
        //     m = x[l]; //linea recta
        //     cout<<"linea vertical en"<<m<<el;
        //     b = 0;
        // }else{
        //     m = (y[r]-y[l])/(x[r]-x[l]);
        
        //     b = m*x[r] + y[r]; // no sé si esta bueno
        // }   
       
        if(flag)cout<<"Yes"<<el;
        else cout<<"No"<<el;
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