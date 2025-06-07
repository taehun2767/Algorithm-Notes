/* nums (array) - non-decreasing order 
 * purpose : remove the duplicates in-place, same order 
 * return - number of unique element size (k)
 */
class Solution {
    public int removeDuplicates(int[] nums) {
        int j = 0;
        int prev = -10000;
        for (int i = 0; i < nums.length; i++){
            if (prev != nums[i]){
                nums[j++] = nums[i]; 
            }
            prev= nums[i];
        }

        return j;
    }
}
