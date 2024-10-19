import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ThreeSum {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        
        // Edge case: if nums has fewer than 3 elements, return an empty list
        if (nums == null || nums.length < 3) {
            return result;
        }

        // Sort the array to use two-pointer technique
        Arrays.sort(nums);

        for (int i = 0; i < nums.length - 2; i++) {
            // Skip duplicates for the first element in the triplet
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            // Use two pointers to find the rest of the triplet
            int target = -nums[i]; // target sum we are looking for
            int left = i + 1;
            int right = nums.length - 1;

            while (left < right) {
                int sum = nums[left] + nums[right];

                if (sum == target) {
                    // Found a valid triplet
                    result.add(Arrays.asList(nums[i], nums[left], nums[right]));
                    
                    // Move left and right pointers to skip duplicates
                    left++;
                    right--;

                    while (left < right && nums[left] == nums[left - 1]) {
                        left++; // Skip duplicate elements for left
                    }

                    while (left < right && nums[right] == nums[right + 1]) {
                        right--; // Skip duplicate elements for right
                    }

                } else if (sum < target) {
                    left++; // We need a larger sum, move the left pointer to the right
                } else {
                    right--; // We need a smaller sum, move the right pointer to the left
                }
            }
        }

        return result;
    }

    public static void main(String[] args) {
        ThreeSum solution = new ThreeSum();
        int[] nums = {-1, 0, 1, 2, -1, -4};
        List<List<Integer>> result = solution.threeSum(nums);

        // Print each triplet
        for (List<Integer> triplet : result) {
            System.out.println(triplet);
        }
    }
}
