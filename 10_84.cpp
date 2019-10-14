#include <iostream>
#include <string_view>
#include <array>
#include <algorithm>
#include <numeric>
#include <bitset>
#include <assert.h>
#include <cstdint>

#include "pngwriter.h"

using namespace std;

#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))

/* 
 * バーコードについて
 * http://www5d.biglobe.ne.jp/~bar/spec/barspec.html 
 * 
 */

#define EAN_13_HEAD (0)
#define EAN_13_GUARD_1 (1)
#define EAN_13_LEFT_HEAD (2)
#define EAN_13_LEFT_TAIL (7)
#define EAN_13_GUARD_CENTER (8)
#define EAN_13_RIGHT_THEAD (9)
#define EAN_13_RIGHT_TAIL (14)  /* 終端はチェックデジット */
#define EAN_13_GUARD_2 (15)
#define EAN_13_MAX (16)

/* ガードバー */
#define GUARD_BAR (0b101)

/* センターバー */
#define CENTER_BAR (0b01010)

/* margin */
#define MARGIN (10)

struct Eag13_t {
    uint8_t body[EAN_13_MAX];
} ;

/* 文字コード表 */
enum PARITY_TYPE
{
    PARITY_TYPE_LEFT_ODD,   /**< 左側の奇数PARITY */
    PARITY_TYPE_LEFT_EVEN,  /**< 左側の偶数PARITY */
    PARITY_TYPE_RIGHT,      /**< 右側 */
    PARITY_TYPE_MAX
};


/* 文字コード表 */
static const uint8_t encodings[10][PARITY_TYPE_MAX] =
{
    { 0b0001101, 0b0100111, 0b1110010 },    // 0
    { 0b0011001, 0b0110011, 0b1100110 },    // 1
    { 0b0010011, 0b0011011, 0b1101100 },    // 2
    { 0b0111101, 0b0100001, 0b1000010 },    // 3
    { 0b0100011, 0b0011101, 0b1011100 },    // 4
    { 0b0110001, 0b0111001, 0b1001110 },    // 5
    { 0b0101111, 0b0000101, 0b1010000 },    // 6
    { 0b0111011, 0b0010001, 0b1000100 },    // 7
    { 0b0110111, 0b0001001, 0b1001000 },    // 8
    { 0b0001011, 0b0010111, 0b1110100 },    // 9
};

/*
 * 先頭の値に対するPARITYの適応表
 */
static const PARITY_TYPE eandigits[10][6] =
{
    {   /* 0 */
        PARITY_TYPE_LEFT_ODD,
        PARITY_TYPE_LEFT_ODD,
        PARITY_TYPE_LEFT_ODD,
        PARITY_TYPE_LEFT_ODD,
        PARITY_TYPE_LEFT_ODD,
        PARITY_TYPE_LEFT_ODD 
    },
    {   /* 1 */
        PARITY_TYPE_LEFT_ODD,
        PARITY_TYPE_LEFT_ODD,
        PARITY_TYPE_LEFT_EVEN,
        PARITY_TYPE_LEFT_ODD,
        PARITY_TYPE_LEFT_EVEN,
        PARITY_TYPE_LEFT_EVEN 
    },
    {   /* 2 */
        PARITY_TYPE_LEFT_ODD,
        PARITY_TYPE_LEFT_ODD,
        PARITY_TYPE_LEFT_EVEN,
        PARITY_TYPE_LEFT_EVEN,
        PARITY_TYPE_LEFT_ODD,
        PARITY_TYPE_LEFT_EVEN
    },
    {   /* 3 */
        PARITY_TYPE_LEFT_ODD,
        PARITY_TYPE_LEFT_ODD,
        PARITY_TYPE_LEFT_EVEN,
        PARITY_TYPE_LEFT_EVEN,
        PARITY_TYPE_LEFT_EVEN,
        PARITY_TYPE_LEFT_ODD
    },
    {   /* 4 */
        PARITY_TYPE_LEFT_ODD,
        PARITY_TYPE_LEFT_EVEN,
        PARITY_TYPE_LEFT_ODD,
        PARITY_TYPE_LEFT_ODD,
        PARITY_TYPE_LEFT_EVEN,
        PARITY_TYPE_LEFT_EVEN 
    },
    {   /* 5 */
        PARITY_TYPE_LEFT_ODD,
        PARITY_TYPE_LEFT_EVEN,
        PARITY_TYPE_LEFT_EVEN,
        PARITY_TYPE_LEFT_ODD,
        PARITY_TYPE_LEFT_ODD,
        PARITY_TYPE_LEFT_EVEN 
    },
    {   /* 6 */
        PARITY_TYPE_LEFT_ODD,
        PARITY_TYPE_LEFT_EVEN,
        PARITY_TYPE_LEFT_EVEN,
        PARITY_TYPE_LEFT_EVEN,
        PARITY_TYPE_LEFT_ODD,
        PARITY_TYPE_LEFT_ODD
    },
    {   /* 7 */
        PARITY_TYPE_LEFT_ODD,
        PARITY_TYPE_LEFT_EVEN,
        PARITY_TYPE_LEFT_ODD,
        PARITY_TYPE_LEFT_EVEN,
        PARITY_TYPE_LEFT_ODD,
        PARITY_TYPE_LEFT_EVEN
    },
    {   /* 8 */
        PARITY_TYPE_LEFT_ODD,
        PARITY_TYPE_LEFT_EVEN,
        PARITY_TYPE_LEFT_ODD,
        PARITY_TYPE_LEFT_EVEN,
        PARITY_TYPE_LEFT_EVEN,
        PARITY_TYPE_LEFT_ODD
    },
    {   /* 9 */
        PARITY_TYPE_LEFT_ODD,
        PARITY_TYPE_LEFT_EVEN,
        PARITY_TYPE_LEFT_EVEN,
        PARITY_TYPE_LEFT_ODD,
        PARITY_TYPE_LEFT_EVEN,
        PARITY_TYPE_LEFT_ODD
    },
};

uint8_t getCheckDigit(const uint8_t *orignNum)
{
    uint8_t tmp_even = 0;
    uint8_t tmp_odd = 0;
    
    /* 偶数桁のデータを足し上げ */
    for (uint8_t idx = 1; idx < 12; idx += 2)
            tmp_even += orignNum[idx];
    
    tmp_even *= 3;

    /* 奇数桁のデータを足し上げ */
    for (uint8_t idx = 0; idx < 12; idx += 2)
            tmp_odd += orignNum[idx];
    

    return 10 - ((tmp_even + tmp_odd) % 10);
};

void getEag13Data(const uint8_t *orignNum, Eag13_t *eag)
{
    assert(ARRAY_LENGTH(orignNum) != 12);

    uint8_t eagCnt = 0;

    eag->body[eagCnt] = encodings[orignNum[0]][eandigits[orignNum[0]][0]];
    eagCnt++;
    eag->body[eagCnt] = GUARD_BAR;
    eagCnt++;

    for (uint8_t idx = 1; idx < 6; idx++) {
        eag->body[eagCnt] = encodings[orignNum[idx]][eandigits[orignNum[0]][idx]];
        eagCnt++;
    }

    eag->body[eagCnt] = CENTER_BAR;
    eagCnt++;

    for (uint8_t idx = 6; idx < 12; idx++) {
        eag->body[eagCnt] = encodings[orignNum[idx]][PARITY_TYPE_RIGHT];
        eagCnt++;
    }

    eag->body[eagCnt] = encodings[getCheckDigit(orignNum)][PARITY_TYPE_RIGHT];
    eagCnt++;

    eag->body[eagCnt] = GUARD_BAR;
    eagCnt++;

}

/* 丸コピー */
int draw_digit(
    unsigned char code, unsigned int size,
    pngwriter& image,
    int const x, int const y,
    int const digit_width, int const height)
{
    std::bitset<7> bits(code);
    int pos = x;
    for (int i = size - 1; i >= 0; --i)
    {
        if (bits[i])
        {
        image.filledsquare(pos, y, pos + digit_width, y + height, 0, 0, 0);
        }

        pos += digit_width;
    }

    return pos;
}

int main(void)
{
    uint8_t orignNum[12] = { 1,2,3,4,5,6,7,8,9,0,1,2};
    Eag13_t eag;
    string_view filename = "test.png";
    int x = MARGIN;

    getEag13Data(orignNum, &eag);
    pngwriter image(
         MARGIN * 2 + 95 * 3,
         50 + MARGIN * 2,
         65535,
         filename.data());

    for (uint8_t idx = 0; idx < EAN_13_MAX; idx++)
    {
        cout << std::bitset<8>(eag.body[idx]) << endl;
        swich () {
            case EAN_13_GUARD_1:
            case EAN_13_GUARD_2:
                x = draw_digit(eag.body[idx], 3, image, x, MARGIN, 3, 50);
                break;
            case EAN_13_GUARD_CENTER:
                x = draw_digit(eag.body[idx],5, image, x, MARGIN, 3, 50);
                break;
            default:
                x = draw_digit(eag.body[idx],6, image, x, MARGIN, 3, 50);
                break;
        };
    }
    image.close();

    return 0;
}