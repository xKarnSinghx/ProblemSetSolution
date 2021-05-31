/*
B. Lord of the Values
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output

While trading on his favorite exchange trader William realized that he found a vulnerability. Using this vulnerability he could change the values of certain internal variables to his advantage. To play around he decided to change the values of all internal variables from a1,a2,…,an to −a1,−a2,…,−an. For some unknown reason, the number of service variables is always an even number.

William understands that with his every action he attracts more and more attention from the exchange's security team, so the number of his actions must not exceed 5000 and after every operation no variable can have an absolute value greater than 1018. William can perform actions of two types for two chosen variables with indices i and j, where i<j:

Perform assignment ai=ai+aj
Perform assignment aj=aj−ai
William wants you to develop a strategy that will get all the internal variables to the desired values.
Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤20). Description of the test cases follows.

The first line of each test case contains a single even integer n (2≤n≤103), which is the number of internal variables.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤109), which are initial values of internal variables.

Output
For each test case print the answer in the following format:

The first line of output must contain the total number of actions k, which the strategy will perform. Note that you do not have to minimize k. The inequality k≤5000 must be satisfied.

Each of the next k lines must contain actions formatted as "type i j", where "type" is equal to "1" if the strategy needs to perform an assignment of the first type and "2" if the strategy needs to perform an assignment of the second type. Note that i<j should hold.

We can show that an answer always exists.

Example
inputCopy
2
4
1 1 1 1
4
4 3 1 2
outputCopy
8
2 1 2
2 1 2
2 1 3
2 1 3
2 1 4
2 1 4
1 1 2
1 1 2
8
2 1 4
1 2 4
1 2 4
1 2 4
1 3 4
1 1 2
1 1 2
1 1 4
Note
For the first sample test case one possible sequence of operations is as follows:

"2 1 2". Values of variables after performing the operation: [1, 0, 1, 1]
"2 1 2". Values of variables after performing the operation: [1, -1, 1, 1]
"2 1 3". Values of variables after performing the operation: [1, -1, 0, 1]
"2 1 3". Values of variables after performing the operation: [1, -1, -1, 1]
"2 1 4". Values of variables after performing the operation: [1, -1, -1, 0]
"2 1 4". Values of variables after performing the operation: [1, -1, -1, -1]
"1 1 2". Values of variables after performing the operation: [0, -1, -1, -1]
"1 1 2". Values of variables after performing the operation: [-1, -1, -1, -1]
For the second sample test case one possible sequence of operations is as follows:

"2 1 4". Values of variables after performing the operation: [4, 3, 1, -2]
"1 2 4". Values of variables after performing the operation: [4, 1, 1, -2]
"1 2 4". Values of variables after performing the operation: [4, -1, 1, -2]
"1 2 4". Values of variables after performing the operation: [4, -3, 1, -2]
"1 3 4". Values of variables after performing the operation: [4, -3, -1, -2]
"1 1 2". Values of variables after performing the operation: [1, -3, -1, -2]
"1 1 2". Values of variables after performing the operation: [-2, -3, -1, -2]
"1 1 4". Values of variables after performing the operation: [-4, -3, -1, -2]

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
}/*
ll n, m;
vll a(1001, 0);*/
void solve() {
	/*cin >> n >> m;
	string s;
	cin >> s;
	ll cntx = n, idx = n;
	foi(n) {
		if (s[i] == '1') {
			a[i] = 0;
		}
		else {
			a[i]++;
			if (i != 0) {
				a[i] += a[i - 1];
			}
		}
	}
	foi(n) {
		if (s[i] == '1') {
			idx = i;
			break;
		}
	}
	for (ll i = idx; i <= n - 2; i++) {
		if (a[i] > 0 and a[i + 1] == 0) {
			ll st = i - a[i] + 1, mid;
			mid = min(a[i] / 2, m);
			for (ll j = st; j < st + mid; j++) {
				s[j] = '1';
			}
			/*
			cout<<cntx;
			*/

	/*	for (ll j = i; j > i - mid; j--) {
			s[j] = '1';
		}
	}
	}
	if (idx < n) {
	ll cnt;
	cnt = m;
	for (ll i = idx - 1; i >= 0 and cnt--; i--) {
		s[i] = '1';
	}
	}*/
	//cout << s;
	/*if (a[n - 1] > 0 and a[n - 1] < n) {
		ll st = n - 1 - a[n - 1] + 1;
		for (ll j = st; j < st + m and j < n; j++) {
			s[j] = '1';
		}
	}
	cout << s;*/
	ll n;
	cin >> n;
	vll a(n, 0);
	foi(n) {
		ll x;
		cin >> x;
		a[i] = x;
	}
	cout << 3 * n << "\n";
	for (ll i = 0; i < n - 1; i += 2) {
		cout << 1 << " " << i + 1 << " " << i + 2 << "\n";
		cout << 2 << " " << i + 1 << " " << i + 2 << "\n";
		cout << 2 << " " << i + 1 << " " << i + 2 << "\n";
		cout << 1 << " " << i + 1 << " " << i + 2 << "\n";
		cout << 2 << " " << i + 1 << " " << i + 2 << "\n";
		cout << 2 << " " << i + 1 << " " << i + 2 << "\n";
	}

}



