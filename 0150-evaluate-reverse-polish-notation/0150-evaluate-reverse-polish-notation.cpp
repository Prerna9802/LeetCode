class Solution {
    using ll = long long;
private:
    map<std::string, function<ll(ll a, ll b)>> ops = { 
        { "+", [](ll a, ll b) { return a + b; }},
        { "-", [](ll a, ll b) { return a - b; }},
        { "*", [](ll a, ll b) { return a * b; }},
        { "/", [](ll a, ll b) { return (b != 0) ? a / b : LONG_LONG_MAX; }} };
public:
    int evalRPN(vector<string>& tokens) {
        stack<ll> stack;

        for(auto const &token: tokens) {
            if(ops.find(token) == ops.end()) {
                stack.push(stoi(token));
            } else {
                ll a = stack.top(); stack.pop();
                ll b = stack.top(); stack.pop();
                stack.push(ops[token](b, a));
            }
        }
        return (int)stack.top();
    }
};