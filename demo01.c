#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
1、有一个字符串开头或结尾含有n个空格（”   abcdefgdddd    ”），欲去掉前后空格，返回一个新字符串。
要求1：请自己定义一个接口（函数），并实现功能；70分
要求2：编写测试用例。30分
int trimSpace(char *inbuf, char **outbuf);  
*/

int trimSpace(char *inbuf, char **outbuf)
{
	int ret = 0, len = 0;
	char *bufStart = NULL, *bufEnd = NULL, out[1024] = {0};

	if (inbuf == NULL)
	{
		ret = -1;
		printf("inbuf不能为NULL \n");
		return ret;
	}
	if (outbuf == NULL)
	{
		ret = -2;
		printf("outbuf不能为NULL \n");
		return ret;
	}
	len = strlen(inbuf);
	bufStart = inbuf;
	bufEnd = bufStart + len - 1;
	while (*bufStart == ' ')
	{
		bufStart ++;
	}
	while (*bufEnd == ' ')
	{
		bufEnd --;
	}
	memcpy(out, bufStart, bufEnd-bufStart+1);
	*outbuf = out;
	return ret;
}

void main()
{
	char *buf = NULL, *out = NULL;
	int ret = 0;
	buf = (char *)malloc(1024*sizeof(char));
	out = (char *)malloc(1024*sizeof(char));
	memset(buf, 0, 1024);
	//memcpy(buf, "   abcdefgdddd    ",1024);
	memset(out, 0, 1024);
	printf("请输入字符串：\n");
	scanf("%s", buf);
	ret = trimSpace(buf, &out);
	if (ret == 0)
	{
		printf("处理后的字符串是:");
		printf("%s\n", out);
	}
	else
	{
		printf("失败了。。。。。。\n");
	}

	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}
	if (out != NULL)
	{
		free(out);
		out = NULL;
	}
	system("pause");
}