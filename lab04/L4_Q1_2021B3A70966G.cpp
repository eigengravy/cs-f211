#include <vector>
using namespace std;

struct ret {
  int left_prefix;
  int right_suffix;
  int acc_product;
  int max_product;
};

void print_ret(char* s, int left, int right, ret r) {
  cout << s << " " << left << " " << right << " " << r.left_prefix << " "
       << r.right_suffix << " " << r.acc_product << " " << r.max_product
       << endl;
}

ret max_product_subarray(vector<int>& nums, int left, int right) {
  if (left == right) {
    return {nums[left], nums[right], nums[left], nums[right]};
  }

  int mid = (left + right) / 2;

  ret left_subarray = max_product_subarray(nums, left, mid);
  ret right_subarray = max_product_subarray(nums, mid + 1, right);

  int left_prefix = left_subarray.acc_product;
  int right_prefix = right_subarray.acc_product;
  int acc_product = left_subarray.acc_product * right_subarray.acc_product;
  int max_product = max(
      acc_product, max(left_subarray.max_product, right_subarray.max_product));
  ret r = {left_prefix, right_prefix, acc_product, max_product};
  return r;
}

int solve(vector<int>& nums) {
  int left = 0;
  int right = nums.size() - 1;
  return max_product_subarray(nums, left, right).max_product;
}
