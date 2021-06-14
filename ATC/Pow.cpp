/*
C - POW  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
300
 points

Problem Statement
For a base number 
X
, the product of multiplying it 
Y
 times is called 
X
 to the 
Y
-th power and represented as 
pow
(
X
,
Y
)
. For example, we have 
pow
(
2
,
3
)
=
2
×
2
×
2
=
8
.

Given three integers 
A
, 
B
, and 
C
, compare 
pow
(
A
,
C
)
 and 
pow
(
B
,
C
)
 to determine which is greater.

Constraints
−
10
9
≤
A
,
B
≤
10
9
1
≤
C
≤
10
9
All values in input are integers.
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
//	ll t ; cin >> t;
//	while (t--)
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
ll n, q;
vll a(100001, 0);
void solve() {
	/*	cin >> n >> q;
		foi(n) {
			ll x;
			cin >> x;
			a[x]++;
		}
		foi(q) {
			ll z;
			cin >> z;
		}*/
	ll a, b, c;
	cin >> a >> b >> c;
	if (c % 2) {
		if (a > 0 and b > 0) {
			if (a > b)
				cout << ">";
			else if (a < b)
				cout << "<";
			else
				cout << "=";
		}
		else if (a > 0 and b < 0)
			cout << ">";
		else if (a<0 and b>0)
			cout << "<";
		else if (a < 0 and b < 0) {
			if (abs(a) > abs(b))
				cout << "<";
			else if (abs(a) < abs(b))
				cout << ">";
			else
				cout << "=";
		}
		else if (a == 0 and b > 0)
			cout << "<";
		else if (b == 0 and a > 0)
			cout << ">";
		else if (a == 0 and b < 0)
			cout << ">";
		else if (b == 0 and a < 0)
			cout << "<";
		else
			cout << "=";
	}
	else {
		if (abs(a) > abs(b))
			cout << ">";
		else if (abs(a) < abs(b))
			cout << "<";
		else
			cout << "=";
	}

}
