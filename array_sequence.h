#pragma once
#include "sequence.h"
#include "dynamic_array.h"

template <class T>
class ArraySequence : public Sequence<T> {
private:
    DynamicArray<T>* dynamic_array;
    int size;
public:
    ArraySequence(T* items, int count);
    ArraySequence();
    ArraySequence(const DynamicArray<T>& old_version);
    ArraySequence(DynamicArray<T>&& old_version);
    const T& get_first() override;
    const T& get_last() override;
    const T& get(int index) override;
    void set(const T& item, int index) override;
    void remove_first() override;
    void get_subsequence(int startindex, int endindex) override;
    int get_length() override;
    void append(const T& item) override;
    void prepend(const T& item) override;
    void insert_at(const T& item, int index) override;
    void concat(Sequence<T>& arr) override;
    void merge_sort_(bool(*comparator_ascending_order)(const T&, const T&)) override;
    void quick_sort_(bool(*comparator_ascending_order)(const T&, const T&)) override;
    void binary_insertion_sort_(bool(*comparator_ascending_order)(const T&, const T&)) override;
};