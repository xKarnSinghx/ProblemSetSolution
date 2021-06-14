/*
D. Lost Tree
time limit per test3 seconds
memory limit per test256 megabytes
inputstandard input
outputstandard output
This is an interactive problem.

Little Dormi was faced with an awkward problem at the carnival: he has to guess the edges of an unweighted tree of n nodes! The nodes of the tree are numbered from 1 to n.

The game master only allows him to ask one type of question:

Little Dormi picks a node r (1≤r≤n), and the game master will reply with an array d1,d2,…,dn, where di is the length of the shortest path from node r to i, for all 1≤i≤n.
Additionally, to make the game unfair challenge Little Dormi the game master will allow at most ⌈n2⌉ questions, where ⌈x⌉ denotes the smallest integer greater than or equal to x.

Faced with the stomach-churning possibility of not being able to guess the tree, Little Dormi needs your help to devise a winning strategy!

Note that the game master creates the tree before the game starts, and does not change it during the game.

Input
The first line of input contains the integer n (2≤n≤2000), the number of nodes in the tree.

You will then begin interaction.

Output
When your program has found the tree, first output a line consisting of a single "!" followed by n−1 lines each with two space separated integers a and b, denoting an edge connecting nodes a and b (1≤a,b≤n). Once you are done, terminate your program normally immediately after flushing the output stream.

You may output the edges in any order and an edge (a,b) is considered the same as an edge (b,a). Answering is not considered as a query.

Interaction
After taking input, you may make at most ⌈n2⌉ queries. Each query is made in the format "? r", where r is an integer 1≤r≤n that denotes the node you want to pick for that query.

You will then receive n space separated integers d1,d2,…,dn, where di is the length of the shortest path from node r to i, followed by a newline.

After printing a query do not forget to output end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

fflush(stdout) or cout.flush() in C++;
System.out.flush() in Java;
flush(output) in Pascal;
stdout.flush() in Python;
see documentation for other languages.
If at any point you make an invalid query or try to make more than ⌈n2⌉ queries, the interaction will terminate immediately and you will receive a Wrong Answer verdict.

Hacks

To hack a solution, use the following format.

The first line contains the integer n (2≤n≤2000).

The next n−1 lines contain two integers u and v (1≤u,v≤n) denoting an edge between u and v (u≠v). These n−1 edges must form a tree.

Examples
inputCopy
4

0 1 2 2

1 0 1 1
outputCopy
? 1

? 2

!
4 2
1 2
2 3
inputCopy
5

2 2 1 1 0
outputCopy
? 5

!
4 5
3 5
2 4
1 3
Note
Here is the tree from the first example.


Notice that the edges can be output in any order.

Additionally, here are the answers for querying every single node in example 1:

1: [0,1,2,2]
2: [1,0,1,1]
3: [2,1,0,2]
4: [2,1,2,0]
Below is the tree from the second example interaction.


Lastly, here are the answers for querying every single node in example 2:

1: [0,4,1,3,2]
2: [4,0,3,1,2]
3: [1,3,0,2,1]
4: [3,1,2,0,1]
5: [2,2,1,1,0]
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
//	ll t ; cin >> t;
//	while (t--)
	{
		solve();
		cout <<endl;
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
ll n;
vll ask(ll z) {
	ll y = z + 1;
	cout << "? " << y << endl;
	vll fin(n, 0);
	foi(n) {
		ll x;
		cin >> x;
		fin[i] = x;
	}
	return fin;
}
void tra(ll x, graph &g, ll y) {
	ll z = x + 1;
	for (auto it : g[x]) {
		if (it == y) {
			continue;
		}
		else {
			ll z1 = it + 1;
			cout << z << " " << z1 << endl;
		}
		tra(it, g, x);
	}
}
vll visited(2001, 0);
ll xy = 0, odd = 0, even = 0;
void solve() {
	cin >> n;
	graph g(n);
	auto it = ask(xy);
	foi(n) {
		if (it[i] % 2 == 0) {
			even++;
		}
		else {
			odd++;
		}
	}
	if (even <= odd) {
		foi(n) {
			if (it[i] == 1) {
				g[xy].pb(i);
				g[i].pb(xy);
				visited[i] = 1;
			}
			else
				continue;
		}
		for (ll i = 2; i < n; i += 2) {
			foj(n) {
				if (it[j] == i) {
					auto fin = ask(j);
					fok(n) {
						if (fin[k] == 1) {
							g[j].pb(k);
							g[k].pb(j);
							visited[k] = 1;
						}
						else
							continue;
					}
				}
			}
		}
	}
	else {
		for (ll i = 1; i < n; i += 2) {
			foj(n) {
				if (it[j] == i) {
					auto fin = ask(j);
					fok(n) {
						if (fin[k] == 1) {
							g[j].pb(k);
							g[k].pb(j);
							visited[k] = 1;
						}
						else
							continue;
					}
				}
			}
		}
	}
	cout << "!" << endl;
	tra(0ll, g, -1);
	g.clear();
	xy = 0, odd = 0, even = 0;
	visited.clear();
}
 
