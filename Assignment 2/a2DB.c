#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 42
#define fieldLength 250

struct db_type
{
   char name[fieldLength];

   int age;

   int height;
   float bmi;
   char status[fieldLength];
};

char prompt_menu(void);
void enterNew(struct db_type *pArr[]);
void init_list(struct db_type *pArr[]);
void displayDB(struct db_type *pArr[]);
void sortDB(struct db_type *pArr[]);
void updateRecord(struct db_type *pArr[]);
void removeRecord(struct db_type *pArr[]);
void clearDB(struct db_type *pArr[]);
void modifyStatus(struct db_type *pArr);
void sortByName(struct db_type *pArr[]);
void swap(struct db_type **firstRecord, struct db_type **secondRecord);
void sortByBMI(struct db_type *pArr[]);
void updateArray(struct db_type *pArr[]);

int main(int argc, char *argv[])
{

   struct db_type *db_pArr[SIZE]; /* main db storage */

   init_list(db_pArr); /* set to NULL */

   char choice;
   for (;;)
   {
      choice = prompt_menu();
      switch (choice)
      {
      case 'n':
         enterNew(db_pArr);
         break;
      case 'd':
         displayDB(db_pArr);
         break;

      case 's':
         sortDB(db_pArr);
         break;

      case 'c':
         clearDB(db_pArr);
         break;

      case 'u':
         updateRecord(db_pArr);
         break;
      case 'r':
         removeRecord(db_pArr);
         break;

      case 'q':
         exit(1); /* terminate the whole program */
      }
   }
   return 0;
}

char prompt_menu(void)
{
   char s[80];
   while (1)
   {
      printf("\n-----------------------------------------------------------------\n");
      printf("|    %-20s", "(N)ew record");
      printf("%-20s", "(R)emove record");
      printf("(U)pdate record\t|\n");
      printf("|    %-20s", "(S)ort database");
      printf("%-20s", "(C)lear database");
      printf("(D)isplay database\t|\n");

      printf("|    %-20s", "(Q)uit");
      printf("*Case Insensitive*\t\t\t|\n");
      printf("-----------------------------------------------------------------\n");
      printf("choose one: ");

      fgets(s, 50, stdin); /* \n added */
      if (strlen(s) == 2 && strchr("edlsuqrcwnvpr", tolower(*s)))
         return tolower(*s); /* s[0], return the first character of s */
      printf("not a valid input!\n");
   }
}

void init_list(struct db_type *pArr[])
{
   int t;
   for (t = 0; t < SIZE; t++)
   {
      pArr[t] = NULL;
   }
}

/* delete all the records in the database */
void clearDB(struct db_type *pArr[])
{
   char yn[3];
   printf("are you sure to clear database? (y) or (n)? ");

   fgets(yn, 3, stdin);

   /* complete the function by calling init_list(); */
   if (strchr(yn, 'y'))
      init_list(pArr);
}

/* input items into the database */
/* hint: need malloc */
void enterNew(struct db_type *pArr[SIZE])
{
   printf("Hello\n");
   int i = 0;
   /* Check for the current size of our database */
   while (pArr[i] != NULL)
   {
      i++;
   }

   char name[fieldLength];
   float weight;
   struct db_type *tempDb = malloc(sizeof(tempDb));
   pArr[i] = tempDb;

   /*---------- Get Name -------------*/
   printf("name: ");
   fgets(name, fieldLength, stdin);
   name[strlen(name) - 1] = '\0';
   strcpy(tempDb->name, name);

   /*---------- Get Age -------------*/
   printf("age: ");
   scanf("%d", &tempDb->age);
   getchar();

   /*---------- Get Height -------------*/
   printf("height (cm): ");
   scanf("%d", &tempDb->height);
   getchar();

   /*---------- Get Weight -------------*/
   printf("weight (kg): ");
   scanf("%f", &weight);
   getchar();

   /*---------- Get BMI -------------*/
   tempDb->bmi = weight / ((tempDb->height / 100.0) * (tempDb->height / 100.0));

   /*---------- Get Status -------------*/
   modifyStatus(tempDb);
}

/* remove an existing item from the database */
void removeRecord(struct db_type *pArr[])
{
   /* Some temp local variables to make my code more readable for myself. */
   char errorMessage[20] = "Record not found!\n";
   char name[fieldLength];
   char *newLineRemover;
   int i, arrSize = 0;

   /* Prompt the user for the name for removal. */
   printf("enter full name to remove: ");
   fgets(name, fieldLength, stdin);
   /* Removing the \n from the end of the string 'name' */
   newLineRemover = strchr(name, '\n');
   *newLineRemover = '\0';

   for (i = 0; i < SIZE; i++)
   {
      if (pArr[i] != NULL)
      {
         if (strcmp(pArr[i]->name, name) == 0)
         {
            pArr[i] = NULL; /* Set the whole record to NULL */
            printf("\nThe record [%s] has been removed successfully.\n", name);
            /* Move down all the elements of the array. */
            updateArray(pArr);
            return; /* Exit the current function. */
         }
      }
   }
   /* Display error message if the record did not exit. */
   printf("%s", errorMessage);
}

/* display all the records in the database. Generate output with the same formaing as the sample output
 use \t to align well
*/
void displayDB(struct db_type *pArr[])
{
   int t;
   int counter = 0;
   printf("===============================\n");
   for (t = 0; t < SIZE; t++)
   {
      if (pArr[t]->name != NULL)
      {
         printf("\nname:\t%s\n", pArr[t]->name);
         printf("age:\t%d\n", pArr[t]->age);
         printf("height:\t%d\n", pArr[t]->height);
         printf("BMI:\t%.1f\n", pArr[t]->bmi);
         printf("status:\t%s\n", pArr[t]->status);
         counter++;
      }
   }
   printf("\n======= %d Records ======", counter);
}

/* modify an existing item */
void updateRecord(struct db_type *pArr[])
{
   /* -------- Copied and Pasted a lot of things from removeRecord -------- */

   /* Some temp local variables to make my code more readable for myself. */
   char name[fieldLength];
   char *newLineRemover;
   char errorMessage[25] = "Record not found! :(\n";
   int i;
   float weight;

   printf("Enter full name to search: ");
   fgets(name, fieldLength, stdin);
   /* Removing the \n from the end of the string 'name' */
   newLineRemover = strchr(name, '\n');
   *newLineRemover = '\0';

   for (i = 0; i < SIZE; i++)
   {
      if (pArr[i] != NULL)
      {
         if (strcmp(pArr[i]->name, name) == 0)
         {
            printf("\nRecord found! Enter new weight (kg): ");
            scanf("%f", &weight);
            getchar();
            pArr[i]->bmi = weight / ((pArr[i]->height / 100.0) * (pArr[i]->height / 100.0));

            /* Update the record's status according to their new BMI. */
            modifyStatus(pArr[i]);
            printf("Weight record of [%s] has been updated successfully!\n", name);

            return; /* Exit the current function. */
         }
      }
   }
   /* Display error message if the record did not exit. */
   printf("%s", errorMessage);
}

/* sort the record, either by name or BMI, prompt use for choice */
void sortDB(struct db_type *pArr[])
{
   char choice;
   printf("sort by name (n) or BMI (b)? ");
   scanf("%c", &choice);
   getchar();

   if (choice == 'n')
      sortByName(pArr);
   else if (choice == 'b')
      sortByBMI(pArr);
}

void modifyStatus(struct db_type *pArr)
{

   /*
      When the record's status is empty, the status is updated
      with the BMI status of the person. Otherwise, the status
      is updated and the new status is added next to the older
      status followed by a '->' to indicate what the person's
      status has changed from.
   */

   if (pArr->bmi < 18.5)
   {
      if (strlen(pArr->status) == 0)
         strcpy(pArr->status, "Underweight");
      else
         strcat(pArr->status, " -> Underweight");
   }
   else if (pArr->bmi < 24.999)
   {
      if (strlen(pArr->status) == 0)
         strcpy(pArr->status, "Normal");
      else
         strcat(pArr->status, " -> Normal");
   }
   else if (pArr->bmi < 29.999)
   {
      if (strlen(pArr->status) == 0)
         strcpy(pArr->status, "Overweight");
      else
         strcat(pArr->status, " -> Overweight");
   }
   else if (pArr->bmi < 34.999)
   {
      if (strlen(pArr->status) == 0)
         strcpy(pArr->status, "Obese Class I");
      else
         strcat(pArr->status, " -> Obese Class I");
   }
   else if (pArr->bmi < 39.999)
   {
      if (strlen(pArr->status) == 0)
         strcpy(pArr->status, "Obese Class II");
      else
         strcat(pArr->status, " -> Obese Class II");
   }
   else
   {
      if (strlen(pArr->status) == 0)
         strcpy(pArr->status, "Obese Class III");
      else
         strcat(pArr->status, " -> Obese Class III");
   }
}

void sortByName(struct db_type *pArr[])
{
   int i, j, k;

   for (i = 0; i < SIZE; i++)
   {
      for (j = 0; j < SIZE - 1 - i; j++)
      {
         if (pArr[j + 1])
         {
            if (strcmp(pArr[j]->name, pArr[j + 1]->name) > 0)
            {
               /* An additional indication of what's being swapped with what. */
               printf("Swapped %s with %s\n", pArr[j]->name, pArr[j + 1]->name);
               swap(&pArr[j], &pArr[j + 1]);
               k = 1; /* To indicate that a change has been made. */
            }
         }
      }
   }
   /* Another additional indication for completion */
   if (k == 1)
      printf("Sort Complete! Press 'd' to view the changes.");
   else
      printf("List is already sorted. No changes were made.");
}

void sortByBMI(struct db_type *pArr[])
{
   int i, j, k = 0;

   for (i = 0; i < SIZE; i++)
   {
      for (j = 0; j < SIZE - 1 - i; j++)
      {
         if (pArr[j + 1])
         {
            if (pArr[j]->bmi > pArr[j + 1]->bmi)
            {
               /* An additional indication of what's being swapped with what. */
               printf("Swapped %s with %s\n", pArr[j]->name, pArr[j + 1]->name);
               /* Swap places with each other */
               swap(&pArr[j], &pArr[j + 1]);
               k = 1; /* To indicate that a change has been made. */
            }
         }
      }
   }
   /* Another additional indication for completion */
   if (k == 1)
      printf("Sort Complete! Press 'd' to view the changes.");
   else
      printf("List is already sorted. No changes were made.");
}

/* An helper method to rearrange the array after an item in the array was removed. */
/* This ensures that the sorting methods will do their job properly. */
void updateArray(struct db_type *pArr[])
{
   int i;

   for (i = 0; i < SIZE - 1; i++)
   {
      if (pArr[i] == NULL)
      {
         /* Swap places with each other */
         swap(&pArr[i], &pArr[i + 1]);
      }
   }
}

void swap(struct db_type **firstRecord, struct db_type **secondRecord)
{
   struct db_type *temp = *firstRecord;
   *firstRecord = *secondRecord;
   *secondRecord = temp;
}
