/*
D. Orac and Medians
time limit per test2 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
Slime has a sequence of positive integers a1,a2,…,an.

In one operation Orac can choose an arbitrary subsegment [l…r] of this sequence and replace all values al,al+1,…,ar to the value of median of {al,al+1,…,ar}.

In this problem, for the integer multiset s, the median of s is equal to the ⌊|s|+12⌋-th smallest number in it. For example, the median of {1,4,4,6,5} is 4, and the median of {1,7,5,8} is 5.

Slime wants Orac to make a1=a2=…=an=k using these operations.

Orac thinks that it is impossible, and he does not want to waste his time, so he decided to ask you if it is possible to satisfy the Slime's requirement, he may ask you these questions several times.

Input
The first line of the input is a single integer t: the number of queries.

The first line of each query contains two integers n (1≤n≤100000) and k (1≤k≤109), the second line contains n positive integers a1,a2,…,an (1≤ai≤109)
The total sum of n is at most 100000.

Output
The output should contain t lines. The i-th line should be equal to 'yes' if it is possible to make all integers k in some number of operations or 'no', otherwise. You can print each letter in lowercase or uppercase.

Example
inputCopy
5
5 3
1 5 2 6 1
1 6
6
3 2
1 2 3
4 3
3 1 2 3
10 3
1 2 3 4 5 6 7 8 9 10
outputCopy
no
yes
yes
no
yes
Note
In the first query, Orac can't turn all elements into 3.

In the second query, a1=6 is already satisfied.

In the third query, Orac can select the complete array and turn all elements into 2.

In the fourth query, Orac can't turn all elements into 3.

In the fifth query, Orac can select [1,6] at first and then select [2,10].

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
	ll n, k;
	cin >> n >> k;
	vll a(n, 0);
	ll f = 0;
	foi(n) {
		ll x;
		cin >> x;
		a[i] = x;
		if (x == k)
			f = 1;
	}
	if (f == 0) {
		cout << "No";
		return;
	}
	if (n == 1) {
		cout << "Yes";
		return;
	}
	foi(n) {
		for (ll j = i + 1; j < i + 3 and j < n; j++) {
			if (a[j] >= k and a[i] >= k) {
				cout << "Yes";
				return;
			}
		}
	}
	cout << "No";
}
 
