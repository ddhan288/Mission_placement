class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        int one = 1;
        int two = 2;
        for (int i = 3; i <= n; i++) {
            int temp = one + two;
            one = two;
            two = temp;
        }
        return two;
    }
};




//
class Solution {
public:
    int climbStairs(int n) {
        unordered_map<int,int> mp;
        return f(0,n,mp);
        }
    int f( int i , int n , unordered_map<int, int> & mp ){
            if ( i>n){
                return 0;
            }
            else if (i == n){
                return 1;
            }
            else{
                if (mp.find(i)!= mp.end()){
                    return mp[i];
                }
                else {
                    int val = f(i+1, n, mp) + f (i+2, n ,mp);
                    mp[i]= val;
                    return val;
                }
            }
        }
    
    
};
