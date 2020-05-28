#pragma once
#include <iostream>
#include <vector>
using namespace std;


template <typename T, typename U>
class Iterator {
public:
	typedef typename std::vector<T>::iterator iter_type;
	Iterator(U* p_data, bool reverse = false) : m_p_data_(p_data) {
		m_it_ = m_p_data_->m_data_.begin();
	}

	void First() {
		m_it_ = m_p_data_->m_data_.begin();
	}

	void Next() {
		m_it_++;
	}

	bool IsDone() {
		return (m_it_ == m_p_data_->m_data_.end());
	}

	iter_type Current() {
		return m_it_;
	}

private:
	U* m_p_data_;
	iter_type m_it_;
};



template <class T>
class Container {
	friend class Iterator<T, Container>;

public:
	void Add(T a) {
		m_data_.push_back(a);
	}

	Iterator<T, Container>* CreateIterator() {
		return new Iterator<T, Container>(this);
	}

private:
	std::vector<T> m_data_;
};

class Data {
public:
	Data(int a = 0) : m_data_(a) {}

	void set_data(int a) {
		m_data_ = a;
	}

	int data() {
		return m_data_;
	}

private:
	int m_data_;
};



template<typename T>
class List
{
public:
	List();
	~List();
	// видалення першого елемента в списку
	void pop_front();

	// додавання елемента в кінець списку
	void push_back(T data);

	// очистити список
	void clear();

	// отримати кількість елементів у списку
	int GetSize() { return Size; }

	// перевантажений оператор []
	T& operator [] (const int index);

	// додавання елемента в початок списку
	void push_front(T data);

	// додавання елемента в список за вказаним індексом
	void insert(T data, int index);

	// видалення елемента в списку за вказаним індексом
	void removeAt(int index);

	// видалення останнього елемента в списку
	void pop_back();

private:


	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T>* head;
};


template<typename T>
List<T>::List()
{
	Size = 0;
	head = nullptr;
}


template<typename T>
List<T>::~List()
{
	clear();
}


template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;

	head = head->pNext;


	Size--;

}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);

	}

	Size++;
}

template<typename T>
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}


template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;

	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>
void List<T>::insert(T data, int index)
{

	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* newNode = new Node<T>(data, previous->pNext);

		previous->pNext = newNode;

		Size++;
	}





}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}


		Node<T>* toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}

}

template<typename T>
void List<T>::pop_back()
{
	removeAt(Size - 1);
}
