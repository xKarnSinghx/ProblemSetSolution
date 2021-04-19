/*
C. Product 1 Modulo N
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Now you get Baby Ehab's first words: "Given an integer n, find the longest subsequence of [1,2,…,n−1] whose product is 1 modulo n." Please solve the problem.

A sequence b is a subsequence of an array a if b can be obtained from a by deleting some (possibly all) elements. The product of an empty subsequence is equal to 1.

Input
The only line contains the integer n (2≤n≤105).

Output
The first line should contain a single integer, the length of the longest subsequence.

The second line should contain the elements of the subsequence, in increasing order.

If there are multiple solutions, you can print any.

Examples
inputCopy
5
outputCopy
3
1 2 3 
inputCopy
8
outputCopy
4
1 3 5 7 
Note
In the first example, the product of the elements is 6 which is congruent to 1 modulo 5. The only longer subsequence is [1,2,3,4]. Its product is 24 which is congruent to 4 modulo 5. Hence, the answer is [1,2,3].


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
typedef pair<pll, ll>      plll;
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
	ll n;
	cin >> n;
	vll ans;
	ll rem = 1;
	for (ll i = 1; i <= n; i++) {
		if (gcd(n, i) == 1) {
			ans.pb(i);
			rem *= i;
			rem %= n;
		}
	}
	if (rem != 1)
		ans.pop_back();
	cout << ans.size() << "\n";
	foi(ans.size()) {
		cout << ans[i] << " ";
	}
}


