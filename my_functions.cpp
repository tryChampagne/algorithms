#include "my_functions.h"
#include <vector>
#include <climits>
#include <algorithm>
#include <utility>

//included only for testing purpose can be removed after test phase complete.
#include <iostream>
using namespace std;

//issue:
// mergeSort returning original array without sort,fix it.
//  resolved:
//          problem was while loop in robo.cpp(or calling program) decrementing array size n
//          i.e while(n--)
//          so mergeSort on first call it self satisfying l>=n
//          hence return array without processing further.

//questions: 
//          1.why std::swap() why not just swap()?
//          ans: because swap function is defined in std namespace.

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
        return indexes;
    }

    //logic: selection sort
    /*
    test cases:
        1,0,-4
        1,-4,0
        0,-4,1
        0,1,-4
        -4,1,0
        -4,0,1
    */
    /*all above test cases tested +ve againset mergeSort */
    void selectionSort(std::vector<int> &v){
        int n =v.size();
    
        for(int i =0; i<n-1; i++){
            auto it =min_element(v.begin()+i,v.end());
            int idx =it - v.begin();
            std::swap(v[i],v[idx]);
        }
    }


    //logic: merge sort
    void merge(std::vector<int> &v,int l,int mid,int h){
        int n1 =mid-l+1;
        int n2 =h-mid;
    
        //making space for 2 parts
        std::vector<int> a;
        std::vector<int> b;
    
        //filling above arrays
        for(int i =l; i<=mid; i++)
            a.push_back(v[i]);
    
        for(int i =mid+1; i<=h; i++)
            b.push_back(v[i]);
    
        //supporters
        a.push_back(INT_MAX);
        b.push_back(INT_MAX);
    
        //merging logic
        int n =h-l+1;
        int i =0,j =0;
        int k =l;
        while(n--){
            if(a[i] >= b[j])
                v[k++] =b[j++];
            else
                v[k++] =a[i++];
        }
    
    }
    
    void mergeSort(std::vector<int> &v,int l,int h){
        if(l>=h)
            return;
    
        int mid =(l+h)/2;
    
        //left call
        mergeSort(v,l,mid);
    
        //right call
        mergeSort(v,mid+1,h);
    
        //merge
        merge(v,l,mid,h);
    }
    
}