#pragma once
#include <iostream>
#include <typeinfo>


using namespace std;





template <typename T>
class ODList
{
public:
	class iterator;
	friend class iterator;
	class MyException
	{

	public:

		MyException(string err)
		{
			ex_mes = err;
		}

		const char* getErr()
		{

			return ex_mes.c_str();
		}

	private:
		string ex_mes;
	};



private:
	class Exam;
	friend class Exam;


	class Exam 
	{
	public:
		friend class ODList<T>;
		friend class iterator;
		class MyException
		{

		public:

			MyException(string err)
			{
				ex_mes = err;
			}

			const char* getErr()
			{

				return ex_mes.c_str();
			}

		private:
			string ex_mes;
		};


	public:
		Exam()
		{
			setMark();
			setId();
			setName();
		}

		Exam(T a) :val(a)
		{
			setId();
			setName();
		}

		Exam(T a, int b, string c) :val(a), id(b), name(c)
		{
		}


		void setName()
		{
			cout << "Input name" << endl;
			cin >> name;
		}

		void setId()
		{

			do
			{
				cout << "Input id" << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> id;
			} while (cin.fail());
		}

		void setMark()
		{

				do
				{
					do
					{
						cout << "Input mark" << endl;
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cin >> val;
					} while (cin.fail());
				} while (val < 0);

		}

		void getMark()
		{
			cout << "Mark is:" << val << endl;
		}

		void get()
		{
			cout << "Id is:" << id << endl;
			cout << "Name is:" << name << endl;
		}

		~Exam()
		{

		}

		int id;
		string name;
		T val;
		Exam* next;
	};




public:
	class iterator
	{
		friend class ODList<T>;
		class MyException
		{

		public:

			MyException(string err)
			{
				ex_mes = err;
			}

			const char* getErr()
			{

				return ex_mes.c_str();
			}

		private:
			string ex_mes;
		};


	public:
		iterator() :the_node(0) {}

		iterator(Exam* ln) : the_node(ln) {}

		iterator(const iterator& it) : the_node(it.the_node) {}

		iterator& operator=(const iterator& it)
		{
			the_node = it.the_node;
			return *this;
		}

	
		bool operator == (const iterator& it) const
		{
			return (the_node == it.the_node);
		}


		bool operator!=(const iterator& it) const
		{
			return !(it == *this);
		}

		iterator operator++(int)
		{
			if (the_node == 0)
				throw "incremented an empty iterator";
			if (the_node->next == 0)
				throw "tried to increment too far past the end";

			the_node = the_node->next;
			return *this;
		}




		T& operator*() const
		{
			if (the_node == 0)
				throw "tried to dereference an empty iterator";
			if (the_node != 0)

				the_node->get();

			return the_node->val;
		}

	private:
		Exam* the_node;
	};

private:
	Exam* head;
	Exam* tail;

	iterator head_iterator;
	iterator tail_iterator;

public:
	ODList()
	{
		head = tail = new Exam(NULL,NULL,"0");
		tail->next = nullptr;

		head_iterator = iterator(head);
		tail_iterator = iterator(tail);
	}

	ODList(T node_val)
	{
		head = tail = new Exam;
		tail->next = nullptr;

		head_iterator = iterator(head);
		tail_iterator = iterator(tail);
		add_front(node_val);
	}

	~ODList()
	{
		Exam* node_to_delete = head;
		for (Exam* cn = head; cn != tail;)
		{
			cn = cn->next;
			delete node_to_delete;
			node_to_delete = cn;
		}

		delete node_to_delete;
	}

	bool is_empty() { 	return head == tail; 	}
	

	iterator front() { return head_iterator; }
	iterator rear() { return tail_iterator; }


	bool operator == (const ODList& it) const
	{
		return (size() == it.size());
	}
	bool operator!=(const ODList& it) const
	{
		return !(it == *this);
	}

	void Shell()
	{
		try
		{
			if (is_empty())
				throw MyException("tried to sort an empty list\n");
		T count=0;
		int i = 0;
		int d = size();
		int n = d;
		d = d / 2;
		while (d > 0)
		{
			Exam* cur = head;
			Exam* last = head;
			for (i = 0; i < d; i++)
			{
				last = last->next;
			}
			for (i = 0; i < n - d; i++)
			{
				int j = i;
				while (j >= 0 && cur->val > last->val)
				{
					count = cur->val;
					cur->val = last->val;
					last->val = count;
					j--;
				}
				cur = cur->next;
				last = last->next;
			}
			d = d / 2;

			if (d == 0)
			{
				d = 1;
				Exam* cur = head;
				Exam* last = head;
				for (i = 0; i < d; i++)
				{
					last = last->next;
				}
				for (i = 0; i < n - d; i++)
				{
					int j = i;
					while (j >= 0 && cur->val > last->val)
					{
						count = cur->val;
						cur->val = last->val;
						last->val = count;
						j--;
					}
					cur = cur->next;
					last = last->next;
				}
				d = d / 2;
			}
		}
		}
		catch (MyException exception)
		{
			cerr << exception.getErr();
		}

	}


	void add_front(T node_val)
	{
		try
		{
			Exam* node_to_add = new Exam(node_val);
			if (find(node_val))
				throw MyException("tried to add an existing element\n");
			node_to_add->next = head;
			head = node_to_add;

			head_iterator = iterator(head);
		}
		catch (MyException exception)
		{
		cerr << exception.getErr();
		}
	}





	bool insert_after(T node_val, const iterator& key_i)
	{
		Exam* dn = head;
		for (Exam* prvn = head; prvn != tail; dn = prvn->next)
		{

			if (dn == key_i.the_node)
			{
				Exam* node_to_add = new Exam(node_val);
				prvn->next = dn;
				node_to_add->next = dn->next;
				dn->next = node_to_add;
				return true;
			}


		}
		return false;
	}

	T remove_front()
	{
		try
		{
			
			if (is_empty())
				throw MyException("tried to remove from an empty list\n");
			Exam* node_to_remove = head;
			T return_val = node_to_remove->val;
			head = node_to_remove->next;
			head_iterator = iterator(head);
			delete node_to_remove;
			return return_val;
		}
		catch (MyException exception)
		{
			cerr << exception.getErr();
		}

	}

	bool remove_it(iterator& key_i)					/////////////
	{
		try
		{
			if (is_empty())
				throw MyException("tried to remove from an empty list\n");
			iterator rn = iterator(head);
			for (iterator prn = iterator(head); prn != tail_iterator; rn++)
			{

				if (rn.the_node == key_i.the_node)
				{
					prn.the_node->next = rn.the_node->next;
					delete rn.the_node;
					key_i.the_node = 0;
					return true;
				}


				prn++;
			}

			return false;
		}
		catch (MyException exception)
		{
			cerr << exception.getErr();
		}

	}


	bool find(T node_val) const
	{
		for (iterator rn = iterator(head); rn != tail_iterator; rn++)
		{
			if (rn.the_node->val == node_val)
				return true;
		}
		return false;

	}


	iterator get_nth(const int element_num) const
	{
		if (element_num < 1)
			return tail_iterator;

		int count = 1;
		for (iterator rn = iterator(head); rn != tail_iterator; rn++)
		{
			if (count++ == element_num)
				return rn;
		}

		return tail_iterator;
	}


	int size() const
	{
		int count = 0;
		for (iterator rn = iterator(head); rn != tail_iterator; rn++)
		{
			++count;
		}

		return count;
	}



	void print() const
	{
		for (iterator rn=iterator(head) ; rn != tail_iterator; rn++)
		{
			rn.the_node->get();
			rn.the_node->getMark();
			cout << endl;	
		}
		cout << endl;              
	}

};

