bool containsCloseNums(std::vector<int> nums, int k) {
    map <int, int> last_oc;
    int size= nums.size();

    for (int i = 0; i < size; i++) {
        if(last_oc.find(nums[i]) == last_oc.end()) last_oc[nums[i]] = i;
        else {
            if (i-last_oc[nums[i]] <= k) return true;
            else {
                last_oc[nums[i]] = i;
            }
        }
    }
    return false;
}
