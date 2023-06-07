#include <stdio.h>
#include <stdlib.h>

#define POPCORN 149
#define MOVIE_RATE 399

struct Movie
{
    char name[25];
    int seat, id, popcorn;
    float bill;
} c[50];

void template();
void book_ticket(struct Movie c[], int *n);
void cancel_ticket(struct Movie c[], int *n);
void seat_matrix();

int main()
{
    system("cls");
    template();
    int choice, num = 0;

    do
    {
        system("cls");
        template();
        printf("\nEnter 1 to Book Ticket\n");
        printf("Enter 2 to view seat Map\n");
        printf("Enter 3 to Cancel Ticket\n");
        printf("Enter 4 to exit\n");
        printf("\n\n>>> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            book_ticket(c, &num);
            // num++;
            break;
        case 2:
            seat_map(c, &num);
            break;
        case 3:
            cancel_ticket(c, &num);
            break;
        default:
            printf("\nEnter valid choice\n");
            break;
        case 4:
            printf("\nThanks!!!!\n\n");
        }
        sleep(5);
    } while (choice != 4);

    return 0;
}

void template()
{
    printf("\n||=======================================================================||");
    printf("\n||                                                                       ||");
    printf("\n||                Welcome to Moive Ticket Booking System                 ||");
    printf("\n||                                                                       ||");
    printf("\n||=======================================================================||\n\n");
}

void book_ticket(struct Movie c[], int *n)
{

    seat_matrix();
    printf("\n\nEnter Customber name: ");
    scanf("%s", c[*n].name);

    do
    {
        printf("\nEnter the seat number you want? ");
        scanf("%d", &c[*n].seat);
        if (c[*n].seat > 50)
        {
            printf("\nEnter seat number less than or equal to 50\n");
        }
        for (int i = 0; i < *n; i++)
        {
            if (c[*n].seat == c[i].seat)
            {
                printf("\nSeat already occupied!!!\nTry Another..\n>>> ");
                scanf("%d", &c[*n].seat);
                i--;
            }
        }

    } while (c[*n].seat > 50);

    printf("\nEnter the id number: ");
    scanf("%d", &c[*n].id);
    char choose;
    printf("\nDo You want to add popcorn[y/n]? ");
    scanf(" %c", &choose);
    if (choose == 'y')
    {
        c[*n].popcorn = 1;
    }
    else
    {
        c[*n].popcorn = 0;
    }
    if (c[*n].popcorn == 1)
    {
        printf("\n|--------------------------------------------------------|");
        printf("\n| POpcorn added successfully                             |");
        printf("\n| Movie ticket price = Rs %d                            |", MOVIE_RATE);
        printf("\n| Popcorn = Rs %d                                       |", POPCORN);
        c[*n].bill = POPCORN + MOVIE_RATE;
        printf("\n| Net price (inclusive of all taxes): Rs %.2f          |", c[*n].bill);
        printf("\n|--------------------------------------------------------|\n");
    }
    else
    {
        printf("\n|--------------------------------------------------------|");
        printf("\n| MOvie ticket price = Rs %d                            |", MOVIE_RATE);
        c[*n].bill = MOVIE_RATE;
        printf("\n| Net price (inclusive of all taxes): %.2f             |", c[*n].bill);
        printf("\n|--------------------------------------------------------|\n");
    }
    printf("\n\n-------------------------------------------------------------------------\n");
    printf("-------------------------------------------------------------------------\n");
    *n += 1;
}

void seat_map(struct Movie c[], int *n)
{
    system("cls");
    // template();
    seat_matrix();
    printf("%d", *n);
    if (*n == 0)
    {
        printf("\nEmpty Show(All seat vacant)\n");
    }
    else
    {
        printf("\n\nBooked seat numbers are\n");
        for (int i = 0; i < *n; i++)
        {
            for (int j = i + 1; j < *n; j++)
            {
                if (c[i].seat > c[j].seat)
                {
                    int temp;
                    temp = c[i].seat;
                    c[i].seat = c[j].seat;
                    c[j].seat = temp;
                }
            }
        }

        for (int i = 0; i < 50; i++)
        {
            if (c[i].seat != 0)
            {
                printf("%d\tBOOKED\n", c[i].seat);
            }
        }
    }
}

void cancel_ticket(struct Movie c[], int *n)
{
    system("cls");
    template();
    int seat_no_verify;
    int id_verify;
    int flag = 0;
    int l = *n;
    printf("Enter your seat Number: ");
    scanf("%d", &seat_no_verify);
    printf("Enter Ticket Id: ");
    scanf("%d", &id_verify);
    for (int i = 0; i < l; i++)
    {
        if ((id_verify == c[i].id) && (seat_no_verify == c[i].seat))
        {
            flag = 1;
            printf("\nSeat Matched.....\nId matched\n");
            printf("Do you want to cancel your Ticket for sure['1' for yes '0' for no]? ");
            int sure;
            scanf("%d", &sure);
            if (sure == 1)
            {
                c[i].bill = 0;
                c[i].id = 0;
                c[i].seat = 0;
                printf("\nTicket cancelled successfully\n");
                *n-=1;
            }
            else
            {
                printf("\nTicket not Cancelled\n");
            }
        }
    }
    if (flag == 0)
    {
        printf("\nDetails did not matched\n");
        printf("\nPlease check again.....and enter valid details\n");
    }
}

void seat_matrix()
{
    printf("\n\n\t\t****************SEAT MATRIX****************\n\n");
    int j = 0;
    for (int i = 0; i < 50; i++)
    {
        printf("%d\t", i + 1);
        j++;
        if (j == 10)
        {
            printf("\n");
            j = 0;
        }
    }
    printf("\n\n");
}