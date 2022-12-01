class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
           return true;
          return false;
    }
           
    bool halvesAreAlike(string s) {
        int left=0;
        int right=s.size()-1;
        
        int leftCount=0;
        int rightCount=0;
        while(left<right){
            if (isVowel(s[left++])) leftCount++;
            if(isVowel(s[right--])) rightCount++;
        }
        return leftCount==rightCount;
        
    }
};