#include <iostream>
#include <set>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

string strSort(string& s) {
    int count[26] = {0}, n = s.length();
    for (int i = 0; i < n; i++)
        count[s[i] - 'a']++;
    int p = 0;
    string t(n, 'a');
    for (int j = 0; j < 26; j++)
        for (int i = 0; i < count[j]; i++)
            t[p++] += j;
    return t;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, multiset<string>> mp;
    for (string s : strs) {
        string t = strSort(s);
        mp[t].insert(s);
    }
    vector<vector<string>> anagrams;
    for (auto m : mp) {
        vector<string> anagram(m.second.begin(), m.second.end());
        anagrams.push_back(anagram);
    }
    return anagrams;
}


//vector< vector<string> > groupAnagrams(vector<string>& strs) {
//    vector< vector<string> > res;
//    vector< unordered_map<char, int> > maps;
//    for(auto str : strs)
//    {
//        int i = 0, j = 0, k = 0;
//        for(i = 0; i < maps.size(); i++)
//        {
//            unordered_map<char, int> t_map = maps[i];
//            for(j = 0; j < str.length(); j++)
//                t_map[str[j]]--;
//            k = 0;
//            for(auto &pair : t_map)
//            {
//                if(pair.second != 0)
//                    break;
//                k++;
//            }
//            if(k == t_map.size())
//                break;
//        }
//        if(i != maps.size())
//            res[i].push_back(str);
//        else {
//            res.push_back(vector<string>({str}));
//            unordered_map<char, int> n_map;
//            for(j = 0; j < str.length(); j++) n_map[str[j]]++;
//            maps.push_back(n_map);
//        }
//    }
//    return res;
//}

int main() {
    vector<string> strs = 
    {
        "", "b"
    };

    vector< vector<string> > res = groupAnagrams(strs);

    return 0;
}
