#include <cs50.h>
#include <stdio.h>

//Functions
void print_card_brand(long ccn);
bool check_valid(long card);
int find_length(long n);
bool checksum(long ccn);

int main(void)
{
    long card;
    do
    {
        //prompts user for input
        card = get_long_long("Enter credit card number: ");
    }
    while (card < 0);

    //checks if card is valid
    if (check_valid(card) == true)
    {
        print_card_brand(card);
    }
    else
    {
        printf("INVALID\n");
    }
}

//validity function
bool check_valid(long card)
{
    int len = find_length(card);
    return (len == 13 || len == 15 || len == 16) && checksum(card);
}

//length function
int find_length(long n)
{
    int len;
    for (len = 0; n != 0; n /= 10, len++);
    return len;
}

//Luhn's Algorithm function
bool checksum(long ccn)
{
    int sum = 0;
    for (int i = 0; ccn != 0; i++, ccn /= 10)
    {
        if (i % 2 == 0)
        {
            sum += ccn % 10;
        }
        else
        {
            int digit = 2 * (ccn % 10);
            sum += digit / 10 + digit % 10;
        }
    }
    return (sum % 10) == 0;
}

//Card brand function
void print_card_brand(long ccn)
{
    if ((ccn >= 34e13 && ccn < 35e13) || (ccn >= 37e13 && ccn < 38e13))
    {
        printf("AMEX\n");
    }
    else if (ccn >= 51e14 && ccn < 56e14)
    {
        printf("MASTERCARD\n");
    }
    else if ((ccn >= 4e12 && ccn < 5e12) || (ccn >= 4e15 && ccn < 5e15))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}