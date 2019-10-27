#include <iostream>
#include <assert.h>
#include <cstdint>
#include <string>

using namespace std;

static const char cBigA = 'A'; 
static const char cBigZ = 'Z'; 

char encode (char x)
{
    if ( x < cBigA ) return x;
    if ( x > cBigZ ) return x;
    x -= cBigA;
    x = (x + 3) % (cBigZ - cBigA + 1);
    return x + cBigA;
}

char decode (char x)
{
    if ( x < cBigA ) return x;
    if ( x > cBigZ ) return x;
    x -= cBigA;
    x = (x + cBigZ - cBigA - 2) % (cBigZ - cBigA + 1);
    return x + cBigA;

}

int main(void)
{
    string test = "ABCDEFGHIJKLMNOPQRSTUVWXYZabc-xyz0-9";

    for(uint8_t idx = 0; idx < test.size(); ++idx){
        test[idx] = encode(test[idx]);
    }

    cout << test << endl;

    for(uint8_t idx = 0; idx < test.size(); ++idx){
        test[idx] = decode(test[idx]);
    }

    cout << test << endl;

    return 0;
}