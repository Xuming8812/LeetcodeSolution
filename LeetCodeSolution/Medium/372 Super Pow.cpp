#include <vector>
#include <map>
#include <string>
#include <queue>
#include <sstream>
#include <stack>
#include <set>
#include <bitset>

using namespace std;

/*
Your task is to calculate ab mod 1337 where a is a positive integer and 
b is an extremely large positive integer given in the form of an array.
*/

const int base = 1337;

int powmod(int a, int k) //a^k mod 1337 where 0 <= k <= 10
{
	a %= base;
	int result = 1;
	for (int i = 0; i < k; ++i)
		result = (result * a) % base;
	return result;
}

int superPow(int a, vector<int>& b) {
	if (b.empty()) return 1;
	int last_digit = b.back();
	b.pop_back();
	return powmod(superPow(a, b), 10) * powmod(a, last_digit) % base;
}