//
//  main.cpp
//  General Number Field Sieve
//
//  Created by Deven Mithal on 7/17/19.
//  Copyright © 2019 Deven Mithal. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

void strange_counting_sort(vector<string>& nums, vector<int> mapping, int digit){
    int real_count[10];
    for(int i = 0; i < 10; ++i){
        real_count[i] = 0;
    }
    
    vector<string> output(nums.size());
    char curr_digit = ' ';
    for(int i = 0; i < nums.size(); ++i){
        try{
            curr_digit = nums[i][nums[i].length() - digit - 1];
            real_count[mapping[curr_digit - '0']]++;
        } catch(...){
            real_count[0]++;
        }
    }
    
    for(int i = 1; i < 10; ++i){
        real_count[i] += real_count[i - 1];
    }
    
    for(int i = (int)nums.size() - 1; i >= 0; --i){
        try{
            curr_digit = nums[i][nums[i].length() - digit - 1];
            real_count[mapping[curr_digit - '0']]++;
            output[real_count[mapping[curr_digit - '0']] - 1] = nums[i];
            real_count[mapping[curr_digit - '0']]--;
        } catch(...){
            real_count[0]++;
            output[real_count[0]] = nums[i];
            real_count[0]--;
        }
        
    }
    
    nums = output;
}



int main(int argc, const char * argv[]) {
    
    vector<string> nums = {"019", "204", "080"};
    vector<int> mapping = {2,3,1,4,5,6,9,8,7,0};
    string converted_nums[] = {"", "", ""};
    int i = 0;
    for(string curr_num : nums){
        for(char curr_digit : curr_num){
            converted_nums[i] += (char)(mapping[curr_digit - '0'] + '0');
        }
        ++i;
    }
    
    for(string curr : converted_nums){
        cout << curr << endl;
    }
    
    cout << "Printed those boys" << endl;
    
    int max_len = INT_MAX;
    for(string curr_num : nums){
        if(curr_num.length() > max_len) max_len = (int)curr_num.length();
    }

    for(int i = 0; i < max_len; ++i){
        strange_counting_sort(nums, mapping, i);
    }
    
    for(string curr : nums){
        cout << curr << endl;
    }
    
    
}


