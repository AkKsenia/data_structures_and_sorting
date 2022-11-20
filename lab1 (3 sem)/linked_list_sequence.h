#pragma once
#include "sequence.h"
#include "linked_list.h"

template <class T>
class LinkedListSequence : public Sequence<T> {
private:
    LinkedList<T>* linked_list;
public:
    LinkedListSequence(T* items, int count);
    LinkedListSequence();
    LinkedListSequence(const LinkedList<T>& old_version);
    LinkedListSequence(LinkedList<T>&& old_version);

    const T& get_first() override;
    const T& get_last() override;
    const T& get(int index) override;
    void set(const T& item, int index);
    void remove_first() override;
    void get_subsequence(int startindex, int endindex) override;
    int get_length() override;
    void append(const T& item) override;
    void prepend(const T& item) override;
    void insert_at(const T& item, int index) override;
    void concat(Sequence<T>& list) override;

    void merge_sort_(bool(*comparator_ascending_order)(const T&, const T&)) override;
    void quick_sort_(bool(*comparator_ascending_order)(const T&, const T&)) override;
    void binary_insertion_sort_(bool(*comparator_ascending_order)(const T&, const T&)) override;
};