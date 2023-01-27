// 791. Custom Sort String...

class Solution {
public:
    string customSortString(string order, string s) {
        int a[26] = {0};
        for (auto i : s){
            a[i-'a']++;
        }
        string str = "";
        for (auto i : order){
            if (a[i-'a'] > 0){
                str.insert(str.end(),a[i-'a'], i);
                a[i-'a'] = 0;
            }
        }
        for (auto i : s){
            if (a[i-'a'] > 0){
                str.push_back(i);
            }
        }
        return str;
    }
};

