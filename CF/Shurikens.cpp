/*
D. Shurikens
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Tenten runs a weapon shop for ninjas. Today she is willing to sell n shurikens which cost 1, 2, ..., n ryo (local currency). During a day, Tenten will place the shurikens onto the showcase, which is empty at the beginning of the day. Her job is fairly simple: sometimes Tenten places another shuriken (from the available shurikens) on the showcase, and sometimes a ninja comes in and buys a shuriken from the showcase. Since ninjas are thrifty, they always buy the cheapest shuriken from the showcase.

Tenten keeps a record for all events, and she ends up with a list of the following types of records:

+ means that she placed another shuriken on the showcase;
- x means that the shuriken of price x was bought.
Today was a lucky day, and all shurikens were bought. Now Tenten wonders if her list is consistent, and what could be a possible order of placing the shurikens on the showcase. Help her to find this out!

Input
The first line contains the only integer n (1≤n≤105) standing for the number of shurikens.

The following 2n lines describe the events in the format described above. It's guaranteed that there are exactly n events of the first type, and each price from 1 to n occurs exactly once in the events of the second type.

Output
If the list is consistent, print "YES". Otherwise (that is, if the list is contradictory and there is no valid order of shurikens placement), print "NO".

In the first case the second line must contain n space-separated integers denoting the prices of shurikens in order they were placed. If there are multiple answers, print any.

Examples
inputCopy
4
+
+
- 2
+
- 3
+
- 1
- 4
outputCopy
YES
4 2 3 1 
inputCopy
1
- 1
+
outputCopy
NO
inputCopy
3
+
+
+
- 2
- 1
- 3
outputCopy
NO
Note
In the first example Tenten first placed shurikens with prices 4 and 2. After this a customer came in and bought the cheapest shuriken which costed 2. Next, Tenten added a shuriken with price 3 on the showcase to the already placed 4-ryo. Then a new customer bought this 3-ryo shuriken. After this she added a 1-ryo shuriken. Finally, the last two customers bought shurikens 1 and 4, respectively. Note that the order [2,4,3,1] is also valid.

In the second example the first customer bought a shuriken before anything was placed, which is clearly impossible.

In the third example Tenten put all her shurikens onto the showcase, after which a customer came in and bought a shuriken with price 2. This is impossible since the shuriken was not the cheapest, we know that the 1-ryo shuriken was also there.


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
	//while (t--)
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

	ll n;
	cin >> n;
	vll res, ans;
	foi(n * 2)
	{
		char c;
		cin >> c;
		ll x = -1;
		if (c != '+')
			cin >> x;
		res.push_back(x);
	}
	stack<ll> s;
	for (ll i = res.size() - 1; i > -1; i--)
	{
		if (res[i] == -1)
		{
			if (s.empty()) {
				cout << "NO";
				return;
			}
			ll t = s.top();
			s.pop();
			ans.push_back(t);
		}
		else
		{
			if (s.size() && s.top() < res[i]) {
				cout << "NO";
				return;
			}
			s.push(res[i]);
		}
	}
	cout << "YES" << endl;
	for (ll i = n - 1; i > -1; i--)
		cout << ans[i] << ' ';
}
