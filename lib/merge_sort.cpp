#include "my_functions.h"
#include <vector>
#include <climits>

namespace MY_FUNCTIONS{

   //logic: merge sort
    
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
   