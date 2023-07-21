#include <iostream>
#include <vector>
#include <algorithm>

bool ok(int x, std::vector<int>& piles, int h){
    long long totalHours = 0;
    for(auto const& e : piles){
        totalHours += (e + x - 1) / x;
    }
    return totalHours <= h;
}

int minEatingSpeed(std::vector<int>& piles, int h){

    int l = 0, r = *(std::max_element(piles.begin(), piles.end()));

    while(r > l + 1){
        
        int m = l + (r - l)/2;

        if(ok(m, piles, h)){
            r = m;
        }else{
            l = m;
        }
    }

    return r;
}

int main(){

    std::vector<int> pile1 = {3, 6, 7, 11};
    int h1 = 8;

    std::cout << "The minimum bananas-per-hour eating is : " << minEatingSpeed(pile1, h1) << std::endl;

    std::vector<int> pile2 = {30, 11, 23, 4, 11};
    int h2 = 5;

    std::cout << "The minimum bananas-per-hour eating is : " << minEatingSpeed(pile2, h2) << std::endl;

    return 0;
}
