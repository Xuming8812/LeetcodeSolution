#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>

using namespace std;

/*
Given a list of non negative integers, arrange them such that they form the largest number.
*/

string largestNumber(vector<int> &num) {
	vector<string> arr;

	for (auto i : num)
		arr.push_back(to_string(i));

	sort(begin(arr), end(arr), [](string &s1, string &s2) { return s1 + s2 > s2 + s1; });

	string res;
	for (auto s : arr)
		res += s;
	while (res[0] == '0' && res.length() > 1)
		res.erase(0, 1);
	return  res;
}