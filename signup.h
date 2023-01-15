#include <fstream>
#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

string hidden(){
  char inp[15];
    int loop = 0;
    char ch;
while (1)
    {

        ch = getch();

        if (ch == 13 && loop != 0)
        {
            break;
        }
        if (ch == 8 && loop != 0)
        {
            cout << "\b \b";
            loop--;
            continue;
        }
        if (ch == 8 && loop == 0)
        {
            continue;
        }
        if (ch == 32)
        {
            continue;
        }

        inp[loop] = ch;
        cout << "*";
        loop++;
    }

    inp[loop] = '\0';
   

    return inp;


}
bool signup()
{

	string user, pass;
	char ch;
	int loop = 0;
	char inp[16];
	

	//	welcome();
	
	
	cout << "  What would you like to be your username?\n>> ";
	cin >> user;
	cout << endl
		 << " Okay " << user << " Please Choose a password for your account >> ";
		pass= hidden();

	{
		fstream obj;
		obj.open("users.txt",ios::app);
		obj<<user<<endl<<pass<<endl;
		obj.close();
	}

	cout<<endl<<" Account Created ! ";
	system("\npause");
	

	return true;
}
