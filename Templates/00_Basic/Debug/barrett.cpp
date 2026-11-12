#include <bits/stdc++.h>

namespace Barrett {
    struct barrett {
        using u64 = uint64_t; 
        using u128 = __uint128_t; 
        u64 mod, im; 
        barrett(u64 p) : mod(p) {im = UINT64_MAX / p;}
        inline u64 reduce(u64 x) const {
            u64 q = (u128)x * im >> 64; 
            u64 r = x - q * mod; 
            if(r >= mod) r -= mod; 
            return r; 
        }
        inline u64 mul(u64 a, u64 b) const {return reduce(a * b);}
    }; 
}

using namespace Barrett; 

int main() {
    
}