#include "library.h"
#include "linked_list_sequence.h"

template <class T>
LinkedListSequence<T>::LinkedListSequence(T* items, int count) : linked_list(new LinkedList<T>(items, count)) {};
template <class T>
LinkedListSequence<T>::LinkedListSequence() : linked_list(new LinkedList<T>) {};
template <class T>
LinkedListSequence<T>::LinkedListSequence(const LinkedList<T>& old_version) : linked_list(new LinkedList<T>(old_version)) {};
template <class T>
LinkedListSequence<T>::LinkedListSequence(LinkedList<T>&& old_version) : linked_list(new LinkedList<T>(old_version)) {};

template <class T>
const T& LinkedListSequence<T>::get_first() {
    return this->linked_list->get_first();
}
template <class T>
const T& LinkedListSequence<T>::get_last() {
    return this->linked_list->get_last();
}
template <class T>
const T& LinkedListSequence<T>::get(int index) {
    return this->linked_list->get(index);
}
template <class T>
void LinkedListSequence<T>::set(const T& item, int index) {
    this->linked_list->set(item, index);
}
template <class T>
void LinkedListSequence<T>::remove_first() {
    this->linked_list->remove_first();
}
template <class T>
void LinkedListSequence<T>::get_subsequence(int startindex, int endindex) {
    try {
        if ((startindex < 0) || (startindex >= this->linked_list->get_length()) || (endindex < 0) || (endindex >= this->linked_list->get_length()) || (startindex > endindex))
            throw (-1);
        for (int i = startindex; i <= endindex; i++) {
            cout << this->linked_list->get(i) << ' ';
        }
        cout << endl;
    }
    catch (int index) {
        cout << "Введённые вами индексы начала и конца подпоследовательности равны " << startindex << " и " << endindex << ", в то время как общее число элементов равно " << this->linked_list->get_length() << ". Операцию извлечения подпоследовательности произвести невозможно!" << endl;
        cout << "Работа функции завершилась с кодом " << index << endl;
    }
}
template <class T>
int LinkedListSequence<T>::get_length() {
    return this->linked_list->get_length();
}
template <class T>
void LinkedListSequence<T>::append(const T& item) {
    this->linked_list->append(item);
}
template <class T>
void LinkedListSequence<T>::prepend(const T& item) {
    this->linked_list->prepend(item);
}
template <class T>
void LinkedListSequence<T>::insert_at(const T& item, int index) {
    this->linked_list->insert_at(item, index);
}
template <class T>
void LinkedListSequence<T>::concat(Sequence<T>& list) {
    int j = this->get_length();
    for (int i = 0; i < list.get_length(); i++) {
        this->insert_at(list.get(i), j);
        ++j;
    }
}
template <class T>
void LinkedListSequence<T>::merge_sort_(bool(*comparator_ascending_order)(const T&, const T&)) {
    this->linked_list->merge_sort_(comparator_ascending_order);
}
template <class T>
void LinkedListSequence<T>::quick_sort_(bool(*comparator_ascending_order)(const T&, const T&)) {
    this->linked_list->quick_sort_(comparator_ascending_order);
}
template <class T>
void LinkedListSequence<T>::binary_insertion_sort_(bool(*comparator_ascending_order)(const T&, const T&)) {
    this->linked_list->binary_insertion_sort_(comparator_ascending_order);
}