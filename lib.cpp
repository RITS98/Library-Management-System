//*********************************HEADER FILES****************************
//*************************************************************************
//*************************************************************************

#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<stdio.h>
#include<process.h>
#include<string>
#include<iomanip>
#include<stdlib.h>
#include<time.h>
#include<direct.h>
#include<windows.h>
#include<conio.h>
using namespace std;

//*****************************CLASS********************************
//*******************************************************************


//******************** BOOK ***********************
class book
{
    public:
	string bno,bname,aname,genre,publisher,isbno;
	string year;
    public:
        book(string bno,string bname,string aname,string genre,string publisher,string year,string isbno)
        {
            this->bno=bno;
            this->bname=bname;
            this->aname=aname;
            this->genre=genre;
            this->publisher=publisher;
            this->isbno=isbno;
            this->year=year;
        }
        book()
        {

        }
    public:
	void show_book()
    {
        cout<<"\nBook no. : "<<bno;
        cout<<"\nBook Name : ";
        cout<<bname<<endl;
        cout<<"Author Name : ";
        cout<<aname<<endl;
        cout<<"Publisher : "<<publisher<<endl;
        cout<<"Genre : "<<genre<<endl;
        cout<<"Year of Publication: "<<year<<endl;
        cout<<"ISBN : "<<isbno<<endl;
        return;
    }
    void report()
    {
        cout<<bno<<setw(30)<<bname<<setw(30)<<aname<<endl;
        return;
    }
};         //class ends here


//*********************** STUDENT *********************
class student
{
    public:
        string admno,name,stbno;
    public:
        student(string admno,string name,string stbno)
        {
            this->admno=admno;
            this->name=name;
            this->stbno=stbno;
        }
        student()
        {

        }

    void show_student()
    {
        cout<<"\nAdmission no. :  "<<admno;
        cout<<"\nStudent Name :  ";
        cout<<name;
        cout<<"\nBook Taken :  "<<stbno;
    }

    void report()
    {
        cout<<"\t"<<admno<<setw(20)<<name<<setw(10)<<stbno<<endl;
    }

};         //class ends here





//************************ LINKED LIST **********************************
//***********************************************************************
//***********************************************************************
class BookNode
{
    public:
    book data;
    BookNode *node;
};
BookNode* head=NULL;
BOOL gotoxy(const WORD x, const WORD y);

void append(BookNode** head_ref, book obj)
{
    /* 1. allocate node */
    BookNode* new_node = new BookNode();

    BookNode *last = *head_ref; /* used in step 5*/

    /* 2. put in the data */
    new_node->data = obj;

    /* 3. This new node is going to be
    the last node, so make next of
    it as NULL*/
    new_node->node = NULL;

    /* 4. If the Linked List is empty,
    then make the new node as head */
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->node != NULL)
        last = last->node;

    /* 6. Change the next of last node */
    last->node = new_node;
    return;
}
void deleteList(BookNode** head_ref)
{
	/* deref head_ref to get the real head */
	BookNode* current = *head_ref;
	BookNode* next;

	while (current != NULL)
	{
	    next = current->node;
	    free(current);
	    current = next;
	}
	/* deref head_ref to affect the real head back
	    in the caller. */
	*head_ref = NULL;
}
void modifyLL(BookNode** head,string bno,string bname,string aname,string genre,string publisher,string year,string isbno)
{
    int count=0;
    BookNode*current=*head;
    while(current!=NULL)
    {

        book ob=current->data;
        if(ob.bno==bno)
        {
            count=1;
            ob.bname=bname;
            ob.aname=aname;
            ob.genre=genre;
            ob.publisher=publisher;
            ob.year=year;
            ob.isbno=isbno;
            current->data=ob;
            break;
        }
        current=current->node;
    }
    if(count==0)
        cout<<"\nNo such book found in the database\n"<<endl;
    else
        cout<<"\nBook is modified and saved"<<endl;
    getch();
}

int searchBook(BookNode** head,string name)
{
    int flag=0;
    BookNode *current=*head;
    while(current!=NULL)
    {
        book ob=current->data;
        if(ob.bname==name)
        {
            flag=1;
            ob.show_book();
            break;
        }
        current=current->node;
    }
    if(flag==0)
    {
        cout<<"\nThe book is not in the Library or Put correct book name or ISBN\n";
        getch();
        return 0;
    }
    else
    {
        cout<<"\nBook Found "<<endl;
        getch();
        return 1;
    }

}
void searchAuthor(BookNode** head,string name)
{
    cout<<"************Author's Name : "<<name<<"  ********************"<<endl;
    int flag=0;
    BookNode *current=*head;
    while(current!=NULL)
    {
        book ob=current->data;
        if(ob.aname==name)
        {
            flag=1;
            ob.show_book();

            cout<<endl<<"******************************"<<endl;
        }
        current=current->node;

    }
    if(flag==0)
        cout<<"\nThe author's name is incorrect";
    getch();

}
void searchISBN(BookNode** head,string ISBN)
{
    int flag=0;
    cout<<"*********************** Book Details *************************";
    BookNode *current=*head;
    while(current!=NULL)
    {
        book ob=current->data;
        if(ob.isbno==ISBN)
        {
            flag=1;
            ob.show_book();
            break;
        }
        current=current->node;
    }
    if(flag==0)
        cout<<"\nThe book is not in the Library or Put correct name or ISBN\n";
    getch();
}
void deleteBook(BookNode **head_ref, string name)
{
    int flag=0;
   if (*head_ref == NULL)
      return;

    BookNode* temp = *head_ref;

    for (int i=0; temp!=NULL; i++)
    {
        book ob=temp->data;
        if(i==0 && ob.bname==name)
        {
            flag=1;
            cout<<"\nBook deleted"<<endl;
            *head_ref=temp->node;
            free(temp);
            return;
        }
        else if(ob.bname==name)
        {
            flag=1;
            cout<<"\nBook deleted"<<endl;
            BookNode* node=temp->node->node;
            free(temp->node);
            temp->node=node;
            return;

        }
        temp = temp->node;
    }
    if(flag==0)
        cout<<"\nThe book is not in the library"<<endl;
    getch();
    return;
}
void searchFiction(BookNode** head,string fiction)
{
    int flag=0;
    cout<<"*********************Genre : "<<fiction<<" ***************************";
    BookNode *current=*head;
    while(current!=NULL)
    {
        book obj=current->data;
        if(obj.genre==fiction)
        {
            flag=1;
            obj.show_book();
        }
        current=current->node;
    }
    if(flag==0)
        cout<<"\nNo such books are available!!"<<endl;
    getch();
}
void searchPublisher(BookNode** head,string pub)
{
    int flag=0;
    cout<<"*********************Publisher : "<<pub<<" ***************************";
    BookNode *current=*head;
    while(current!=NULL)
    {
        book obj=current->data;
        if(obj.publisher==pub)
        {
            flag=1;
            obj.show_book();
            cout<<"\n\n***************************************************\n\n";
        }
        current=current->node;
    }
    if(flag==0)
        cout<<"\nNo such publisher is available!!"<<endl;
    getch();
}
void searchYear(BookNode** head,string year )
{
    int flag=0;
    cout<<"************** Year of Publication :"<<year<<" ****************************"<<endl;
    BookNode* current=*head;
    while(current!=NULL)
    {
        book obj=current->data;
        if(obj.year==year)
        {
            flag=1;
            obj.show_book();
            cout<<"********************************************"<<endl;
        }
        current=current->node;
    }
    if(flag==0)
        cout<<"\nNo books found ";
    getch();
}
void countBooks(BookNode** temp1)
{
    system("CLS");
    cout<<"**************  BOOK COUNT **************************\n\n";
    int count=0;
    int arr[10]={0};
    BookNode *temp=*temp1;
    while(temp!=NULL)
    {
        count++;
        book obj=temp->data;
        string gen=obj.genre;

        if(gen=="Thriller")
            arr[0]++;
        else if(gen=="Romantic")
            arr[1]++;
        else if(gen=="Adventurous")
            arr[2]++;
        else if(gen=="Sci-Fi")
            arr[3]++;
        else if(gen=="Comedy")
            arr[4]++;
        else if(gen=="Historical")
            arr[5]++;
        else if(gen=="Biography")
            arr[6]++;
        else if(gen=="Traveling")
            arr[7]++;
        else if(gen=="Scientific")
            arr[8]++;
        else if(gen=="Educational")
            arr[9]++;

        temp=temp->node;
    }
    cout<<"\tTotal No. of books -> "<<count<<endl;
    cout<<"\tThriller Books  -> "<<arr[0]<<endl;
    cout<<"\tRomantic Books  -> "<<arr[1]<<endl;
    cout<<"\tAdventurous Books  -> "<<arr[2]<<endl;
    cout<<"\tSci-Fi Books  -> "<<arr[3]<<endl;
    cout<<"\tComedy Books  -> "<<arr[4]<<endl;
    cout<<"\tHistorical Books  -> "<<arr[5]<<endl;
    cout<<"\tBiography Books  -> "<<arr[6]<<endl;
    cout<<"\tTraveling Books  -> "<<arr[7]<<endl;
    cout<<"\tScientific Books  -> "<<arr[8]<<endl;
    getch();

}
void listAllBook(BookNode** head)
{
    int flag=0;
    system("CLS");
    cout<<"Sr. No.-\t-Title-  \t  -Author's Name-   \t   -Genre-\t-Publisher-\t-Year-\t -ISBN"<<endl<<endl;
    BookNode *current=*head;
    while(current!=NULL)
    {
        flag=1;
        book obj=current->data;
        cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
        cout<<"-"<<obj.bno<<"-\t-"<<obj.bname<<"-\t-"<<obj.aname<<"-\t-"<<obj.genre<<"-\t-"<<obj.publisher<<"-\t-"<<obj.year<<"-\t-"<<obj.isbno<<"-"<<endl;
        current=current->node;
    }
    if(flag==0)
        cout<<"No records found"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------"<<endl;
    getch();
}





//****************************************** FILE BOOK FUNCTION *************************************
//***************************************************************************
//**************************************************************************
void writeBookFile(string bno,string bname,string aname,string genre,string publisher,string year,string isbno)
{
    fstream fout;
    fout.open("book.csv",ios::out|ios::app);
    fout<<bno<<","<<bname<<","<<aname<<","<<genre<<","<<publisher<<","<<year<<","<<isbno<<endl;
    fout.close();
}
void create_book()
{
    string bno,bname,aname,genre,publisher,year,isbno;
    char ch;
    cout<<"\nNEW BOOK ENTRY...\n";
    cout<<"\nEnter The book no. ->\t  ";
    cin.ignore();
    getline(cin,bno,'\n');
    cout<<"\nEnter The Name of The Book ->\t  ";
    getline(cin,bname,'\n');
    cout<<"\nEnter The Author's Name ->\t  ";
    getline(cin,aname,'\n');
    cout<<"\nEnter the Genre of the book ->\t ";
    getline(cin,genre,'\n');
    cout << "\nEnter Publisher Name -> \t";
    getline(cin,publisher, '\n');
    cout << "\nEnter Year of Publication:\t";
    cin>>year;
    cout << "\nEnter the ISBN -> \t";
    cin.ignore();
    getline(cin, isbno, '\n');
    cout<<"\n\n\nBook Created....Congratulation";
    cout<<"\n\nDo you want to see what you have just entered?(Y/n)";
    cin>>ch;
    if(ch=='Y'||ch=='y')
    {
        book ob(bno,bname,aname,genre,publisher,year,isbno);
        ob.show_book();
        getch();
    }
    writeBookFile(bno,bname,aname,genre,publisher,year,isbno);
    return;
}

void readBookFile()
{
    fstream fin;
    fin.open("book.csv",ios::in);
    if(!fin)
    {
       return;
    }

    vector<string> row;
    string line, word, temp;

    while (fin.good())
	{
        row.clear();
        // read an entire row and store it in a string variable 'line'
        getline(fin, line);
        // used for breaking words
        stringstream s(line);
        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s,word,','))
		{
        	row.push_back(word);
        }
  		book obj(row[0],row[1],row[2],row[3],row[4],row[5],row[6]);
  		append(&head,obj);

    }
}
void modifyBookFile(string bno,string bname,string aname,string genre,string publisher,string year,string isbno)
{
    fstream fin,fout;
    fin.open("book.csv",ios::in);
    fout.open("booknew.csv",ios::out|ios::app);
    vector<string> row;
    string line,word,temp;
    while(fin.good())
    {
        row.clear();
        // read an entire row and store it in a string variable 'line'
        getline(fin, line);
        // used for breaking words
        stringstream s(line);
        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s,word,','))
        {
            row.push_back(word);
        }
        if(row[0]==bno)
            fout<<bno<<","<<bname<<","<<aname<<","<<genre<<","<<publisher<<","<<year<<","<<isbno<<endl;
        else
            fout<<line<<endl;
    }
    fin.close();
    fout.close();
    remove("book.csv");
    rename("booknew.csv","book.csv");

}
void modify_book()
{
    string bno,bname,aname,genre,publisher,year,isbno;
    cout<<"\nBook no. :  ";
    cin.ignore();
    getline(cin,bno,'\n');
    cout<<"\nModify Book Name :  ";
    getline(cin,bname,'\n');
    cout<<"\nModify Author's Name of Book :  ";
    getline(cin,aname,'\n');
    cout<<"\nModify Publisher's Name : ";
    getline(cin,publisher,'\n');
    cout<<"\nModify Genre : ";
    getline(cin,genre,'\n');
    cout<<"\nModify Year of publication : ";
    getline(cin,year,'\n');
    cout<<"\nModify ISBN : ";
    getline(cin,isbno,'\n');
    modifyLL(&head,bno,bname,aname,genre,publisher,year,isbno);
    modifyBookFile(bno,bname,aname,genre,publisher,year,isbno);
    return ;
}

void delete_book(string n)
{
    int flag=0;
    fstream fin,fout;
    cout<<"\n\n\n\tDELETE BOOK ...";
    fin.open("book.csv",ios::in);
    fout.open("Temp.csv",ios::out|ios::app);
    vector<string> row;
    string line,word;
    while(fin.good())
    {
        row.clear();
        // read an entire row and store it in a string variable //'line'
        getline(fin, line);
        // used for breaking words
        stringstream s(line);
        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s,word,','))
		{
        	row.push_back(word);
        }
  		if(row[1]==n)
        {
            flag=1;
            searchBook(&head,n);
            cout<<"\n\nDo you want to delete the book? (Y/n) ";
            char c;
            cin>>c;
            if(c=='Y'||c=='y')
            continue;
            else
                fout<<line<<endl;
        }
        else
            fout<<line<<endl;
    }


    fin.close();
    fout.close();
    remove("book.csv");
    rename("Temp.csv","book.csv");

    if(flag==0)
        cout<<"\n\n\tNo such record found";
    else
        cout<<"\n\n\tRecord Deleted ..";
    getch();
    return;
}



//************************* File Student Function *******************
//*******************************************************************

void write_student(string admno,string name,string stbno)
{
    fstream fout;
    fout.open("student.csv",ios::out|ios::app);
    fout<<admno<<","<<name<<","<<stbno<<endl;
    fout.close();
}
void create_student()
{
    int token;
    string admno,name,stbno;
    system("CLS");
    cout<<"\nNEW STUDENT ENTRY...\n";
    cout<<"\nEnter The admission no. -> \t";
    cin.ignore();
    getline(cin,admno,'\n');
    cout<<"\n\nEnter The Name of The Student ->\t";
    getline(cin,name,'\n');
    token=0;
    stbno="0";
    cout<<"\n\nStudent Record Created.. Congratulations";
    char ch;
    cout<<"\n\nDo you want to see what you have just entered? (Y/n)";
    cin>>ch;
    if(ch=='Y'||ch=='y')
    {
        student ob(admno,name,stbno);
        ob.show_student();
        getch();
    }
    write_student(admno,name,stbno);

}

void modifystudentFile(string name)
{
    int flag=0;
    fstream fout,fin;
    fin.open("student.csv",ios::in);
    fout.open("temp.csv",ios::out|ios::app);
    vector<string> row;
    string line,word,temp;
    while(fin.good())
    {
        row.clear();
        getline(fin, line);
        stringstream s(line);
        while (getline(s,word,','))
		{
        	row.push_back(word);
        }
  		if(row[0]==name)
         {
             flag=1;
             cout<<"\nEnter new name of the student : ";
             string name;
             cin.ignore();
             getline(cin,name);
             fout<<row[0]<<","<<name<<","<<row[2]<<endl;
         }
        else
            fout<<line<<endl;
    }
    fin.close();
    fout.close();
    remove("student.csv");
    rename("temp.csv","student.csv");

    if(flag==0)
        cout<<"\nNo such record found"<<endl;
    else
        cout<<"\nRecord modified..."<<endl;
    getch();
}
 void modify_student()
{
    system("CLS");
    string admno,name;
    cout<<"\nAdmission no. : "<<admno;
    cin>>admno;
    modifystudentFile(admno);
    return;
}

void display_sps(string n)
{
    int flag=0;
    fstream fin;
    cout<<"\nSTUDENT DETAILS\n";
    fin.open("student.csv",ios::in);
    vector<string> row;
    string line,word,temp;
    while(fin.good())
    {
        row.clear();
        getline(fin,line);
        stringstream s(line);
        while(getline(s,word,','))
            row.push_back(word);
        if(row[0]==n)
        {
            flag=1;
            student ob(row[0],row[1],row[2]);
            ob.show_student();
        }
    }
    cout<<"\n**********************************\n"<<endl;
    fin.close();
    if(flag==0)
            cout<<"\n\nStudent does not exist";
    getch();
    return;
}
void display_alls()
{
    int count=0;
    fstream fin;
    system("CLS");
    fin.open("student.csv",ios::in);
    if(!fin)
    {
        cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
        getch();
        return;
    }

    cout<<"\n\n\t\tSTUDENT LIST\n\n";
    cout<<"==================================================================\n";
    cout<<"\tAdmission No."<<setw(10)<<"Name"<<setw(20)<<"Book Issued\n";
    cout<<"==================================================================\n";
    vector<string> row;
    string line,word,temp;
    while(fin)
    {
        row.clear();
        getline(fin,line);
        stringstream s(line);
        while(getline(s,word,','))
            row.push_back(word);
        student ob(row[0],row[1],row[2]);
        ob.report();
        count++;
    }
    cout<<endl<<count<<endl;
    getch();
    fin.close();

    return;
}
void delete_student()
{
    int flag=0;
    fstream fin,fout;
    system("CLS");
    string ad;
    cout<<"Enter the registration number of student : ";
    cin>>ad;
    fin.open("student.csv",ios::in);
    fout.open("temp.csv",ios::out|ios::app);
    vector<string> row;
    string line,word;
    while(fin.good())
    {
        row.clear();
        getline(fin,line);
        stringstream s(line);
        while(getline(s,word,','))
        {
            row.push_back(word);
        }
        if(row[0]==ad)
        {
            flag=1;
            char ch;
            student ob(row[0],row[1],row[2]);
            ob.show_student();
            cout<<"\n\n Are you sure you want to delete the above record ? (Y/n)"<<endl;
            cin>>ch;
            if(ch=='Y'||ch=='y')
                continue;
            else
                fout<<row[0]<<", "<<row[1]<<", "<<row[2]<<endl;
        }
        else
            fout<<line<<endl;
    }
    fin.close();
    fout.close();
    if(flag==0)
        cout<<"\nNo such record found ... "<<endl;
    else
        cout<<"Operation completed ..."<<endl;
    remove("student.csv");
    rename("temp.csv","student.csv");

    getch();
    return;
}


//**************************** LINKED LIST (STUDENT) ************
//***************************************************************
class StuNode
{
public:
    student data;
    StuNode *next;
};

StuNode *top=NULL;
void studentAppend(StuNode** head_ref, student obj)
{
    /* 1. allocate node */
    StuNode* newnode = new StuNode();

    StuNode *last = *head_ref; /* used in step 5*/

    /* 2. put in the data */
    newnode->data = obj;

    /* 3. This new node is going to be
    the last node, so make next of
    it as NULL*/
    newnode->next = NULL;

    /* 4. If the Linked List is empty,
    then make the new node as head */
    if (*head_ref == NULL)
    {
        *head_ref = newnode;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = newnode;
    return;
}
void deleteStudentList(StuNode** head_ref)
{
	/* deref head_ref to get the real head */
	StuNode* current = *head_ref;
	StuNode* temp;

	while (current != NULL)
	{
	    temp = current->next;
	    free(current);
	    current = temp;
	}
	/* deref head_ref to affect the real head back
	    in the caller. */
	*head_ref = NULL;
}
void readStudentFile()
{
    fstream fin;
    fin.open("student.csv",ios::in);
    if(!fin)
    {
       return;
    }

    vector<string> row;
    string line, word, temp;

    while (fin.good())
	{
        row.clear();
        // read an entire row and store it in a string variable 'line'
        getline(fin, line);
        // used for breaking words
        stringstream s(line);
        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s,word,','))
		{
        	row.push_back(word);
        }
  		student obj(row[0],row[1],row[2]);
  		studentAppend(&top,obj);

    }
    fin.close();
}
int searchStudent(StuNode** top,string admno)
{
    int token=0;
    int flag=0;
    StuNode *current=*top;
    while(current!=NULL)
    {
        student ob=current->data;
        if(ob.admno==admno)
        {
            flag=1;
            ob.show_student();
            if(ob.stbno=="0")
                token=2;
            else
                token=3;
            break;
        }
        current=current->next;
    }
    gotoxy(16,6);
    if(flag==0)
    {
        cout<<"\nStudent Record not Found";
        getch();
        return 0;
    }
    else
    {
        cout<<"\nStudent Found"<<endl;
        getch();
        return token;
    }

}
void modifyStuFile(string admno,int t)
{
    fstream fin,fout;
    fin.open("student.csv",ios::in);
    fout.open("studentnew.csv",ios::out|ios::app);
    vector<string> row;
    string line,word;
    while(fin)
    {
        row.clear();
        getline(fin,line);
        stringstream s(line);
        while(getline(s,word,','))
        {
            row.push_back(word);
        }
        if(row[0]==admno)
            fout<<row[0]<<","<<row[1]<<","<<t<<endl;
        else
            fout<<line<<endl;
    }
    fin.close();
    fout.close();
    remove("student.csv");
    rename("studentnew.csv","student.csv");

    return;
}
//*********************************************
//                  BOOK ISSUE
//*********************************************

void book_issue()
{
    system("CLS");
    cout<<"Enter student register no. ";
    string admno;
    cin>>admno;
    int sig=searchStudent(&top,admno);
    cout<<endl<<sig<<endl;
    if(sig==2)
    {
        cout<<"Enter name of the book : ";
        string name;
        cin.ignore();
        getline(cin,name);
        if(searchBook(&head,name))
        {
            modifyStuFile(admno,1);
            cout<<"\nBook Issued ... "<<endl;
            cout<<"\nPlease Note: Write current date in backside of book \n submit within 15 days fine Rs. 2 for each day after 15 days period"<<endl;
        }
    }
    else if(sig==3)
    {
        cout<<"Please return the last book to issue a new book"<<endl;
    }
    else
    {
        cout<<"No such student record found"<<endl;
    }
    getch();
    return;
}

//**********************************************
//              BOOK DEPOSIT
//**********************************************

void book_deposit()
{
    system("CLS");
    string name;
    cout<<"Enter student register no. ";
    string admno;
    cin>>admno;
    int sig=searchStudent(&top,admno);
    if(sig==3)
    {
        cout<<"Book Deposited "<<endl;
        modifyStuFile(admno,0);
        cout<<"No. of days for which  the book issued : ";
        int days;
        cin>>days;
        if(days>15)
        {
            int fine=(days-15)*2;
            cout<<"\nFine for each day is Rs. 2 "<<endl;
            cout<<"Total fine : "<<fine;
        }

    }
    else if(sig==2)
    {
        cout<<"You haven't issued any book"<<endl;
    }
    else
    {
        cout<<"No such student record found"<<endl;
    }
    getch();
    return;
}






//***************************************************************
//        INTRODUCTION FUNCTION
//****************************************************************
BOOL gotoxy(const WORD x, const WORD y)
{
    COORD xy;
    xy.X=x;
    xy.Y=y;
    return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),xy);
}
void intro()
{
    system("CLS");
    gotoxy(32,11);
    cout<<"LIBRARY MANAGEMENT SYSTEM";
    cout<<"\n\nMADE BY : RITAYAN PATRA (18BEC0170)\n\tARIN PAUL (18BEC0172)\n\tMD AYAZ HAQUE (18BEC0556)";
    cout<<"\n\nCOLLEGE : VIT University, Vellore - 632014";
    return;
}
void delay(int number_of_seconds)
{
    int milli_seconds = 1000 * number_of_seconds;

    clock_t start_time = clock();
     while (clock() < start_time + milli_seconds);
}






//********************************************** MENU *********************************************
//*************************************************************************************************
//*************************************************************************************************

void book_menu()
{
    readBookFile();
    string nameb,n,na,au,ge,isb;
    string y;
    system("CLS");
    int sw;
    cout<<"\n\n\n\tBOOK MENU";
    cout<<"\n\n\t1. CREATE BOOK ";
    cout<<"\n\n\t2. DISPLAY ALL BOOKS ";
    cout<<"\n\n\t3. DISPLAY SPECIFIC BOOK ";
    cout<<"\n\n\t4. MODIFY BOOK ";
    cout<<"\n\n\t5. DELETE BOOK ";
    cout<<"\n\n\t6. SEARCH BOOK BY GENRE ";
    cout<<"\n\n\t7. SEARCH BOOK BY AUTHOR ";
    cout<<"\n\n\t8. SEARCH BOOK BY PUBLISHER ";
    cout<<"\n\n\t9. SEARCH BOOK BY YEAR ";
    cout<<"\n\n\t10. SEARCH BOOK BY ISBN ";
    cout<<"\n\n\t11. TOTAL NO. OF BOOKS? ";
    cout<<"\n\n\t12. BACK TO ADMIN MENU";
    cout<<"\n\n\tPlease Enter Your Choice (1-10) ";
    cin>>sw;
    switch(sw)
    {
        case 1:{
            system("CLS");
            create_book();
            break;
            }
        case 2:{
            listAllBook(&head);
            break;
            }
        case 3:{
            string nameb;
            system("CLS");
            cout<<"Enter name of the book : ";
            cin.ignore();
            getline(cin,nameb,'\n');
            searchBook(&head,nameb);
            break;
            }
        case 4:{
            system("CLS");
            book o;
            modify_book();
            break;
            }
        case 5:{
            system("CLS");
            cout<<"Enter the Book Name : ";
            cin.ignore();
            getline(cin,na);
            deleteBook(&head,na);
            delete_book(na);break;
            }
        case 6:{
            system("CLS");
            cout<<"Enter the genre : ";
            cin>>ge;
            searchFiction(&head,ge);
            break;
            }
        case 7:{
            system("CLS");
            cout<<"Enter author's name : ";
            cin.ignore();
            getline(cin,au);
            searchAuthor(&head,au);
            break;
            }
        case 8:{
            system("CLS");
            cout<<"Enter Publisher's name : ";
            string pub;
            cin.ignore();
            getline(cin,pub);
            searchPublisher(&head,pub);
            break;
            }
        case 9:{
            system("CLS");
            cout<<"Enter year of publication : ";
            cin>>y;
            searchYear(&head,y);
            break;
            }
        case 10: {
            system("CLS");
            cout<<"Enter the ISBN: ";
            cin>>isb;
            searchISBN(&head,isb);
            break;
            }
        case 11: {
            countBooks(&head);
            break;
            }
        case 12: return;
        default:cout<<"\a";
    }
    deleteList(&head);
    book_menu();
}
void admin_menu()
{
    readStudentFile();
    string num;
    system("CLS");
    int ch2;
    cout<<"\n\n\n\tADMINISTRATOR MENU";
    cout<<"\n\n\t1. CREATE STUDENT RECORD";
    cout<<"\n\n\t2. DISPLAY ALL STUDENTS RECORD";
    cout<<"\n\n\t3. DISPLAY SPECIFIC STUDENT RECORD ";
    cout<<"\n\n\t4. MODIFY STUDENT RECORD";
    cout<<"\n\n\t5. DELETE STUDENT RECORD";
    cout<<"\n\n\t6. BOOK MENU";
    cout<<"\n\n\t7. BACK TO MAIN MENU";
    cout<<"\n\n\tPlease Enter Your Choice (1-6) ";
    cin>>ch2;
    switch(ch2)
    {
            case 1:{
                system("CLS");
                create_student();
                break;
                }
            case 2: {
                display_alls();
                break;
                }
            case 3:{
                system("CLS");
                cout<<"\n\n\tPlease Enter The Admission No. : ";
                cin>>num;
                display_sps(num);
                break;
                }
            case 4:{
                modify_student();
                break;
                }
            case 5: {
                delete_student();
                break;
                }
        case 6: {
            system("CLS");
            book_menu();
            break;
            }
        case 7: {
            return;
            }
        default:cout<<"\a";
    }
    deleteStudentList(&top);
    admin_menu();
}


//***************************************************************
//        THE MAIN FUNCTION OF PROGRAM
//****************************************************************


int main()
{
    int ch;
    intro();
    delay(2);
    do
    {
        system("CLS");
        cout<<"\n\n\n\tMAIN MENU";
        cout<<"\n\n\t01. BOOK ISSUE";
        cout<<"\n\n\t02. BOOK DEPOSIT";
        cout<<"\n\n\t03. ADMINISTRATOR MENU";
        cout<<"\n\n\t04. EXIT";
        cout<<"\n\n\tPlease Select Your Option (1-4) ";
        cin>>ch;
        switch(ch)
        {
            case 1:system("CLS");
                book_issue();
                break;
            case 2:book_deposit();
                    break;
            case 3:admin_menu();
                break;
            case 4:exit(0);
                    break;
            default :cout<<"Please enter Correct input";
            continue;

        }
    }while(ch!='4');
        return 0;
}
