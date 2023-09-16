#include <algorithm>
#include <cstdio>

struct dam {
  int att, str, icc, cdm, ias;
  dam() { scanf("%d %d %d %d %d", &att, &str, &icc, &cdm, &ias); }
  dam(int att, int str, int icc, int cdm, int ias) {
    this->att = att, this->str = str;
    this->icc = icc, this->cdm = cdm, this->ias = ias;
  }

  long long get() const {
    long long cd = 100LL * (100 - std::min(icc, 100)) + std::min(icc, 100) * cdm;
    return 1LL * att * (100 + str) * cd * (100 + ias);
  }

  dam operator+(const dam& o) const { return {att + o.att, str + o.str, icc + o.icc, cdm + o.cdm, ias + o.ias}; }
  dam operator-(const dam& o) const { return {att - o.att, str - o.str, icc - o.icc, cdm - o.cdm, ias - o.ias}; }
  bool operator<(const dam& o) const { return get() < o.get(); }
  bool operator==(const dam& o) const { return get() == o.get(); }
};

int main() {
  dam cri = dam();
  dam pav = dam();
  dam crw = dam();
  dam pvw = dam();
  dam crn = cri - crw + pvw, pvn = pav - pvw + crw;
  printf("%c\n", cri == crn ? '0' : cri < crn ? '+' : '-');
  printf("%c", pav == pvn ? '0' : pav < pvn ? '+' : '-');
}