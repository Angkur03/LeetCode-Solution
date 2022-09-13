class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int cnt=0;
        for(auto it : data) {
            if(cnt==0) //for 1st 1 byte of data or first number, Eg-1: 197
            {
                //0b used for binary number
                if((it>>5) == 0b110) cnt=1; //check first 3 bit of it is equal to 110
                else if((it>>4) == 0b1110) cnt=2; //check first 4 bit of it is equal to 1110
                else if((it>>3) == 0b11110) cnt=3; //check first 5 bit of it is equal to 11110
                else if((it>>7)) return false;
            }
            
            else //for next bytes of data or remaining number,Eg-2: 130, 1
            {
                if(it>>6 != 0b10) return false; //check n-1 bytes equal to 10 or not
                cnt--;
            }
            
        }
        return cnt==0;
    }
};