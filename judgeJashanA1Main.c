#include "givenA1.h" //including the header file 

int main(int argc,char **argv){

struct courseStruct courseInfo[NUMBER_COURSES];
struct profStruct profInfo[NUMBER_PROFS];  

char profsNCourses[50][MAX_STR]; //used in t4

char cNameFound[MAX_STR]; //t5
char cName[MAX_STR]; // ask ta do i need 2d
int cNumFound; 
int courseNum;

char taughtBy [NUMBER_PROFS][MAX_STR];
courseNum = 0;

int userInput =0;

int numCourses =0;



readCourse(argv[1], courseInfo); //reads the first text file and passes it through the function
readProfAndCoursesTaught(argv[2], profInfo, courseInfo); //reads the second text file and passes it through the function
   
int whileInt =0;


while (whileInt==0){ //while loop ends when a input other then 4,5,6,7,8 is entered and displays the menu


printf("\n\nWelcome to Assignment 1 //how does the user add the inputs for the data files\n");
printf("\nThe program has 5 tasks that the you can choose to do.\nPlease ensure you only input 4, 5, 6, 7, or 8 otherwise the program will end: ");


scanf("%d", &userInput); //scans the user input 


switch(userInput){ 

   case 4:  
   printf("\nPlease input a int number and you will be returned the names of all the professors who teach that number of courses or more: ");
   scanf("%d", &numCourses);
   nCourses (numCourses, profInfo, profsNCourses);
   break;

   case 5:
   printf("\nPlease enter a course number as input and you will be returned the coursename: ");
   scanf("%d", &courseNum);
   getCourseName (courseNum,cNameFound,courseInfo);
   break;

   case 6:
   printf("\nPlease input a course name and you will be returned the course code: ");
   getchar();
   
   fgets(cName, MAX_STR, stdin); // delete newline
    cName[strlen (cName)-1 ]= '\0';
   //scanf(" %[^\n]%*c", cName);
   //scanf(" %[^\n]", cName);
   //printf("\n%s", cName);
   getCourseNum(cName,&cNumFound,courseInfo);

   break;

   case 7:
   printf("\nTake a course number as input and return all profs teaching the course: ");
   scanf("%d", &courseNum);
   profsTeachingCourse (courseNum,profInfo,taughtBy);
   break;

   case 8:
   printf("\nReturn the avergae number of courses taught by profs: ");
   avgNumCourses (profInfo);
   break;

    default:
    whileInt = 1;
    break;

}

}
     return 0;
     
 }
 



//    //scanf(" %[^\n]", cName);
