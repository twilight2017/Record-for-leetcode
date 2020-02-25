class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) return "";
		string res = "";//用于存储检索结果的字符串
		for (int i = 0; i < strs[0].size(); i++)//变量i遍历第一个字符串中的每一个字符
		{
			char a = strs[0][i];//对所有字符逐一进行检索
			for (int j = 1; j < strs.size(); j++)//变量j用于遍历字符串集中的每一个字符串
				if (i >= strs[j].size() || strs[j][i] != a)
					return res;
			res.push_back(a);
		}
		return res;
    }

};