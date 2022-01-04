#include <string>
#include <iostream>


/**
 * m = len(s), n = len(t)
 * if m >> n: O(m*n)
*/ 
int BF(std::string &s, std::string &t)
{
    int pos = -1;
    int len_s = s.length();
    int len_t = t.length();
    for (int i=0; i < (len_s - len_t + 1); i++){
        int j = 0;
        while (j < len_t && t[j] == s[i+j]){
            j++;
        }
        if (j == len_t){
            pos = i;
            break;
        }
    }
    return pos;
}

int main()
{
    std::string s = "00000123";
    std::string t = "12";
    
    std::cout << "len s: " << s.length() << std::endl;
    std::cout << "len t: " << t.length() << std::endl;
    int pos = BF(s, t);
    std::cout << "pos: " << pos << std::endl;

}