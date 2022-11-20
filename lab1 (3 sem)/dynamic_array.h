#pragma once

template <class T>
class DynamicArray {
private:
	int size;
	int capacity;
	T* data;
public:
	DynamicArray(T* items, int count);
	DynamicArray(int size);
	DynamicArray(const DynamicArray<T>& old_version);
	DynamicArray(DynamicArray<T>&& old_version);
	~DynamicArray();

	const T& get(int index);
	int get_size();
	void set(const T& item, int index);
	void resize(int newSize);
	void remove_first();
	T& operator[](int index);

	class Iterator {
		friend class DynamicArray;
	private:
		T* some_element;
		Iterator(T* new_element);
		Iterator();
	public:
		Iterator& operator++();
		Iterator operator++(int);

		Iterator& operator--();
		Iterator operator--(int);

		bool operator!=(Iterator it);
		bool operator==(Iterator it);
		bool operator<(Iterator it);
		bool operator<=(Iterator it);

		const T& operator*();
	};

	Iterator begin();
	Iterator end();
	Iterator advance_forward(int amount);
	Iterator advance_back(int amount);
	int real_index(Iterator it);


	//QUICK SORT
	Iterator partition(Iterator beginning, Iterator ending, bool(*comparator_ascending_order)(const T&, const T&));
	void quick_sort(Iterator beginning, Iterator ending, bool(*comparator_ascending_order)(const T&, const T&));
	void quick_sort_(bool(*comparator_ascending_order)(const T&, const T&));


	//BINARY INSERTION SORT
	void binary_insertion_sort(bool(*comparator_ascending_order)(const T&, const T&));
	Iterator find_middle(Iterator beginning, Iterator ending);
	Iterator binary_search(Iterator beginning, Iterator ending, const T& key, bool(*comparator_ascending_order)(const T&, const T&));
	void binary_insertion_sort_(bool(*comparator_ascending_order)(const T&, const T&));


	//MERGE SORT
	void merge(Iterator beginning, Iterator& middle, Iterator ending, bool(*comparator_ascending_order)(const T&, const T&));
	void merge_sort(Iterator beginning, Iterator ending, bool(*comparator_ascending_order)(const T&, const T&));
	void merge_sort_(bool(*comparator_ascending_order)(const T&, const T&));
};