class Solution {
public:
    bool checkclosingBracked(stack<char> order, char ch) {
        if (order.empty()) return false;
        return ((ch == ')' && order.top() == '(') || (ch == ']' && order.top() == '[') 
            || (ch == '}' && order.top() == '{'));
    }
    bool isValid(string s) {
        stack<char> order;

        for (auto ch: s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                order.push(ch);
            } else if (checkclosingBracked(order, ch)) {
                order.pop();
            } else return false;
            
        }
        return order.empty();
    }
};
