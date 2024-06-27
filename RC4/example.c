#include "arcfour.h"

#define F fflush(stdout)

int main(void);

void printbin(int8 *input,const int16 size){
    int16 i;
    int8 *p;

    assert(size > 0);


    for(i=size, p=input; i; i--,p++){
        if (!((i) % 2)){
            printf(" ");
        }
        printf("%.02x", *p);
        
    }
    printf("\n");
    return;
}

int main(){
    Arcfour *rc4;
    int16 bkey, btext;
    char *key, *from;
    int8 *encrypted, *decrypted;

    
    key = "yomatoes";
    bkey = strlen(key);
    from = "Eh mungu nguvu yetu";
    btext = strlen(from);

    printf("Initializing the encryption");
    rc4 = rc4init((int8 *)key, bkey);
    printf("done\n");

    printf("'%s'\n ->", from);
    encrypted =rc4encrypt(rc4, (int8 *)from, btext);
    printbin((int8 *)encrypted,btext);
    rc4uninit(rc4);


    printf("Initializing the decryption \n");
    rc4 = rc4init((int8 *)key, bkey);
    printf("done\n");

   
    decrypted =rc4decrypt(rc4, (int8 *)encrypted, btext);
    printf("  ->'%s'\n ->", decrypted);
    rc4uninit(rc4);

    return 0;
}