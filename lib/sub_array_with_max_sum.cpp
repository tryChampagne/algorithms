#include "my_functions.h"
#include <vector>
#include <climits>
#include <utility>

//for debugging
#include <ostream>
#include <iostream>

//main magic
namespace MY_FUNCTIONS{

    //logic: subArrayWithMaxSum

    //tested +ve against:
    //  {0,2,3,4},
    //  {-2,-8},
    //  {-2,0},
    //{4,-2,10}

    std::pair<int,int> subArrayWithMaxSum(std::vector<int> &v){
        int max_sum =INT_MIN,curr_max_sum =INT_MIN;
        int idx_l =0,idx_h =0;
        int curr_sum =0;
    
        std::pair<int,int> indexes;
        
        for(int i =0; i<v.size(); i++){
            curr_sum +=v[i];
            if(curr_sum >= curr_max_sum){ //it will give array that might have redundant elements.
                curr_max_sum =curr_sum;
                idx_h =i;
            }
            if(curr_sum < 0){
                if(max_sum < curr_max_sum){
                    indexes.first =idx_l;
                    indexes.second =idx_h;
                    max_sum =curr_max_sum;
                }
                curr_sum =0;
                curr_max_sum =INT_MIN;
                idx_l =idx_h =i+1;
            }

        }
        //don't forget last group contribution
        if(max_sum < curr_max_sum){
            indexes.first =idx_l;
            indexes.second =idx_h;
        }

        //comment below 2 lines ,to prevent printing to console
        std::cout<<"lower_idx: "<<indexes.first<<std::endl;
        std::cout<<"upper_idx: "<<indexes.second<<std::endl;

        return indexes;
    }

}