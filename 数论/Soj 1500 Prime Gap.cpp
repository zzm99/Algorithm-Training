#include <iostream>  
using namespace std;  
 
bool isPrime( int num ){
    for( int i = 2; i * i <= num; ++i ){
        if( num % i == 0 ) return false;    
    }  
    return true;  
}
 
int main () {
    int num,before,after;
    while( cin >> num && num != 0 ){
        if( isPrime(num) ){
            cout << 0 << endl;
        }else{
            for( int i = num + 1; ; ++i ){
                if( isPrime(i) ){
                    after = i;  
                    break;
                }     
            }    
            for( int i = num - 1; ; --i ){
                if( isPrime(i) ){
                    before = i;  
                    break;
                }   
            }    
            cout << after - before << endl;
        }              
    }    
 
    return 0;  
}  