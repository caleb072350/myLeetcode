#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

/*
* ����һ: ����
*	��ָ������ַ�����Ҫ���ֺ��ÿ�����ַ���Ψһ�������ַ����������Ŀ������ͨ�������㷨ʵ�֡�
*	���ڳ���Ϊ n ���ַ������� n-1 ����ֵ㡣�����ұ����ַ���������ÿ����ֵ㣬����ڴβ��֮��
*	�µõ���һ���ǿ����ַ���������ֵ��������һ������ֳ��ķǿ����ַ�������֮ǰ��ֳ��ķǿ�
*	���ַ���������ͬ����ǰ�Ĳ�ֵ���Խ��в�֣�Ȼ�������ʣ�µĲ��֣�����ֵ��Ҳ�Ĳ��֣����в�֡�
* 
*	�жϲ�ֳ��ķǿ����ַ����Ƿ����ظ�������ʹ�ù�ϣ��
* 
*	�������ַ���������ʱ�������ֵõ��ķǿ����ַ�������Ŀ�������������Ŀ��
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