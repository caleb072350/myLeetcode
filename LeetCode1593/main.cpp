#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

/*
* 方法一: 回溯
*	拆分给定的字符串，要求拆分后的每个子字符串唯一，求子字符串的最大数目，可以通过回溯算法实现。
*	对于长度为 n 的字符串，有 n-1 个拆分点。从左到右遍历字符串，对于每个拆分点，如果在次拆分之后，
*	新得到的一个非空子字符串（即拆分点左侧的最后一个被拆分出的非空子字符串）与之前拆分出的非空
*	子字符串都不相同，则当前的拆分点可以进行拆分，然后继续对剩下的部分（即拆分点右侧的部分）进行拆分。
* 
*	判断拆分出的非空子字符串是否有重复，可以使用哈希表。
* 
*	当整个字符串拆分完毕时，计算拆分得到的非空子字符串的数目，并更新最大数目。
*/

int maxSplit;

void backtrack(int index, int split, string& s, unordered_set<string>& us) {
	int length = s.size();
	if (index >= length) {
		maxSplit = max(maxSplit, split);
	}
	else {
		for (int i = index; i < length; i++) {
			string substr = s.substr(index, i - index + 1);
			if (us.find(substr) == us.end()) {
				us.insert(substr);
				backtrack(i + 1, split + 1, s, us);
				us.erase(substr);
			}
		}
	}
}

int maxUniqueSplit(string s) {
	maxSplit = 1;
	unordered_set<string> us;
	backtrack(0, 0, s, us);
	return maxSplit;
}

int main() {
	string s = "aa";
	int maxSplit = maxUniqueSplit(s);
	cout << maxSplit << endl;
}