#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

//10X5,5里面只是5个字符串 
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

//真正行映射到模板的第几行 
int getrow(int row, int multiple)
{
    if(row == 0)
        return 0;   // 第1行
    //小于尺寸+1，就归类为第2行 
    else if(row < multiple + 1)
        return 1;   // 第2行
    //等于尺寸+1，刚好是中间行 ，第3行 
    else if(row == multiple + 1)
        return 2;   // 第3行
    //最后一行，就取模板的第5行 
    else if(row == 2 * multiple + 2)
        return 4;   // 第5行
    else
        return 3;   // 第4行
}

//将某一行的字符串放大 
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
	//n是尺寸 
    while(scanf("%d%s", &n, s) != EOF && n) {
    	//控制行，若是尺寸为n，则有2 * n + 3行 
        for(int i = 0; i < 2 * n + 3; i++) {
			//控制列 ，针对每一个数字               
            for(int j = 0; j < (int)strlen(s); j++) { 
				//控制空白的输出，刚开始没有空白   
                if(j != 0)
                    printf(" ");
                //getrow(i,n)真实行数i映射到应该取模板中的第几行 
                zoom(typematrix[s[j] - '0'][getrow(i, n)], n);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
