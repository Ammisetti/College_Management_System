#include<bits/stdc++.h>
#include<conio.h>
using namespace std;
char un[20];
class Admin
{
    char name[20];
    int totsub;
    char subject[10][10];
    char mobile[15], mail[50], fname[20];
    char password[20], rpassword[20];
public:
    char rollno[15];
    /*this function is used to get the student data entry form
    the ADMIN portal.....all the record entries are made by
    this method*/
    void getstdata()
    {
        system("cls");
        cout<<"\nEnter the Details :- \n";
        cout<<"\nEnter the Student Name         : ";
        cin>>name;
        cout<<"\nEnter the Student ID/Roll No.  : ";
        cin>>rollno;
        cout<<"\nEnter the Student Father Name  : ";
        cin>>fname;
        cout<<"\nEnter the Mobile Number        : ";
        cin>>mobile;
        cout<<"\nEnter the E-Mail ID            : ";
        cin>>mail;
        cout<<"\nEnter the Total Subjects       : ";
        cin>>totsub;
        for(int i=0;i<totsub;i++)
        {
            cout<<"\nEnter the subject "<<i+1<<" Name : ";
            cin>>subject[i];
        }
        cout<<"\nCreate Your Login Password     : ";
        cin>>password;
        cout<<"\nEnter the Unique Keyword to Recover Password : ";
        cin>>rpassword;
        cout<<"\n\nPlease note your UserName is ID/Roll No.\n";
    }
    /*this function authentication the login of both the student & faculties.
    with their reference to their Unique ID/PASSWORD login is provided.*/
    int login()
    {
        if((strcmp(::un,rollno)) == 0)
        {
            cout<<"\nEnter the login Password : ";
            int len = 0;
            len = strlen(password);
            char inputpassword[20];
            for(int i=0;i<len;i++)
            {
                inputpassword[i] = getch();
                cout<<"*";
            }
            if((strcmp(::un,rollno) == 0) && (strcmp(password, inputpassword)) == 0)
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
    /*this function help both the students & faculties to recover the password with the help
    of unique keyword provided by the ADMIN.*/
    int recover()
    {
        char key[20];
        if((strcmp(::un,rollno)) == 0)
        {
            cout<<"\nEnter the Unique Keyword (Provided by Admin) : ";
            cin>>key;
            if((strcmp(key,rpassword) == 0))
            {
                cout<<"\nYou are a Valid User.\n";
                cout<<"\nYour Password is : "<<password;
                cout<<"\nPlease Exit to Login Again. ";
                return 1;
            }
            else
                return 0;
        }
        else
            return 0;
    }
    /*this function displays the faculty profile to the faculty at their respective portals*/
    int faprofile()
    {
        if((strcmp(::un,rollno)) == 0)
        {
            cout<<"\nFaculty Name           : "<<name;
            cout<<"\nFaculty Father's Name  : "<<fname;
            cout<<"\nFaculty Mobile Number  : "<<mobile;
            cout<<"\nFaculty E-Mail ID      : "<<mail;
            return 1;
        }
        else
            return 0;
    }
    //this function displays the different subjects of the faculty at their respective portal.*/
    int knowfasub()
    {
        if((strcmp(::un,rollno)) == 0)
        {
            cout<<"\nFaculty Total Subjects :- "<<totsub;
            for(int i=0;i<totsub;i++)
            {
                cout<<"\n\tSubject "<<i+1<<" : "<<subject[i];
            }
            return 1;
        }
        else
            return 0;
    }
    //this function helps a faculty to add a subject in their module.
    void addfsub()
    {
        if((strcmp(::un, rollno)) == 0)
        {
            cout<<"\nEnter the New Subject : ";
            cin>>subject[totsub];
            totsub++;
            cout<<"\n\nNew Subject Added Successfully...";
        }
    }
    //this function helps a faculty to delete a subject from their module.
    void delfasub()
    {
        knowfasub();
        int de = 0;
        if((strcmp(::un, rollno)) == 0)
        {
            if(totsub == 0 || totsub<0)
            {
                totsub = 0;
                cout<<"\nNone Subjects Exits...";
                getch();
                exit(0);
            }
            cout<<"\nEnter the Subject No. to be Deleted : ";
            cin>>de;
            if(de == totsub)
            {
                totsub--;
                strcpy(subject[totsub]," ");
            }
            else if(totsub == 1)
            {
                totsub = 0;
                strcpy(subject[totsub]," ");
            }
            else
            {
                de--;
                strcpy(subject[totsub]," ");
                for(int p = de;p<totsub;p++)
                    strcpy(subject[p],subject[p+1]);
                totsub--;
            }
            cout<<"\nRecords Updated Successfully...\n";
        }
    }
    //this function helps a faculty to modify his personal profile
    void modfaprofile()
    {
        if((strcmp(::un,rollno)) == 0)
        {
            cout<<"\nThe Profile Details are : ";
            cout<<"\n 1. Faculty E-Mail : "<<mail;
            cout<<"\n 2. Faculty Mobile : "<<mobile;
            int g = -1;
            cout<<"\n\nEnter the Detail NO. to be Modified : ";
            cin>>g;
            if(g == 1)
            {
                char mail[50];
                cout<<"\nEnter the New Mail Address : ";
                strcpy(mail,mail);
                cout<<"\nRecords Updated Successfully...\n";
            }
            else if(g == 2)
            {
                char nmobile[15];
                cout<<"\nEnter the New Mobile Number : ";
                cin>>nmobile;
                strcpy(mobile,nmobile);
                cout<<"\nRecords Updated Successfully...\n";
            }
            else
                cout<<"\nInvalid Input Provided !!!";
        }
    }
    //This function displays the student profile at the student portal
    int stprofile()
    {
        if((strcmp(::un,rollno)) == 0)
        {
            cout<<"\nStudent Name           : "<<name;
            cout<<"\nStudent Father's Name  : "<<fname;
            cout<<"\nStudent Mobile No.     : "<<mobile;
            cout<<"\nStudent E-Mail ID      : "<<mail;
        }
        else
            return 0;
    }
    //this function displays the different enrolled subjects of the respective students...according to their profile.
    int knowstsub()
    {
        if((strcmp(::un, rollno)) == 0)
        {
            cout<<"\nStudent Total Subjects :- "<<totsub;
            for(int i=0;i<totsub;i++)
                cout<<"\n\tSubject "<<i+1<<" : "<<subject[i];
            return 1;
        }
        else
            return 0;
    }
    //this function allows the student to add a subjects in total subjects of the student profile...
    void addstsub()
    {
        if((strcmp(::un, rollno)) == 0)
        {
            cout<<"\nEnter the New Subject : ";
            cin>>subject[totsub];
            totsub++;
            cout<<"\nNew Subject Added Successfully...";
        }
    }
    //this function allows the student to delete a subjects in total subjects of the student profile...
    void delstsub()
    {
        knowstsub();
        int de=0;
        if((strcmp(::un,rollno)) == 0)
        {
            if(totsub == 0 || totsub < 0)
            {
                totsub = 0;
                cout<<"\nNone Subjects Exists...";
                getch();
                exit(0);
            }
            cout<<"\nEnter the Subjects No. to be Deleted : ";
            cin>>de;
            if(de == totsub)
            {
                totsub--;
                strcpy(subject[totsub]," ");
            }
            else if(totsub == 1)
            {
                totsub = 0;
                strcpy(subject[totsub]," ");
            }
            else
            {
                de--;
                strcpy(subject[totsub]," ");
                for(int p = de;p<totsub;p++)
                    strcpy(subject[p],subject[p+1]);
                totsub--;
            }
            cout<<"\nRecords Updated Successfully...";
        }
    }
    //this function allows the student to modify their personal profile details at the student portal
    void modstprofile()
    {
        if((strcmp(::un,rollno)) == 0)
        {
            cout<<"\nThe Profile Details are : ";
            cout<<"\n 1. Student E-Mail : "<<mail;
            cout<<"\n 2. Student Mobile : "<<mobile;
            int g = -1;
            cout<<"\n\nEnter the Detail No. to be Modified : ";
            cin>>g;
            if(g == 1)
            {
                char nmail[50];
                cout<<"\nEnter the New Mail Address : ";
                strcpy(mail,nmail);
                cout<<"\nRecords Updated Successfully...";
            }
            else if(g == 2)
            {
                char nmobile[15];
                cout<<"\nEnter the New Mobile Number : ";
                cin>>nmobile;
                strcpy(mobile,nmobile);
                cout<<"\nRecords Updated Successfully...\n";
            }
            else
                cout<<"\nInvalid Input Provided !!!";
        }
    }
    //This function allow the ADMIN to make a new Record Entry for the different new faculty...
    //new Faculty records are updated with the help of this function...
    void getfadata()
    {
        system("cls");
        cout<<"\nEnter the Details :- \n";
        cout<<"\nEnter the Faculty Name             : ";cin>>name;
        cout<<"\nEnter the Faculty ID/Roll no.      : ";cin>>rollno;
        cout<<"\nEnter the Faculty Father Name      : ";cin>>fname;
        cout<<"\nEnter the Mobile No.               : ";cin>>mobile;
        cout<<"\nEnter the E-Mail ID                : ";cin>>mail;
        cout<<"\nEnter the Total Subjects           : ";cin>>totsub;
        for(int i=0;i<totsub;i++)
        {
            cout<<"\nEnter the Subject"<<i+1<<" Name : ";
            cin>>subject[i];
        }
        cout<<"\nCreate Your Login Password : ";
        cin>>password;
        cout<<"\nEnter the Unique Keyword to Recover Password : ";
        cin>>rpassword;
        cout<<"\n\nPlease note your UserName is ID/Roll No.\n\n";
    }
    //This function displays all the relevant information to the ADMIN related to the
    //Students at the ADMIN portals
    void stdispaly()
    {
        cout<<"\nStudent Name           : "<<name;
        cout<<"\nStudent ID/Roll No.    : "<<rollno;
        cout<<"\nStudent Father's Name  : "<<fname;
        cout<<"\nStudent Mobile Number  : "<<mobile;
        cout<<"\nStudent E-Mail ID      : "<<mail;
        cout<<"\nStudent Subjects       : "<<totsub;
        for(int i=0;i<totsub;i++)
            cout<<"\nSubject "<<i+1<<" : "<<subject[i];
        if(totsub == 0)
            cout<<"(None Subjects Specified...)";
    }
    //This function displays all the relevant information to the ADMIN related to
    //the faculty at the ADMIN portals.
    void fadisplay()
    {
        cout<<"\nFaculty Name           : "<<name;
        cout<<"\nFaculty ID/Roll No.    : "<<rollno;
        cout<<"\nFaculty Father's Name  : "<<fname;
        cout<<"\nFaculty Mobile No.     : "<<mobile;
        cout<<"\nFaculty E-Mail ID      : "<<mail;
        cout<<"\nFaculty Subjects       : "<<totsub;
        for(int i=0;i<totsub;i++)
            cout<<"\nSubject "<<i+1<<" : "<<subject[i];
        if(totsub == 0)
            cout<<"\nNone Subjects Specified...";
    }
}a;
Admin f;

//a & f are the objects of the class ADMIN

int main()
{
    int ch;
    cout<<"\n\n\n\t\t\t..Welcome to SURYA Database Portal..";
    cout<<"\n\n\n\t\t\t\t..Enter to Continue..";
    getch();
    system("cls");
    cout<<"\n\n\n\t\t\tPress 1 for ADMIN Portal";
    cout<<"\n\t\t\tPress 2 Faculty Portal";
    cout<<"\n\t\t\tPress 3 Student Portal";
    cout<<"\n\n\t\t\tEnter Your Choice : ";
    cin>>ch;
    system("cls");
    if(ch == 1)
    {
        char adminuser[20], adminpass[20];
        cout<<"\n\t\t\tWelcome To ADMIN Login Portal ";
        cout<<"\n\nEnter the UserName : ";
        cin>>adminuser;
        cout<<"\nEnter the Password : ";
        for(int k=0;k<8;k++)
        {
            adminpass[k] = getch();
            cout<<"*";
        }
        adminpass[8] = '\0';
        if((strcmp(adminuser, "admin"))== 0 && (strcmp(adminpass,"password")) == 0)
            system("cls");
        else
        {
            cout<<"\n\n\t\t\t Invalid Access to Portal";
            cout<<"\n\n\t\t\t Thank You !!!\n\n\n\n";
            getch();
            exit(0);
        }
        char opera = 'y';
        do
        {
            system("cls");
            int temp;
            cout<<"\n\t\t\t Welcome To ADMIN Panel";
            cout<<"\n\nPress 1 to Add Single Faculty Record ";
            cout<<"\nPress 2 to Add Multiple Records of Faculty ";
            cout<<"\nPress 3 to View All Records of Faculty ";
            cout<<"\nPress 4 to Delete a faculty Record ";
            cout<<"\nPress 5 to Add a Student Record ";
            cout<<"\nPress 6 to Add Multiple Records of Students ";
            cout<<"\nPress 7 to View All Records of Students ";
            cout<<"\nPress 8 to Delete a Student Record";
            cout<<"\nPress 9 to Exit.";
            cout<<"\n\n\tEnter Your Choice : ";
            cin>>temp;
            system("cls");
            if(temp == 1)   //for inserting d single faculty records
            {
                fstream fs;
                fs.open("fainfo.txt",ios::out | ios::ate | ios::app);
                a.getfadata();
                fs.write((char *)&a, sizeof(Admin));
                fs.close();
                cout<<"\nRecord Entered Successfully...";
            }   //for inserting single faculty records.
            else if(temp == 2)   //for inserting multiple records
            {
                int m =0;
                fstream fs;
                do
                {
                    fs.open("fainfo.txt",ios::out | ios::ate | ios::app);
                    if(!fs)
                    {
                        cout<<"File Not Found"<<endl;
                        exit(0);
                    }
                    a.getfadata();
                    fs.write((char * )&a, sizeof(Admin));
                    fs.close();
                    cout<<"\nEnter any character to Stop";
                    cout<<"\nEnter 0 if you want to Enter More Records : ";
                    cin>>m;
                }while(m == 0);
            }   //for inserting multiple records.
            else if(temp == 3)   //for view all faculty records
            {
                fstream fs;
                fs.open("fainfo.txt",ios::in);
                if(!fs)
                    cout<<"File Not Found"<<endl;
                fs.seekg(0);
                while(fs.read((char *)&a, sizeof(Admin)))
                {
                    a.fadisplay();
                    cout<<endl<<endl<<"----------------------------"<<endl;
                }
                fs.close();
            }   //for view of all faculty records.
            else if(temp == 4)   //for deleting a faculty records
            {
                char tmpfaid[15];
                int de = 0, result = -1;
                cout<<"\nEnter the Faculty ID/Roll No :- ";
                cin>>tmpfaid;
                fstream fs;
                fs.open("fainfo.txt",ios::in);
                fstream fsl;
                fsl.open("fanewinfo.txt",ios::out);
                while(fs.read((char *)&a, sizeof(Admin)))
                {
                    result = strcmp(tmpfaid,a.rollno);
                    if(result == 0)
                        de = 1;
                    else
                        fsl.write((char *)&a, sizeof(Admin));
                }
                if(de == 1)
                    cout<<"\nRecord Deleted Successfully.....";
                else
                    cout<<"\nRecord Not Found.....";
                fs.close();
                fsl.close();
                remove("fainfo.txt");
                rename("fanewinfo.txt","fainfo.txt");
            }   //for deleting faculty record
            else if(temp == 5)   //for single student record input
            {
                fstream fs;
                fs.open("stinfo.txt",ios::out | ios::ate | ios::app);
                a.getstdata();
                fs.write((char *)&a, sizeof(Admin));
                fs.close();
                cout<<"\nRecord Entered Successfully.....";
            }   //for single student record input
            else if(temp == 6)   //Add multiple records of students
            {
                int m = 0;
                fstream fs;
                fs.open("stinfo.txt",ios::out | ios::ate | ios::app);
                do
                {
                    a.getstdata();
                    fs.write((char *)&a, sizeof(Admin));
                    cout<<"\nEnter any character to Stop";
                    cout<<"\nEnter 0 if you want to Enter More Records : ";
                    cin>>m;
                }while(m == 0);
            }   //add multiple records of students
            else if(temp == 7)   //View records of students
            {
                fstream fs;
                fs.open("stinfo.txt",ios::in);
                if(!fs)
                    cout<<"File Not Found"<<endl;
                fs.seekg(0);
                while(fs.read((char *)&a, sizeof(Admin)))
                {
                    a.stdispaly();
                    cout<<endl<<endl<<"----------------------------"<<endl;
                }
                fs.close();
            }   //for view of all student records.
            else if(temp == 8)   //for deleting a student record
            {
                char tmpstid[15];
                int de = 0, result = -1;
                cout<<"\nEnter the student ID/Roll No. :- ";
                cin>>tmpstid;
                fstream fs;
                fs.open("stinfo.txt",ios::in);
                fstream fsl;
                fsl.open("stnewinfo.txt",ios::out | ios::ate);
                while(fs.read((char *)&a, sizeof(Admin)))
                {
                    result = strcmp(tmpstid, a.rollno);
                    if(result == 0)
                        de = 1;
                    else
                        fsl.write((char *)&a, sizeof(Admin));
                }
                if(de == 1)
                    cout<<"\nRecord Deleted Successfully......";
                else
                    cout<<"\nRecord not found......";
                fs.close();
                fsl.close();
                remove("stinfo.txt");
                rename("stnewinfo.txt","stinfo.txt");
            }   //for deleting a student record
            else if(temp == 9)   //for exit
            {
                cout<<"\n\n\n\n\t\t\tThank You !!!\n\n\n\n";
                getch();
                exit(0);
            }   //for exit
            else
            {
                system("cls");
                cout<<"\n\n\n\t\t\t\tInvalid Input.........";
            }   //for invalid input among choice of operation
            getch();
            cout<<"\n\nPress y ; For More Operations otherwise n : ";
            cin>>opera;
            if(opera != 'y')
            {
                getch();
                system("cls");
                cout<<"\n\n\n\n\n\t\t\t\t\tThank You !!!\n\n\n\n";
                getch();
            }   //closing of thank you.
        }while(opera == 'y' || opera == 'Y');
    }   // closing of ADMIN Portal

    if(ch == 2) //begin of faculty Login Page
    {
        system("cls");
        char un[20];
        int val, s =0;
        cout<<"\n\t\tWelcome to Faculty Login Page";
        cout<<"\n\nEnter the UserName : ";
        cin>>::un;
        fstream fs;
        fs.open("fainfo.txt",ios::in | ios::binary);
        fs.seekg(0);
        while(fs.read((char *)&f, sizeof(Admin)))
        {
            val = -1;
            val = f.login();
            if(val == 1)
            {
                s = 1;
                break;
            }
        }
        fs.close();
        if(s == 1)
        {
            system("cls");
        }   //if first login is valid
        if(s != 1)
        {
            system("cls");
            int ho = 0;
            cout<<"\n\n\t\tYour Login Credentials are In-Correct...\n\n";
            cout<<"\nThe UserName is Your ID/Roll No...";
            cout<<"\nThe Password is Case-Sensitive...";
            cout<<"\n\n1. Press 1 to Re-Cover Password\n2. Press 2 to Re-Attempt Login";
            cout<<"\nEnter Your Choice : ";
            cin>>ho;
            if(ho == 1) //recover password
            {
                cout<<"\nEnter the UserName :- ";
                cin>>::un;
                fstream fs;
                fs.open("fainfo.txt",ios::in | ios::binary);
                fs.seekg(0);
                int re, su=-1;
                while(fs.read((char *)&f, sizeof(Admin)))
                {
                    re = -1;
                    re = f.recover();
                    if(re == 1)
                    {
                        su = 1;
                        break;
                    }
                }
                fs.close();
                if(su == 1)
                {
                    getch();
                    system("cls");
                    cout<<"\n\n\n\n\t\t\tThank You !!!\n\n\n\n";
                    getch();
                    exit(0);
                }
                else
                {
                    cout<<"\nYou are a Invalid User.";
                    getch();
                    exit(0);
                }
            }   //recover password
            else if(ho == 2) //re-attempt to login FACULTY PORTAL
            {
                cout<<"\nEnter the UserName : ";
                cin>>::un;
                fstream fs;
                fs.open("fainfo.txt",ios::in | ios::binary);
                fs.seekg(0);
                int suc = -1, valu;
                while(fs.read((char *)&f, sizeof(Admin)))
                {
                    valu = -1;
                    valu = f.login();
                    if(valu == 1)
                    {
                        suc = 1;
                        break;
                    }
                }
                fs.close();
                if(suc == 1)
                {
                    system("cls");
                }
                else
                {
                    getch();
                    cout<<"\nYou are an Invalid User...";
                    cout<<"\nThank You !!!\n\n\n\n";
                    getch();
                    exit(0);
                    //exit(0);
                }
            }
            else
            {
                cout<<"\n\nInvalid Input Provided !!!";
                cout<<"\n\n\t\t\tThank You !!!\n\n\n\n";
                exit(0);
            }
        }   //CLOSING OF FIRST IVALID LOGIN (FORGOT AND RECOVER PASSWORD)

        //BEGIN OF FACUTLY
        do
        {
            system("cls");
            cout<<"\n\n\t\t\tWelcome to Faculty Panel ";
            cout<<"\n\n\t\t\t\t\t\tYour UserId is : "<<::un;
            cout<<"\n\n1. Press 1 to View Your Profile.";
            cout<<"\n2. Press 2 to Know Your Subjects.";
            cout<<"\n3. Press 3 to Add a Subject.";
            cout<<"\n4. Press 4 to Delete a Subject.";
            cout<<"\n5. Press 5 to Modify Your Profile.";
            cout<<"\n6. Exit.";
            int choice;
            cout<<"\n\nEnter Your Choice : ";
            cin>>choice;

            if(choice == 1) //VIEW YOUR PROFILE IN FACULTY PORTAL
            {
                fstream fs;
                fs.open("fainfo.txt", ios::in);
                fs.seekg(0);
                int x;
                while(fs.read((char *)&f, sizeof(Admin)))
                {
                    x = 0;
                    x = f.faprofile();
                    if(x == 1)
                    {
                        break;
                    }
                }
                fs.close();
            }   //closing of choice 1(VIEW YOUR PROFILE) IN FACULTY PORTAL

            else if(choice == 2) // KNOW YOUR SUBJECTS IN FACULTY PORTAL
            {
                fstream fs;
                fs.open("fainfo.txt",ios::in);
                fs.seekg(0);
                int y;
                while(fs.read((char *)&f, sizeof(Admin)))
                {
                    y = 0;
                    y = f.knowfasub();
                    if(y == 1)
                    {
                        break;
                    }
                }
                fs.close();
            }   //closing of choice 2 (KNOW YOUR SUBJECTS) IN FACULTY PORTAL

            else if(choice == 3) // ADD A SUBJECT IN FACULTY PORTAL
            {
                fstream fs;
                fstream fsl;
                fs.open("fainfo.txt",ios::in | ios::binary);
                fsl.open("tmpfinfo.txt",ios::out | ios::ate);
                fs.seekg(0);
                while(fs.read((char *)&f, sizeof(Admin)))
                {
                    f.addfsub();
                    fsl.write((char *)&f, sizeof(Admin));
                }
                fs.close();
                fsl.close();
                remove("fainfo.txt");
                rename("tmpfinfo.txt","fainfo.txt");
            }   //closing of ADD A SUBJECT IN FACULTY PORTAL

            else if(choice == 4) //DELETE A SUBJECT IN FACLUTY PORTAL
            {
                fstream fs;
                fstream fsl;
                fs.open("fainfo.txt",ios::in | ios::binary);
                fsl.open("delfainfo.txt",ios::out | ios::ate);
                fs.seekg(0);
                while(fs.read((char *)&f, sizeof(Admin)))
                {
                    f.delfasub();
                    fsl.write((char *)&f, sizeof(Admin));
                }
                fs.close();
                fsl.close();
                remove("fainfo.txt");
                rename("delfainfo.txt","fainfo.txt");
            }   //END OF DEL SUB IN FACULTY PORTAL

            else if(choice == 5)     //Modify profile in FACULTY PORTAL
            {
                fstream fs;
                fstream fsl;
                fs.open("fainfo.txt",ios::in | ios::ate | ios::app);
                fsl.open("modfainfo.txt",ios::out | ios::ate);
                fs.seekg(0);
                while(fs.read((char *)&f, sizeof(Admin)))
                {
                    f.modfaprofile();
                    fsl.write((char *)&f, sizeof(Admin));
                }
                fs.close();
                fsl.close();
                remove("fainfo.txt");
                rename("modfainfo.txt","fainfo.txt");
            }   //End of Modify profile in FACULTY PORTAL

            else if(choice == 6)
            {
                cout<<"\n\n\n\n\t\t\tThank You !!!\n\n\n\n";
                getch();
                exit(0);
            }

            else
                cout<<"\nInvalid Input Provided !!!";

            cout<<"\n\n\t\t\t\tEnter To Continue";
            getch();
        }while(true);
    }       //CLOSE OF FACULTY PORTAL

    if(ch == 3)     //BEGIN OF STUDENT PORTAL
    {
        system("cls");
        int val, s1 = 0;
        cout<<"\n\t\t\tWelcome to Student Login Page ";
        cout<<"\n\nEnter the UserName : ";
        cin>>::un;
        fstream fs;
        fs.open("stinfo.txt",ios::in | ios :: binary);
        fs.seekg(0);
        while(fs.read((char *)&f, sizeof(Admin)))
        {
            val  = -1;
            val = f.login();
            if(val == 1)
            {
                s1 = 1;
                break;
            }
        }
        fs.close();
        if(s1 == 1)
        {
            system("cls");
        }   //if first login is Valid

        if(s1 != 1) //if first login is invalid
        {
            system("cls");
            int sho=0;
            cout<<"\n\n\t\tYour Login Credentials are In-Correct.";
            cout<<"\nThe UserName is Your ID/Roll No.";
            cout<<"\nThe Password is Case-Sensitive.";
            cout<<"\n\n1. Press 1 to Re-Cover Password.\n2. Press 2 to Re-Attempt to Login";
            cout<<"\nEnter the Choice : ";
            cin>>sho;
            if(sho == 1)    //recover password
            {
                cout<<"\nEnter the UserName : ";
                cin>>::un;
                fstream fs;
                fs.open("stinfo.txt",ios::in | ios::binary);
                fs.seekg(0);
                int re, su = -1;
                while(fs.read((char * )&f, sizeof(Admin)))
                {
                    re = -1;

                    re = f.recover();
                    if(re == 1)
                    {
                        su = 1;
                        break;
                    }
                }
                fs.close();
                if(su == 1)
                {
                    getch();
                    system("cls");
                    cout<<"\n\n\n\n\t\t\tThank You !!!\n\n\n\n";
                    getch();
                    exit(0);
                }
                else
                {
                    cout<<"\n You are a Invalid User.";
                    cout<<"\n Thank You !!!\n\n\n\n";
                    exit(0);
                }
            }   //CLOSE OF RECOVER PASSWORD IN STUDENT PORTAL

            else if(sho == 2) //RE-ATTEMPT TO LOGI IN STUDENT PORTAL
            {
                cout<<"\n\nEnter the UserName : ";
                cin>>::un;
                fstream fs;
                fs.open("stinfo.txt",ios::in | ios::binary);
                fs.seekg(0);
                int suc = -1, valu;  //value for storing login()) return value
                while(fs.read((char *)&f, sizeof(Admin)))
                {
                    valu = -1;
                    valu = f.login();
                    if(valu == 1)
                    {
                        suc = 1;
                        break;
                    }
                }
                fs.close();
                if(suc == 1)
                {
                    system("cls");
                }
                else
                {
                    getch();
                    cout<<"\nYou are Invalid User...";
                    cout<<"\nThank You !!!\n\n\n\n";
                }
            }
            else
            {
                cout<<"\n\nInvalid Input Provided !!!";
                cout<<"\n\n\t\t\tThank You !!!\n\n\n\n";
                getch();
                exit(0);
            }   //CLOSING OF FIRST INVALID LOGIN(FORGOT & REATTEMPT PASSWORD)
        }

        //BEGIN OF STUDENT PORTAL
        do
        {
            system("cls");
            cout<<"\n\n\t\t\tWelcome to Student Panel.";
            cout<<"\n\n\t\t\t\t\t\t Your UserId is : "<<::un;
            cout<<"\n\n1. Press 1 to View Your Profile.";
            cout<<"\n2. Press 2 to Know Your Subjects.";
            cout<<"\n3. Press 3 to Add Subject.";
            cout<<"\n4. Press 4 to Delete a Subjects.";
            cout<<"\n5. Press 5 to Modify Your Profile.";
            cout<<"\n6. Exit";
            int inchoice;
            cout<<"\n\nEnter Your Choice : ";
            cin>>inchoice;

            if(inchoice == 1)
            {
                fstream fs;
                fs.open("stinfo.txt",ios::in);
                fs.seekg(0);
                int x;
                while(fs.read((char *)&f, sizeof(Admin)))
                {
                    x = 0;
                    x = f.stprofile();
                    if(x == 1)
                    {
                        break;
                    }
                }
                fs.close();
            }   //CLOSING OF VIEW PROFILE OF STUDENT

            else if(inchoice == 2)      //KNOW SUBJECTS IN STUDENT PORTAL
            {
                fstream fs;
                fs.open("stinfo.txt", ios::in);
                fs.seekg(0);
                int y;
                while(!fs.eof())
                {
                    y = 0;
                    fs.read((char *)&f, sizeof(Admin));
                    y = f.knowstsub();
                    if(y == 1)
                        break;
                }
                fs.close();
            }   //CLOSE OF KNOW SUBJECTS IN STUDENT PORTAL

            else if(inchoice == 3)       //ADD SUBJECT IN STUDENT PORTAL
            {
                fstream fs;
                fstream fsl;
                fs.open("stinfo.txt",ios::in | ios::binary);
                fsl.open("tmpstinfo.txt",ios::out | ios::ate);
                fs.seekg(0);
                while(fs.read((char *)&f, sizeof(Admin)))
                {
                    f.addstsub();
                    fsl.write((char *)&f, sizeof(Admin));
                }
                fs.close();
                fsl.close();
                remove("stinfo.txt");
                rename("tmpstinfo.txt","stinfo.txt");
            }   //CLOSING OF ADD SUBJECT IN STUDENT PORTAL

            else if(inchoice == 4)   //DELETE SUBJECT IN STUDENT PORTAL
            {
                fstream fs;
                fstream fsl;
                fs.open("stinfo.txt", ios::in | ios::binary);
                fsl.open("delstinfo.txt", ios::out | ios::ate);
                fs.seekg(0);
                while(fs.read((char *)&f, sizeof(Admin)))
                {
                    f.delstsub();
                    fsl.write((char *)&f, sizeof(Admin));
                }
                fs.close();
                fsl.close();
                remove("stinfo.txt");
                rename("delstinfo.txt","stinfo.txt");
            }   //CLOSING OF DELETE A SUBJECT IN STUDENT PORTAL

            else if(inchoice == 5)   //MODIFY YOUR PROFIEL (IN STUDENT PORTAL)
            {
                fstream fs;
                fstream fsl;
                fs.open("stinfo.txt", ios::in | ios:: binary | ios::app);
                fsl.open("modstinfo.txt",ios::out | ios :: ate);
                fs.seekg(0);
                while(fs.read((char *)&f, sizeof(Admin)))
                {
                    f.modstprofile();
                    fsl.write((char *)&f, sizeof(Admin));
                }
                fs.close();
                fsl.close();
                remove("stinfo.txt");
                rename("modstinfo.txt", "stinfo.txt");
            }   //CLOSE OF MODIFY PROFILE IN STUDENT PORTAL

            else if(inchoice == 6)
            {
                cout<<"\n\n\n\n\t\t\tThank You !!!\n\n\n\n";
                getch();
                exit(0);
            }

            else
                cout<<"\nInvalid Input Provided !!!....";
            cout<<"\n\n\t\t\tEnter to Continue....";
            getch();
        }while(true);
    }   //CLOSING OF STUDENT PORTAL

    if(ch < 1 || ch >3 )
    {
        cout<<"\nInvalid Input Provided !!!....";
        getch();
        system("cls");
        cout<<"\n\n\n\t\t\tThank You !!!\n\n\n\n";
    }
    return 0;
}
