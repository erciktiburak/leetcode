class Solution {
    public int kthFactor(int n, int k) {
        List<Integer> factors = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                factors.add(i);
            }
        }
        return k <= factors.size() ? factors.get(k - 1) : -1;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.kthFactor(12, 3));  // Output: 3
        System.out.println(solution.kthFactor(7, 2));   // Output: 7
        System.out.println(solution.kthFactor(4, 4));   // Output: -1
    }
}
