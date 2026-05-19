#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>

int order(unsigned long long k){
    int z = 0;
    do {
    k = k/10;
    z=z+1;
   }
    while(k>=1);
    return z;
}

int main(void)
{
   setlocale(LC_ALL, "Russian");
   srand(time(NULL));
   unsigned long long x;// вводимое угадываемое число
   unsigned long long y;// загадываемое число
   unsigned long long rnd;
   unsigned long long maximum;
   unsigned long long minimum;

   unsigned int m,lh=0,rh=0;
   printf("Привет! Сыграем в отгадывание числа?\nИгра называется Быки и Коровы.\n");
   do{
       printf("Введите число от 3-х до 10-ти:\n");
       scanf ("%llu", &m);
       if(m<3 || m>10){
          printf("Неверное число!\n");
       }
   }
   while(m<3 || m>10);

    rnd =(rand()<<30|rand()<<15|rand());
    maximum = ((unsigned long long)pow(10, m)-((unsigned long long)pow(10, m-1)));
    minimum = ((unsigned long long)pow(10, m-1));
    y =(rnd % maximum)+ minimum;
    //printf("y= %llu\n",y);
    //printf("max= %llu\n",maximum);
    //printf("min= %llu\n",minimum);

    printf("Отлично! Я загадал %d - значное число.\nПопробуйте отгадать)))\n",m);
    printf("Введите ваше %d - значное число:\n",m);
    scanf ("%llu", &x);
    return 0;
}

