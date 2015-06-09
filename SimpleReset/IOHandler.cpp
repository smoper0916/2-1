#include "IOHandler.h"

void IOHandler::save(Student object){
	ofstream os(fileName);
	os << object << endl;
	os.close();
}
void IOHandler::load(Chain& stdList){
	Student* ob = new Student();
	Student& object = *ob;
	ifstream is(fileName);
	if (is.fail())
		throw "File Open에 실패했습니다.";
	while (true){
		is >> object;
		if (is.eof())
			break;

		ChainIterator* iter = stdList.getBig(object);
		if (iter)
			stdList.insertData(iter->getNode()->getData(), object);
		else
			stdList.insertData(object);
	}
	is.close();
}