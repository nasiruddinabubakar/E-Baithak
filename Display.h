#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <windows.h>


using namespace std;
char popup()
{
}

using namespace std;

class node
{

public:
	string post;
	string name;

	node *next;
	node *prev;

	node(string post, string name)
	{
		this->name = name;
		this->post = post;
		next = NULL;
		prev = NULL;
	}
	node()
	{
	}
};

class page
{

public:
	node *head;
	node *tail;

	page()
	{
		head = tail = NULL;
	}

	void insert(string data, string name)
	{

		node *new_post = new node(data, name);

		if (head == NULL)
		{
			head = new_post;
			tail = new_post;
		}

		else
		{
			tail->next = new_post;
			new_post->prev = tail;

			new_post->next = NULL;
			tail = new_post;
		}
	}

	void display()
	{

		node *traversal = head;
		char op;

		while (1)
		{

			system("cls");
	
			
			//	welcome();
			cout << traversal->post << "\n\n\n\n  ";
			cout << "\n Written by -> " << traversal->name << endl;

			cout<<" \n\n Press e to go forward and w to go backwards ! ";
			op = getch();
			if (op == 'e')
			{

				traversal = traversal->next;
				

				continue;
			}
			else if (op=='w'){
			traversal = traversal->prev;
			continue;

			}else{
				cout<<" \n Enter  a valid command ! /n";
				system("\npause");

			}
			//				cout<< traversal->post<<"\n\n\n\n  ";
			//				getch();
					}
	}
	
	node* pop(){

	node* temp;
	temp = tail;
	tail->prev->next=NULL; 
	tail=tail->prev;
	return temp;
	}
};
void welcome()
{

	for (int i = 0; i < 20; i++)
	{

		cout << endl;
	}
	cout << " \t\t\t E - B A I T H A K ";
	cout << "\n\n\n\n\n\n\n";
}

void search()
{

	fstream obj;
	string temp;
	string name;
	string post;
	page posts;

	int count = 0;
	bool check = true;
	cout << " Enter a #hashtag to search a post !";
	cin >> temp;

	temp += ".txt";
	obj.open(temp.c_str(), ios::in);

	while (!obj.eof())
	{
	
		if (check)
		{
			getline(obj, name);
			check = false;
		}

		
			getline(obj, temp);

			if (temp == "*")
			{
				check=true;
				count++;
				posts.insert(post, name);
				post.clear();
				
			}
			else{

			
			post += "  ";
			post += temp;
			post += "\n\n";

			}
		
		
		
		
	}
	node* papa = posts.pop();
	cout<<papa->name;
	papa=posts.pop();
	cout<<papa->name;
	posts.display();
}


