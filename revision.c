// // #include <stdio.h>
// // #include <string.h>
 
// // int main()
// // {
// //     char s[1000]; 
// //     int i,alphabets=0,digits=0,specialcharacters=0;
 
// //     printf("Enter  the string : ");
// //     gets(s);
     
// //     for(i=0;s[i];i++)  
// //     {
// //         if((s[i]>=65 && s[i]<=90)|| (s[i]>=97 && s[i]<=122) )
// //           alphabets++;
// //         else if(s[i]>=48 && s[i]<=57)
// //          digits++;
// //         else
// //          specialcharacters++;

// //  	}
 	
     
// //     printf("Alphabets = %d\n",alphabets);
// //     printf("Digits = %d\n",digits);
// //     printf("Special characters = %d", specialcharacters);
    

// //     return 0;
// // }













































// // C Program to count
// // the Number of Characters in a Text File

// #include <stdio.h>
// #define MAX_FILE_NAME 100

// int main()
// {
// 	FILE* fp;

// 	// Character counter (result)
// 	// int count = 0;   
//     char s[1000]; 
//     // int i,alphabets=0,digits=0,specialcharacters=0;
//     int nletter, ndigit, nspace, nother; /* char counts */
//     int i;
//     clrscr();
// 	char filename[MAX_FILE_NAME];

// 	// To store a character read from file
// 	char c;

// 	// Get file name from user.
// 	// The file should be either in current folder
// 	// or complete path should be provided
// 	printf("Enter file name: ");
// 	scanf("%s", filename);

// 	// Open the file
// 	fp = fopen(filename, "r");

// 	// Check if file exists
// 	if (fp == NULL) {
// 		printf("Could not open file %s",
// 			filename);
// 		return 0;
// 	}

// 	// Extract characters from file
// 	// and store in character c
// 	gets(str);
//       /* count characters in string str */
//       nletter = ndigit = nspace = nother = 0; /* init counts */
//       i = 0;
//       while (str[i] != '\0')
//           {
//               char ch= str[i];
//               if (ch>= 'A' && ch<= 'Z' || ch>= 'a' && ch<= 'z')
//               nletter++;
//               else if (ch>= '0' && ch<= '9')
//                        ndigit++;
//               else if (ch == ' ' || ch =='\n' || ch == '\t')
//                        nspace++;
//               else nother++;
//                        i++;
//           }

// 	// Close the file
// 	fclose(fp);

// 	// Print the count of characters
// 	// printf("The file %s has %d characters\n ",filename, count);
//     printf("Letters: %d \tWhite spaces : %d", nletter, nspace);
//     printf(" Digits : %d \tOther chars : %d\n", ndigit, nother);
//     getch();
    

// 	return 0;
// }


// /*gets(str);
//       /* count characters in string str 
//       nletter = ndigit = nspace = nother = 0; /* init counts 
//       i = 0;
//       while (str[i] != '\0')
//           {
//               char ch= str[i];
//               if (ch>= 'A' && ch<= 'Z' || ch>= 'a' && ch<= 'z')
//               nletter++;
//               else if (ch>= '0' && ch<= '9')
//                        ndigit++;
//               else if (ch == ' ' || ch =='\n' || ch == '\t')
//                        nspace++;
//               else nother++;
//                        i++;
//           }
//               /* print counts */
              
















#include<stdio.h>
#include<string.h>

void main()
{
     char key[32][12]={"auto","break","double","int","char","while"};
     char ch[500];

 	FILE *fp=fopen("gaurav.txt","r");
 
 	//file exists krti h ya nh
    if(fp=='\0') 
    {
     printf("file not found..\n");
     return 0;
     }
	  //word ko extract krna tab tak file ka end tak nh poch jaye 
	int cnt=0;
	int i;
    while((fscanf(fp,"%s",ch))!=EOF)
   {
      for(i=0;i<32;i++)
      {
       if(strcmp(key[i],ch)==0) {
       printf("\nkeyword is : %s",ch); 
       cnt++;
      }
     }
	}
    printf("keywords are : %d", cnt);
    fclose(fp);
}
