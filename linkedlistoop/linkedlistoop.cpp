#include<iostream>
#include<string.h>
using namespace std;

class Node
{
public:
	int noMhs;
	char nama[20];
	Node* next;
};

class list
{
	Node* START;
public:
	list();
	void addNode();
	bool Search(int nim, Node** current, Node** previous);
	bool listEmpty();
	bool delNode(int element);
	void traverse();
};

list::list()
{
	START = NULL;
}
void list::addNode()	/*Menambahkan sebuah Node ke dalam list*/
{
	int nim;
	char nm[20];
	cout << "\nMasukan nomor mahasiswa: ";
	cin >> nim;
	cout << "\nMasukan nama: ";
	cin >> nm;

}
