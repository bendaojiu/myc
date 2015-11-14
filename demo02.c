#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
有一个字符串符合以下特征（” "abcd11111abcd2222abcdqqqqq"”）,要求写一个函数（接口），输出以下结果
1）	求字符串字串（“abcd”）出现的次数，并把结果传出；
2）	把字符串替换成（dcba11111dcba2222dcbaqqqqq），并把结果传出。
*/

#define str1 "abcd"
#define str2 "dcba"
int strfreplace(char *inbuf, int *times, char **outbuf)
{
	int ret = 0, i = 0, len = 0;
	char *in = NULL, *out = NULL, *tmp1 = NULL, *tmp2 = NULL;
	if (inbuf == NULL)
	{
		ret = -1;
		printf("传入字符串inbuf不能为空\n");
		return ret;
	}
	if (times == NULL)
	{
		ret = -2;
		printf("接收次数地址不能为空\n");
		return ret;
	}
	if (outbuf == NULL)
	{
		ret =-3;
		printf("接收替换后的字符串地址outbuf不能为空\n");
		return ret;
	}
	len = strlen(inbuf);
	in = (char *)malloc((len+1)*sizeof(char));
	memset(in, 0, (len+1));
	out = (char *)malloc((len+1)*sizeof(char));
	memset(out, 0, (len+1));
	if (in == NULL)
	{
		ret = -4;
		printf("内部错误。。。in分配内存出错\n");
		return ret;
	}
	if (out == NULL)
	{
		ret = -4;
		printf("内部错误。。。out分配内存出错\n");
		return ret;
	}
	memcpy(in, inbuf, len);
	memcpy(out, inbuf, len);
	tmp1 = in;
	while(strlen(tmp1)>(strlen(str1)-1))
	{
		tmp2 = strstr(tmp1, str1);
		if (tmp2 == NULL)
		{
			if (tmp1 == in)
			{
				ret = 1;
				break;
			}
			else
			{
				break;
			}
		}
		i ++;
		memcpy(out+(tmp2-in), str2, strlen(str2));
		
		tmp1 = tmp2 + strlen(str1);
	}
	memcpy(*outbuf, out, (len+1));
	*times = i;
	free(in);
	free(out);
	return ret;
}
void main()
{
	int ret = 0, times = 0;
	char *inbuf = "abcd11111abcd2222abcdqqqqq";
	char *outbuf = NULL;
	outbuf = (char *)malloc((strlen(inbuf)+1)*sizeof(char));
	memset(outbuf, 0, (strlen(inbuf)+1));
	ret = strfreplace(inbuf, &times, &outbuf);
	if (ret == 0)
	{
		printf("共出现%d次\n", times);
		printf("替换之后的字符串是:%s\n", outbuf);
	}
	else if (ret == 1)
	{
		printf("该字符串没有出现\n");
	}
	if (outbuf != NULL)
	{
		free(outbuf);
	}
	system("pause");
}