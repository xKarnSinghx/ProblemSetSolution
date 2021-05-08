/*
A. Cashier
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Vasya has recently got a job as a cashier at a local store. His day at work is L minutes long. Vasya has already memorized n regular customers, the i-th of which comes after ti minutes after the beginning of the day, and his service consumes li minutes. It is guaranteed that no customer will arrive while Vasya is servicing another customer.

Vasya is a bit lazy, so he likes taking smoke breaks for a minutes each. Those breaks may go one after another, but Vasya must be present at work during all the time periods he must serve regular customers, otherwise one of them may alert his boss. What is the maximum number of breaks Vasya can take during the day?

Input
The first line contains three integers n, L and a (0≤n≤105, 1≤L≤109, 1≤a≤L).

The i-th of the next n lines contains two integers ti and li (0≤ti≤L−1, 1≤li≤L). It is guaranteed that ti+li≤ti+1 and tn+ln≤L.

Output
Output one integer  — the maximum number of breaks.

Examples
inputCopy
2 11 3
0 1
1 1
outputCopy
3
inputCopy
0 5 2
outputCopy
2
inputCopy
1 3 2
1 2
outputCopy
0
Note
In the first sample Vasya can take 3 breaks starting after 2, 5 and 8 minutes after the beginning of the day.

In the second sample Vasya can take 2 breaks starting after 0 and 2 minutes after the beginning of the day.

In the third sample Vasya can't take any breaks.


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


//	ll t ; cin >> t;
//	while (t--)
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
void solve() {
	ll n, l, a;
	cin >> n >> l >> a;
	ll ans = 0, s = 0;
	foi(n) {
		ll x, y;
		cin >> x >> y;
		ans += (x - s) / a;
		s = x + y;
	}
	ans += (l - s) / a;
	cout << ans;

}
