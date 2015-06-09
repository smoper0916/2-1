#pragma once

#include "ChainNode.h"
#include "ChainIterator.h"
#include <iostream>

class Chain
{
public:
	Chain(){ tail = head = nullptr; }
	ChainIterator begin() { return ChainIterator(head); }
	ChainIterator end() { return ChainIterator(0); }
	ChainIterator find(Student data);
	ChainIterator* getBig(Student s);
	ChainNode* getHead(){ return head; }
	ChainNode* getTail(){ return tail; }
	void setHead(ChainNode* head){ this->head = head; }
	void setTail(ChainNode* tail){ this->tail = tail; }

	void insertData(Student data);
	void insertData(Student frontData, Student data);
	void deleteData(Student data);
	void printData();
private:
	ChainNode* head;
	ChainNode* tail;
};