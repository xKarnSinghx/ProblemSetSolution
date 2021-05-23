/*
Chef is playing a game where he has an array A of N integers, and an integer K. He looks at every subarray of length K, and writes its sum on a piece of paper. If a number appears as the sum of multiple subarrays of length K, then he only writes down that number once.

Chef is lazy and doesn't like to write numbers. You, being a friend of Chef, want to modify the array such that Chef will only write one number on his paper. In one modification you can choose any index i and replace Ai with any integer.

You need to find the minimum number of modifications required.

Input
The first line contains an integer T, the number of test cases. Then the test cases follow.
Each test case contains two lines of input.
The first line contains two space-separated integers N, K.
The second line contains N space-separated integers A1,A2,…,AN.
Output
For each test case, output the answer in a single line.

Constraints
1≤T≤1000
1≤N≤105
1≤K≤N
1≤Ai≤105
The sum of N over all test cases does not exceed 5⋅105.
Sample Input
2
3 3 
1 2 3
2 1
4 6
Sample Output
0
1
Explanation
Test Case 1: K=3 and there is only one subarray of length 3, so no changes are required.

Test Case 2: K=1 and the subarrays of length 1 are [4] and [6]. So, at least one modification is required. One possible solution with only one modification is to change A2 to 4.
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
typedef  map<ll, vll>             mvll;
typedef  map<char, int>           mci;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
const ll MOD = 1000000007;
void solve();

ll N = 1001;
ll a[1111][1111] = {};
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
void solve() {
	ll n, k;
	cin >> n >> k;
	vll a;
	foi(n) {
		ll x;
		cin >> x;
		a.pb(x);
	}

	mll m;
	ll ans = 0;
	foi(k) {
		ll cnt = 1;
		m[a[i]]++;
		ll j = i + k;
		while (j < n) {
			m[a[j]]++;
			cnt++;
			j += k;
		}
		ll mx = 0;
		for (auto x : m) {
			mx = max(mx, x.ss);
		}
		m.clear();
		ans += (cnt - mx);
	}
	cout << ans;
}


