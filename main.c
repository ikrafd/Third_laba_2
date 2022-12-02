#include <stdio.h>
int year, month, date, day, n,  a_y,  a_m, LeapYear;
char er, symbol;
int main() {
    do //Введення року
    {er=0;
        printf("Enter year (from 1922 to 2122) \n");
        scanf("%i%c",&year,&symbol);
        if (symbol!='\n')
        { er=1;
            while ((getchar()) != '\n');
            printf("Enter number without symbol\n");}
        else {if ((year<1922)||(year>2122))
        { er=1;
            while ((getchar()) != '\n');
            printf("Incorrect year\n");}}
        }
     while (er!=0);
    symbol=0;

    do //Введення місяця
    { er=0;
        printf("\nEnter month\n");
        scanf("%i%c",&month,&symbol);
        if (symbol!='\n')
        { er=1;
            while ((getchar()) != '\n');
            printf("Error input number");}
        else {if ((month<1)||(month>12))
            { er=1;
                while ((getchar()) != '\n');
                printf("Month does not exist\n");}}
    } while (er!=0);
    symbol=0;

    //перевірка високосного року
    if (((year%100!=0)&&(year%4==0))||((year%100==0)&&(year%400==0))) {
        LeapYear = 1;
    } else {
        LeapYear = 0;
    }

    do //Введення дня
    { er=0;
        printf("Enter date\n");
        scanf("%i%c",&date,&symbol);
        if (symbol!='\n')
        { er=1;
            while ((getchar()) != '\n');
            printf("Error input number");}
        else {if ((date<1)||(date>31))
            { er=1;
                while ((getchar()) != '\n');
                printf("Date does not exist\n");}}
        if (((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && date > 31) ||
           ((month==4||month==6||month==9||month==11)&& date > 30 )||
           (month == 2 && LeapYear == 1 && date > 29) ||
           (month == 2 && LeapYear == 0 && date > 28))
        {er=1;
            while ((getchar()) != '\n');
            printf("There is no date in the month\n");
        }

    } while (er!=0);
    symbol=0;

    if (month > 2) {
        n = 0;
    } else {
        if (month <= 2) {
            (LeapYear == 1) ? n = 1 : (n = 2);
        }
    }

    a_y=365.25*year;
    a_m=30.56*month;
    day = (a_y+a_m+date+n) % 7;

    switch (day){
        case(0):
            printf("Monday");
            break;
        case(1):
            printf("Tuesday");
            break;
        case(2):
            printf("Wednesday");
            break;
        case(3):
            printf("Thursday ");
            break;
        case(4):
            printf("Friday");
            break;
        case(5):
            printf("Saturday");
            break;
        case(6):
            printf("Sunday");
            break;
        default:
            printf("Incorrect data");
    }

    return 0;
}
