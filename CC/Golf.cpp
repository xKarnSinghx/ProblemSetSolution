/*
It's a lockdown. You’re bored in your house and are playing golf in the hallway.

The hallway has N+2
tiles numbered from 0 to N+1 from left to right. There is a hole on tile number x. You hit the ball standing on tile 0. When you hit the ball, it bounces at lengths of k, i.e. the tiles covered by it are 0,k,2k,…, and so on until the ball passes tile N+1

.

If the ball doesn't enter the hole in the first trial, you try again but this time standing on the tile N+1
. When you hit the ball, it bounces at lengths of k, i.e. the tiles covered by it are (N+1),(N+1−k),(N+1−2k),…, and so on until the ball passes tile 0

.

Find if the ball will enter the hole, either in its forward journey or backward journey.

Note: The input and output of this problem are large, so prefer using fast input/output methods.
Input

    The first line contains an integer T

, the number of test cases. Then the test cases follow.
The only line of each test case contains three integers N,x,k

    .

Output

Output in a single line, the answer, which should be "YES" if the ball enters the hole either in the forward or backward journey and "NO" if not.

You may print each character of the string in uppercase or lowercase (for example, the strings "yEs", "yes", "Yes" and "YES" will all be treated as identical).
Constraints

    1≤T≤105

1≤x,k≤N≤109

Subtasks

Subtask #1 (10 points): N≤102

Subtask #2 (90 points): original constraints
Sample Input

3
5 4 2
5 3 2
5 5 2

Sample Output

YES
NO
NO

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
void solve() {
	ll n, x, k;
	cin >> n >> x >> k;
	vll a, b;
	ll z = 0;
	while (z < n + 2) {
		a.pb(z);
		z += k;
	}
	z = n + 1;
	while (z > 0) {
		b.pb(z);
		z -= k;
	}
	foi(a.size()) {
		if (a[i] == x) {
			cout << "YES";
			return;
		}
	}
	foi(b.size()) {
		if (b[i] == x) {
			cout << "YES";
			return;
		}
	}
	cout << "NO";

}


