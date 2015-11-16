#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
��һ���ַ������������������� "abcd11111abcd2222abcdqqqqq"����,Ҫ��дһ���������ӿڣ���������½��
1��	���ַ����ִ�����abcd�������ֵĴ��������ѽ��������
2��	���ַ����滻�ɣ�dcba11111dcba2222dcbaqqqqq�������ѽ��������
*/

int strfreplace(char *inbuf, char *str1, char *str2, int *times, char **outbuf)
{
	int ret = 0, i = 0, len = 0;
	char *inf = NULL, *out = NULL, *tmpTostart = NULL, *tmpToend = NULL, *outf = NULL, *in = NULL;
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
		printf("�ڲ����󡣡���out�����ڴ����\n");
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
	//printf("%d   %d", sizeof(out), strlen(out)); //Ϊʲô��ʾ�Ĳ�һ����������
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