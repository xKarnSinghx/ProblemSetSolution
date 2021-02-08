 /*
 The great hero guards the country where Homer lives. The hero has attack power A and initial health value B. There are n monsters in front of the hero. The i-th monster has attack power ai and initial health value bi.

The hero or a monster is said to be living, if his or its health value is positive (greater than or equal to 1); and he or it is said to be dead, if his or its health value is non-positive (less than or equal to 0).

In order to protect people in the country, the hero will fight with monsters until either the hero is dead or all the monsters are dead.

In each fight, the hero can select an arbitrary living monster and fight with it. Suppose the i-th monster is selected, and the health values of the hero and the i-th monster are x and y before the fight, respectively. After the fight, the health values of the hero and the i-th monster become x−ai and y−A, respectively.
Note that the hero can fight the same monster more than once.

For the safety of the people in the country, please tell them whether the great hero can kill all the monsters (even if the great hero himself is dead after killing the last monster).

Input
Each test contains multiple test cases. The first line contains t (1≤t≤105) — the number of test cases. Description of the test cases follows.

The first line of each test case contains three integers A (1≤A≤106), B (1≤B≤106) and n (1≤n≤105) — the attack power of the great hero, the initial health value of the great hero, and the number of monsters.

The second line of each test case contains n integers a1,a2,…,an (1≤ai≤106), where ai denotes the attack power of the i-th monster.

The third line of each test case contains n integers b1,b2,…,bn (1≤bi≤106), where bi denotes the initial health value of the i-th monster.

It is guaranteed that the sum of n over all test cases does not exceed 105.

Output
For each test case print the answer: "YES" (without quotes) if the great hero can kill all the monsters. Otherwise, print "NO" (without quotes).
Example
input
5
3 17 1
2
16
10 999 3
10 20 30
100 50 30
1000 1000 4
200 300 400 500
1000 1000 1000 1000
999 999 1
1000
1000
999 999 1
1000000
999
output
YES
YES
YES
NO
YES
Note
In the first example: There will be 6 fights between the hero and the only monster. After that, the monster is dead and the health value of the hero becomes 17−6×2=5>0. So the answer is "YES", and moreover, the hero is still living.

In the second example: After all monsters are dead, the health value of the hero will become 709, regardless of the order of all fights. So the answer is "YES".

In the third example: A possible order is to fight with the 1-st, 2-nd, 3-rd and 4-th monsters. After all fights, the health value of the hero becomes −400. Unfortunately, the hero is dead, but all monsters are also dead. So the answer is "YES".

In the fourth example: The hero becomes dead but the monster is still living with health value 1000−999=1. So the answer is "NO".
TAG:greedy    implementation    sortings */
#include<bits/stdc++.h>
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
typedef pair<int, pii>      piii;
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
	ll A, B, n;
	cin >> A >> B >> n;
	ll a[n], b[n];
	ll s = 0, s1 = 0;
	foi(n) {
		cin >> a[i];
		s += a[i];
	}
	foi(n) {
		cin >> b[i];
		s1 += b[i];
	}
	vpll xx(n);
	foi(n)
	{
		xx[i].first = a[i];
		xx[i].second = b[i];

	}
	sort( xx.begin(), xx.end());

	foi(n) {
		ll h ;
		if (xx[i].second % A == 0)
			h = xx[i].second / A;
		else
			h = xx[i].second / A + 1;
		xx[i].second = xx[i].second - (h - 1)  * A;


		B = B - (h - 1) * xx[i].first;
		if (i == n - 1 && B > 0) {
			if ( xx[i].second >= 0) {
				cout << "YES";
				return;
			}
		}
		B = B -  xx[i].first;
		if ( B <= 0) {
			break;
		}
		xx[i].second = xx[i].second -    A;
		if (xx[i].second > 0 ) {
			cout << "NO";
			return;
		}




	}
	if ( B <= 0) {
		cout << "NO";

	}
	else
		cout << "YES";



}

 
