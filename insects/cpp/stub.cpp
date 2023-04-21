#include "insects.h"
#include"bits/stdc++.h"
#include <cassert>
#include <cstdio>

#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;


const int maxn = 2005;
int ex[maxn];int ix[maxn];
int in[maxn];
int group;

void inside (int i) {
    in[i] = 1;
    move_inside(i);
}
void outside (int i) {
    in[i] = 0;
    move_outside(i);
}

int press () {
    return press_button();
}

vector<int> rem,sel;
int cnt;

int check (int mid, int N, bool flag) {
    rem.clear();
    if (!flag) sel.clear();
    for (int i=0;i<N;i++) {
        if (cnt==group*mid) break;
        if (in[i]||ex[i]) continue;
        inside(i);
        int w = press();
        if (w>mid) {
            outside(i);
            rem.push_back(i);
        }
        else {
            cnt++;
            sel.push_back(i);
        }
    }
    if (cnt==group*mid) return true;
    else return false;
}

void del (int N) {
    for (int i=0;i<N;i++) {
        if (in[i]&&!ix[i]) {
            outside(i);
            cnt--;
        }
    }
    for (int u:rem) ex[u] = 1;
}

void upd (int N) {
    for (int u:sel) ix[u] = 1;
}

int min_cardinality (int N) {
    srand(time(0));
    sel.push_back(0);
    inside(0); group++;cnt++;
    for (int i=1;i<N;i++) {
        inside(i);
        int w = press();
        if (w==1) {
            group++;
            cnt++;
            sel.push_back(i);
        }
        else outside(i);
    }
    if (group==N) return 1;
    int left = 1;int right = N/group;
    int ans = -1;
    while (left<=right) {
        int mid = (left+right+rand()%2)/2;
        if (check(mid,N,(left==1)&&(right==N/group))) {
            left = mid+1;
            ans = mid;
            upd(N);
        }
        else {
        	  right = mid-1;
            del(N);
        }
    }
    return ans;
}

static constexpr int kMaxQueries = 40000;

static int N;
// Insect types are compressed to colors in the range [0, N).
static std::vector<int> color;
static std::vector<bool> in_box;

static std::vector<int> color_occurrences;
static std::multiset<int> max_occurrences;

static std::vector<int> op_counter(3, 0);

static inline void protocol_violation(std::string message) {
  printf("Protocol Violation: %s\n", message.c_str());
  exit(0);
}

void move_inside(int i) {
  if (i < 0 || i >= N) {
    protocol_violation("invalid parameter");
  }
  ++op_counter[0];
  if (op_counter[0] > kMaxQueries) {
    protocol_violation("too many calls");
  }
  if (!in_box[i]) {
    in_box[i] = true;
    max_occurrences.erase(max_occurrences.find(color_occurrences[color[i]]));
    ++color_occurrences[color[i]];
    max_occurrences.insert(color_occurrences[color[i]]);
  }
}

void move_outside(int i) {
  if (i < 0 || i >= N) {
    protocol_violation("invalid parameter");
  }
  ++op_counter[1];
  if (op_counter[1] > kMaxQueries) {
    protocol_violation("too many calls");
  }
  if (in_box[i]) {
    in_box[i] = false;
    max_occurrences.erase(max_occurrences.find(color_occurrences[color[i]]));
    --color_occurrences[color[i]];
    max_occurrences.insert(color_occurrences[color[i]]);
  }
}

int press_button() {
  ++op_counter[2];
  if (op_counter[2] > kMaxQueries) {
    protocol_violation("too many calls");
  }
  return *(max_occurrences.rbegin());
}

int main() {
  assert(1 == scanf("%d", &N));
  color.resize(N);
  in_box.assign(N, false);

  std::map<int, int> type_to_color;
  for (int i = 0; i < N; ++i) {
    int Ti;
    assert(1 == scanf("%d", &Ti));
    if (type_to_color.find(Ti) == type_to_color.end()) {
      int new_color = type_to_color.size();
      type_to_color[Ti] = new_color;
      max_occurrences.insert(0);
    }
    color[i] = type_to_color[Ti];
  }

  color_occurrences.assign(type_to_color.size(), 0);

  int answer = min_cardinality(N);
  int Q = *std::max_element(op_counter.begin(), op_counter.end());
  printf("%d\n", answer);
  printf("%d\n", Q);
  return 0;
}
