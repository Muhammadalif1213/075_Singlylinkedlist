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

	Node* nodeBaru = new Node;
	nodeBaru->noMhs = nim;
	strcpy_s(nodeBaru->nama, nm);

	if (START == NULL || nim <= START->noMhs)
	{
		if ((START != NULL) && (nim == START->noMhs))
		{
			cout << "\nDuplikasi noMhs tidak diijinkan\n";
			return;
		}
		nodeBaru->next = START;
		START = nodeBaru;
		return;
	}
	Node* previous, * current;

	current = START;
	previous = START;


	while ((current !=NULL)&& (nim>= current->noMhs))
	{
		if (nim == current ->noMhs)
		{
			cout << "\nDuplikasi noMhs tidak diijinkan\n";
			return;
		}
		previous = current;
		current = current->next;

	}
	/*Jika loop diatas dieksekusi, previous dan current akan menempati posisi dimana*/
	nodeBaru->next = current;
	nodeBaru->next = nodeBaru;
}

bool list::listEmpty()
{
	if (START == NULL)
		return true;
	else
		return false;
}
bool list::delNode(int nim)/*menghapus node dari dalam list*/
{
	Node* current, * previous;
	if (Search(nim, &previous, &current) == false)
		return false;
	previous->next = current->next;
	if (current == START)
		START = START->next;

	delete current;
	return true;
}

/*check apakah node yang dimaksud ada dalam list atau tidak*/
bool list::Search(int nim, Node** previous, Node** current)
{
	*previous = START;
	*current = START;
	while ((*current !=NULL)&&(nim !=(*current)->noMhs))
	{
		*previous = START;
		*current = (*current)->next;
	}
	return(*current != NULL);
}

void list::traverse()
{
	if (listEmpty())
		cout << "\nList Kosong\n";
	else
	{
		cout << endl << "Data didalam list adalah:" << endl;
		Node* currentNode;
		for (currentNode = START; currentNode != NULL; currentNode = currentNode->next)
		{
			cout << currentNode->noMhs << " " << currentNode->nama << "\n";
		}
		cout << endl;
	}
}

int main()
{
	list mhs;
	int nim;
	char ch;
	while (1)
	{
		cout << endl << "menu";
		cout << endl << "1. menambah data kedalam list"<< endl;
		cout << "2. menghapus data dari dalam list"<<endl;
		cout << "3. menampilkan semua data didalam list" << endl;
		cout << "4. mencari data dalam list" << endl;
		cout << "5. keluar" << endl;
		cout << endl << "masukan pilihan (1-5): ";
		cin >> ch;
		switch (ch)
		{
		case'1':
		{
			mhs.addNode();
		}
		break;

		case '2':
		{
			if (mhs.listEmpty())
			{
				cout << endl << "list Kosong" << endl;
				break;
			}
			cout << endl << "\nMasukan no mahasiswa yang akan dihapus: ";
			cin >> nim;
			if (mhs.delNode(nim) == false)
				cout << endl << "data tidak ditemukan" << endl;
			else
				cout << endl << "data dengan nomor mahasiswa " << nim << "berhasil di hapus" << endl;
		}
		break;
		case '3':
		{
			mhs.traverse();
		}
		break;
		 

		case'4':
		{
			if(mhs.listEmpty()==true)
			{
				cout << "\nlist kosong\n";
				break;
			}
			Node* previous, * current;
			cout << endl << "masukan nomor mahasiswa yang dicari: ";
			cin >> nim;
			if (mhs.Search(nim, &previous, &current) == false)
				cout << endl << "data tidak ditemukan" << endl;
			else
			{
				cout << endl << "data ditemukan" << endl;
				cout << "\nNo mahasiswa:" << current->noMhs;
				cout << "\n\nnama: " << current->nama;
				cout << "\n";
			}
		}
		break;
		case '5':
		{
			exit(0);
		}
		break;
		default:
		{
			cout << "pilihan salah !." << endl;
		}
		break;
		}
	}
}