#ifndef NODE_H_
#define NODE_H_

template<class T>
class Node
{
	private:
		T item;
		T max;
		T sum;
		T mean;
		Node<T> *nextPtr;

	public:
		Node() = default;
		Node(const T &anItem):item(anItem), max(anItem), sum(anItem), mean(anItem){}
		Node(const Node<T> &other) {
			Node(other.getItem());
		}
		Node(const T &anItem, Node<T> *nextNodePtr);
		void setItem(const T &anItem);
		void setNext(Node<T> *nextNodePtr);
		T getMax() const;
		void setMax(const T &newMax);
		T getMean() const;
		void setMean(const T &newMean);
		T getSum() const;
		void setSum(const T &newMean);
		T getItem() const;
		Node<T> *getNext() const;
		//setNext();

};

#endif
