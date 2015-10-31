/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 */
int pdf()
{
	unsigned char c1[6] = { 0x25, 0x50, 0x44, 0x46, 0x2D, 0x31 }, c3 = 0x46, c4, cname[10] , ctemp = 0x00;

	/*
	 * c1 holds the header(0x25,0x50,0x44,0x46,0x2D,0x31).
	 * c3 holds part of  footer(0x46).
	 * cname holds the name of current output file.
	 * ctemp holds the previous fread value.
	 */

	int i = 001, j = 0, k = 0;


	/*
	 * i holds the current number of the pdf file recovered.
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

		if(c4 == c1[j]){//0x25
			j++;
			fread (&c4, 1, 1, f);
			if(c4 == c1[j]){//0x50
				j++;
				fread (&c4, 1, 1, f);
				if(c4 == c1[j]){//0x44
					j++;
					fread (&c4, 1, 1, f);
					if(c4 == c1[j]){//0x46
						j++;
						fread (&c4, 1, 1, f);
						if(c4 == c1[j]){//0x2D
							j++;
							fread (&c4, 1, 1, f);
							if(c4 == c1[j]){//0x31
								j++;
								printf("pdf file found\n");
							}
						}
					}
				}
			}
		}
		k = 0;


		/*
		 * if u have found the header of pdf then write the image to a file.
		 */

		if(j == 6){
			sprintf(cname, "pdf/%d.pdf", i);
			ftemp = fopen(cname, "wb");

			if(ftemp == NULL){
				printf("file %s cant be opened\n", cname);
				exit(0);
			}else{
				printf("file %s opened\n", cname);
			}

			/*
			 * writing the pdf header to new file.
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

			while(c4 != 0x46 || ctemp != 0x4F){
				ctemp = c4;
				fread (&c4, 1, 1, f);
				fwrite(&c4, 1, 1, ftemp);
				if(ctemp == 0x4F && c4 == 0x46){
					printf("pdf file closed \n");


					/*
					 * completed pdf file is recovered to new file.
					 */

					fclose(ftemp);
					i++;
					break;
				}
			}
		}
	}

	printf("\n\nALL PDF FILES ARE CARVED\n \n");
	printf("TOTAL NO OF PDF FILES=%d",i);
	fclose(f);
	go_back_main_menu();
}
//program end.
