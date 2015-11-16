#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
有一个字符串符合以下特征（” "abcd11111abcd2222abcdqqqqq"”）,要求写一个函数（接口），输出以下结果
1）	求字符串字串（“abcd”）出现的次数，并把结果传出；
2）	把字符串替换成（dcba11111dcba2222dcbaqqqqq），并把结果传出。
*/

int strfreplace(char *inbuf, char *str1, char *str2, int *times, char **outbuf)
{
	int ret = 0, i = 0, len = 0;
	char *inf = NULL, *out = NULL, *tmpTostart = NULL, *tmpToend = NULL, *outf = NULL, *in = NULL;
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
	tmpTostart = inbuf;
	tmpToend = inbuf;
	len = strlen(inbuf);
	inf = inbuf;
	
	out = (char *)malloc(1024*sizeof(char));
	memset(out, 0, 1024);
	outf = out;
	in = inbuf;
	
	if (out == NULL)
	{
		ret = -4;
		printf("内部错误。。。out分配内存出错\n");
		return ret;
	}
	

	while(tmpToend != NULL)
	{
		tmpTostart = strstr(inf, str1);
		if (tmpTostart == NULL)
		{
			if (tmpToend == in)
			{
				ret = 1;
				break;
			}
			else
			{
				
				memcpy(outf, tmpToend, sizeof(tmpToend));
				*(outf + sizeof(tmpToend)) = '\0';
				break;
			}
		}
		i ++;
	
		memcpy(outf, tmpToend, tmpTostart - inf);
		outf = outf + (int)(tmpTostart - inf);
		memcpy(outf, str2, strlen(str2));
		outf = outf + strlen(str2);
		tmpToend = tmpTostart + strlen(str1);
		inf = tmpToend;
		
		
	}
	memcpy(*outbuf, out, strlen(out));
	//printf("%d   %d", sizeof(out), strlen(out)); //为什么显示的不一样！！！！是指针，指针就是4字节，所以sizeof是4
	*(*outbuf + strlen(out)) = 0;
	*times = i;

	free(out);
	return ret;
}
void main()
{
	int ret = 0, times = 0;
	char *inbuf = "abcd11111abcd2222abcdqqqqq", *str1 = "abcd", *str2 = "zxcvbnm";
	char *outbuf = NULL;
	outbuf = (char *)malloc(1024*sizeof(char));
	memset(outbuf, 0, (strlen(inbuf)+1));
	ret = strfreplace(inbuf, str1, str2, &times, &outbuf);
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
