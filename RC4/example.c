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
    //Arcfour *rc4;
    int16 bkey, btext;
    char *key, *from, *encrypted, *decrypted; 

    key = from = encrypted = decrypted = 0;
    from = key;
    bkey = btext = 0;

    key = "yomatoes";
    bkey = strlen(key);
    from = "Eh mungu nguvu yetu";
    btext = strlen(from);

    printf("Initializing the encryption");
    //rc4 = rc4init(key, bkey);
    printf("done\n");

    printf("'%s'\n ->", from);
    //encrypted =rc4encrypt(from, btext);
    printbin((int8 *)key,bkey);

    return 0;
}