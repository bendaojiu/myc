#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
1����һ���ַ�����ͷ���β����n���ո񣨡�   abcdefgdddd    ��������ȥ��ǰ��ո񣬷���һ�����ַ�����
Ҫ��1�����Լ�����һ���ӿڣ�����������ʵ�ֹ��ܣ�70��
Ҫ��2����д����������30��
int trimSpace(char *inbuf, char **outbuf);  
*/

int trimSpace(char *inbuf, char **outbuf)
{
	int ret = 0, len = 0;
	char *bufStart = NULL, *bufEnd = NULL, out[1024] = {0};

	if (inbuf == NULL)
	{
		ret = -1;
		printf("inbuf����ΪNULL \n");
		return ret;
	}
	if (outbuf == NULL)
	{
		ret = -2;
		printf("outbuf����ΪNULL \n");
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
	printf("�������ַ�����\n");
	scanf("%s", buf);
	ret = trimSpace(buf, &out);
	if (ret == 0)
	{
		printf("�������ַ�����:");
		printf("%s\n", out);
	}
	else
	{
		printf("ʧ���ˡ�����������\n");
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