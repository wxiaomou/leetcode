class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> s;        
        if (!tokens.size()) return 0;
        if (tokens.size() == 1) return atoi(tokens[0].c_str());
        for (int i = 0; i < tokens.size(); i++) {
            string c = tokens[i];
            if (c != "+" && c != "-" && c != "*" && c != "/") {
                s.push(atoi(tokens[i].c_str()));
            } else {
                int tmp = s.top();
                s.pop();
                if (c == "+")
                        s.top() += tmp;
                else if (c == "-")
                        s.top() -= tmp;
                else if (c == "*")
                        s.top() *= tmp;
                else if (c == "/")
                        s.top() /= tmp;
                else
                        return -1;
            }
        }
        return s.top();
    }
};