

// 1227. Airplane Seat Assignment Probability...



class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return (n==1)?(double)n:(double)1/2;
    }
};
