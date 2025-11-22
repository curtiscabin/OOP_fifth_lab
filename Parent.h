#pragma once
#include<iostream>
#include<string>
using namespace std;

class Parent {
public:
	Parent() {
		cout << "creating Parent\n";
	}

	virtual ~Parent() {
		cout << "delete Parent\n";
	}

	void method1() {
		cout << "method1 worked\n";
		method2();
	}

	void method2() {
		cout << "method2 worked in Parent\n";
	}

	void method4virtual1() {
		cout << "method1 for virtual in Parent\n";
		method4virtual2();
	}

	virtual void method4virtual2() {
		cout << "method2 fot virtual in Parent\n";
	}

	void non_virtual() {
		cout << "non_virtual in Parent\n";
	}

	virtual void func4virtual() {
		cout << "func for virtual in Parent\n";
	}

	virtual string classname() {
		return "Parent";
	}

	virtual bool isA(string classname) {
		return classname == this->classname();
	}
};

class Child : public Parent {
public:
	Child() {
		cout << "creating Child\n";
	}

	~Child() {
		cout << "delete Child\n";
	}

	void method2() {
		cout << "method2 worked in Child\n";
	}

	void method4virtual2() override {
		cout << "method2 for virtual in Child\n";
	}

	void non_virtual() {
		cout << "non_virtual in Child\n";
	}

	void func4virtual() override {
		cout << "func for virtual in Child\n";
	}

	string classname() override {
		return "Child";
	}

	bool isA(string classname) override {
		return classname == this->classname() || Parent::isA(classname);
	}

	void methodChild() {
		cout << "i am Child\n";
	}
};

class Baby : public Parent {
public:
	Baby() {
		cout << "creating Baby\n";
	}

	string classname() override {
		return "Baby";
	}

	bool isA(string classname) override {
		return classname == this->classname() || Parent::isA(classname);
	}

	void methodBaby() {
		cout << "i am Baby\n";
	}

};