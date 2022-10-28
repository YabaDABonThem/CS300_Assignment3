#ifndef NODE_H_
#define NODE_H_
#include <algorithm>

template<class T>
class Node
{
	private:
		// set default values for fields
		T item_ = {};
		T max_ = {};
		T sum_ = {};
		T count_ = {};
		Node<T> *nextPtr_ = nullptr;

	public:
		Node() = delete;
		// constructor is called when there are no items in the stack
		Node(const T &anItem):item_(anItem), max_(anItem), sum_(anItem), count_(1){}

		// Node(const Node<T> &other) {
		// 	Node(other.getItem());
		// }
		
		Node(const T &anItem, Node<T> *nextNodePtr) {
			// Recompute these values. 
			// check if you are the only Node
			if (nextNodePtr == nullptr) {
				item_ = anItem;
				max_ = anItem;
				sum_ = anItem;
				count_ = 1;
				return;
			}
			// If there is are existing nodes, then you need to compute values
			// based off the ones from the previous node.
			item_ = anItem;
			max_ = std::max(item_, nextNodePtr->getMax());
			sum_ = item_ + nextNodePtr->getSum();
			count_ = nextNodePtr->getCount() + 1;
			nextPtr_ = nextNodePtr;
			
		}
		
		// getters and setters below:
		void setNext(Node<T> *nextNodePtr) {
			nextPtr_ = nextNodePtr;
		}
		T getMax() const {
			return max_;
		}
		
		T getMean() const {
			return sum_ / count_;
		}
		
		T getSum() const {
			return sum_;
		}
		
		T getItem() const {
			return item_;
		}

		size_t getCount() const {
			return count_;
		}

		Node<T> *getNext() const {
			return nextPtr_;
		}

};

#endif
