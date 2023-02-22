#include <string>
#include <vector>

using namespace std;

int tti(int hh, int mm) { return mm + hh * 60; }

vector<vector<pair<int, bool>>> init(const vector<int>& fees,
                                     const vector<string>& records) {
  vector<vector<pair<int, bool>>> vv(10000, vector<pair<int, bool>>());

  for (const auto& rec : records) {
    int pos1 = rec.find(':'), pos2 = rec.find(' ');
    int pos3 = rec.find(' ', pos2 + 1);
    bool inn = ("IN" == rec.substr(pos3 + 1, rec.size()));
    int beg_H = stoi(rec.substr(0, pos1));
    int beg_M = stoi(rec.substr(pos1 + 1, pos2 - 2));
    int car_N = stoi(rec.substr(pos2 + 1, pos3));
    vv[car_N].push_back({tti(beg_H, beg_M), inn});
  }
  return vv;
}

vector<int> solution(vector<int> fees, vector<string> records) {
  constexpr int MXT = 1439;  // 23:59
  const int bas_tim = fees[0], bas_cst = fees[1], per_tim = fees[2],
            per_cst = fees[3];
  vector<int> answer;
  auto vv = init(fees, records);
  for (const auto& vr : vv) {
    if (vr.empty()) continue;
    int tsm = 0, tmp = -1;
    for (const auto& rr : vr) {
      if (rr.second)
        tmp = rr.first;
      else {
        tsm += (rr.first - tmp);
        tmp = -1;
      }
    }
    if (tmp != -1) tsm += (MXT - tmp);

    int r = bas_cst;
    if (tsm >= bas_tim) {
      tsm -= bas_tim;
      r += ((tsm / per_tim) * per_cst);
      if (tsm % per_tim ) r += per_cst;
    }
    answer.push_back(r);
  }

  return answer;
}