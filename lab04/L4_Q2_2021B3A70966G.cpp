#include <climits>
#include <vector>
using namespace std;

bool validateDist(int n, int m, vector<pair<int, int> > farm, int dist) {
  int start = farm[0].first;
  int end = farm[farm.size() - 1].second;

  int index = start;
  int farmIndex = 0;
  int count = 0;
  while (index < end && farmIndex < m) {
    if (index <= farm[farmIndex].second && index >= farm[farmIndex].first) {
      count++;
      index += dist;
    } else if (index >= farm[farmIndex].second &&
               index < farm[farmIndex + 1].first) {
      index = farm[farmIndex + 1].first;
    } else {
      farmIndex++;
    }
  }

  return count >= n;
}

int solve(int n, int m, vector<pair<int, int> > farm) {
  int start = farm[0].first;
  int end = farm[farm.size() - 1].second;

  int left = 1;
  int right = (end - start + 1) / n;

  while (left < right) {
    int mid = (left + right) / 2;
    if (validateDist(n, m, farm, mid)) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return right;
}