#include <iostream>
#include<string>
#include<stdlib.h>
#include<fstream>
#include<cstring>
#include<sstream>
#include<ctime>
#include<string.h>
#include <cstdio>
#include <iomanip>
#include<bits/stdc++.h>
#include<regex>
using namespace std;
#define MAX 200

int i=0,j=0,k1,k2,k3,k4,k=0,m=0,t=0;
string users[MAX];
string passw[MAX];
int stud[MAX];
int bok[MAX];
int prof[MAX];
string cho;
string lineu,linep,lines,temp,temp1;
class login
{
private:
  string user;
  string pass;
public:
  int check();
  string regis();
  void disp();
  void change_pass();
  void exit();
  void append();
  int initial();
};
class book
{
private:
    int number;
string book_name;
 string auth; 
int book_ed;
public:
    void add_book();
    void list_ofall();
    void due_details();
    void check_in();
    void check_out();
    void date_enroll();
    void reset_enroll();
};
void book :: add_book()
{
  cout<<"----------------------"<<endl;
  cout<<"enter the title without spaces (for " " use underscore in this format) of book: ";
  cin>>book_name;
  cout<<"enter the name  without spaces (for " " use underscore in this format) of author";
  cin>>auth;
  
  cout<<"Enter the number of ISBN: ";
  cin>>book_ed;
  cout<<"----------------------"<<endl;
  fstream bookfile("book.txt",ios::app);
  bookfile<<book_name<<" ";
  bookfile<<auth<<" ";
  bookfile<<book_ed<<endl;
  bok[t]=book_ed;
  bookfile.close();
  t=t+1;
}
/// Printing all books 
void book :: list_ofall()
{
  cout<<"----------------------"<<endl;
  string al("");
  string alpha("");
  string num("");
  fstream bookfile("book.txt",ios::in);
  string temp;
  int u=0;
  while(getline(bookfile,temp))
  {
    for (int i=0; i<temp.length(); i++)
    {

      if((temp[i] >= 'A' && temp[i] <= 'Z') ||
              (temp[i] >= 'a' && temp[i] <= 'z') ||(temp=="_"))
      {
          alpha=alpha+temp[i];

      }
      if(temp[i]==' '){
        u=u+1;
      }
  
      if(((temp[i] >= 'A' && temp[i] <= 'Z') ||
              (temp[i] >= 'a' && temp[i] <= 'z') ||(temp=="_"))&&u==1)
      {
          al=al+temp[i];

      }
      if (isdigit(temp[i]))
      {
        num=num+temp[i];

      }
    }
    cout<<"book title: "<<alpha <<"---";
    cout<<"book author: "<<al<<"---";
    
    cout<<"ISBN number: "<<num << endl;
    num="";
    alpha="";
    al="";

  }
  cout<<"----------------------"<<endl;
  bookfile.close();
}
class student
{
private:
    string stu_name;
    int stu_id;
public:
    void add_stu();
    int edit_stu();
    void view_det(int w);
    void list_ofall();
    int initial();
};
class professor
{
private:
    string prof_name;
    int prof_id;
public:
    void add_prof();
    int edit_prof();
    void view_det(int w);
    void list_ofall();
    int initial();
};
/// Check out of book (issuing the book)
void book :: check_out()
{
  string book;
  fstream booklist("book.txt",ios::app | ios::out);
  cout<<"----------------------"<<endl;
  cout<<"Enter the number books to be issued: ";
  cin>>number;
  int i=0;
  cin.ignore();
  time_t tt;
  struct tm * ti;
  time (&tt);
  ti = localtime(&tt);
  cout<<"----------------------"<<endl;
  cout << "Issue Day, Date and Time is: " <<endl;
  cout<<"Day Month Date Time Year"<<endl;
  cout<<asctime(ti);
  cout<<"----------------------"<<endl;
  time_t now = time(0);
  struct tm *ltm = localtime(&now);
  int upload_temp;
  char upload[50];
  upload_temp=sprintf(upload,"%02d/%02d/%04d",ltm->tm_mday,1+ltm->tm_mon,1900 + ltm->tm_year);

  while(i<number)
  {
    cout<<"----------------------"<<endl;
    cout<<"Enter the name of book: ";
    getline(cin,book);
    booklist<<k3<<" "<<book<<" "<<upload<<endl;
    i++;
  }
  cout<<"----------------------"<<endl;
  cout<<"Books issued"<<endl;
  cout<<"----------------------"<<endl;
  booklist.close();
}
/// Check in of book by student (Returning the book)
void book :: check_in()
{
  string stri;
  string str,ee[MAX];
  int h;
  int j=0;
  fstream file("book.txt",ios::in);
  while(getline(file,str))
  {
      smatch matches;
      regex reg2("([0-9]+)");
      regex_search(str,matches,reg2);
      if(matches.str(1)==to_string(k3))
      {
        regex reg("[0-9]+ (.*)");
        sregex_iterator currentmatch(str.begin(),str.end(),reg);
        sregex_iterator lastmatch;
        while(currentmatch!=lastmatch)
        {
            smatch match=*currentmatch;
            ee[j]=match.str();
            currentmatch++;
        }
        j++;
      }
  }
  file.close();
  if(j==0)
  {
    cout<<"----------------------"<<endl;
    cout<<"No entry found in that ID"<<endl;
    cout<<"----------------------"<<endl;
  }
  else
  {
    cout<<"----------------------"<<endl;
    cout<<"what do u want to remove in: "<<endl;
    for (int i=0;i<j;i++)
    {
      cout<<i+1<<": "<<ee[i]<<endl;
    }
    cout<<"----------------------"<<endl;
    cin>>h;
    int i;
    int c=0;
    for(i=0;i<j;i++)
    {
      if(ee[i]!=ee[h-1])
      {
        c++;
      }
      else
      {
        fstream f("book.txt",ios::in);
        fstream temp("temp.txt",ios::out);
        while (getline(f, stri))
        {
        if (stri != ee[h-1])
        {
            temp<<stri<<endl;
        }
        }
        f.close();
        temp.close();
        remove("book.txt");
        rename("temp.txt","book.txt");
      }
    }
    
    if(c==j)
    {
      cout<<"----------------------"<<endl;
      cout<<"Not found"<<'\n';
      cout<<"----------------------"<<endl;
    }
    else
    {
      cout<<"----------------------"<<endl;
      cout<<"Removed successfully"<<'\n';
      cout<<"----------------------"<<endl;
    }
  }

}
void student :: add_stu()
{
  cout<<"----------------------"<<endl;
  cout<<"Enter the name of student to add: ";
  cin>>stu_name;
  cout<<"Enter the student ID(only numbers): ";
  cin>>stu_id;
  cout<<"----------------------"<<endl;
  fstream studentfile("stu.txt",ios::app);
  studentfile<<stu_name<<" ";
  studentfile<<stu_id<<endl;
  stud[k]=stu_id;
  studentfile.close();
  k=k+1;
}
/// Printing all Students who have took membership
void student :: list_ofall()
{
  cout<<"----------------------"<<endl;
  string alpha("");
  string num("");
  fstream studentfile("stu.txt",ios::in);
  string temp;
  while(getline(studentfile,temp))
  {
    for (int i=0; i<temp.length(); i++)
    {

      if((temp[i] >= 'A' && temp[i] <= 'Z') ||
              (temp[i] >= 'a' && temp[i] <= 'z') ||
              (temp[i]==' '))
      {
          alpha=alpha+temp[i];

      }
      if (isdigit(temp[i]))
      {
        num=num+temp[i];

      }
    }
    cout<<"Student name: "<<alpha <<"---";
    cout<<"Student ID: "<<num << endl;
    num="";
    alpha="";

  }
  cout<<"----------------------"<<endl;
  studentfile.close();
}


/// View the details of particular student
void student :: view_det(int w)
{
  time_t tt;
  struct tm * ti;
  time (&tt);
  ti = localtime(&tt);
  time_t now = time(0);
  struct tm *ltm = localtime(&now);

  fstream studentfile("stu.txt",ios::in);

  cout<<endl;
  int y=0;
  while(y<k)
  {
    if(stud[y]==w)
    {
      break;
    }
    y++;
  }
  y=y+1;
  if(y==k+1)
  {
    cout<<"----------------------"<<endl;
    cout<<"Not found"<<endl;
    cout<<"----------------------"<<endl;
  }
  else
  {
    cout<<"----------------------"<<endl;
    cout<<"The entered ID is in line no.: "<<y<<endl;
    fstream studentfile("stu.txt",ios::in);
    int lineno=0;
    do
    {
        if (lineno == y)
        {
            cout <<"Student name and ID: "<<lines<< endl;
            cout<<"----------------------"<<endl;
            break;
        }
        lineno++;

    }
    while(getline(studentfile,lines));
    fstream file ("book.txt",ios::in);
    string str;
    cout<<"The list of checked out books under ID: "<<w<<endl;
    while(getline(file,str))
    {
      smatch matches;
      regex reg2("([0-9]+)");
      regex_search(str,matches,reg2);
      if(matches.str(1)==to_string(w))
      {
        regex reg("[0-9]+ (.*)");
        sregex_iterator currentmatch(str.begin(),str.end(),reg);
        sregex_iterator lastmatch;
        
        while(currentmatch!=lastmatch)
        {
            smatch match=*currentmatch;
            cout<<matches.str(1)<<": "<<match.str()<<endl;

            smatch mat;
            regex rew("[0-9A-Za-z .]*([0-9][0-9]/[0-9][0-9]/[0-9][0-9][0-9][0-9])");
            regex_search(str,mat,rew);
            if(regex_search(str,mat,rew))
            {
              string k;
              k=mat.str(1);

              // Checking for fine starts //
              int date1,month1,year1;
              smatch date2;smatch month2;smatch year2;
              regex reg1("([0-9][0-9])/[0-9][0-9]/[0-9][0-9][0-9][0-9]");
              regex reg2("[0-9][0-9]/([0-9][0-9])/[0-9][0-9][0-9][0-9]");
              regex reg3("[0-9][0-9]/[0-9][0-9]/([0-9][0-9][0-9][0-9])");
              regex_search(k,date2,reg1);
              regex_search(k,month2,reg2);
              regex_search(k,year2,reg3);
              int temp_date,temp_month,temp_year;
              smatch matches;
              regex reg("([0-9][0-9]/[0-9][0-9]/[0-9][0-9][0-9][0-9])");
              regex_search(k,matches,reg);

              if(regex_search(k,matches,reg))
              {
                if(stoi(year2[1]) < 1900+ltm->tm_year)
                {
                  cout<<"---> Passed by year. Huge Fine has to be paid for this book"<<endl;
                }
                else if(stoi(year2[1]) > 1900+ltm->tm_year)
                {
                  cout<<"---> The check in date will come soon. No need to worry"<<endl;
                }
                else
                {
                  if(stoi(month2[1]) < 1+ltm->tm_mon)
                  {
                    cout<<"---> Passed by month. Huge Fine has to be paid for this book"<<endl;
                  }
                  else if(stoi(month2[1]) > 1+ltm->tm_mon)
                  {
                    cout<<"---> The check in date will come soon. No need to worry"<<endl;
                  }
                  else
                  {
                    if(stoi(date2[1]) < ltm->tm_mday)
                    {
                      cout<<"---> Passed by date. Fine has to be paid for the this book"<<endl;
                    }
                    else if(stoi(date2[1]) > ltm->tm_mday)
                    {
                      cout<<"---> The check in date will come soon. No need to worry"<<endl;
                    }
                    else
                    {
                      cout<<"---> The book has been issued today !!"<<endl;
                    }
                  }
                }
              }
              // Checking for fine ends //

            }

            
            currentmatch++;
        }
        
      }
    }
    cout<<"----------------------"<<endl;
    cout<<endl;
    file.close();
  }
    
}
/// Initializing (the code that runs first of all)
int student :: initial()
{
	ifstream studentfile("stu.txt");
  if(studentfile.is_open())
  {
    string lines;
    while(!studentfile.eof())
    {
      getline(studentfile,lines);
        stringstream ss(lines);
        string tem;
        int fou;
        while(ss>>temp)
        {
          if(stringstream(temp) >> fou)
          {
            stud[k]=fou;

          }

        }
        k++;
    }
    k=k-1;
  }
  else
  {
    k=0;
  }

  studentfile.close();

  return k;
}

/// Edit the details of particular student (issue or return)
int student :: edit_stu()
{ 
  cout<<'\n';
  int id_temp;
  cout<<"----------------------"<<endl;
  cout<<"Enter the student ID: ";
  cin>>id_temp;
  int i=0;
  while(i<MAX)
  {
    if(id_temp==stud[i])
    {
      k3=id_temp;
      cout<<"----------------------"<<endl;
      cout<<"1:Issue (check out) a book\n2:Return (check in) a book\n";
      book b;
      int choice2;
      cin>>choice2;
      switch(choice2)
      {
        case 1:
        {
          b.check_out();
          break;
        }
        case 2:
        {
          b.check_in();
          break;
        }
        default:
        {
          cout<<"----------------------"<<endl;
          cout<<"Incorrect entry"<<endl;
          cout<<"----------------------"<<endl;
          break;
        }
      }

      break;
    }
    else
    {
      i++;
    }
    if(i==MAX)
    {
      cout<<"----------------------"<<endl;
      cout<<"No student found"<<endl;
      cout<<"----------------------"<<endl;
    }
  }

  return k3;
}
void professor:: add_prof()
{
  cout<<"----------------------"<<endl;
  cout<<"Enter the name of prof to add: ";
  cin>>prof_name;
  cout<<"Enter the prof ID(only numbers): ";
  cin>>prof_id;
  cout<<"----------------------"<<endl;
  fstream proffile("prof.txt",ios::app);
  proffile<<prof_name<<" ";
  proffile<<prof_id<<endl;
  prof[m]=prof_id;
  proffile.close();
  m=m+1;
}
/// Initializing (the code that runs first of all)
int  professor::  initial()
{
	ifstream proffile("prof.txt");
  if(proffile.is_open())
  {
    string lines;
    while(!proffile.eof())
    {
      getline(proffile,lines);
        stringstream ss(lines);
        string tem;
        int fou;
        while(ss>>temp)
        {
          if(stringstream(temp) >> fou)
          {
            prof[k]=fou;

          }

        }
        m++;
    }
    m=m-1;
  }
  else
  {
    m=0;
  }

  proffile.close();

  return m;
}

/// View the details of particular prof
void professor :: view_det(int w)
{
  time_t tt;
  struct tm * ti;
  time (&tt);
  ti = localtime(&tt);
  time_t now = time(0);
  struct tm *ltm = localtime(&now);

  fstream proffile("prof.txt",ios::in);

  cout<<endl;
  int y=0;
  while(y<m)
  {
    if(prof[y]==w)
    {
      break;
    }
    y++;
  }
  y=y+1;
  if(y==m+1)
  {
    cout<<"----------------------"<<endl;
    cout<<"Not found"<<endl;
    cout<<"----------------------"<<endl;
  }
  else
  {
    cout<<"----------------------"<<endl;
    cout<<"The entered ID is in line no.: "<<y<<endl;
    fstream proffile("prof.txt",ios::in);
    int lineno=0;
    do
    {
        if (lineno == y)
        {
            cout <<"professor name and ID: "<<lines<< endl;
            cout<<"----------------------"<<endl;
            break;
        }
        lineno++;

    }
    while(getline(proffile,lines));
    fstream file ("book.txt",ios::in);
    string str;
    cout<<"The list of checked out books under ID: "<<w<<endl;
    while(getline(file,str))
    {
      smatch matches;
      regex reg2("([0-9]+)");
      regex_search(str,matches,reg2);
      if(matches.str(1)==to_string(w))
      {
        regex reg("[0-9]+ (.*)");
        sregex_iterator currentmatch(str.begin(),str.end(),reg);
        sregex_iterator lastmatch;
        
        while(currentmatch!=lastmatch)
        {
            smatch match=*currentmatch;
            cout<<matches.str(1)<<": "<<match.str()<<endl;

            smatch mat;
            regex rew("[0-9A-Za-z .]*([0-9][0-9]/[0-9][0-9]/[0-9][0-9][0-9][0-9])");
            regex_search(str,mat,rew);
            if(regex_search(str,mat,rew))
            {
              string k;
              k=mat.str(1);

              // Checking for fine starts //
              int date1,month1,year1;
              smatch date2;smatch month2;smatch year2;
              regex reg1("([0-9][0-9])/[0-9][0-9]/[0-9][0-9][0-9][0-9]");
              regex reg2("[0-9][0-9]/([0-9][0-9])/[0-9][0-9][0-9][0-9]");
              regex reg3("[0-9][0-9]/[0-9][0-9]/([0-9][0-9][0-9][0-9])");
              regex_search(k,date2,reg1);
              regex_search(k,month2,reg2);
              regex_search(k,year2,reg3);
              int temp_date,temp_month,temp_year;
              smatch matches;
              regex reg("([0-9][0-9]/[0-9][0-9]/[0-9][0-9][0-9][0-9])");
              regex_search(k,matches,reg);

              if(regex_search(k,matches,reg))
              {
                if(stoi(year2[1]) < 1900+ltm->tm_year)
                {
                  cout<<"---> Passed by year. Huge Fine has to be paid for this book"<<endl;
                }
                else if(stoi(year2[1]) > 1900+ltm->tm_year)
                {
                  cout<<"---> The check in date will come soon. No need to worry"<<endl;
                }
                else
                {
                  if(stoi(month2[1]) < 1+ltm->tm_mon)
                  {
                    cout<<"---> Passed by month. Huge Fine has to be paid for this book"<<endl;
                  }
                  else if(stoi(month2[1]) > 1+ltm->tm_mon)
                  {
                    cout<<"---> The check in date will come soon. No need to worry"<<endl;
                  }
                  else
                  {
                    if(stoi(date2[1]) < ltm->tm_mday)
                    {
                      cout<<"---> Passed by date. Fine has to be paid for the this book"<<endl;
                    }
                    else if(stoi(date2[1]) > ltm->tm_mday)
                    {
                      cout<<"---> The check in date will come soon. No need to worry"<<endl;
                    }
                    else
                    {
                      cout<<"---> The book has been issued today !!"<<endl;
                    }
                  }
                }
              }
              // Checking for fine ends //

            }

            
            currentmatch++;
        }
        
      }
    }
    cout<<"----------------------"<<endl;
    cout<<endl;
    file.close();
  }
    
}
/// Printing all profs who have took membership
void professor :: list_ofall()
{
  cout<<"----------------------"<<endl;
  string alpha("");
  string num("");
  fstream proffile("prof.txt",ios::in);
  string temp;
  while(getline(proffile,temp))
  {
    for (int i=0; i<temp.length(); i++)
    {

      if((temp[i] >= 'A' && temp[i] <= 'Z') ||
              (temp[i] >= 'a' && temp[i] <= 'z') ||
              (temp[i]==' '))
      {
          alpha=alpha+temp[i];

      }
      if (isdigit(temp[i]))
      {
        num=num+temp[i];

      }
    }
    cout<<"professor name: "<<alpha <<"---";
    cout<<"professor ID: "<<num << endl;
    num="";
    alpha="";

  }
  cout<<"----------------------"<<endl;
  proffile.close();
}


/// Edit the details of particular student (issue or return)
int professor :: edit_prof()
{ 
  cout<<'\n';
  int id_temp;
  cout<<"----------------------"<<endl;
  cout<<"Enter the prof ID: ";
  cin>>id_temp;
  int i=0;
  while(i<MAX)
  {
    if(id_temp==prof[i])
    {
      k3=id_temp;
      cout<<"----------------------"<<endl;
      cout<<"1:Issue (check out) a book\n2:Return (check in) a book\n";
      book b;
      int choice2;
      cin>>choice2;
      switch(choice2)
      {
        case 1:
        {
          b.check_out();
          break;
        }
        case 2:
        {
          b.check_in();
          break;
        }
        default:
        {
          cout<<"----------------------"<<endl;
          cout<<"Incorrect entry"<<endl;
          cout<<"----------------------"<<endl;
          break;
        }
      }

      break;
    }
    else
    {
      i++;
    }
    if(i==MAX)
    {
      cout<<"----------------------"<<endl;
      cout<<"No prof found"<<endl;
      cout<<"----------------------"<<endl;
    }
  }

  return k3;
}

int login :: initial()
{
	fstream passfile("abc.txt");
	fstream userfile("xyz.txt");
	
    if(userfile.is_open())
    {
      while(!userfile.eof())
      {
          getline(userfile,lineu);
          users[i]=lineu;
          i++;
      }
      i=i-1;
    }
    else
    {
      i=0;
    }
    userfile.close();

    if(passfile.is_open())
    {
      while(!passfile.eof())
      {
          getline(passfile,linep);
          passw[j]=linep;
          j++;
      }
      j=j-1;
    }
    else
    {
      j=0;
    }
    passfile.close();

  return i;
  return j;
}

/// Registering a user to control the whole system
string login :: regis()
{
    ifstream userfile("xyz.txt");
    cout<<"----------------------"<<endl;
    cout<<"Do u have an account? yes or no"<<endl;
    cin>>cho;
    if(cho=="yes")
    {
      cin.ignore();
      check();

    }
    else if(cho=="no")
    {
      cout<<"----------------------"<<endl;
      cout<<"Type your New Username: "<<endl;
      cin.ignore();
      getline(cin,user);
      k2=0;
      while(getline(userfile,lineu))
      {
        if(lineu==user)
        {
          k2++;
        }
      }
      userfile.close();
      fstream passfile("abc.txt",ios::app|ios::out);
      fstream userfi("xyz.txt",ios::app|ios::out);
      if(k2==1)
      {
        cout<<"----------------------"<<endl;
        cout<<"Same username existing in database\nPlease use another username to register"<<endl;
        cout<<"----------------------"<<endl;
        regis();
      }
      else
      {
        userfi<<user<<endl;
        users[i]=user;
        cout<<"----------------------"<<endl;
        cout<<"Type your New Password: "<<endl;
        getline(cin,pass);
        passfile<<pass<<endl;
        passw[j]=pass;
        cout<<"----------------------"<<endl;
        cout<<endl<<"Registered successfully"<<endl;
        cout<<"----------------------"<<endl;
        check();
      }
      passfile.close();
      userfi.close();

    }
    else
    {
      cout<<"----------------------"<<endl;
      cout<<"Invalid Entry"<<endl<<endl;
      cout<<"----------------------"<<endl;
      regis();
    }

    return cho;
}

/// Check for the credentials while logging in
int login :: check()
{
  cout<<"----------------------"<<endl;
  cout<<"enter the username: ";
  getline(cin,user);
  k1=0;
  do
  {
    if(user==users[k1])
    {
      cout<<"----------------------"<<endl;
      cout<<"enter the password: "<<endl;
      cout<<"if you have forgot the password, type forget"<<endl;
      getline(cin,pass);
      if(pass==passw[k1])
      {
        cout<<endl;
        cout<<"----------------------"<<endl;
        cout<<"You are now logged in"<<endl;
        cout<<"----------------------"<<endl;
        break;

      }
      else if(pass=="forget")
      {
        cout<<"----------------------"<<endl;
        cout<<"enter the same username again"<<endl;
        getline(cin,temp1);
        if(temp1==users[k1])
        {
          cout<<endl;
          cout<<"----------------------"<<endl;
          cout<<"You are now logged in"<<endl;
          cout<<"----------------------"<<endl;
          pass=passw[k1];
          break;
        }
        else
        {
          cout<<"----------------------"<<endl;
          cout<<"Incorrect entry sorry"<<endl;
          cout<<"----------------------"<<endl;
          _Exit(0);
        }
        pass=passw[k1];
      }
      else
      {
        cout<<"----------------------"<<endl;
        cout<<"Incorrect password"<<endl;
        cout<<"----------------------"<<endl;
        _Exit(0);
      }

    }
    k1++;

  }
  while(k1<MAX);
  if(k1==MAX)
  {
    cout<<"----------------------"<<endl;
    cout<<"User doesnt exist"<<endl;
    cout<<"----------------------"<<endl;
    exit();
  }
  cout<<"The serial number of username and password in the text file is: "<<k1+1<<endl<<endl;
  return k1;

}

/// Change the password if user wants after logging in
void login :: change_pass()
{
    string pass1;
    cout<<endl;

    cin.ignore();
    if(k1==i)
    {
      cout<<"----------------------"<<endl;
      cout<<"You cannot change your password at this moment"<<'\n';
      cout<<"Try to change when you login with same credentials the next time"<<endl;
      cout<<"----------------------"<<endl;
    }
    else
    {
      cout<<"----------------------"<<endl;
      cout<<"Type your old password here: "<<endl;
      getline(cin,temp);
      ofstream fileout("xyz1.txt");
      ifstream filein("abc.txt",ios::app);
      if(temp!=pass)
      {
        cout<<"----------------------"<<endl;
        cout<<"You have typed an incorrect password"<<endl;
        cout<<"----------------------"<<endl;
        filein.close();
        fileout.close();
      }
      else
      {
        cout<<"----------------------"<<endl;
        cout<<"Type the new password"<<endl;
        getline(cin,pass1);
        for(k2=0;k2<j;k2++)
        {
          if(passw[k2]==pass)
          {
              // the line is k2+1
              for(int y=0;y<k1;++y)
              {
                  getline(filein,linep);
                  fileout<<linep<<endl;
              }

              fileout<<pass1<<endl;
              if(cho=="yes")
              {
                for(int y=k1+1;y<j;y++)
                {
                    fileout<<passw[y]<<endl;
                }
              }
              else if(cho=="no")
              {
                for(int y=k1+1;y<j+1;y++)
                {
                    fileout<<passw[y]<<endl;
                }
              }

              passw[k2]=pass1;
          }
        }
        filein.close();
        fileout.close();

        remove("abc.txt");
        rename("xyz1.txt","abc.txt");
        pass=pass1;
      }
      cout<<"----------------------"<<endl;
      cout<<"Password updated successfully"<<endl;
      cout<<"----------------------"<<endl;
    }
    disp();
}

/// Display the credentials
void login :: disp()
{
  cout<<"----------------------"<<endl;
  cout<<"Username: "<<user<<endl;
  cout<<"Password: "<<pass<<endl;
  cout<<"----------------------"<<endl;
}

/// Exit the portal
void login :: exit()
{
    _Exit(0);
}

int main()
{
  cout<<i<<" "<<j<<" "<<k<<" "<<'\n';
  int choice,choice1,ch2,ch3;
  login l;
  book b;
  professor p;
  student s;
  s.initial();
  p.initial();
  cout<<"----------------------"<<endl;
  cout<<endl;
  cout<<"The student ID stored are: "<<endl;
  for(k2=0;k2<k;k2++)
  {
    cout<<stud[k2]<<endl;
  }
    cout<<"----------------------"<<endl;
  cout<<endl;
  cout<<"The professor ID stored are: "<<endl;
  for(k2=0;k2<m;k2++)
  {
    cout<<prof[k2]<<endl;
  }
  l.initial();
  cout<<"----------------------"<<endl;
  cout<<endl;
  cout<<"The passwords stored are: "<<endl;
  for(k2=0;k2<j;k2++)
  {
    cout<<passw[k2]<<endl;
  }
  cout<<"----------------------"<<endl;
  cout<<endl;
  cout<<"The usernames stored are: "<<endl;
  for(k2=0;k2<i;k2++)
  {
    cout<<users[k2]<<endl;
  }
  cout<<"----------------------"<<endl;
  cout<<endl;
  cout<<i<<" "<<j<<" "<<k<<" "<<'\n';
  l.regis();
  
    
    cout<<"----------------------"<<endl;
    cout<<"1:Change password\n2:Display details\n3:Exit from 1st portal\n  and enter into 2nd portal"<<endl;
    cout<<"----------------------"<<endl;
    cin>>choice;
    switch (choice)
    {
      case 1:
      {
        l.change_pass();
        break;
      }
      case 2:
      {
        l.disp();
        break;
      }
      case 3:
      {  cout<<"choose who u are?\n1.student 2.professor 3. librarian\n"; 
        
        cin>> ch2;
        cout<<ch2;
        cout<<" enter ur id: ";
          cin>>ch3;
        switch (ch2){
          case 1:{
            for(;;)
  {
    
            cout<<"1.see all books 2.see book with his id 3.logout ";
            cin>>ch2;
            cout<<ch2;
            switch(ch2){
              case 1:
                { b.list_ofall();
            break;
                  
                }
          case 2:
                {
            s.view_det(ch3);
            break;
                  
                }
              case 3:
                {
            _Exit(0);
            break;
                }
            }
          }
            break;}
          case 2:{
            for(;;)
  {
            cout<<"1.see all books 2.see book with his id  3.logout ";
            cin>>ch2;
            cout<<ch2;
            switch(ch2){
              case 1:
                { b.list_ofall();
            break;
                  
                }
              case 2:
                {
            p.view_det(ch3);
            break;
                  
                }
              case 3:
                {
            _Exit(0);
            break;
                }
            }}break;}
          case 3:{
             
            for(;;)
  {
        cout<<"----------------------"<<endl;
        cout<<"1:Add a student to database \n2:Edit the details of a student(issued books or return a book)\n3:View the details of a particular student(issued books or return a book)\n4:View all enrolled students for library books\n5.Add a prof to database\n6.edit details of prof(issue a book or retuen a book)\n7.view details of a particular prof (books taken)\n8.View all enrolled profs for library books\n9.add a book\n10:logout"<<endl;
        cout<<"----------------------"<<endl;
        cin>>choice1;
        switch(choice1)
        {
          case 1:
          {
            s.add_stu();
            cout<<endl;
            cout<<"----------------------"<<endl;
            cout<<"The data in the student file is:"<<endl;
            s.list_ofall();
            cout<<"----------------------"<<endl;
            cout<<endl;
            break;
          }
          case 2:
          {
            cout<<"----------------------"<<endl;
            cout<<"Processing...."<<'\n';
            cout<<"----------------------"<<endl;
            s.edit_stu();
            break;
          }
          case 3:
          {
            int q;
            cout<<"----------------------"<<endl;
            cout<<"Enter the ID of student to view the details"<<endl;
            cin>>q;
            s.view_det(q);
            break;
          }
          case 4:
          {
            s.list_ofall();
            break;
          }
          case 5:
          {
            p.add_prof();
            cout<<endl;
            cout<<"----------------------"<<endl;
            cout<<"The data in the prof file is:"<<endl;
            p.list_ofall();
            cout<<"----------------------"<<endl;
            cout<<endl;
            break;
          }
          case 6:
          {
            cout<<"----------------------"<<endl;
            cout<<"Processing...."<<'\n';
            cout<<"----------------------"<<endl;
            p.edit_prof();
            break;
          }
          case 7:
          {int q;
            cout<<"----------------------"<<endl;
            cout<<"Enter the ID of prof to view the details"<<endl;
            cin>>q;
            p.view_det(q);
            break;
            
           
          }
          case 8:
          {
            p.list_ofall();
            break;
          }
          case 10:
          {
            _Exit(0);
            break;
          }
          case 9:{
            b.add_book();
            cout<<endl;
            cout<<"----------------------"<<endl;
            cout<<"The data in the book file is:"<<endl;
            b.list_ofall();
            cout<<"----------------------"<<endl;
            cout<<endl;
            break;
          }
          default:
          {
            cout<<"----------------------"<<endl;
            cout<<"Incorrect entry"<<endl;
            cout<<"----------------------"<<endl;
            break;
          }
          }}break;}

        break;
      }break;}
      default:
      {
        cout<<"----------------------"<<endl;
        cout<<"Incorrect entry"<<endl;
        cout<<"----------------------"<<endl;
        break;
      }
    }
  return 0;
}
  