#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
��һ���ַ������������������� "abcd11111abcd2222abcdqqqqq"����,Ҫ��дһ���������ӿڣ���������½��
1��	���ַ����ִ�����abcd�������ֵĴ��������ѽ��������
2��	���ַ����滻�ɣ�dcba11111dcba2222dcbaqqqqq�������ѽ��������
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
		printf("�����ַ���inbuf����Ϊ��\n");
		return ret;
	}
	if (times == NULL)
	{
		ret = -2;
		printf("���մ�����ַ����Ϊ��\n");
		return ret;
	}
	if (outbuf == NULL)
	{
		ret =-3;
		printf("�����滻����ַ�����ַoutbuf����Ϊ��\n");
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
		printf("�ڲ����󡣡���in�����ڴ����\n");
		return ret;
	}
	if (out == NULL)
	{
		ret = -4;
		printf("�ڲ����󡣡���out�����ڴ����\n");
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
		printf("������%d��\n", times);
		printf("�滻֮����ַ�����:%s\n", outbuf);
	}
	else if (ret == 1)
	{
		printf("���ַ���û�г���\n");
	}
	if (outbuf != NULL)
	{
		free(outbuf);
	}
	system("pause");
}