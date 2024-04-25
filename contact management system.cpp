#include<fstream>
#include<iostream>
#include<string.h>
#include<iomanip>
#include<windows.h>
#include<conio.h>
using namespace std;
class contact{
private:
    string ph, name, add, email;
public:
    void save_contact();
    void show_all_contact();
    void search_contact();
    void edit_contact();
    void delete_contact();
    void create()
    {
        system("cls");
        cin.ignore();
        cout<<"Enter Phone: ";
        getline(cin, ph);

//        cin.ignore();

        cout<<"Enter name: ";
        getline(cin, name);

//        cin.ignore();

        cout<<"Enter address: ";
        getline(cin, add);

//        cin.ignore();

        cout<<"Enter email-id: ";
        getline(cin, email);

        cout<<endl;
    }

    void show_contact()
    {
        system("cls");
        cout<<"\t\t\t\t\t\tphone: "<<ph<<endl;
        cout<<"\t\t\t\t\t\tname: "<<name<<endl;
        cout<<"\t\t\t\t\t\taddress: "<<add<<endl;
        cout<<"\t\t\t\t\t\temail: "<<email<<endl;
    }

    void update_contact()
    {
        system("cls");
        cout<<"Enter new Phone: ";
        getline(cin, ph);

        cout<<"Enter new name: ";
        getline(cin, name);

        cout<<"Enter new address: ";
        getline(cin, add);

        cout<<"Enter new email-id: ";
        getline(cin, email);

        cout<<endl;
    }

    void menu()
    {
        system("cls");
        cout<<"\n\t\t     ___________________________________________________________________________________________"<<endl;
        cout<<"\t\t    |                                                  \t\t\t\t\t        |";
        cout<<"\n\t\t    |\t\t\t               CONTACT MANAGEMENT SYSTEM                                |"<<endl;
        cout<<"\t\t    |                                                  \t\t\t\t\t        |";
        cout<<"\n\t\t    |___________________________________________________________________________________________|"<<endl<<endl<<endl;
        cout<<"\n\t\t\t\t\t ______________________________________\n";
        cout<<"\t\t\t\t\t|                                      |";
        cout<<"\n\t\t\t\t\t|                 MENU                 |";
        cout<<"\n\t\t\t\t\t|______________________________________|";
        cout<<"\n\t\t\t\t\t|                                      |";
        cout<<"\n\t\t\t\t\t|Kindly select an option below:        |";
        cout<<"\n\t\t\t\t\t|1. SAVE CONTACT                       |";
        cout<<"\n\t\t\t\t\t|2. LIST OF ALL CONTACTS               |";
        cout<<"\n\t\t\t\t\t|3. SEARCH CONTACT                     |";
        cout<<"\n\t\t\t\t\t|4. EDIT CONTACT                       |";
        cout<<"\n\t\t\t\t\t|5. DELETE CONTACT                     |";
        cout<<"\n\t\t\t\t\t|6. EXIT                               |"<<endl;
        cout<<"\t\t\t\t\t|______________________________________|"<<endl<<endl;
        int ch;
        cout<<"\t\t\t\t\t->";
        cin>>ch;
        system("cls");
        switch(ch)
        {
            case 1:
                save_contact();
                break;
            case 2:
                show_all_contact();
                break;
            case 3:
                search_contact();
                break;
            //case 4:
                //edit_contact();
                //break;
            case 5:
                delete_contact();
                break;
            default:
                break;
        }
    }

};

fstream file;
contact c;

void contact::save_contact()
{
    system("cls");
    cout<<"\n\t\t\t\t ________________________________________\n";
    cout<<"\t\t\t\t|                                        |";
    cout<<"\n\t\t\t\t|               SAVE CONTACT             |"<<endl;
    cout<<"\t\t\t\t|________________________________________|"<<endl<<endl;
    file.open("phonedirectory", ios::in | ios::out | ios::app);
    if(!file)
    {
        cout<<"something went wrong please try again"<<endl;
    }
    else
    {
        p:
        create();
        while(ph[0]=='0' || ph[0]=='1' || ph[0]=='2' || ph[0]=='3' || ph[0]=='4' || ph[0]=='5')
        {
            cout<<"invalid number"<<endl<<endl;
            getch();
            goto p;
        }
        while(ph=="" || name=="" || add=="" || email=="")
        {
            cout<<"please enter proper & all the details!"<<endl;
            getch();
            goto p;
        }
        file<<ph<<endl<<name<<endl<<add<<endl<<email<<endl;
        cout<<"contact created successfully..."<<endl;
        file.close();
    }
    system("pause");
    menu();
}

void contact::show_all_contact()
{
    system("cls");
    cout<<endl;
    cout<<"\t\t\t\t\t ________________________________________\n";
    cout<<"\t\t\t\t\t|                                        |\n";
    cout<<"\t\t\t\t\t|           LIST OF ALL CONTACTS         |"<<endl;
    cout<<"\t\t\t\t\t|________________________________________|"<<endl<<endl;
    int x=1;
    file.open("phonedirectory", ios::in);
    if(!file)
        cout<<"no phone directory available"<<endl;
    else
    {
        file>>ph>>name>>add>>email;
        while(!file.eof())
        {
            Sleep(100);
            cout<<"\t\t\t\t\t\t\t("<<x++<<")"<<endl<<endl;
            cout<<"\t\t\t\t\t\t   phone: "<<ph<<endl;
            cout<<"\t\t\t\t\t\t   name: "<<name<<endl;
            cout<<"\t\t\t\t\t\t   address: "<<add<<endl;
            cout<<"\t\t\t\t\t\t   email: "<<email<<endl;
            file>>ph>>name>>add>>email;
            cout<<endl<<endl;
        }
        file.close();
        system("pause");
    }
    menu();
}

void contact::search_contact()
{
    system("cls");
    cout<<endl;
    cout<<"\t\t\t\t\t ________________________________________\n";
    cout<<"\t\t\t\t\t|                                        |\n";
    cout<<"\t\t\t\t\t|              SEARCH CONTACT            |"<<endl;
    cout<<"\t\t\t\t\t|________________________________________|"<<endl<<endl;
    bool found;
    found = false;
    file.open("phonedirectory", ios::in);
    string ch;
    cout<<"enter u want to search by name or number ? "<<endl;
    cin>>ch;
    if(ch == "number")
    {
        string num;
        cout<<"enter number to search: ";
        cin.ignore();
        getline(cin, num);
        file>>ph>>name>>add>>email;
        while(!file.eof())
        {
            if(ph==num)
            {
                cout<<"phone: "<<ph<<endl;
                cout<<"name: "<<name<<endl;
                cout<<"address: "<<add<<endl;
                cout<<"email: "<<email<<endl;
                found = true;
            }
            file>>ph>>name>>add>>email;
        }
        file.close();
        if(!found)
        {
            cout<<"no such contact saved!"<<endl;
        }
    }
    if(ch == "name")
    {
        string nm;
        cout<<"enter name to search: ";
        cin.ignore();
        getline(cin, nm);
        file>>ph>>name>>add>>email;
        while(!file.eof())
        {
            if(name==nm)
            {
                cout<<"phone: "<<ph<<endl;
                cout<<"name: "<<name<<endl;
                cout<<"address: "<<add<<endl;
                cout<<"email: "<<email<<endl;
                found = true;
            }
            file>>ph>>name>>add>>email;
        }
        file.close();
        if(!found)
        {
            cout<<"no such contact saved!"<<endl;
        }
    }
    system("pause");
    menu();
}

/*void contact::edit_contact()
{
    cout<<endl;
    cout<<"\t\t\t\t\t ________________________________________\n";
    cout<<"\t\t\t\t\t|                                        |\n";
    cout<<"\t\t\t\t\t|               EDIT CONTACTS            |"<<endl;
    cout<<"\t\t\t\t\t|________________________________________|"<<endl<<endl;
    system("cls");
    file.open("phonedirectory", ios::in);
    ofstream outfile("temp");
    if(!file.is_open())
    {
        cout<<"error opening the file."<<endl;
        return;
    }
    if(!outfile.is_open())
    {
        cout<<"error creating temp file."<<endl;
        file.close();
        return;
    }
    string line;
    bool found=false;

    string contactname;
    cout<<"enter name of contact to edit: "<<endl;
    cin.ignore();
    getline(cin, contactname);

    while(getline(file, line))
    {
        name = line;
        getline(file, ph);
        getline(file, add);
        getline(file, email);

        if(name == contactname)
        {
            found = true;
            cout<<"contact found:"<<endl;
            c.show_contact();
            c.update_contact();

            outfile<<ph<<endl<<name<<endl<<add<<endl<<email<<endl;
        }
        else{
            outfile<<ph<<endl<<name<<endl<<add<<endl<<email<<endl;
        }
    }
    file.close();
    outfile.close();

    if(!found)
    {
        cout<<"contact not found"<<endl;
        remove("temp");
    }
    else{
        remove("phonedirectory");
        rename("temp", "phonedirectory");
        cout<<"contact updated successfully"<<endl;
    }
    system("pause");
    menu();
}*/

void contact::delete_contact()
{
    system("cls");
    cout<<endl;
    cout<<"\t\t\t\t\t ________________________________________\n";
    cout<<"\t\t\t\t\t|                                        |\n";
    cout<<"\t\t\t\t\t|              DELETE CONTACT            |"<<endl;
    cout<<"\t\t\t\t\t|________________________________________|"<<endl<<endl;
    fstream file1;
    file.open("phonedirectory", ios::in);
    file1.open("modify", ios::app | ios::out);
    string nm;
    cout<<"enter name to delete:";
    cin.ignore();
    getline(cin, nm);
    file>>ph>>name>>add>>email;
    while(!file.eof())
    {
        if(nm==name)
        {
            file>>ph>>name>>add>>email;
        }
        else{
            file1<<ph<<endl<<name<<endl<<add<<endl<<email<<endl;
        }
        file>>ph>>name>>add>>email;
    }
    cout<<endl<<"deleting account...."<<endl;
    cout<<endl<<"account deleted successfully...."<<endl;
    file.close();
    file1.close();
    remove("phonedirectory");
    rename("modify", "phonedirectory");
    system("pause");
    menu();
}

int main()
{
    system("Color F0");
    c.menu();
    cout<<endl;
    cout<<"\t\t\t\t\t ________________________________________\n";
    cout<<"\t\t\t\t\t|                                        |\n";
    cout<<"\t\t\t\t\t|          THANKS FOR USING CMS!         |"<<endl;
    cout<<"\t\t\t\t\t|________________________________________|"<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    return 0;
}
