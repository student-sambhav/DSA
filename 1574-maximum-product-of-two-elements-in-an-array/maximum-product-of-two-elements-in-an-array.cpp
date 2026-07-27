class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int largest=0;
        int secl=0;
        for(int num:nums){
            if(num>largest){
                secl=largest;
                largest=num;
            }
            else{
                secl=max(secl,num);
            }
        }
        return (largest-1)*(secl-1);
    }
};