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

    //----------------------------------------------//
    int evalRPN(vector<string> &tokens) {
        int n = tokens.size();
        if (n == 1) return (atoi(tokens[0].c_str()));
        if (!n) return 0;
        stack<int> s;
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                s.push(atoi(tokens[i].c_str()));
            } else {
                ret = s.top();
                s.pop();
                if (!s.size()) return ret;
                if (tokens[i] == "+") {
                    ret += s.top();
                } else if (tokens[i] == "-") {
                    ret = s.top() - ret;
                } else if (tokens[i] == "*") {
                    ret *= s.top();
                } else {
                    ret = s.top() / ret;
                }
                s.pop();
                s.push(ret);
            }
        }
        return ret;
    }
};