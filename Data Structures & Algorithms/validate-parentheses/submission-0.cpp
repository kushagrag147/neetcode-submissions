class Solution {
public:
    bool isValid(string s) {
        stack<char> pStack;
        unordered_map<char, char> pairOfParenthese = {{')', '('}, {'}', '{'},{']', '['}};

        for (char c: s) {
            switch(c) {
                case '(':
                case '{':
                case '[':
                    pStack.push(c);
                    break;
                case ')':
                case '}':
                case ']':
                    if (pStack.empty()) return false;
                    char poppedChar = pStack.top();
                    pStack.pop();
                    if (poppedChar != pairOfParenthese[c]) {
                        return false;
                    }
                    break;
            }
        }

        return pStack.empty();
    }
};
