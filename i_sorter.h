#pragma once
#include "sequence.h"

template <class T>
class ISorter {
public:
    void quick_sort(Sequence<T>* seq, bool(*comparator_ascending_order)(const T&, const T&));
    void binary_insertion_sort(Sequence<T>* seq, bool(*comparator_ascending_order)(const T&, const T&));
    void merge_sort(Sequence<T>* seq, bool(*comparator_ascending_order)(const T&, const T&));
    void message_before(Sequence<T>* seq);
    void message_after(Sequence<T>* seq);
};