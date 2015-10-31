/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
*/
int gif()
{
unsigned char c1[6] = { 0x47, 0x49, 0x46, 0x38, 0x39, 0x61 }, c3 = 0x3B, c4, cname[10] , ctemp = 0x00;

/*
* c1 holds the header(0x47,0x49,0x46,0x38,0x37,0x61).
* c3 holds part of  footer(0x3B).
* cname holds the name of current output file.
* ctemp holds the previous fread value.
*/

int i = 001, j = 0, k = 0;


/*
* i holds the current number of the gif file recovered.
* j holds the no of matchs to the header.
* k loop varible.
*/

FILE *f = fopen("raw", "rb");
FILE *ftemp ;


/*
* f holds the pointer to free space data file.
* ftemp holds the output file pointer to which data has to be written.
*/

if(f == NULL){
printf("file raw cant be opened\n");
exit(0);
}
else{
printf("file raw opened\n");
}

while(!feof(f)){
fread (&c4, 1, 1, f);
j = 0;

/*
* checking for the header.
*/

if(c4 == c1[j]){//0x47
j++;
fread (&c4, 1, 1, f);
if(c4 == c1[j]){//0x49
j++;
fread (&c4, 1, 1, f);
if(c4 == c1[j]){//0x46
j++;
fread (&c4, 1, 1, f);
if(c4 == c1[j]){//0x38
j++;
fread (&c4, 1, 1, f);
if(c4 == c1[j]){//0x39
j++;
fread (&c4, 1, 1, f);
if(c4 == c1[j]){//0x61
j++;
printf("gif file found\n");
}
}
}
}
}
}
k = 0;


/*
* if u have found the header of gif then write the image to a file.
*/

if(j == 6){
sprintf(cname, "gif/%d.gif", i);
ftemp = fopen(cname, "wb");

if(ftemp == NULL){
printf("file %s cant be opened\n", cname);
exit(0);
}else{
printf("file %s opened\n", cname);
}

/*
* writing the gif header to new file.
*/

while(k !=  j){
fwrite(&c1[k], 1, 1, ftemp);
k++;
}
ctemp = c4;
printf("ctemp =%x c4 =%x \n", ctemp, c4);


/*
* writing the file data to the file newly created.
*/

while(c4 != 0x3B || ctemp != 0x00){
ctemp = c4;
fread (&c4, 1, 1, f);
fwrite(&c4, 1, 1, ftemp);
if(ctemp == 0x00 && c4 == 0x3B){
printf("gif file closed \n");


/*
* completed gif file is recovered to new file.
*/

fclose(ftemp);
i++;
break;
}
}
}
}

printf("closed \n");
fclose(f);
}
//program end.
