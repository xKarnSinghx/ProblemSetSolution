/*
B. Balls of Steel
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
You have n distinct points (x1,y1),…,(xn,yn) on the plane and a non-negative integer parameter k. Each point is a microscopic steel ball and k is the attract power of a ball when it's charged. The attract power is the same for all balls.

In one operation, you can select a ball i to charge it. Once charged, all balls with Manhattan distance at most k from ball i move to the position of ball i. Many balls may have the same coordinate after an operation.

More formally, for all balls j such that |xi−xj|+|yi−yj|≤k, we assign xj:=xi and yj:=yi.

An example of an operation. After charging the ball in the center, two other balls move to its position. On the right side, the red dot in the center is the common position of those balls.
Your task is to find the minimum number of operations to move all balls to the same position, or report that this is impossible.

Input
The first line contains a single integer t (1≤t≤100) — the number of test cases.

The first line of each test case contains two integers n, k (2≤n≤100, 0≤k≤106) — the number of balls and the attract power of all balls, respectively.

The following n lines describe the balls' coordinates. The i-th of these lines contains two integers xi, yi (0≤xi,yi≤105) — the coordinates of the i-th ball.

It is guaranteed that all points are distinct.

Output
For each test case print a single integer — the minimum number of operations to move all balls to the same position, or −1 if it is impossible.

Example
inputCopy
3
3 2
0 0
3 3
1 1
3 3
6 7
8 8
6 9
4 1
0 0
0 1
0 2
0 3
outputCopy
-1
1
-1
Note
In the first test case, there are three balls at (0,0), (3,3), and (1,1) and the attract power is 2. It is possible to move two balls together with one operation, but not all three balls together with any number of operations.

In the second test case, there are three balls at (6,7), (8,8), and (6,9) and the attract power is 3. If we charge any ball, the other two will move to the same position, so we only require one operation.

In the third test case, there are four balls at (0,0), (0,1), (0,2), and (0,3), and the attract power is 1. We can show that it is impossible to move all balls to the same position with a sequence of operations.


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

	int t ; cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}



void solve()

{
	ll n, k, ans = -1;
	cin >> n >> k;
	vpll x(n);
	foi(n)
	cin >> x[i].ff >> x[i].ss;
	foi(n ) {
		ll s = -11111111;
		foj(n) {
			s = max(s, (abs(x[i].ff - x[j].ff) + abs(x[i].ss - x[j].ss)));

		}
		if (s <= k)
			ans = 1;
	}
	cout << ans;
}
 
