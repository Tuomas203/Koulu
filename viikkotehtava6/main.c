#include <stdio.h>
#include <string.h>
/*--teht.1--*/
/*int main()
{
    char userName[50];

    printf("What is your name: ");

    scanf("%s", &userName);

    FILE *filePointer;

    filePointer=fopen("C:/Users/tuoma/Desktop/syksy 2024/johdannusohjelmointiin/tehtava6.txt", "w");

    fprintf(filePointer,"%s", userName);

    fclose(filePointer);

    return 0;
}*/

/*--teht.2--*/

/*int main(){
    char readFile;
    char text[255];

    FILE *sourcePointer;
    FILE *targetPointer;

    sourcePointer = fopen("C:/Users/tuoma/Desktop/syksy 2024/johdannusohjelmointiin/source.txt", "r");
    targetPointer = fopen("C:/Users/tuoma/Desktop/syksy 2024/johdannusohjelmointiin/target.txt", "w");

    while((readFile = fgetc(sourcePointer)) !=EOF)
        if (readFile==','){
            readFile=';';
            fprintf(targetPointer,"%c",readFile);}
        else
            fprintf(targetPointer,"%c",readFile);




    fclose(sourcePointer);
    fclose(targetPointer);
    return 0;
}*/

/*--teht.3--*/

/*int main(){

    char readFile;
    int numberOfSpaces=0;
    FILE *sourcePointer;

    sourcePointer = fopen("C:/Users/tuoma/Desktop/syksy 2024/johdannusohjelmointiin/source.txt", "r");

    while((readFile = fgetc(sourcePointer)) !=EOF)
        if (readFile==' '){
            numberOfSpaces++;
}
    printf("The number of spaces in the text document is: %d\n", numberOfSpaces);


    fclose(sourcePointer);



   return 0;
}*/



/*---teht.4yritys---*/

/*struct Student {
    int id;
    char name[50];
    int age;
};

int main(){
    struct Student students[6];



    for(int i=1;i<=5; i++){

    printf("what is the student id number of the %d student:", i);
    scanf("%d", &students[i].id);

    printf("What is the name of the %d student:", i);
    scanf("%s", &students[i].name);

    printf("How old is the %d student:", i);
    scanf("%d", &students[i].age);

}



     for(int j=1; j<=5;j++){

    printf("%d, ",students[j].id);
    printf("%s, ",students[j].name);
    printf("%d, ",students[j].age );
    printf("\n");
}







    return 0;
}*/


/*---teht.5---*/




/*struct Student {
    int id;
    char name[50];
    int age;
};

int main(){

    FILE *studentPointer;

    studentPointer = fopen("C:/Users/Tuomas/Desktop/Github/Koulu/viikkotehtava6/studentData.txt","w");

    struct Student students[6];

    students[1].id=*"%d";

    strcpy(students[1].name, "%s");

    students[1].age=*"%d";


    students[2].id=*"%d";

    strcpy(students[2].name, "%s");

    students[2].age=*"%d";


    students[3].id=*"%d";

    strcpy(students[3].name, "%s");

    students[3].age=*"%d";


    students[4].id=*"%d";

    strcpy(students[4].name, "%s");

    students[4].age=*"%d";


    students[5].id=*"%d";

    strcpy(students[5].name, "%s");

    students[5].age=*"%d";

    for(int i=1;i<=5; i++){

        printf("what is the student id number of the %d student:", i);
        scanf("%d", &students[i].id);

        printf("What is the name of the %d student:", i);
        scanf("%s", &students[i].name);

        printf("How old is the %d student:", i);
        scanf("%d", &students[i].age);       
    }

    int userNumber;

    printf("Do you want to save the students information if yes input 1 if no input 2: ");

    scanf("%d", &userNumber);

    if("%d", userNumber=1){


        for(int j=1; j<=5;j++){



            fprintf(studentPointer,"%d, ",students[j].id);
            fprintf(studentPointer,"%s, ",students[j].name);
            fprintf(studentPointer,"%d ",students[j].age );
            fprintf(studentPointer,"\n");

        }
    }

    else{
        fprintf(studentPointer,"Photes not bwinted");
    }


    fclose(studentPointer);

    return 0;
}*/


















