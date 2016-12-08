#include "ConsoleUI.h"

ConsoleUI::ConsoleUI()
{

}

void ConsoleUI::run()
{   
    string command;

    cout    << "Welcome!" << endl
            << "This is a list that contains well known characters from Computer Science\n" << endl;

    do
    {
        commands(); //Prints out user input options.

        cout << "Enter command: ";
        cin >> command;

        if(command == "add")
        {
            addScientist();
        }
        else if(command == "list")
        {
            list();
        }
        else if(command == "find")
        {
            findScientist();
        }
        else if(command == "edit")
        {
            editScientist();
        }
        else if(command == "delete")
        {
            deleteScientist();
        }
        else if(command == "quit")
        {
            break;
        }
        else
        {
            cout << endl;
            cout << "! - Invalid command - !" << endl;
            cout << endl;
        }

    }while(true);
}

void ConsoleUI::commands()
{
    cout << "**********************************************************************" << endl;
    cout << "Please enter one of the following commands:" << endl
         << "add \t - Add new scientist to the list" << endl
         << "list \t - Show a list of all scientist" << endl
         << "find \t - Find scientist in list" << endl
         << "edit \t - Edit scientist in list" << endl
         << "delete \t - Delete scientist, write exact name of scientist to delete." << endl
         << "quit \t - Quit the program." << endl;
    cout << "**********************************************************************" << endl;
}

void ConsoleUI::printListOfScientists(vector<Scientist> vs)
{
   printHeaderScientists();
   for(size_t i = 0; i < vs.size(); i++)
   {
       cout << vs.at(i);
   }
   cout << endl;
}

void ConsoleUI::printHeaderScientists()
{
    cout << endl;
    cout << "ID" << "\t" << "Scientist" << "\t" << "\t" << "\t" << "YoB" << "\t" << "YoD" << "\t" << "Gender" << endl;
    cout << "=============================================================" << endl;
}

void ConsoleUI::printListOfComputers(vector<Computer> vc)
{
    printHeaderComputers();
    for(size_t i = 0; i < vc.size(); i++)
    {
        cout << vc.at(i);
    }
    cout << endl;
}

void ConsoleUI::printHeaderComputers()
{
    cout << endl;
    cout << "ID" << "\t" << "Computer" << "\t" << "\t" << "\t" << "Build year" << "\t" << "Type" << "\t" << "Was built" << endl;
    cout << "=============================================================" << endl;
}

void ConsoleUI::addScientist() //Adds scientist to the list.
{
    string sName;
    int bDate;
    int dDate;
    char gender;

    sName = addNameOfScientist();
    bDate = addBirthDateOfScientist();
    dDate = addDeathDateOfScientist(bDate);
    gender = addGenderOfScientist();

    _scs.addScientist(sName, bDate, dDate, gender);
    listName();
}

string ConsoleUI::addNameOfScientist() //Gets a name of scientist from the user.
{
    string sName;
    cin.ignore(); //To empty cin in order to use getline();
    do
    {
        cout << "First and last name of scientist to add: ";

        getline(cin,sName);

        if(sName.size() == 0)
        {
            cout << endl;
            cout << "! - No scientist name was entered. - !" << endl;
            cout << endl;
        }
        else if(sName.size() > 23)
        {
            cout << endl;
            cout << "! - Scientist name you entered is too long. - !" << endl
                 << "! - Scientist name can be max 23 characters with space. - !" << endl;
            cout << endl;
        }
    }while(sName.size() == 0 || sName.size() > 23);

    return sName;
}

int ConsoleUI::addBirthDateOfScientist() //Gets a year of birth of scientist from user.
{
    int bDate;
    //int bDate = 2020;

    do
    {
        cout << "Year of Birth (YYYY): ";
        cin >> bDate;
        if(!_scs.validYearCheck(bDate))
        {
            cout << endl;
            cout << "! - Invalid year format - !" << endl;
            cout << endl;
        }

    }while(!_scs.validYearCheck(bDate));

    /*do
    {
        cout << "Year of Birth (YYYY): ";
        cin >> bDate;
        if(bDate.sizecout << endl;
            cout << "! - Invalid year format - !" << endl;
            cout << endl;() != 4 || isalpha(bDate[0]) || isalpha(bDate[1]) || isalpha(bDate[2]) || isalpha(bDate[3]))
        {

        }
    }while(bDate.size() != 4 || isalpha(bDate[0]) || isalpha(bDate[1]) || isalpha(bDate[2]) || isalpha(bDate[3]));*/

    return bDate;
}

int ConsoleUI::addDeathDateOfScientist(int bDate) //Gets a year of death of scientist from user.
{
    //int dDate = 2020;

    int dDate;
    string deadOrAlive;

    do
    {
        cout << "Is scientist still alive? (yes/no): ";
        cin >> deadOrAlive;

        if(deadOrAlive == "no")
        {
            do
            {
                cout << "Year of Death (YYYY): ";
                cin >> dDate;
                if(!_scs.validYearCheck(dDate) || dDate < bDate)
                {
                    cout << endl;
                    cout << "! - Invalid year format - !" << endl;
                    cout << endl;
                }
            }while(!_scs.validYearCheck(dDate) || dDate < bDate);
        }
        else if(deadOrAlive == "yes")
        {
            dDate = 9999;
        }
        else
        {
            cout << endl;
            cout << "! - Invalid choice, please enter 'yes' or 'no' - !" << endl;
        }
    }while(deadOrAlive != "no" && deadOrAlive != "yes");


   /* do
    {
        cout << "Year of Death (YYYY, or if still alive, write 'alive'): ";
        cin >> dDate;
        //This boolean ensures that the user either enters 4 digits or the word 'alive'.
        if((isalpha(dDate[0]) && dDate != "alive") || (isalpha(dDate[1]) && dDate != "alive") || (isalpha(dDate[2])
            && dDate != "alive") || (isalpha(dDate[3]) && dDate != "alive") || (isdigit(dDate[0]) && dDate.size() != 4))
        {
            cout << endl;
            cout << "! - Invalid year format - !" << endl;
            cout << endl;
        }
     }while((isalpha(dDate[0]) && dDate != "alive") || (isalpha(dDate[1]) && dDate != "alive") || (isalpha(dDate[2])
        && dDate != "alive") || (isalpha(dDate[3]) && dDate != "alive") || (isdigit(dDate[0]) && dDate.size() != 4));*/

    return dDate;
}

char ConsoleUI::addGenderOfScientist() //Gets a gender of scientist from user.
{
    char gender;
    do
    {
        cout << "Gender (f/m): ";
        cin >> gender;
        if(gender != 'f' && gender != 'm')
        {
            cout << endl;
            cout << "! - This selection was invalid - !" << endl;
            cout << endl;
        }
    }while(gender != 'f' && gender != 'm');

    return gender;
}

void ConsoleUI::addComputer() //Adds computer to the list.
{
    string cName;
    int buildYear;
    string type;
    string wasBuilt;

    cName = addNameOfComputer();
    buildYear = addBuildYearOfComputer();
    type = addTypeOfComputer();
    wasBuilt = addWasBuiltOfComputer();

    _cs.addComputer(cName, buildYear, type, wasBuilt);
    //listName();
}

string ConsoleUI::addNameOfComputer()
{
    string cName;
    cin.ignore();
    do
    {
        cout << "Name of Computer to add: ";

        getline(cin,cName);

        if(cName.size() == 0)
        {
            cout << endl;
            cout << "! - No computer name was entered. - !" << endl;
            cout << endl;
        }
        else if(cName.size() > 23)
        {
            cout << endl;
            cout << "! - Computer name you entered is too long. - !" << endl
                 << "! - Computer name can be max 23 characters with space. - !" << endl;
            cout << endl;
        }
    }while(cName.size() == 0 || cName.size() > 23);

    return cName;
}

int ConsoleUI::addBuildYearOfComputer()
{
   // int buildYear = 1879;
    int buildYear;

    do
    {
        cout << "Enter build year (YYYY): ";
        cin >> buildYear;
        if(!_scs.validYearCheck(buildYear))
        {
            cout << endl;
            cout << "! - Invalid year format - !" << endl;
            cout << endl;
        }

    }while(!_scs.validYearCheck(buildYear));

    return buildYear;
}

string ConsoleUI::addTypeOfComputer()
{
    string cType;
    cin.ignore(); //To empty cin in order to use getline();
    do
    {
        cout << "Type to add: ";

        getline(cin,cType);

        if(cType.size() == 0)
        {
            cout << endl;
            cout << "! - No type was entered. - !" << endl;
            cout << endl;
        }
        else if(cType.size() > 7)
        {
            cout << endl;
            cout << "! - Computer name you entered is too long. - !" << endl
                 << "! - Computer name can be max 7 characters with space. - !" << endl;
            cout << endl;
        }
    }while(cType.size() == 0 || cType.size() > 7);

    return cType;
}

string ConsoleUI::addWasBuiltOfComputer()
{
    string wasBuilt;
    cin.ignore(); //To empty cin in order to use getline();
    do
    {
        cout << "Has the computer been built, yes/no: ";

        getline(cin,wasBuilt);

        if(wasBuilt.size() == 0 || wasBuilt != "yes" || wasBuilt != "Yes" || wasBuilt != "YES"|| wasBuilt != "no" || wasBuilt != "No" || wasBuilt != "NO")
        {
            cout << endl;
            cout << "! - Invalid input. - !" << endl;
            cout << endl;
        }
    }while(wasBuilt.size() == 0 || wasBuilt != "yes" || wasBuilt != "Yes" || wasBuilt != "YES"|| wasBuilt != "no" || wasBuilt != "No" || wasBuilt != "NO");

    return wasBuilt;
}

void ConsoleUI::list() //Gets user input on how to sort the list.
{
    char in;

    cout    << "********************************************************" << endl;
    cout    << "Enter n - For a list of scientists ordered by name" << endl;
    cout    << "Enter b - For a list of scientists ordered by birth year" << endl;
    cout    << "Enter d - For a list of scientists ordered by death year" << endl;
    cout    << "Enter g - For a list of scientists ordered by gender" << endl;
    cout    << "********************************************************" << endl;

    cout << "Please enter now: " << endl;
    cin >> in;

    switch(in)
    {
        case 'n':
                listName();
                break;
        case 'b':
                listDoB();
                break;
        case 'd':
                listDoD();
                break;
        case 'g':
                listGender();
                break;
        default:
                cout << endl;
                cout << "! - Invalid command - !" << endl;
                cout << endl;
    }

}

void ConsoleUI::listName() //Gets a list of the scientists and prints it out ordered by name.
{
    //_scs.ScientistsOrderByName();
    vector<Scientist> sc = _scs.getScientists();
    printListOfScientists(sc);
}

void ConsoleUI::listDoB() //Gets a list of the scientists and prints it out ordered by year of birth.
{
    //_scs.ScientistsOrderByDoB();
    vector<Scientist> sc = _scs.getScientists();
    printListOfScientists(sc);
}

void ConsoleUI::listDoD() //Gets a list of the scientists and prints it out ordered by year of death.
{
    //_scs.ScientistsOrderByDoD();
    vector<Scientist> sc = _scs.getScientists();
    printListOfScientists(sc);
}

void ConsoleUI::listGender() //Gets a list of the scientists and prints it out ordered by gender.
{
    //_scs.ScientistsOrderByGender();
    vector<Scientist> sc = _scs.getScientists();
    printListOfScientists(sc);
}

void ConsoleUI::findScientist()
{
    string findSc;

    cin.ignore();
    cout << "Enter the name of scientist: ";
    getline(cin,findSc);
    vector<Scientist> sc = _scs.findScientistByName(findSc);
    /*if(sc.getName() == "")
    {
        cout << endl;
        cout << "! - Scientist was not found. - !" << endl;
        cout << endl;
    }
    else
    {
        printHeader();
        cout << sc;
    }
    cout << endl;*/
}

void ConsoleUI::findComputer()
{
    string findC;

    cin.ignore();
    cout << "Enter the name of computer: ";
    getline(cin,findC);
    vector<Computer> c = _cs.findComputerByName(findC);
}

void ConsoleUI::deleteScientist()
{
    string deleteScientistName;
    cout << "Enter first and last name of the scientist you want to delete: " << endl;
    cin.ignore();
    getline(cin,deleteScientistName);
    int id = 0; //Preliminary svo það buildist. Þarf að breyta.
    int n = _scs.deleteScientist(id);
    if(n == -1)
    {
        cout << endl;
        cout << "! - " << deleteScientistName << " was not found in the list. - !" << endl;
        cout << endl;
    }
    else
    {
        listName();
    }
}

void ConsoleUI::deleteComputer()
{
    string deleteComputerName;
    cout << "Enter the name of the computer you want to delete: " << endl;
    cin.ignore();
    getline(cin,deleteComputerName);
    int id = 0; //Preliminary placeholder. Þarf að breyta.
    int n = _cs.deleteComputer(id);
    if(n == -1)
    {
        cout << endl;
        cout << "! - " << deleteComputerName << " was not found in the list. - !" << endl;
        cout << endl;
    }
    else
    {
        //listName();
    }
}

void ConsoleUI::editScientist()
{
    string editSC, sName;
    int dob, dod;
    char gender;
    cout << "Enter first and last name of the scientist you want to edit: " << endl;
    cin.ignore();
    getline(cin,editSC);
    vector<Scientist> sc = _scs.findScientistByName(editSC);
    /*if(sc.getName() == "")
    {
        cout << endl;
        cout << "! - Scientist was not found. - !" << endl;
        cout << endl;
    }
    else
    {
        cout << "You want to edit: " << endl;
        printHeader();
        cout << sc << endl;
        name = editName(sc);
        dob = editBirthDate(sc);
        dod = editDeathDate(sc);
        gender = editGender(sc);

        _scs.editScientist(editSC, name, dob, dod, gender);
        sc = _scs.findScientistByName(name);

        cout << endl;
        cout << "Scientist has now been edited: " << endl;
        printHeader();
        cout << sc << endl;
        cout << endl;
    }*/
}

string ConsoleUI::editNameOfScientist(Scientist sc)
{
    string editSC, sName;
    cout << "Would you like to edit the name? yes or no: ";
    cin >> editSC;

    if(editSC == "yes")
    {
        cin.ignore();
        do
        {
            cout    << "Enter new first and last name: ";
            getline(cin,sName);
            if(sName.size() == 0)
            {
                cout << endl;
                cout << "! - No name was entered. - !" << endl;
                cout << endl;
            }
            else if(sName.size() > 23)
            {
                cout << endl;
                cout << "! - Name you entered is too long. - !" << endl << "! - Name can only be under 23 characters with space. - !" << endl;
                cout << endl;
            }

        }while(sName.size() == 0 || sName.size() > 23);
    }
    else if(editSC == "no")
    {
        sName = sc.getName();
    }
    else
    {
        cout << endl;
        cout << "! - Invalid command, name will not be changed - !" << endl;
        sName = sc.getName();
        cout << endl;
    }
    return sName;
}

int ConsoleUI::editBirthDateOfScientist(Scientist sc)
{
    string editSC;
    int dob;
    cout << "Would you like to edit year of birth? yes or no: ";
    cin >> editSC;

    if(editSC == "yes")
    {
        do
        {
            cout << "Enter new year of Birth (YYYY): ";
            cin >> dob;
            if(!_scs.validYearCheck(dob))
            {
                cout << endl;
                cout << "! - Invalid year format - !" << endl;
                cout << endl;
            }

        }while(!_scs.validYearCheck(dob));


        /* do
        {
            cout << "Enter new year of Birth (YYYY): ";
            cin >> dob;
            if(dob.size() != 4 || isalpha(dob[0]) || isalpha(dob[1]) || isalpha(dob[2]) || isalpha(dob[3]))
            {
                cout << endl;
                cout << "! - Invalid year format - !" << endl;
                cout << endl;
            }
        }while(dob.size() != 4 || isalpha(dob[0]) || isalpha(dob[1]) || isalpha(dob[2]) || isalpha(dob[3]));*/
    }
    else if(editSC == "no")
    {
        dob = sc.getBirthDate();
    }
    else
    {
        cout << endl;
        cout << "! - Invalid command, year of birth will not be changed - !" << endl;
        dob = sc.getBirthDate();
        cout << endl;
    }
    return dob;
}

int ConsoleUI::editDeathDateOfScientist(Scientist sc)
{
    string editSC;
    int dDate;
    cout << "Would you like to edit year of death? yes or no: ";
    cin >> editSC;

    if(editSC == "yes")
    {
        /*do
        {
            cout << "Year of Death (YYYY, or if still alive, write 'alive'): ";
            cin >> dDate;
            if((isalpha(dDate[0]) && dDate != "alive") || (isalpha(dDate[1]) && dDate != "alive") || (isalpha(dDate[2])
                && dDate != "alive") || (isalpha(dDate[3]) && dDate != "alive") || (isdigit(dDate[0]) && dDate.size() != 4))
            {
                cout << endl;
                cout << "! - Invalid year format - !" << endl;
                cout << endl;
            }
         }while((isalpha(dDate[0]) && dDate != "alive") || (isalpha(dDate[1]) && dDate != "alive") || (isalpha(dDate[2])
            && dDate != "alive") || (isalpha(dDate[3]) && dDate != "alive") || (isdigit(dDate[0]) && dDate.size() != 4));*/
    }
    else if(editSC == "no")
    {
        dDate = sc.getDeathDate();
    }
    else
    {
        cout << endl;
        cout << "! - Invalid command, year of death will not be changed - !" << endl;
        dDate = sc.getDeathDate();
        cout << endl;
    }

    return dDate;
}

char ConsoleUI::editGenderOfScientist(Scientist sc)
{
    string editSC;
    char gender;
    cout << "Would you like to edit gender? yes or no: ";
    cin >> editSC;

    if(editSC == "yes")
    {
        do
        {
            cout << "Enter new gender (f/m): ";
            cin >> gender;
            if(gender != 'f' && gender != 'm')
            {
                cout << endl;
                cout << "! - This selection was invalid - !" << endl;
                cout << endl;
            }
        }while(gender != 'f' && gender != 'm');
    }
    else if(editSC == "no")
    {
        gender = sc.getGender();
    }
    else
    {
        cout << endl;
        cout << "! - Invalid command, gender will not be changed - !" << endl;
        gender = sc.getGender();
        cout << endl;
    }

    return gender;
}

void ConsoleUI::editComputer()
{
    string editC, cName;
    int by;
    string t, wb;
    cout << "Enter name of the computer you want to edit: " << endl;
    cin.ignore();
    getline(cin,editC);
    vector<Computer> c = _cs.findComputerByName(editC);
}

string ConsoleUI::editNameOfComputer(Computer c)
{
    string editC, cName;
    cout << "Would you like to edit the name? yes or no: ";
    cin >> editC;

    if(editC == "yes")
    {
        cin.ignore();
        do
        {
            cout    << "Enter new first and last name: ";
            getline(cin,cName);
            if(cName.size() == 0)
            {
                cout << endl;
                cout << "! - No name was entered. - !" << endl;
                cout << endl;
            }
            else if(cName.size() > 23)
            {
                cout << endl;
                cout << "! - Name you entered is too long. - !" << endl << "! - Name can only be under 23 characters with space. - !" << endl;
                cout << endl;
            }

        }while(cName.size() == 0 || cName.size() > 23);
    }
    else if(editC == "no")
    {
        cName = c.getName();
    }
    else
    {
        cout << endl;
        cout << "! - Invalid command, name will not be changed - !" << endl;
        cName = c.getName();
        cout << endl;
    }
    return cName;
}

int ConsoleUI::editBuildYearOfComputer(Computer c)
{
    string editC;
    int by;
    cout << "Would you like to edit the build year? yes or no: ";
    cin >> editC;

    if(editC == "yes")
    {
       /* do
        {
            cout << "Enter new year of Birth (YYYY): ";
            cin >> dob;
            if(dob.size() != 4 || isalpha(dob[0]) || isalpha(dob[1]) || isalpha(dob[2]) || isalpha(dob[3]))
            {
                cout << endl;
                cout << "! - Invalid year format - !" << endl;
                cout << endl;
            }
        }while(dob.size() != 4 || isalpha(dob[0]) || isalpha(dob[1]) || isalpha(dob[2]) || isalpha(dob[3]));*/
    }
    else if(editC == "no")
    {
        by = c.getBuildYear();
    }
    else
    {
        cout << endl;
        cout << "! - Invalid command, build year will not be changed - !" << endl;
        by = c.getBuildYear();
        cout << endl;
    }
    return by;
}

string ConsoleUI::editTypeOfComputer(Computer c)
{
    string editC, cType;
    cout << "Would you like to edit the type? yes or no: ";
    cin >> editC;

    if(editC == "yes")
    {
        cin.ignore();
        do
        {
            cout    << "Enter new type: ";
            getline(cin,cType);
            if(cType.size() == 0)
            {
                cout << endl;
                cout << "! - No type was entered. - !" << endl;
                cout << endl;
            }
            else if(cType.size() > 7)
            {
                cout << endl;
                cout << "! - Type you entered is too long. - !" << endl << "! - Type can only be under 7 characters with space. - !" << endl;
                cout << endl;
            }

        }while(cType.size() == 0 || cType.size() > 7);
    }
    else if(editC == "no")
    {
        cType = c.getType();
    }
    else
    {
        cout << endl;
        cout << "! - Invalid command, type will not be changed - !" << endl;
        cType = c.getType();
        cout << endl;
    }
    return cType;
}

string ConsoleUI::editWasBuiltOfComputer(Computer c)
{
    string editC, wasBuilt;
    cout << "Would you like to edit if the computer has been built? yes or no: ";
    cin >> editC;

    if(editC == "yes")
    {
        cin.ignore();
        do
        {
            cout    << "Enter yes or no: ";
            getline(cin,wasBuilt);
            if(wasBuilt.size() == 0 || wasBuilt != "yes" || wasBuilt != "Yes" || wasBuilt != "YES"|| wasBuilt != "no" || wasBuilt != "No" || wasBuilt != "NO")
            {
                cout << endl;
                cout << "! - Invalid input. - !" << endl;
                cout << endl;
            }
        }while(wasBuilt.size() == 0 || wasBuilt != "yes" || wasBuilt != "Yes" || wasBuilt != "YES"|| wasBuilt != "no" || wasBuilt != "No" || wasBuilt != "NO");
    }
    else if(editC == "no")
    {
        wasBuilt = c.getWasBuilt();
    }
    else
    {
        cout << endl;
        cout << "! - Invalid command, type will not be changed - !" << endl;
        wasBuilt = c.getWasBuilt();
        cout << endl;
    }
    return wasBuilt;
}
