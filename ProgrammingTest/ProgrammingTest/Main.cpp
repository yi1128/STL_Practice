#include <stdio.h>
#include <iostream>
#include <string>
#include <span>
#include <list>
#include <map>
#include <tuple>

//#define ARRAY
//#define DYNAMIC_PROGRAMMING
//#define LINKED_LIST
//#define LIST
//#define TUPLE
//#define MAP
//#define MULTIMAP
//#define MOVE_SEMENTICS
//#define CLASS_VIRTUAL
//#define OPERATOR
//#define CLASS_CONST
//#define ALLOCATOR
//#define ACCUMULATE_MOVE
//#define SHARED_PTR_N_WEAK_PTR
//#define UNINITIALIZED_COPY
//#define LAMBDA_FUNCTION
//#define TRANSFORM
//#define VECTOR
//#define FORWARD_LIST
//#define PRIORITY_QUEUE
//#define VECTOR_PTR
//#define HASH_TABLE
//#define SORT
//#define STABLE_SORT
//#define PARTIAL_SORT
//#define PARTIAL_SORT_COPY
//#define NTH_ELEMENT
//#define MERGE
//#define FIND
//#define SEARCH
//#define PARTITION

#ifdef ARRAY
#include<iostream>
#include<iomanip>
#include<array>
#include<algorithm>

int main(void)
{
	const unsigned int min_wt{ 100U };
	const unsigned int max_wt{ 250U };
	const unsigned int wt_step{ 10U };
	const size_t wt_count{ 1 + (max_wt + min_wt) / wt_step };

	const unsigned int min_ht{ 100U };
	const unsigned int max_ht{ 250U };
	const unsigned int ht_step{ 10U };
	const size_t ht_count{ 1 + (max_ht - min_ht) / ht_step };

	const double lbs_per_kg{ 2.20462 };
	const double ins_per_m{ 39.3701 };

	std::array<unsigned int, wt_count> weight_lbs;
	std::array<unsigned int, ht_count> height_ins;

	for (size_t i{}, w{ min_wt }; i < wt_count; w += wt_step, ++i)
	{
		weight_lbs.at(i) = w;
	}

	unsigned int h{ min_ht };
	for (auto& height : height_ins)
	{
		height = h;
		h += ht_step;
	}

	std::cout << std::setw(7) << " |";
	for (const auto& w : weight_lbs)
		std::cout << std::setw(5) << w << " |";
	std::cout << std::endl;

	for (size_t i{ 1 }; i < wt_count; ++i)
		std::cout << "--------";
	std::cout << std::endl;

	double bmi{};
	unsigned int feet{};
	unsigned int inches{};
	const unsigned int inches_per_foot{ 12U };
	for (const auto& h : height_ins)
	{
		feet = h / inches_per_foot;
		inches = h % inches_per_foot;
		std::cout << std::setw(2) << feet << "'" << std::setw(2) << inches << "\"" << "|";
		std::cout << std::fixed << std::setprecision(1);
		for (const auto& w : weight_lbs)
		{
			bmi = h / ins_per_m;
			bmi = (w / lbs_per_kg) / (bmi * bmi);
			std::cout << std::setw(2) << " " << bmi << " |";
		}
		std::cout << std::endl;
	}

	for (size_t i{ 1 }; i < wt_count; ++i)
		std::cout << "--------";
	std::cout << "\nBMI 18.5~24.9는 정상입니다." << std::endl;

	unsigned int height{};
	std::generate(std::begin(height_ins), std::end(height_ins), [height, &min_ht, &ht_step]() mutable {return height += height == 0 ? min_ht : ht_step; });
	for (auto& height_ : height_ins)
	{
		std::cout << height_ << std::endl;
	}

}
#endif

#ifdef DYNAMIC_PROGRAMMING
int main()
{
	const int x = 5;
	const int y = 5;
	int count = 0;
	int aValue[x][y];
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			aValue[i][j] = count;
			std::cout << count++ << "\t";
		}
		std::cout << std::endl;
	}
	std::
	
	return 1;
}
#endif

#ifdef LINKED_LIST
/* Linked List */
struct ListNode {
	int element;
	ListNode* prev, * next;
};

void deleteNode(ListNode* node) {
	node->prev->next = node->next;
	node->next->prev = node->prev;
}

void recoverNode(ListNode* node) {
	node->prev->next = node;
	node->next->prev = node;
}
#endif

#ifdef LIST
int main()
{
	std::list<int> a;
	
	a.push_back(22);
	a.push_back(33);
	a.push_front(11);
	a.push_back(44);
	a.push_back(55);
	
	std::list<int>::iterator iter;
	for (iter = a.begin(); iter != a.end(); iter++)
	{
		std::cout << *iter << std::endl;
	}

	std::cout << "" << std::endl;
	std::cout << "" << std::endl;

	// 원소 삭제 
	a.pop_front();
	a.pop_back();

	for (iter = a.begin(); iter != a.end(); iter++)
	{
		std::cout << *iter << std::endl; // 원소 삭제후 리스트: 22 33 44 
	}

	std::cout << "" << std::endl;

	// 리스트 사이즈 출력 
	std::cout << "size : " << a.size() << std::endl; // 3 출력( 22, 33, 44 이므로) 

	// 리스트가 비어있는가 
	std::cout << "empty ? "<< a.empty() << std::endl; // 비어있지 않으므로 0 반환 

	// 리스트 첫번째 원소 출력 
	std::cout << "first element : " << a.front() << std::endl; // 22 

	// 리스트 마지막 원소 출력 
	std::cout << "last element : " << a.back() << std::endl; // 44 

	std::cout << "" << std::endl;

	// 반복자 2번째 위치로 이동 
	iter--; // 반복자가 두번째 원소(33)를 가리킴 
	iter--; // 반복자가 세번째 원소(44)를 가리킴 
	
	a.insert(iter, 55555);
	for (iter = a.begin(); iter != a.end(); iter++)
	{
		std::cout << *iter << std::endl; //세번째 원소(44) 전에 추가하는 것(22,55555,33,44) 
	}
	return 0;
}


/*
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <list>


class my_greater
{
public:
	bool operator()(const std::string& s1, const std::string& s2)
	{
		if (s1[0] == s2[0])
			return s1.length() > s2.length();
		else
			return s1 > s2;
	}
};

int main(void)
{
	std::list<std::string> names{ "Jules", "Jim", "Janet", "Hugo", "Hannah", "Ann", "Alan" };

	names.sort(std::greater<std::string>());

	std::list<std::string>::iterator names_iter = names.begin();
	for (; names_iter != names.end(); names_iter++)
	{
		std::cout << *names_iter << " ";
	}
	std::cout << std::endl;
	names.sort(my_greater());
	std::copy(names.begin(), names.end(), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;

	names.sort([](const  std::string s1, const std::string s2) {
		if (s1[0] == s2[0])
			return s1.length() > s2.length();
		else
			return s1 > s2;
		}
	);
	std::copy(names.begin(), names.end(), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;

	std::list<std::string> names_plus{ "Lee", "Han", "Su", "Bek" };

	names.sort();
	names_plus.sort();
	names.merge(names_plus);
	std::copy(names.begin(), names.end(), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;
	// merge 후 names_plus는 비어 있게 된다.
	std::copy(names_plus.begin(), names_plus.end(), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;
	names_plus.push_back("Hi");
	names_plus.push_back("Bill");
	names_plus.push_back("Draw");
	// splice 후에는 names_plus 하나가 사라진다.
	names.splice(std::begin(names), names_plus, std::begin(names_plus));
	std::copy(names.begin(), names.end(), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;

	names_plus.push_back("Dan");
	names_plus.push_back("Craw");
	names_plus.push_back("Fill");
	// splice 후에 names_plus 모두 사라지게 된다.
	names.splice(std::begin(names), names_plus, std::begin(names_plus), std::end(names_plus));
	std::copy(names.begin(), names.end(), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;

	names_plus.push_back("Don");
	names_plus.push_back("Caw");
	names_plus.push_back("Hun");
	// splice 후에 names_plus 모두 사라짐
	names.splice(std::end(names), names_plus);
	std::copy(names.begin(), names.end(), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;
}


*/

#endif

#ifdef TUPLE
int main()
{
	int nNum = 10;
	char a = 'A';
	std::string str = "abdcefg";
	std::tuple<int, char, std::string> User = std::tuple<int, char, std::string>(nNum, a, str);
	std::cout << std::get<0>(User) << std::endl;
	std::cout << std::get<1>(User) << std::endl;
	std::cout << std::get<2>(User) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::get<0>(User) = 20;
	std::get<1>(User) = 'B';
	std::get<2>(User) = "hijklnmop";
	std::cout << std::get<0>(User) << std::endl;
	std::cout << std::get<1>(User) << std::endl;
	std::cout << std::get<2>(User) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	
	std::tuple<int, char, std::string> User2 = std::make_tuple(nNum, a, str);
	std::cout << std::get<0>(User2) << std::endl;
	std::cout << std::get<1>(User2) << std::endl;
	std::cout << std::get<2>(User2) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	/* how to use tuple size */
	int nNum1 = 30;
	int nNum2 = 40;
	int nNum3 = 50;
	char c = 'C';
	std::string strMerge = "abcdefghijklnmop";
	std::tuple<int, int, int, char, std::string> User3 = std::make_tuple(30, 40, 50, 'C', "abcdefghijklnmop");
	//std::tuple<int, int, int, char, std::string> User3 = std::make_tuple(nNum1, nNum2, nNum3, c, strMerge);
	auto nTupleCount = std::tuple_size<decltype(User3)>::value;
	std::cout << "tuple size : " << nTupleCount << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	/* end how to use tuple size */

	/* 참고 decltype 사용법 */
	std::cout << "example how to use decltype" << std::endl;
	struct A {
		double d;
	};

	int prac_a = 3;
	decltype(prac_a) prac_b = 2;  // int
	std::cout << "prac_a : " << prac_a << std::endl;
	std::cout << "prac_b : " << prac_b << std::endl;
	std::cout << std::endl;

	int& r_a = prac_a;
	decltype(r_a) r_b = prac_b;  // int&
	std::cout << "r_a : " << r_a << std::endl;
	std::cout << "r_b : " << r_b << std::endl;
	std::cout << std::endl;

	int&& prac_x = 3;
	decltype(prac_x) prac_y = 2;  // int&&
	std::cout << "prac_x : " << prac_x << std::endl;
	std::cout << "prac_y : " << prac_y << std::endl;

	A* aa;
	decltype(aa->d) dd = 0.1;  // double
	std::cout << "dd : " << dd << std::endl;

	struct B {
		double t;
		double c;
	};
	
	B structB;
	B structBtest;
	structBtest.c = 3.14;
	structBtest.t = 3.15;
	decltype(structB) sturctB2 = structBtest;
	/* end 참고 decltype 사용법 */

	std::tuple<int, char, std::string> User4 = std::make_tuple(40, 'A', "abc");
	std::tuple<int, char, std::string> User5 = std::make_tuple(50, 'B', "def");
	auto User_cat = std::tuple_cat(User4, User5);
	std::cout << std::get<0>(User_cat) << std::endl;
	std::cout << std::get<1>(User_cat) << std::endl;
	std::cout << std::get<2>(User_cat) << std::endl;
	std::cout << std::get<3>(User_cat) << std::endl;
	std::cout << std::get<4>(User_cat) << std::endl;
	std::cout << std::get<5>(User_cat) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	/* tuple example */
	auto t = make_tuple(1, 2, 3);

	int x = get<0>(t);
	int y = get<1>(t);
	int z = get<2>(t);

	cout << x << ' ' << y << ' ' << z << '\n';    //1 2 3

	x = y = z = 0;
	cout << x << ' ' << y << ' ' << z << '\n';    //0 0 0

	std::tie(x, y, z) = t;
	cout << x << ' ' << y << ' ' << z << '\n';    //1 2 3

	x = y = z = 0;
	std::tie(x, y, ignore) = t;    //세번째 자리는 무시 키워드 : ignore
	cout << x << ' ' << y << ' ' << z << '\n';    //1 2 0
	/* end tuple example */

	return 0;
}
#endif

#ifdef MAP

/*
m.begin();
m.end();
m.cbegin();				// read only
m.cend();				// read only
m.rbegin();
m.rend();
m.clear();
m.count(k);
m.empty();
m.insert(k);			//k는 pair 객체입니다.
m.insert(iter, k);
m.erase(start, end);
m.find(k);
m2.swap(m1);
m.upper_bound(k);
m.lower_bound(k);
m.equal_range(k);
m.value_comp();
m.key_comp();
m.size();
m.max_size();
*/

void practice_1()
{
	std::cout << "practice 1 --------------------------------------" << std::endl;

	/* 기본 예제 */
	std::map<std::string, int> _map;

	// 추가
	_map.insert(std::pair<std::string, int>("1", 1));
	_map["2"] = 2;


	// 가져오기
	int _1 = _map["1"];
	int _2 = _map.at("2");
	std::cout << _map.at("1") << std::endl;
	std::cout << _map["2"] << std::endl;

	// 수정
	_map["1"] = 2;
	_map.at("2") = 3;
	std::cout << _map.at("1") << std::endl;
	std::cout << _map["2"] << std::endl;

	// 삭제
	_map.erase("1");
	_map.erase(_map.find("2"));

	// + 추가
	_map.insert(std::make_pair("1", 11));
	_map.insert(std::make_pair<std::string, int>("2", 22));
	std::cout << _map.at("1") << std::endl;
	std::cout << _map["2"] << std::endl;
	/* end 기본 예제 */

	std::map<int, std::string> m;

	m.insert(std::pair<int, std::string>(40, "me"));
	m.insert(std::pair<int, std::string>(35, "Show"));
	m.insert(std::pair<int, std::string>(10, "Dok2"));
	m.insert(std::pair<int, std::string>(90, "6"));
	m.insert(std::pair<int, std::string>(65, "money"));
	m.insert(std::pair<int, std::string>(20, "ZICO"));
	m.insert(std::pair<int, std::string>(50, "the"));

	std::map<int, std::string>::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++) {
		std::cout << "[" << iter->first << "," << iter->second << "]" << " ";
	}
	std::cout << std::endl;

	for (iter = m.begin(); iter != m.end(); iter++) {
		std::cout << "[" << (*iter).first << "," << (*iter).second << "]" << " ";
	}

	std::cout << std::endl;
	std::cout << "end pracitc 1 --------------------------------------" << std::endl;
}

void practice_2()
{
	std::cout << "practice 2 --------------------------------------" << std::endl;

	std::map<int, int> m;

	m[9] = 109;
	m[3] = 103;
	m[13] = 113;
	m[15] = 115;
	m[1] = 101;
	m[7] = 107;
	m[5] = 105;
	m[11] = 111;
	std::map<int, int >::iterator iter;

	for (iter = m.begin(); iter != m.end(); iter++) {
		std::cout << "[" << iter->first << ", " << iter->second << "]" << " ";
	}
	std::cout << std::endl;

	m[11] = 999;
	m[1] = 999;

	//변경 후 순회 
	for (iter = m.begin(); iter != m.end(); iter++) {
		std::cout << "[" << iter->first << ", " << iter->second << "]" << " ";
	}
	std::cout << std::endl;

	//사이즈 출력 
	std::cout << "size : " << m.size() << std::endl;

	std::cout << std::endl;
	std::cout << "end practice 2 --------------------------------------" << std::endl;

}

int main()
{
	practice_1();
	std::cout << std::endl;
	practice_2();

	/* map example */
	std::map<std::string, int> mapTest{ { "Abc",10 }, { "Bcd", 20 }};

	for (const auto value : mapTest) {
		std::cout << value.first << " " << value.second << std::endl;
	}

	/* end map example */
	return 0;

}
#endif

#ifdef MULTIMAP
#include <iostream>
#include <queue>
#include <vector>
#include <deque>
#include <map>
#include <windows.h>

/* ostream_iterator 에서 std::pair를 이용하는 방안 */
namespace std
{
	template <class T1, class T2>
	inline ostream& operator << (ostream& strm, const pair<T1, T2>& p)
	{
		strm << p.second;
		return strm;
	}
}


int main(void)
{

	std::multimap<std::string, size_t> people{ {"Ann", 25}, {"Bill", 46} ,{"Jack", 77}, {"Jack", 32}, {"Jill", 32}, {"Ann", 35} , {"Jack", 45} };

	std::string name{ "Bill" };
	auto iter = people.find(name);
	if (iter != std::end(people)) std::cout << name << " is " << iter->second << std::endl;
	iter = people.find("Ann");
	if (iter != std::end(people)) std::cout << iter->first << " is " << iter->second << std::endl;

	// equal_range() 동등한 키를 갖는 원소 범위를 pair 객체로 캡슐화한 반복자 쌍을 반환
	std::cout << "equal_range() 사용 시 " << std::endl;
	auto pr = people.equal_range("Ann");
	if (pr.first != std::end(people))
	{
		for (auto iter = pr.first; iter != pr.second; iter++)
			std::cout << iter->first << " is " << iter->second << std::endl;
	}

	std::cout << "lower_bound() , upper_bound() 사용 시" << std::endl;
	// lower_bound()
	auto iter1 = people.lower_bound("Ann");
	// upper_bound()
	auto iter2 = people.upper_bound("Ann");
	std::vector<std::string> iter_name;
	iter_name.push_back(std::string("lower_bound"));	// 먼저 Map에 들어가 있는 iterator
	iter_name.push_back(std::string("upper_bound"));	// 가장 늦게 Map에 들어가 있는 iterator
	int index = 0;
	if (iter1 != std::end(people))
	{
		for (auto iter = iter1; iter != iter2; iter++)
		{
			std::cout << iter_name.at(index) << " : " << iter->first << " is " << iter->second << std::endl;
			index++;
		}
	}
	// count 사용법
	std::cout << "Ann 의 갯수 : " << people.count("Ann") << std::endl;

	// distance 사용법
	std::string key = "Jack";
	std::cout << "Jack's distance : " << std::distance(people.lower_bound(key), people.upper_bound(key)) << std::endl;	// Jack 은 3개

	// hint 이용한 원소 추가 방안 - 중복 원소는 LIFO로 추가됨
	std::cout << "hint를 이용한 원소 추가 방안" << std::endl;
	std::string type = "Jack";
	size_t old = 64;
	auto iter_for_hint = people.lower_bound(type);
	if (iter_for_hint != std::end(people))
	{
		people.emplace_hint(iter_for_hint, type, old);
	}
	else
	{
		people.emplace(type, old);
	}
	std::copy(people.begin(), people.end(), std::ostream_iterator<std::pair<std::string, size_t>>(std::cout, " "));
	std::cout << std::endl;


	// people 모두 출력하기
	std::cout << "people 모두 출력" << std::endl;
	auto iter_all = std::begin(people);
	while (iter_all != std::end(people))
	{
		// equal_range(key) : 해당 key 모두 접근 pair(처음, 끝)
		auto pr = people.equal_range(iter_all->first);
		std::cout << "\nPeople name " << iter_all->first << " are \n";
		for (auto p = pr.first; p != pr.second; p++)
		{
			std::cout << " " << p->second;
		}
		std::cout << std::endl;
		iter_all = pr.second;
	}

	// 원소 삭제 방안
	//people.erase("Jack");
	//people.erase(iter_all);
	//people.erase(people.begin(), people.end());
}
#endif

#ifdef MOVE_SEMENTICS

void func_nn(int&& n)
{
	printf("%d\n", n);
}

void func_n(int& n)
{
	printf("%d\n", n);
}

int main()
{
	int n = 3;
	func_nn(3);
	func_n(n);
	func_nn(std::forward<int>(n));
	return 0;
}

#endif

#ifdef CLASS_VIRTUAL
class Shape {
public :
	virtual void draw() { std::cout << "Shape" << std::endl; }
};

class Elipse : public Shape {
public :
	virtual void draw() { std::cout << "Elipse" << std::endl; }
};

class Rectangle : public Shape {
public :
	virtual void draw() { std::cout << "Rectangle" << std::endl; }
};

class A {
public:
	virtual void Draw() { std::cout << "A" << std::endl; }
};

class B : public A {
public:
	virtual void Draw() { std::cout << "B" << std::endl; }
};

int main()
{
	Shape* shape[2] = { new Elipse, new Rectangle };
	shape[0]->draw();
	shape[1]->draw();
	
	std::cout << std::endl;
	std::cout << std::endl;

	B b;
	A& a = b;
	a.Draw();

}
#endif

#ifdef OPERATOR
class NUMBOX
{
private:
	int	num1, num2;
	double dnum1, dnum2, dnum3;
public:
	NUMBOX(int a, int b) : num1(a), num2(b) { }
	NUMBOX(double a, double b, double c) : dnum1(a), dnum2(b), dnum3(c) { }
	void ShowNumber()
	{
		std::cout << "num1 : " << num1 << " num2 : " << num2 << std::endl;
	}
	void dShowNumber()
	{
		std::cout << "dnum1 : " << dnum1 << " dnum2 : " << dnum2 << " dnum3 : " << dnum3 << std::endl;
	}
	NUMBOX operator+(NUMBOX& ref)
	{
		return NUMBOX(num1 + ref.num1, num2 + ref.num2);
	}
	NUMBOX operator+(int ref)
	{
		return NUMBOX(num1 + ref, num2 + ref);
	}
	NUMBOX operator*(NUMBOX& ref)
	{
		return NUMBOX(dnum1 * ref.dnum1, dnum2 * ref.dnum2, dnum3 * ref.dnum3);
	}
	int getNum1() { return num1; }
	int getNum2() { return num2; }
	double getDnum1() { return dnum1; }
	double getDnum2() { return dnum2; }
	double getDnum3() { return dnum3; }
};

int main()
{
	NUMBOX nb1(10, 20);
	NUMBOX nb2(30, 40);
	NUMBOX nbResult = nb1 + nb2;
	nbResult.ShowNumber();
	nbResult = nb1 + 55;
	nbResult.ShowNumber();

	NUMBOX db1(10.0, 20.0, 30.0);
	NUMBOX db2(3.0, 4.0, 5.0);
	nbResult = db1 * db2;
	nbResult.dShowNumber();
	nbResult = nb1 + nb2;
	nbResult.ShowNumber();
	nbResult.dShowNumber();

	std::cout << nbResult.getNum1() << std::endl;
	std::cout << nbResult.getDnum1() << std::endl;
	
}

#endif


// explicit

// mutable

// template 사용법

// class const
#ifdef CLASS_CONST
template<typename T>
class Array
{
private:
	T* elements;
	size_t count;

public:
	// explicit 키워드는 자신이 원하지 않은 형변환이 일어나지 않도록 제한하는 키워드
	explicit Array(size_t arraySize);
	Array(const Array& other);
	Array(Array&& other);
	virtual ~Array();
	T& operator[](size_t index);
	const T& operator[](size_t index) const; // 리턴값 const, 내부 맴버 const(즉, 이 함수내부에서 맴버 변수들 변경 불가)
	Array& operator=(const Array& rhs);
	Array& operator=(Array&& rhs);
	size_t size() { return count; }
};

// function-try-contructor
template<typename T>
Array<T>::Array(size_t arraySize) try : elements{ new T[arraySize] }, cout{ arraySize }
{
	for (size_t i{}; i < count; i++)
	{
		elements[i] = array.elements[i];
	}
}
catch (std::bad_alloc&/*const std::exception& e*/)
{
	std::cerr << "Array 생성자에서 메모리 할당 실패." << std::endl;
	rethrow e;
}


/*
// function-try-contructor
class SafeExceptionDuringCtor
{
public:
	SafeExceptionDuringCtor() try
		: _member1(NULL)
		, invalidMember(NULL)
		, _member2(NULL) {
		_member1 = new Member1("1st");
		_invalidMember = new InvalidMember1("out");
		_member2 = new Member1("last");
	}
	catch (std::exception&) {
		if (_member1) delete _member1;
		if (_invalidMember) delete invalidMember;
		if (_member2) delete _member2;
	}
private:
	Member1* _member1;
	InvalidMember1* _invalidMember;
	Member2* _member2;
};
*/
#endif

#ifdef ALLOCATOR


int main(void)
{
	std::allocator<std::string> _allocator;
	std::string * data;
	data = _allocator.allocate(4);
	std::string* avail;
	avail = data + 4;
	std::uninitialized_fill(data, avail, "ABCDEFGHIJK");
	std::string* test = _allocator.allocate(4);
	std::uninitialized_copy(data, avail, test);

	*(data + 1) = "IJK";
	*(data + 2) = "TKD";
	*(data + 3) = "FTS";

	std::cout << *data << std::endl;
	std::cout << *(data+1) << std::endl;
	std::cout << *(data + 2) << std::endl;
	std::cout << *(data + 3) << std::endl;
	std::cout << *test << std::endl;
	std::cout << *(test + 1) << std::endl;
	std::cout << *(test + 2) << std::endl;
	std::cout << *(test + 3) << std::endl;

	std::cout << data << std::endl;
	std::cout << avail << std::endl;
	std::cout << test << std::endl;

	for (auto i = data; i != avail; i++)
	{
		_allocator.destroy(i);
		//std::cout << *i << std::endl;
	}
	_allocator.deallocate(data, 4);
	_allocator.deallocate(test, 4);
	//_allocator.deallocate(data, 4);
	//_allocator.deallocate(test, 4);

	std::cout << "hi" << std::endl;

}


#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstddef>
#include <memory>
#include <stdexcept>
#include <string>

template < typename T >
class FixedVec {
public:
	typedef         T* iterator;
	typedef const   T* const_iterator;
	typedef         T& reference;
	typedef const   T& const_reference;
	typedef         T               value_type;
	typedef         size_t          size_type;

	FixedVec() { create(); }                                                ///< default construct
	explicit FixedVec(size_type n, const T& t = T()) { create(n, t); }		///< construct overloading
	FixedVec(const FixedVec& fv) { create(fv.begin(), fv.end()); }			///< copy construct
	virtual ~FixedVec() { destroy(); }                                      ///< destruct

	//! operator overloading
	FixedVec& operator=   (const FixedVec&);								///< assignment
	value_type& operator[]  (size_type i) { return data[i]; }				///< operator []
	const value_type& operator[]  (size_type i) const { return data[i]; }	///< const T operator[]

	//! public method
	size_type           size()  const { return avail - data; }				///< return value is to allocate size of FixedVec
	iterator            begin() { return data; }							///< data iterator
	const_iterator      begin()  const { return data; }						///< data const_iterator
	iterator            end() { return avail; }								///< avail iterator
	const_iterator      end()  const { return avail; }						///< avail const_iterator

	void                clear() { destroy(); }								///< same destroy
	bool                empty()  const { return data == avail; }			///< empty
private:
	iterator            data;                                               ///< first element in the FixedVec
	iterator            avail;                                              ///< (one past) the last element in the FixedVec
	// std::allocator 는 new와 다르게 어느 정도만 해제 할 수 있다.
	// ex) std::deallocator(p, n) p에서 n개의 메모리 해제 가능
	std::allocator<T>   alloc;                                              ///< object to handle memory allocation

	void                create();											///< memory allocation initialize
	void                create(size_type, const T&);						///< memory allocation by size and value
	void                create(const_iterator, const_iterator);				///< memory allocation by iterator
	void                Swap(FixedVec&);									///< container data swapping
	void                destroy();											///< memory deallocation
};

template < typename T >
FixedVec< T >& FixedVec< T >::operator= (const FixedVec< T >& rhs)
{
	FixedVec< T > temp(rhs);
	Swap(temp);
	return *this;
}

template < typename T >
void FixedVec< T >::create()
{
	data = avail = 0;
}

template < typename T >
void FixedVec< T >::create(size_type n, const T& val)
{
	data = alloc.allocate(n);
	avail = data + n;
	// std::unitialized_fill(data, avail, val) : 초기화 함수
	// data : begin iterator
	// avail : end iterator
	// val : 채울 변수
	std::uninitialized_fill(data, avail, val);
}

template < typename T >
void FixedVec< T >::create(const_iterator i, const_iterator j)
{
	data = alloc.allocate(j - i);
	// std::unitialized_fill_copy = memcpy
	avail = std::uninitialized_copy(i, j, data);
}

template < typename T >
void FixedVec< T >::destroy()
{
	if (data) {
		iterator it = avail;
		while (it != data)
			alloc.destroy(--it);
		alloc.deallocate(data, avail - data);
	}

	data = avail = 0;
}

template < typename T >
void FixedVec< T >::Swap(FixedVec< T >& rhs)
{
	// std::swap 주어진 값 교환 ex) alloc 과 rhs.alloc을 교환함
	std::swap(alloc, rhs.alloc);
	std::swap(data, rhs.data);
	std::swap(avail, rhs.avail);
}


template< typename T >
void fnPrintContainerElement(const T& t, const std::string title = "Container")
{
	typedef typename T::value_type value_type;
	std::cout << title << " : ";
	//std::copy(t.begin(), t.end(), std::ostream_iterator< value_type >(std::cout, " "));
	std::copy(t.begin(), t.end(), std::ostream_iterator<value_type>(std::cout, " "));
	std::cout << std::endl;
}

int main()
{
	try {
		FixedVec< std::string > fvecStrA;
		// allocator 사용
		FixedVec< std::string > fvecStrB(15, "B");
		// allocator 사용
		FixedVec< std::string > fvecStrC(20, "C");

		if (fvecStrA.empty()) {
			std::cout << "fvecStrA is empty" << std::endl;
		}

		fnPrintContainerElement(fvecStrA, "Fixed Vector A");
		
		FixedVec< std::string >::size_type sz = 10;
		fvecStrA = FixedVec< std::string >(sz, "A");
		fnPrintContainerElement(fvecStrA, "Fixed Vector A");

		fvecStrA = fvecStrB;
		fvecStrB = fvecStrC;

		std::cout << "fvecStrC size = " << fvecStrC.size() << std::endl;
		for (size_t i = 0; i < fvecStrC.size(); i++) {
			fvecStrC[i] = "TT";
		}

		fnPrintContainerElement(fvecStrA, "Fixed Vector A");
		fnPrintContainerElement(fvecStrB, "Fixed Vector B");
		fnPrintContainerElement(fvecStrC, "Fixed Vector C");

		std::cout << std::endl;
		std::cout << "fvecStrA size = " << fvecStrA.size() << std::endl;
		std::cout << "fvecStrB size = " << fvecStrB.size() << std::endl;
		std::cout << "fvecStrC size = " << fvecStrC.size() << std::endl;
		
	}
	catch (const std::exception& error) {
		std::cerr << error.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	catch (...) {
		std::cerr << "Unknown error precess halted." << std::endl;
		std::exit(EXIT_FAILURE);
	}

	return EXIT_SUCCESS;
}

#endif

#ifdef ACCUMULATE_MOVE
#include <iostream>
#include <vector>
#include <numeric>
#include <string>
#include <functional>

int main()
{
	std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	int sum = std::accumulate(v.begin(), v.end(), 0);

	int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());

	auto dash_fold = [](std::string a, int b) {
		// std::move(value) value를 Lvalue -> Rvalue  즉, value를 복사가 아닌 소유권을 넘겨줌\
		// std::vector 에서 push_back 을 이용할 때 std::move를 사용하면 성능 상승이 됨
		// ex) stringVector.push_back(std::move(value))
		return std::move(a) + '-' + std::to_string(b);
	};

	std::string s = std::accumulate(std::next(v.begin()), v.end(),
		std::to_string(v[0]), // start with first element
		dash_fold);

	// Right fold using reverse iterators
	std::string rs = std::accumulate(std::next(v.rbegin()), v.rend(),
		std::to_string(v.back()), // start with last element
		dash_fold);

	std::cout << "sum: " << sum << '\n'
		<< "product: " << product << '\n'
		<< "dash-separated string: " << s << '\n'
		<< "dash-separated string (right-folded): " << rs << '\n';
}
#endif

#ifdef SHARED_PTR_N_WEAK_PTR

#include <iostream>
#include <memory>
/*
// 오류 발생 코드
class A {
	int* data;

public:
	A() {
		data = new int[100];
		std::cout << "자원을 획득함!" << std::endl;
	}

	~A() {
		std::cout << "소멸자 호출!" << std::endl;
		delete[] data;
	}

	std::shared_ptr<A> get_shared_ptr() { return std::shared_ptr<A>(this); }
};

int main() {
	std::shared_ptr<A> pa1 = std::make_shared<A>();
	std::shared_ptr<A> pa2 = pa1->get_shared_ptr();	// 오류 발생 코드 라인

	std::cout << pa1.use_count() << std::endl;
	std::cout << pa2.use_count() << std::endl;
}
*/

#include <iostream>
#include <memory>

class A : public std::enable_shared_from_this<A> {
  int *data;

 public:
  A() {
	data = new int[100];
	std::cout << "자원을 획득함!" << std::endl;
  }

  ~A() {
	std::cout << "소멸자 호출!" << std::endl;
	delete[] data;
  }

  std::shared_ptr<A> get_shared_ptr() { return shared_from_this(); }
};

int main() {
  std::shared_ptr<A> pa1 = std::make_shared<A>();
  std::shared_ptr<A> pa2 = pa1->get_shared_ptr();

  std::cout << pa1.use_count() << std::endl;
  std::cout << pa2.use_count() << std::endl;
}



// shared_ptr 예제
#include <iostream>
#include <memory>

void f1(std::shared_ptr<int> &s1)
{
	int *num1 = new int(10);
	s1.reset(num1);

	std::cout << "in function : " << s1.use_count() << " " << *s1 << std::endl;
}

void f2(std::shared_ptr<int> &s2)
{
	int num2 = 20;
	s2.reset(&num2);  // (1)

	std::cout << "in function : " << s2.use_count() << " " << *s2 << std::endl;
}

int main()
{
	std::shared_ptr<int> s1;

	f1(s1);

	std::cout << "out of function : " <<  s1.use_count() << " " << *s1 << std::endl;


	std::shared_ptr<int> s2;

	f2(s2);

	std::cout << "out of function : " << s2.use_count() << " " << *s2 << std::endl; // (2)

	return 0;
}

#include <iostream>
#include <memory>

typedef struct
{
	int n;
	double dTrick;
	double dDrive;
	double dRight;
	double dLeft;
	double dt;
}stPoint;

int main()
{
	//std::shared_ptr<stPoint> stPointTest = std::make_shared<stPoint>();
	std::shared_ptr<stPoint> stPointTestSharedPtr(new stPoint[10], std::default_delete<stPoint[]>());
	//std::shared_ptr<stPoint> stPointTestSharedPtr(new stPoint[10], [](stPoint* p) {delete[] p; });

	stPointTestSharedPtr.get()[0].n = 10;
	stPointTestSharedPtr.get()[1].n = 20;
	stPointTestSharedPtr.get()[2].n = 30;
	stPointTestSharedPtr.get()[3].n = 40;

	std::cout << stPointTestSharedPtr.get()[0].n << std::endl;
	std::cout << stPointTestSharedPtr.get()[1].n << std::endl;
	std::cout << stPointTestSharedPtr.get()[2].n << std::endl;
	std::cout << stPointTestSharedPtr.get()[3].n << std::endl;

	stPointTestSharedPtr.reset();
	stPointTestSharedPtr.get()[0].n = 10;
	stPointTestSharedPtr.get()[1].n = 20;
	stPointTestSharedPtr.get()[2].n = 30;
	stPointTestSharedPtr.get()[3].n = 40;
	std::cout << stPointTestSharedPtr.get()[0].n << std::endl;
	std::cout << stPointTestSharedPtr.get()[1].n << std::endl;
	std::cout << stPointTestSharedPtr.get()[2].n << std::endl;
	std::cout << stPointTestSharedPtr.get()[3].n << std::endl;

	std::unique_ptr<stPoint[]> stPointTestUniquePtr(new stPoint[10]);

}

// WEAK_PTR
// 기존 shared_ptr 은 메모리가 연결되어 있으면 끊어져도 소멸자가 호출되지 않지만
// weak_ptr 의 lock을 이용해서 연결하게 된다면 하나만 메모리 해제 되어도 소멸자가 호출되어 버림.
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class A {
  std::string s;
  std::weak_ptr<A> other;

public:
	A(const std::string& s) : s(s) { std::cout << "자원을 획득함!" << std::endl; }

	~A() { std::cout << "소멸자 호출!" << std::endl; }

	void set_other(std::weak_ptr<A> o) 
	{ 
		other = o; 
	}
	void access_other() 
	{
		std::shared_ptr<A> o = other.lock();
		if (o) 
		{
			std::cout << "접근 : " << o->name() << std::endl;
		} 
		else 
		{
			std::cout << "이미 소멸됨 ㅠ" << std::endl;
		}
	}
	std::string name() { return s; }
};

int main() 
{
	std::vector<std::shared_ptr<A>> vec;
	vec.push_back(std::make_shared<A>("자원 1"));
	vec.push_back(std::make_shared<A>("자원 2"));

	vec[0]->set_other(vec[1]);
	vec[1]->set_other(vec[0]);

	// pa 와 pb 의 ref count 는 그대로다.
	std::cout << "vec[0] ref count : " << vec[0].use_count() << std::endl;
	std::cout << "vec[1] ref count : " << vec[1].use_count() << std::endl;

	// weak_ptr 로 해당 객체 접근하기
	vec[0]->access_other();

	// 벡터 마지막 원소 제거 (vec[1] 소멸)
	vec.pop_back();
	vec[0]->access_other();  // 접근 실패!
}

#include <iostream>
#include <memory>
#include <vector>

template<typename n>
class A : public std::enable_shared_from_this<A<n>> 
{
private:
	std::string s;
	std::weak_ptr<A<n>> other;
	n data;

public:
	A(const std::string& s) : s(s) { std::cout << name() << " 생성자" << std::endl; }
	~A() { std::cout << name() << " 소멸자" << std::endl; }
	
	void set_other(std::weak_ptr<A<n>> o)
	{
		other = o;
	}

	n acess_other()
	{
		std::shared_ptr<A<n>> o = other.lock();
		if(o)
		{
			// 접근
			std::cout << name() << " 접근" << std::endl;
			return o.get()->get_data();
		}
		else
		{
			//소멸
			std::cout << name() << " 소멸" << std::endl;
		}
	}
	n& get_data() { return data; }
	std::string name() { return s; }
	std::shared_ptr<A<n>> get_shared_ptr() { return this.shared_from_this(); }
};
int main()
{
	std::vector<std::shared_ptr<A<int>>> vecPtr;
	vecPtr.push_back(std::make_shared<A<int>>("자원 1"));
	vecPtr.push_back(std::make_shared<A<int>>("자원 2"));

	vecPtr.at(0)->get_data() = 12;
	vecPtr.at(1)->get_data() = 13;
	
	//std::cout << vecPtr.at(0)->get_data() << std::endl;
	
	std::vector<std::shared_ptr<A<int>>>::iterator iter;
	
	for (iter = vecPtr.begin(); iter != vecPtr.end(); iter++)
	{
		//std::cout << iter->get()->name() << std::endl;
		std::cout << iter->get()->get_data() << std::endl;
	}

	std::shared_ptr<A<int>> temp(std::make_shared<A<int>>("자원 2 연결"));
	temp->set_other(vecPtr[1]);
	temp->acess_other();
	
	std::cout << temp->acess_other() << std::endl;
	std::cout << vecPtr[1].use_count() << std::endl;
	vecPtr.pop_back();
	std::cout << temp.use_count() << std::endl;

	std::cout << temp->get_data() << std::endl;
	//vecPtr.pop_back();
	//std::cout << temp->get_data() << std::endl;
	//vecPtr[0]->acess_other();
	//vecPtr[1]->acess_other();
	
	//vecPtr[1].reset();
}

#endif

#if UNINITIALIZED_COPY
// uninitialized_copy_n example
#include <iostream>
#include <memory>
#include <string>

int main() {
	std::string numbers[] = { "one","two","three" };

	// get block of uninitialized memory:
	// 동적 할당 (first : 동적할당, second : 할당 갯수)
	std::pair <std::string*, std::ptrdiff_t> result = std::get_temporary_buffer<std::string>(3);

	if (result.second > 0) {

		std::uninitialized_copy_n(numbers, result.second, result.first);

		for (int i = 0; i < result.second; i++)
			std::cout << result.first[i] << ' ';
		std::cout << '\n';
		// 메모리 해제
		std::return_temporary_buffer(result.first);
	}

	return 0;
}
#endif

#ifdef LAMBDA_FUNCTION
// Lambda Function
#include <iostream>
#include <memory>
#include <utility>
#include <string>
#include <functional>

int main() {

	/*
	* Lambda Function
	* [capture](params)->return
	* capture --------
	* =  : 모든 외부변수 복사
	* =, .... : 모든 외부변수 복사와 가변인자 템플릿
	* =, initializer : 모든 외부변수 복사 및 변수 초기화 기능
	* & : 모든 외붑녀수 참조
	* &, ... : 모든 외부변수 참조와 가변인자 템플릿
	* &, initializer : 모든 외붑녀수 참조 및 변수 초기화 기능
	* this : 해당 클래스의 변수 참조 기능
	* *this : 해당 클래스의 변수 복사 가능
	*/

	auto nData = [](double x, double y) -> double {return x * y; };
	std::cout << nData(3.0, 2.5) << std::endl;


	auto d = [](double value) { return value * value * value; };
	std::cout << d(4) << std::endl;
	int data[]{ 1, 2, 3, 4 };
	//change(std::begin(data), std::end(data), [](double value) {return value * value * value; });

	auto f1 = [](int a, int b) {                    //인라인화 OK!! , f1 변수 변경 불가
		return a + b;
	};

	int(*f2)(int, int) = [](int a, int b) {            //인라인화 Fail!!
		return a + b;
	};

	std::function<int(int, int)> f3 = [](int a, int b) {    //인라인화 Fail!!
		return a + b;
	};

}
#endif

#ifdef TRANSFORM
// std::transform()
#include <iostream>
#include <memory>
#include <utility>
#include <string>
#include <functional>
#include <algorithm>

class Root
{
public:
	double operator()(double x) { return std::sqrt(x); };
};

int main() {


	double data[]{ 1.5, 2.5, 3.5, 4.5, 5.5 };
	Root root;
	std::cout << "Square roots are:" << std::endl;
	std::transform(std::begin(data), std::end(data), std::ostream_iterator<double>(std::cout, " "), root);

	std::cout << "\n\nCubes are: " << std::endl;
	std::transform(std::begin(data), std::end(data),
		std::ostream_iterator<double>(std::cout, " "), [](double x) { return x * x * x; });

	// std::function<> 타입의 변수를 인수로 사용하기
	// std::function<리턴값(인풋값)>
	std::function<double(double)> op{ [](double x) { return x * x; } };
	std::cout << "\n\nSquares are:" << std::endl;
	std::transform(std::begin(data), std::end(data),
		std::ostream_iterator<double>(std::cout, " "), op);

	std::cout << "\n\n4th powers are:" << std::endl;
	std::transform(std::begin(data), std::end(data),
		std::ostream_iterator<double>(std::cout, " "), [&op](double x) { return op(x) * op(x); });
	std::cout << std::endl;

}
#endif

#ifdef VECTOR
// Vector

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iterator>
using std::string;
using std::vector;

int main(void)
{
	vector<string> words;
	words.reserve(10);
	std::cout << "단어는 공백으로 구분해서 입력하세요. 종료하려면 다음 줄에서 Ctrl+Z를 입력하세요:" << std::endl;
	std::copy(std::istream_iterator<string> {std::cin}, std::istream_iterator<string> {}, std::back_inserter(words));

	std::cout << "정렬을 시작합니다." << std::endl;
	bool out_of_order{ false };
	auto last = std::end(words);
	while (true)
	{
		for (auto first = std::begin(words) + 1; first != last; ++first)
		{
			if (*(first - 1) > *first)
			{
				std::swap(*first, *(first - 1));
				out_of_order = true;
			}
		}
		if (!out_of_order)
			break;
		out_of_order = false;
	}

	// 정렬된 벡터를 출력
	std::cout << "오름차순으로 정렬된 단어:" << std::endl;
	std::copy(std::begin(words), std::end(words), std::ostream_iterator<string>{std::cout, " "});
	std::cout << std::endl;

	vector<string> words_copy{ std::make_move_iterator(std::begin(words)), std::make_move_iterator(std::end(words)) };
	std::cout << "\nwords에서 원소들을 이동한 후에 words_copy의 내용:" << std::endl;
	std::copy(std::begin(words_copy), std::end(words_copy), std::ostream_iterator<string> {std::cout, " "});
	std::cout << std::endl;

	// words 벡터의 원소들에 무슨 일이 일어났는지 알아보기 ...
	std::cout << "\nwords 벡터는 원소 " << words.size() << "개를 갖고 있습니다.\n";
	if (words.front().empty())
		std::cout << "첫 번째 원소는 빈 문자열 객체입니다." << std::endl;

	std::cout << "첫 번째 원소는 \"" << words.front() << "\"입니다." << std::endl;
	
	std::string temp("velelelelelo");
	words.emplace(std::begin(words), temp);

	vector<string> words_copy{ std::make_move_iterator(std::begin(words)), std::make_move_iterator(std::end(words)) };
	std::cout << "\nwords에서 원소들을 이동한 후에 words_copy의 내용:" << std::endl;
	std::copy(std::begin(words_copy), std::end(words_copy), std::ostream_iterator<string> {std::cout, " "});
	std::cout << std::endl;
}
#endif

#ifdef FORWARD_LIST
// Forward_list
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <forward_list>
#include <utility>

int main(void)
{
	std::forward_list<int> data{ 10, 21, 43, 87, 175, 351 };
	auto iter = std::begin(data);
	for (; iter != data.end(); iter++)
	{
		std::cout << *iter << std::endl;
	}
	iter = std::begin(data);
	std::advance(iter, 3);
	std::cout << *iter << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	std::forward_list<std::string> my_words{ "three", "six", "eight" };
	std::forward_list<std::string> your_words{ "seven","four","nine" };
	//my_words.splice_after(my_words.before_begin(), your_words, your_words.before_begin());
	my_words.splice_after(my_words.before_begin(), your_words, your_words.before_begin(), your_words.end());
	std::copy(my_words.begin(), my_words.end(), std::ostream_iterator<std::string>(std::cout, " "));
	std::cout << std::endl;
	std::cout << std::endl;

}

#endif

#ifdef PRIORITY_QUEUE
#include <iostream>
#include <queue>
#include <vector>

class A
{
public:
	int m_priority;
	A(int _priority) : m_priority(_priority) { }
public:
	/* Example 1 */
	bool operator < (const A n) const { return n.m_priority < this->m_priority; }
};

/* Example 2*/
struct cmp {
	bool operator ()(A a, A b) {
		return a.m_priority < b.m_priority;
	}
};


int main(void)
{

	// Example 1
	std::cout << "Example 1" << std::endl;
	std::priority_queue<A> _queue;

	_queue.push(A(1));
	_queue.push(A(1));
	_queue.push(A(1));
	_queue.push(A(3));
	_queue.push(A(3));
	_queue.push(A(3));

	std::cout << _queue.top().m_priority << std::endl;
	_queue.pop();
	std::cout << _queue.top().m_priority << std::endl;
	_queue.pop();
	std::cout << _queue.top().m_priority << std::endl;
	_queue.pop();
	std::cout << _queue.top().m_priority << std::endl;
	_queue.pop();
	std::cout << _queue.top().m_priority << std::endl;
	_queue.pop();
	std::cout << _queue.top().m_priority << std::endl;
	_queue.pop();


	// Example 2
	std::cout << "\n\n\n" << std::endl;
	std::cout << "Example 2" << std::endl;
	std::priority_queue<A, std::vector<A>, cmp> _queue2;

	_queue2.push(A(1));
	_queue2.push(A(5));
	_queue2.push(A(7));
	_queue2.push(A(8));
	_queue2.push(A(12));
	_queue2.push(A(24));

	std::cout << _queue2.top().m_priority << std::endl;
	_queue2.pop();
	std::cout << _queue2.top().m_priority << std::endl;
	_queue2.pop();
	std::cout << _queue2.top().m_priority << std::endl;
	_queue2.pop();
	std::cout << _queue2.top().m_priority << std::endl;
	_queue2.pop();
	std::cout << _queue2.top().m_priority << std::endl;
	_queue2.pop();
	std::cout << _queue2.top().m_priority << std::endl;
	_queue2.pop();


	// 스마트 포인터 이용 ver
	auto comp = [](const std::shared_ptr<std::string>& wp1, const std::shared_ptr<std::string>& wp2) { return *wp1 > *wp2; };
	std::priority_queue<std::shared_ptr<std::string>, std::vector<std::shared_ptr<std::string>>, decltype(comp)> words1{ comp };

	words1.emplace(std::make_shared<std::string>("string1"));
	words1.emplace(std::make_shared<std::string>("string2"));
	words1.emplace(std::make_shared<std::string>("string3"));
	words1.emplace(std::make_shared<std::string>("string4"));

	std::cout << *words1.top() << std::endl;
	words1.pop();
	std::cout << *words1.top() << std::endl;
	words1.pop();

}
#endif

#ifdef VECTOR_PTR

struct B
{
	int a;
	float b;
	float c;
	float d;
};
/*
// shared_ptr 버전
float sum(std::shared_ptr<B> _p)
{
	std::shared_ptr<B> pData;
	pData = _p;
	std::cout << "use_count : " << pData.use_count() << std::endl;
	return pData->a + pData->b + pData->c + pData->d;
}
*/
/*
// weak_ptr 버전
float sum(std::weak_ptr<B> _p)
{
	std::shared_ptr<B> pData = _p.lock();
	std::cout << "use_count : " << pData.use_count() << std::endl;
	return pData->a + pData->b + pData->c + pData->d;
}
*/

// unique_ptr 버전
float sum(const std::unique_ptr<B>& _p)
{
	int a = _p->a;
	float b = _p->b;
	float c = _p->c;
	float d = _p->d;
	return a + b + c + d;
}

int main(void)
{
	B _b;
	_b.a = 4;
	_b.b = 5.0;
	_b.c = 6.4;
	_b.d = 7.4;
	std::vector<B*> data;
	data.push_back(new B(_b));
	_b.a = 5;
	_b.b = 6.4;
	_b.c = 7.8;
	_b.d = 8.9;
	data.push_back(new B(_b));

	for (std::vector<B*>::iterator iter = data.begin(); iter != data.end(); iter++)
	{
		std::cout << (**iter).a << std::endl;
		//delete* iter;
	}

	for (auto element : data)
	{
		std::cout << element->a << std::endl;
		//delete element;
	}

	// 메모리 삭제를 이용할 때 & 를 사용할것
	for (auto& elements : data)
	{
		std::cout << elements->a << std::endl;
		//delete elements;
	}

	/*
	// shared_ptr 버전
	while (true)
	{
		std::vector<std::shared_ptr<B>> bVector;

		_b.a = 237;
		_b.b = 236.54;
		_b.c = 4567.348;
		_b.d = 568.29;
		bVector.push_back(std::make_shared<B>(_b));
		_b.a = 333;
		_b.b = 333.33;
		_b.c = 3333.333;
		_b.d = 33333.3333;
		bVector.push_back(std::make_shared<B>(_b));
		_b.a = 44;
		_b.b = 4.44;
		_b.c = 444.4444;
		_b.d = 44.444;
		bVector.push_back(std::make_shared<B>(_b));

		// use_count 를 줄여줌
		for (auto& elements : bVector)
		{
			std::cout << elements->a << "\t" << elements->b << "\t" << elements->c << std::endl;
			std::cout << "SUM : " << sum(elements) << std::endl;
			//Sleep(10);
			//delete elements;
		}
		bVector.clear();
	}
	*/

	// unique_ptr 버전
	while (true)
	{
		std::vector<std::unique_ptr<B>> bVector;

		_b.a = 237;
		_b.b = 236.54;
		_b.c = 4567.348;
		_b.d = 568.29;
		bVector.push_back(std::make_unique<B>(_b));
		_b.a = 333;
		_b.b = 333.33;
		_b.c = 3333.333;
		_b.d = 33333.3333;
		bVector.push_back(std::make_unique<B>(_b));
		_b.a = 44;
		_b.b = 4.44;
		_b.c = 444.4444;
		_b.d = 44.444;
		bVector.push_back(std::make_unique<B>(_b));

		// use_count 를 줄여줌
		for (auto&& elements : bVector)
		{
			std::cout << elements->a << "\t" << elements->b << "\t" << elements->c << std::endl;
			std::cout << "SUM : " << sum(elements) << std::endl;
			//Sleep(10);
			//delete elements;
		}
		bVector.clear();
	}
}
#endif

#ifdef HASH_TABLE
#include <iostream>
#include <queue>
#include <vector>
#include <deque>
#include <map>
#include <functional>
#include <windows.h>

struct nStruct
{
	int n;
	double x;
	double y;
	double z;
};

int main()
{
	// 정수 해싱
	std::hash<int> hash_int;
	std::vector<int> n{ -5, -2, 2, 5, 10 };
	std::vector<int> n_to_hash{ 0, 0 ,0, 0, 0 };

	std::transform(std::begin(n), std::end(n), n_to_hash.begin(), hash_int);
	std::cout << std::endl;
	std::copy(std::begin(n_to_hash), std::end(n_to_hash), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	std::transform(std::begin(n), std::end(n), std::back_inserter(n_to_hash), hash_int);
	std::cout << std::endl;
	std::copy(std::begin(n_to_hash), std::end(n_to_hash), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	std::cout << std::endl;

	// 포인터 해싱
	std::cout << "Pointer Hash" << std::endl;
	std::hash<nStruct*> hash_struct;
	nStruct _nStruct;
	_nStruct.n = 3;
	_nStruct.x = 3.25243;
	_nStruct.y = 4.32323;
	_nStruct.z = 5.21678;
	std::cout << "Hash value = " << hash_struct(&_nStruct) << std::endl;
}

#endif

#ifdef SORT
#include<algorithm>
#include<vector>
#include<iostream>

int main()
{
	std::vector<int> numbers{ 99, 77, 33, 33, 66, 22, 11, 44, 88 };
	std::sort(std::begin(numbers), std::end(numbers), std::greater<int>());
	std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(std::cout, " "));

	std::cout << std::endl;
	std::cout << std::distance(numbers.begin(), numbers.end()) << std::endl;

	std::cout << "numbers is " << (std::is_sorted(numbers.begin(), numbers.end()) ? "" : " not ") << "sorted" << std::endl;
	std::copy(std::begin(numbers), std::is_sorted_until(std::begin(numbers), std::end(numbers)), std::ostream_iterator<int>(std::cout, " "));
}
#endif

#ifdef STABLE_SORT
#include<algorithm>
#include<vector>
#include<iostream>

int main()
{
	std::vector<int> numbers{ 22, 7, 93, 45, 19, 56, 88, 12, 8, 7, 15, 10 };
	// std::sort 도 가능 하지만 
	// std::sort 에 같은 값이 있으면 어떤값이 먼저 나올지 예측 불가
	// 하지만 std::stable_sort는 같은값이 있으면 컨테이너 앞쪽에 있는 값이 먼저 나오게 됨.
	std::stable_sort(std::begin(numbers), std::end(numbers), [](const std::string& s1, const std::string& s2) {return s1.back() < s2.back(); }); 
	std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<std::string>(std::cout, " "));

	std::cout << std::endl;
	std::cout << std::distance(numbers.begin(), numbers.end()) << std::endl;

	std::cout << "numbers is " << (std::is_sorted(numbers.begin(), numbers.end()) ? "" : " not ") << "sorted" << std::endl;
	std::copy(std::begin(numbers), std::is_sorted_until(std::begin(numbers), std::end(numbers)), std::ostream_iterator<int>(std::cout, " "));
}

#endif

#ifdef PARTIAL_SORT
#include<algorithm>
#include<vector>
#include<iostream>

int main()
{
	int count{ 5 };
	std::vector<int> numbers{ 22, 7, 93, 45, 19, 56, 88, 12, 8, 7, 15, 10 };
	// std::partial_sort 부분만 정렬하는 알고리즘 적용 시간상 더 빠름
	std::partial_sort(std::begin(numbers), std::begin(numbers) + count, std::end(numbers), std::greater<int>());
	std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(std::cout, " "));

	std::cout << std::endl;
	std::cout << std::distance(numbers.begin(), numbers.end()) << std::endl;

	std::cout << "numbers is " << (std::is_sorted(numbers.begin(), numbers.end()) ? "" : " not ") << "sorted" << std::endl;
	std::copy(std::begin(numbers), std::is_sorted_until(std::begin(numbers), std::end(numbers), std::greater<int>()), std::ostream_iterator<int>(std::cout, " "));

}
#endif

#ifdef PARTIAL_SORT_COPY
#include<algorithm>
#include<vector>
#include<iostream>

int main()
{
	int count{ 5 };
	std::vector<int> numbers{ 22, 7, 93, 45, 19, 56, 88, 12, 8, 7, 15, 10 };
	std::vector<int> result(count);
	// std::partial_sort 부분만 정렬하는 알고리즘 적용 시간상 더 빠름
	std::partial_sort_copy(std::begin(numbers), std::end(numbers), std::begin(result), std::end(result));
	std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, " "));

	std::cout << std::endl;
	std::cout << std::distance(numbers.begin(), numbers.end()) << std::endl;

	std::cout << "numbers is " << (std::is_sorted(numbers.begin(), numbers.end()) ? "" : " not ") << "sorted" << std::endl;
	std::copy(std::begin(numbers), std::is_sorted_until(std::begin(numbers), std::end(numbers)), std::ostream_iterator<int>(std::cout, " "));
}
#endif

#ifdef NTH_ELEMENT
#include<algorithm>
#include<vector>
#include<iostream>

int main()
{
	int count{ 5 };
	std::vector<int> numbers{ 22, 7, 93, 45, 19, 56, 88, 12, 8, 7, 15, 10 };
	// std::nth_element n번째 숫자가 정렬될 때까지만 정렬이 실시 된다.
	std::nth_element(std::begin(numbers), std::begin(numbers) + count, std::end(numbers));
	std::copy(numbers.begin(), numbers.end(), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	std::cout << std::distance(numbers.begin(), numbers.end()) << std::endl;

	std::cout << "numbers is " << (std::is_sorted(numbers.begin(), numbers.end()) ? "" : " not ") << "sorted" << std::endl;
	std::copy(std::begin(numbers), std::is_sorted_until(std::begin(numbers), std::end(numbers)), std::ostream_iterator<int>(std::cout, " "));
}
#endif

#ifdef MERGE
#include<algorithm>
#include<vector>
#include<iostream>

int main()
{
	int i;
	std::cout << "merge" << std::endl;
	std::vector<int> vi1, vi2, vi3;
	for (i = 1; i < 5; i++) vi1.push_back(i);
	for (i = 3; i < 9; i++) vi2.push_back(i);
	std::merge(vi1.begin(), vi1.end(), vi2.begin(), vi2.end(), std::back_inserter(vi3));
	std::copy(std::begin(vi3), std::end(vi3), std::ostream_iterator<int>(std::cout, " "));
	std::cout << "\n\n" << std::endl;

	// merge 후에는 정렬이 되어 있지 않는다
	// 그러므로 merge 된 지점을 기준(middle) 으로 inplace_merge를 해줌으로서 완전한 정리
	std::cout << "inplace_merge" << std::endl;
	std::vector<int> vi4;
	for (i = 1; i < 5; i++) vi4.push_back(i);
	for (i = 3; i < 9; i++) vi4.push_back(i);
	std::cout << "before inplcae_merge" << std::endl;
	std::copy(std::begin(vi4), std::end(vi4), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	inplace_merge(vi4.begin(), vi4.begin() + 4, vi4.end());
	std::cout << "after inplace_merge" << std::endl;
	std::copy(std::begin(vi4), std::end(vi4), std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;
	//std::dump("merge", vi3);
}
#endif

#ifdef FIND
#include<algorithm>
#include<vector>
#include<iostream>

int main()
{
	// std::find 사용법 (첫번째 원소만 찾기)
	std::vector<int> numbers{ 5, 46, -5, -6, 23, 17, 5, 9, 6, 5 };
	int value{ 23 };
	auto iter = std::find(std::begin(numbers), std::end(numbers), value);
	if (iter != std::end(numbers)) std::cout << value << " was found.\n";

	// std::find 사용법 (모든 원소 찾기)
	size_t count{ 0 };
	int five{ 5 };
	auto start_iter = std::begin(numbers);
	auto end_iter = std::end(numbers);
	while ((start_iter = std::find(start_iter, end_iter, five)) != end_iter)
	{
		++count;
		++start_iter;
	}
	std::cout << five << "was found " << count << " times." << std::endl;

	// std::find_if 사용법 (true 일 때만)
	value = 5;
	auto iter1 = std::find_if(std::begin(numbers), std::end(numbers), [value](int n) { return n > value; });
	if (iter1 != std::end(numbers)) std::cout << *iter1 << " was found greater than " << value << ".\n";

	// std::find_if_not 사용법 (false 일 때만)
	count = 0;
	five = 5;
	start_iter = std::begin(numbers);
	end_iter = std::end(numbers);
	while ((start_iter = std::find_if_not(start_iter, end_iter, [five](int n) {return n >= five; })) != end_iter)
	{
		std::cout << *start_iter << std::endl;
		++count;
		++start_iter;
	}
	std::cout << count << " elements were found that are not greater than " << five << std::endl;
	
	// std::find_first_of 사용법 (범위 찾기)
	std::string text{ "The world of searching" };
	std::string vowels{ "aeiou" };
	auto iter2 = std::find_first_of(std::begin(text), std::end(text), std::begin(vowels), std::end(vowels));
	if (iter2 != std::end(text)) std::cout << "We found '" << *iter2 << "'." << std::endl;

	// std::find_first_of 사용법 (범위 안 모두 찾기)
	std::string found{};
	for (auto iter3 = std::begin(text); (iter3 = std::find_first_of(iter3, std::end(text), std::begin(vowels), std::end(vowels))) != std::end(text); )
		found += *(iter3++);

	std::cout << "The characters \"" << found << "\" were found in text." << std::endl;

	// std::find_first_of (조건(true) 범위 찾기)
	std::vector<long> numbersL{ 64L, 46L, -65L, -128L, 121L, 17L, 35L, 9L, 91L, 5L };
	int factors[] = { 7, 11, 13 };
	auto iter4 = std::find_first_of(std::begin(numbersL), std::end(numbersL),
		std::begin(factors), std::end(factors),
		[](long v, long d) { return v % d == 0; });
	if (iter4 != std::end(numbersL)) std::cout << *iter4 << " was found." << std::endl;
	// + 모두 찾기
	std::vector<long> results;
	auto iter5 = std::begin(numbersL);
	while ((iter5 = std::find_first_of(iter5, std::end(numbersL),
		std::begin(factors), std::end(factors),
		[](long v, long d) {return v % d == 0; })) != std::end(numbersL))
		results.push_back(*iter5++);

	std::cout << results.size() << " values were found:\n";
	std::copy(std::begin(results), std::end(results), std::ostream_iterator<long>(std::cout, " "));
	std::cout << std::endl;

	// std::adjacent_find 연속해서 나오는 값 찾기
	std::string saying{ "Children should be seen and not heard." };
	auto iter6 = std::adjacent_find(std::begin(saying), std::end(saying));
	if (iter6 != std::end(saying))
		std::cout << "In the following text:\n\"" << saying << "\"\n'"
		<< *iter6 << "' is repeated starting at index position "
		<< std::distance(std::begin(saying), iter6) << std::endl;

	// 연속 두 숫자가 홀수인 값 찾기
	std::vector<long> numbers{ 64L,46L,-65L,-128L,121L,17L,35L,9L,91L,5L };
	auto iter7 = std::adjacent_find(std::begin(numbers), std::end(numbers), [](long n1, long n2) {return n1 % 2 && n2 % 2; });

	if (iter7 != std::end(numbers))
		std::cout << "The first pair of odd numbers is "
		<< *iter7 << " and " << *(iter1 + 1) << std::endl;

	// std::find_end() 같은 값 끝 위치 찾기
	std::string text{ "Smith, where Jones had had \"had\", had had \"had had\"."
	" \"Had had\" had had the examiners\' approbal." };
	std::cout << text << std::endl;

	std::string phrase{ "had had" };
	auto iter8 = std::find_end(std::begin(text), std::end(text), std::begin(phrase), std::end(phrase));
	if (iter8 != std::end(text))
		std::cout << "The las \"" << phrase << "\" was found at index " << std::distance(std::begin(text), iter8) << std::endl;

	// + 대소문자 무시버전
	std::cout << "std::find_end() 대소문자 무시 버전" << std::endl;
	size_t count9{};
	auto iter9 = std::end(text);
	auto end_iter9 = iter9;
	while ((iter9 = std::find_end(std::begin(text), end_iter9, std::begin(phrase), std::end(phrase),
		[](char ch1, char ch2) {return std::toupper(ch1) == std::toupper(ch2); })) != end_iter9)
	{
		++count9;
		end_iter9 = iter9;
	}
	std::cout << count9 << std::endl;

}
#endif

#ifdef SEARCH
#include<algorithm>
#include<vector>
#include<iostream>

int main()
{

	// std::search() 범위 같은 값 찾기
	std::string text{ "Smith, where Jones had had \"had\", had had \"had had\"."
	" \"Had had\" had had the examiners\' approbal." };
	std::cout << text << std::endl;
	std::string phrase{ "had had" };
	size_t count{};
	auto iter = std::begin(text);
	auto end_iter = std::end(text);
	while ((iter = std::search(iter, end_iter, std::begin(phrase), std::end(phrase),
		[](char ch1, char ch2) {return std::toupper(ch1) == std::toupper(ch2); })) != end_iter)
	{
		++count;
		std::advance(iter, phrase.size());
	}
	std::cout << "\n\"" << phrase << "\" was found " << count << " times." << std::endl;

	// std::search_n() 연속으로 일치되는 원소 범위 검색
	std::vector<double> values{ 2.7, 2.7, 2.7, 3.14, 3.14, 3.14, 2.7, 2.7 };
	double value{ 3.14 };
	int times{ 3 };
	auto iter1 = std::search_n(std::begin(values), std::end(values), times, value);
	if (iter1 != std::end(values))
		std::cout << times << " successive instances of " << value << " found starting index " <<
		std::distance(std::begin(values), iter1) << std::endl;

	// std::serach_n() 람다 함수
	std::vector<int> temperatures{ 65, 75, 56, 48, 31, 28, 32, 29, 40, 41, 44, 50 };
	int max_temp{ 32 };
	//int times{ 3 };
	// 람다 함수식 안 max는 max_temp를 가르킨다
	auto iter2 = std::search_n(std::begin(temperatures), std::end(temperatures), times, max_temp,
		[](double v, double max) {return v <= max; });
	if (iter2 != end(temperatures))
		std::cout << "람다 함수 적용 serach_n : " << std::distance(std::begin(temperatures), iter2) << std::endl;
}
#endif

#ifdef PARTITION
#include<algorithm>
#include<vector>
#include<iostream>
#include<numeric>

int main()
{
	std::vector<double> temperatures{ 65, 75, 56, 48, 31, 28, 32, 29, 40 ,41 ,44 ,50 };
	std::copy(std::begin(temperatures), std::end(temperatures), std::ostream_iterator<double> {std::cout, " "});
	std::cout << std::endl;

	auto average = std::accumulate(std::begin(temperatures), std::end(temperatures), 0.0) / temperatures.size(); // std::accumulate(시작, 끝, 초기값)
	std::cout << "Average temperature : " << average << std::endl;

	// 원소들의 원본 순서 유지 안함
	//std::partition(std::begin(temperatures), std::end(temperatures), [average](double t) {return t < average; });
	// 원소들의 원본 순서를 유지
	std::stable_partition(std::begin(temperatures), std::end(temperatures), [average](double t) {return t < average; });
	std::copy(std::begin(temperatures), std::end(temperatures), std::ostream_iterator<double>{std::cout, " " });
	std::cout << std::endl;
	// 원소들의 기준에 따라 복사
	std::vector<double> low_t;
	std::vector<double> high_t;
	std::partition_copy(std::begin(temperatures), std::end(temperatures), std::back_inserter(low_t), std::back_inserter(high_t),
		[average](double t) {return t < average; });
	std::copy(std::begin(low_t), std::end(low_t), std::ostream_iterator<double>{std::cout, " " });
	std::cout << std::endl;
	std::copy(std::begin(high_t), std::end(high_t), std::ostream_iterator<double>{std::cout, " " });
	std::cout << std::endl;

	// 첫 번째 파티션의 끝 반복자를 얻기 위한 알고리즘
	if (std::is_partitioned(std::begin(temperatures), std::end(temperatures), [average](double t) {return t < average; }))
	{
		auto iter = std::partition_point(std::begin(temperatures), std::end(temperatures), [average](double t) {return t < average; });
		std::cout << "Elements in the first partition: ";
		std::copy(std::begin(temperatures), iter, std::ostream_iterator<double>{std::cout, " "});
		std::cout << std::endl;
		std::cout << "Elements in teh second partion: ";
		std::copy(iter, std::end(temperatures), std::ostream_iterator<double>{std::cout, " "});
	}
}
#endif

#ifdef BINARY_SEARCH
#include<algorithm>
#include<vector>
#include<iostream>
#include<numeric>
#include <list>

int main()
{
	std::list<int> values{ 17, 11, 40, 36, 22, 22, 22, 54, 48, 70, 61, 82, 78, 89, 99, 92, 43 };
	// 내림차순
	//auto predicate = [](int a, int b) { return a > b; };
	//values.sort(predicate);
	// 오름차순
	values.sort();
	int wanted{ 22 };
	if (std::binary_search(std::begin(values), std::end(values), wanted))
		std::cout << wanted << " is definitely in there - somewher..." << std::endl;
	else
		std::cout << wanted << " cannot be found - maybe you got it wrong..." << std::endl;

	// lower_bound() - 세 번째 인수와 같거나 보다 큰 첫 번째 원소
	std::cout << "The lower bound for " << wanted << " is " << *std::lower_bound(std::begin(values), std::end(values), wanted) << std::endl;
	// upper_bound() - 세 번째 인수보다 큰 첫 번째 원소
	std::cout << "The upper bound for " << wanted << " is " << *std::upper_bound(std::begin(values), std::end(values), wanted) << std::endl;

	std::list<int>::iterator bIter;
	for (bIter = std::lower_bound(std::begin(values), std::end(values), wanted);
		bIter != std::upper_bound(std::begin(values), std::end(values), wanted);
		bIter++)
	{
		std::cout << *bIter << std::endl;
	}

	// equal_range() - 같은 원소 모두 찾기
	std::cout << "equal_range : " << std::endl;
	auto pr = std::equal_range(std::begin(values), std::end(values), wanted);
	std::cout << "the lower bound for " << wanted << " is " << *pr.first << std::endl;
	std::cout << "the upper bound for " << wanted << " is " << *pr.second << std::endl;
	std::list<int>::iterator iter;
	for (iter = pr.first; iter != pr.second; iter++)
	{
		std::cout << *iter << std::endl;
	}

	// partition() 에 의해 분리된 원소 equal_range()
	// 1. value < wanted 에 의해 분리
	std::partition(std::begin(values), std::end(values),
		[wanted](double value) { return value < wanted; });
	// 2. !(value < wanted) 에 의해 분리
	std::partition(std::begin(values), std::end(values),
		[wanted](double value) { return !(value < wanted); });

	std::copy(std::begin(values), std::end(values), std::ostream_iterator<int> {std::cout, " "});
	std::cout << std::endl;

	auto pr2 = std::equal_range(std::begin(values), std::end(values), wanted);
	std::cout << "the lower bound for " << wanted << " is " << *pr.first << std::endl;
	std::cout << "the upper bound for " << wanted << " is " << *pr.second << std::endl;
}
#endif

//#define NUMBER1

#ifdef NUMBER1
#include <iostream>
#include <thread>
#include <future>
//#include <thread>

void thread(std::promise<int>& p, int a, int b)
{
	int data = 0;
	for (int i = a; i < b; i++)
	{
		data += i;
	}
	p.set_value(data);
}

int main()
{
	std::promise<int> pm;
	std::future<int> ft = pm.get_future();
	std::thread th(thread, std::ref(pm), 1, 1000);
	int n = ft.get();
	std::cout << n << std::endl;
	th.join();
}
#endif


#ifdef NUMBER2_A
#include <chrono>
#include <iostream>
#include <future>
#include <random>
#include <vector>
#include <string>
#include <numeric>
#include <execution>

static const int NUM = 10; // 1억
std::vector<int> vec;
std::mutex m;

void fill_vector()
{
	/*
	std::random_device seed;
	std::mt19937 engine(seed());
	std::uniform_int_distribution<int> dist(0, 100);

	vec.reserve(NUM);

	for (int i = 0; i < NUM; ++i)
	{
		vec.push_back(dist(engine));
		//std::cout << "tunring" << std::endl;
	}
	*/

	for (int i = 0; i < NUM; ++i)
	{
		vec.push_back(i);
		//std::cout << "tunring" << std::endl;
	}
}

void thread(std::promise<int>& p, std::vector<int> vecData)
{
	int data = 0;
	//std::lock_guard<std::mutex> lg(m);
	for (std::vector<int>::iterator iter = vecData.begin(); iter != vecData.end(); iter++)
	{
		data += *iter;
	}
	p.set_value(data);
}

int main()
{
	fill_vector();

	std::promise<int> pm;
	std::future<int> ft = pm.get_future();
	std::thread th(thread, std::ref(pm), vec);
	int n = ft.get();
	std::cout << n << std::endl;
	th.join();
}
#endif

#ifdef NUMBER2_B
#include <chrono>
#include <iostream>
#include <future>
#include <random>
#include <vector>
#include <string>
#include <numeric>
#include <execution>

static const int NUM = 100000000; // 1억
std::vector<int> vec;

void fill_vector()
{

	std::random_device seed;
	std::mt19937 engine(seed());
	std::uniform_int_distribution<int> dist(0, 100);

	vec.reserve(NUM);

	for (int i = 0; i < NUM; ++i)
	{
		vec.push_back(dist(engine));
		//std::cout << "tunring" << std::endl;
	}


}

int main()
{
	fill_vector();
	auto future1 = std::async([]() { return std::accumulate(&vec[0], &vec[(vec.size()) / 4], 0); });
	auto future2 = std::async([]() { return std::accumulate(&vec[(vec.size()) / 4], &vec[(vec.size()) / 2], 0); });
	auto future3 = std::async([]() { return std::accumulate(&vec[(vec.size()) / 2], &vec[(vec.size()) * 3 / 4], 0); });
	auto future4 = std::async([]() { return std::accumulate(&vec[(vec.size()) * 3 / 4], &vec[vec.size() - 1], vec[vec.size() - 1]); });

	int data = future1.get() + future2.get() + future3.get() + future4.get();
	std::cout << data << std::endl;
	std::cout << std::accumulate(vec.begin(), vec.end(), 0) << std::endl;
}
#endif

#define NUMBER3_A
#ifdef NUMBER3_A

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <queue>
#include <condition_variable>

std::mutex m;
std::condition_variable cv;
std::queue<int> q;
bool data_ready = false;

void consumer()
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		std::unique_lock<std::mutex> ul(m);
		if (q.size() < 10)
			cv.wait(ul, [] { return data_ready; });
		else
		{
			std::cout << "consume : " << q.front() << "\t" << q.size() << std::endl;
			q.pop();
		}
		//ul.unlock();
		//cv.notify_one();
	}
}
void producer()
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		{
			int shared_data = 0;
			std::lock_guard<std::mutex> lg(m);
			shared_data = 100;

			if (q.size() < 1000)
				q.push(shared_data);

			if (q.size() >= 10)
				data_ready = true;
			else
				data_ready = false;

			std::cout << "produce : " << q.front() << "\t" << q.size() << std::endl;
		}
		cv.notify_all();
	}

}

int main()
{
	std::thread t1(producer);
	std::thread t2(consumer);
	std::thread t3(consumer);
	std::thread t4(consumer);
	t1.join(); t2.join();
	t3.join(); t4.join();
}
#endif