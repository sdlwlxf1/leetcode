#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

//int longestPalindrome(string s) {
//    unordered_map<char, int> map;
//    for(auto c : s)
//        map[c]++;
//    int ret = 0;
//    for(auto p : map)
//    {
//        if(p.second % 2 == 0)
//            ret += p.second;
//        else if(p.second % 2 == 1 && ret % 2 == 0)
//            ret += 1;
//    }
//    return ret;
//}

//int main() {
//    string s = "abccccdd";
//    int ret = longestPalindrome(s);
//    return ret;
//}
