#ifndef NODE_H_
#define NODE_H_
#include <algorithm>

template<class T>
class Node
{
	private:
		T item_;
		T max_;
		T sum_;
		T count_;
		Node<T> *nextPtr_;

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
				Node(anItem);
				return;
			}

			item_ = anItem;
			max_ = std::max(item_, nextNodePtr->getMax());
			sum_ = item_ + nextNodePtr->getSum();
			count_ = nextNodePtr->getCount() + 1;
			
		}
		// void setItem(const T &anItem);
		void setNext(Node<T> *nextNodePtr) {
			nextPtr_ = nextNodePtr;
		}
		T getMax() const {
			return max_;
		}
		// void setMax(const T &newMax);
		T getMean() const {
			return sum_ / count_;
		}
		// void setMean(const T &newMean);
		T getSum() const {
			return sum_;
		}
		// void setSum(const T &newMean);
		T getItem() const {
			return item_;
		}

		size_t getCount() const {
			return count_;
		}

		Node<T> *getNext() const {
			return nextPtr_;
		}
		//setNext();

};

#endif
