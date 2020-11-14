class Solution {
public:
    int stringtoint(string t) {
        int res = 0;
        int f = 0;
        if(t[0] == '-') f = 1;
        for(int i=f; i<t.size(); i++) {
            res = res * 10 + t[i]-'0';
        }
        if(f == 1) res *= -1;
        return res;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(auto t: tokens) {
            if(t == "+") {
                int a = nums.top(); nums.pop();
                int b = nums.top(); nums.pop();
                nums.push(a + b);
            } else if(t == "-") {
                int a = nums.top(); nums.pop();
                int b = nums.top(); nums.pop();
                nums.push(b - a);
            } else if(t == "*") {
                int a = nums.top(); nums.pop();
                int b = nums.top(); nums.pop();
                nums.push(a * b);
            } else if(t == "/") {
                int a = nums.top(); nums.pop();
                int b = nums.top(); nums.pop();
                nums.push(b / a);
            } else {
                int tmp = stringtoint(t);
                nums.push(tmp);
            }
        }
        return nums.top();
    }
};