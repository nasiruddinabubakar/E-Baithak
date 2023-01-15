#include <iostream>
#include "Logo 1.h"
#include <conio.h>
#include "signup.h"
#include <string>

using namespace std;

string username;
string password;
 
void startfunc();

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
            head->prev = tail;
            tail->next = head;
        }

        else
        {
            tail->next = new_post;
            new_post->prev = tail;

            new_post->next = head;
            head->prev = new_post;
            tail = new_post;
        }
    }
    void queue_insert(string post, string name)
    {
        node *newnode = new node(post, name);

        if (head == NULL && tail == NULL)
        {

            head = tail = newnode;
            head->next = tail ;
            head->prev-tail;
            tail->next=head;
            tail->prev=head;
        }
        else
        {
            newnode->next = head;
            head = newnode;
            newnode->prev = tail;
            tail->next = newnode;
        }

        // cout<<n->post;
    }

    void display()
    {

        node *traversal = head;
        char op;

        while (1)
        {

            system("cls");

            all_logo();
            cout << "\n\n";
            //	welcome();
            cout << traversal->post << "\n\n\n\n  ";
            cout << "\n Written by -> " << traversal->name << endl;

            cout << " \n\n Press 'e' To Go To Next Post \n Press 'w' To Go Previous Post\n Press '1' to Return To Main Menu ";
            op = getch();
            if (op == 'e')
            {

                traversal = traversal->next;

                continue;
            }
            else if (op == 'w')
            {
                traversal = traversal->prev;
                continue;
            }
            else if (op == '1')
            {
                return;
            }
            else
            {
                cout << " \n Enter  a valid command ! /n";
                system("\npause");
            }
            //				cout<< traversal->post<<"\n\n\n\n  ";
            //				getch();
        }
        return;
    }

    node *pop(node *tail)
    {

        return tail->prev;
    }

    node *peek()
    {

        return tail;
    }
};

void Browsing(page &stack)
{

    page posts;
    node *popped;

    popped = stack.peek();
    posts.insert(popped->post, popped->name);

    for (int i = 0; i < 4; i++)
    {
        popped = stack.pop(popped);

        posts.insert(popped->post, popped->name);
    }

    fflush(stdin);

    posts.display();
}
page user_stack(page &userstack)
{

    fstream obj;
    fflush(stdin);
    string post;
    string pc;
    string temp = username + ".txt";
    obj.open(temp.c_str(), ios::in);
    if (obj.is_open())
    {

        while (!obj.eof())
        {

            getline(obj, pc);
            cout << pc;

            if (pc == "*")
            {

                userstack.queue_insert(post, username);
                // cout<<post<<endl;

                post.clear();
            }
            else
            {

                post += pc;
            }
        }
    }
    // userstack.display();
}
page Stack_Frame(page &stack)
{

    fstream obj;
    string temp;
    string name;
    string post;
    bool check = true;
    obj.open("Stack.txt", ios::in);
    while (!obj.eof())
    {

        if (check)
        {
            getline(obj, name);
            if (name == "\0")
            {
                continue;
            }
            check = false;
        }

        getline(obj, temp);

        if (temp == "*")
        {
            check = true;

            stack.insert(post, name);
            post.clear();
        }
        else
        {

            post += "  ";
            post += temp;
        }
    }

    return stack;
}

void search()
{

    fstream obj;
    string temp;
    string name;
    string post;
    string pattern;
    page posts;
    char op;
    int count = 0;
    bool check = true, found = false;
    system("cls");
    all_logo();
    cout << endl;
    cout << " Enter a #hashtag to search a post !";
    cin >> temp;
    string hash = temp;
    temp += ".txt";
    fflush(stdin);
    obj.open(temp.c_str(), ios::in);

    if (obj.is_open())
    {

        cout << " Press 1 to Bring All Posts of " << hash << endl
             << " Press 2 To Search Post by a sentence in " << hash << " Posts " << endl;
        ;
        while (1)
        {
            op = getch();
            if (op == '1')
            {
                break;
            }
            if (op == '2')
            {
                cout << " Enter A Sentence To Search -> ";
                getline(cin, pattern);
                break;
            }
            else
            {
                cout << endl
                     << " Invalid input ! ";
            }
        }
        fflush(stdin);
        int index = 0;
        int length = pattern.length();
        int len = 0;

        while (!obj.eof())
        {

            if (check)
            {
                getline(obj, name);
                if (name == "\0")
                {
                    continue;
                }
                check = false;
            }
            getline(obj, temp);
            len = temp.length();
            if (op == '2')
            {
                for (int i = 0; i < len; i++)
                {
                    if (index == length)
                    {
                        break;
                    }
                    if (temp[i] == pattern[index])
                    {

                        index++;
                    }
                    else if (index > 0)
                    {
                        index--;
                    }
                }
            }

            if (temp == "*")
            {
                check = true;
                count++;
                if (index == length)
                {
                  
                   
                    found = true;
                    posts.insert(post, name);
                }
                index = 0;
                post.clear();
            }
            else
            {

                post += temp;
            }
        }

        if (op == '1')
        {
            posts.display();
        }
        else if (found)
        {
            posts.display();
        }
        else
        {
            cout << " No Post Found !";
            system("pause>0");
        }
    }

    else
    {

        cout << " No Post Found ! " << endl;
        system("pause>0");
    }
}

void Searching()
{
    search();
}
void checkforhashtag(string &blog)
{
    string hash;
    int flag = 0;
    int n = blog.length();
    for (int i = 0; i < n; i++)
    {
        if (blog[i] == '#')
        {
            flag++;
        }
    }
    if (flag == 0)
    {
        cout << endl
             << "Enter atleast one hashtag!\n";
        getline(cin, hash);
        blog = blog + hash;
        checkforhashtag(blog);
    }
    return;
}
void analyzedata(string &blog)
{
    char hashtag[] = {"#.txt"};
    ;

    checkforhashtag(blog);
    int n = blog.length();
    string temp = "", idk = blog;
    int i = 0;
    while (blog[i])
    {
        n--;
        if (blog[i] == '#')
        {
            temp += "#";
            int j = 1;
            temp[j] += blog[i];
            while (blog[i + 1] != ' ' && blog[i + 1] != '.' && blog[i + 1] != ',' && n > 0 && blog[i + 1] != '#')
            {
                n--;
                // cout<<temp[j];
                j++;
                i++;
                temp += blog[i];
            }
            temp.append(".txt");
            //----------------------------------
            ofstream a1;
            a1.open(temp.c_str(), ios_base::app);
            a1 << endl
               << username << endl
               << idk << endl
               << "*";
            a1.close();
            a1.open("Stack.txt", ios::app);
            a1 << endl
               << username << endl
               << idk << endl
               << "*";
            a1.close();
            //----------------------------------
        }
        temp.clear();
        i++;
        //----------------------------------
        remove(hashtag);
        //----------------------------------
    }
    return;
}
void Writing(bool logged, page &stack, page &userstack)
{
    {
        if (!logged)
        {
            cout << " Please Login Your Account To Create A Post ! " << endl;
            system("\npause");
            return;
        }
    }
    string blog;
    fflush(stdin);
    all_logo();
    cout << "Start Entering your Post:\n";

    getline(cin, blog);
    analyzedata(blog);

    string temp;
    fstream myfile;
    temp = temp + username + ".txt";

    myfile.open(temp.c_str(), ios::app);
    // myfile << username << endl;
    myfile << endl
           << blog << endl;
    myfile << "*";
    myfile.close();
    stack.insert(blog, username);
    userstack.queue_insert(blog, username);
    cout << "\n Post Saved Successfully !!" << endl
         << " ";
    system("\npause");
}
bool login()
{
    system("cls");
    all_logo();
    string user, pass;
    bool check = 0;
    cout << " Enter Your Username >> ";
    cin >> user;
    cout << " Enter Your Password >> ";
    pass = hidden();

    fstream myfile;
    myfile.open("users.txt", ios::in);
    string fileusername;
    string filepassword;

    while (myfile >> fileusername)
    {

        if (fileusername == user)
        {
            myfile >> filepassword;

            if (filepassword == pass)
            {
                check = true;
                break;
            }
            else
            {
            }
        }
        else
        {
            myfile >> fileusername;
        }
    }
    myfile.close();

    if (check)
    {
        username = user;
        password = pass;
        return true;
    }
    else
    {
        cout << endl;
        // spaces();
        cout << " Invalid Credentials ! \n";
        system("\npause");
        return false;
    }
}

bool login_signup()
{
    system("cls");

    char c;
    bool yes = 0;
    bool success = 0;
    while (1)

    {
        system("cls");
        all_logo();
        cout << " 1) Login\n\n 2) Dont Have An Account? Sign Up Now ! " << endl;
        c = getch();

        switch (c)
        {
        case '1':
            success = login();
            if (success)
                yes = false;
            break;
        case '2':
            all_logo();
            yes = signup();
            fflush(stdin);
            break;
        default:
            break;
        }

        if (yes)
        {

            continue;
            ;
        }

        if (success)
        {
            break;
        }
        else
        {
        }
    }
    return true;
}

void Personal_posts(page &userstack)
{
    userstack.display();
}

void spaces()
{

    cout << "\t\t\t       ";
}
void skips()
{

    cout << "\n\n\n";
}

void startfunc()
{
    page stack;
    page userstack;
    stack = Stack_Frame(stack);

    bool user = 0;
    char c;
    while (1)
    {
        /* code */

        system("cls");
        skips();
        mainlogo();
        cout << endl;
        spaces();
        cout << " 1) See Top Latest Posts " << endl;
        cout << endl;
        spaces();
        cout << " 2) Find Your Relevant Post " << endl;
        cout << endl;
        spaces();
        cout << " 3) Write a post " << endl;
        cout << endl;
        spaces();

        if (user)
        {

            cout << " 4) View My Posts" << endl;
        }
        else
        {
            cout << " 4) Login " << endl;
        }
        cout << endl;
        spaces();
        cout << " 5) Exit " << endl;
        cout << endl;

        c = getch();

        switch (c)
        {
        case '1':

            Browsing(stack);
            break;
        case '2':
            Searching();
            break;
        case '3':
            Writing(user, stack, userstack);
            break;
        case '4':
            if (user)
            {

                Personal_posts(userstack);
            }

            else
            {
                user = login_signup();
                user_stack(userstack);
            }
            break;

        case '5':
            exit(0);
            break;
        default:
            cout << "hey;";
            break;
        }
    }
}

int main()
{
	 system("Color E4");
    startfunc();
}
