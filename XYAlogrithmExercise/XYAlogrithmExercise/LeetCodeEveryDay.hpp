//
//  LeetCodeEveryDay.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2020/3/13.
//  Copyright © 2020 Yanci. All rights reserved.
//

#ifndef LeetCodeEveryDay_hpp
#define LeetCodeEveryDay_hpp

#include <stdio.h>
#include <vector>
#include <unordered_map>
using namespace std;
class LeetCodeEveryDay {
public:
//    给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
//    
//    你可以假设数组是非空的，并且给定的数组总是存在多数元素。
//    
//    来源：力扣（LeetCode）
//    链接：https://leetcode-cn.com/problems/majority-element
//    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
    int majorityElement(vector<int>& nums) {
        int count = nums.size() / 2;
        unordered_map<int,int>map;
        for (int i = 0; i < nums.size();i++) {
            map[nums[i]] = map[nums[i]] ? map[nums[i]] + 1 : 1;
            if (map[nums[i]] > count) {
                return nums[i];
            }
        }
        
        return 0;
    }
};

#endif /* LeetCodeEveryDay_hpp */
