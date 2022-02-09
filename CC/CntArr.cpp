/*
Given an array A of length N such that 1≤Ai≤N and Ai≠i, ∀i∈[1,N]

.

Count the number of arrays B
of length N such that ∀i∈[1,N]

:

    Bi≠BAi

1≤Bi≤M

Since the answer may be large, print it modulo 109+7

.
Input Format

    The first line contains a single integer T

− the number of test cases. The description of T
test cases follows.
Each test case contains 2
lines of input:

    The first line of each test case contains two space separated integers N

, M
.
The second line of each test case contains N
space separated integers A1,A2,…,AN

        .

Output Format

For each test case, output a single integer on a newline - answer modulo 109+7

.
Constraints

    1≤T≤105

2≤N≤105
1≤M≤100
1≤Ai≤N,Ai≠i
Sum of N
over all test cases does not exceed 106

Sample Input 1

2
2 3
2 1
3 2
2 1 1

Sample Output 1

6
2

Explanation

Test Case 1
: There are 6 possible arrays - [1,2],[2,1],[1,3],[3,1],[2,3],[3,2]

.

Test Case 2
: There are 2 possible arrays - [1,2,2],[2,1,1].
*/
