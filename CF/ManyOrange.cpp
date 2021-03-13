/*
B - Many Oranges  / 
Time Limit: 2 sec / Memory Limit: 1024 MB

Score : 
200
 points

Problem Statement
We have many oranges. It is known that every orange weighs between 
A
 and 
B
 grams, inclusive. (An orange can have a non-integer weight.)

We chose some of those oranges, and their total weight was exactly 
W
 kilograms.

Find the minimum and maximum possible numbers of oranges chosen. If no set of oranges can weigh exactly 
W
 kilograms in total, report that fact.

Constraints
1
≤
A
≤
B
≤
1000
1
≤
W
≤
1000
All values in input are integers.
Input
Input is given from Standard Input in the following format:

A
 
B
 
W

Output
Print the minimum and maximum possible numbers of oranges chosen, in this order, with space in between. If there is no number of oranges that can have the specified total weight, print UNSATISFIABLE instead.

Sample Input 1 
Copy
100 200 2
Sample Output 1 
Copy
10 20
Here, one range weighs between 
100
 and 
200
 grams (inclusive).

If we choose 
10
 
200
-gram oranges, their total weight will be exactly 
2
 kilograms.
If we choose 
20
 
100
-gram oranges, their total weight will be exactly 
2
 kilograms.
With less than 
10
 oranges or more than 
20
 oranges, the total weight will never be exactly 
2
 kilograms, so the minimum and maximum possible numbers of oranges chosen are 
10
 and 
20
, respectively.

Sample Input 2 
Copy
120 150 2
Sample Output 2 
Copy
14 16
Here, one range weighs between 
120
 and 
150
 grams (inclusive).

If we choose 
10
 
140
-gram oranges and 
4
 
150
-gram oranges, for example, their total weight will be exactly 
2
 kilograms.
If we choose 
8
 
120
-gram oranges and 
8
 
130
-gram oranges, for example, their total weight will be exactly 
2
 kilograms.
With less than 
14
 oranges or more than 
16
 oranges, the total weight will never be exactly 
2
 kilograms, so the minimum and maximum possible numbers of oranges chosen are 
14
 and 
16
, respectively.

Sample Input 3 
Copy
300 333 1
Sample Output 3 
Copy
UNSATISFIABLE
Here, one range weighs between 
300
 and 
333
 grams (inclusive).

No set of oranges of this kind can weigh exactly 
1
 kilograms in total.
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

	//int t ; cin >> t;
	//while (t--)
	{
		solve();
		cout << "\n";
	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
//vector<int> G[100005];
//ll b[100005], f;
ll ceils(ll x, ll y) {
	return x / y + ((x % y) != 0);
}
ll mult(ll x, ll y, ll mod) {
	return (x * y) % mod;
}
ll bin_pow(ll x, ll p, ll mod) {
	if (p == 0) return 1;
	if (p & 1) return mult(bin_pow(x, p - 1, mod), x, mod);
	return bin_pow(mult(x, x, mod), p / 2, mod);
}

void solve()
{

	ll a, b, w, m1 = 0, n1 = 0;
	cin >> a >> b >> w;
    w*=1000;
  m1=ceils(w,b);
  n1=w/a;
  if(m1>n1)
    cout<<"UNSATISFIABLE";
  else
    cout<<m1<<" "<<n1;
	




}
