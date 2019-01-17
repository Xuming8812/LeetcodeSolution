#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
We have two integer sequences A and B of the same non-zero length.

We are allowed to swap elements A[i] and B[i].  Note that both elements are in the same index position in their respective sequences.

At the end of some number of swaps, A and B are both strictly increasing.  (A sequence is strictly increasing if and only if A[0] < A[1] < A[2] < ... < A[A.length - 1].)

Given A and B, return the minimum number of swaps to make both sequences strictly increasing.  It is guaranteed that the given input always makes it possible.
*/

int minSwap(vector<int>& A, vector<int>& B) {
	int len = A.size();

	if (len == 0) {
		return 0;
	}

	//initialize the dp matrix
	vector<vector<int>> dp(len, vector(2, INT_MAX));

	dp[0][0] = 0;
	dp[0][1] = 1;

	for (int i = 1; i < len; i++)
	{
		if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
			dp[i][0] = dp[i - 1][0];   //keep both i and i-1
			dp[i][1] = dp[i - 1][1] + 1; //swap both i and i-1
		}
		if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
			dp[i][1] = min(dp[i - 1][0] + 1, dp[i][1]); //swap i 
			dp[i][0] = min(dp[i][0], dp[i - 1][1]);   //swap i-1    
		}
	}

	return min(dp[len - 1][0], dp[len - 1][1]);
}