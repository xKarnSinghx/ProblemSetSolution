/*
You are given two integers N,K such that K+1≤N≤2K−1. Your friend is hiding from you a permutation (P1,P2,…,PN) of integers from 1 to N

, whose elements are written cyclically.

Your friend doesn't tell you the permutation. Instead, he tells you this. For each i
from 1 to N he will tell you Ai − the number of such integers j with 0≤j<K such that P((i+j)modN)+1<Pi

.

Given A1,A2,…,AN
, find any permutation P

producing them or tell that there is no such permutation.
Input Format

The first line of the input contains a single integer T
−

the number of test cases. The description of test cases follows.

The first line of each test case contains two integers N,K

.

The second line of each test case contains N
integers A1,A2,…,AN

.
Output Format

For each test case, if there is no permutation producing array A
, output −1. Otherwise, output N integers P1,P2,…,PN (1≤Pi≤N, Pi≠Pj for i≠j) −

the required permutation. If there are several such permutations, you can output any.
Constraints

    1≤T≤105

1≤K+1≤N≤2K−1
.
0≤Ai≤K
3≤N≤2⋅105
The sum of N
over all test cases doesn't exceed 2⋅105

Subtasks

Subtask 1 (50 points): The sum of N
over all test cases doesn't exceed 2000

Subtask 2 (50 points): No additional constraints
Sample Input 1

2
5 3
1 2 1 3 0
5 3
3 0 0 0 1

Sample Output 1

3 4 2 5 1 
-1

Explanation

In the first test case, (3,4,2,5,1)
produces A=[1,2,1,3,0]. Indeed, there is one element among 4,2,5 smaller than 3, there are 2 elements among 2,5,1 smaller than 4, one element among 5,1,3 smaller than 2, three elements among 1,3,4 smaller than 5, and no elements among 3,4,2 smaller than 1

.

It can be shown that array A
from the second test case doesn't correspond to any permutation.
*/
