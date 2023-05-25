#include "Function.h"
void standardizeName(string &s)
{
    int n = s.length();
    // Xóa khoảng trắng đầu và cuối xâu
    while (s[0] == ' ')
    {
        s.erase(s.begin() + 0); // Xoa ki tu tai vi tri 0
    }
    while (s[n - 1] == ' ')
    {
        s.erase(s.begin() + (n - 1)); // Xoa ki tu tai vi tri cuoi
    }
    // xoa khoang trang thua o giua cac tu
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ' && s[i + 1] == ' ')
        {
            s.erase(s.begin() + i);
            i--;
        }
    }
    // viet hoa moi ki tu dau
    strlwr((char *)s.c_str()); // chuyen ve chuoi in thuong
    s[0] = s[0] - 32;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == ' ' && s[i + 1] != ' ')
        {
            s[i + 1] = s[i + 1] - 32;
        }
    }
}
