/*\
B. The Golden Age
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Unlucky year in Berland is such a year that its number n can be represented as n = xa + yb, where a and b are non-negative integer numbers.

For example, if x = 2 and y = 3 then the years 4 and 17 are unlucky (4 = 20 + 31, 17 = 23 + 32 = 24 + 30) and year 18 isn't unlucky as there is no such representation for it.

Such interval of years that there are no unlucky years in it is called The Golden Age.

You should write a program which will find maximum length of The Golden Age which starts no earlier than the year l and ends no later than the year r. If all years in the interval [l, r] are unlucky then the answer is 0.

Input
The first line contains four integer numbers x, y, l and r (2 ≤ x, y ≤ 1018, 1 ≤ l ≤ r ≤ 1018).

Output
Print the maximum length of The Golden Age within the interval [l, r].

If all years in the interval [l, r] are unlucky then print 0.

Examples
inputCopy
2 3 1 10
outputCopy
1
inputCopy
3 5 10 22
outputCopy
8
inputCopy
2 3 3 5
outputCopy
0
Note
In the first example the unlucky years are 2, 3, 4, 5, 7, 9 and 10. So maximum length of The Golden Age is achived in the intervals [1, 1], [6, 6] and [8, 8].

In the second example the longest Golden Age is the interval [15, 22].


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


	//ll t ; cin >> t;
	//while (t--)
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
	ll x, y, l, r;
	cin >> x >> y >> l >> r;
	vll ans;
	ans.pb(l - 1);
	ans.pb(r + 1);
	for (ll i = 1;; i *= x)
	{
		for (ll j = 1;; j *= y)
		{
			if (i + j >= l && i + j <= r)
				ans.push_back(i + j);
			if (j > r / y)
				break;
		}
		if (i > r / x)
			break;
	}
	sort(ans.begin(), ans.end());
	ll ans1 = 0;
	for (ll i = 1 ; i < ans.size(); ++i)
		ans1 = max(ans1, ans[i] - ans[i - 1] - 1);
	cout << ans1;

}


