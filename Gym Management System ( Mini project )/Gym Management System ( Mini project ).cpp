#include "Header.h"
#include <iostream>
#include<string>
using namespace std;

int main()
{
    DoublyLinkedList Clients;
    Clients = InitialGymList();
    bool running = true;

    while (running)
    {
        int option;
        system("CLS");
        cout << "\n\n\n" << endl;
        cout << "\t\t\t\t==================================================\n" << endl;
        cout << "\t\t\t\t\tWelcome to GYM Management System\n" << endl;
        cout << "\t\t\t\t\tPlease select an option:" << endl;
        cout << "\t\t\t\t\t\t1. Add new member" << endl;
        cout << "\t\t\t\t\t\t2. Modify member" << endl;
        cout << "\t\t\t\t\t\t3. Display all members" << endl;
        cout << "\t\t\t\t\t\t4. Select member" << endl;
        cout << "\t\t\t\t\t\t5. Diet Plans" << endl;
        cout << "\t\t\t\t\t\t6. Delete member" << endl;
        cout << "\t\t\t\t\t\t7. Quit \n" << endl;
        cout << "\t\t\t\t==================================================" << endl;



        cin >> option;



        if (option == 1)
        {
            system("CLS");
            string name, address;
            int age;
            float height, weight;

            cout << "\n\n\t\tEnter name: ";
            getline(cin >> ws, name);
            cout << "\n\t\tEnter address: ";
            getline(cin >> ws, address);
            cout << "\n\t\tEnter age: ";
            cin >> age;
            cout << "\n\t\tEnter height (in meters): ";
            cin >> height;
            cout << "\n\t\tEnter weight (in kilograms): ";
            cin >> weight;

            User U(name, address, age, height, weight);
            Clients.insertLast(U);

        }
        else if (option == 2)
        {
            system("CLS");
            int id;
            cout << "\n\n\t\tEnter user ID to modify: ";
            cin >> id;

            Node* ptr = Clients.getAt(id - 1);

            string newAddress;
            int newage;
            float newhight;
            float newweight;

            cout << "\n\n\t\tEnter new address: ";
            getline(cin >> ws, newAddress);
            ptr->data.setAddress(newAddress);
            cout << "\n\t\tEnter new age: ";
            cin >> newage;
            ptr->data.setAge(newage);
            cout << "\n\t\tEnter new height (in meters): ";
            cin >> newhight;
            ptr->data.setHeight(newhight);
            cout << "\n\t\tEnter new weight (in kilograms): ";
            cin >> newweight;
            ptr->data.setWeight(newweight);

            ptr->data.CalcBMI();
        }

        else if (option == 3)
        {
            system("CLS");
            Clients.printAllUsers();
            system("PAUSE");
        }
        else if (option == 4)
        {
            system("CLS");
            Clients.printAllUsers();
            cout << "\nEnter the index of the User ";
            int ind;
            cin >> ind;
            Node* u = Clients.getAt(ind - 1);


            system("CLS");
            u->data.printUser();
            system("PAUSE");

        }
        else if (option == 5)
        {
            system("CLS");
            Clients.printAllUsers();
            cout << "\nEnter the index of the User ";
            int ind;
            cin >> ind;
            Node* u = Clients.getAt(ind - 1);


            system("CLS");
            u->data.dietPlan();
            system("PAUSE");

        }

        else if (option == 6)
        {
            system("CLS");
            Clients.printAllUsers();

            int id;
            cout << "\nEnter user ID to delete: ";
            cin >> id;
            Clients.deleteAt(id - 1);


        }
        else if (option == 7) {
            running = false;
        }
        else
        {
            cout << "Invalid option\n";
            system("PAUSE");
        }
    }
    return 0;
}