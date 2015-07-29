#include <iostream>
#include <cstring>
#include <fstream>
#include <string>

using namespace std;

class Contact
{
private:
    string m_fName;
    string m_lName;
    string m_email;
    string m_phoneNumber;
    string m_bDay[3];

public:
    Contact () {}

    void setContact (string nFirstname, string nLastname, string nEmail, string nPhoneNumber, string m, string d, string y)
    {
        m_fName = nFirstname;
        m_lName = nLastname;
        m_email = nEmail;
        m_phoneNumber = nPhoneNumber;
        m_bDay[0] = m;
        m_bDay[1] = d;
        m_bDay[2] = y;
    }

    void setbmonth (string m)
    { m_bDay[0] = m; }
    string getbmonth ()
    { return m_bDay[0];}

    void setbday (string d)
    { m_bDay[1] = d; }
    string getbday ()
    { return m_bDay[1];}

    void setbyear (string y)
    { m_bDay[2] = y; }
    string getbyear ()
    { return m_bDay[2];}

    void print ()
    {
    cout << "First Name: " << m_fName << endl;
    cout << "Last Name: " << m_lName << endl;
    cout << "Email: " << m_email << endl;
    cout << "Phone Number: " << m_phoneNumber << endl;
    cout << "Birthday: " << m_bDay[0] << "-" << m_bDay[1] << "-" << m_bDay[2] << endl;
    cout << endl << endl;
    }

    void printToFile ()
    {
        ofstream ofile ("data.txt", ios::app);
        ofile << m_fName << '\n'<< m_lName << '\n' << m_email << '\n' << m_phoneNumber << '\n'<< m_bDay[0] << '\n' << m_bDay[1] << '\n' << m_bDay[2];
        ofile.close();
    }
};

int main()
{
    Contact myContact[10];
    int contCount = 0;
    char yesorno1;
    char yesorno2;
    bool keepRunning=true;
    bool showContacts;

    string inp_fname, inp_lname, inp_email, inp_pnumber, inp_m, inp_d, inp_y;

    cout << "Do you want to see existing contacts? (y/n)" << endl;
    cin >> yesorno1;

    switch (yesorno1)
    {

        case 'n':
        case 'N':
        case 'no':
        case 'No':
        case 'NO':
            showContacts = false;
            break;
    }

    while (showContacts) {

    ifstream ifile ("data.txt");
    string test;
    while ( getline(ifile, test))
    {
        cout << test << endl;
    }
    ifile.close();
    }

    while (keepRunning)
    {

    cout << "Enter the first name: ";
    cin >> inp_fname;
    cout << "Enter the last name: ";
    cin >> inp_lname;
    cout << "Enter the email: ";
    cin >> inp_email;
    cout << "Enter the phone number: ";
    cin >> inp_pnumber;
    cout << "Enter the month of the birthdate (mm): ";
    cin >> inp_m;
    cout << "Enter the date of the birthdate (dd): ";
    cin >> inp_d;
    cout << "Enter the year of the birthdate (yyyy): ";
    cin >> inp_y;

    myContact[contCount].setContact(inp_fname, inp_lname, inp_email, inp_pnumber, inp_m, inp_d, inp_y);
    myContact[contCount].printToFile();

    cout <<"what you entered is" << endl;
    myContact[contCount].print();

    cout << "Wanna input another contact? (y/n)";
    cin >> yesorno2;

    switch (yesorno2)
    {

        case 'n':
        case 'N':
        case 'no':
        case 'No':
        case 'NO':
            keepRunning= false;
            break;
    }

    contCount++;
    } //end of while

    return 0;
}
