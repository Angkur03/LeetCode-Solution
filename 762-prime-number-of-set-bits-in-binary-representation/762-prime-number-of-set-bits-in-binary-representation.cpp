class Solution {
public:
    int numberOfBits(int num){ 
        int count = 0;
        while (num > 0){
            if (num % 2 == 1){
                count +=1;
                num = num/2;
            }
            else{
                num = num/2;
            }
        }
        return count;
    }
    
    bool isPrime(int num){ 
        if (num <=1){ 
            return false;
        }
        int i =2;
        while (i <= (num/2)){
            if (num % i == 0){
                return false;
            }
            i++;
        }
        return true;
    }
    
    int countPrimeSetBits(int L, int R) {
        int res = 0;
        int count;
        for (int i = L; i <= R; i++){
            count = numberOfBits(i);
            if (isPrime(count)){
                res +=1;
            }
        }
        return res;
    }
};