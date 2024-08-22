#include <cstdio>


int isbn10_checksum(int const digits[]) {
    int sum = 0;

    for(int i = 0; i < 9; ++i){
        sum += ((i + 1) * digits[i]);
        }
    return (sum % 11);
}

bool parse_isbn10(char const str[], int n, int digits[]) {
    int zahlen = 0; 

    if(n != 13){ // pruft das str 13 chars hat
        return false;
    }

    for(int i = 0; i < n; ++i){ 
        if((str[i] != '-') && (str[i] < '0'|| str[i] > '9') && (str[i] != 'X')){ //pruft ob string ungultiges characteren hat
            return false;
        }
        else if(str[0] == '-' || str[n-1] == '-'){ //pruft ob es mit - faengt oder endet
            return false;
        }
        else if(str[i] == '-' && str[i + 1] == '-'){ //pruft fur doppelte - zeichen
            return false;
        }

        if(str[i] != '-'){
          ++zahlen;
        }
        
    }

    if(zahlen != 10){ // pruft das der string 10 zahlen hat
       return false;
    }

    int index = 0;
    for(int i = 0; i < n; ++i){

        if(str[i] != '-' && index <= 8){
            digits[index] = str[i] - 48;
            ++index;
        }
    }

    return true;
}

bool is_valid_isbn10(char const str[], int n) {
    int digits[9];
    bool valid_format = parse_isbn10(str,n, digits);
    int last_digit = isbn10_checksum(digits);
    bool valid_last_digit = false;

    if(last_digit == 10 && str[n-1] == 'X'){
        valid_last_digit = true; 
    }
    else if (str[n-1] == last_digit + 48){
            valid_last_digit = true;
    }

    return valid_format && valid_last_digit;

}

int main(){
    // einige Testfälle
    int array[] = {1,8,4,3,5,6,0,2,8};
    char array2[] = {"3-342-312-78X"};
    int array3[10];
/*
    printf("%i\n", isbn10_checksum(array));
    printf("%d\n", parse_isbn10(array2, 13, array3));

    for (int i = 0; i <= 8; ++i)
    {
        printf("%i,", array3[i]);
     }
     printf("\n");
*/
    printf("%i\n", is_valid_isbn10("3-642-31278-0", 13)); // sollte "1" ausgeben, da gültige ISBN-10
    printf("%i\n", is_valid_isbn10("99921-58-10-7", 13)); // sollte "1" ausgeben, da gültige ISBN-10
    printf("%i\n", is_valid_isbn10("4--X12-1337-5", 13)); // sollte "0" ausgeben, da keine gültige ISBN-10
    printf("%i\n", is_valid_isbn10("irgendein Unfug", 15)); // sollte "0" ausgeben, da keine gültige ISBN-10
   

    return 0;
}
