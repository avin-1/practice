#include <iostream>
using namespace std;
// I have to implement recursive multiply
// recursive multiply is without * operator 
// so for example 5*3 so i just have to add 5 3 times right 
// cool
int helper(int n,int m,int i,int result){
    // so if i == m then we got the result then return it 
    result = result+n;
    i++;
    if(m==i){
        return result;
    }
    return helper(n,m,i,result);
}

int recursiveMultiply(int n,int m){
    int result = 0;
    int i = 0;
    return helper(n,m,i,result);
}


int main(){
    cout<<recursiveMultiply(5,3);
    return 0;
}