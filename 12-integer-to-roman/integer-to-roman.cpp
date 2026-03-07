class Solution {
public:
    //M-1000
    //CM-900
    //D-500
    //CD-400
    //C-100
    //XC-90
    //L-50
    //XL-40
    //X-10
    //IX-9
    //V-5
    //IV-4
    //I-1
    string intToRoman(int num) {
        string s="";
        int intCode[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
        string stCode[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        for(int i=0;i<13;i++){
            while(num>=intCode[i]){
                s+=stCode[i];
                num-=intCode[i];

            }
        }
     
        return s;
        
    }
};