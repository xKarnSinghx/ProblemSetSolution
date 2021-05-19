/*
D. Omkar and Circle
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Danny, the local Math Maniac, is fascinated by circles, Omkar's most recent creation. Help him solve this circle problem!

You are given n nonnegative integers a1,a2,…,an arranged in a circle, where n must be odd (ie. n−1 is divisible by 2). Formally, for all i such that 2≤i≤n, the elements ai−1 and ai are considered to be adjacent, and an and a1 are also considered to be adjacent. In one operation, you pick a number on the circle, replace it with the sum of the two elements adjacent to it, and then delete the two adjacent elements from the circle. This is repeated until only one number remains in the circle, which we call the circular value.

Help Danny find the maximum possible circular value after some sequences of operations.

Input
The first line contains one odd integer n (1≤n<2⋅105, n is odd)  — the initial size of the circle.

The second line contains n integers a1,a2,…,an (0≤ai≤109)  — the initial numbers in the circle.

Output
Output the maximum possible circular value after applying some sequence of operations to the given circle.

Examples
inputCopy
3
7 10 2
outputCopy
17
inputCopy
1
4
outputCopy
4
Note
For the first test case, here's how a circular value of 17 is obtained:

Pick the number at index 3. The sum of adjacent elements equals 17. Delete 7 and 10 from the circle and replace 2 with 17.

Note that the answer may not fit in a 32-bit integer.


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
ll a[400002] = {};
void solve() {
	ll n;
	cin >> n;
	foi(n) {
		cin >> a[i];
		a[n + i] = a[i];
	}
	ll ans = 0;
	foi(2 * n) {
		a[i] += a[i - 2];
	}
	for (ll i = n; i < 2 * n; i++) {
		ans = max(ans, a[i] - a[i - n - 1]);
	}
	cout << ans;
}

