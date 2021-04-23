/*
*/
#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <chrono>
#include <complex>
using namespace std;
#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define mp                   make_pair
#define eb                   emplace_back
#define pb                   push_back
#define pf                   push_front
#define popb                 pop_back
#define popf                 pop_front
#define hashmap              unordered_map
#define hashset              unordered_set
#define lb                   lower_bound
#define ub                   upper_bound
#define all(a)               (a).begin(), (a).end()
#define rall(a)              (a).rbegin(), (a).rend()
#define ff                   first
#define ss                   second
#define foi(n) for(ll i=0;i<n;i++)
#define foj(n) for(ll j=0;j<n;j++)
#define fok(n) for(ll k=0;k<n;k++)
#define forr(i,a,b) for(ll i=a;i<b;i++)
#define forrr(i,b,a) for(ll i=b;i>=a;i--)
#define forrrr(i,a,b,k) for(ll i=a;i<b;i=i+k)
#define graph          vector<vector<int>>
#define sz(v) v.size()
typedef pair<int, int> pii;
typedef pair<ll, ll>   pll;
typedef vector<int>         vi;
typedef vector<ll>          vll;
typedef vector<string>      vs;
typedef vector<double>      vd;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;
typedef pair< ll, pll>      plll;
typedef vector<plll>      vplll;
typedef  vector<string> 	     vs;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  map<string, int>         msi;
typedef  map<int, int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<char, int>           mci;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
const ll MOD = 1000000007;
void solve();
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif


	ll t ; cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
ll ceils(ll x, ll y) {
	return x / y + ((x % y) != 0);
}
ll gcd(ll a, ll b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
void solve()
{
	ll n, m;
	cin >> n >> m;
	ll a[n][m];
	foi(n) {
		foj(m)
		cin >> a[i][j];
	}
	vplll b;
	foi(n) {
		foj(m)
		b.pb(mp(a[i][j], mp (i, j))) ;
	}
	sort(b.begin(), b.end());
	ll ans[n][m] = {}, k = 0;

	foi(m) {
		ans[b[i].ss.ff][k] = b[i].ff;
		k++;
	}
	k = 0;
	foi(n) {
		ll z[101] = {}, k = 0;
		foj(m) {
			if (ans[i][j] != 0)
				z[k] = ans[i][j], k++;
		}
		ll y[101] = {};
		k = 0;
		foj(m) {
			y[k] = a[i][j], k++;
		}
		sort(y, y + k);
		ll xy[101];
		k = 0;
		ll mx = 0, f = 0;
		foj(m) {
			if (z[k] == y[j] )
				k++;
			else
				xy[mx] = y[j], mx++;

		}
		k = 0;
		foj(m) {
			if (ans[i][j] == 0)
				ans[i][j] = xy[k], k++;
		}


	}
	foi(n) {
		foj(m)
		cout << ans[i][j] << " ";
		cout << "\n";
	}



}


