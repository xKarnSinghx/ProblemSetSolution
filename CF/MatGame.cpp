/*
A. Matrix Game
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Ashish and Vivek play a game on a matrix consisting of n rows and m columns, where they take turns claiming cells. Unclaimed cells are represented by 0, while claimed cells are represented by 1. The initial state of the matrix is given. There can be some claimed cells in the initial state.

In each turn, a player must claim a cell. A cell may be claimed if it is unclaimed and does not share a row or column with any other already claimed cells. When a player is unable to make a move, he loses and the game ends.

If Ashish and Vivek take turns to move and Ashish goes first, determine the winner of the game if both of them are playing optimally.

Optimal play between two players means that both players choose the best possible strategy to achieve the best possible outcome for themselves.

Input
The first line consists of a single integer t (1≤t≤50) — the number of test cases. The description of the test cases follows.

The first line of each test case consists of two space-separated integers n, m (1≤n,m≤50) — the number of rows and columns in the matrix.

The following n lines consist of m integers each, the j-th integer on the i-th line denoting ai,j (ai,j∈{0,1}).

Output
For each test case if Ashish wins the game print "Ashish" otherwise print "Vivek" (without quotes).

Example
inputCopy
4
2 2
0 0
0 0
2 2
0 0
0 1
2 3
1 0 1
1 1 0
3 3
1 0 0
0 0 0
1 0 0
outputCopy
Vivek
Ashish
Vivek
Ashish
Note
For the first case: One possible scenario could be: Ashish claims cell (1,1), Vivek then claims cell (2,2). Ashish can neither claim cell (1,2), nor cell (2,1) as cells (1,1) and (2,2) are already claimed. Thus Ashish loses. It can be shown that no matter what Ashish plays in this case, Vivek will win.

For the second case: Ashish claims cell (1,1), the only cell that can be claimed in the first move. After that Vivek has no moves left.

For the third case: Ashish cannot make a move, so Vivek wins.

For the fourth case: If Ashish claims cell (2,3), Vivek will have no moves left.


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
#define graph          vector<vector<ll>>
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
typedef  map<ll, vll>             mvll;
typedef  map<char, ll>           mcl;
typedef map<pair<ll, ll>, ll>  mplll;
typedef  unordered_map<char, ll>           umcl;
typedef  unordered_map< ll, char>           umlc;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
typedef priority_queue<ll, vector<ll>, greater<ll>> prq;
const ll MOD = 1000000007;
const ll modx = 998244353;
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
ll powmod(ll x, ll y) {
	ll res = 1;
	for (ll i = 0; i < y; i++) {
		res = res * x % MOD;
	}
	return res;
}
bool isPrime(ll n)
{
	if (n <= 1)
		return false;
	if (n <= 3)
		return true;
	if (n % 2 == 0 || n % 3 == 0)
		return false;

	for (ll i = 5; i * i <= n; i = i + 6)
		if (n % i == 0 || n % (i + 2) == 0)
			return false;

	return true;
}
ll kadanesAlgo(vll a)
{
	ll n = a.size();

	ll currMax = 0;
	ll mx = INT_MIN;

	foi(n)
	{
		currMax += a[i];

		if (currMax <= a[i])
		{
			currMax = a[i];
		}

		mx = max(currMax, mx);
	}
	return mx;
}
void solve() {
	ll n, m;
	cin >> n >> m;
	ll a[n][m];
	foi(n) {
		foj(m)
		cin >> a[i][j];
	}
	ll cnt = 0, cnt1 = 0;
	foi(n) {
		foj(m) {
			if (a[i][j] == 1) {
				cnt++;
				break;
			}
		}
	}
	foi(m) {
		foj(n) {
			if (a[j][i] == 1) {
				cnt1++;
				break;
			}
		}
	}
	ll ans = n - cnt;
	ans = min(ans, m - cnt1);
	if (ans % 2 == 1) {
		cout << "Ashish";
	}
	else
		cout << "Vivek";
}
