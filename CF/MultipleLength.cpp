/*
C. Multiples of Length
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given an array a of n integers.

You want to make all elements of a equal to zero by doing the following operation exactly three times:

Select a segment, for each number in this segment we can add a multiple of len to it, where len is the length of this segment (added integers can be different).
It can be proven that it is always possible to make all elements of a equal to zero.

Input
The first line contains one integer n (1≤n≤100000): the number of elements of the array.

The second line contains n elements of an array a separated by spaces: a1,a2,…,an (−109≤ai≤109).

Output
The output should contain six lines representing three operations.

For each operation, print two lines:

The first line contains two integers l, r (1≤l≤r≤n): the bounds of the selected segment.
The second line contains r−l+1 integers bl,bl+1,…,br (−1018≤bi≤1018): the numbers to add to al,al+1,…,ar, respectively; bi should be divisible by r−l+1.
Example
inputCopy
4
1 3 2 4
outputCopy
1 1 
-1
3 4
4 2
2 4
-3 -6 -6
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
string to_oct(ll n) {
	string s;
	while (n) {
		s = to_string(n % 8) + s;
		n /= 8;
	}
	return s;
}
void solve() {
	ll n;
	cin >> n;
	ll a[n];
	foi(n) {
		cin >> a[i];
	}
	cout << 1 << " " << 1 << endl;
	cout << -a[0] << endl;
	a[0] -= a[0];
	cout << 1 << " " << n << endl;
	foi(n) {
		cout << -a[i]*n << " ";
	}
	cout << endl;
	if (2 <= n) {
		cout << 2 << " " << n << endl;
		for (ll i = 1; i < n; i++) {
			cout << (n - 1)*a[i] << " ";
		}
	}
	else {
		cout << 1 << " " << n << endl;
		foi(n) {
			cout << -a[i]*n << " ";
		}
	}
}
 
