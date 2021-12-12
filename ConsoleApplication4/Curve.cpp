#include "Curve.h"

Curve::Curve():head(nullptr), tail(nullptr), count(0)
{
}

Curve::Curve(std::initializer_list<Point>&& listOfPoints):Curve()
{
	for (const auto i : listOfPoints)
	{
		addTail(i);
	}
}

Curve::~Curve()
{
	delAll();
}

Curve::Curve(const Curve& listToCopy):Curve()
{
	//copy
	Elem* temp = listToCopy.head;
	while (temp != nullptr)
	{
		addTail(temp->data);
		temp = temp->next;
	}
}

Curve& Curve::operator=(Curve&& listToMove) noexcept
{
	//Check if the same
	if (this == &listToMove)
		return *this;

	this->~Curve();

	//Moving
	count = listToMove.count;
	head = listToMove.head;
	tail = listToMove.tail;

	listToMove.count = 0;
	listToMove.head = nullptr;
	listToMove.tail = nullptr;

	return *this;
}

Curve& Curve::operator=(const Curve& listToCopy)
{
	//Check if the same
	if (this == &listToCopy)
		return *this;

	this->~Curve(); 

	//copy
	Elem* temp = listToCopy.head;
	while (temp != nullptr)
	{
		addTail(temp->data);
		temp = temp->next;
	}

	return *this;
}

Curve::Curve(Curve&& listToMove) noexcept: count(listToMove.count), head(listToMove.head), tail(listToMove.tail)
{
		listToMove.count = 0;
		listToMove.head = nullptr;
		listToMove.tail = nullptr;
}


void Curve::addTail(Point n)
{
	Elem* temp = new Elem;

	temp->next = nullptr;
	temp->data = n;
	temp->prev = tail;

	if (tail != nullptr)
	{
		tail->next = temp;
	}
	if (count == 0)
	{
		head = tail = temp;
	}
	else
	{
		tail = temp;
	}
	++count;
}

void Curve::del(Elem* element)
{
	size_t i = 0;
	Elem* del = head;

	while (del != element)
	{

		del = del->next;
		++i;
		if (i - 1 == count)
		{
			return;
		}
	}

	Elem* prevDel = del->prev;
	Elem* afterDel = del->next;

	if (prevDel != nullptr && count != 1)
	{
		prevDel->next = afterDel;
	}
	if (afterDel != nullptr && count != 1)
	{
		afterDel->prev = prevDel;
	}
	if (i == 0)
	{
		head = afterDel;
	}
	if (i == count - 1)
	{
		tail = prevDel;
	}
	delete del;

	--count;
}

void Curve::print()
{

	if (count != 0)
	{
		Elem* temp = head;
		std::cout << "( ";
		while (temp->next != 0)
		{
			std::cout << temp->data.X << " " << temp->data.Y << ", ";
			temp = temp->next;
		}

		std::cout << temp->data.X << " " << temp->data.Y << " )\n";
	}
}

bool Curve::operator<(const Curve& curve)
{
	return this->curveslength() < curve.curveslength();


}

void Curve::delAll()
{
	while (count != 0)
	{
		del(head);
	}
}

int Curve::getCount()
{
	return count;
}

Elem* Curve::getElem(int pos)
{
	Elem* temp = head;

	if (pos < 0 && pos > count - 1)
	{
		return nullptr;
	}

	int i = 0;
	while (i < pos && temp != nullptr)
	{
		temp = temp->next;
		++i;
	}

	if (temp == nullptr)
	{
		return nullptr;
	}
	else
	{
		return temp;
	}
}

double Curve::distanceBetweenPoints(Elem& a, Elem& b) const
{
	return sqrt((b.data.X - a.data.X) * (b.data.X - a.data.X) + (b.data.Y - a.data.Y) * (b.data.Y - a.data.Y));
}

double Curve::curveslength() const
{
	double longation = 0;
	Elem* current = head;
	while (current != tail->prev)
	{
		longation += distanceBetweenPoints(*current, *(current->next));
		current = current->next;
	}
	return longation;
}