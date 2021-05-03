/*
A. Phoenix and Gold
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Phoenix has collected n pieces of gold, and he wants to weigh them together so he can feel rich. The i-th piece of gold has weight wi. All weights are distinct. He will put his n pieces of gold on a weight scale, one piece at a time.

The scale has an unusual defect: if the total weight on it is exactly x, it will explode. Can he put all n gold pieces onto the scale in some order, without the scale exploding during the process? If so, help him find some possible order.

Formally, rearrange the array w so that for each i (1≤i≤n), ∑j=1iwj≠x.

Input
The input consists of multiple test cases. The first line contains an integer t (1≤t≤1000) — the number of test cases.

The first line of each test case contains two integers n and x (1≤n≤100; 1≤x≤104) — the number of gold pieces that Phoenix has and the weight to avoid, respectively.

The second line of each test case contains n space-separated integers (1≤wi≤100) — the weights of the gold pieces. It is guaranteed that the weights are pairwise distinct.

Output
For each test case, if Phoenix cannot place all n pieces without the scale exploding, print NO. Otherwise, print YES followed by the rearranged array w. If there are multiple solutions, print any.

Example
inputCopy
3
3 2
3 2 1
5 3
1 2 3 4 8
1 5
5
outputCopy
YES
3 2 1
YES
8 1 2 3 4
NO
Note
In the first test case, Phoenix puts the gold piece with weight 3 on the scale first, then the piece with weight 2, and finally the piece with weight 1. The total weight on the scale is 3, then 5, then 6. The scale does not explode because the total weight on the scale is never 2.

In the second test case, the total weight on the scale is 8, 9, 11, 14, then 18. It is never 3.

In the third test case, Phoenix must put the gold piece with weight 5 on the scale, and the scale will always explode.

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
ll TT = 1;
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
	ll s = 0, a[n];
	foi(n) {
		cin >> a[i];
		s += a[i];
	}
	if (s == m) {
		cout << "NO";
		return;
	}
	sort(a, a + n);
	ll s1 = 0, x, f = 0;
	vll b;
	foi(n) {
		if (s1 + a[i] == m and i != n - 1) {
			x = a[i];
			f = 1;
		}
		else if (s1 + a[i] == m and i == n - 1) {
			cout << "YES" << endl;
			cout << a[i] << " ";
			foj(n - 1)
			cout << a[j] << " ";
			return;

		}
		else {
			b.pb(a[i]);
			s1 += a[i];
		}
	}
	if (f) {
		cout << "YES" << endl;
		foi(n - 1)
		cout << b[i] << " ";
		cout << x;
	}
	else {
		cout << "YES" << endl;
		foi(n)
		cout << b[i] << " ";
	}


}


