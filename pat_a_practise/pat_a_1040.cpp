/**
 *  
 *  File Name: main.cpp
 *  brief: 
 *  Create Time: 2018年04月26日 15:27:02
 *  
 */


/*
题目大意：
	Given a string, you are supposed to output the length of the longest symmetric sub-string
	即输出序列内最大的对称序列

输入：
	单行：字符串
		--String String.size() <= 1000

输出：
	输出最大的序列的字符数
   */

#include <iostream>
#include <string>

int main ()
{
	std::string in;
	std::getline(std::cin, in);
	auto in_len = in.size();
	int32_t ret = -1;
	for (int32_t i = 0; i < in_len; )
	{
		int32_t start = i-1, end=i+1, _tmp = 1;
		while (end < in_len && 
				in[end] == in[i])
		{
			++_tmp; ++end;
		}
		i = end;
		while (end < in_len && start >= 0 && 
				in[end++] == in[start--])
		{
			_tmp += 2;
		}
		if (_tmp > ret)
		{
			ret = _tmp;
		}
	}
	std::cout << ret << std::endl;
	return 0;
}
