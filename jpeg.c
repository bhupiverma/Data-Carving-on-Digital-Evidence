/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
*/
int jpeg()
{
unsigned char c1[6] = { 0xFF, 0xD8, 0xFF, 0xE0, 0x00, 0x10 }, c3 = 0xD9, c4, cname[10] , ctemp = 0x00;

/*
* c1 holds the header(0xFFD8FFE00010).
* c3 holds part of  footer(0xD9).
* cname holds the name of current output file.
* ctemp holds the previous fread value.
*/

int i = 001, j = 0, k = 0;


/*
* i holds the current number of the jpeg file recovered.
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

if(c4 == c1[j]){//0xFF
j++;
fread (&c4, 1, 1, f);
if(c4 == c1[j]){//0xD8
j++;
fread (&c4, 1, 1, f);
if(c4 == c1[j]){//0xFF
j++;
fread (&c4, 1, 1, f);
if(c4 == c1[j]){//0xE0
j++;
fread (&c4, 1, 1, f);
if(c4 == c1[j]){//0x00
j++;
fread (&c4, 1, 1, f);
if(c4 == c1[j]){//0x10
j++;
printf("jpeg image found\n");
}
}
}
}
}
}
k = 0;


/*
* if u have found the header of jpg then write the image to a file.
*/

if(j == 6){
sprintf(cname, "jpeg/%d.jpg", i);
ftemp = fopen(cname, "ab");

if(ftemp == NULL){
printf("file %s cant be opened\n", cname);
exit(0);
}else{
printf("file %s opened\n", cname);
}

/*
* writing the image header to new file.
*/

while(k !=  j){
fwrite(&c1[k], 1, 1, ftemp);
k++;
}
ctemp = c4;
printf("ctemp =%x c4 =%x \n", ctemp, c4);


/*
* writing the image data to the file newly created.
*/

while(c4 != 0xd9 || ctemp != 0xFF){
ctemp = c4;
fread (&c4, 1, 1, f);
fwrite(&c4, 1, 1, ftemp);
if(ctemp == 0xFF && c4 == 0xD9){
printf("image closed \n");


/*
* completed image is recovered to new file.
*/

fclose(ftemp);
i++;
break;
}
}
}
}

printf("\nALL JPEG FILES ARE CARVED \n\n");
fclose(f);
go_back_main_menu();

}
//program end.
