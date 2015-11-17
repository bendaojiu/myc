#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
��һ���ַ�������������������abcdef,acccd,eeee,aaaa,e3eeeee,sssss,";��,Ҫ��дһ���������ӿڣ���������½��
1��	�Զ��ŷָ��ַ������γɶ�ά���飬���ѽ��������
2��	�Ѷ�ά��������������Ҳ������
*/

int merge_buf(char *inbuf, int *num_line, char  ***out_buf)
{
	int ret = 0, num = 0, i = 0;
	char *startToinbuf = NULL, *endToinbuf = NULL, **outbuf = NULL;
	if (inbuf == NULL)
	{
		printf("����inbuf����Ϊ��\n");
		ret = -1;
		return ret;
	}
	/*
	if (outbuf == NULL)
	{
		printf("���outbuf����Ϊ��\n");
		ret = -2;
		return ret;
	}
	*/
	startToinbuf = inbuf;
	endToinbuf = inbuf;
	while (endToinbuf != NULL)
	{
		endToinbuf = strstr(endToinbuf, ",");
		
		if (endToinbuf == NULL)
		{
			break;
		}
		num++;
		endToinbuf = endToinbuf + 1;
		
	}

	outbuf = (char **)malloc(num * sizeof(char *));
	for (i = 0; i < num; i++)
	{
		(outbuf[i]) = (char *)malloc(1024 * sizeof(char));
		memset(outbuf[i], 0, 1024);
	}
	if (outbuf == NULL)
	{
		ret = -2;
		printf("ϵͳ���ܷ����ڴ����\n");
		return ret;
	}
	i = 0;
	endToinbuf = startToinbuf;
	while (endToinbuf != NULL)
	{
		endToinbuf = strstr(startToinbuf, ",");
		if (endToinbuf == NULL)
		{
			break;
		}
		memcpy((outbuf[i]), startToinbuf, (int)(endToinbuf - startToinbuf));
		
		i++;
		startToinbuf = endToinbuf + 1;
	}
	*num_line = num;
	*out_buf = outbuf;
	return ret;
}

int target_buf_free(char ***inbuf, int num)
{
	int ret = 0, i = 0;
	char **tmp_buf = *inbuf;
	for (i = 0; i < num; i++)
	{
		free(tmp_buf[i]);
		tmp_buf[i] = NULL;
	}
	free(*inbuf);
	*inbuf = NULL;
	if (*inbuf != NULL)
	{
		ret = -3;
		printf("�ͷ�ʧ��\n");
		return ret;
	}
	return ret;
}

int main()
{
	int ret = 0, num_line = 0, i = 0;
	char ** const target_buf;
	char  *inbuf = { "abcdef,acccd,eeee,aaaa,e3eeeee,sssss," };
	ret = merge_buf(inbuf, &num_line, &target_buf);
	if (ret == 0)
	{
		for (i = 0; i < num_line; i++)
			printf("%s\n", target_buf[i]);
		
		printf("����%d��\n", num_line);
	}
	ret = target_buf_free(&target_buf, num_line);
	if (ret == 0)
	{
		printf("SUCCESS!!!\n");
	}

	return 0;
}