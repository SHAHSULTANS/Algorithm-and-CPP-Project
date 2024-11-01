#include <iostream>
#include <bits/stdc++.h>
#include <conio.h>
#include <string.h>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class faculty;

class permission
{
protected:
    string user_id;
    string passsoward;

public:
    permission()
    {
        user_id = "shanto";
        passsoward = "sultan";
    }
    void inp()
    {
        string p;
        cout << "\t\t____________________________________________________________" << endl;
        cout << "\n\t\t\t\t|Enter user_permission ID:-| ";
        cin >> user_id;
        cout << "\n\t\t\t\t|Enter user passwoard( 6 character):-| "; // cin>>passsoward;
        for (int i = 0; i < 6; i++)
        {
            p += getch();
            cout << "*";
        }
        passsoward = p;
        cout << "\n\t\t____________________________________________________________";
        cout << endl;
    }
    bool operator==(permission s)
    {
        if (s.user_id.compare(user_id) == 0 && s.passsoward.compare(passsoward) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }  
    void loadingbar();
    void intro();
    void ccolour(int);
};

class date
{
public:
    int dd;
    int mm;
    int yy;
};
class registration
{
public:
    date birth;
    string department;
    int batch;
    float gpa;
    vector<int> course;

public:
    registration()
    {
        birth.dd = 0;
        birth.mm = 0;
        birth.yy = 0;
        department = "\0";
        batch = 0;
        gpa = 0.0;
    }
    void input()
    {
        fflush(stdin);
        cout << "\t*******************************************" << endl;
        cout << "\t* ENTER DATE OF BIRTH (DD/MM/YY) : ";
        cin >> birth.dd >> birth.mm >> birth.yy;
        fflush(stdin);
        cout << "\t*******************************************" << endl;
        cout << "\t* ENTER STUDENT DEPARTMENT: ";
        cin >> department;
        fflush(stdin);
        cout << "\t*******************************************" << endl;
        cout << "\t* ENTER STUDENT BATCH: ";
        cin >> batch;
        fflush(stdin);
        cout << "\t*******************************************" << endl;
        cout << "\t* ENTER STUDENT GPA: ";
        cin >> gpa;
        fflush(stdin);
        cout << "\t*******************************************" << endl;
        // fflush(stdin);
        // cout<<"\t* ENTER TOTOAL NUMBER OF COURSE: ";int n;cin>>n;
        // cout << "\t*******************************************" << endl;
        // fflush(stdin);
        // cout<<"\t* ENTER TOTOAL NUMBER OF COURSE: ";int n;cin>>n;
    }
};

class rating
{
public:
    float r;

public:
    rating()
    { 
        r=0.00;
    }
};

class student : public registration,public rating
{
public:
    char name[30];
    string fr_name;
    char gender;
    string email;
    int roll_id;
    int age;
    int busno;

public:
    student()
    {
        strcpy(name, "\0");
        fr_name = "\0";
        gender = ' ';
        email = "\0";
        roll_id = 0;
        age = 0;
        busno = 0;
        registration();
        rating();

    }
    friend void f();



    void reg()
    {
        fflush(stdin);
        cout << "\t*******************************************" << endl;
        cout << "\t* ENTER STUDENT NAME: ";
        cin.getline(name, 29);
        fflush(stdin);
        cout << "\t*******************************************" << endl;
        cout << "\t* ENTER STUDENT ROLL NO: ";
        cin >> roll_id;
        fflush(stdin);
        fflush(stdin);
        cout << "\t*******************************************" << endl;
        cout << "\t* ENTER STUDENT GENDER: ";
        cin >> gender;
        cin.get();
        fflush(stdin);
        fflush(stdin);
        cout << "\t*******************************************" << endl;
        cout << "\t* ENTER STUDENT FATHER NAME: ";
        getline(cin, fr_name);
        fflush(stdin);
        fflush(stdin);
        cout << "\t*******************************************" << endl;
        cout << "\t* ENTER EMAIL ID: ";
        cin >> email;
        fflush(stdin);
        cout << "\t*******************************************" << endl;
        cout << "\t* ENTER STUDENT AGE: ";
        cin >> age;
        fflush(stdin);
        cout << "\t*******************************************" << endl;
        cout << "\t* ENTER STUDENT BUS NO: ";
        cin >> busno;
        fflush(stdin);
        registration::input();
        srand(time(NULL));
        r=rand()%100;
        // float input,sum=0;
        // cout << "\t*******************************************" << endl;
        // cout << "\t* ENTER STUDENT RATING FOR GPA: ";
        // cin>>input;sum=sum+input;
        // cout << "\t*******************************************" << endl;
        // cout << "\t* ENTER STUDENT RATING FOR BATCH: ";
        // cin>>input;sum=sum+input;
        // cout << "\t*******************************************" << endl;
        // fflush(stdin);


    }
    void show();
    int storedata();
    void searchoption();
    void findsearch(char *s);
    void del(char *s);
    void viewalldata();
    void update(char* t);
};

// void permission::ccolour(int clr){
// 	HANDLE  hConsole;
// 	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
// 	SetConsoleTextAttribute(hConsole, clr);
// }


void f()
{
    cout<<"\n student name:" ;
    //cout<<

}



void student::show()
{
    cout << "\t****************************************************" << endl;
    cout<<"\t|                               |               "<<endl;
    cout<<"\t|Total RATING OF THE STUDENT    |->    "<<r<<endl;
    cout<<"\t|NAME OF THE STUDENT IS         |->    "<<name<<endl;
    cout<<"\t|                               |               "<<endl;
    cout<<"\t|ROLL NO OF THE STUDENT         |->    "<<roll_id<<endl; 
    cout<<"\t|                               |               "<<endl;
    cout<<"\t|GENDER OF THE STUDENT          |->    "<<gender<<endl;
    cout<<"\t|                               |               "<<endl;
    cout<<"\t|FATHER NAME OF THE STUDENT     |->    "<<fr_name<<endl;
    cout<<"\t|                               |               "<<endl;
    cout<<"\t|                               |               "<<endl;
    cout<<"\t|CGPA THE STUDENT               |->    "<<gpa<<endl; 
    cout<<"\t|                               |               "<<endl;
    cout<<"\t|DEPARTMENT  OF THE STUDENT     |->    "<<department<<endl; 
    cout<<"\t|                               |               "<<endl;
    cout<<"\t|BATCH NO OF THE STUDENT        |->    "<<batch<<endl; 
    cout<<"\t|                               |               "<<endl;
    cout<<"\t|BUS NO OF THE STUDENT          |->    "<<busno<<endl;
    cout<<"\t|                               |               "<<endl;
    cout<<"\t|EMAIL OF THE STUDENT           |->    "<<email<<endl;
    cout<<"\t|                               |               "<<endl;
    cout<<"\t|DATE OF  BIRTH                 |->    "<<birth.dd<<" / "<<birth.mm<<" / "<<birth.yy<<endl;
    cout<<"\t|                               |               "<<endl;
    cout<<"\t|AGE OF THE STUDENT             |->    "<<age<<endl;  
    cout << "\t****************************************************" << endl;
}




void permission::loadingbar()
{
    int i, j;
    for (i = 15; i <= 100; i = i + 5)
        ;
    {
        system("cls");
        cout << "\n\n\n\n\n\t";
        cout << i << " %% loading...\n\n\\n\nt\t";
        cout << " ";
        for (j = 0; j < i; j = i + 3)
            ;
        {
            cout << " ";
        }
        Sleep(50);
        if (i == 70 || i == 50 || i == 65 || i == 80 || i == 90)
        {
            Sleep(50);
        }
        system("cls");
    }
}
void permission::intro()
{
    cout << "\t\t***********************************************************" << endl;
    cout << "\t\t***********************************************************" << endl;
    cout << "\t\t******       BEST STUDENT RATING SYSTEM        ************" << endl;
    cout << "\t\t******     MADE BY SHAH SULTAN & KOUSHIK ROY   ************" << endl;
    cout << "\t\t***********************************************************" << endl;
    cout << "\t\t***********************************************************" << endl;
    cout << "\t\t____________________________________________________________" << endl;
    getch();
}

int student::storedata()
{
    if (age == 0 && roll_id == 0)
    {
        cout << "\n Student data not initialized : ";
        return (0);
    }
    else
    {
        ofstream fout;
        fout.open("shanto.dat", ios::app | ios::binary);
        fout.write((char *)this, sizeof(*this));
        fout.close();
        return (1);
    }
}


void student::findsearch(char *s)
{
    int count=0;
    ifstream fin;
    fin.open("shanto.dat",ios::in|ios::binary);
    if(!fin)
    {
        cout<<"error file not find."<<endl;
    }
    else
    {
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            if(!strcmp(s,name))
            {
                show();
                count++;
                //return;
                //break;
            }
           fin.read((char*)this,sizeof(*this)); 
        }
        if(count==0)
        {
            cout<<"\nrecord not found"<<endl;
        }
        fin.close();
    }
    //return;
}


void student::searchoption()
{
    cout << "\t\t*************************************************" << endl;
    cout<<"\t\t|                                                 |"<<endl;
    cout<<"\t\t|              STUDENT SEARCH OPTION              |"<<endl;
    cout<<"\t\t|                                                 |"<<endl;
    cout << "\t\t*************************************************" << endl;
    char str[30];
    cout<<"\t\t Enter Name of the student: ";
    fflush(stdin);
    cin.getline(str,29);
    findsearch(str);
}



void student::del(char *t)
{
    ifstream fin;
    ofstream fout;
    fin.open("shanto.dat",ios::in|ios::binary);
    if(!fin)
    {
        cout<<"Error file not found:";
    }

    else{
        fout.open("sultan.dat",ios::out|ios::binary);
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            if(strcmp(name,t))
                fout.write((char*)this,sizeof(*this));
            fin.read((char*)this,sizeof(*this));
        }
        fin.close();
        fout.close();
        remove("shanto.dat");
        rename("sultan.dat","shanto.dat");
    }
}


void student::viewalldata()
{
    ifstream fin;
    fin.open("shanto.dat",ios::in|ios::binary);
    if(!fin)
        cout<<"error file not found:";
    else{
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof()){
            show(); 
           fin.read((char*)this,sizeof(*this));
        }
        fin.close();
    }
}

void student::update(char *t)
{
    fstream file;
    file.open("file.dat",ios::in|ios::out|ios::ate|ios::binary);
    file.seekg(0);
    file.read((char*)this,sizeof(*this));
    while(!file.eof())
    {
        if(!strcmp(t,name)){
            reg();
            file.seekp(file.tellp()-sizeof(*this));
            file.write((char*)this,sizeof(*this));
        }
        file.read((char*)this,sizeof(*this));
    }
}

int main()
{
    // permission class object.
    //remove("shanto.dat");

    cout << "\t\tyou need to permsion to using next interface";
    cout << "\n**********************************************************************" << endl;

    permission ob, ob2;
    ob.loadingbar();
    ob.intro();
lb:
    ob2.inp();
    if (ob == ob2)
    {
        cout << "\n\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*|" << endl;
        cout << "\t\t\t\t|**** Successfully Login.  *|" << endl;
        cout << "\t\t\t\t|*-*-*-*-*-*-*-*-*-*-*-*-*-*|" << endl;
    }
    else
    {
        cout << "\t\tincorrect user name or passoward." << endl;
        cout << "\t\tplease try again." << endl;
        getch();
        goto lb;
    }

    getch();
    student st;
    int op = 1;
    while (op)
    {
        system("cls");
        cout << "\n\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*";
        cout << "\n\t\tWelcome to Jahangirnagar university Student Database";
        cout << "\n\t*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;

        cout << "\t************************************************************************" << endl;
        cout << "\t************************************************************************" << endl;
        cout << "\t***                                                                  ***" << endl;
        cout << "\t***               1. Registration Student record.                    ***" << endl;
        cout << "\t***               2. Search Student record.                          ***" << endl;
        cout << "\t***               3. View All Student record.                        ***" << endl;
        cout << "\t***               4. Delete Student record.                          ***" << endl;
        cout << "\t***               5. Update Student record.                          ***" << endl;
        cout << "\t***               0. For Exit the programm.                          ***" << endl;
        cout << "\t***                                                                  ***" << endl;
        cout << "\t************************************************************************" << endl;
        cout << "\t************************************************************************" << endl;
        cin >> op;
        cin.get();
        switch (op)
        {
        case 1:
            st.reg();
            st.storedata();
            cout << "\n\t\t Data is Successfully Stored:";
            getch();
            break;
        case 2:
            //st.show();
            st.searchoption();
            getch();
            break;
        case 3:
            st.viewalldata();
            getch();
            break;
        case 4:
            //st.show();
            char str[30];
            cout<<"\t\t Enter Name of the student: ";
            fflush(stdin);
            cin.getline(str,29);
            st.del(str);
            cout << "\n\t\t Delete Successfully:";
            getch();
            break;
        case 5:
            // char name[30];
            cout<<"\n\n Enter Student Name to Update a record:";fflush(stdin);
            cin.getline(str,29);
            st.update(str);
            cout<<"\n\t\t Data is Successfully Updated:";
        getch();
        break;
        case 6:
            cout<<"\n\t\t Thank You For using This Application:";
            cout<<"\n\t\t Enter Any Key To Exit:-";
            getch();
            exit(0);
            break;
        default:
        cout<<"Invalid Input Try Again:";
        getch();
        }
    }
}