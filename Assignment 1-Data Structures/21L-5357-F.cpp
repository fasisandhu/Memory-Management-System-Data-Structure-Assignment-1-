#include <iostream>
using namespace std;

class block;//as sorting and merging functions are friend functions in list class wrt block
template <class t>
class List {
private:
	//node
	struct node {
		t data;
		node* next;
		node() { next = NULL; }
		node(t el, node* ptr=NULL)
		{
			data = el; next = ptr;
		}
	};
	////////////
	class ListIterator {
	public:
		friend class List;
		ListIterator(node* ptr = NULL)
		{ iptr = ptr; };
		ListIterator& operator++()
		{
			if (iptr) iptr = iptr->next;
			return (*this);
		}
		ListIterator& operator++(int) {
			ListIterator old1 = *this;
			++(*this);
				return old1;
		}
		ListIterator& returnonenext()
		{
			ListIterator dummy;
			dummy.iptr = iptr->next;
			return  dummy;
		}
		void setdata(t val)
		{
			iptr->data = val;
		}
		t& operator*() {

			return iptr->data;

		}
		bool operator==(const ListIterator& l) const
		{

			return iptr == l.iptr;

		}

		bool operator!=(const ListIterator& l) const {

			return !(iptr == l.iptr);

		}
		void setiptrdata(t val)
		{
			iptr->data = val;
		}
	private:

		node* iptr;

	};
	node* head, * tail;
	int size;
public:
	typedef ListIterator Iterator;
	Iterator begin() { Iterator I(head); return I; }
	Iterator end() { Iterator I(tail); return I; }
	List()
	{
		head = tail = NULL;
		size = 0;
	}
	/*List(const List& obj)
	{
		if (obj.head == NULL)
			head = NULL;
		else
		{
			head = new node;
			head->data = obj.head->data; dummy head no data
			node* temp = head->next;
			node* tempforobj = obj.head->next;
			for (int i = 1; i <= obj.size; i++)
			{
				temp= new node;
				temp->data = tempforobj->data;
				temp = temp->next;
				tempforobj = tempforobj->next;
			}
			temp = new node;
			tail = temp;
			size = obj.size;
		}
	}
	List& operator=(List& obj)
	{
		if (obj.head == NULL)
					head = NULL;
		else
		{
			head = new node;
			head->data = obj.head->data; dummy head no data
			node* temp = head->next;
			node* tempforobj = obj.head->next;
			for (int i = 1; i <= obj.size; i++)
			{
				temp= new node;
				temp->data = tempforobj->data;
				temp = temp->next;
				tempforobj = tempforobj->next;
			}
			temp = new node;
			tail = temp;
			size = obj.size;
		}
		return *this;
	}*/
	~List()
	{
	
		head = NULL;


		if (head != 0)
		{
			while (head != 0)
			{
				node* p = head->next;
				delete head;
				head = p;
			}
		}

	}

	void insert_at_start(t val)
	{
		if (head == NULL)
		{
			head = new node;//dummy
			tail = new node;
			node* temp = new node(val, tail);
			head->next = temp;
			size++;
		}
		else
		{
			node* temp = new node(val, head->next);
			head->next = temp;size++;
		}

	}


	void insert_at_tail(t& el)
	{
		if (head == NULL)
		{
			head = new node;//dummy
			tail = new node;
			node* temp = new node(el, tail);
			head->next = temp; size++;
		}
		else
		{
			node* temp; /*node* temp2 = new node(element, tail);*/
			for (temp = head; temp->next != tail; temp = temp->next)
			{
				
			}
			temp->next = new node(el, tail); size++;
		}
	}

	void deletebyiterator(Iterator it)
	{
		if (head != 0 || head->next != tail)//for empty
		{
			node* temp = it.iptr;
			if (temp == head->next&&temp->next==tail)//means one element
			{
				delete temp;
				head->next = tail;
				size--;
			}
			else
			{
				List<t>::Iterator it1;
				List<t>::Iterator it2;
				it1 = begin();//as it is dummy head
				it2 = end();
				node* temp1=0;
				while (it1 != it2)
				{
					temp1 = it1.iptr;
					if (temp1->next == temp)
					{
						break;
					}it1++;
				}
				//the item to be deleted is after it1 so
				temp1->next = temp->next;
				delete temp;
				size--;
			}
		}
	}
	void unionlist(List l1)
	{
		node* temp; /*node* temp2 = new node(element, tail);*/
		for (temp = head; temp->next != tail; temp = temp->next)
		{

		}
		//delete tail;
		tail = l1.tail;
		temp->next = l1.head->next;//now tail of l1 will become tail of the main list
		//and head of l1 is delete and tail of main list too
		size = size + l1.size;
	}

	friend void sorting(List<block> l);
	friend void merging(List<block> l);

};

class block
{
	int start_byte_ID;
	int total_bytes;
public:
	block(int id=0,int t=0)
	{
		start_byte_ID = id; total_bytes = t;
	}
	//block(const block& obj)
	//{
	//	start_byte_ID = obj.start_byte_ID;
	//	total_bytes = obj.total_bytes;
	//}
	//block& operator=(block&obj)
	//{
	//	start_byte_ID = obj.start_byte_ID;
	//	total_bytes = obj.total_bytes;
	//	return *this;
	//}
	//no destructor as no dynamic member
	void setbyteID(int id)
	{
		start_byte_ID = id;
	}
	int getbyteID()
	{
		return start_byte_ID;
	}
	void settotalbytes(int t)
	{
		total_bytes = t;
	}
	int gettotalbytes()
	{
		return total_bytes;
	}

};
class program
{
	int id;
	int size;
	List<block> linklistofblocks;
public:
	program()
	{
		id = 0; size = 0;
	}
	program(List<block> linklist, int id = 0, int size = 0)
	{

	}
	//program(const program& obj)
	//{
	//	id = obj.id;
	//	size = obj.size;
	//	linklistofblocks = obj.linklistofblocks;
	//}
	/*program& operator=(program &obj)
	{
		id = obj.id;
		size = obj.size;
		linklistofblocks = obj.linklistofblocks;
		return *this;
	}*/
	void setprogID(int IDD)
	{
		id = IDD;
	}
	int getprogID()
	{
		return id;
	}
	void setsize(int t)
	{
		size = t;
	}
	int getsize()
	{
		return size;
	}
	void setblocklist(List<block> t)
	{
		linklistofblocks = t;
	}
	List<block> getblocklist()
	{
		return linklistofblocks;
	}
	void insertablock(block el)
	{
		List<block>::Iterator it;
		it = linklistofblocks.begin();
		//size = size + el.gettotalbytes();
		if (it == NULL)//means the linklist is empty
		{
			linklistofblocks.insert_at_start(el);
		}
		else
		{
			linklistofblocks.insert_at_tail(el);
		}
	}

};

class MemoryManagementSystem
{
	List<block> pool;
	List<program> progs;
	int sizeOfMemory;
	bool strategy;//first fit==True && best fit==False
public:
	void run()
	{
		cout << "Enter size of memory::" << endl;
		cin >> sizeOfMemory;
		cout << "Enter your strategy(0 for First Fit or 1 for Best Fit" << endl;
		int n; cin >> n;
		while (n != 0 && n != 1)
		{
			cout << "enter again" << endl;
			cin >> n;
		}
		if (n == 0)
		{
			strategy = true;
		}
		else
			strategy = false;
		
		//strategy = strat;
		//sizeOfMemory = size;
		block obj; obj.setbyteID(0);
		obj.settotalbytes(sizeOfMemory);
		pool.insert_at_start(obj);
	}

	void menu()
	{
		int c=-1;
		run();
		while (c != 5)
		{
			cout << "Enter your choice::" << endl;
			cout << "1::getmem" << endl;
			cout << "2::deleteaprogram" << endl;
			cout << "3::print pool" << endl;
			cout << "4::print programs" << endl;
			cout << "5::exit" << endl;

			cin >> c;
			while (c != 2 && c != 1 && c != 3 && c != 4 && c != 5)
			{
				cout << "enter again" << endl;
				cin >> c;
			}
			if (c == 1)
			{
				int id, mem;
				cout << "Enter id of program(ONLY INT)" << endl;
				cin >> id;
				cout << "Enter the memory of program" << endl;
				cin >> mem; bool r;
				r = get_mem(id, mem);
				if (r)
					cout << "success" << endl;
				else
					cout << "failed" << endl;
			}
			else if (c == 2)
			{
				int id;
				cout << "Enter id of program" << endl;
				cin >> id;
				//deleteprogram(id);
				bool r;
				r = deleteprogram(id);
				if (r)
					cout << "success" << endl;
				else
					cout << "failed" << endl;
			}
			else if (c == 3)
			{
				print();
			}
			else if (c == 4)
			{
				printprog();
			}
			else if (c == 5)
			{
				break;
			}
		}
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	bool get_mem(int prog_id, int size_mem)
	{
		//finding if prog exist
		List<program>::Iterator it;
		List<program>::Iterator it2; it2 = progs.end();
		List<program>::Iterator reqit;
		int chk = 0;
		for (it = progs.begin(); it != it2; it++)
		{
			program* tem = &(*it);
			//program tem = *it;
			if (prog_id == (*tem).getprogID())
			{
				reqit = it; chk = 1;
			}
		}
		program* temp=new program;
		if (chk == 1)
		{
			temp = &(*reqit);
			//List<block> l = temp.getblocklist();
		}
		else
		{
			/*program* temp = new program;*/ (*temp).setsize(size_mem);
			(*temp).setprogID(prog_id);
		}
		List<block>::Iterator itforpool;
		List<block>::Iterator itforpool3;
		List<block>::Iterator itforpool2;
		itforpool = pool.begin(); itforpool++;//as at head is dummy
		itforpool2 = pool.end();
		block min = *itforpool;
		int chkformin = 0;
		int chkformemorybestfit = 0;
		block tempforblock;
		while (itforpool != itforpool2)
		{
			tempforblock = *itforpool;
			if (strategy)//first fit
			{
				//itforpool3 = itforpool;
				if (size_mem <= tempforblock.gettotalbytes())
				{
					block tempblockinsetioninprogram; tempblockinsetioninprogram.setbyteID(tempforblock.getbyteID());
					tempblockinsetioninprogram.settotalbytes(size_mem);
					tempforblock.setbyteID(tempforblock.getbyteID() + size_mem);
					tempforblock.settotalbytes(tempforblock.gettotalbytes() - size_mem);
					(*temp).insertablock(tempblockinsetioninprogram);
					
					if (chk == 1)
					{
						(*temp).setprogID(prog_id);
						int sum = (*temp).getsize() + size_mem;
						(*temp).setsize(sum);
						reqit.setdata(*temp);
					}
					else
					 progs.insert_at_tail(*temp);
					if (tempforblock.gettotalbytes() == 0)
					{
						pool.deletebyiterator(itforpool);
					}
					else
					 itforpool.setdata(tempforblock);
				//	cout << tempforblock.getbyteID() << "  " << tempforblock.gettotalbytes() << endl;
				//	print();
					return true;
				}
				//itforpool++;
			}
			else//best fit
			{
				if (chkformin == 0 && size_mem <= tempforblock.gettotalbytes())
				{
					chkformin = 1; min = tempforblock; itforpool3 = itforpool;
					chkformemorybestfit = 1;
				}
				if(chkformin==1 && size_mem <= tempforblock.gettotalbytes() && tempforblock.gettotalbytes()<min.gettotalbytes())
				{
					itforpool3 = itforpool;
					min = tempforblock;
				}
			}
			itforpool++;
			
		}
		if (chkformemorybestfit == 1)//means memory found
		{
			//cout << "idd:::" << min.getbyteID() << endl;
			//cout << "idd75657:::" << size_mem << endl;
			block tempblockinsetioninprogram; tempblockinsetioninprogram.setbyteID(min.getbyteID());
			tempblockinsetioninprogram.settotalbytes(size_mem);
			min.setbyteID(min.getbyteID() + size_mem);
			//cout << "idd:::" << min.getbyteID() << endl;

			min.settotalbytes(min.gettotalbytes() - size_mem);
			if (min.gettotalbytes() == 0)
			{
				pool.deletebyiterator(itforpool3);
			}
			else
			itforpool3.setdata(min);
			(*temp).insertablock(tempblockinsetioninprogram);
			if (chk == 1)
			{
				(*temp).setprogID(prog_id);
				int sum = (*temp).getsize() + size_mem;
				(*temp).setsize(sum);
				reqit.setdata(*temp);
			}
			else
				progs.insert_at_tail(*temp);
			return true;
		}
		return false;
	}
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	bool deleteprogram(int prog_id)
	{
		//finding if prog exist
		List<program>::Iterator it;
		List<program>::Iterator it2; it2 = progs.end();
		List<program>::Iterator reqit;
		int chk = 0;
		for (it = progs.begin(); it != it2; it++)
		{
			program tem = *it;
			if (prog_id == tem.getprogID())
			{
				reqit = it; chk = 1;
			}
		}
		program *temp;
		if (chk == 1)
		{
			temp = &(*reqit);
		}
		else
		{
			return false;
		}
		List<block> tempforfreedblock;
		//print();
		tempforfreedblock = (*temp).getblocklist();
		//tempforfreedblock = (*temp).getblocklist();

		//List<block>::Iterator it1;
		//List<block>::Iterator it3;
		//it1 = tempforfreedblock.begin();
		//it3 = tempforfreedblock.end();
		//it1++;
		//while (it1 != it3)
		//{
		//	block temp = *it1;
		//	cout << "id:::" << temp.getbyteID() << endl;
		//	cout << "no of bytes:::" << temp.gettotalbytes() << endl;
		//	cout << endl;
		//	cout << endl;
		//	cout << endl;
		//	cout << endl;
		//	it1++;
		//}

		//pool.insert_at_start(tempforfreedblock);
		pool.unionlist(tempforfreedblock);
		progs.deletebyiterator(reqit);
	//	print();
		sorting(pool);
	//	print();
		merging(pool);
		return true;
	}
	void printprog()
	{
		List<program>::Iterator it1;
		List<program>::Iterator it2;
		it1 = progs.begin();
		it2 = progs.end();
		it1++;
		while (it1 != it2)
		{
			program temp1 = *it1;
			program temp = temp1;
			cout << "Program ID:: P-" << temp.getprogID() << endl;
			cout << "Program Size::" << temp.getsize() << endl;
			List<block> tempblock = temp.getblocklist();
			List<block>::Iterator it1b;
			List<block>::Iterator it2b;
			it1b = tempblock.begin();
			it2b = tempblock.end();
			it1b++;
			while (it1b != it2b)
			{
				block tempb = *it1b;
				cout << "id:::" << tempb.getbyteID() << endl;
				cout << "no of bytes:::" << tempb.gettotalbytes() << endl;
				cout << endl;
				cout << endl;
				it1b++;
			}
			it1++;
			
		}

	}
	void print()
	{
		List<block>::Iterator it1;
		List<block>::Iterator it2;
		it1 = pool.begin();
		it2 = pool.end();
		it1++;
		while (it1 != it2)
		{
			block temp = *it1;
			cout << "id:::" << temp.getbyteID() << endl;
			cout << "no of bytes:::" << temp.gettotalbytes() << endl;
			cout << endl;
			cout << endl;
			it1++;
		}
	}
};
void sorting(List<block> l)//friend func of list class
{
	List<block>::Iterator it1;
	List<block>::Iterator it2;
	List<block>::Iterator itonebeforetail;
	List<block>::Iterator ittwobeforetail;
	it1 = l.begin(); 
	it2 = l.end();
	int size = l.size;
	//size sis equal to nodes excluding head and tail;
	for (int i = 1; i < size; i++)
	{
		it1++;
	}
	ittwobeforetail = it1;
	it1 = l.begin();
	for (int i = 1; i <= size; i++)
	{
		it1++;
	}
	itonebeforetail = it1;
	it1 = l.begin(); it1++;

	while (it1 != itonebeforetail)
	{
		
		List<block>::Iterator itmin;
		itmin = it1;
		List<block>::Iterator itforjloop;
		itforjloop = it1;
		while (itforjloop != it2)
		{
			block temp1 = *itforjloop;
			block temp2 = *itmin;
			int t1 = temp1.getbyteID();
			int t2 = temp2.getbyteID();
			if (t1 < t2)
			{
				itmin = itforjloop;
			}
			itforjloop++;
		}
		if (it1 != itmin)
		{
			block temp;
			block temp1 = *it1;
			block temp2 = *itmin;
			temp.setbyteID(temp1.getbyteID());
			temp.settotalbytes(temp1.gettotalbytes());
			it1.setdata(temp2);
			//temp1.setbyteID(temp2.getbyteID());
			//temp1.settotalbytes(temp2.getbyteID());
			//temp2.setbyteID(temp.getbyteID());
			//temp2.settotalbytes(temp.getbyteID());
			itmin.setdata(temp);
		}
		it1++;

	}
}
void merging(List<block> l)
{
	List<block>::Iterator it1;
	List<block>::Iterator it2;
	it1 = l.begin();
	it2 = l.end();
	while (it1 != it2)
	{
		int c = 0;
		block temp1 = *it1;
		List<block>::Iterator it3;
		it3 = it1.returnonenext();
		if (it3 == it2)
		{
			break;
		}
		block temp2 = *it3;
		int sum = temp1.getbyteID() + temp1.gettotalbytes();
		if (sum == temp2.getbyteID())
		{
			int incr = temp1.gettotalbytes() + temp2.gettotalbytes();
			//temp1.setbyteID(incr);
			temp1.settotalbytes(incr);
			it1.setdata(temp1);
			c = 1;//merging occured
			l.deletebyiterator(it3);
		}
		if (c != 1)//so that it checks again the same node if chngng occurs
		{
			it1++;
		}
	}


}


int main()
{
	MemoryManagementSystem RAM;
	RAM.menu();

	//RAM.print();
	//RAM.run();
	//RAM.print();
	//RAM.get_mem(1, 40);
    //RAM.print();
	/*
	RAM.get_mem(2, 30);
	RAM.get_mem(1, 20);
	RAM.get_mem(3, 30);
	RAM.get_mem(1, 200);
	RAM.get_mem(2, 100);
	RAM.get_mem(4, 30);
	RAM.get_mem(3, 50);
	RAM.get_mem(4, 100);
	RAM.get_mem(3, 200);
	RAM.get_mem(4, 150);
	RAM.get_mem(3, 30);
	RAM.get_mem(4, 400);
	RAM.get_mem(5, 2180);
	RAM.get_mem(4, 250);
	RAM.get_mem(45, 3000);*/
	//RAM.print();
	//RAM.printprog();
	//RAM.deleteprogram(4);
	//RAM.get_mem(123, 200);
	//RAM.get_mem(321, 200);
	//RAM.get_mem(444, 50);
	//RAM.get_mem(788, 200);

	//RAM.printprog();
	//cout << "--------POOL------------" << endl;
	//RAM.print();
	//RAM.printprog();
	
	system("pause");
	return 0;
}