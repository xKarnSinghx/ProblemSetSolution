/*
B. Minimum Product
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You are given four integers a, b, x and y. Initially, a≥x and b≥y. You can do the following operation no more than n times:

Choose either a or b and decrease it by one. However, as a result of this operation, value of a cannot become less than x, and value of b cannot become less than y.
Your task is to find the minimum possible product of a and b (a⋅b) you can achieve by applying the given operation no more than n times.

You have to answer t independent test cases.

Input
The first line of the input contains one integer t (1≤t≤2⋅104) — the number of test cases. Then t test cases follow.

The only line of the test case contains five integers a, b, x, y and n (1≤a,b,x,y,n≤109). Additional constraint on the input: a≥x and b≥y always holds.

Output
For each test case, print one integer: the minimum possible product of a and b (a⋅b) you can achieve by applying the given operation no more than n times.

Example
inputCopy
7
10 10 8 5 3
12 8 8 7 2
12343 43 4543 39 123212
1000000000 1000000000 1 1 1
1000000000 1000000000 1 1 1000000000
10 11 2 1 5
10 11 9 1 10
outputCopy
70
77
177177
999999999000000000
999999999
55
10
Note
In the first test case of the example, you need to decrease b three times and obtain 10⋅7=70.

In the second test case of the example, you need to decrease a one time, b one time and obtain 11⋅7=77.

In the sixth test case of the example, you need to decrease a five times and obtain 5⋅11=55.

In the seventh test case of the example, you need to decrease b ten times and obtain 10⋅1=10.


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
void solve() {

	ll a, b, x, y, n;
	cin >> a >> b >> x >> y >> n;
	ll x1 = min(n, a - x), y1 = min(n, b - y);
	ll x2 = min(n - x1, b - y), y2 = min(n - y1, a - x);
	ll ans = min((a - x1) * (b - x2), (a - y2) * (b - y1));
	cout << ans;
}

