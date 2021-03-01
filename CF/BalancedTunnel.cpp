/*
B. Balanced Tunnel
time limit per test1 second
memory limit per test512 megabytes
inputstandard input
outputstandard output
Consider a tunnel on a one-way road. During a particular day, n cars numbered from 1 to n entered and exited the tunnel exactly once. All the cars passed through the tunnel at constant speeds.

A traffic enforcement camera is mounted at the tunnel entrance. Another traffic enforcement camera is mounted at the tunnel exit. Perfectly balanced.

Thanks to the cameras, the order in which the cars entered and exited the tunnel is known. No two cars entered or exited at the same time.

Traffic regulations prohibit overtaking inside the tunnel. If car i overtakes any other car j inside the tunnel, car i must be fined. However, each car can be fined at most once.

Formally, let's say that car i definitely overtook car j if car i entered the tunnel later than car j and exited the tunnel earlier than car j. Then, car i must be fined if and only if it definitely overtook at least one other car.

Find the number of cars that must be fined.

Input
The first line contains a single integer n (2≤n≤105), denoting the number of cars.

The second line contains n integers a1,a2,…,an (1≤ai≤n), denoting the ids of cars in order of entering the tunnel. All ai are pairwise distinct.

The third line contains n integers b1,b2,…,bn (1≤bi≤n), denoting the ids of cars in order of exiting the tunnel. All bi are pairwise distinct.

Output
Output the number of cars to be fined.

Examples
inputCopy
5
3 5 2 1 4
4 3 2 5 1
outputCopy
2
inputCopy
7
5 2 3 6 7 1 4
2 3 6 7 1 4 5
outputCopy
6
inputCopy
2
1 2
1 2
outputCopy
0
Note
The first example is depicted below:



Car 2 definitely overtook car 5, while car 4 definitely overtook cars 1, 2, 3 and 5. Cars 2 and 4 must be fined.

In the second example car 5 was definitely overtaken by all other cars.

In the third example no car must be fined.


*/
#include<bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
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
typedef pair<ll, pll>      plll;
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
typedef priority_queue<pii, vector<pii>, greater<pii> > pqq;
#define MOD  1000000007;
void solve();


int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);

#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("error1.txt", "w", stderr);
	freopen("output1.txt", "w", stdout);
#endif


		solve();
	

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
ll ceil(ll x, ll y) {
	return x / y + ((x % y) != 0);
}
void solve()

{
	ll n;
	cin >> n;
	queue<ll> a, b;
	vll check(n + 1), check1(n + 1);
	foi(n) {
		ll x;
		cin >> x;
		a.push(x);
		check[x] = 1;

	}
	foi(n) {
		ll x;
		cin >> x;
		b.push(x);
		check1[x] = 1;
	}
	ll ans = 0;
	while (!a.empty() && !b.empty()) {
		ll x2 = a.front(), y2 = b.front();
even: if (check[x2] == 0) {
			a.pop();

		}
		x2 = a.front(), y2 = b.front();
		if (check[x2] == 0) {
			goto even;

		}
		if (y2 == x2 && check[y2] == 1) {
			check[y2] = 0;
			b.pop();

		}
		if (y2 != x2 && check[y2] == 1 ) {
			check[y2] = 0;
			b.pop();
			ans++;

		}
	}
	cout << ans;

}
/*
//alternate soln
int n;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		--a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		--b[i];
	}

	vector<int> pos(n);
	for (int i = 0; i < n; i++) {
		pos[b[i]] = i;
	}

	vector<int> c(n);
	for (int i = 0; i < n; i++) {
		c[i] = pos[a[i]];
	}
	for (int i = 0; i < n; i++) {
		cout << c[i];
		//--b[i];
	}
	int mx = -1, ans = 0;
	for (int i = 0; i < n; i++) {
		if (c[i] > mx) {
			mx = c[i];
		} else {
			++ans;
		}
	}
	cout << ans << '\n';*/

