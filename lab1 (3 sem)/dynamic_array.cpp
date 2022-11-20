#include "library.h"
#include "dynamic_array.h"

template<class T>
DynamicArray<T>::DynamicArray(T* items, int count) {
	size = count;
	capacity = size;
	if (size != 0) {
		data = new T[count];
		for (int i = 0; i < count; i++)
			data[i] = items[i];
	}
	else
		data = nullptr;
}
template<class T>
DynamicArray<T>::DynamicArray(int size) {
	this->size = size;
	capacity = size;
	if (size != 0)
		data = new T[size];
	else
		data = nullptr;
}
template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& old_version) {
	size = old_version.size;
	capacity = old_version.capacity;
	data = old_version.data;
}
template<class T>
DynamicArray<T>::DynamicArray(DynamicArray<T>&& old_version) {
	size = old_version.size;
	capacity = old_version.capacity;
	data = std::move(old_version.data);
	old_version.data = nullptr;
	old_version.size = old_version.capacity = 0;
}
template<class T>
DynamicArray<T>::~DynamicArray() {
	delete[] data;
}

template<class T>
const T& DynamicArray<T>::get(int index) {
	try {
		if ((index > size - 1) || (index < 0))
			throw (index);
		return data[index];
	}
	catch (int index) {
		cout << "Введённый вами индекс равен " << index << ", в то время как общее количество элементов в последовательности - " << size << ". Получение элемента осуществить невозможно!" << endl;
		cout << "Работа функции завершилась с кодом ";
		return -1;
	}
}
template<class T>
int DynamicArray<T>::get_size() {
	return size;
}
template<class T>
void DynamicArray<T>::set(const T& item, int index) {
	try {
		if ((index > size - 1) || (index < 0))
			throw (index);
		data[index] = item;
	}
	catch (int index) {
		cout << "Введённый вами индекс равен " << index << ", в то время как общее количество элементов в последовательности - " << size << ". Установку " << item << " на место " << index << " осуществить невозможно!" << endl;
		cout << endl;
	}
}
template<class T>
void DynamicArray<T>::resize(int newSize) {
	if (newSize > capacity) {
		int new_capacity = newSize;
		T* new_data = new T[newSize];
		for (int i = 0; i < size; ++i)
			new_data[i] = data[i];
		data = new_data;
		capacity = new_capacity;
		delete[] new_data;
	}
	size = newSize;
}
template<class T>
void DynamicArray<T>::remove_first() {
	try {
		if (data == nullptr)
			throw (0);
		int size = this->get_size();
		T* new_data = new T[size - 1];
		for (int i = 1; i < size; i++)
			new_data[i - 1] = data[i];
		this->resize(size - 1);
		for (int i = 0; i < size - 1; i++)
			data[i] = new_data[i];
		delete[] new_data;
	}
	catch (int number) {
		cout << "Первый элемент удалить невозможно, поскольку длина последовательности, равна " << number << endl;
	}
}
template<class T>
T& DynamicArray<T>::operator[](int index) {
	return data[index];
}

template<class T>
DynamicArray<T>::Iterator::Iterator(T* new_element) : some_element(new_element) {};
template<class T>
DynamicArray<T>::Iterator::Iterator() : some_element(nullptr) {};

template<class T>
typename DynamicArray<T>::Iterator& DynamicArray<T>::Iterator::operator++() {
	++some_element;
	return (*this);
}
template<class T>
typename DynamicArray<T>::Iterator DynamicArray<T>::Iterator::operator++(int) {
	Iterator result = *this;
	++(*this);
	return result;
}

template<class T>
typename DynamicArray<T>::Iterator& DynamicArray<T>::Iterator::operator--() {
	--some_element;
	return (*this);
}
template<class T>
typename DynamicArray<T>::Iterator DynamicArray<T>::Iterator::operator--(int) {
	Iterator result = *this;
	--(*this);
	return result;
}

template<class T>
bool DynamicArray<T>::Iterator::operator!=(Iterator it) {
	return (some_element != it.some_element);
}
template<class T>
bool DynamicArray<T>::Iterator::operator==(Iterator it) {
	return (some_element == it.some_element);
}
template<class T>
bool DynamicArray<T>::Iterator::operator<(Iterator it) {
	return (some_element < it.some_element);
}
template<class T>
bool DynamicArray<T>::Iterator::operator<=(Iterator it) {
	return (some_element <= it.some_element);
}

template<class T>
const T& DynamicArray<T>::Iterator::operator*() {
	return *(some_element);
}

template<class T>
typename DynamicArray<T>::Iterator DynamicArray<T>::begin() {
	return Iterator(data);
}
template<class T>
typename DynamicArray<T>::Iterator DynamicArray<T>::end() {
	return Iterator(data + size - 1);
}
template<class T>
typename DynamicArray<T>::Iterator DynamicArray<T>::advance_forward(int amount) {
	Iterator result = *this;
	for (int i = 0; i < amount; i++)
		++(*this);
	return result;
}
template<class T>
typename DynamicArray<T>::Iterator DynamicArray<T>::advance_back(int amount) {
	Iterator result = *this;
	for (int i = 0; i < amount; i++)
		--(*this);
	return result;
}
template<class T>
int DynamicArray<T>::real_index(Iterator it) {
	int counter = 0;
	for (Iterator ptr = data; ptr <= end(); ++ptr) {
		if (ptr == it)
			return counter - 1;
		++counter;
	}
	return -1;
}

//QUICK SORT
template<class T>
typename DynamicArray<T>::Iterator DynamicArray<T>::partition(Iterator beginning, Iterator ending, bool(*comparator_ascending_order)(const T&, const T&)) {
	T pivot = ending.operator*();
	Iterator i = beginning;
	--i;
	while (beginning < ending) {
		if (comparator_ascending_order(beginning.operator*(), pivot)) {
			++i;
			T tmp = i.operator*();
			*(i.some_element) = beginning.operator*();
			*(beginning.some_element) = tmp;
		}
		++beginning;
	}
	Iterator i_plus_one = i;
	++i_plus_one;
	T tmp = i_plus_one.operator*();
	*(i_plus_one.some_element) = pivot;
	*(ending.some_element) = tmp;
	return i_plus_one;
}
template<class T>
void DynamicArray<T>::quick_sort(Iterator beginning, Iterator ending, bool(*comparator_ascending_order)(const T&, const T&)) {
	if (beginning < ending) {
		Iterator index = partition(beginning, ending, comparator_ascending_order);
		Iterator ind_prev = index, ind_post = index;
		--ind_prev;
		++ind_post;
		quick_sort(beginning, ind_prev, comparator_ascending_order);
		quick_sort(ind_post, ending, comparator_ascending_order);
	}
}
template<class T>
void DynamicArray<T>::quick_sort_(bool(*comparator_ascending_order)(const T&, const T&)) {
	quick_sort(begin(), end(), comparator_ascending_order);
}


//BINARY INSERTION SORT
template<class T>
void DynamicArray<T>::binary_insertion_sort(bool(*comparator_ascending_order)(const T&, const T&)) {
	Iterator j = nullptr, location = nullptr, i = begin(), j_tmp = nullptr, tmp = nullptr;
	T key;
	++i;
	for (; i <= end(); ++i) {
		j = i;
		--j;
		key = i.operator*();
		location = binary_search(begin(), j, key, comparator_ascending_order);
		while (location <= j) {
			j_tmp = j;
			++j_tmp;
			*(j_tmp.some_element) = j.operator*();
			--j;
		}
		j_tmp = j;
		++j_tmp;
		*(j_tmp.some_element) = key;
	}
}
template<class T>
typename DynamicArray<T>::Iterator DynamicArray<T>::find_middle(Iterator beginning, Iterator ending) {
	if (beginning == nullptr)
		return nullptr;
	Iterator slow = beginning, fast = beginning;
	++fast;
	if (beginning == ending)
		return ending;
	while (fast != ending) {
		++fast;
		if (fast != ending) {
			++slow;
			++fast;
		}
		else ++slow;
	}
	return slow;
}
template<class T>
typename DynamicArray<T>::Iterator DynamicArray<T>::binary_search(Iterator beginning, Iterator ending, const T& key, bool(*comparator_ascending_order)(const T&, const T&)) {
	Iterator tmp = nullptr;
	while (beginning <= ending) {
		Iterator middle = find_middle(beginning, ending);
		if (key == middle.operator*())
			return middle;
		else if (comparator_ascending_order(middle.operator*(), key)) {
			tmp = middle;
			++tmp;
			beginning = tmp;
		}
		else {
			tmp = middle;
			--tmp;
			ending = tmp;
		}
	}
	return beginning;
}
template<class T>
void DynamicArray<T>::binary_insertion_sort_(bool(*comparator_ascending_order)(const T&, const T&)) {
	binary_insertion_sort(comparator_ascending_order);
}


//MERGE SORT
template<class T>
void DynamicArray<T>::merge(Iterator beginning, Iterator& middle, Iterator ending, bool(*comparator_ascending_order)(const T&, const T&)) {
	Iterator middle_plus_1 = middle;
	int real = real_index(middle);
	++middle_plus_1;
	Iterator length_of_first_subarray = middle;
	Iterator length_of_second_subarray = ending;
	Iterator index_of_first_subarray = beginning, index_of_second_subarray = middle_plus_1;
	int index_of_merged_array = 0;
	T* merged_array = new T[real_index(ending) + 1];

	while ((index_of_first_subarray <= length_of_first_subarray) && (index_of_second_subarray <= length_of_second_subarray)) {
		if (comparator_ascending_order(index_of_second_subarray.operator*(), index_of_first_subarray.operator*())) {
			*(merged_array + index_of_merged_array) = index_of_second_subarray.operator*();
			++index_of_second_subarray;
		}
		else {
			*(merged_array + index_of_merged_array) = index_of_first_subarray.operator*();
			++index_of_first_subarray;
		}
		++index_of_merged_array;
	}
	while (index_of_first_subarray <= length_of_first_subarray) {
		*(merged_array + index_of_merged_array) = index_of_first_subarray.operator*();
		++index_of_first_subarray;
		++index_of_merged_array;
	}
	while (index_of_second_subarray <= length_of_second_subarray) {
		*(merged_array + index_of_merged_array) = index_of_second_subarray.operator*();
		++index_of_second_subarray;
		++index_of_merged_array;
	}
	int counter = 0;
	for (Iterator ptr = beginning; ptr <= ending; ++ptr) {
		*(ptr.some_element) = *(merged_array + counter);
		++counter;
	}
}
template<class T>
void DynamicArray<T>::merge_sort(Iterator beginning, Iterator ending, bool(*comparator_ascending_order)(const T&, const T&)) {
	if (beginning < ending) {
		Iterator middle = find_middle(beginning, ending);
		Iterator tmp = middle;
		++tmp;
		merge_sort(beginning, middle, comparator_ascending_order);
		merge_sort(tmp, ending, comparator_ascending_order);
		merge(beginning, middle, ending, comparator_ascending_order);
	}
}
template<class T>
void DynamicArray<T>::merge_sort_(bool(*comparator_ascending_order)(const T&, const T&)) {
	merge_sort(begin(), end(), comparator_ascending_order);
}