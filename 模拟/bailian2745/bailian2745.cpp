#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

//10X5,5����ֻ��5���ַ��� 
string typematrix[10][5] = {
    {
        " - ",
        "| |",
        "   ",
        "| |",
        " - "
    },
    {
        "   ",
        "  |",
        "   ",
        "  |",
        "   "
    },
    {
        " - ",
        "  |",
        " - ",
        "|  ",
        " - "
    },
    {
        " - ",
        "  |",
        " - ",
        "  |",
        " - "
    },
    {
        "   ",
        "| |",
        " - ",
        "  |",
        "   "
    },
    {
        " - ",
        "|  ",
        " - ",
        "  |",
        " - "
    },
    {
        " - ",
        "|  ",
        " - ",
        "| |",
        " - "
    },
    {
        " - ",
        "  |",
        "   ",
        "  |",
        "   "
    },
    {
        " - ",
        "| |",
        " - ",
        "| |",
        " - "
    },
    {
        " - ",
        "| |",
        " - ",
        "  |",
        " - "
    }
};

//������ӳ�䵽ģ��ĵڼ��� 
int getrow(int row, int multiple)
{
    if(row == 0)
        return 0;   // ��1��
    //С�ڳߴ�+1���͹���Ϊ��2�� 
    else if(row < multiple + 1)
        return 1;   // ��2��
    //���ڳߴ�+1���պ����м��� ����3�� 
    else if(row == multiple + 1)
        return 2;   // ��3��
    //���һ�У���ȡģ��ĵ�5�� 
    else if(row == 2 * multiple + 2)
        return 4;   // ��5��
    else
        return 3;   // ��4��
}

//��ĳһ�е��ַ����Ŵ� 
void zoom(string& s, int n)
{
    printf("%c", s[0]);
    for(int i = 0; i < n; i++)
        printf("%c", s[1]);
    printf("%c", s[2]);
}

int main()
{
    int n;
    char s[100];
	//n�ǳߴ� 
    while(scanf("%d%s", &n, s) != EOF && n) {
    	//�����У����ǳߴ�Ϊn������2 * n + 3�� 
        for(int i = 0; i < 2 * n + 3; i++) {
			//������ �����ÿһ������               
            for(int j = 0; j < (int)strlen(s); j++) { 
				//���ƿհ׵�������տ�ʼû�пհ�   
                if(j != 0)
                    printf(" ");
                //getrow(i,n)��ʵ����iӳ�䵽Ӧ��ȡģ���еĵڼ��� 
                zoom(typematrix[s[j] - '0'][getrow(i, n)], n);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
