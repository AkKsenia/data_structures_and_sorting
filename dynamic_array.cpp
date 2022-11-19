#include "library.h"
#include "dynamic_array.h"


template <class T>
class DynamicArray {
private:
	int size_of_array;
	int capacity_of_array;
	T* data_of_array;
public:
	DynamicArray(T* items, int count) {
		size_of_array = count;
		capacity_of_array = size_of_array;
		if (size_of_array != 0) {
			data_of_array = new T[count];
			for (int i = 0; i < count; i++)
				data_of_array[i] = items[i];
		}
		else
			data_of_array = nullptr;
	}
	DynamicArray(int size) {
		size_of_array = size;
		capacity_of_array = size_of_array;
		if (size_of_array != 0)
			data_of_array = new T[size];
		else
			data_of_array = nullptr;
	}
	DynamicArray(const DynamicArray<T>& old_version) {
		size_of_array = old_version.size_of_array;
		capacity_of_array = old_version.capacity_of_array;
		data_of_array = old_version.data_of_array;
	}
	DynamicArray(DynamicArray<T>&& old_version) {
		size_of_array = old_version.size_of_array;
		capacity_of_array = old_version.capacity_of_array;
		data_of_array = std::move(old_version.data_of_array);
		old_version.data_of_array = nullptr;
		old_version.size_of_array = old_version.capacity_of_array = 0;
	}

	const T& get(int index) {
		try {
			if ((index > size_of_array - 1) || (index < 0))
				throw (index);
			return data_of_array[index];
		}
		catch (int index) {
			cout << "Введённый вами индекс равен " << index << ", в то время как общее количество элементов в последовательности - " << size_of_array << ". Получение элемента осуществить невозможно!" << endl;
			cout << "Работа функции завершилась с кодом ";
			return -1;
		}
	}
	int get_size() {
		return size_of_array;
	}
	void set(const T& item, int index) {
		try {
			if ((index > size_of_array - 1) || (index < 0))
				throw (index);
			data_of_array[index] = item;
		}
		catch (int index) {
			cout << "Введённый вами индекс равен " << index << ", в то время как общее количество элементов в последовательности - " << size_of_array << ". Установку " << item << " на место " << index << " осуществить невозможно!" << endl;
			cout << endl;
		}
	}
	void resize(int newSize) {
		if (newSize > capacity_of_array) {
			int new_capacity = newSize;
			T* new_data = new T[newSize];
			for (int i = 0; i < size_of_array; ++i)
				new_data[i] = data_of_array[i];
			data_of_array = new_data;
			capacity_of_array = new_capacity;
			delete[] new_data;
		}
		size_of_array = newSize;
	}
	void remove_first() {
		try {
			if (data_of_array == nullptr)
				throw (0);
			int size = this->get_size();
			T* new_data = new T[size - 1];
			for (int i = 1; i < size; i++)
				new_data[i - 1] = data_of_array[i];
			this->resize(size - 1);
			for (int i = 0; i < size - 1; i++)
				data_of_array[i] = new_data[i];
			delete[] new_data;
		}
		catch (int number) {
			cout << "Первый элемент удалить невозможно, поскольку длина последовательности, равна " << number << endl;
		}
	}
	T& operator[](int index) {
		return data_of_array[index];
	}

	class Iterator_for_array {
		friend class DynamicArray;
	private:
		T* some_element;
		Iterator_for_array(T* new_element) : some_element(new_element) {};
		Iterator_for_array() : some_element(nullptr) {};
	public:
		Iterator_for_array& operator++() {
			some_element = some_element + 1;
			return (*this);
		}
		Iterator_for_array operator++(int) {
			Iterator_for_array result = *this;
			++(*this);
			return result;
		}

		Iterator_for_array& operator--() {
			some_element = some_element - 1;
			return (*this);
		}
		Iterator_for_array operator--(int) {
			Iterator_for_array result = *this;
			--(*this);
			return result;
		}

		bool operator!=(Iterator_for_array it) {
			return (some_element != it.some_element);
		}
		bool operator==(Iterator_for_array it) {
			return (some_element == it.some_element);
		}
		bool operator<(Iterator_for_array it) {
			return (some_element < it.some_element);
		}
		bool operator<=(Iterator_for_array it) {
			return (some_element <= it.some_element);
		}

		const T& operator*() {
			return *(some_element);
		}
	};

	Iterator_for_array begin() {
		return Iterator_for_array(data_of_array + 0);
	}
	Iterator_for_array end() {
		return Iterator_for_array(data_of_array + size_of_array - 1);
	}
	Iterator_for_array advance_forward(int amount) {
		Iterator_for_array result = *this;
		for (int i = 0; i < amount; i++)
			++(*this);
		return result;
	}
	Iterator_for_array advance_back(int amount) {
		Iterator_for_array result = *this;
		for (int i = 0; i < amount; i++)
			--(*this);
		return result;
	}
	int real_index(Iterator_for_array it) {
		int counter = 0;
		for (Iterator_for_array ptr = data_of_array; ptr <= end(); ++ptr) {
			if (ptr == it)
				return counter - 1;
			++counter;
		}
		return -1;
	}


	//QUICK SORT
	Iterator_for_array partition(Iterator_for_array beginning, Iterator_for_array ending, bool(*comparator_ascending_order)(const T&, const T&)) {
		T pivot = ending.operator*();
		Iterator_for_array i = beginning;
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
		Iterator_for_array i_plus_one = i;
		++i_plus_one;
		T tmp = i_plus_one.operator*();
		*(i_plus_one.some_element) = pivot;
		*(ending.some_element) = tmp;
		return i_plus_one;
	}
	void quick_sort(Iterator_for_array beginning, Iterator_for_array ending, bool(*comparator_ascending_order)(const T&, const T&)) {
		if (beginning < ending) {
			Iterator_for_array index = partition(beginning, ending, comparator_ascending_order);
			Iterator_for_array ind_prev = index, ind_post = index;
			--ind_prev;
			++ind_post;
			quick_sort(beginning, ind_prev, comparator_ascending_order);
			quick_sort(ind_post, ending, comparator_ascending_order);
		}
	}
	void quick_sort_(bool(*comparator_ascending_order)(const T&, const T&)) {
		quick_sort(begin(), end(), comparator_ascending_order);
	}


	//BINARY INSERTION SORT
	void binary_insertion_sort(bool(*comparator_ascending_order)(const T&, const T&)) {
		Iterator_for_array j = nullptr, location = nullptr, i = begin(), j_tmp = nullptr, tmp = nullptr;
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
	Iterator_for_array find_middle(Iterator_for_array beginning, Iterator_for_array ending) {
		if (beginning == nullptr)
			return nullptr;
		Iterator_for_array slow = beginning, fast = beginning;
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
	Iterator_for_array binary_search(Iterator_for_array beginning, Iterator_for_array ending, const T& key, bool(*comparator_ascending_order)(const T&, const T&)) {
		Iterator_for_array tmp = nullptr;
		while (beginning <= ending) {
			Iterator_for_array middle = find_middle(beginning, ending);
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
	void binary_insertion_sort_(bool(*comparator_ascending_order)(const T&, const T&)) {
		binary_insertion_sort(comparator_ascending_order);
	}


	//MERGE SORT
	void merge(Iterator_for_array beginning, Iterator_for_array& middle, Iterator_for_array ending, bool(*comparator_ascending_order)(const T&, const T&)) {
		Iterator_for_array middle_plus_1 = middle;
		int real = real_index(middle);
		++middle_plus_1;
		Iterator_for_array length_of_first_subarray = middle;
		Iterator_for_array length_of_second_subarray = ending;
		Iterator_for_array index_of_first_subarray = beginning, index_of_second_subarray = middle_plus_1;
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
		for (Iterator_for_array ptr = beginning; ptr <= ending; ++ptr) {
			*(ptr.some_element) = *(merged_array + counter);
			++counter;
		}
	}
	void merge_sort(Iterator_for_array beginning, Iterator_for_array ending, bool(*comparator_ascending_order)(const T&, const T&)) {
		if (beginning < ending) {
			Iterator_for_array middle = find_middle(beginning, ending);
			Iterator_for_array tmp = middle;
			++tmp;
			merge_sort(beginning, middle, comparator_ascending_order);
			merge_sort(tmp, ending, comparator_ascending_order);
			merge(beginning, middle, ending, comparator_ascending_order);
		}
	}
	void merge_sort_(bool(*comparator_ascending_order)(const T&, const T&)) {
		merge_sort(begin(), end(), comparator_ascending_order);
	}
};