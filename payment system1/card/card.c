#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Card.h"

/*

-----------------------------------------------required variables of the card-------------------------------------------------

Maximum of Card Holder Name = 24
Minmum of Card Holde rName== 20
the Date of expiry = 5
*/





EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
    int max_name = 24;
    int min_name = 20;
    printf("Please enter the Card Holder's Name: ");

    scanf_s("%[^\n]s", &cardData->Card_Holder_Name, max_name + 1); // scanf_s prevents overflow

    // Check on the Card Holder's Name format
   
    int x = strlen(cardData->Card_Holder_Name);
    if (x < min_name|| max_name < x || (cardData->Card_Holder_Name) == NULL)
        return WRONG_NAME;

    strcpy(ALPHA_2.Card_Holder_Name, cardData->Card_Holder_Name);


    printf("Hello, %s\n", cardData->Card_Holder_Name);

    return Card_OK;
}

EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
    int expdate = 5;
    printf("Please enter the card Expiry Date in the format of MM/YY: ");
    // Using <ctype.h> to check on the Expiry Date format
    scanf_s("%s", &cardData->Card_Expiration_Date, expdate + 1);

    if (strlen(cardData->Card_Expiration_Date) != expdate || (cardData->Card_Expiration_Date) == NULL)
        return WRONG_EXP_DATE;

    if ((cardData->Card_Expiration_Date[2]) != '/')
        return WRONG_EXP_DATE;

    if (!isdigit(cardData->Card_Expiration_Date[0]) || !isdigit(cardData->Card_Expiration_Date[1]))
        return WRONG_EXP_DATE;

    if (!isdigit(cardData->Card_Expiration_Date[3]) || !isdigit(cardData->Card_Expiration_Date[4]))
        return WRONG_EXP_DATE;

    printf("The Expiry Date is: %s\n", cardData->Card_Expiration_Date);

    strcpy(ALPHA_2.Card_Expiration_Date, cardData->Card_Expiration_Date);

    return Card_OK;
}

EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
    int max_pan = 19;
    int min_pan = 16;
    printf("Please enter the Card PAN: ");

    scanf_s("%s", &cardData->Primary_Account_Number, max_pan + 1);
    int z = strlen(cardData->Primary_Account_Number);
    // Check on the Card PAN format
    if (z < min_pan || z>max_pan || (cardData->Primary_Account_Number) == NULL)
    {
        return WRONG_PAN;
    }
    printf("Card PAN number is: %s\n", cardData->Primary_Account_Number);

    strcpy(ALPHA_2.Primary_Account_Number, cardData->Primary_Account_Number);

    return Card_OK;
}