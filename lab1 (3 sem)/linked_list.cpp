#include "library.h"
#include "linked_list.h"

template<class T>
Node<T>::Node() : data(0), next(nullptr) {}
template<class T>
Node<T>::Node(const T& item, Node<T>* ptr) : data(item), next(ptr) {}

template<class T>
LinkedList<T>::LinkedList() {
	head = nullptr;
	tail = nullptr;
}
template<class T>
LinkedList<T>::LinkedList(T* items, int amount) {
	if (amount == 0) {
		head = nullptr;
		tail = nullptr;
	}
	else {
		Node<T>* current = new Node<T>;
		head = current;
		for (int i = 0; i < amount; i++) {
			current->data = items[i];
			tail = current;
			if (i != amount - 1) {
				Node<T>* new_node = new Node<T>;
				current->next = new_node;
				current = current->next;
			}
		}
	}
}
template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& old_version) {
	int kol_vo = 0;
	Node<T>* cur_node = old_version.head;
	if (cur_node != nullptr) {
		while (cur_node->next != nullptr) {
			++kol_vo;
			cur_node = cur_node->next;
		}
		++kol_vo;
		Node<T>* node1 = new Node<T>;
		Node<T>* old_node = old_version.head;
		node1->data = old_node->data;
		old_node = old_node->next;
		if (kol_vo == 1) {
			node1->next = nullptr;
			head = node1;
			tail = node1;
		}
		else {
			node1->next = old_node;
			head = node1;
			node1 = node1->next;
			for (int i = 1; i < kol_vo - 1; ++i) {
				node1->data = old_node->data;
				old_node = old_node->next;
				node1->next = old_node;
				node1 = node1->next;
			}
			node1->data = old_node->data;
			node1->next = nullptr;
			tail = node1;
		}
	}
	else {
		head = nullptr;
		tail = nullptr;
	}
}
template<class T>
LinkedList<T>::LinkedList(LinkedList<T>&& old_version) {
	int kol_vo = 0;
	Node<T>* cur_node = old_version.head;
	if (cur_node != nullptr) {
		while (cur_node->next != nullptr) {
			++kol_vo;
			cur_node = cur_node->next;
		}
		++kol_vo;
		Node<T>* node1 = new Node<T>;
		Node<T>* old_node = old_version.head;
		node1->data = old_node->data;
		old_node = old_node->next;
		if (kol_vo == 1) {
			node1->next = nullptr;
			head = node1;
			tail = node1;
		}
		else {
			node1->next = old_node;
			head = node1;
			node1 = node1->next;
			for (int i = 1; i < kol_vo - 1; ++i) {
				node1->data = old_node->data;
				old_node = old_node->next;
				node1->next = old_node;
				node1 = node1->next;
			}
			node1->data = old_node->data;
			node1->next = nullptr;
			tail = node1;
		}
	}
	else {
		head = nullptr;
		tail = nullptr;
	}
	old_version.head = nullptr;
}
template<class T>
LinkedList<T>::~LinkedList() {
	Node<T>* current = head;
	while (current) {
		Node<T>* for_deleting = current;
		current = current->next;
		delete for_deleting;
	}
}

template<class T>
const T& LinkedList<T>::get_first() {//может выбрасывать исключение IndexOutOfRange
	Node<T>* current = head;
	try {
		if (current == nullptr)
			throw (0);
		return current->data;
	}
	catch (int number) {
		cout << "Первый элемент получить невозможно, поскольку длина последовательности, равна ";
		return number;
	}
}
template<class T>
const T& LinkedList<T>::get_last() {//может выбрасывать исключение IndexOutOfRange
	Node<T>* current = head;
	try {
		if (current == nullptr)
			throw (0);
		while (current->next != nullptr) {
			current = current->next;
		}
		return current->data;
	}
	catch (int number) {
		cout << "Последний элемент получить невозможно, поскольку длина последовательности, равна ";
		return number;
	}
}
template<class T>
const T& LinkedList<T>::get(int index) {//может выбрасывать исключение IndexOutOfRange
	Node<T>* current = head;
	Node<T>* current1 = head;
	int kol_vo = 0, k = 0;
	while (current != nullptr) {
		current = current->next;
		++kol_vo;
	}
	try {
		if ((index < 0) || (index > kol_vo - 1))
			throw (index);
		while (k != index) {
			current1 = current1->next;
			++k;
		}
		return current1->data;
	}
	catch (int index) {
		cout << "Введённый вами индекс равен " << index << ", в то время как общее количество элементов в последовательности - " << kol_vo << ". Получение элемента осуществить невозможно!" << endl;
		cout << "Работа функции завершилась с кодом ";
		return -1;
	}
}
template<class T>
LinkedList<T>* LinkedList<T>::get_sub_list(int startindex, int endindex) {//может выбрасывать исключение IndexOutOfRange
	Node<T>* node = head;
	int kol_vo = 0;
	while (node != nullptr) {
		node = node->next;
		++kol_vo;
	}
	try {
		LinkedList<T>* list = new LinkedList<T>();
		if ((startindex < 0) || (startindex >= kol_vo) || (endindex < 0) || (endindex >= kol_vo) || (startindex > endindex))
			throw (list);
		Node<T>* current = head;
		int k = 0;
		while (k != startindex) {
			current = current->next;
			++k;
		}
		for (k; k <= endindex; k++) {
			list->append(current->data);
			current = current->next;
		}
		return list;
	}
	catch (LinkedList<T>* list) {
		cout << "Введённые вами индексы начала и конца подпоследовательности равны " << startindex << " и " << endindex << ", в то время как общее число элементов равно " << kol_vo << ". Операцию извлечения подпоследовательности произвести невозможно!" << endl;
		return list;
	}
}
template<class T>
LinkedList<T>* LinkedList<T>::concat(const LinkedList<T>& list) {
	LinkedList<T>* concat_list = new LinkedList<T>();
	Node<T>* node1 = head;
	Node<T>* node2 = list.head;
	while (node1 != nullptr)
	{
		concat_list->append(node1->data);
		node1 = node1->next;
	}
	while (node2 != nullptr)
	{
		concat_list->append(node2->data);
		node2 = node2->next;
	}
	return concat_list;
}
template<class T>
int LinkedList<T>::get_length() {
	int kol_vo = 0;
	Node<T>* current = head;
	while (current != nullptr) {
		++kol_vo;
		current = current->next;
	}
	return kol_vo;
}
template<class T>
void LinkedList<T>::append(const T& item) {
	Node<T>* new_node = new Node<T>;
	new_node->data = item;
	new_node->next = nullptr;
	Node<T>* current = head;
	if (current != nullptr) {
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = new_node;
		tail = new_node;
	}
	else {
		head = new_node;
		tail = new_node;
	}
}
template<class T>
void LinkedList<T>::set(const T& item, int index) {
	Node<T>* current = head;
	Node<T>* current1 = head;
	int kol_vo = 0, k = 0;
	while (current != nullptr) {
		current = current->next;
		++kol_vo;
	}
	try {
		if ((index < 0) || (index > kol_vo - 1))
			throw (index);
		while (current1 != nullptr) {
			if (k == index) {
				current1->data = item;
				return;
			}
			else {
				++k;
				current1 = current1->next;
			}
		}
	}
	catch (int index) {
		cout << "Введённый вами индекс равен " << index << ", в то время как общее количество элементов в последовательности - " << kol_vo << ". Установку " << item << " на место " << index << " осуществить невозможно!" << endl;
		cout << endl;
	}
}
template<class T>
void LinkedList<T>::prepend(const T& item) {
	Node<T>* new_node = new Node<T>;
	new_node->data = item;
	new_node->next = head;
	if (head == nullptr) {
		head = new_node;
		tail = new_node;
	}
	else head = new_node;
}
template<class T>
void LinkedList<T>::insert_at(const T& item, int index) {//может выбрасывать исключение IndexOutOfRange
	Node<T>* node = head;
	int kol_vo = 0;
	while (node != nullptr) {
		node = node->next;
		++kol_vo;
	}
	try {
		if ((index < 0) || (index > kol_vo))
			throw (index);
		Node<T>* new_node = new Node<T>;
		new_node->data = item;
		new_node->next = nullptr;
		Node<T>* current = head;
		Node<T>* current1 = nullptr;
		int k = 0;
		if ((index > 0) && (index != kol_vo)) {
			while (k != index - 1) {
				current = current->next;
				++k;
			}
			current1 = current->next;
			current->next = new_node;
			current = current->next;
			current->next = current1;
		}
		int k1 = 0;
		if ((index == kol_vo) && (kol_vo != 0)) {
			while (k1 != index - 1) {
				current = current->next;
				++k1;
			}
			current1 = current->next;
			current->next = new_node;
			current = current->next;
			current->next = current1;
			tail = current;
		}
		if (index == 0) {
			new_node->next = head;
			if (head == nullptr) {
				head = new_node;
				tail = new_node;
			}
			else head = new_node;
		}
	}
	catch (int index) {
		cout << endl;
		cout << "Введённый вами индекс равен " << index << ", в то время как общее количество элементов в последовательности - " << kol_vo << ". Вставку осуществить невозможно!" << endl;
	}
}
template<class T>
void LinkedList<T>::remove_first() {//может выбрасывать исключение IndexOutOfRange
	Node<T>* current = head;
	try {
		if (current != nullptr) {
			if (current->next == nullptr) {
				head = head->next;
				tail = tail->next;
			}
			else head = head->next;
			delete current;
		}
		else
			throw (0);
	}
	catch (int number) {
		cout << "Первый элемент удалить невозможно, поскольку длина последовательности, равна " << number << endl;
	}
}

template<class T>
LinkedList<T>::Iterator::Iterator(Node<T>* new_node) : some_node(new_node) {};
template<class T>
LinkedList<T>::Iterator::Iterator() : some_node(nullptr) {};

template<class T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator++() {
	some_node = some_node->next;
	return (*this);
}
template<class T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator++(int) {
	Iterator result = *this;
	++(*this);
	return result;
}

template<class T>
typename LinkedList<T>::Iterator& LinkedList<T>::Iterator::operator--() {
	some_node = previous(some_node);
	return (*this);
}
template<class T>
typename LinkedList<T>::Iterator LinkedList<T>::Iterator::operator--(int) {
	Iterator result = *this;
	--(*this);
	return result;
}

template<class T>
bool LinkedList<T>::Iterator::operator!=(Iterator it) {
	return (some_node != it.some_node);
}
template<class T>
bool LinkedList<T>::Iterator::operator==(Iterator it) {
	return (some_node == it.some_node);
}

template<class T>
const T& LinkedList<T>::Iterator::operator*() {
	return this->some_node->data;
}

template<class T>
typename LinkedList<T>::Iterator LinkedList<T>::begin() {
	return Iterator(head);
}
template<class T>
typename LinkedList<T>::Iterator LinkedList<T>::end() {
	return nullptr;
}
template<class T>
typename LinkedList<T>::Iterator LinkedList<T>::advance_forward(int amount) {
	Iterator result = *this;
	for (int i = 0; i < amount; i++)
		++(*this);
	return result;
}
template<class T>
typename LinkedList<T>::Iterator LinkedList<T>::advance_back(int amount) {
	Iterator result = *this;
	for (int i = 0; i < amount; i++)
		--(*this);
	return result;
}


//MERGE SORT
template <class T>
void LinkedList<T>::split(Iterator head, Iterator& f, Iterator& s) {
	Iterator slow = head, fast = head;
	++fast;
	while (fast != nullptr) {
		++fast;
		if (fast != nullptr) {
			++slow;
			++fast;
		}
	}
	Iterator tmp = slow;
	++tmp;
	f = head;
	s = tmp;
	slow.some_node->next = nullptr;
}
template <class T>
void LinkedList<T>::merge_sort(Iterator& head, bool(*comparator_ascending_order)(const T&, const T&)) {
	Iterator head_ = head, f, s;
	Iterator tmp = head;
	++tmp;
	if ((head_ == nullptr) || (tmp == nullptr))
		return;
	split(head_, f, s);
	merge_sort(f, comparator_ascending_order);
	merge_sort(s, comparator_ascending_order);
	head = merge(f, s, comparator_ascending_order);
}
template <class T>
void LinkedList<T>::merge_sort_(bool(*comparator_ascending_order)(const T&, const T&)) {
	Iterator head_ = begin();
	merge_sort(head_, comparator_ascending_order);
	head = head_.some_node;
}
template <class T>
typename LinkedList<T>::Iterator LinkedList<T>::merge(Iterator f, Iterator s, bool(*comparator_ascending_order)(const T&, const T&)) {
	Iterator result = nullptr;
	if (f == nullptr)
		return s;
	if (s == nullptr)
		return f;
	if (comparator_ascending_order(s.operator*(), f.operator*())) {
		result = s;
		++s;
	}
	else {
		result = f;
		++f;
	}
	Iterator tmp = result;
	while (f != nullptr && s != nullptr) {
		if (comparator_ascending_order(s.operator*(), f.operator*())) {
			tmp.some_node->next = s.some_node;
			++s;
		}
		else {
			tmp.some_node->next = f.some_node;
			++f;
		}
		++tmp;
	}
	if (f != nullptr) {
		tmp.some_node->next = f.some_node;
	}
	if (s != nullptr) {
		tmp.some_node->next = s.some_node;
	}
	return result;
}


//QUICK SORT
template <class T>
typename LinkedList<T>::Iterator LinkedList<T>::partition(Iterator head, Iterator tail, bool(*comparator_ascending_order)(const T&, const T&)) {
	Iterator pivot = head, current = head;
	while ((current != nullptr) && (current != tail)) {
		if (comparator_ascending_order(current.operator*(), tail.operator*())) {
			pivot = head;
			T tmp = head.operator*();
			head.some_node->data = current.operator*();
			current.some_node->data = tmp;
			++head;
		}
		++current;
	}
	T tmp = head.operator*();
	head.some_node->data = tail.operator*();
	tail.some_node->data = tmp;
	return pivot;
}
template <class T>
void LinkedList<T>::quick_sort(Iterator head, Iterator tail, bool(*comparator_ascending_order)(const T&, const T&)) {
	if (head == tail)
		return;
	Iterator pivot = partition(head, tail, comparator_ascending_order);
	Iterator pivot_next = pivot;
	++pivot_next;
	if ((pivot != nullptr) && (pivot_next != nullptr))
		quick_sort(pivot_next, tail, comparator_ascending_order);
	if ((pivot != nullptr) && (head != pivot))
		quick_sort(head, pivot, comparator_ascending_order);
}
template <class T>
void LinkedList<T>::quick_sort_(bool(*comparator_ascending_order)(const T&, const T&)) {
	quick_sort(head, tail, comparator_ascending_order);
}


//BINARY INSERTION SORT
template <class T>
typename LinkedList<T>::Iterator LinkedList<T>::find_middle(Iterator head, Iterator tail) {
	if (head == nullptr)
		return nullptr;
	Iterator slow = head, fast = head;
	++fast;
	while (fast != tail) {
		++fast;
		if (fast != tail) {
			++slow;
			++fast;
		}
	}
	return slow;
}
template <class T>
typename LinkedList<T>::Iterator LinkedList<T>::binary_search(Iterator head, Iterator tail, const T& key, bool(*comparator_ascending_order)(const T&, const T&)) {
	Iterator head_ = head;
	Iterator tail_ = tail;
	++tail_;//=nullptr
	do {
		Iterator middle = find_middle(head_, tail_);
		if (middle == nullptr)
			return nullptr;
		if (middle.operator*() == key)
			return middle;
		if (comparator_ascending_order(middle.operator*(), key)) {
			Iterator middle_next = middle;
			++middle_next;
			head_ = middle_next;
		}
		else tail_ = middle;
	} while (tail_ != head_);
	return head_;
}
template <class T>
typename LinkedList<T>::Iterator LinkedList<T>::previous(Iterator some_node) {
	Iterator current = head, tmp = head;
	++tmp;
	while (tmp != nullptr) {
		if (tmp == some_node)
			return current;
		++current;
		++tmp;
	}
	return nullptr;
}
template <class T>
void LinkedList<T>::binary_insertion_sort_(bool(*comparator_ascending_order)(const T&, const T&)) {
	Iterator must_be_replaced = nullptr, prev_mbr = nullptr, j = head, i = nullptr, i_ = nullptr, tmp = nullptr;
	if (head == nullptr)
		i = nullptr;
	else {
		tmp = head;
		++tmp;
		i = tmp;
	}
	while (i != nullptr) {
		tmp = i;
		++tmp;
		i_ = tmp;
		T key = i.operator*();
		must_be_replaced = binary_search(head, j, key, comparator_ascending_order);
		if (i != must_be_replaced) {
			if (must_be_replaced != head) {
				prev_mbr = previous(must_be_replaced);
				prev_mbr.some_node->next = i.some_node;
			}
			else head = i.some_node;
			j.some_node->next = i.some_node->next;
			i.some_node->next = must_be_replaced.some_node;
		}
		i = i_;
		j = previous(i);
	}
}