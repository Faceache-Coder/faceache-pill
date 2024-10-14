#define _CRT_SECURE_NO_WARNINGS

/*取自剑指offer第十九题 正则表达式匹配(题目文本取自leetcode.com)
请设计一个程序来支持用户在文本编辑器中的模糊搜索功能。用户输入内容中可能使用到如下两种通配符：

'.' 匹配任意单个字符。
'*' 匹配零个或多个前面的那一个元素。
*/

#include <cstdio>
#include <string.h>

#define MAX_LEN 50  // 根据实际需求调整最大长度

bool articleMatch1(char* str, char* pattern) {
    if (str == NULL || pattern == NULL)
        return false;
    
    if (*str == '\0' && *pattern == '\0')
        return true;

    if (*str != '\0' && *pattern == '\0')
        return false;

    if (*(pattern + 1) == '*') {
        if (*pattern == *str || (*pattern == '.' && *str != '\0'))
            return articleMatch1(str + 1, pattern + 2)
            || articleMatch1(str, pattern + 2)
            || articleMatch1(str + 1, pattern)
            || articleMatch1(str, pattern + 2);
        else
            return articleMatch1(str, pattern + 2);
    }

    if (*str == *pattern || (*pattern == '.' && *str != '\0'))
        return articleMatch1(str + 1, pattern + 1);
    return false;
}
//原书参考答案,但是由于使用大量递归,时间复杂度较高

bool articleMatch2(char* str, char* pattern) {
    int m = strlen(str);
    int n = strlen(pattern);

    // 创建 DP 表格
    bool dp[MAX_LEN + 1][MAX_LEN + 1];

    // 初始化 DP 表格
    dp[0][0] = true;
    for (int i = 1; i <= m; i++) {
        dp[i][0] = false;
    }
    for (int j = 1; j <= n; j++) {
        dp[0][j] = (pattern[j - 1] == '*') && dp[0][j - 2];
    }

    // 填充 DP 表格
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (pattern[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2] || (str[i - 1] == pattern[j - 2] || pattern[j - 2] == '.') && dp[i - 1][j];
            }
            else {
                dp[i][j] = (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '.') && dp[i - 1][j - 1];
            }
        }
    }

    return dp[m][n];
}
//采用动态规划的方法以减小时间复杂度,但是空间占用较高

bool articleMatch3Core(char* s, char* p)
{
    //初始条件分析1
    if (*s == '\0' && *p == '\0')
        return true;
    //初始条件分析3
    if (*p == '\0' && *s != '\0')
        return false;
    //初始条件分析4
    //可能情况分析2
    if (*(p + 1) == '*')
    {
        //可能情况分析2.(2)(1)及边界条件分析2   
        if (*p == *s || (*p == '.' && *s != '\0'))
        {
            return articleMatch3Core(s + 1, p)
                || articleMatch3Core(s, p + 2);
        }
        //可能情况分析2.(3)
        if (*p != *s && *p != '.')
        {
            return articleMatch3Core(s, p + 2);
        }

        //边界条件分析1.(2)
        else if (*p == '.' && *s == '\0')
            return articleMatch3Core(s, p + 2);
    }
    //可能情况分析1
    if ((*p == '.' && *s != '\0') || *p == *s)
    {
        return articleMatch3Core(s + 1, p + 1);
    }
    return false;
}

bool articleMatch3(char* s, char* p){
    if (s == NULL || p == NULL)
        return false;

    return articleMatch3Core(s, p);
}
//仍旧使用递归,但是空间复杂度较低,时间复杂度也够看

/*=====================================Test======================================*/
void Test(bool judge) {
    if (judge)
        printf("True\n");
    else
        printf("False\n");
}

int main() {
    char str[4] = "aaa";
    char pattern[3] = "a*";
    Test(articleMatch1(str,pattern));
    Test(articleMatch2(str,pattern));
    Test(articleMatch3(str,pattern));
    return 0;
}