#include <stdio.h>

int main(){
    long a1, a2, a, b1, b2, b;
    
    scanf("%li %li %li %li %li %li", &a1, &b1, &a2, &b2, &a, &b);

    if ((a2 >= a && b2 >= b) || (b2 >= a && 
a2 >= b)) { printf("S\n"); return 0;}
    if (a1 >= a){
        if  (b1 >= b)                   { printf("S\n"); return 0;}       
        if  (a2 >= a && (b1 + b2) >= b) { printf("S\n"); return 0;}
        if  (b2 >= a && (b1 + a2) >= b) { printf("S\n"); return 0;}
    }
    if (b1 >= a){
        if  (a1 >= b)                   { printf("S\n"); return 0;}
        if  (a2 >= a && (a1 + b2) >= b) { printf("S\n"); return 0;}
        if  (b2 >= a && (a1 + a2) >= b) { printf("S\n"); return 0;}
    }
    if (a1 >= b){
        if  (a2 >= b && (b1 + b2) >= a) { printf("S\n"); return 0;}
        if  (b2 >= b && (b1 + a2) >= a) { printf("S\n"); return 0;}
    }
    if (b1 >= b){
        if  (a2 >= b && (a1 + b2) >= a) { printf("S\n"); return 0;}  
        if  (b2 >= b && (a1 + a2) >= a) { printf("S\n"); return 0;}        
    }
   
    printf("N\n");

	return 0;
}
