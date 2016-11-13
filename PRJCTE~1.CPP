#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<iomanip.h>
#include<dos.h>
#include<graphics.h>


class book
{
	char bno[6];
	char bname[50];
	char aname[20];
	char bcost[6];
	public:
		void create_book()
		{
			cout<<"NEW BOOK ENTRY"<<endl;
			cout<<"\nEnter The book number   : ";
			cin>>bno;
			cout<<endl;
			cout<<"Enter The Name of The Book: ";
			gets(bname);
			cout<<endl;
			cout<<"Enter The Author's Name   : ";
			gets(aname);
			cout<<endl;
			cout<<"Enter the cost of the book: ";
			cin>>bcost;
			cout<<endl;
			delay(500);
			cout<<"\nBook Created";
		}
		void show_book()
		{
			cout<<"\nBook no   : "<<bno;
			cout<<"\nBook Name : ";
			puts(bname);
			cout<<"Author Name : ";
			puts(aname);
			cout<<"Cost        : "<<bcost;
		}
		void modify_book()
		{
			cout<<"\nBook number   : "<<bno;
			cout<<endl;
			cout<<"Modify Book Name: ";
			gets(bname);
			cout<<endl;
			cout<<"Modify Author's Name of Book: ";
			gets(aname);
			cout<<"Modify the cost of the book: ";
			cin>>bcost;
		}
		char* retbno()
		{
			return bno;
		}
		char* retbname()
		{
			return bname;
		}
		char* retaname()
		{
			return aname;
		}
		void data()
		{
			cout<<bno<<setw(25)<<bname<<setw(25)<<aname<<setw(17)<<bcost<<endl;
		}
		char* retcost()
		{
			return bcost;
		}

};

class student
{
	char admno[6];
	char name[20];
	char stbno[6];
	int bkstatus;
	public:
		void create_student()
		{
			clrscr();
			cout<<"NEW STUDENT ENTRY"<<endl;
			cout<<"\nEnter the Admission Number : ";
			cin>>admno;
			cout<<endl;
			cout<<"Enter The Name of The Student: ";
			gets(name);
			cout<<endl;
			bkstatus=0;
			stbno[0]='/0';
			delay(500);
			cout<<"\nStudent Record Created";
		}
		void show_student()
		{
			cout<<"\nAdmission no. : "<<admno<<endl;
			cout<<"Student Name : ";
			puts(name);
			cout<<endl;
			cout<<"No of Book issued : "<<bkstatus<<endl;
			if(bkstatus==1)
				cout<<"Issued Book Number: "<<stbno;
		}
		void modify_student()
		{
			cout<<"\nAdmission Number: "<<admno;
			cout<<endl;
			cout<<"Modify Student Name: ";
			gets(name);
		}
		char* retstuname()
		{
			return name;
		}
		char* retadmsnno()
		{
			return admno;
		}
		char* retstbno()
		{
			return stbno;
		}
		int retbkstatus()
		{
			return bkstatus;
		}
		void bkborrowed()
		{
			bkstatus=1;
		}
		void bkreturned()
		{
			bkstatus=0;
		}
		void getstbno(char t[])
		{
			strcpy(stbno,t);
		}
		void data()
		{
			cout<<setw(5)<<admno<<setw(30)<<name<<setw(23)<<bkstatus<<endl;
		}

};


void end();
void sort_book();
void bkmenu();
void stmenu();
fstream f,f1;
book bk;
student st;

void write_book()
{
	char ch;
	f.open("book.dat",ios::out|ios::app|ios::in);
	do
	{
		bk.create_book();
		f.write((char*)&bk,sizeof(book));
		cout<<"\nDo you want add another book? (y/n): ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	f.close();
}


void write_student()
{
	char ch;
	f.open("student.dat",ios::out|ios::app);
	do
	{
		st.create_student();
		f.write((char*)&st,sizeof(student));
		cout<<"\nDo you want add another student? (y/n): ";
		cin>>ch;
	}while(ch=='y'||ch=='Y');
	f.close();
}


void displayb_num(char n[])
{
	cout<<"BOOK DETAILS\n";
	int flag=0;
	f.open("book.dat",ios::in);
	while(f.read((char*)&bk,sizeof(book)))
	{
		if(strcmpi(bk.retbno(),n)==0)
		{
			bk.show_book();
			flag=1;
		}
	}

	f.close();
	if(flag==0)
	cout<<"\n\nBook does not exist";
	getch();
}


void displayb_name(char n[])
{
	cout<<"BOOK DETAILS\n";
	int flag=0;
	f.open("book.dat",ios::in);
	while(f.read((char*)&bk,sizeof(book)))
	{
		if(strcmpi(bk.retbname(),n)==0)
		{
			bk.show_book();
			flag=1;
		}
	}

	f.close();
	if(flag==0)
	cout<<"\n\nBook does not exist";
	getch();
}

void displayb_aname(char n[])
{
	cout<<"BOOK DETAILS\n";
	int flag=0;
	f.open("book.dat",ios::in);
	while(f.read((char*)&bk,sizeof(book)))
	{
		if(strcmpi(bk.retaname(),n)==0)
		{
			bk.show_book();
			cout<<endl;
			flag=1;
		}
	}

	f.close();
	if(flag==0)
	cout<<"\n\nBook does not exist";
	getch();
}

void displayb_cost(char n[],char n1[])
{
	cout<<"BOOK DETAILS\n";
	int flag=0;
	f.open("book.dat",ios::in);
	while(f.read((char*)&bk,sizeof(book)))
	{
		if(strcmp(bk.retcost(),n)>0 && strcmp(bk.retcost(),n1)<0)
		{
			bk.show_book();
			cout<<endl;
			flag=1;
		}
	}

	f.close();
	if(flag==0)
	cout<<"\n\nBook does not exist";
	getch();
}


void displays_num(char n[])
{
	int flag=0;
	f.open("student.dat",ios::in);
	while(f.read((char*)&st,sizeof(student)))
	{
		if((strcmpi(st.retadmsnno(),n)==0))
		{
			cout<<"STUDENT DETAILS: "<<endl;
			st.show_student();
			flag=1;
		}
	}

	f.close();
	if(flag==0)
	cout<<"\n\nStudent does not exist";
	getch();
}

void displays_name(char n[])
{
	int flag=0;
	f.open("student.dat",ios::in);
	while(f.read((char*)&st,sizeof(student)))
	{
		if((strcmpi(st.retstuname(),n)==0))
		{
			cout<<"STUDENT DETAILS: "<<endl;
			st.show_student();
			flag=1;
		}
	}

	f.close();
	if(flag==0)
	cout<<"\n\nStudent does not exist";
	getch();
}



void display_alls()
{
	clrscr();
	f.open("student.dat",ios::in);
	if(!f)
	{
		cout<<"File could not be opened ";
		getch();
		return;
	}

	cout<<"\n\n\t\tSTUDENT LIST\n\n";
	cout<<"==================================================================\n";
	cout<<"Admission No."<<setw(19)<<"Name"<<setw(33)<<"Book Issued\n";
	cout<<"==================================================================\n";

	while(f.read((char*)&st,sizeof(student)))
	{
		st.data();
	}

	f.close();
	getch();
}

void display_allb()
{
	clrscr();
	f.open("book.dat",ios::in);
	if(!f)
	{
		cout<<"ERROR!!! FILE COULD NOT BE OPENED ";
		getch();
		return;
	}

	cout<<"\n\n\t\tBook LIST\n\n";
	cout<<"=========================================================================\n";
	cout<<"Book Number"<<setw(19)<<"Book Name"<<setw(25)<<"Author"<<setw(16)<<"Cost\n";
	cout<<"=========================================================================\n";

	while(f.read((char*)&bk,sizeof(book)))
	{
		bk.data();
	}
	f.close();
	getch();
}



void modify_book()
{
	char n[6];
	int found=0;
	clrscr();
	cout<<"\nMODIFY BOOK RECORD "<<endl;
	cout<<"\nEnter The Book Number: ";
	cin>>n;
	f.open("book.dat",ios::in|ios::out);
	while(f.read((char*)&bk,sizeof(book)) && found==0)
	{
		if(strcmpi(bk.retbno(),n)==0)
		{
			bk.show_book();
			cout<<"\nEnter The New Details of book: ";
			bk.modify_book();
			int pos=-1*sizeof(bk);
			f.seekp(pos,ios::cur);
			f.write((char*)&bk,sizeof(book));
			delay(500);
			cout<<"\n\nRecord Updated";
			found=1;
		}
	}

	f.close();
	if(found==0)
	cout<<"\n\n Record Not Found ";
	getch();
}


void modify_student()
{
	char n[6];
	int found=0;
	clrscr();
	cout<<"\nMODIFY STUDENT RECORD "<<endl;
	cout<<"\nEnter The admission no. of The student: ";
	cin>>n;
	f.open("student.dat",ios::in|ios::out);
	while(f.read((char*)&st,sizeof(student)) && found==0)
	{
		if(strcmpi(st.retadmsnno(),n)==0)
		{
			st.show_student();
			cout<<"\nEnter The New Details of student: ";
			st.modify_student();
			int pos=-1*sizeof(st);
			f.seekp(pos,ios::cur);
			f.write((char*)&st,sizeof(student));
			delay(500);
			cout<<"\n\nRecord Updated";
			found=1;
		}
	}

	f.close();
	if(found==0)
	cout<<"\n\n Record Not Found ";
	getch();
}



void delete_student()
{
	char n[6];
	int flag=0;
	clrscr();
	cout<<"\nDELETE STUDENT..."<<endl;
	cout<<"\nEnter The admission no. of the Student You Want To Delete: ";
	cin>>n;
	f.open("student.dat",ios::in|ios::out);
	fstream f2;
	f2.open("Temp.dat",ios::out);
	f.seekg(0,ios::beg);
	while(f.read((char*)&st,sizeof(student)))
	{
		if(strcmpi(st.retadmsnno(),n)!=0)
			f2.write((char*)&st,sizeof(student));
		else
			flag=1;
	}

	f2.close();
	f.close();
	remove("student.dat");
	rename("Temp.dat","student.dat");
	if(flag==1)
	{
		delay(500);
		cout<<"\n\nRecord Deleted ..";

	}
	else
		cout<<"\n\nRecord not found";
	getch();
}


void delete_book()
{
	char n[6];
	clrscr();
	cout<<"\nDELETE BOOK"<<endl;
	cout<<"\nEnter The Book no. of the Book You Want To Delete: ";
	cin>>n;
	f.open("book.dat",ios::in|ios::out);
	fstream f2;
	f2.open("Temp.dat",ios::out);
	f.seekg(0,ios::beg);
	while(f.read((char*)&bk,sizeof(book)))
	{
		if(strcmpi(bk.retbno(),n)!=0)
		{
			f2.write((char*)&bk,sizeof(book));
		}
	}

	f2.close();
	f.close();
	remove("book.dat");
	rename("Temp.dat","book.dat");
	delay(500);
	cout<<"\n\nRecord Deleted.";
	getch();
}




void book_issue()
{
	char sn[6],bn[6];
	int found=0,flag=0;
	clrscr();
	cout<<"\nBOOK ISSUE ..."<<endl;
	cout<<"\nEnter Admission no: ";
	cin>>sn;
	f.open("student.dat",ios::in|ios::out);
	f1.open("book.dat",ios::in|ios::out);
	while(f.read((char*)&st,sizeof(student)) && found==0)
	{
		if(strcmpi(st.retadmsnno(),sn)==0)
		{
			found=1;
			if(st.retbkstatus()==0)
			{
				cout<<"\nEnter the book no: ";
				cin>>bn;
				while(f1.read((char*)&bk,sizeof(book))&& flag==0)
				{
					if(strcmpi(bk.retbno(),bn)==0)
					{
						bk.show_book();
						flag=1;
						st.bkborrowed();
						st.getstbno(bk.retbno());
						int pos=-1*sizeof(st);
						f.seekp(pos,ios::cur);
						f.write((char*)&st,sizeof(student));
						cout<<"\nBook issued successfully"<<endl;
						cout<<endl;
						int money;
						cout<<endl;
						delay(1500);
						clrscr();
						cout<<"Please deposit 10 AED"<<endl;
						cin>>money;
						if(money>10)
						{
							cout<<endl;
							cout<<"Change - "<<money-10<<" AED"<<endl;
							cout<<"\n The book has been issued successfully"<<endl;
							cout<<endl;
							textcolor(BLACK+BLINK);
							textbackground(WHITE);
							gotoxy(21,13);
							cprintf(" Please return the book after 15 days ");
							textcolor(LIGHTGRAY);
							textbackground(BLACK);
						}
						else
						if(money<10)
						{
							cout<<endl;
							cout<<"You have not entered the correct amount"<<endl;
							cout<<endl;
							int money2,newmoney;
							newmoney=10-money;
							delay(1000);
							cout<<"Please deposit "<<newmoney<<" more"<<endl;
							cin>>money2;
							if((money+money2)==10)
							{
								cout<<"The book has been issued successfully"<<endl;
								cout<<endl;
								textcolor(BLACK+BLINK);
								textbackground(WHITE);
								gotoxy(21,13);
								cprintf(" Please return the book after 15 days ");
								textcolor(LIGHTGRAY);
								textbackground(BLACK);
							}
							else
							{
								cout<<"The amount entered is incorrect"<<endl;
								char simp;
								delay(500);
								clrscr();
								cout<<"\n\n\n\n Directing to main menu ";
								delay(2000);
								return;
							}
						}
						else
						if(money==10)
						{
							cout<<endl;
							cout<<"The book has been issued successfully"<<endl;
							cout<<endl;
							textcolor(BLACK+BLINK);
							textbackground(WHITE);
							gotoxy(21,13);
							cprintf(" Please return the book after 15 days ");
							textcolor(LIGHTGRAY);
							textbackground(BLACK);
							delay(2000);
						}
						cout<<endl;
						textcolor(BLACK+BLINK);
						textbackground(WHITE);
						cprintf(" NOTE! ");
						textcolor(LIGHTGRAY);
						textbackground(BLACK);
						cout<<endl;
						cout<<"Write current date in backside of book and submit within 15 days."<<endl;
						cout<<"A fine of Rs. 1 will be implemented for each day after the 15 day period"<<endl;
						getch();
					}
				}
				if(flag==0)
				cout<<"Book no does not exist";
			}
			else
				cout<<"Student has not returned the last book ";
		}
	}
	if(found==0)
	cout<<"Student record doesn't exist.";
	getch();
	f.close();
	f1.close();
}


void book_deposit()
{
	char sn[6],bn[6];
	int found=0,flag=0,day,fine,fine2;
	clrscr();
	cout<<"\n\nBOOK DEPOSIT ...";
	cout<<"\nEnter The student's admission no: ";
	cin>>sn;
	f.open("student.dat",ios::in|ios::out);
	f1.open("book.dat",ios::in|ios::out);
	while(f.read((char*)&st,sizeof(student)) && found==0)
	{
		if(strcmpi(st.retadmsnno(),sn)==0)
		{
			found=1;
			if(st.retbkstatus()==1)
			{
				while(f1.read((char*)&bk,sizeof(book))&& flag==0)
				{
					if(strcmpi(bk.retbno(),st.retstbno())==0)
					{
						bk.show_book();
						flag=1;
						cout<<"\nBook deposited in no. of days: ";
						cin>>day;
						if(day>15)
						{
							fine=(day-15)*1;
							cout<<"\nPlease Deposit a fine of Rs:"<<fine<<" : ";
							cin>>fine2;
							cout<<endl;
							if(fine2>fine)
							{
								cout<<endl;
								cout<<"Change - "<<fine2-fine<<" AED"<<endl;
								cout<<"\n\nBook deposited successfully";
								cout<<endl;
							}
							else
							if(fine2<fine)
							{
								cout<<endl;
								cout<<"You have not entered the correct amount"<<endl;
								cout<<endl;
								int money2,newmoney;
								newmoney=fine-fine2;
								delay(1000);
								cout<<"Please deposit "<<newmoney<<" more"<<endl;
								cin>>money2;
								if((fine2+money2)==fine)
								{
									cout<<endl;
									cout<<"\n\nBook deposited successfully";
								}
								else
								{
									cout<<"The amount entered is incorrect"<<endl;
									char simp;
									delay(500);
									clrscr();
									cout<<"\n\n\n\n Directing to main menu ";
									delay(2000);
									return;
								}
							}
							else
							if(fine2==fine)
							{
								cout<<endl;
								cout<<endl;
								cout<<"\n\nBook deposited successfully";
								delay(2000);
							}
						}
						st.bkreturned();
						int pos=-1*sizeof(st);
						f.seekp(pos,ios::cur);
						f.write((char*)&st,sizeof(student));
					}
				}
				if(flag==0)
					cout<<"Book no does not exist";
			}
			else
				cout<<"Student has not issued any book";
		}
	}
	if(found==0)
	cout<<"Student record does not exist...";
	getch();
	f.close();
	f1.close();
}



void intro()
{
	clrscr();
	int u;
	gotoxy(31,5);
	cout <<"Welcome to Project!";
	delay(400);
	textcolor(BLACK+BLINK);
	textbackground(WHITE);
	gotoxy(33,7);
	cprintf(" BOOK LIBRARY ");
	textcolor(LIGHTGRAY);
	textbackground(BLACK);
	gotoxy(15,10);
	delay(400);
	cout<<"This  project has the facility of maintaining records";
	gotoxy(30,11);
	delay(400);
	cout<<"of Books and Members";
	gotoxy(25,14);
	delay(400);
	cout<<"Designed by Yashit Maheshwary"<<endl;
	gotoxy(33,15);
	delay(400);
	cout<<"Class - XII A"<<endl;
	cout<<endl;
	cout<<endl;
	delay(400);
	cout<<"Press any key to continue"<<endl;
	getch();
}



void admin_menu()
{
	clrscr();
	int ch3;
	int found=0;
	char pass[4];
	cout<<"Enter the Administrator Password: ";
	for(int f=0;f<4;f++)
	{
		pass[f]=getch();
		cout<<"*";
	}
	if(strcmp(pass,"comp")==0)
	{
		cout<<"\n\n The password entered is correct"<<endl;
		delay(1000);
		cout<<"\n\nLoading.........."<<endl;
		delay(600);
		clrscr();
		cout<<"\n\n ADMINISTRATOR MENU";
		delay(200);
		cout<<"\n 1. Students Menu";
		delay(200);
		cout<<"\n 2. Books Menu";
		delay(200);
		cout<<"\n 3. Return to Main Menu";
		delay(200);
		cout<<"\n 4. Exit";
		delay(800);
		cout<<"\n\n\tPlease Enter Your Choice: ";
		ch3=getche();
		switch(ch3)
		{
			case '1': clrscr();
				stmenu();
				break;
			case '2': clrscr();
				bkmenu();
				break;
			case '3': return;
			case '4': end();
			default:cout<<"\n\n\n\nThere's no such choice!"<<endl;
				delay(500);
				cout<<"Redirecting back to Menu....";
				delay(500);
				cout<<"\a";
		}
	}
	else if(strcmp(pass,"comp")!=0)
	    {
		    cout<<"\n The password entered is incorrect"<<endl;
		    cout<<"\n\n\n\n\n\n Redirecting to Main menu...."<<endl;
		    delay(1500);
		    return;
	    }
}
void stmenu()
{
	clrscr();
	int ch2;
	cout<<"\n\nSTUDENTS MENU!"<<endl;
	delay(200);
	cout<<"\n 1. Create a new student record";
	delay(200);
	cout<<"\n 2. Display all student records";
	delay(200);
	cout<<"\n 3. Search for details of students";
	delay(200);
	cout<<"\n 4. Modify a student record";
	delay(200);
	cout<<"\n 5. Delete a record";
	delay(200);
	cout<<"\n 6. Delete all student records";
	delay(200);
	cout<<"\n 7. Return to previous Menu";
	delay(200);
	cout<<"\n 8. Return to Main menu";
	delay(200);
	cout<<"\n 9. Exit";
	delay(800);
	cout<<"\n\n\tPlease Enter Your Choice: ";
	cin>>ch2;
	switch(ch2)
	{
		case 1: clrscr();
			write_student();
			break;
		case 2: display_alls();
			break;
		case 3:
		{
			char num[6];
			int chc;
			clrscr();
			cout<<"\n\nSEARCH MENU!"<<endl;
			cout<<"\n1. Search using Admission Number";
			cout<<"\n2. Search using Student Name";
			cout<<"\n3. Return to previous Menu";
			cout<<"\n4. Return to Main menu";
			cout<<"\n5. Exit";
			cout<<"\n\n\tPlease enter your choice: ";
			cin>>chc;
			switch(chc)
			{
				case 1:
				{
					clrscr();
					cout<<"\n\n\tPlease Enter The Admission No. ";
					cin>>num;
					displays_num(num);
					break;
				}
				case 2:
				{
					clrscr();
					char stuname[30];
					cout<<"\n\n\t Please enter the student's name: ";
					cin>>stuname;
					displays_name(stuname);
					break;
				}
				case 3: admin_menu();
					break;
				case 4: return;
				case 5: end();
			}
			break;
		}
		case 4: modify_student();
			break;
		case 5: delete_student();
			break;
		case 6:
		{
			clrscr();
			delay(1000);
			cout<<"\n\nDeletion in Progress"<<endl;
			f.open("student.dat",ios::out | ios::trunc);
			f.close();
			delay(1000);
			cout<<"\n\n\n\nDeletion Complete"<<endl;
			delay(1000);
			break;
		}
		case 7: admin_menu();
			break;
		case 8: return;
		case 9: end();
		default: cout<<"\a";
	}
	stmenu();
}

void bkmenu()
{
	int bookcount;
	clrscr();
	int ch4;
	cout<<"\n\nBOOKS MENU!"<<endl;
	delay(200);
	cout<<"\n 1. Create a new book record";
	delay(200);
	cout<<"\n 2. Display all book records ";
	delay(200);
	cout<<"\n 3. Search for details of books";
	delay(200);
	cout<<"\n 4. Modify a book record";
	delay(200);
	cout<<"\n 5. Delete a book record";
	delay(200);
	cout<<"\n 6. Delete all book records";
	delay(200);
	cout<<"\n 7. Return to previous Menu";
	delay(200);
	cout<<"\n 8. Return to the main menu";
	delay(200);
	cout<<"\n 9. Exit";
	delay(800);
	cout<<"\n\n\tPlease Enter Your Choice: ";
	cin>>ch4;
	switch(ch4)
	{
		case 1: clrscr();
			write_book();
			break;
		case 2: display_allb();
			  break;
		case 3:
		{
			char num[6];
			int chc;
			clrscr();
			cout<<"\n\nSEARCH MENU!"<<endl;
			cout<<"\n1. Search using Book Number";
			cout<<"\n2. Search using Book Name";
			cout<<"\n3. Search using Author Name";
			cout<<"\n4. Search using cost";
			cout<<"\n5. Return to previous Menu";
			cout<<"\n6. Return to Main menu";
			cout<<"\n7. Exit";
			cout<<"\n\n\tPlease enter your choice: ";
			cin>>chc;
			switch(chc)
			{
				case 1:
				{
					char num[10];
					clrscr();
					cout<<"\n\n\tPlease Enter The Book No. ";
					cin>>num;
					displayb_num(num);
					break;
				}
				case 2:
				{
					clrscr();
					char bkname[30];
					cout<<"\n\n\tPlease enter the Book's name: ";
					cin>>bkname;
					displayb_name(bkname);
					break;
				}
				case 3:
				{
					clrscr();
					char athname[30];
					cout<<"\n\n\tPlease enter the Author's name: ";
					cin>>athname;
					displayb_aname(athname);
					break;
				}
				case 4:
				{
					clrscr();
					char llmt[30],ulmt[30];
					cout<<"\n\n\tPlease enter the lower limit: ";
					cin>>llmt;
					cout<<"\tPlease enter the upper limit: ";
					cin>>ulmt;
					displayb_cost(llmt,ulmt);
					break;
				}
				case 5: admin_menu();
					break;
				case 6: return;
				case 7: end();
			}
			break;
		}
		case 4: modify_book();
			break;
		case 5: delete_book();
			 break;
		case 6:
		{
			clrscr();
			delay(1000);
			cout<<"\n\nDeletion in progress"<<endl;
			f.open("book.dat",ios::out | ios::trunc);
			f.close();
			delay(1000);
			cout<<"\n\n\n\nDeletion Complete"<<endl;
			delay(1000);
			break;
		}
		case 7: admin_menu();
			break;
		case 8: return;
		case 9: end();
		default: cout<<"\a";
	}
	bkmenu();
}


void main()
{
	char ch;
	intro();
	do
	{
		clrscr();
		cout<<"\n\n MAIN MENU";
		delay(400);
		cout<<"\n 1. Issue a book";
		delay(400);
		cout<<"\n 2. Return a book";
		delay(400);
		cout<<"\n 3. Administrator Menu";
		delay(400);
		cout<<"\n 4. Exit";
		delay(1000);
		cout<<"\n\n Please Select Your Option: ";
		ch=getche();
		switch(ch)
		{
			case '1':clrscr();
				 book_issue();
				 break;
			case '2':book_deposit();
				 break;
			case '3':admin_menu();
				 break;
			case '4':end();
			default :cout<<"\a";
		}
		f.close();
	}while(ch!='4');
}


void end()
{
	clrscr();
	int u;
	delay(400);
	textcolor(BLACK+BLINK);
	textbackground(WHITE);
	gotoxy(33,13);
	cprintf(" THANK YOU! ");
	textcolor(LIGHTGRAY);
	textbackground(BLACK);
	delay(400);
	cout<<"\n\n\n\n\n\n Press any key to exit"<<endl;
	getch();
	exit(0);
}



