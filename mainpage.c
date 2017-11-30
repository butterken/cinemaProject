#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void add();
void del();
int main()
{
	
	
	char option;
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	
	printf("\n\t*** Welcome to HK Grand SPACE Movie Ticketing Management System 2017 ***\n");
	printf("\n\t*** This system is developed by CCIT4020 class No. CL-06 Group No.___ ***\n");
	while(1){
	printf("\n <---Basic functions--->");
	printf("\n 1. Add New movie Ticketing Record(s):");
	printf("\n 2. Display All Movie Ticketing Records:");	             
	printf("\n 3. Modify Movie Ticketing Record(s):");	           
	printf("\n 4. Search Movie Ticketing Record(s):");	          
	printf("\n 5. Delete Movie Ticketing Record(s):");	
	printf("\nWhat is your option (1-5)? [q for quit]");
	printf("\nMy Option: ");
	scanf("%c",&option);	//getting option from user
	
	switch(option)
	{
		case '1':
			add();	//Calling method for add record(s)
                case '2':
			display();
		case '3':
			modify();
		case '4':
			search();
		case '5':
			del(); /*calling the delete function*/
		case 'Q': case 'q':
			printf("Exiting system...");
			exit(1);
			break;
		default:
			printf("Invaild input!");
	}
	}
	

	
	
	
	return 0;
}

void add()
{
	char content[50];	//String variable to store user's input
	
	char bookingNo[10]; //String variable to store confirmed Movie Booking Number
	char customerName[30]; //String variable to store confirmed Name of Customer
	char movieName[30]; //String variable to store confirmed Name of Movie
	char movieSchedule[10]; //String variable to store confirmed Movie Schedule
	char time[4]; //String variable to store confirmed Time
	char guestNum[3]; //String variable to store confirmed Number of Guests
	char houseNo[2]; //String variable to store confirmed House Number
	char ticketType[20]; //String variable to store confirmed Ticket Type
	char totalFee[10]; //String variable to store confirmed Total Fee
	
	char n;	//char for user's answer of add another record
	int next = 1;	//boolean for add another record
	
	do{
		//printf("\nPlease enter 1)Movie Booking Number, 2)Name of Customer, 3)Name of Movie, 4)Movie Schedule, 5)Time, 6)Number of Guests, 7)House Number, 8)Ticket Type, 9)Total Fee:\n");
		
		//read Movie Booking Number
		printf("\nPlease enter\n1)Movie Booking Number: ");
		fflush(stdin);
		gets(content);
		strcpy(bookingNo,content);
		printf("bookingNo:");
		puts(bookingNo);
		
		//read Name of Customer
		printf("2)Name of Customer: ");
		fflush(stdin);
		gets(content);
		strcpy(customerName,content);
		printf("customerName:");
		puts(customerName);
		
		//read Name of Movie
		printf("3)Name of Movie: ");
		fflush(stdin);
		gets(content);
		strcpy(movieName,content);
		printf("movieName:");
		puts(movieName);
		
		//read Movie Schedule
		printf("4)Movie Schedule(eg.1-10-2017): ");
		fflush(stdin);
		gets(content);
		strcpy(movieSchedule,content);
		printf("movieSchedule:");
		puts(movieSchedule);
		
		//read Time
		printf("5)Time(eg.1945): ");
		fflush(stdin);
		gets(content);
		strcpy(time,content);
		printf("time:");
		puts(time);
		
		//read Number Of Guest
		printf("6)Number Of Guest: ");
		fflush(stdin);
		gets(content);
		strcpy(guestNum,content);
		printf("guestNum:");
		puts(guestNum);
		
		//read House Number
		printf("7)House Number: ");
		fflush(stdin);
		gets(content);
		strcpy(houseNo,content);
		printf("houseNo:");
		puts(houseNo);
		
		//read Ticket Type
		printf("8)Ticket Type(Adult,Student,Senior and Children): ");
		fflush(stdin);
		gets(content);
		strcpy(ticketType,content);
		printf("ticketType:");
		puts(ticketType);
		
		//read Total Fee
		printf("9)Total Fee: ");
		fflush(stdin);
		gets(content);
		strcpy(totalFee,content);
		printf("totalFee(e.g.140.0):");
		puts(totalFee);
		
		FILE *f = fopen("record.txt", "a");	//opening record.txt for adding record
		
		fprintf(f, "%s\n", bookingNo);	//write Movie Booking Number to file
		fprintf(f, "%s\n", customerName);	//write Name of Customer to file
		fprintf(f, "%s\n", movieName);	//write Name of Movie to file
		fprintf(f, "%s\n", movieSchedule);	//write Movie Schedule to file
		fprintf(f, "%s\n", time);	//write Time to file
		fprintf(f, "%s\n", guestNum);	//write Number of Guest to file
		fprintf(f, "%s\n", houseNo);	//writeHouse Number to file
		fprintf(f, "%s\n", ticketType);	//write Ticket Type to file
		fprintf(f, "%s\n\n", totalFee);	//write Total Fee to file & add emtpy line at end of record
		
		fclose(f);
		
		printf("\nAdd another record(y/n): ");	//ask do user want to add another record
		scanf("%c",&n);
		if(n=='n'){
			next = 0;	//if not, quit the while-loop
		}
	}while(next == 1);
	
	return;
}

void del()
{
	char ch[40],con,n,next=1;
	int del, delno,i;	
	FILE *infile, *outfile, *outfile2;
	infile = fopen("movie.txt","r"); /*open text file for reading*/
	outfile = fopen("del.txt","w"); /*create text file for transfer the data that is needed*/
	outfile2 = fopen("rubbish.txt","w"); /*create text file to store the deleted record*/
	
	if (infile == NULL)  /*check the file is exist or not*/
	{
		printf("\nFile Lost!!! ");
		printf("\nPlease find adminstor to help you fix the problem");
		exit(1);
	}
	do{ /*back to here if delete another record*/
	
    printf("please enter the movie booking number that you want to delete<1001-1050>:"); /*ask for input the record that needed for delete*/
    scanf("%d",&del);
    while(del<1000 && del>1050)  /*input validation*/
    {
    	printf("invaid movie booking number, please type again<1001-1050>:");
    	fflush(stdin);
    	scanf("%d",&del);   /*retype if invalid*/
	}
	delno = (del-1000)*10 - 10;	/*find the no. of line to be transfer*/
		for(i=0;i<delno;i++)
			{	
			fgets(ch,40,infile);
		fputs(ch, outfile);
			}		
/**/
		for(i=0;i<9;i++)  /*transfer deleted record to rubbish bin*/
		{
		fgets(ch,40,infile);
		fputs(ch, outfile2);
		fputs("-deleted-",outfile); /*leave it blank to prevent bug*/
		}
/**/
		for(;con != EOF;) /*transfer the remaining record*/
		{

		con=fgetc(infile);
		fputc(con, outfile);
		} 
	fclose(infile);
	fclose(outfile);
        fclose(outfile2);

		
		printf("Are you confirm to delete the record?<y or n>: "); /*confirm the delete of file*/
	    fflush(stdin);
		scanf("%c",&n);
		do{
		switch(n)
		{case 'y' : case 'Y' :
            infile = fopen("movie.txt","w"); /*open a new file and overwrite the old one*/
	    outfile = fopen("del.txt","r");
             while (1) {
             con = fgetc(outfile); /*transfer the record back to the file*/
             if (con == EOF)
             break;
             else
             fputc(con, infile);
   }
		case 'n' :
		case 'N' :
		     break;
		default :
		     printf("invalid input");
	         printf("\nAre you confirm to delete the record?<y or n>: ");
	    	 fflush(stdin);
	    	 scanf("%c",&n);
		}
	}while(1);
	
		printf("Do you want to remove another customer's movie ticket booking record?<y or n>'");
		fflush(stdin);
		scanf("%c",&n);
		do{
		
		switch(n)
		{
			case 'y' :
			case 'Y' :
				next = 1;
				break;
			case 'n' :
		        case 'N' :
		    	        next = 0;
		    	        break;
		    default :
		    	printf("invalid input");
		    	printf("Do you want to remove another customer's movie ticket booking record?<y or n>'");
		        fflush(stdin);
				scanf("%c",&n);
		}
	}while(1);
		
		  }while(next!=0);	
	fclose(infile);
	fclose(outfile);
	fclose(outfile2);
		  return;
		  }
