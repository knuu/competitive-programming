#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    int L = s.size();
    int ret_len = 1, ret_start = 0;
    for (int i = 0; i < L; i++) {
      int left = i, right = i;
      while (0 <= left and right < L and s[left] == s[right]) left--, right++;
      if (ret_len < right - left - 1) ret_len = right - left - 1, ret_start = left + 1;

      left = i, right = i+1;
      while (0 <= left and right < L and s[left] == s[right]) left--, right++;
      if (ret_len < right - left - 1) ret_len = right - left - 1, ret_start = left + 1;
    }

    return s.substr(ret_start, ret_len);
  }
};
