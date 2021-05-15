/*
A. Distance and Axis
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
We have a point A with coordinate x=n on OX-axis. We'd like to find an integer point B (also on OX-axis), such that the absolute difference between the distance from O to B and the distance from A to B is equal to k.

The description of the first test case.
Since sometimes it's impossible to find such point B, we can, in one step, increase or decrease the coordinate of A by 1. What is the minimum number of steps we should do to make such point B exist?

Input
The first line contains one integer t (1≤t≤6000) — the number of test cases.

The only line of each test case contains two integers n and k (0≤n,k≤106) — the initial position of point A and desirable absolute difference.

Output
For each test case, print the minimum number of steps to make point B exist.

Example
inputCopy
6
4 0
5 8
0 1000000
0 0
1 0
1000000 1000000
outputCopy
0
3
1000000
0
1
0
Note
In the first test case (picture above), if we set the coordinate of B as 2 then the absolute difference will be equal to |(2−0)−(4−2)|=0 and we don't have to move A. So the answer is 0.

In the second test case, we can increase the coordinate of A by 3 and set the coordinate of B as 0 or 8. The absolute difference will be equal to |8−0|=8, so the answer is 3.



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
string to_oct(ll n) {
	string s;
	while (n) {
		s = to_string(n % 8) + s;
		n /= 8;
	}
	return s;
}
void solve() {
	ll n, k;
	cin >> n >> k;
	ll ans = 0;
	if (n < k)
		ans = k - n;
	else {
		if ((n - k) % 2)
			ans = 1;
		else
			ans = 0;
	}
	cout << ans;

}

