#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

namespace fraction {
	class Fraction {
		int numerator;
		int denominator;
	public:
		Fraction(int n, int d) : numerator(n), denominator(d) {
            if (denominator == 0) {
                cout << "Denominator cannot be zero. ";
                throw - 1;
            }
		}

		Fraction add(const Fraction& other) const {
			int new_numerator = numerator * other.denominator + other.numerator * denominator;
			int new_denominator = denominator * other.denominator;
			return Fraction(new_numerator, new_denominator);
		}

		Fraction subtract(const Fraction& other) const {
			int new_numerator = numerator * other.denominator - other.numerator * denominator;
			int new_denominator = denominator * other.denominator;
			return Fraction(new_numerator, new_denominator);
		}

		Fraction multiply(const Fraction& other) const {
			int new_numerator = numerator * other.numerator;
			int new_denominator = denominator * other.denominator;
			return Fraction(new_numerator, new_denominator);
		}

		Fraction divide(const Fraction& other) const {
            if (other.numerator == 0) {
                cout << "Cannot divide by zero. ";
                throw - 1;
            }
			int new_numerator = numerator * other.denominator;
			int new_denominator = denominator * other.numerator;
			return Fraction(new_numerator, new_denominator);
		}

		void print() const {
            cout << numerator << "/" << denominator << endl;
		}
	};
}

namespace point {
	class Point2D {
		int x, y;
	public:
		Point2D(int X, int Y) : x(X), y(Y) {}

		double distance(const Point2D& other) const {
			return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2));
		}
	};

	class Point3D {
		int x, y, z;
	public:
		Point3D(int X, int Y, int Z) : x(X), y(Y), z(Z) {}

		double distance(const Point3D& other) const {
			return sqrt(pow(x - other.x, 2) + pow(y - other.y, 2) + pow(z - other.z, 2));
		}
	};
}

namespace equation {
    class Equation {
    public:
        virtual void solution() const = 0;
        virtual void print() const = 0;
    };

    class LinearEquation : public Equation {
        int a, b;
    public:
        LinearEquation(int A, int B) : a(A), b(B) {
            if (a == 0) {
                cout << "No solution. ";
                throw - 1;
            }
        }

        void solution() const override {
            if (a != 0) {
                double x = double(-b) / a;
                cout << "The solution of linear equation: x = " << x << endl;
            }
            else if (a == 0 && b == 0) {
                cout << "The equation has infinitely many solutions." << endl;
            }
        }

        void print() const override {
            cout << a << "x ";
            if (b < 0) {
                cout << "- " << abs(b);
            }
            else {
                cout << "+ " << b;
            }
            cout << " = 0" << endl;
        }
    };

    class QuadraticEquation : public Equation {
        int a, b, c;
    public:
        QuadraticEquation(int A, int B, int C) : a(A), b(B), c(C) {
            if (a == 0) {
                cout << "No solution. ";
                throw - 1;
            }
        }

        void solution() const override {
            double D = pow(b, 2) - 4 * a * c;
            if (D > 0) {
                double x1 = double(-b + sqrt(D)) / (2 * a);
                double x2 = double(-b - sqrt(D)) / (2 * a);
                cout << "The solutions of quadratic equation: x1 = " << x1 << ", x2 = " << x2 << endl;
            }
            else if (D == 0) {
                double x = double(-b) / (2 * a);
                cout << "The solution of quadratic equation: x = " << x << endl;
            }
            else {
                cout << "No real solutions." << endl;
            }
        }

        void print() const override {
            cout << a << "x^2 ";
            if (b < 0) {
                cout << "- " << abs(b) << "x ";
            }
            else {
                cout << "+ " << b << "x ";
            }
            if (c < 0) {
                cout << "- " << abs(c);
            }
            else {
                cout << "+ " << c;
            }
            cout << " = 0" << endl;
        }
    };
}

int main() {
    try {
        fraction::Fraction f1(1, 3);
        fraction::Fraction f2(1, 4);
        fraction::Fraction result = f1.add(f2);
        cout << "Add: " << endl;
        result.print();
        result = f1.subtract(f2);
        cout << "Subtract: " << endl;
        result.print();
        result = f1.multiply(f2);
        cout << "Multiply: " << endl;
        result.print();
        result = f1.divide(f2);
        cout << "Divide: " << endl;
        result.print();
    }
    catch(...) {
        cerr << "Error!" << endl;
    }

    point::Point2D p1(0, 0);
    point::Point2D p2(3, 4);
    cout << "Distance between points in 2D: " << p1.distance(p2) << endl;

    point::Point3D p3(0, 0, 0);
    point::Point3D p4(1, 2, 2);
    cout << "Distance between points in 3D: " << p3.distance(p4) << endl;

    try {
        equation::LinearEquation e1(2, -4);
        e1.print();
        e1.solution();

        equation::QuadraticEquation e2(3, -14, -5);
        e2.print();
        e2.solution();
    }
    catch (...) {
        cerr << "Error!" << endl;
    }

    return 0;
}