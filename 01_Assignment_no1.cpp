#include <iostream>
using namespace std;

int strLength(char str[])
{
    int length = 0;
    while (str[length] != '\0')
    {
        length++;
    }
    return length;
}
void strCopy(char dest[], char src[])
{
    int i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}
void strReverse(char str[])
{
    int start = 0;
    int end = strLength(str) - 1;
    char temp;

    while (start < end)
    {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}
void strConcat(char str1[], char str2[])
{
    int len1 = strLength(str1);
    int i = 0;

    while (str2[i] != '\0')
    {
        str1[len1] = str2[i];
        len1++;
        i++;
    }
    str1[len1] = '\0';
}

int main()
{
    char str1[100], str2[100], copyStr[100];

    cout << "Enter first string: ";
    cin >> str1;

    cout << "Enter second string: ";
    cin >> str2;
    cout << "\nLength of first string = " << strLength(str1) << endl;

    strCopy(copyStr, str1);
    cout << "Copy of first string = " << copyStr << endl;

    strReverse(str1);
    cout << "Reverse of first string = " << str1 << endl;

    strConcat(copyStr, str2);
    cout << "Concatenation of copied string + second string = " << copyStr << endl;

    return 0;
}
