class Solution {
 public:
  int calSteps(int n, long n1, long n2) {
    int steps = 0;
    while (n1 <= n) {
      steps += min((long)n + 1, n2) - n1;
      n1 *= 10;
      n2 *= 10;
    }
    return steps;
  }

  int findKthNumber(int n, int k) {
    int curr = 1;
    k = k - 1;  // We start counting from 1, so decrement k by 1
    while (k > 0) {
      int steps = calSteps(n, curr, curr + 1);
      if (steps <= k) {
        curr += 1;   // Move to the next number in the same level
        k -= steps;  // Decrease k by the number of steps taken
      } else {
        curr *= 10;  // Move to the next level (first child of the current number)
        k -= 1;      // Account for moving down one level
      }
    }
    return curr;
  }
};