/*
C. Really Big Numbers
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Ivan likes to learn different things about numbers, but he is especially interested in really big numbers. Ivan thinks that a positive integer number x is really big if the difference between x and the sum of its digits (in decimal representation) is not less than s. To prove that these numbers may have different special properties, he wants to know how rare (or not rare) they are — in fact, he needs to calculate the quantity of really big numbers that are not greater than n.

Ivan tried to do the calculations himself, but soon realized that it's too difficult for him. So he asked you to help him in calculations.

Input
The first (and the only) line contains two integers n and s (1 ≤ n, s ≤ 1018).

Output
Print one integer — the quantity of really big numbers that are not greater than n.

Examples
inputCopy
12 1
outputCopy
3
inputCopy
25 20
outputCopy
0
inputCopy
10 9
outputCopy
1
Note
In the first example numbers 10, 11 and 12 are really big.

In the second example there are no really big numbers that are not greater than 25 (in fact, the first really big number is 30: 30 - 3 ≥ 20).

In the third example 10 is the only really big number (10 - 1 ≥ 9).


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


	//ll tc ; cin >> tc;
//	while (tc--)
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
ll sod(ll n) {
	ll s = 0;
	while (n > 0) {
		s += n % 10;
		n /= 10;
	}
	return s;
}
void solve()
{
	ll n, s;
	cin >> n >> s;
	ll cnt = s;
	while (cnt - sod(cnt) < s)
		cnt++;
	cout << max(0ll, n - cnt + 1);
}

 
