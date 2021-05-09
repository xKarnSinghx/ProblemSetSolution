/*
B. Game of the Rows
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
Daenerys Targaryen has an army consisting of k groups of soldiers, the i-th group contains ai soldiers. She wants to bring her army to the other side of the sea to get the Iron Throne. She has recently bought an airplane to carry her army through the sea. The airplane has n rows, each of them has 8 seats. We call two seats neighbor, if they are in the same row and in seats {1, 2}, {3, 4}, {4, 5}, {5, 6} or {7, 8}.

A row in the airplane
Daenerys Targaryen wants to place her army in the plane so that there are no two soldiers from different groups sitting on neighboring seats.

Your task is to determine if there is a possible arranging of her army in the airplane such that the condition above is satisfied.

Input
The first line contains two integers n and k (1 ≤ n ≤ 10000, 1 ≤ k ≤ 100) — the number of rows and the number of groups of soldiers, respectively.

The second line contains k integers a1, a2, a3, ..., ak (1 ≤ ai ≤ 10000), where ai denotes the number of soldiers in the i-th group.

It is guaranteed that a1 + a2 + ... + ak ≤ 8·n.

Output
If we can place the soldiers in the airplane print "YES" (without quotes). Otherwise print "NO" (without quotes).

You can choose the case (lower or upper) for each letter arbitrary.

Examples
inputCopy
2 2
5 8
outputCopy
YES
inputCopy
1 2
7 1
outputCopy
NO
inputCopy
1 2
4 4
outputCopy
YES
inputCopy
1 4
2 2 1 2
outputCopy
YES
Note
In the first sample, Daenerys can place the soldiers like in the figure below:


In the second sample, there is no way to place the soldiers in the plane since the second group soldier will always have a seat neighboring to someone from the first group.

In the third example Daenerys can place the first group on seats (1, 2, 7, 8), and the second group an all the remaining seats.

In the fourth example she can place the first two groups on seats (1, 2) and (7, 8), the third group on seats (3), and the fourth group on seats (5, 6).


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


	//ll t ; cin >> t;
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
	ll n, k;
	cin >> n >> k;
	ll seat1 = 0, y = 0, seat2 = 2 * n, seat4 = n;
	foi(k) {
		ll x;
		cin >> x;
		while (x >= 3 and (seat4 > 0 or seat2 > 0) ) {
			if (x >= 4 and seat4 > 0)
				seat4--, x -= 4;
			else if (seat2 > 0)
				x -= 2, seat2--;
			else if (x == 3 and seat4 > 0)
				x -= 3, seat4--;

		}
		if (x == 2 and seat2 > 0)
			x -= 2, seat2--;
		else if (x == 2 and seat4 > 0)
			seat4--, seat1++;
		else if (x <= 0)
			continue;
		else if (x == 2)
			y += 2;
		else
			y++;
	}
	seat1 += seat2 + seat4 * 2;
	if (y > seat1) {
		cout << "NO";
		return;
	}
	cout << "YES";
}
