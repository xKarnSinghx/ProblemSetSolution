/*
K. The Robot
time limit per test2 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
There is a robot on a checkered field that is endless in all directions. Initially, the robot is located in the cell with coordinates (0,0). He will execute commands which are described by a string of capital Latin letters 'L', 'R', 'D', 'U'. When a command is executed, the robot simply moves in the corresponding direction:

'L': one cell to the left (the x-coordinate of the current cell decreases by 1);
'R': one cell to the right (the x-coordinate of the current cell is increased by 1);
'D': one cell down (the y-coordinate of the current cell decreases by 1);
'U': one cell up (the y-coordinate of the current cell is increased by 1).
Your task is to put an obstacle in one cell of the field so that after executing the commands, the robot will return to the original cell of its path (0,0). Of course, an obstacle cannot be placed in the starting cell (0,0). It is guaranteed that if the obstacle is not placed, then the robot will not return to the starting cell.

An obstacle affects the movement of the robot in the following way: if it tries to go in a certain direction, and there is an obstacle, then it simply remains in place (the obstacle also remains, that is, it does not disappear).

Find any such cell of the field (other than (0,0)) that if you put an obstacle there, the robot will return to the cell (0,0) after the execution of all commands. If there is no solution, then report it.

Input
The first line contains one integer t (1≤t≤500) — the number of test cases.

Each test case consists of a single line containing s — the sequence of commands, which are uppercase Latin letters 'L', 'R', 'D', 'U' only. The length of s is between 1 and 5000, inclusive. Additional constraint on s: executing this sequence of commands leads the robot to some cell other than (0,0), if there are no obstacles.

The sum of lengths of all s in a test doesn't exceed 5000.

Output
For each test case print a single line:

if there is a solution, print two integers x and y (−109≤x,y≤109) such that an obstacle in (x,y) will force the robot to return back to the cell (0,0);
otherwise, print two zeroes (i. e. 0 0).
If there are multiple answers, you can print any of them.

Example
inputCopy
4
L
RUUDL
LLUU
DDDUUUUU
outputCopy
-1 0
1 2
0 0
0 1

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
	string s;
	cin >> s;
	ll x = 0, y = 0, f = 0;
	for (auto k : s)
	{
		if (k == 'U')
			y++;
		else if (k == 'D')
			y--;
		else if (k == 'L')
			x--;
		else if (k == 'R')
			x++;
		ll x1 = 0, y1 = 0;
		for (auto k2 : s)
		{
			ll x2 = x1, y2 = y1;
			if (k2 == 'U')
				y2++;
			else if (k2 == 'D')
				y2--;
			else if (k2 == 'L')
				x2--;
			else if (k2 == 'R')
				x2++;
			if (x2 != x || y2 != y)
				x1 = x2, y1 = y2;
		}
		if (x1 == 0 && y1 == 0)
		{
			f = 1;
			cout << x << " " << y ;
			break;
		}
	}
	if (f == 0)
	{
		cout << "0 0" ;
	}

}
 
