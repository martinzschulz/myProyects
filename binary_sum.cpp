#include <iostream>

using namespace std;
void bin_sum(int int_a, int int_b, int length, int c[]);
int bin_to_dec(const int c[], int length);
int* int_to_arr(int a, int length);
int size(int a, int b);
int power_of_size(int length);


int main(){
    int a = 11110001;
    int b = 110000;

    int length = size(a,b);
    int c[length + 1]; //create array to save the sum 

    bin_sum(a, b, length, c);

//print out sum of two binary digits
    for(int i = 0; i <= length; ++i){
        cout << c[i];
    }
    cout << endl;
//print out the value in decimal
    cout << bin_to_dec(c, length) << endl;

}

//calculate how many digits the integer has and return bigger number of integers
int size(int a, int b){
    int size_a = 0; 
    int size_b = 0;

//count the digits by dividing multilpe times by 10
    while (a > 0) {
        a /= 10;
        ++size_a;
    }

  while (b > 0) {
        b /= 10;
        ++size_b;
    }

    return (size_a > size_b) ? size_a : size_b;
}

int power_of_size(int size){
    int power10 = 1;
    for(int i =1; i <= size; ++i){
        power10 *= 10;
    }
    return power10;
}

int* int_to_arr(int a, int size){


    int* arr = new int[size]();
    int count = size - 1;

    for(int i = 10; i <= power_of_size(size);i = i*10){
        if( a % i == 0){
            arr[count] = 0; 
        }

        else{
            arr[count] = 1;
            a = a - (i/10);
        }
        --count;
    }
    return arr;
}

void bin_sum(int int_a, int int_b, int length, int c[]){

    int* a = int_to_arr(int_a, length);
    int* b = int_to_arr(int_b, length);
    int rest = 0;
  

    for(int i = length - 1; i >= 0; --i){
        if(a[i] + b[i] + rest < 2){ //if sum is 1 or 0 
            c[i + 1] = a[i] + b[i] + rest; //save sum
            rest = 0;
        }
        else if(a[i] + b[i] + rest == 3){
            c[i + 1] = 1;
            rest = 1;

        }
        else{
            c[i + 1] = 0; 
            rest = 1;
        }
    }
    c[0] = rest; //save the last element 


}
int bin_to_dec(const int c[], int size){
    int sum = 0;
    int power_two = 1;

    for(int i = size; i >= 0 ; --i){
        
        sum = (c[i] * power_two) + sum;
        power_two *= 2;
    }
    return sum;
}