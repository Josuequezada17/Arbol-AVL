#include <iostream>
#include <fstream>
#include "menu.hpp"

using namespace std;

void Menu::mainMenu(BTree<Persona>& myArbol) {
    char op, opcionMenuPrincipal;
    string myCadena;
    bool carga = false;

    Name myNombre;
    Persona myAlumno;

    BTree<Persona>::Position pos;

    do {
        system("cls");
        system("color 79");

        if(carga == true){
        cout <<myArbol.parsePreOrder() << endl;
        }
        cout << "  UDG ALUMNOS     " << endl
             << "    MAIN MENU     " << endl << endl
             << "Add a new student [A]" << endl
             << "Delete student    [B]" << endl
             << "Find student      [C]" << endl
             << "Retrieve student  [D]" << endl
             << "Get height        [E]" << endl
             << "Get higest        [F]" << endl
             << "Get lowest        [G]" << endl
             << "Parse preOrder    [H]" << endl
             << "Parse inOrder     [I]" << endl
             << "Parse posOrder    [J]" << endl
             << "Show tree         [K]" << endl
             << "Load tree         [L]" << endl
             << "Save tree         [M]" << endl
             << "DeleteAll         [N]" << endl
             << "EXIT              [0]" << endl << endl
             << "Option: ";

        cin >> opcionMenuPrincipal;
        cin.ignore();
        system("cls");

        switch(opcionMenuPrincipal) {
        case 'A':
            do {
                cout << "Code: ";
                getline(cin, myCadena);
                myAlumno.setCodigo(myCadena);

                cout << "Student first name: ";
                getline(cin, myCadena);
                myNombre.setFirst(myCadena);

                cout << "Student last name: ";
                getline(cin, myCadena);
                myNombre.setLast(myCadena);

                myAlumno.setAlumno(myNombre);

                myArbol.insertData(myAlumno);
                myArbol.writeToDisk();

                cout << "Insert one more? (y/n): ";
                cin >> op;
                cin.ignore();

            } while(op == 'y' or op == 'Y');
            break;

        case 'B':

            cout<< myArbol.parsePreOrder()<<endl;

            do {

                cout<<"Write the code of the studnet to delete: ";
                getline(cin,myCadena);
                myAlumno.setCodigo(myCadena);
                pos = myArbol.findData(myAlumno);

                cout << endl << endl;

                if(pos == nullptr) {
                    cout << "Isn't found" << endl;
                } else {
                    cout<<"Deleting the student: "<<myCadena<<endl;

                    cout<< myArbol.retrieve(pos).toString();

                    cout<<endl<<endl;

                    myArbol.deleteData(myAlumno);

                    cout <<endl;
                }

                cout << myArbol.parsePreOrder()<<endl<<endl;

                cout << "Do you want to delete other? (y/n): ";
                cin >> op;
                cin.ignore();

            } while(op == 'y' or op == 'Y');
            break;

        case 'C':
            cout << myArbol.parsePreOrder()<<endl<<endl;

            cin.ignore();
            cout << "Write the studnet code to search: ";
            getline(cin, myCadena);
            myAlumno.setCodigo(myCadena);
            system("cls");

            pos = myArbol.findData(myAlumno);

            cout<< "The student with name "<<myCadena;
            if(pos == nullptr) {
                cout<<" isn't in the tree "<<endl<<endl;
            } else {
                cout<< " is in the position "<<pos<< " of the tree"<<endl<<endl;
                cout<< " Student: ";
                cout<< myArbol.retrieve(pos).getCodigo()<<endl<<endl;
                cout<< " Full record: "<<endl;
                cout<< myArbol.retrieve(pos).toString()<<endl<<endl;
            }
            pos = nullptr;

            system("pause");
            break;

        case 'D':
            cout << "Introduce the student's code to retrieve: ";
            getline(cin, myCadena);
            system("cls");
            myAlumno.setCodigo(myCadena);
            pos = myArbol.findData(myAlumno);
            cout << myArbol.retrieve(pos).toString() << endl;
            system("pause");
            break;

        case 'E':
            cout << "Height of the tree: " << myArbol.getHeight()
                 << endl;
            break;

        case 'F':
            cout << "Highest: " << myArbol.retrieve(myArbol.getHighest()) << endl;
            break;

        case 'G':
            cout << "Lowest: " << myArbol.retrieve(myArbol.getLowest()) << endl;
            break;

        case 'H':
            cout << "Parse Pre-Order: " << endl
                 << myArbol.parsePreOrder() << endl;
            break;

        case 'I':
            cout << "Parse In-Order: " << endl
                 << myArbol.parseInOrder() << endl;
            break;

        case 'J':
            cout << "Parse Post-Order: " << endl
                 << myArbol.parsePostOrder() << endl;
            break;

        case 'K':
            cout << endl << myArbol.toString() << endl;
            break;

        case 'L':
            myArbol.readFromDisk();
            cout << "Tree ready." << endl;
            carga = true;
            break;

        case 'M':
           myArbol.writeToDisk();
            cout << "Saving tree." << endl;
            break;

        case 'N':
            myArbol.deleteAll();
            cout << "Delete all the tree." << endl;
            break;

            case '0':
                system("Color A0");
                cout<<"Exit of UDG alumnos"<<endl;
                break;

            default:
                system("color 4F");
                cout<<"Invalid option!"<<endl;
                cout<<"Insert a valid option"<<endl;

        }

        cout << endl;
        system("pause");

    } while(opcionMenuPrincipal != '0');
}

