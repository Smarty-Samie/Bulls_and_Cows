#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <time.h>

int order(unsigned long long k){//возвращает длину числа
    int z = 0;
    do {
    k = k/10;
    z=z+1;
   }
    while(k>=1);
    return z;
}
unsigned long long rndom(int m){//возвращает случайное число заданной длины
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
   unsigned int m, n, ch=0, p=0, b, c;//быки, коровы, попытки...
   int x_arr[10]={0};
   int y_arr[10]={0};
   int readout =0;// возврат от сканф-а

   char answ[2];
   printf("Привет! Сыграем в отгадывание числа?\nИгра называется <<Быки и Коровы>>.\n");
   printf("Я загадаю число, и буду давать подсказки.\n");
   printf("Угаданная цифра в числе - <<бык>>, угаданная, но не на своем месте- <<корова>>.\n");
   printf("Числа - целые, положительные. Нули слева не воспринимаются.\n");
   printf("\nСкольки-значное число будем отгадывать?\n");
   do{
       printf("Введите число от 3-х до 10-ти: ");
       readout = scanf ("%u", &m);
       printf("\n");
       if(m<3 || m>10 || readout ==0){
          printf("Неверное число!\n");
          while(getchar() != '\n');
       }

   }
   while(m<3 || m>10 || readout ==0);
    readout = 0;
    y=rndom(m);//загадываем число))


    //printf("y= %llu\n",y);//шпаргалка для отладки

    printf("Отлично! Я загадал %d - значное число.\nПопробуйте отгадать)))\n",m);

    do{// основной цикл программы


     do{//цикл ввода числа с проверкой на валидность
        printf("\nВведите ваше %d - значное число: ",m);
        readout = scanf ("%llu", &x);
        printf("\n");
        if(readout!=0){
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
        else{
          printf("Неверные данные!\n");
          n=0;
          while(getchar() != '\n');
        }
     }
     while(m!=n);
     while(getchar() != '\n');//чистим буфер чтения клавы

    //printf("Номер %d - значный.\n",n);
    p = p + 1;
    ch = ch+1;
    f=x;
    w=y;
    if(x==y){
        printf("Поздравляю! Вы угадали))\n");
        //return 0;
    }
    else{
        c=0;
        b=0;
        for(int i = (m-1); i>=0;){//этот цикл разбирает число на циферки и пакует их в массивы.
            unsigned long long e = ((unsigned long long)pow(10, i));
            int a = f/e;
            f = f%e;
            int g = w/e;
            w = w%e;
            x_arr[i]=a;
            y_arr[i]=g;

            //printf("%d : %d\n",a,g);//для отладки. наглядно.

            //if(a==g){
                //b=b+1;
            //}
            //else{
                //c=c+1;
            //}
          i=i-1;
          }
        for(int i =(m-1); i>=0;){//в этом цикле происходит поэлементное сравнение двух массивов.
            for(int j=(m-1); j>=0;){
                if((x_arr[i] == y_arr[j])&&(i==j)){
                    b=b+1;
                }
                else if((x_arr[i] == y_arr[j])&&(i!=j)){
                    c=c+1;
                }
                j=j-1;
            }
            i=i-1;
        }
        printf("Вы не угадали.\n");
        printf("У вас быков: %d, и коров: %d \n",b,c);

        if(ch==3){// спрашиваем не каждый проход))

            do{
                answ[0]='\0';
                //while(getchar() != '\n');
                printf("\nПродолжим? (y/n): ");//если юзеру надоест отгадывать))
                scanf(" %1[yYnN]", answ);
                while(getchar() != '\n');
            }
            while (answ[0] !='y' && answ[0] !='Y' && answ[0] !='n' && answ[0]!='N');

            //printf("answ=%c\n",answ[0]);


            if(answ[0] =='n'||answ[0] =='N'){
                printf("\nИгра завершена.\n");
                break;
            }
            ch = 0;
          }

    }
    }
    while(x!=y);


    printf("Количество попыток: %d \n",p);
    printf("Загаданное мной число: %llu\n",y);
    printf("Для выхода нажмите Enter. \n");
    //getchar();
    getchar();//это чтоб экзешник не захлопнулся сразу
    return 0;
}

