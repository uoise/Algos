#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
  vector<int> answer, tmp, tv[501];
  vector<bool> bv(100001, 0);
  int beg, end, cnt, rct = 0;
  for (int i = 1; i < s.size() - 1; i++) {
    if (s[i] == '{') {
      cnt = 0;
      beg = i + 1;
    } else if (s[i] == ',' && beg) {
      end = i;
      tmp.push_back(stoi(s.substr(beg, end - beg)));
      ++cnt;
      beg = i + 1;
    } else if (s[i] == '}') {
      end = i;
      tmp.push_back(stoi(s.substr(beg, end - beg)));
      beg = 0;
      rct = max(rct, ++cnt);
      tv[cnt] = move(tmp);
    }
  }

  for (int i = 1; i <= rct; i++) {
    for (const auto& r : tv[i]) {
      if (!bv[r]) {
        answer.push_back(r);
        bv[r] = 1;
      }
    }
  }

  return answer;
}