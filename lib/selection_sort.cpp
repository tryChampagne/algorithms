#include "my_functions.h"
#include <vector>
#include <algorithm>


namespace MY_FUNCTIONS{
    //logic: selection sort

    /*
    test cases:
    */
    
    void selectionSort(std::vector<int> &v){
        int n =v.size();
    
        for(int i =0; i<n-1; i++){
            auto it =min_element(v.begin()+i,v.end());
            int idx =it - v.begin();
            std::swap(v[i],v[idx]);
        }
    }

}
