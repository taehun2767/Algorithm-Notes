class Solution {
    public int[] searchRange(int[] nums, int target) {
       int first = binarySearch(nums, target, true);
       int last = binarySearch(nums, target, false);
       return new int[]{ first, last };
    }
    private int binarySearch(int[] nums, int target, boolean isStart) {
        int left = 0;
        int right = nums.length - 1;
        int ret = -1;
        while(left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target){
                ret = mid;
                if (isStart) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }

            if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ret;
    }
}
