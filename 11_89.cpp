#include <iostream>
#include <assert.h>
#include <cstdint>
#include <string>

using namespace std;

#define CNT_ALPHABET (26)

static const char cBigA = 'A'; 
static const char cBigZ = 'Z'; 

class Vigenere {
    private:
        string str_key;

        char encode_c (char x, char c_key) {
            uint8_t shift = c_key - cBigA;
            if ( x < cBigA ) return x;
            if ( x > cBigZ ) return x;
            x -= cBigA;
            x = (x + shift) % CNT_ALPHABET;
            return x + cBigA;
        };

        char decode_c (char x, char c_key) {
            uint8_t shift = c_key - cBigA;
            if ( x < cBigA ) return x;
            if ( x > cBigZ ) return x;
            x -= cBigA;
            x = (CNT_ALPHABET + x - shift) % CNT_ALPHABET;
            return x + cBigA;
        };

    public:
        void setKey(string key) {
            str_key = key;
        };

        string encode (string text) {
            string ret;
            uint16_t index = 0;
            for (auto x:text) {
                ret += encode_c(x, str_key[index]);
                index = (index + 1) % str_key.size();
            }
            return ret;
        };

        string decode (string text) {
            string ret;
            uint16_t index = 0;
            for (auto x:text) {
                ret += decode_c(x, str_key[index]);
                index = (index + 1) % str_key.size();
            }
            return ret;
        };
};


int main(void)
{
    string test = "ABCDEFGHIJKLMNOPQRSTUVWXYZabc-xyz0-9";
    string key = "ZA";
    Vigenere vigenere;

    vigenere.setKey(key);

    string tmp = vigenere.encode(test);
    cout << tmp << endl;
    cout << vigenere.decode(tmp) << endl;

    return 0;
}