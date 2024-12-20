#include <iostream>
#include <fstream>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <windows.h>
using namespace std;
class node {
private:
	string name, gender, nationality;
	int age, phone_number;
public:
	node();
	node* next;
	// all set fun
	void set_name(string na);
	void set_gender(string ge);
	void set_nationality(string nat);
	void set_age(int agge);
	void set_phone_number(int phone);
	//////all get fun//////////////////////////////////
	string get_name();
	string get_gender();
	string get_nationality();
	int get_age();
	int get_phone_number();
};
class Queues
{
public:
	int max = 0;
	node* frist;
	node* last;
	node* entered_room;
	Queues();
	void enQueues(string name, string gender, string nationality, int agge, int phone);
	void deQueues();
	void search(string name);
	void count();
	void display();
	void clearAll();
	void ness(string name, string gender, string nationality, int agge, int phone);
	void enquess_room();
	void out_room();
	void print_entered_room();
};
node::node() {
	name = "no name";
	gender = "no gender";
	nationality = "no nationality";
	age = 0;
	phone_number = 0;

}
Queues::Queues() {
	frist = NULL;
}
void node::set_name(string namee) {
	name = namee;
}
void node::set_gender(string genderr) {
	gender = genderr;
}
void node::set_nationality(string nationalityy) {
	nationality = nationalityy;
}
void node::set_age(int agee) {
	age = agee;
}
void node::set_phone_number(int phone_numberr) {
	phone_number = phone_numberr;
}
string node::get_name() {
	return name;
}
string node::get_gender() {
	return gender;
}
string node::get_nationality() {
	return nationality;
}
int node::get_age() {
	return age;
}
int node::get_phone_number() {
	return phone_number;
}
void Queues::enQueues(string name, string gender, string nationality, int agge, int phone) {

	if (max < 20) {
		node* newnode = new node;
		newnode->set_name(name);
		newnode->set_gender(gender);
		newnode->set_nationality(nationality);
		newnode->set_age(agge);
		newnode->set_phone_number(phone);
		if (frist == NULL) {
			frist = newnode;
			last = newnode;

		}
		else {
			last->next = newnode;
			last = newnode;
		}
		newnode->next = NULL;
		++max;
	}
	else {
		cout << "Room full" << endl;
	}
}
void Queues::enquess_room() {

	entered_room = frist;
	deQueues();

}
void Queues::out_room() {
	if (entered_room == NULL) {
		cout << "no one in room";
	}
	else {
		entered_room = NULL;
	}
}
void Queues::deQueues() {
	if (max > 0) {
		node* temp = frist;
		frist = frist->next;
		delete temp;
		++max;
	}
	else {
		cout << "Room is empty";
	}

}
void Queues::display() {
	node* temp = frist;
	while (temp != NULL) {
		cout << setw(15) << "Name" << setw(20) << "Phone Number" << setw(10) << "Gender" << setw(15) << "Nationality" << endl;
		cout << setw(15) << temp->get_name() << setw(20) << temp->get_phone_number() << setw(10) << temp->get_gender() << setw(15) << temp->get_nationality() << endl;

		temp = temp->next;
	}
}
void Queues::clearAll() {
	while (frist != NULL) {
		deQueues();
	}
	cout << "Room cleared";
}
void Queues::ness(string name, string gender, string nationality, int agge, int phone) {
	node* newnode = new node;
	newnode->set_name(name);
	newnode->set_gender(gender);
	newnode->set_nationality(nationality);
	newnode->set_age(agge);
	newnode->set_phone_number(phone);
	newnode->next = frist;
	frist = newnode;
	++max;
}
void Queues::count() {
	int i = 0;
	node* temp = frist;
	while (temp != NULL) {
		i++;
		temp = temp->next;
	}
	cout << "count = " << i << endl;
}
void Queues::search(string name) {
	node* temp = frist;
	while (temp->get_name() != name) {
		temp = temp->next;
	}
	cout << " name : " << temp->get_name() << endl;
	cout << " phone number : " << temp->get_phone_number() << endl;
	cout << "gender :  " << temp->get_gender() << endl;
	cout << "nationality :  " << temp->get_nationality() << endl;
}
void Queues::print_entered_room() {
	if (entered_room == NULL) {
		cout << "no one in room " << endl;
	}
	else {
		cout << "***" << entered_room->get_name() << "***" << endl;
	}
}
class Boss_class
{

private:
	string nameOfClass, Dr;//dr = dector
	int numberOfClass;

public:
	Queues* newQueues = new Queues;
	Boss_class* next;
	Boss_class();
	Boss_class(string name, int num, string Dector);
	void set_nameOfClass(string nnameOfClass);
	void set_numberOfClass(int nnumberOfClass);
	string get_nameOfClass();
	int get_numberOfClass();
	string get_Dector();
	void add(string name, string gender, string nationality, int agge, int phone);
	void delete_();
	void display();
	void ness(string name, string gender, string nationality, int agge, int phone);
	void enquess_room();
	void out_room();
	void print_entered_room();
};
Boss_class::Boss_class() {
	nameOfClass = "no nameOfClass";
	numberOfClass = 0;
}
Boss_class::Boss_class(string namee, int numm, string Dector) {
	nameOfClass = namee;
	numberOfClass = numm;
	Dr = Dector;
	cout << "creat room " << endl;
}
void Boss_class::set_nameOfClass(string n) {
	nameOfClass = n;
}
void Boss_class::set_numberOfClass(int nn) {
	numberOfClass = nn;
}
string Boss_class::get_nameOfClass() {
	return nameOfClass;
}
int Boss_class::get_numberOfClass() {
	return numberOfClass;
}
void Boss_class::add(string name, string gender, string nationality, int agge, int phone) {

	newQueues->enQueues(name, gender, nationality, agge, phone);
}
void Boss_class::delete_() {
	newQueues->deQueues();
}
void Boss_class::display() {
	newQueues->display();
}
void Boss_class::ness(string name, string gender, string nationality, int agge, int phone) {
	newQueues->ness(name, gender, nationality, agge, phone);
}
string Boss_class::get_Dector() {
	return Dr;
}
void Boss_class::enquess_room() {
	newQueues->enquess_room();
}
void Boss_class::out_room() {
	newQueues->out_room();
}
void Boss_class::print_entered_room() {
	newQueues->print_entered_room();
}

class Linked_class
{
public:
	Boss_class* head;
	Linked_class();
	void newclass(string name, int num, string Dector);
	void delete_class(int number_of_class);
	void displyall();
	void displyroom(int num);
	void add(string name, string gender, string nationality, int agge, int phone, int numberOfClass);
	void nes(string name, string gender, string nationality, int agge, int phone, int numberOfClass);
	void enquess_room(string name_dector);
	void out_room(string name);
	void print_entered_room(string name);
};
Linked_class::Linked_class() {
	head = NULL;
}
void Linked_class::newclass(string name, int num, string Dector) {
	Boss_class* newclass = new Boss_class(name, num, Dector);
	if (head == NULL) {
		head = newclass;
		newclass->next = NULL;
	}
	else {
		newclass->next = head;
		head = newclass;
	}
}
void Linked_class::delete_class(int number_of_class) {
	if (head == NULL) {
		cout << "we can not find  room " << endl;
	}
	else {
		Boss_class* temp = head;
		while (temp != NULL && temp->get_numberOfClass() != number_of_class) {
			temp = temp->next;
		}
		if (temp == NULL) {
			cout << "Room not found" << endl;
		}
		else {
			delete temp;
			cout << "delete Room sussed" << endl;
		}
	}

}
void Linked_class::displyall() {
	Boss_class* temp = head;
	while (temp != NULL) {
		cout << temp->get_nameOfClass() << endl;
		cout << temp->get_numberOfClass() << endl;
		temp->display();
		cout << "====================================" << endl;
		temp = temp->next;
	}
}
void Linked_class::displyroom(int num) {
	Boss_class* temp = head;
	while (temp->get_numberOfClass() != num) {
		temp = temp->next;
	}
	temp->display();
}
void Linked_class::add(string name, string gender, string nationality, int agge, int phone, int numberOfClass) {

	Boss_class* temp = head;
	while (temp != NULL && temp->get_numberOfClass() != numberOfClass) {
		temp = temp->next;
	}
	if (temp == NULL) {
		cout << "we canot find Room" << endl;
	}
	else {
		temp->add(name, gender, nationality, agge, phone);
	}
}
void Linked_class::nes(string name, string gender, string nationality, int agge, int phone, int numberOfClass) {
	Boss_class* temp = head;
	while (temp != NULL && temp->get_numberOfClass() != numberOfClass) {
		temp = temp->next;
	}
	if (temp == NULL) {
		cout << "we canot find Room" << endl;
	}
	else {
		temp->ness(name, gender, nationality, agge, phone);
	}
}
void Linked_class::enquess_room(string name) {
	if (head == NULL) {
		cout << "no one in room " << endl;
	}
	else {
		Boss_class* temp = head;
		while (temp != NULL && temp->get_Dector() != name) {

			temp = temp->next;
		}
		temp->enquess_room();
	}
}
void Linked_class::out_room(string name) {
	if (head == NULL) {
		cout << "no one in room " << endl;
	}
	else {
		Boss_class* temp = head;
		while (temp->get_Dector() != name) {

			temp = temp->next;
		}
		temp->out_room();
	}

}
void Linked_class::print_entered_room(string name) {
	if (head == NULL) {
		cout << "no one in room " << endl;
	}
	else {
		Boss_class* temp = head;
		while (temp != NULL && temp->get_Dector() != name) {
			temp = temp->next;
		}
		temp->print_entered_room();
	}
}



class MyClass {
public:
	string username, password, nameDr;
	void adddd(string u, string p, string n)
	{
		username = u;
		password = p;
		nameDr = n;
	}
};
int main() {
	int x = 0;
	bool shek;
	int emergencyOrnormal, numberofroom;
	//
	string name, gender, nationality;
	int agge, phone;
	//
	//login admin
	string u;
	string p;
	//

	int numberOfClassShreach;
	int chooseShowAdmin;
	int deleteNumOfRoom;
	string username_d, password_d, nameDr_d;//d as dector
	Linked_class Linked_class1;
	int choose_mode, numberOfClass;
	// Create an array of objects on the stack
	MyClass arrayOnStack[100];
	int i = 0;
	string username_admin, password_admin, nameOfClass, DrOfClass;
	/////login dector
	string name_dector, username_dector, password_dector;
	//in room and out room//
	int cho;
	////
	while (true) {
		//Check the file path
		ifstream indata_of_admin("C:\\Users\\AAMMK\\Desktop\\project data\\out data admin.txt", ios::app);
		ofstream outdata_of_admin("C:\\Users\\AAMMK\\Desktop\\project data\\out data admin.txt", ios::app);
		int tast = 0, tast1 = 0;
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
		int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

		// Calculate the left margin to center the table
		int leftMargin = (consoleWidth - 33) / 2;

		// Displaying a table-like structure in the middle of the screen
		cout << setw(leftMargin) << "" << "***********************************" << endl;
		cout << setw(leftMargin) << "" << "* Welcome                        *" << endl;
		cout << setw(leftMargin) << "" << "* Please choose the              *" << endl;
		cout << setw(leftMargin) << "" << "* appropriate number             *" << endl;
		cout << setw(leftMargin) << "" << "***********************************" << endl;
		cout << setw(leftMargin) << "" << "* 1- manager system              *" << endl;
		cout << setw(leftMargin) << "" << "* 2- reception system            *" << endl;
		cout << setw(leftMargin) << "" << "* 3- Dr system                   *" << endl;
		cout << setw(leftMargin) << "" << "***********************************" << endl;
		cin >> choose_mode;
		switch (choose_mode) {
		case 1:
			if (indata_of_admin.is_open() && outdata_of_admin.is_open()) {
				if (indata_of_admin >> username_admin && indata_of_admin >> password_admin) {
					cout << "enter your username";
					cin >> u;
					cout << "enter your password";
					cin >> p;
					if (u == username_admin && p == password_admin) {
						tast = 1;
					}
				}
				else {
					cout << "Welcome to admin mode. Please enter the username and password" << endl;
					cout << "enter your username " << endl;
					cin >> username_admin;
					outdata_of_admin << username_admin;
					outdata_of_admin << endl;
					cout << "enter your password " << endl;
					cin >> password_admin;
					outdata_of_admin << password_admin;
					outdata_of_admin.close();
					tast1 = 1;
				}
			}
			else {
				cout << "canot open file system";
				exit(1);
			}
			if (tast == 1 || tast1 == 1) {
				cout << "hello manager " << endl;
				cout << "1- Add a new room" << endl;
				cout << "2- add a new doctor" << endl;
				cout << "3- delete a room " << endl;
				cout << "4- Show patients" << endl;
				int key;
				cin >> key;
				switch (key) {
				case 1:
					cout << "enter yout number Of Class" << endl;
					cin >> numberOfClass;
					cout << "enter name Of Class" << endl;
					cin >> nameOfClass;
					cout << "enter Dr Of Class" << endl;
					cin >> DrOfClass;
					Linked_class1.newclass(nameOfClass, numberOfClass, DrOfClass);
					break;
				case 2:
					cout << "enter name:";
					cin >> nameDr_d;
					cout << "enter username:";
					cin >> username_d;
					cout << "enter password:";
					cin >> password_d;
					arrayOnStack[i].adddd(username_d, password_d, nameDr_d);
					cout << endl << "==============================================================" << endl;
					i++;
					break;
				case 3:
					cout << "Enter the room number you would like the delete" << endl;
					cin >> deleteNumOfRoom;
					Linked_class1.delete_class(deleteNumOfRoom);
					break;
				case 4:
					cout << "Do you want to show patients in the entire hospital or a specific room?" << endl;
					cout << "1: all" << endl;
					cout << "2: specific room" << endl;
					cin >> chooseShowAdmin;
					if (chooseShowAdmin == 1) {
						Linked_class1.displyall();
					}
					else {
						cout << "enter the number of room";
						cin >> numberOfClassShreach;
						Linked_class1.displyroom(numberOfClassShreach);
					}
					break;
				default:
					cout << "You entered the wrong number";
				}
			}
			else {
				cout << "The user name or password is incorrect";
				continue;
			}
			break;
		case 2:
			cout << "Is it an emergency or normal?" << endl;

			cout << "1- emergency" << endl;
			cout << "2- normal" << endl;
			cin >> emergencyOrnormal;
			if (emergencyOrnormal == 1) {
				cout << "entr number of room";
				cin >> numberofroom;

				cout << "enter name " << endl;
				cin >> name;

				cout << "enter age " << endl;
				cin >> agge;

				cout << "enter nationality" << endl;
				cin >> nationality;

				cout << "enter gender" << endl;
				cin >> gender;
				cout << "enter phone" << endl;
				cin >> phone;
				Linked_class1.nes(name, gender, nationality, agge, phone, numberofroom);

			}
			else {
				cout << "entr number of room";
				cin >> numberofroom;

				cout << "enter name " << endl;
				cin >> name;

				cout << "enter age " << endl;
				cin >> agge;

				cout << "enter nationality" << endl;
				cin >> nationality;

				cout << "enter gender" << endl;
				cin >> gender;
				cout << "enter phone" << endl;
				cin >> phone;
				Linked_class1.add(name, gender, nationality, agge, phone, numberofroom);
			}
			break;
		case 3:
			cout << "hello doctor nice to meet you" << endl;
			cout << "enter name :";
			cin >> name_dector;
			cout << "enter username :";
			cin >> username_dector;
			cout << "enter password :";
			cin >> password_dector;

			while (x < 100) {

				if (arrayOnStack[x].username != username_dector && arrayOnStack[x].password != password_dector) {

					++x;
					shek = false;
				}
				else {
					shek = true;
					break;
				}
			}
			if (shek == false) {
				cout << "we canot find you" << endl;
				x = 0;
			}

			else {
				while (true) {


					cout << " 1- Admitting a patient," << endl;
					cout << " 2- removing a patient," << endl;
					cout << " 3- Exit the system," << endl;
					cout << " 4- Print current patient," << endl;
					cin >> cho;
					if (cho == 1) {
						Linked_class1.enquess_room(name_dector);
					}
					else if (cho == 2) {

						Linked_class1.out_room(name_dector);
					}
					else if (cho == 3) {
						break;
						continue;
					}
					else if (cho == 4) {
						Linked_class1.print_entered_room(name_dector);
					}
				}
			}

		}


	}

	return 0;
}