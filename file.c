    #include <stdio.h>
    #include <stdlib.h>

//#define WRITE_TEXT
//#define READ_TEXT
//#define N_STUDENT_DATA_WRITE
//#define STUDENT_DATA_TABLE_WRITE
//#define STRUCT_STUDENT_TABLE
//#define STRUCT_STUDENT_TABLE_READ
//#define STRUCT_STUDENT_WB
#define STRUCT_STUDENT_RB

//int main()
//{

#ifdef WRITE_TEXT

       int num11;
       int num;
       FILE *fptr;
       fptr = fopen("E:\\sample.txt","w");
       if(fptr == NULL)
       {
          printf("Error!");
          exit(1);
       }
       printf("Enter num: ");
       scanf("%d",&num);
       fprintf(fptr,"%d",num);
       fclose(fptr);
#endif // WRITE_TEXT

#ifdef READ_TEXT
        int num;
        FILE *fptr;
        if ((fptr = fopen("E:\\sample.txt","r")) == NULL)
            {
            printf("Error! opening file");
            // Program exits if the file pointer returns NULL.
            exit(1);
            }
        fscanf(fptr,"%d", &num);
        printf("Value of n=%d", num);
        fclose(fptr);
#endif // READ_TEXT

#ifdef N_STUDENT_DATA_WRITE

   char name[50];
   int marks, i, num;
   printf("Enter number of students: ");
   scanf("%d", &num);
   FILE *fptr;
   fptr = (fopen("E:\\student_data.txt", "a"));
   if(fptr == NULL)
        {
       printf("Error!");
       exit(1);
        }
   for(i = 0; i < num; ++i)
      {
      printf("For student%d\nEnter name: ", i+1);
      scanf("%s", name);
      printf("Enter marks: ");
      scanf("%d", &marks);
      fprintf(fptr,"\nName: %s \nMarks=%d \n", name, marks);
      }
    fclose(fptr);
#endif // N_STUDENT_DATA_WRITE

#ifdef STUDENT_DATA_TABLE_WRITE

   char name[50], address[50];
   int age, i, num;
   printf("Enter number of students: ");
   scanf("%d", &num);
   FILE *fptr;
   fptr = (fopen("E:\\student_data_table.txt", "w"));
   if(fptr == NULL)
        {
       printf("Error!");
       exit(1);
        }
   fprintf(fptr,"\n No.  Name     Age       Adress\n", i+1, name, age, address);

   for(i = 0; i < num; ++i)
      {
      printf("For student%d\nEnter name: ", i+1);
      scanf("%s", name);
      printf("Enter age: ");
      scanf("%d", &age);
      printf("For student%d\nEnter address: ", i+1);
      scanf("%s", address);
      fprintf(fptr,"\n %2d  %8s   %d   %15s \n", i+1, name, age, address);
      }

    fclose(fptr);

#endif // STUDENT_DATA_TABLE_WRITE

#ifdef STRUCT_STUDENT_TABLE

struct student
 {
    char name[50];
    int roll;
    float marks;
 } s[10];

int main()
{
    int i, num, num1;
    FILE *fptr;
    printf("Enter number of students: ");
    scanf("%d", &num);

    fptr = (fopen("E:\\struct_student_table.txt", "w"));
    if(fptr == NULL)
        {
       printf("Error!");
       exit(1);
        }
   //fprintf(fptr,"\n ro   Na    ma    \n");

    printf("Enter information of students:\n");

    // storing information
    for(i=0; i<num; ++i)
     {
        s[i].roll = i+1;
        printf("\nroll number:%d\n",s[i].roll);
        printf("Enter name: ");
        fflush(stdin);
        scanf("%s",s[i].name);
        printf("Enter marks: ");
        fflush(stdin);
        scanf("%f",&s[i].marks);
        printf("\n");
        fprintf(fptr,"\n %2d  %8s   %.2f\n", s[i].roll, s[i].name, s[i].marks);
     }
    fclose(fptr);

    // Read & Displaying information


    /*for(i=0; i<num; ++i)
     {
         s[i].roll = 88;
         s[i].marks=44;
     }

    if ((fptr = fopen("E:\\struct_student_table.txt","r")) == NULL)
      {
        printf("Error! opening file");
        // Program exits if the file pointer returns NULL.
        exit(1);
      }

    //fseek(fptr, sizeof(struct student), SEEK_SET);
    printf("Search the Student Data:\n\n");
    printf("Enter student roll number: ");
    scanf("%d", &num1);
    printf("\n roll   Name    marks\n");

    //for(i = 0; i<num; ++i)
    for(i = num1-1; i<num1; ++i)
     {
       fscanf(fptr,"\n %2d  %8s   %.2f\n", &s[i].roll, s[i].name, &s[i].marks);

       printf("\n %2d  %8s   %.2f\n", s[i].roll, s[i].name, s[i].marks);
       //fseek(fptr, -sizeof(struct student), SEEK_CUR);
     }
     fclose(fptr);*/

#endif // STRUCT_STUDENT_TABLE

#ifdef STRUCT_STUDENT_TABLE_READ

struct student
 {
    char name[50];
    int roll;
    float marks;
 } s[10];

int main()
{
    int i, num1, num2;
    FILE *fptr;
    fptr = fopen("E:\\struct_student_table.txt","r");

    if (fptr == NULL)
      {
        printf("Error! opening file");
        // Program exits if the file pointer returns NULL.
        exit(1);
      }

     //fseek(fptr, sizeof(struct student), SEEK_SET);
     //printf("Search the Student Data:\n\n");
     //printf("Enter student roll number - start: ");
     //scanf("%d", &num1);
     //printf("Enter student roll number - End: ");
     //scanf("%d", &num2);

     //if(num1 '%d' )
     //{
      // i = num1;
     //printf("\n roll   Name    marks\n");
     for(i = 0; i<5; ++i)
     //for(i = num1-1; i<num1; ++i)
     {
       fscanf(fptr,"%2d", &s[i].roll);
       fscanf(fptr,"%8s", s[i].name);
       fscanf(fptr,"%f", &s[i].marks);
       printf("\n %2d  %8s   %.2f\n", s[i].roll, s[i].name, s[i].marks);
       //fseek(fptr, -sizeof(struct student), SEEK_CUR);
     }
     /*}else
     {
         printf("you enter the wrong roll number");
     }*/
     fclose(fptr);
#endif // STRUCT_STUDENT_TABLE_READ

#ifdef STRUCT_STUDENT_WB
struct student
 {
    char name[50];
    int roll;
    float marks;
 };

int main()
{
    int i, num1, num2;
    FILE *fptr;
    struct student s[5];
    fptr = fopen("E:\\struct_student_table_bin.txt","wb");

    if (fptr == NULL)
      {
        printf("Error! opening file");
        // Program exits if the file pointer returns NULL.
        exit(1);
      }

      printf(" Enter the student details: \n");
      for(i=0; i<5; ++i)
     {
        s[i].roll = i+1;
        printf("\nroll number:");
        fflush(stdin);
        scanf("%d",&s[i].roll);
        printf("Enter name: ");
        fflush(stdin);
        gets(s[i].name);
        printf("Enter marks: ");
        fflush(stdin);
        scanf("%f",&s[i].marks);
        printf("\n");
        //fprintf(fptr,"\n %2d  %8s   %.2f\n", s[i].roll, s[i].name, s[i].marks);
     }
     fwrite(s,sizeof(struct student),5,fptr);
     printf("\nData store Successfully...\n");
     fclose(fptr);
#endif // STRUCT_STUDENT_WB

#ifdef STRUCT_STUDENT_RB

struct student
 {
    char name[50];
    int roll;
    float marks;
 };

int main()
{
    int i, num1, num2;
    FILE *fptr;
    struct student s[5];
    fptr = fopen("E:\\struct_student_table_bin.txt","rb");

    if (fptr == NULL)
      {
        printf("Error! opening file");
        // Program exits if the file pointer returns NULL.
        exit(1);
      }

    fread(s,sizeof(struct student),5,fptr); // improve to see and read only one data-set of the student.

      printf("Search the Student Data:\n\n");
     printf("Enter student roll number - start: ");
     scanf("%d", &num1);

        printf("\n > Roll number: %d",s[num1].roll);
        printf("\n > Name: %s",s[num1].name);
        printf("\n > Marks: %.2f", s[num1].marks);


     //printf("Enter student roll number - End: ");
     //scanf("%d", &num2);

      printf("student details: \n");
      for(i=0; i<num1; ++i)
     {
        printf("\nRoll number: %d",s[i].roll);
        printf("\nName: %s",s[i].name);
        printf("\nMarks: %.2f", s[i].marks);
       //fprintf(fptr,"\n %2d  %8s   %.2f\n", s[i].roll, s[i].name, s[i].marks);
     }
     printf("\n");

     fclose(fptr);
#endif // STRUCT_STUDENT_RB

return 0;
}
