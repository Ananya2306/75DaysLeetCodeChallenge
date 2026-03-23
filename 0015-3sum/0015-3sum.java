import java.util.AbstractList;
class Solution {
    private List<List<Integer>> res;
    public List<List<Integer>> threeSum(int[] nums) {
        return new AbstractList<List<Integer>>() {
            @Override
            public List<Integer> get(int index) {
                 init();
                return res.get(index);
            }

            @Override
            public int size() {
                 init();
                return res.size();
            }
            public void init(){
                if (res != null) return;
                Arrays.sort(nums);
                int x = 0;
                int itr = nums.length - 3 + 1;
                Set<List<Integer>> result = new HashSet<>();
                while (x < itr) {
                    int i = x;
                    int j=x+1;
                    int k = nums.length - 1;
                    while (j<k) {
                        int sum = nums[i] + nums[j] + nums[k];
                        if (sum == 0) {
                            List<Integer> res= new ArrayList<>();
                            res.add(nums[i]);
                            res.add(nums[j]);
                            res.add(nums[k]);
                            result.add(res);
                        }
                        if(sum<0){
                            ++j;
                        }else{
                            --k;
                        }

                    }
                    ++x;
                }
              res=new ArrayList<>(result);
            }
        };
    }
}