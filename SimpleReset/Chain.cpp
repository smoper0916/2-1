#include "Chain.h"

ChainIterator Chain::find(Student data){
	for (ChainIterator p = begin(); p != end(); ++p)
	if (*p == data) return p;
	return NULL;
}
ChainIterator* Chain::getBig(Student s){
	ChainIterator p;
	ChainIterator* big = NULL;
	
	for (p = begin(); p != 0; ++p){
		//cout << p.getNode()->getData().getStdN();
		if (*p < s){
			if (big){
				if (**big < *p)
					big = &p;
			}
			else
				big = &p;
		}
	}
	if (big){
		p = *big;
		big = new ChainIterator(p);
	}
	return big;
}
void Chain::insertData(Student data)
{
	if (!head)
		head = tail = new ChainNode(data);
	else{
		tail->next = new ChainNode(data);
		tail = tail->next;
	}
}
void Chain::insertData(Student frontData, Student data)
{
	if (!head)
		std::cout << "Can't Found Data" << endl;
	else{
		ChainIterator* current = NULL;
		ChainNode* currentNode;
		ChainNode* midNode;
		ChainNode* nextNode;
		for (current = new ChainIterator(begin()); *current != end(); ++current){
			if (**current == frontData)
				break;
		}
		currentNode = current->getNode();
		nextNode = currentNode->next;
		midNode = new ChainNode(data);

		currentNode->next = midNode;
		midNode->next = nextNode;
	}
}
void Chain::deleteData(Student data)
{
	ChainIterator* previous = NULL;
	ChainIterator* current;

	ChainNode* previousNode;
	ChainNode* currentNode;
	for (current = new ChainIterator(begin()); *current != end(); ++current){
		if (**current == data)
			break;
		previous = current;
	}
	delete current;
	currentNode = current->current;
	previousNode = previous->current;

	if (!previous){
		if (!head->next)
			tail = NULL;
		ChainNode* tmp = head->next;
		delete head;
		head = tmp;
	}
	else if (currentNode == tail){
		previousNode->next = NULL;
		delete tail;
		tail = previousNode;
	}
	else{
		previousNode->next = currentNode->next;
		currentNode->next = NULL;
		delete currentNode;
	}
}
void Chain::printData(){

}