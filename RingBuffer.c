#include <stdio.h>
#include <stdlib.h>
// moving average filter
//const int rb_n = 5;   //FİLTRE ELEMAN SAYISI


#define rb_n 5

int rb_i = 0;
float rb_data[rb_n];   
float tempOflm35;

float rb_get_element(int j)
{   
	int t = rb_i + j; 
	if(t > rb_n-1){   
	  t = t - rb_n ;  
	}
	return rb_data[t];   
}

float rb_put_element(float v)
{  
	float r = rb_get_element( rb_n - 1 );                  
	rb_i = rb_i - 1 ; 
	if( rb_i < 0){
	rb_i = rb_n-1;
	} 
	rb_data[rb_i] = v;
	return r;
}

float mean = 0;  

float calc_mean(float input)
{
	float v0;  
	float vout; 
	v0 = input;   
	vout  = rb_put_element(v0);  
	mean = mean  + v0/rb_n  - vout/rb_n;   
    return mean;
}

float arrayTemp[] = {10, 20 ,30, 40, 50, 60 ,70, 80 ,90 ,100};

float filteredTemp;
float temp;
int main()
{

    for(int i = 0; i < 10; i++)
    {
     temp = arrayTemp[i];
     filteredTemp = calc_mean(temp);   
    }
    
    printf("mean : %0.2f", filteredTemp);
    return 0;
}
