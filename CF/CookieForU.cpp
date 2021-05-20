/*
C. A Cookie for You
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Anna is a girl so brave that she is loved by everyone in the city and citizens love her cookies. She is planning to hold a party with cookies. Now she has a vanilla cookies and b chocolate cookies for the party.

She invited n guests of the first type and m guests of the second type to the party. They will come to the party in some order. After coming to the party, each guest will choose the type of cookie (vanilla or chocolate) to eat. There is a difference in the way how they choose that type:

If there are v vanilla cookies and c chocolate cookies at the moment, when the guest comes, then

if the guest of the first type: if v>c the guest selects a vanilla cookie. Otherwise, the guest selects a chocolate cookie.
if the guest of the second type: if v>c the guest selects a chocolate cookie. Otherwise, the guest selects a vanilla cookie.
After that:

If there is at least one cookie of the selected type, the guest eats one.
Otherwise (there are no cookies of the selected type), the guest gets angry and returns to home.
Anna wants to know if there exists some order of guests, such that no one guest gets angry. Your task is to answer her question.

Input
The input consists of multiple test cases. The first line contains a single integer t (1≤t≤1000) — the number of test cases. Next t lines contain descriptions of test cases.

For each test case, the only line contains four integers a, b, n, m (0≤a,b,n,m≤1018,n+m≠0).

Output
For each test case, print the answer in one line. If there exists at least one valid order, print "Yes". Otherwise, print "No".

You can print each letter in any case (upper or lower).

Example
inputCopy
6
2 2 1 2
0 100 0 1
12 13 25 1
27 83 14 25
0 0 1 0
1000000000000000000 1000000000000000000 1000000000000000000 1000000000000000000
outputCopy
Yes
No
No
Yes
No
Yes
Note
In the first test case, let's consider the order {1,2,2} of types of guests. Then:

The first guest eats a chocolate cookie. After that, there are 2 vanilla cookies and 1 chocolate cookie.
The second guest eats a chocolate cookie. After that, there are 2 vanilla cookies and 0 chocolate cookies.
The last guest selects a chocolate cookie, but there are no chocolate cookies. So, the guest gets angry.
So, this order can't be chosen by Anna.

Let's consider the order {2,2,1} of types of guests. Then:

The first guest eats a vanilla cookie. After that, there is 1 vanilla cookie and 2 chocolate cookies.
The second guest eats a vanilla cookie. After that, there are 0 vanilla cookies and 2 chocolate cookies.
The last guest eats a chocolate cookie. After that, there are 0 vanilla cookies and 1 chocolate cookie.
So, the answer to this test case is "Yes".

In the fifth test case, it is illustrated, that the number of cookies (a+b) can be equal to zero, but the number of guests (n+m) can't be equal to zero.

In the sixth test case, be careful about the overflow of 32-bit integer type.
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
	ll a, b, n, m;
	cin >> a >> b >> n >> m;
	if (min(a, b) >= m and a + b >= m + n) {
		cout << "Yes";
	}
	else
		cout << "No";
}
 
