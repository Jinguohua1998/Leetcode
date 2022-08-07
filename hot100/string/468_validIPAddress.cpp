/*
给定一个字符串 queryIP。如果是有效的 IPv4 地址，返回 "IPv4" ；
如果是有效的 IPv6 地址，返回 "IPv6" ；如果不是上述类型的 IP 地址，返回 "Neither" 。

有效的IPv4地址 是 “x1.x2.x3.x4” 形式的IP地址。 其中 0 <= xi <= 255 且 xi 不能包含 前导零。

一个有效的IPv6地址 是一个格式为“x1:x2:x3:x4:x5:x6:x7:x8” 的IP地址，其中:

1 <= xi.length <= 4
xi 是一个 十六进制字符串 ，可以包含数字、小写英文字母( 'a' 到 'f' )和大写英文字母( 'A' 到 'F' )。
在 xi 中允许前导零。
*/
#include <bits/stdc++.h>

using namespace std;

// 字符串操作函数find的使用

class Solution {
public:
    string validIPAddress(string queryIP) {
        if (queryIP.find('.') != string::npos) {
            // IPv4
            int last = -1;
            for (int i = 0; i < 4; ++i) {
                int cur = (i == 3 ? queryIP.size() : queryIP.find('.', last + 1));
                if (cur == string::npos) {
                    return "Neither";
                }
                if (cur - last - 1 < 1 || cur - last - 1 > 3) {
                    return "Neither";
                }
                int addr = 0;
                for (int j = last + 1; j < cur; ++j) {
                    if (!isdigit(queryIP[j])) {
                        return "Neither";
                    }
                    addr = addr * 10 + (queryIP[j] - '0');
                }
                if (addr > 255) {
                    return "Neither";
                }
                if (addr > 0 && queryIP[last + 1] == '0') {
                    return "Neither";
                }
                if (addr == 0 && cur - last - 1 > 1) {
                    return "Neither";
                }
                last = cur;
            }
            return "IPv4";
        }
        else {
            // IPv6
            int last = -1;
            for (int i = 0; i < 8; ++i) {
                int cur = (i == 7 ? queryIP.size() : queryIP.find(':', last + 1));
                if (cur == string::npos) {
                    return "Neither";
                }
                if (cur - last - 1 < 1 || cur - last - 1 > 4) {
                    return "Neither";
                }
                for (int j = last + 1; j < cur; ++j) {
                    if (!isdigit(queryIP[j]) && !('a' <= tolower(queryIP[j]) && tolower(queryIP[j]) <= 'f')) {
                        return "Neither";
                    }
                }
                last = cur;
            }
            return "IPv6";
        }
    }
};
