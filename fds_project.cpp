// contibuted by:

//                    KAPIL (7227)
//    HARDIK PANDYA (7222)

#include <iostream>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <stdio.h>

using namespace std;

string ans, word, def, deleteline, line;
int pick, add(), del(), print(), sort();

bool checkword(char* filename)
{
    int offset;
    string line, search;
    ifstream myfile;
    myfile.open("/Users/Alex/Documents/CISP 400/Project1./Project1/dictionary.txt");
	sort();
    if(myfile.is_open())
    {
        while(!myfile.eof())
        {
            getline(myfile,line);
            if ((offset = line.find(deleteline, 0)) != string::npos)
            {
				cout << "found '" << deleteline << " \n\n"<< line  <<endl;
				return true;
            }
            else
            {

                cout << "Not found \n\n";

            }
        }
        myfile.close();
    }
    else
		cout<<"Unable to open this file."<<endl;

    return false;
}

int add()
{
    int count;
    cout << "Please enter 3 different words followed by their definition.\n";
	//Loop for how many entries
    count = 1;
    while (count<4)
	{
		cout << "Enter the word you would like to add\n";
		cin.ignore();
		getline(cin, word);
		cout << "Enter the definition of this word\n";
		getline(cin, def);
		//Add the words and def to the end of the file
		fstream myfile;
		myfile.open ("/Users/Alex/Documents/CISP%20400/Project1./Project1/dictionary.txt", fstream::in | fstream::out | fstream::app);
		myfile<<word <<" - " << def <<endl;
		myfile.close();
		count ++;
    }
	cout << "\nThank you, your words and definitions have been added.";
	cin.ignore();
	return 0;
}

int del()
{
	print();
	string check;
	//See in old and new file
	ifstream myfile;
	myfile.open("/Users/Alex/Documents/CISP%20400/Project1./Project1/dictionary.txt");
	ofstream temp;
	temp.open("/Users/Alex/Documents/CISP%20400/Project1./Project1/temp.txt");
	sort();
	cout << "What word would you like to delete?";
	cin >> deleteline;
	cout<< "Are you sure you want to delete this: yes or no.";
	cin>> check;
	if (check == "yes")
	{
	checkword("/Users/Alex/Documents/CISP%20400/Project1./dictionary.txt");
	//Copy all lines except the targeted one
	while (getline(myfile,line))
	{
		if (line != deleteline)
		{
			temp << line << endl;
		}
	}
			temp.close();
			myfile.close();
	//Remove and rename old and new file
			remove("/Users/Alex/Documents/CISP 400/Project1./Project1/dictionary.txt");
			rename("/Users/Alex/Documents/CISP%20400/Project1./Project1/temp.txt","/Users/Alex/Documents/CISP%20400/Project1./Project1/dictionary.txt");
			cout <<endl<<endl<<endl;
	}
	else
	{
		del();
	}

}




int print()
{
    string readfile();
    {
		//Read in file
        string line;
        ifstream myfile ("/Users/Alex/Documents/CISP 400/Project1./Project1/dictionary.txt");
		myfile.open("/Users/Alex/Documents/CISP 400/Project1./Project1/dictionary.txt");
        if (myfile.is_open())
        {
			//Print file
            while ( getline (myfile,line) )
            {
                cout << line << endl;
            }
            myfile.close();
        }

        else cout << "Unable to open file";

        return 0;
    };

}

int sort()
{
    //Empty vector holding all names from file
	vector<string> names;

	//Read names from file
	ifstream myfile("/Users/Alex/Documents/CISP 400/Project1./Project1/dictionary.txt");
	myfile.open("/Users/Alex/Documents/CISP 400/Project1./Project1/dictionary.txt");
	if(!myfile.is_open())
		cout << "Unable to open file\n";

	//Sort Names
	string word;
	while(getline(myfile, word))
		names.push_back(word);

	sort(names.begin(), names.end());

	//Loop to print names
	for (size_t i = 0; i < names.size(); i++)
		cout << names[i] << '\n';
    return 0;
}

int main()
{
    ans = "yes";
    while (ans == "yes")
    {
        cout << "\nTo add a word press 1: \n To delete a word press 2: \n To search a word press 3: \n To print a list press 4:";
        cin >> pick;
		fstream myfile;
		myfile.open("/Users/Alex/Documents/CISP 400/Project1./Project1/dictionary.txt");
        switch (pick)
        {
            case 1:;
                add();
            case 2:;
                del();
            case 3:;
                checkword("/Users/Alex/Documents/CISP 400/Project1./Project1/dictionary.txt");
            case 4:;
                sort();
        }
        cout << "Would you like to run this again: 'Yes or No'";
        cin >> ans;
    }
	return 0;
}
