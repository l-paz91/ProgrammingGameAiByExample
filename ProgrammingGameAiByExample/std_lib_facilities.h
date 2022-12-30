/*
std_lib_facilities.h
*/

/*
	simple "Programming: Principles and Practice using C++ (second edition)" course header to
	be used for the first few weeks.
	It provides the most common standard headers (in the global namespace)
	and minimal exception/error support.

	Students: please don't try to understand the details of headers just yet.
	All will be explained. This header is primarily used so that you don't have
	to understand every concept all at once.

	By Chapter 10, you don't need this file and after Chapter 21, you'll understand it

	Revised April 25, 2010: simple_error() added

	Revised November 25 2013: remove support for pre-C++11 compilers, use C++11: <chrono>
	Revised November 28 2013: add a few container algorithms
	Revised June 8 2014: added #ifndef to workaround Microsoft C++11 weakness
*/

// @ BEGIN LPTCP - This header has been modified over the years by myself. This version can be found here:
// https://github.com/l-paz91/principles-practice/blob/master/std_lib_facilities.h
// @ END LPTCP

#ifndef H112
#define H112 251113L


#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <list>
#include <forward_list>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <array>
#include <regex>
#include <random>
#include <stdexcept>
#include <conio.h>

//#define _CRTDBG_MAP_ALLOC
//#include <crtdbg.h>

//------------------------------------------------------------------------------

typedef uint32_t uint32;

//------------------------------------------------------------------------------

typedef long Unicode;

//------------------------------------------------------------------------------

using namespace std;

template<class T> string to_string(const T& t)
{
	ostringstream os;
	os << t;
	return os.str();
}

// -----------------------------------------------------------------------------

//@ LPTCP BEGIN - add from_string from section 23.2
template<typename T>
T from_string(const string& s)
{
	istringstream is{ s };
	T t;
	if (!(is >> t))
		cerr << "Bad cast from string.\n";
	return t;
}
//@ LPTCP END - add from_string from section 23.2

// -----------------------------------------------------------------------------

struct Range_error : out_of_range {	// enhanced vector range error reporting
	int index;
	Range_error(int i) :out_of_range("Range error: " + to_string(i)), index(i) { }
};

// -----------------------------------------------------------------------------

// trivially range-checked vector (no iterator checking):
template< class T> struct Vector : public std::vector<T>
{
	using size_type = typename std::vector<T>::size_type;

#ifdef _MSC_VER
	// microsoft doesn't yet support C++11 inheriting constructors
	Vector() { }
	explicit Vector(size_type n) :std::vector<T>(n) {}
	Vector(size_type n, const T& v) :std::vector<T>(n, v) {}
	template <class I>
	Vector(I first, I last) : std::vector<T>(first, last) {}
	Vector(initializer_list<T> list) : std::vector<T>(list) {}
#else
	using std::vector<T>::vector;	// inheriting constructor
#endif

	T& operator[](unsigned int i) // rather than return at(i);
	{
		if (i < 0 || this->size() <= i) throw Range_error(i);
		return std::vector<T>::operator[](i);
	}
	const T& operator[](unsigned int i) const
	{
		if (i < 0 || this->size() <= i) throw Range_error(i);
		return std::vector<T>::operator[](i);
	}

	//@ LPTCP BEGIN - add range-checked iterators to vector - c20 e18
	class CheckedIt;
	//@ LPTCP END - add range-checked iterators to vector - c20 e18

	// @ LPTCP BEGIN - add 'push_front' to a vector for an exercise
	void push_front(T value)
	{
		std::vector<T>::insert(std::vector<T>::begin(), value);	// the laziest implementation ever
	}
	// @ LPTCP END - add 'push_front' to a vector for an exercise
};

//@ LPTCP BEGIN - add range-checked iterators to vector - c20 e18
template<typename T>
class Vector<T>::CheckedIt
{
	using It = typename vector<T>::iterator;
	using v = typename std::vector<T>;

public:
	CheckedIt(v* parent)
		: mParent(parent)
		, mCurrent(parent->begin())
	{}

	It& operator++()
	{
		++mCurrent;
		rangeCheck();
		return mCurrent;
	}

	It& operator--()
	{
		--mCurrent;
		rangeCheck();
		return mCurrent;
	}

	It& operator=(const It& it) { mCurrent = it; return mCurrent; }
	T& operator*() { return *mCurrent; }
	const T& operator*() const { return *mCurrent; }

	bool operator==(const It& i) const { return mCurrent == i; }
	bool operator!=(const It& i) const { return mCurrent != i; }

	It& operator+(int n)
	{
		mCurrent += n;
		rangeCheck();
		return mCurrent;
	}

	It& operator+=(CheckedIt& i)
	{
		auto pos = mCurrent + i.mCurrent;
		mCurrent += pos;
		rangeCheck();
		return mCurrent;
	}

	It& operator+=(int n)
	{
		mCurrent += n;
		rangeCheck();
		return mCurrent;
	}

	It& operator-(int n)
	{
		mCurrent -= n;
		rangeCheck();
		return mCurrent;
	}

	It& operator-=(CheckedIt& i)
	{
		auto pos = mCurrent - i.mCurrent;
		mCurrent -= pos;
		rangeCheck();
		return mCurrent;
	}

	It& operator-=(int n)
	{
		mCurrent -= n;
		rangeCheck();
		return mCurrent;
	}

	void rangeCheck()
	{
		auto i = mCurrent - mParent->begin();
		if (i >= mParent->size() || i < 0)
			throw Range_error(i);
	}

private:
	v* mParent;
	It mCurrent;
};
//@ LPTCP END - add range-checked iterators to vector - c20 e18

// disgusting macro hack to get a range checked vector:
#define vector Vector

// -----------------------------------------------------------------------------

// trivially range-checked string (no iterator checking):
struct String : std::string {
	using size_type = std::string::size_type;
	//	using string::string;

	char& operator[](unsigned int i) // rather than return at(i);
	{
		if (i < 0 || size() <= i) throw Range_error(i);
		return std::string::operator[](i);
	}

	const char& operator[](unsigned int i) const
	{
		if (i < 0 || size() <= i) throw Range_error(i);
		return std::string::operator[](i);
	}
};

namespace std {

	template<> struct hash<String>
	{
		size_t operator()(const String& s) const
		{
			return hash<std::string>()(s);
		}
	};

} // of namespace std


struct Exit : runtime_error {
	Exit() : runtime_error("Exit") {}
};

// error() simply disguises throws:
inline void error(const string& s)
{
	throw runtime_error(s);
}

inline void error(const string& s, const string& s2)
{
	error(s + s2);
}

inline void error(const string& s, int i)
{
	ostringstream os;
	os << s << ": " << i;
	error(os.str());
}


template<class T> char* as_bytes(T& i)	// needed for binary I/O
{
	void* addr = &i;	// get the address of the first byte
						// of memory used to store the object
	return static_cast<char*>(addr); // treat that memory as bytes
}


inline void keep_window_open()
{
	cin.clear();
	cout << "Please enter a character to exit\n";
	char ch;
	cin >> ch;
	return;
}

inline void keep_window_open(string s)
{
	if (s == "") return;
	cin.clear();
	cin.ignore(120, '\n');
	for (;;) {
		cout << "Please enter " << s << " to exit\n";
		string ss;
		while (cin >> ss && ss != s)
			cout << "Please enter " << s << " to exit\n";
		return;
	}
}

// -----------------------------------------------------------------------------

// @ BEGIN LPTCP - add simple continue function
inline void pressKeyToContinue()
{
	cin.clear();
	cout << "Press any key to continue\n";
	_getch();
	return;
}
// @ END LPTCP - add simple continue function

// -----------------------------------------------------------------------------

// error function to be used (only) until error() is introduced in Chapter 5:
inline void simple_error(string s)	// write ``error: s and exit program
{
	cerr << "error: " << s << '\n';
	keep_window_open();		// for some Windows environments
	exit(1);
}

// make std::min() and std::max() accessible on systems with antisocial macros:
#undef min
#undef max


// run-time checked narrowing cast (type conversion). See ???.
template<class R, class A> R narrow_cast(const A& a)
{
	R r = R(a);
	if (A(r) != a) error(string("info loss"));
	return r;
}

// random number generators. See 24.7.

// @ BEGIN LPTCP - change seed of mt19937 to pc time to stop it using the default
inline int randint(int min, int max)
{
	static default_random_engine ran((unsigned int)time(0));
	return uniform_int_distribution<>{min, max}(ran);
}
// @ END LPTCP - change seed of mt19937 to pc time to stop it using the default

inline int randint(int max) { return randint(0, max); }

//inline double sqrt(int x) { return sqrt(double(x)); }	// to match C++0x

// container algorithms. See 21.9.

template<typename C>
using Value_type = typename C::value_type;

template<typename C>
using Iterator = typename C::iterator;

template<typename C>
// requires Container<C>()
void sort(C& c)
{
	std::sort(c.begin(), c.end());
}

template<typename C, typename Pred>
// requires Container<C>() && Binary_Predicate<Value_type<C>>()
void sort(C& c, Pred p)
{
	std::sort(c.begin(), c.end(), p);
}

template<typename C, typename Val>
// requires Container<C>() && Equality_comparable<C,Val>()
Iterator<C> find(C& c, Val v)
{
	return std::find(c.begin(), c.end(), v);
}

template<typename C, typename Pred>
// requires Container<C>() && Predicate<Pred,Value_type<C>>()
Iterator<C> find_if(C& c, Pred p)
{
	return std::find_if(c.begin(), c.end(), p);
}

#endif //H112