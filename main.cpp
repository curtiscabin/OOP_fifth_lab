#include"Parent.h"


int main() {
	Parent *a = new Child();
	delete a;

	cout << endl;
	Child b;
	b.method1();

	b.method4virtual1();


	cout << endl;

	Parent* p = new Parent();
	Parent* c = new Child();

	p->non_virtual();
	c->non_virtual();

	p->func4virtual();
	c->func4virtual();

	delete p;
	delete c;

	cout << endl;

	cout << "\ntype casting\n";
	cout << "\nUnsafe\n";

	Parent* p1 = new Parent();
	Parent* p2 = new Child();
	Parent* p3 = new Baby();

	Child* c1 = (Child*)p1;
	Baby* b1 = (Baby*)p2;

	c1->methodChild();
	b1->methodBaby();

	cout << "\nSafe with isA\n";

	if (p2->isA("Child")) {
		Child* c = (Child*)p2;
		c->methodChild();
	}
	if (p3->isA("Baby")) {
		Baby* b = (Baby*)p3;
		b->methodBaby();
	}

	cout << "\nSafe with dynamic_cast\n";

	Child* c2 = dynamic_cast<Child*>(p3);
	if (c2)
	c2->methodChild();
	else cout << "p3 is not Child\n";

	Baby* b2 = dynamic_cast<Baby*>(p3);
	if (b2)
	b2->methodBaby();
	else cout << "p3 is not Baby\n";

	

}


