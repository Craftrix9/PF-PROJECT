/*

  Muhammad Jahanzeb Arfan 24P-3079
  Muhammad Moaz Umar      24P-3087
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void cal_average(float [],int);
void high_low(float [],int);
void pass_fail(float [],int);
void ascending_order(float [],int);
void grade_std(float [],int);
void update_grade(float [][3],float[],int);
void curve(float [][3],float [] ,int);
void subject_pass_fail(float [][3], int);
void generate_report_cards(float [][3],float [],int);
void topper_in_subject(float [][3], int);

int main()
{

   int choice;
   char password[50];
   printf("\n\t\t\t\t Welcome to Student Grade Management System \t\t\t\t\n");
   printf("\n1 : SIGNUP \t\t\t 2 : LOGIN \t\t\t 0 : exit\t\t\n");
   scanf("%d",&choice);


   while(choice==1)
    {
      FILE *outFile = NULL;
      outFile=fopen("Password.txt", "a");
      if (outFile == NULL)
        {
            printf("Failed to create file.\n");
            exit(1);
        }
       printf("\t\t\n ENTER THE PASSWORD : \t\t\n");
       scanf("%s", password);
       fprintf(outFile,"%s\n",password);
       fclose(outFile);
       printf("\n1 : SIGNUP \t\t\t 2 : LOGIN \t\t\t 0 : exit\t\t\n");
       scanf("%d",&choice);
    }
    char line[50];
    int found = 0;
    if(choice==2)
    {
      do
      {
         printf("\n\t\t Enter Password: \t\t\n");
         scanf("%s", password);
         FILE *inFile =NULL;
         inFile= fopen("Password.txt", "r");
         if (inFile == NULL)
         {
            printf("\n\t\t Failed to open file for reading. \t\t\n");
            exit(1);
         }

         while (fgets(line, sizeof(line), inFile))
         {
            line[strcspn(line, "\n")] = '\0';

            if (strcmp(password, line) == 0)
            {
               printf("\n\t\t Password is correct.\t\t\n");
               printf("\n\t\t LOGIN SUCCESSFUL.\t\t\n");
               found = 1;
               break;
            }
         }
         if (found==0)
         {
             printf("\n\t\t Password is incorrect.\t\t\n");
         }
        fclose(inFile);
      } while (found==0);
    }

    if(choice==0)
    {
      exit(0);
    }

   int std;
   printf("\n\t\t Enter the number of students up to 50 : \t\t\n");
   scanf("%d",&std);
   while(std>50)
   {
    printf("\n\t\t ERROR \t\t\n\n\t\t Enter the valid number of students up to 50 : \t\t\n");
    scanf("%d",&std);
   }

   float std_sub_grade[std][3];
   for(int i=0;i<std;i++)
   {
       printf("\n\n\t\t STUDENT %d \t\t\n\n",i+1);
       for(int j=0;j<3;j++)
       {
          switch (j)
         {
          case 0:
            {
              printf("\n\t\t Enter the %d student's PF grade : \t\t\n",i+1);
              scanf("%f",&std_sub_grade[i][j]);
                while(std_sub_grade[i][j]>100  ||  std_sub_grade[i][j]<0)
                 {
                    printf("\n\t\t ERROR \t\t\n\n\t\t Re-enter the %d student's PF grade : \t\t\n",i+1);
                    scanf("%f",&std_sub_grade[i][j]);
                 }
              break;
            }
            case 1:
            {
              printf("\n\t\t Enter the %d student's ICT grade : \t\t\n",i+1);
              scanf("%f",&std_sub_grade[i][j]);
                while(std_sub_grade[i][j]>100  ||  std_sub_grade[i][j]<0)
                 {
                    printf("\n\t\t ERROR \t\t\n\n\t\t Re-enter the %d student's ICT grade : \t\t\n",i+1);
                    scanf("%f",&std_sub_grade[i][j]);
                 }
              break;
            }
            case 2:
            {
              printf("\n\t\t Enter the %d student's CALCULUS grade : \t\t\n",i+1);
              scanf("%f",&std_sub_grade[i][j]);
                while(std_sub_grade[i][j]>100  ||  std_sub_grade[i][j]<0)
                 {
                    printf("\n\t\t ERROR \t\t\n\n\t\t Re-enter the %d student's calculus grade : \t\t\n",i+1);
                    scanf("%f",&std_sub_grade[i][j]);
                 }
              break;
            }
         }
       }
   }

   float std_grade[std];
   for(int i=0;i<std;i++)
   {
       std_grade[i]= ((std_sub_grade[i][0] + std_sub_grade[i][1] + std_sub_grade[i][2])/300.0)*100.0;
   }
   int menu_opt;
do
{

printf("\n1: Calculate and display the average grade of the class.\n");
printf("2: Find and display the highest and lowest grades.\n");
printf("3: Count and display the number of students who passed (grade >= 50) and failed (grade < 50).\n");
printf("4: Sort and display all the grades in ascending order.\n");
printf("5: Search for a particular grade and display how many students received it.\n");
printf("6: Update a student’s grade.\n");
printf("7: Do a curve.\n");
printf("8: Show how many subjects each student passed and failed.\n");
printf("9: Generate Report Cards for Students.\n");
printf("10: Find the topper in each subject.\n");
printf("11: Exit the program.\n");
scanf("%d",&menu_opt);
while(menu_opt<0 || menu_opt>11)
{
    printf("\t\t\n ERROR \t\t\n\n\t\t Enter valid number : \t\t\n");
    scanf("%d",&menu_opt);
}
switch (menu_opt)
{
case 1:
{
   cal_average(std_grade,std);
   break;
}
case 2:
{
   high_low(std_grade,std);
   break;
}
case 3:
{
   pass_fail(std_grade,std);
   break;
}
case 4:
{
   ascending_order(std_grade,std);
   break;
}
case 5:
{
   grade_std(std_grade,std);
   break;
}
case 6:
{
   update_grade(std_sub_grade,std_grade,std);
   break;
}
case 7:
{
   curve(std_sub_grade,std_grade,std);
   break;
}
 case 8:
{
    subject_pass_fail(std_sub_grade, std);
    break;
}
 case 9:
 {
     generate_report_cards(std_sub_grade,std_grade,std);
     break;
 }
case 10:
 {
      topper_in_subject(std_sub_grade, std);
      break;
 }
case 11:
   {
       exit(0);
   }

}

}
while(menu_opt!=11);



 return 0;
}


void cal_average(float grade[],int std)
{
   float sum =0;
     for(int i =0;i<std;i++)
     {
             sum = sum + grade[i];
     }
    float  average_grade = sum / std;
    printf("\n\t\t Average grade of class  : %.2f \t\t\n",average_grade);
}

void high_low(float grade[],int std)
{
    float high=grade[0];float low = grade[0];
    for(int i=1;i<std;i++)
    {
        if(high<grade[i])
        {
            high = grade[i];
        }
        if (low>grade[i])
        {
            low=grade[i];
        }

    }
    printf("\n\t\t Highest grade  : %.2f \t\t\n",high);
    printf("\n\t\t Lowest grade  : %.2f \t\t\n",low);
}

void pass_fail(float grade[],int std)
{
   int pass=0;int fail=0;
   for(int i =0 ;i<std;i++)
   {
      if(grade[i]>=50)
      pass++;
      else
      fail++;
   }
   printf("\n\t\t Students passed are or have grade >= 50 : %d \t\t\n",pass);
   printf("\n\t\t Students failed are or have grade < 50 : %d \t\t\n",fail);
}

void ascending_order(float grade[],int std)
{
   float arr[std];int k=1;
   for(int i =0;i<std;i++)
   {

       arr[i]=grade[i];
   }

    for (int i = 0; i < std - 1; i++)
        {
        for (int j = 0; j < std - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                }
        }
        }

   printf("\n\t\t Grades in ascendig order are : \t\t\n");
   for(int i =0 ;i<std;i++)
   {
      printf("\n\t\t%.2f\t\t\n",arr[i]);
   }
   printf("\n\n\t\toriginal grades are : \t\t\n\n");
    for(int i =0 ;i<std;i++)
   {
      printf("\n\t\t%.2f\t\t\n",grade[i]);
   }
}

void grade_std(float grade[],int std)
{
  float grad ; int count =0;
 printf("\n\t\t Enter the grade : \t\t\n");
 scanf("%f",&grad);
 for (int i = 0; i < std; i++)
 {
   if(grade[i]==grad)
   count++;
 }
 printf("\n\t\t %d students received %f grade \t\t\n",count,grad);

}

void update_grade(float grades[][3],float ful_grade[],int std)
{
   int stud;int st_num;float grde;int subject;
   printf("\n\t\t Enter the number of students whose grade has to be update : \t\t\n");
   scanf("%d",&stud);
   for (int i = 0; i < stud; i++)
   {
         printf("\n\t\t Enter the student no whose grade is to be update : \t\t\n");
         scanf("%d",&st_num);
       while (st_num>std)
       {
           printf("\n\t\t ERROR. \t\t\n\n\t\t Enter the student no whose grade is to be update : \t\t\n");
           scanf("%d",&st_num);
       }
         printf("\n\t\t Enter the subject \t\t\n");
         printf("\n\t\t 1:PF \t\t\n");
         printf("\n\t\t 2:ICT \t\t\n");
         printf("\n\t\t 3:CALCULUS \t\t\n");
         scanf("%d",&subject);

         printf("\n\t\t Enter the new grade : \t\t\n");
         scanf("%f",&grde);
       while (grde>=100)
       {
           printf("\n\t\t ERROR. \t\t\n\n\t\t Enter the new grade : \t\t\n");
         scanf("%f",&grde);
       }
      grades[st_num-1][subject-1]=grde;

   }
   for(int i=0;i<std;i++)
   {
       ful_grade[i]= ((grades[i][0] + grades[i][1] + grades[i][2])/300.0)*100.0;
   }

}
void curve(float grades[][3], float ful_grade[],int std)
{
   int choice;
   printf("\n\t\t 1:For Whole Grade. \t\t\n\n\t\t 2:For particular subjects. \t\t\n");
   scanf("%d",&choice);
   float crv;
   if(choice==1)
   {
       printf("\n\t\t Enter the number of curve: \t\t\n");
       scanf("%f",&crv);
       for(int i =0; i<std;i++)
       {
           if(crv<=100-ful_grade[i])
           {
               ful_grade[i]=ful_grade[i]+crv;
           }
           else
           {
               ful_grade[i]=100;
           }
       }
   }

   if(choice==2)
   {
       int choice2;
       printf("\n\t\t 1:For PF \t\t\n");
       printf("\n\t\t 2:For ICT \t\t\n");
       printf("\n\t\t 3:For CALCULUS \t\t\n");
       scanf("%d",&choice2);
       while(choice2<1 || choice2>3)
       {
        printf("\t\t\n ERROR \t\t\n\n\t\t Enter valid number : \t\t\n");
        scanf("%d",&choice2);
       }
       if(choice2==1)
       {
           printf("\n\t\t Enter the curve for PF: \t\t\n");
           scanf("%f", &crv);
           for (int i = 0; i < std; i++)
           {
           if (grades[i][0] + crv<= 100)
           {
             grades[i][0] = grades[i][0] +crv;
           }
           else
           {
             grades[i][0] = 100;
           }
           }
       }
       if(choice2==2)
       {
           printf("\n\t\t Enter the curve for ICT: \t\t\n");
           scanf("%f", &crv);
           for (int i = 0; i < std; i++)
           {
           if (grades[i][1] + crv<= 100)
           {
             grades[i][1] = grades[i][1] +crv;
           }
           else
           {
             grades[i][1] = 100;
           }
           }
       }
       if(choice2==3)
       {
           printf("\n\t\t Enter the curve for CALCULUS: \t\t\n");
           scanf("%f", &crv);
           for (int i = 0; i < std; i++)
           {
           if (grades[i][2] + crv<= 100)
           {
             grades[i][2] = grades[i][2] +crv;
           }
           else
           {
             grades[i][2] = 100;
           }
           }
       }
         for(int i=0;i<std;i++)
         {
            ful_grade[i]= ((grades[i][0] + grades[i][1] + grades[i][2])/300.0)*100.0;
         }
   }


}

void subject_pass_fail(float grades[][3], int std)
{
     char *subject_names[] = {"PF", "ICT", "Calculus"};

    for (int i = 0; i < std; i++)
    {
        int pass_count = 0, fail_count = 0;
        printf("\n\n\t\t Student %d: \t\t\n", i + 1);

        printf("\n\t\t Passed subjects: \t\t\n");
        for (int j = 0; j < 3; j++)
        {
            if (grades[i][j] >= 50)
            {
                pass_count++;
                printf("\t\t %s \t\t", subject_names[j]);
            }
        }

        printf("\n\t\t Failed subjects: \t\t\n");
        for (int j = 0; j < 3; j++)
        {
            if (grades[i][j] < 50)
            {
                fail_count++;
                printf("\t\t %s \t\t", subject_names[j]);
            }
        }

        printf("\n\t\t Total Passed: %d \t\t\n\n\t\t Total Failed: %d \t\t\n", pass_count, fail_count);
    }
}

void generate_report_cards(float grades[][3],float grade[],int std)
{
    char *subject_names[] = {"PF", "ICT", "Calculus"};

   for (int i = 0; i < std; i++)
   {
      printf("\n\n\t\t Report Card for Student %d \t\t\n", i + 1);
      printf("\n\t\t Grades in subjects: \t\t\n");
      for (int j = 0; j < 3; j++)
      {
         printf("\n\t\t %s: %.2f \t\t\n", subject_names[j], grades[i][j]);
      }
      printf("\n\t\t Total grade: %.2f \t\t\n", grade[i]);
   }
}

void topper_in_subject(float grades[][3], int std)
{
    char *subject_names[] = {"PF", "ICT", "Calculus"};

   for (int j = 0; j < 3; j++)
   {
       int topper = 0;
       float highest_grade = grades[0][j];

       for (int i = 1; i < std; i++)
       {
           if (grades[i][j] > highest_grade)
           {
               highest_grade = grades[i][j];
               topper = i;
           }
       }
       printf("\n\t\t Topper in %s: Student %d with %.2f grade.\t\t\n", subject_names[j], topper + 1, highest_grade);
   }
}
