class Solution {

public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        vector<string>bucket(s.size()+1,"");
        for(char ch:s) {
            mp[ch]++;
        }
        for(auto const &[key,val]: mp) {
            for(int i = 0; i<val;i++) {
                bucket[val]+=key;
            }
        }
        s.clear();
        for(string &cur: bucket) {
            s+=cur;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};