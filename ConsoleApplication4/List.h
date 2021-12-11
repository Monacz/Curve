#pragma once

#include <iostream>
#include <vector>

struct Point
{
	int X;
	int Y;
};

struct Elem
{
	Point data;
	Elem* next;
	Elem* prev;
};

class List
{
public:

	List();
	explicit List(std::initializer_list<Point>&& listOfPoints);
	~List();
	List& operator=(const List& listToCopy);
	List(const List&& listToMove) noexcept;
	


	int getCount();
	Elem* getElem(int);
	void del(Elem* element);
	void addTail(Point n);
	double distanceBetweenPoints(Elem* a, Elem* b) const;
	double curveslongation() const;
	void print();

	List(const List& listToCopy);
	List& operator=(const List&& listToMove) noexcept;
	bool operator<(const List& curve);

private:
	Elem* head;
	Elem* tail;
	std::size_t count;

	void delAll();

};


