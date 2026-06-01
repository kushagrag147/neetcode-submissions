class Solution {
public:
    bool isPalindrome(string s) {
        
        int i=0, j=s.length()-1;
        while (i<j) {
            if (!isAsciiAlnum(s[i])){
                i++;
                continue;
            }
            if (!isAsciiAlnum(s[j])){
                j--;
                continue;
            }
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

    bool isAsciiAlnum(char ch) {
    return (ch >= 'A' && ch <= 'Z') || 
           (ch >= 'a' && ch <= 'z') || 
           (ch >= '0' && ch <= '9');
    }
};
