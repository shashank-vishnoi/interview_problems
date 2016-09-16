#include <iostream>

using namespace std;

class A;
class A1;
class A2;
class B1;
class B2;

class B {
    public:
        // dispatcher function to A
        virtual void collide(const A& a) const = 0;

        // actual collision logic B with types of A
        virtual void collide(const A1& a) const = 0;
        virtual void collide(const A2& a) const = 0;
};

class A {
    public:
        // dispatcher function to B
        virtual void collide(const B& b) const = 0;

        // actual collision logic A with types of B
        virtual void collide(const B1& b) const = 0;
        virtual void collide(const B2& b) const = 0;
};

class A1 : public A {
    public:
        void collide(const B& b) const {
            // dispatch to b
		cout<<"A1::collide(const B& b)\n";
            b.collide(*this);
        }
        void collide(const B1& b) const {
            cout << "collision with B1 and A1" << endl;
        }
        void collide(const B2& b) const {
            cout << "collision with B2 and A1" << endl;
        }
};

class A2 : public A {
    public:
        void collide(const B& b) const {
            // dispatch to a
            b.collide(*this);
        }
        void collide(const B1& b) const {
            cout << "collision with B1 and A2" << endl;
        }
        void collide(const B2& b) const {
            cout << "collision with B2 and A2" << endl;
        }
};

class B1 : public B {
    public:
        void collide(const A& b) const {
		cout<<"collide(const A& b)...\n";
            b.collide(*this);
        }
        void collide(const A1& b) const {
            cout << "collision with A1 Bnd B1" << endl;
        }
        void collide(const A2& b) const {
            cout << "collision with A2 Bnd B1" << endl;
        }
};

class B2 : public B {
    public:
        void collide(const A& a) const {

		cout<<"A1::collide(const B& b)\n";
            a.collide(*this);
        }
        void collide(const A1& a) const {
            cout << "collision with A1 Bnd B2" << endl;
        }
        void collide(const A2& a) const {
            cout << "collision with A2 Bnd B2" << endl;
        }
};

int main() {

    A* a = new A1();
    B* b = new B2();
    B2* b2 = new B2();

    // first dispatch is done by polymorphism ( a is resolved as a A1 )
    // second dispatch is done in collide function by the function overloading
    // ( in collide function we are sending A1 to collide function of B )
    a->collide(*b);

}

