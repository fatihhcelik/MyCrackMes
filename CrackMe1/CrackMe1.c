#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int read_from_file(char *filename);
int validate_license(char *key);

int main(){
    read_from_file("license.txt");

    return 0;
}

int read_from_file(char *filename){
    FILE *fp;
    char buf[100];

    if ((fp = fopen(filename, "r")) == NULL) {
        printf("Where is the file!");
        exit(1);
    }

    //Read from file until to the newline.
    fscanf(fp,"%[^\n]",buf); // :( We will come to this later..

    int c_code = fclose(fp);
    if(c_code != 0){
        printf("Error");
        exit(1);
    }

    validate_license(buf); //Validate
    return 0;
}

int validate_license(char *key){
    char *encoded_key="QnhjsxjYj}y";
    char temp[10];
    char *start = "#BEGIN#";
    char *end = "#END#";
    int length = strlen(key);
    int counter = 0;

    if(strlen(key) != 23){
        printf("The license key is not correct.");
        exit(1);
    }

    for(int i=0; i<7; i++){
        if(start[i] != key[i]){
            printf("The license key is not correct.");
            exit(1);
        }
    }

    for(int i=length-5; i<length;i++){
        if(end[counter] != key[i]){
            printf("The license key is not correct.");
            exit(1);
        }
        counter++;
    }

    counter=0;
    for(int i=7; i<=17; i++){
        temp[counter] = key[i];
        counter++;
    }

    for(int i=0; i<strlen(encoded_key); i++){
        if(encoded_key[i] != temp[i]+5){
            printf("The license key is not correct.");
            exit(1);            
        }
    }

    printf("Congratz!");
}

