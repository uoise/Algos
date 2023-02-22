#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;
using ll = long long;

vector<ll> solution(ll k, vector<ll> room_number) {
  vector<ll> ans(room_number.size(), 0);
  unordered_map<ll, ll> loc;
  stack<ll> stk;
  for (int i = 0; i < room_number.size(); i++) {
    const ll& rn = room_number[i];
    auto it = loc.find(rn);
    if (it == loc.end()) {
      loc.insert({rn, rn + 1});
      ans[i] = rn;
    } else {
      stk.push(rn);
      while (it != loc.end()) {
        stk.push(it->second);
        it = loc.find(stk.top());
      }
      ll nn = stk.top() + 1;
      while (!stk.empty()) {
        loc[stk.top()] = nn;
        stk.pop();
      }

      ans[i] = nn - 1;
    }
  }
  return ans;
}