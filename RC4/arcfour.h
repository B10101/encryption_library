#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#define _GNU_SOURCEclear

#define export __attribute__((visibility("default")))
#define rc4decrypt(x,y,z)  rc4encrypt(x,y,z)
#define rc4uninit(x) free(x)
#define rc4whitewash(x,y) for(x=0; x<(MS*1000000);x++)\
                    (volatile int8)rc4byte(y);
#define MS  500

typedef struct b_arcfour Arcfour;
typedef unsigned char int8;
typedef unsigned short int int16;
typedef unsigned int int32;

struct b_arcfour{
    int16 i,j,k;
    int8 s[256];
};



export Arcfour *rc4init(int8*,int16);
int8 rc4byte(Arcfour*);
export int8 *rc4encrypt(Arcfour* ,int8*, int16);
