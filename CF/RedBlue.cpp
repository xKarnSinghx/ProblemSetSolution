/*
A. Red and Blue Beans
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You have r red and b blue beans. You'd like to distribute them among several (maybe, one) packets in such a way that each packet:

has at least one red bean (or the number of red beans ri≥1);
has at least one blue bean (or the number of blue beans bi≥1);
the number of red and blue beans should differ in no more than d (or |ri−bi|≤d)
Can you distribute all beans?

Input
The first line contains the single integer t (1≤t≤1000) — the number of test cases.

The first and only line of each test case contains three integers r, b, and d (1≤r,b≤109; 0≤d≤109) — the number of red and blue beans and the maximum absolute difference in each packet.

Output
For each test case, if you can distribute all beans, print YES. Otherwise, print NO.

You may print every letter in any case you want (so, for example, the strings yEs, yes, Yes and YES are all recognized as positive answer).

Example
inputCopy
4
1 1 0
2 7 3
6 1 4
5 4 0
outputCopy
YES
YES
NO
NO
Note
In the first test case, you can form one packet with 1 red and 1 blue bean. The absolute difference |1−1|=0≤d.

In the second test case, you can form two packets: 1 red and 4 blue beans in the first packet and 1 red and 3 blue beans in the second one.

In the third test case, since b=1, you can form only one packet with 6 red and 1 blue beans. The absolute difference |6−1|=5>d.

In the fourth test case, since d=0 so each packet should contain the same number of red and blue beans, but r≠b.


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
ll sod(ll n) {
	ll s = 0;
	while (n > 0) {
		s += n % 10;
		n /= 10;
	}
	return s;
}
ll a, b;
ll cal(ll x1, ll y1, ll x2, ll y2)
{
	ll area = x1 * y1 + x2 * y2;
	if (x1 + x2 <= a && y1 <= b && y2 <= b)
		return area;
	if (y1 + y2 <= b && x1 <= a && x2 <= a)
		return area;
	return 0;
}
void solve()
{
	ll r, b, d;
	cin >> r >> b >> d;
	ll x = min(r, b);
	if (d == 0) {
		if (r == b)
			cout << "YES";
		else
			cout << "NO";
		return;
	}
	if (x * d + x >= max(r, b))
		cout << "YES";
	else
		cout << "NO";

}

 
