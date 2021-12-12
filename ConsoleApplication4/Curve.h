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

class Curve
{
public:

	Curve();
	explicit Curve(std::initializer_list<Point>&& listOfPoints);
	~Curve();
	Curve(const Curve& listToCopy);
	Curve(const Curve&& listToMove) noexcept;
	

	//Count of nodes
	int getCount();
	//get pointer to element on some pos
	Elem* getElem(int pos);
	//delete element
	void del(Elem* element);
	//add element to the end
	void addTail(Point n);
	//distance between points
	double distanceBetweenPoints(Elem& a, Elem& b) const;
	//Lenght of curve
	double curveslength() const;
	//print nodes
	void print();

	//copy assignment 
	Curve& operator=(const Curve& listToCopy);
	//move assignment
	Curve& operator=(const Curve&& listToMove) noexcept;
	//< operator to use in sorting algorithm
	bool operator<(const Curve& curve);

private:
	Elem* head;
	Elem* tail;
	std::size_t count;

	void delAll();

};


