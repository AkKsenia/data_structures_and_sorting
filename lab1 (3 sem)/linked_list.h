#pragma once

template<class T>
class Node {
public:
	T data;
	Node<T>* next;
	Node();
	Node(const T& item, Node<T>* ptr = nullptr);
};

template<class T>
class LinkedList {
public:
	Node<T>* head;
	Node<T>* tail;
public:
	LinkedList();
	LinkedList(T* items, int amount);
	LinkedList(const LinkedList<T>& old_version);
	LinkedList(LinkedList<T>&& old_version);
	~LinkedList();

	const T& get_first();
	const T& get_last();
	const T& get(int index);
	LinkedList<T>* get_sub_list(int startindex, int endindex);
	LinkedList<T>* concat(const LinkedList<T>& list);
	int get_length();
	void append(const T& item);
	void set(const T& item, int index);
	void prepend(const T& item);
	void insert_at(const T& item, int index);
	void remove_first();

	class Iterator {
		friend class LinkedList;
	private:
		Node<T>* some_node;
		Iterator(Node<T>* new_node);
		Iterator();
	public:
		Iterator& operator++();
		Iterator operator++(int);

		Iterator& operator--();
		Iterator operator--(int);

		bool operator!=(Iterator it);
		bool operator==(Iterator it);

		const T& operator*();
	};

	Iterator begin();
	Iterator end();
	Iterator advance_forward(int amount);
	Iterator advance_back(int amount);


	//MERGE SORT
	void split(Iterator head, Iterator& f, Iterator& s);
	void merge_sort(Iterator& head, bool(*comparator_ascending_order)(const T&, const T&));
	void merge_sort_(bool(*comparator_ascending_order)(const T&, const T&));
	Iterator merge(Iterator f, Iterator s, bool(*comparator_ascending_order)(const T&, const T&));


	//QUICK SORT
	Iterator partition(Iterator head, Iterator tail, bool(*comparator_ascending_order)(const T&, const T&));
	void quick_sort(Iterator head, Iterator tail, bool(*comparator_ascending_order)(const T&, const T&));
	void quick_sort_(bool(*comparator_ascending_order)(const T&, const T&));


	//BINARY INSERTION SORT
	Iterator find_middle(Iterator head, Iterator tail);
	Iterator binary_search(Iterator head, Iterator tail, const T& key, bool(*comparator_ascending_order)(const T&, const T&));
	Iterator previous(Iterator some_node);
	void binary_insertion_sort_(bool(*comparator_ascending_order)(const T&, const T&));
};