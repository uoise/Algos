#include <vector>

using namespace std;

constexpr int MX = 10;
void rcr(vector<int>& ans, const vector<int>& info, vector<int>& arr,
         const int cur, const int lft, int& cur_high, long long& ord) {
  if (cur >= MX || !lft) {
    arr[MX] = lft;
    int smm = 0;
    for (int i = 0; i < MX; i++) {
      if (info[i] || arr[i]) {
        if (info[i] < arr[i])
          smm += (MX - i);
        else
          smm -= (MX - i);
      }
    }
    if (cur_high < smm) {
      for (int i = 0; i <= MX; i++) ans[i] = arr[i];
      cur_high = smm;
      ord = 0;
      for (int i = MX; i >= 0; i--) ord = ((ord * 10) + arr[i]);
    } else if (cur_high == smm) {
      long long tll = 0;
      for (int i = MX; i >= 0; i--) tll = ((tll * 10) + arr[i]);
      if (ord < tll) {
        for (int i = 0; i <= MX; i++) ans[i] = arr[i];
        ord = tll;
      }
    }
    arr[MX] -= lft;
    return;
  }

  rcr(ans, info, arr, (cur + 1), lft, cur_high, ord);
  if (info[cur] + 1 <= lft) {
    arr[cur] = (info[cur] + 1);
    rcr(ans, info, arr, (cur + 1), (lft - (info[cur] + 1)), cur_high, ord);
    arr[cur] = 0;
  }
}

vector<int> solution(int n, vector<int> info) {
  vector<int> answer(MX + 1, 0), tmp(MX + 1, 0);
  int mxx = -1;
  long long mxn = -1;
  rcr(answer, info, tmp, 0, n, mxx, mxn);
  if (mxx > 0) return answer;
  return {-1};
}