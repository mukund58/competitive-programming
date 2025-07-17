#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main() {

  vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  int left = 0;
  int right = height.size() - 1;
  int area = 0;
  int leftMax = height[left];
  int rightMax = height[right];
  while (left < right) {
    if (leftMax < rightMax) {
      left++;
                        leftMax= max(leftMax,height[left]);
			area += leftMax-height[left];
    } else {
      right--;
        rightMax=max(rightMax,height[right]);
	area += rightMax-height[right];
    }
  }

  cout << area << endl;
}
