#pragma once
#include<iostream>
using namespace std;

class Base {
public:
	int x;
	Base() : x(0) {
		cout << "default constructor Base\n";
	}

	Base(Base* obj) {
		cout << "pointer constructor Base\n";
		x = obj->x;
	}

	Base(Base& obj) {
		cout << "reference constructor Base\n";
		x = obj.x;
	}

	~Base() {
		cout << "delete Base\n";
	}

	virtual void say() {
		cout << "i am Base, my x is - "<<x<<endl;
	}
};

class Desc : public Base {
public:
	int x;
	Desc() : x(0) {
		cout << "default constructor Desc\n";
	}

	Desc(Desc* obj) {
		cout << "pointer constructor Desc\n";
		x = obj->x;
	}

	Desc(Desc& obj) {
		cout << "reference constructor Desc\n";
		x = obj.x;
	}

	~Desc() {
		cout << "delete Desc\n";
	}

	void say() override {
		cout << "i am Desc, my x is - " << x << endl;
	}
};

void func1_(Base  obj) {
	cout << "\nvoid func1\n";
	obj.say();
};
void func2_(Base* obj) {
	cout << "\nvoid func2\n";
	obj->say();
};
void func3_(Base& obj) {
	cout << "\nvoid func3\n";
	obj.say();
};



Base func1() {
	cout << "Base func1\n";
	Base a;
	return a;
};
Base* func2() {
	cout << "Base func2\n";
	Base a;
	Base* b = &a;
	return b;
};
Base& func3() {
	cout << "Base func3\n";
	Base a;
	return a;
};
Base func4() {
	cout << "Base func4\n";
	Base* a = new Base;
	return *a;
};
Base* func5() {
	cout << "Base func5\n";
	Base* a = new Base;
	return a;
};
Base& func6() {
	cout << "Base func6\n";
	Base* a = new Base;
	return *a;
};


