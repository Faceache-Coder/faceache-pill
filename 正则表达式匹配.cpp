#define _CRT_SECURE_NO_WARNINGS

/*ȡ�Խ�ָoffer��ʮ���� ������ʽƥ��(��Ŀ�ı�ȡ��leetcode.com)
�����һ��������֧���û����ı��༭���е�ģ���������ܡ��û����������п���ʹ�õ���������ͨ�����

'.' ƥ�����ⵥ���ַ���
'*' ƥ���������ǰ�����һ��Ԫ�ء�
*/

#include <cstdio>
#include <string.h>

#define MAX_LEN 50  // ����ʵ�����������󳤶�

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
//ԭ��ο���,��������ʹ�ô����ݹ�,ʱ�临�ӶȽϸ�

bool articleMatch2(char* str, char* pattern) {
    int m = strlen(str);
    int n = strlen(pattern);

    // ���� DP ���
    bool dp[MAX_LEN + 1][MAX_LEN + 1];

    // ��ʼ�� DP ���
    dp[0][0] = true;
    for (int i = 1; i <= m; i++) {
        dp[i][0] = false;
    }
    for (int j = 1; j <= n; j++) {
        dp[0][j] = (pattern[j - 1] == '*') && dp[0][j - 2];
    }

    // ��� DP ���
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
//���ö�̬�滮�ķ����Լ�Сʱ�临�Ӷ�,���ǿռ�ռ�ýϸ�

bool articleMatch3Core(char* s, char* p)
{
    //��ʼ��������1
    if (*s == '\0' && *p == '\0')
        return true;
    //��ʼ��������3
    if (*p == '\0' && *s != '\0')
        return false;
    //��ʼ��������4
    //�����������2
    if (*(p + 1) == '*')
    {
        //�����������2.(2)(1)���߽���������2   
        if (*p == *s || (*p == '.' && *s != '\0'))
        {
            return articleMatch3Core(s + 1, p)
                || articleMatch3Core(s, p + 2);
        }
        //�����������2.(3)
        if (*p != *s && *p != '.')
        {
            return articleMatch3Core(s, p + 2);
        }

        //�߽���������1.(2)
        else if (*p == '.' && *s == '\0')
            return articleMatch3Core(s, p + 2);
    }
    //�����������1
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
//�Ծ�ʹ�õݹ�,���ǿռ临�ӶȽϵ�,ʱ�临�Ӷ�Ҳ����

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