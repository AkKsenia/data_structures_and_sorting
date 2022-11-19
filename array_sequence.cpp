#include "array_sequence.h"
#include "library.h"

template <class T>
ArraySequence<T>::ArraySequence(T* items, int count) : dynamic_array(new DynamicArray<T>(items, count)), size(0) {};
template <class T>
ArraySequence<T>::ArraySequence() : dynamic_array(new DynamicArray<T>(size)) {};
template <class T>
ArraySequence<T>::ArraySequence(const DynamicArray<T>& old_version) : dynamic_array(new DynamicArray<T>(old_version)), size(0) {};
template <class T>
ArraySequence<T>::ArraySequence(DynamicArray<T>&& old_version) : dynamic_array(new DynamicArray<T>(old_version)), size(0) {};

template <class T>
const T& ArraySequence<T>::get_first() {
    return this->dynamic_array->get(0);
}
template <class T>
const T& ArraySequence<T>::get_last() {
    return this->dynamic_array->get(this->dynamic_array->get_size() - 1);
}
template <class T>
const T& ArraySequence<T>::get(int index) {
    return this->dynamic_array->get(index);
}
template <class T>
void ArraySequence<T>::set(const T& item, int index) {
    this->dynamic_array->set(item, index);
}
template <class T>
void ArraySequence<T>::get_subsequence(int startindex, int endindex) {
    try {
        if ((startindex < 0) || (startindex >= this->get_length()) || (endindex < 0) || (endindex >= this->get_length()) || (startindex > endindex))
            throw (-1);
        for (int i = startindex; i <= endindex; i++) {
            cout << this->dynamic_array->get(i) << ' ';
        }
        cout << endl;
    }
    catch (int index) {
        cout << "Введённые вами индексы начала и конца подпоследовательности равны " << startindex << " и " << endindex << ", в то время как общее число элементов равно " << this->get_length() << ". Операцию извлечения подпоследовательности произвести невозможно!" << endl;
        cout << "Работа функции завершилась с кодом " << index << endl;
    }
}
template <class T>
int ArraySequence<T>::get_length() {
    size = this->dynamic_array->get_size();
    return size;
}
template <class T>
void ArraySequence<T>::append(const T& item) {
    this->insert_at(item, this->get_length());
}
template <class T>
void ArraySequence<T>::prepend(const T& item) {
    this->insert_at(item, 0);
}
template <class T>
void ArraySequence<T>::insert_at(const T& item, int index) {
    int arr_size = this->get_length();
    try {
        if ((index < 0) || (index > arr_size))
            throw (index);
        T* arr = new T[arr_size + 1];
        for (int i = 0; i < index; i++)
            arr[i] = this->dynamic_array->get(i);
        arr[index] = item;
        for (int i = index; i < this->get_length(); i++)
            arr[i + 1] = this->get(i);
        this->dynamic_array->resize(arr_size + 1);
        for (int i = 0; i < this->get_length(); i++)
            this->dynamic_array->set(arr[i], i);
        ++size;
        delete[] arr;
    }
    catch (int index) {
        cout << endl;
        cout << "Введённый вами индекс равен " << index << ", в то время как общее количество элементов в последовательности - " << arr_size << ". Вставку осуществить невозможно!" << endl;
    }
}
template <class T>
void ArraySequence<T>::concat(Sequence<T>& arr) {
    int j = this->get_length();
    for (int i = 0; i < arr.get_length(); i++) {
        this->insert_at(arr.get(i), j);
        ++j;
    }
}
template <class T>
void ArraySequence<T>::remove_first() {
    int length = this->get_length();
    this->dynamic_array->remove_first();
    if (this->get_length() != length)
        --size;
}
template <class T>
void ArraySequence<T>::merge_sort_(bool(*comparator_ascending_order)(const T&, const T&)) {
    this->dynamic_array->merge_sort_(comparator_ascending_order);
}
template <class T>
void ArraySequence<T>::quick_sort_(bool(*comparator_ascending_order)(const T&, const T&)) {
    this->dynamic_array->quick_sort_(comparator_ascending_order);
}
template <class T>
void ArraySequence<T>::binary_insertion_sort_(bool(*comparator_ascending_order)(const T&, const T&)) {
    this->dynamic_array->binary_insertion_sort_(comparator_ascending_order);
}