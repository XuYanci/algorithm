//
//  LeetCodeSolution_goback.hpp
//  XYAlogrithmExercise
//
//  Created by Yanci on 2019/12/2.
//  Copyright © 2019 Yanci. All rights reserved.
//

#ifndef LeetCodeSolution_goback_hpp
#define LeetCodeSolution_goback_hpp

#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
class LeetCodeSolutionGoBack {
public:
    //    给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
    //
    //    你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
    //
    //    示例:
    //
    //    给定 nums = [2, 7, 11, 15], target = 9
    //
    //    因为 nums[0] + nums[1] = 2 + 7 = 9
    //    所以返回 [0, 1]
    //
    //    来源：力扣（LeetCode）
    //    链接：https://leetcode-cn.com/problems/two-sum
    //    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
    /// 思路1
    /// 暴力解法: 组合，取2个数字， C(2/m)
    /// 假设 N = 4 , N = 2 ,  ( 4 x 3 x 2 x 1 ) / ( 2 x ( 2 x 1)) = 6
    /// 思路2
    
    
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> sumTwo;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size();j++) {
                if (nums[i] + nums[j] == target) {
                    sumTwo.push_back(i);
                    sumTwo.push_back(j);
                    return sumTwo;
                }
            }
        }
        
//        map<int,int> _map;
//        map<int,int>::iterator it1;
//        for(int i = 0; i < nums.size();i++) {
//            it1 = _map.find(target - nums[i]);
//            if (it1 != _map.end() ) {
//                sumTwo.push_back(_map[target-nums[i]] );
//                sumTwo.push_back(i);
//                return sumTwo;
//            }
//            _map[nums[i]] = i;
//
//        }
        
        
        return sumTwo;
    }
};
#endif /* LeetCodeSolution_goback_hpp */
