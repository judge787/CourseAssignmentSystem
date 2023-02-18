#include "givenA1.h" //including the header file 

// task 1 points to the file and and opens up the file for
// reading that comes form the command line arguments from the main
// file 
FILE *openFileForReading(char fileName [MAX_STR]){
   
 FILE *fptr = fopen(fileName, "r");
 if (fptr == NULL){
    //printf("File not found in task 1\n"); // for testing 
    return NULL;
   }

  else{
   return fptr;
}
}
// for task2 I first called the openFileForReading function so that it can 
// read the file, after that i created a do loop to check when there is a newline
// so that it can iterate the variable curent_line in order to count the number of
// lines the files have, after thats done, i check if the lines are greater than or less
// than 2 * NUMBER_COURSES so that it can return -1


int readCourse (char filename [MAX_STR],
                struct courseStruct courseInfo [NUMBER_COURSES]){

      FILE* fptr = openFileForReading(filename);
      if (fptr== NULL){
         //printf("File not found in task 2\n"); // for testing 
         return -1;
      }
      //calls another function to open and read the text files

      int current_line = 1;
      char c;
      do{
         c = fgetc(fptr);
         if (c == '\n'){
            current_line++;
         }
      } while (c!= EOF);
         rewind(fptr); //brings the line back to line 1 so that the next time the program
                     //reads the file it starts at the top
         
         //printf("Lines: %d\n", current_line); // for testing
       if(current_line < NUMBER_COURSES * 2 || current_line > NUMBER_COURSES * 2){
         return -1;
      }
//   
        for (int i=0; i< NUMBER_COURSES; i++){ //inputs the courseName from the file and stores the values into courseName, it also removes the newlien from the end of the line
         fgets (courseInfo[i].courseName, MAX_STR, fptr);
         courseInfo[i].courseName [strlen (courseInfo[i].courseName)-1 ]= '\0';
        //printf("%s\n", courseInfo[i].courseName); // for testing t2
        }
        
        for (int i=NUMBER_COURSES; i < NUMBER_COURSES *2; i++){ //for loop that starts when the line is at the courseIDs and then stores the ids to courseID
         fscanf(fptr, "%d", &courseInfo[i -NUMBER_COURSES].courseID);
         //printf("%d\n", courseInfo[i - NUMBER_COURSES].courseID); // for testing 
          }     

    fclose(fptr); // closes the file
   return 1;
                }


int readProfAndCoursesTaught (char filename [MAX_STR],
                               struct profStruct profInfo [NUMBER_PROFS],
                              struct courseStruct courseInfo [NUMBER_COURSES]
                               ){

    FILE* fptr = openFileForReading(filename);  
      if (fptr== NULL){
        // printf("File not found in task 3\n"); // for testing 
         return -1;
      }

      char yn[50][MAX_STR];

                           //reads the profs names and stores them on 
                           // profName and removes the newline from the end of the line
      for (int i=0; i< NUMBER_PROFS; i++){
         fgets (profInfo[i].profName, MAX_STR, fptr); 
         profInfo[i].profName [strlen (profInfo[i].profName)-1 ]= '\0';
        //printf("%s\n", profInfo[i].profName); // for testing
        }

                              // reads the ys and ns from the file and stoes them in yn
                              // it also removes the newline at the end of each line if the line is not the last line in the file
        for (int i=0 ; i < NUMBER_PROFS; i++){
         fgets (yn[i], MAX_STR, fptr);
       if (i != NUMBER_PROFS- 1){
         yn[i][strlen (yn[i])-1]= '\0';
       }
         //printf("%s testing from t3\n", yn[i]); // for testing
        }
                              // checks yn if the values are y or n, if there y it stores the courseid into coursestaught
                              // if its n it stores the value -1 into coursestaught
         for (int i = 0; i < NUMBER_PROFS; i++)   
         {
            for (int j = 0; j < NUMBER_COURSES; j++)
            {
               if(yn[i][j]=='y'|| yn[i][j]=='Y'){
                  profInfo[i].coursesTaught[j] = courseInfo[j].courseID;
                  //printf("i:%d, j:%d, value: %d\n", i, j, profInfo[i].coursesTaught[j]); // for testing    
               }
               else if (yn[i][j]=='n'|| yn[i][j]=='N'){
                  profInfo[i].coursesTaught[j] = -1;
                  // printf("i:%d, j:%d, value: %d\n", i, j, profInfo[i].coursesTaught[j]);    
                }
            }
            
         }
       fclose(fptr);
   return 1;
          }   
      
/* Task 4 */
int nCourses (int n,
              struct profStruct profInfo [NUMBER_PROFS],
              char profsNCourses [NUMBER_PROFS][MAX_STR]
              ){
     
     int temp = n; // temp value so that it can store the input number from the user
     n=0; // n =0 so that the number of courses taught start at 0

   for (int i=0; i<NUMBER_PROFS; i++){ // populates profsNCourses with empty spaces so that it doesnt carry over prof names from the previous time the task was used 

      strcpy(profsNCourses[i], "");
   }




     for (int i = 0; i < NUMBER_PROFS; i++)
         {
            int count =0;// makes count 0 everytime it finishes checking if a prof teaches those courses 
            for (int j = 0; j < NUMBER_COURSES; j++)
            {                  
                  if (profInfo[i].coursesTaught[j] != -1)  { // counts the amount of actual courses the prof teaches by incrementing count
                                                            // if the values in coursestaught is not -1
                     count++; 

                                       // checks if the count is greater than or equal to the user inputed number "temp" and then compares
                                       //the values so that it doesnt add the same prof name to profsNCourses

                    //if (count >= temp && strcmp(profsNCourses[i], profInfo[i].profName)!= 0 && temp<=NUMBER_PROFS){ 
                    if (count >= temp && strcmp(profsNCourses[i], profInfo[i].profName)!= 0 && temp>0){  //v2 works i think
                      
                        strcpy(profsNCourses[i], profInfo[i].profName); //stores the correct prof names into profsNCourses
                        n++; //incremnets the return value 
                        //printf("%s\n", profsNCourses[i]); // for testing
                         }                                              }
            }
            }
               
//printf("%d\n", n); // for testing 
         return n; //return the number of profs that teach n courses 
              }

/* Task 5 */
int getCourseName (int courseNum, 
                   char cNameFound [MAX_STR],
                   struct courseStruct courseInfo [NUMBER_COURSES]
                   ){
int returnVal= 0;
   
   for (int i =0; i < NUMBER_COURSES; i++){ //cleans out cNameFound so that the string is not populated with junk data
   strcpy(cNameFound, ""); //cleans out cNameFound so that the previous use of the task does not interfere
   } 

 for (int i = 0; i < NUMBER_COURSES; i++)
         {             
               if (courseInfo[i].courseID== courseNum)  {
                    //printf("\n%d\n", courseInfo[i].courseID);
                     strcpy(cNameFound, courseInfo[i].courseName);
                    // printf("%s\n", cNameFound); //cname test 
                     returnVal = 1;
                  }
            //          else {
            //             //printf("not found");
            //          }           
            }
return returnVal;
                   }

// /* Task 6 */
int getCourseNum (char cName [50],
                  int * cNumFound,
                  struct courseStruct courseInfo [NUMBER_COURSES]
                  ){
                    *cNumFound = 0; //make it 0 so that previous uses of the task dont interfere
                   // printf("%d", *cNumFound);
                    
                     int returnVal = 0;
                     for (int i = 0; i < NUMBER_COURSES; i++)
         {        
                 // printf("%s", courseInfo[i].courseName);
               if (strcmp(cName, courseInfo[i].courseName) ==0 )  {
                     *cNumFound = courseInfo[i].courseID; 
                     //printf("\n%s\n", cName);
                   // printf("\n%d\n", * cNumFound);
                     returnVal = 1;
                  }

         }
         
return returnVal;
                  }

// /* Task 7 */
int profsTeachingCourse (int courseNum,
                         struct profStruct profInfo [NUMBER_PROFS],
                         char taughtBy [NUMBER_PROFS][MAX_STR]
                         ){
            
int temp = courseNum;
courseNum =0; //make it 0 so that previous uses of the task dont interfere

                          for (int i = 0; i < NUMBER_PROFS; i++)
         {
            for (int j = 0; j < NUMBER_COURSES; j++) 
            {
               if(temp == profInfo[i].coursesTaught[j]){  //checks if the users number is the same as the courses then copies it into taughtBy
                  strcpy(taughtBy[i], profInfo[i].profName);
                  courseNum++; 
                // printf("%s\n",taughtBy[i]);
                  //printf("%d\n", courseNum);  
               }
            }   
         }

         if(courseNum == 0){
           // printf("num zero");
                     return 0;    
                  }
        //    printf("%d\n", courseNum);  
      return courseNum;
             }

// /*Task 8 */

// task 8 counts the amount of courses being taught by checking the non -1 values then divides that by the number of profs and rounds it up using the round function from math.h
float avgNumCourses (struct profStruct profInfo [NUMBER_PROFS]){
 float avg =0;
   float count =0;
    for (int i = 0; i < NUMBER_PROFS; i++)
         {
            for (int j = 0; j < NUMBER_COURSES; j++)
            {
               if(profInfo[i].coursesTaught[j] != -1){
                  count++;
               }
            }   
         }

   avg = round(count/NUMBER_PROFS);
   //printf("%.1lf\n", avg);
return avg;
}



