/*
D. Integral Array
time limit per test2 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
You are given an array a of n positive integers numbered from 1 to n. Let's call an array integral if for any two, not necessarily different, numbers x and y from this array, x≥y, the number ⌊xy⌋ (x divided by y with rounding down) is also in this array.

You are guaranteed that all numbers in a do not exceed c. Your task is to check whether this array is integral.

Input
The input consists of multiple test cases. The first line contains a single integer t (1≤t≤104) — the number of test cases. Description of the test cases follows.

The first line of each test case contains two integers n and c (1≤n≤106, 1≤c≤106) — the size of a and the limit for the numbers in the array.

The second line of each test case contains n integers a1, a2, ..., an (1≤ai≤c) — the array a.

Let N be the sum of n over all test cases and C be the sum of c over all test cases. It is guaranteed that N≤106 and C≤106.

Output
For each test case print Yes if the array is integral and No otherwise.

Examples
inputCopy
4
3 5
1 2 5
4 10
1 3 3 7
1 2
2
1 1
1
outputCopy
Yes
No
No
Yes
inputCopy
1
1 1000000
1000000
outputCopy
No
Note
In the first test case it is easy to see that the array is integral:

⌊11⌋=1, a1=1, this number occurs in the arry
⌊22⌋=1
⌊55⌋=1
⌊21⌋=2, a2=2, this number occurs in the array
⌊51⌋=5, a3=5, this number occurs in the array
⌊52⌋=2, a2=2, this number occurs in the array
Thus, the condition is met and the array is integral.

In the second test case it is enough to see that

⌊73⌋=⌊213⌋=2, this number is not in a, that's why it is not integral.

In the third test case ⌊22⌋=1, but there is only 2 in the array, that's why it is not integral.
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
typedef vector<ld>          vld;
typedef vector<string>      vs;
typedef vector<double>      vd;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;
typedef pair< ll, pll>      plll;
typedef queue<ll>           qll;
typedef vector<plll>      vplll;
typedef  vector<set<ll>>   vsll;
typedef  vector<char>	         vc;
typedef  vector<bool>            vb;
typedef  map<string, int>         msi;
typedef  map<int, int>	         mii;
typedef  map<ll, ll>             mll;
typedef  map<ll, vll>             mvll;
typedef  map<vll, ll>             mvlll;
typedef  map<char, ll>           mcl;
typedef map<pair<ll, ll>, ll>  mplll;
typedef  unordered_map<char, ll>           umcl;
typedef  unordered_map< ll, char>           umlc;
typedef  unordered_map< ll, ld>           umld;
typedef  map<int, string>	     mis;
typedef  pair<string, int>       psi;
typedef  pair<string, string>    pss;
typedef priority_queue <ll> pq;
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
typedef priority_queue<ll, vector<ll>, greater<ll>> prq;
const ll MOD = 1000000007;
const ll mod = 998244353;
ld PI = 3.1415926535897;
const ll N = 1000010;
void solve();
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif
	ll t; cin >> t;
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
ll binpow(ll a, ll b, ll m) {
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}
string ans(string &s) {
	map<int, vector<char>>m;
	m[1] = {',', '@'};
	m[2] = {'A', 'B', 'C', 'a', 'b', 'c', '2'};
	m[3] = {'D', 'E', 'F', 'd', 'e', 'f', '3'};
	m[4] = {'G', 'H', 'I', 'g', 'h', 'i', '4'};
	m[5] = {'J', 'K', 'L', 'j', 'k', 'l', '5'};
	m[6] = {'M', 'N', 'O', 'm', 'n', 'o', '6'};
	m[7] = {'P', 'Q', 'R', 'S', 'p', 'q', 'r', 's', '7'};
	m[8] = {'T', 'U', 'V', 't', 'u', 'v', '8'};
	m[9] = {'X', 'Y', 'Z', 'x', 'y', 'z', '9'};
	m[0] = {' ', '0'};
	string ans = "";
	int c = s[0] - '0', r = 1;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] == '_' or i == s.size() - 1 or s[i] != s[i - 1]) {
			if (s[i] == s[i - 1])
				ans += m[c][r % m[c].size()];
			else if (s[i] != s[i - 1] and s[i] != '_')
				ans += m[c][(r - 1) % m[c].size()];
			if (isdigit(s[i]))
				c = s[i] - '0', r = 1;
			if (i == s.size() - 1 and s[i] == s[i - 1])
				return ans;
		}
		else {
			r++;
		}
	}
	ans += m[c][r - 1];
	return ans;

}
void solve() {
	ll n, c;
	cin >> n >> c;
	vll a(n), m(2 * c + 1, 0);
	foi(n) {
		cin >> a[i];
		m[a[i]]++;
	}
	for (ll i = 2; i < 2 * c + 1; i++) {
		m[i] += m[i - 1];
	}
	if (!m[1]) {
		cout << "NO";
		return;
	}
	foi(c + 1) {
		if (i == 0 or m[i] == m[i - 1] or i == 1)
			continue;
		for (ll j = i; j < c + 1; j += i) {
			if (m[i + j - 1] > m[j - 1] and m[j / i] == m[j / i - 1]) {
				cout << "NO";
				return;
			}
		}
	}
	cout << "YES";

}
