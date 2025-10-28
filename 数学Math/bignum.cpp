// {"name": "高精度计算", "intro": "对大整数进行计算。"}
#include <bits/stdc++.h>
using namespace std;
class BINT {
  private:
    string s;

  public:
    BINT(string x = "0") : s(x){};
    const BINT operator+(const BINT &t) {
        string sa = s, sb = t.s;
        int la = sa.size(), lb = sb.size();
        int m = max(la, lb);
        vector<int> a(m + 1, 0), b(m + 1, 0), c(m + 1, 0);
        for (int i = 0; i < la; i++) a[i] = sa[la - 1 - i] - '0';
        for (int i = 0; i < lb; i++) b[i] = sb[lb - 1 - i] - '0';
        for (int i = 0; i < m; i++) c[i] += a[i] + b[i], c[i + 1] += c[i] / 10, c[i] = c[i] % 10;
        while (!c[m] && m) m--;
        string res;
        for (int i = m; i >= 0; i--) res += char(c[i] + '0');
        return BINT(res);
    }
    const BINT operator*(const BINT &t) {
        string sa = s, sb = t.s;
        int la = sa.size(), lb = sb.size();
        int m = la + lb;
        vector<int> a(m + 1, 0), b(m + 1, 0), c(m + 1, 0);
        for (int i = 0; i < la; i++) a[i] = sa[la - 1 - i] - '0';
        for (int i = 0; i < lb; i++) b[i] = sb[lb - 1 - i] - '0';
        for (int i = 0; i < la; i++)
            for (int j = 0; j < lb; j++) c[i + j] += a[i] * b[j], c[i + j + 1] += c[i + j] / 10, c[i + j] %= 10;
        while (!c[m] && m) m--;
        string res;
        for (int i = m; i >= 0; i--) res += char(c[i] + '0');
        return BINT(res);
    }
    bool operator<(const BINT &t) {
        string b = t.s;
        if (s.size() < b.size()) return true;
        if (s.size() == b.size() && s < b) return true;
        return false;
    }
    void operator=(const string &x) { s = x; }
    void operator=(const long long &x) { s = to_string(x); }
    void operator=(const int &x) { s = to_string(x); }
    friend istream &operator>>(istream &in, BINT &t) {
        in >> t.s;
        return in;
    }
    friend ostream &operator<<(ostream &out, const BINT &t) {
        out << t.s;
        return out;
    }
};
signed main() { return 0; }