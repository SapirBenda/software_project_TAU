#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool checkbase(int a);
bool checkinput(char c, int base);
void convert_D_to_new_base(int word, int newbase);
void convert_rec(int word, int newbase, int m);


int main(){

    int oldbase;
    printf("Please enter the numbers base: ");
    scanf("%d", &oldbase);
   
    if(checkbase(oldbase)){
        int desiredbase;
        printf("Please enter the desired base: ");
        scanf("%d", &desiredbase);
        
        if(checkbase(desiredbase)){
            char ch;
            int full_word = 0;
            printf("Please enter a number in base %d :", oldbase);
            getchar();
            while((ch = getchar()) != 10){
                if (!checkinput(ch,oldbase)){ // ch isn't a valid input
                    printf("Invalid number!\n");
                    break;
                }else{ // compute word
                    full_word = full_word*oldbase +ch-48;
                }
            } 
            printf("The result is: ");
            convert_D_to_new_base(full_word,desiredbase);
        }else{
            printf("Invalid input base\n"); }
    }else{
        printf("Invalid input base\n"); } 
}

/*
 * cheks if the base is valid 
 * returns 1 iff a is valid base
 */ 
bool checkbase(int a){
    return (a<2 || a>16) ? false :true;
}
/*
 * checks if the char c is from base 'base' 
 * returns 1 iff c is valid number in base
 */
bool checkinput(char c, int base){
    int digit = c - 48;
    return (c == '\n' || digit < 0 || digit > base ) ? false : true;
}

/*
*convert word from base 10 to new base
*/
void convert_D_to_new_base(int word, int newbase){
    if (newbase == 10){
        printf("%d",word);
    }else{
    int m =0;
    convert_rec(word,newbase,m);
    }
}

/*
* a recusive function, prints the word in base newbase
*/
void convert_rec(int word, int newbase, int m){
    if(word == 0){
        return;
    }
    m = word % newbase;
    word = (int) floor(word/newbase);
    convert_rec(word,newbase,m);
    if(m >= 10){
        m = m+55;
        printf("%c",m);
    }
    else{
        printf("%d",m);
    }   
}
