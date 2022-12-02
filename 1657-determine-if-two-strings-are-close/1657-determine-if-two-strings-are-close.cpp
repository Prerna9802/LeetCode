class Solution {
public:
    bool closeStrings(string word1, string word2) {
        
        if(word1.size()!=word2.size()) return 0;
        
        vector<int> w1(26,0);
        vector<int> w2(26,0);
        
        for(int i=0;i<word1.size();i++){
            w1[word1[i]-'a']++;
            w2[word2[i]-'a']++;
        }
     
        for(int i=0;i<26;i++){
            if(w1[i]!=0 && w2[i] !=0 && w1[i]!=w2[i] ){
                for(int j=i+1;j<26;j++){
                    if(w1[j]==w2[i]){
                        int t=w1[i];
                        w1[i]=w1[j];
                        w1[j]=t;
                    }
                }
            }
        }
        
        for(int i=0;i<26;i++){
            if(w1[i]!=w2[i]){
                return 0;
            }
        }
        
        return 1;
    }
};