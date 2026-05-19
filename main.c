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
unsigned long long rndom(int m){
    unsigned long long rnd,rndm;
    unsigned long long maximum;
    unsigned long long minimum;
    rndm =(rand()& 0x7FFF);
    rnd =(rndm<<30|rndm<<15|rndm);
    minimum = ((unsigned long long)pow(10, m-1));
    maximum = ((unsigned long long)pow(10, m)- minimum);

    return ((rnd % maximum)+ minimum);
}


int main(void)
{
   setlocale(LC_ALL, "Russian");
   srand(time(NULL));
   unsigned long long x,f;// вводимое угадываемое число
   unsigned long long y,w;// загадываемое число
   unsigned int m, n, p=0, b, c;
   printf("Привет! Сыграем в отгадывание числа?\nИгра называется <<Быки и Коровы>>.\n");
   printf("Я загадаю число, и буду давать подсказки.\n");
   printf("Угаданная цифра в числе - <<бык>>, а если нет, то - <<корова>>.\n");
   printf("Скольки-значное число будем отгадывать?\n");
   do{
       printf("Введите число от 3-х до 10-ти:\n");
       scanf ("%llu", &m);
       if(m<3 || m>10){
          printf("Неверное число!\n");
       }
   }
   while(m<3 || m>10);

    y=rndom(m);


    printf("y= %llu\n",y);

    printf("Отлично! Я загадал %d - значное число.\nПопробуйте отгадать)))\n",m);

    do{


     do{
        printf("Введите ваше %d - значное число:\n",m);
        scanf ("%llu", &x);
        n=order(x);
        if(m!=n){
            printf("Неверное число!\n");

            if (m < n){
             printf("Превышено кол-во цифр!\n");
            }
            else{
            printf("Недостаточное кол-во цифр!\n");
            }
         }
     }
     while(m!=n);

    //printf("Номер %d - значный.\n",n);
    p = p + 1;
    f=x;
    w=y;
    if(x==y){
        printf("Поздравляю! Вы угадали))\n");
        //return 0;
    }
    else{
        c=0;
        b=0;
        for(int i = (m-1); i>=0;){
            unsigned long long e = ((unsigned long long)pow(10, i));
            int a = f/e;
            f = f%e;
            int g = w/e;
            w = w%e;

            printf("%d : %d\n",a,g);

            if(a==g){
                b=b+1;
            }
            else{
                c=c+1;
            }
          i=i-1;
          }
        printf("Вы не угадали.\n");
        printf("У вас быков: %d, и коров: %d \n",b,c);

    }
    }
    while(x!=y);


    printf("Количество попыток: %d \n",p);
    printf("Загаданное мной число: %llu\n",y);
    return 0;
}

