#include<iostream>
#include<conio.h>
#include<bits/stdc++.h>
#include<string.h>
#include<iomanip>
#include<windows.h>
#include<fstream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
unordered_map<int,int>um,male;

class room_no
{
public:
    list<pair<int,int>>l,l2;

public:
    room_no()
    {
        int i,j,k;
        for(i=1;i<=7;i++)
        {
            k=i*100;
            for(j=1;j<=7;j++)
            {
                l.push_back({k+j,2});
            }
        }
        l2=l;
    }
    void allot()
    {
        for(auto it=um.begin();it!=um.end();it++)
        {
            if(l.size()>0)
            {
                um[it->second]=l.front().first;
                l.front().second-=1;
                if(l.front().second==0)
                {
                    l.pop_front();
                }
            }
            else
            {
                um[it->second]=0;
            }
        }
        for(auto it=male.begin();it!=male.end();it++)
        {
            if(l2.size()>0)
            {
                male[it->second]=l2.front().first;
                l2.front().second-=1;
                if(l2.front().second==0)
                {
                    l2.pop_front();
                }
            }
            else
            {
                male[it->second]=0;
            }
        }
    }
 

};
class loginsystem
{
protected:
    string id;
    int pass;
public:
    loginsystem()
    {
        id="shathi";
        pass=3535;  
    }
    void input()
    {
        string p;
        cout << "\t\t____________________________________________________________" << endl;
        cout << "\n\t\t\t\t|Enter user_permission ID:-| ";
        cin >> id;
        cout << "\n\t\t\t\t|Enter user passwoard:-| "; 
        cin>>pass;
    }
    bool operator==(loginsystem s)
    {
        if (s.id.compare(id) == 0 && s.pass== pass)
        {
            return true;
        }
        else
        {
            return false;
        }

    }
};
class student:public room_no
{
public:
    char name[30];
    int Roll_no;
    char gender;
    int batch;
    string pr_hall;
    int rom;
    string convert(string s)
    {
        for(int i=0;i<s.length();i++)
        {
            s[i]=toupper(s[i]);
        }
        return s;
    }
public:
    void intro(void);
    void loadingbar(void);
    void login(void); 
    void getdata(void);   
    void showdata(void);  
    void viewAlldata();     
    int storedata();       
    void searchData(char *);
    void showsearch(void);      
    void deleteData(char *);
    void updateData(char *);   
    student()
    {
        Roll_no=0;
        gender=' ';
        strcpy(name,"no name");
        batch=0;
        pr_hall="\0";
        rom=0;
    }

};
// void student::loadingbar()
// {
//     for (int i=15;i<=100;i+=5)
//         {
//         system("cls");
//         //ccolor(14);
// 		cout<<"\n\n\n\n\n\n\n\t\t\t";
// 		cout<<i<<" %% loadding...\n\n\t\t";
// 		cout<<" ";
// 		for (int j=0; j<i;j+=2){
// 			cout<<" ";
// 		}
// 		Sleep(50);
// 		if(i==90 || i==50 || i==96 || i==83){
// 			Sleep(50);
// 		}
// 	}
// 	system("cls");// clear the terminal
// }
void student::intro()
{
    //ccolor(433);
    cout<<"*****************************************************************"<<endl
        <<"*****************************************************************"<<endl
        <<"*************       HALL ALLOTED  SYSTEM            **************"<<endl
        <<"*************          SHARMIN & TUSKA              **************"<<endl
        <<"*****************************************************************"<<endl
        <<"*****************************************************************"<<endl
        <<"_________________________________________________________________\n";
        //simple introduction
        getch();
}
void student::login()
{
    char ui[]="shathi";
    char psw[]="3535";
    char gui[10],gpsw[10];
    cout<<"\n\t\t______________________________"<<endl
        <<"\t\t|ENTER USER ID:-|";
    cin>>gui;
    cout<<"\n\t\t______________________________"<<endl
        <<"\t\t|ENTER PASSWORD:-|";
    cin>>gpsw;
    if(strcmp(ui,gui)!=0 && strcmp(psw,gpsw)==0)
       {
        cout<<"\t\tINVALID UI AND PASSWORD:";
        getch();
        exit(0);
    }
    else
    {
        cout<<"\t\tLOGIN SUCSESSFULLY:-\n";
    }
}
void student::getdata()
{

    fflush(stdin);
   cout<<"\t**************************************************"<<endl;
   cout<<"\t* ENTER STUDENT NAME :";cin.getline(name,29);fflush(stdin);
   cout<<"\t**************************************************"<<endl;
   cout<<"\t* ENTER STUDENT ROLL.NO :";cin>>Roll_no;fflush(stdin);
   cout<<"\t**************************************************"<<endl;
   cout<<"\t* ENTER STUDENT GENDDER(M/F) :";cin>>gender;fflush(stdin);
   cout<<"\t**************************************************"<<endl;fflush(stdin);
   cout<<"\t* ENTER STUDENT PREVIOUS HALL NAME :";getline(cin,pr_hall);fflush(stdin);
   cout<<"\t**************************************************"<<endl;
   cout<<"\t* ENTER STUDENT BATCH :";cin>>batch;fflush(stdin);
   cout<<"\t**************************************************"<<endl;fflush(stdin);
    if(gender=='M')
    {
        male[Roll_no]=Roll_no;
        rom=male[Roll_no];
    }
    else
    {
        um[Roll_no]=Roll_no;
        rom=um[Roll_no];
    }

}
void student::showdata()
{
            cout<<"\t***************************************************"<<endl;
            cout<<"\t|                             |                   "<<endl;
            cout<<"\t|NAME of the student is       |->    "<<name<<"   "<<endl;
            cout<<"\t|                             |                   "<<endl;
            cout<<"\t|Roll.NO of the student is    |->       "<<Roll_no<<"          "<<endl;
            cout<<"\t|                             |                   "<<endl;
            cout<<"\t|Gender of the student is     |->       "<<gender<<"         "<<endl;
            cout<<"\t|                             |                   "<<endl;
            cout<<"\t|Previous hall name of student|->     "<<pr_hall<<"  "<<endl;
            cout<<"\t|                             |                   "<<endl;
            cout<<"\t|BATCH NO                     |->    "<<batch<<"     "<<endl;
            cout<<"\t|                             |                   "<<endl;
            cout<<"\t|ARE YOU ALLOTED NEW HALL:    |->     ";
            if(gender=='M')
            {
                if(rom==0)
                {
                    cout<<"Not allowed"<<endl;
                }
                else
                {
                    cout<<"hall name 21 & room no: "<<rom;//male[Roll_no];
                }
            }
            else
            {
                if(rom==0)
                {
                    cout<<"Not allowed"<<endl;
                }
                else
                {
                    cout<<"hall name 18 & room no: "<<rom;//um[Roll_no];
                }
            }
            cout<<"\n\t***************************************************"<<endl;
}
int student::storedata()
{
    if(Roll_no==0)
    {
        cout<<"\n Student data not initialized : ";
        return(0);
    }
    else
    {
        ofstream fout;
        fout.open("file.dat",ios::app|ios::binary);
        fout.write((char*)this,sizeof(*this));
        fout.close();
        return(1);

    }
}
void student::viewAlldata()
{
    ifstream fin;
    fin.open("file.dat",ios::in|ios::binary);
    if(!fin)
        cout<<"error file not found:";
    else{
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof()){
            if(gender=='F')
            {
                showdata(); 
            }
           fin.read((char*)this,sizeof(*this));
        }
        fin.close();
    }


    fin.open("file.dat",ios::in|ios::binary);
    if(!fin)
        cout<<"error file not found:";
    else{
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof()){
            if(gender=='M')
            {
                showdata(); 
            }
           fin.read((char*)this,sizeof(*this));
        }
        fin.close();
    }
}
void student::searchData(char *t)
{
    int count=0;
    ifstream fin;
    fin.open("file.dat",ios::in|ios::binary);
    if(!fin)
        cout<<"error file not found:";
    else{
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof()){
            if(!strcmp(t,name)){
                showdata();
                count++;
            }
           fin.read((char*)this,sizeof(*this));
        }
        if(count==0)
            cout<<"\n record not found:";
        fin.close();
    }
}
void student::showsearch()
{
    cout<<"\t\t*************************************"<<"\n";
    cout<<"\t\t*                                   *"<<"\n";
    cout<<"\t\t*      STUDENT SEARCH OPTION        *"<<"\n";
    cout<<"\t\t*                                   *"<<"\n";
    cout<<"\t\t*************************************"<<"\n";
    char ser[30];
    cout<<"\t\t Enter Name of the student:";
    fflush(stdin);
    cin.getline(ser,29);
    searchData(ser);
}
void student::deleteData(char *t)
{
    ifstream fin;
    ofstream fout;
    fin.open("file.dat",ios::in|ios::binary);
    if(!fin)
    {
        //ccolor(12);
        cout<<"Error file not found:";
    }

    else{
        fout.open("temp.dat",ios::out|ios::binary);
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
            if(strcmp(name,t))
                fout.write((char*)this,sizeof(*this));
            fin.read((char*)this,sizeof(*this));
        }
        fin.close();
        fout.close();
        remove("file.dat");
        rename("temp.dat","file.dat");
    }
}
void student::updateData(char *t)
{
    fstream file;
    file.open("file.dat",ios::in|ios::out|ios::ate|ios::binary);
    file.seekg(0);
    file.read((char*)this,sizeof(*this));
    while(!file.eof())
    {
        if(!strcmp(t,name)){
            getdata();
            file.seekp(file.tellp()-sizeof(*this));
            file.write((char*)this,sizeof(*this));
        }
        file.read((char*)this,sizeof(*this));
    }
}

int main()
{
    student s1;
    room_no al;
    remove("file.dat");
    s1.loadingbar();
    s1.intro();
    loginsystem ob,ob2;
    lb:
    ob.input();
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

    int choice;
    while(choice!=6)
    {
        system("cls");
    cout<<"*****************************************************************"<<"\n";
    cout<<"***                                                           ***"<<"\n";
    cout<<"***              1. Insert Student record.                    ***"<<"\n";
    cout<<"***              2. Lotterycand alloted room                  ***"<<"\n";
    cout<<"***              3. View all record data after alloted.       ***"<<"\n";
    cout<<"***              4. Search Student record.                    ***"<<"\n";
    cout<<"***              5. Delete Student record.                    ***"<<"\n";
    cout<<"***              6. Update Student record.                    ***"<<"\n";
    cout<<"***              7. For Exit the program.                     ***"<<"\n";
    cout<<"***                                                           ***"<<"\n";
    cout<<"*****************************************************************"<<"\n";
    cout<<"\n        Enter Your choice:";
    cin>>choice;
    switch(choice)
    {
    case 1:
        s1.getdata();
        s1.storedata();
        cout<<"\n\t\t Data is Successfully Stored:";
        getch();
        break;
    case 2:
        al.allot();
        //s1.viewAlldata();
        getch();
        break;
    case 3:
        s1.viewAlldata();
        getch();
        break;
    case 4:
        s1.showsearch();
        getch();
        break;
    case 5:
       cout<<"\n\n Enter Student Name to delete a record:";
        char name[30];fflush(stdin);
        cin.getline(name,29);
        s1.deleteData(name);
        cout<<"\n\t\t Data is Successfully Deleted:";
        getch();
        break;
    case 6:
        cout<<"\n\n Enter Student Name to Update a record:";fflush(stdin);
        cin.getline(name,29);
        s1.updateData(name);
        cout<<"\n\t\t Data is Successfully Updated:";
        getch();
        break;
    case 7:
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
    getch();
}