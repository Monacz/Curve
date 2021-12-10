#include "List.h"

List::List()
{
	head = tail = nullptr;
	count = 0;
}

List::List(std::initializer_list<Point>&& listOfPoints)
{
	head = tail = nullptr;
	count = 0;
	for (const auto i : listOfPoints)
	{
		addTail(i);
	}
}

List::~List()
{
	delAll();
}


void List::addTail(Point n)
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

void List::del(Elem* element)
{
	size_t i = 0;
	Elem* Del = head;

	while (Del != element)
	{

		Del = Del->next;
		++i;
		if (i - 1 == count)
		{
			return;
		}
	}

	Elem* PrevDel = Del->prev;
	Elem* AfterDel = Del->next;

	if (PrevDel != nullptr && count != 1)
	{
		PrevDel->next = AfterDel;
	}
	if (AfterDel != nullptr && count != 1)
	{
		AfterDel->prev = PrevDel;
	}
	if (i == 0)
	{
		head = AfterDel;
	}
	if (i == count - 1)
	{
		tail = PrevDel;
	}
	delete Del;

	--count;
}

void List::print()
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

bool List::operator<(const List& curve)
{
	return this->curveslongation() < curve.curveslongation();


}

void List::delAll()
{
	while (count != 0)
	{
		del(head);
	}
}

int List::getCount()
{
	return count;
}

Elem* List::getElem(int pos)
{
	Elem* temp = head;

	if (pos < 0 && pos > count - 1)
	{
		std::cout << "Incorrect position !!!\n";
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

double List::distanceBetweenPoints(Elem* a, Elem* b) const
{
	return sqrt((b->data.X - a->data.X) * (b->data.X - a->data.X) + (b->data.Y - a->data.Y) * (b->data.Y - a->data.Y));
}

double List::curveslongation() const
{
	double longation = 0;
	Elem* current = head;
	while (current != tail->prev)
	{
		longation += distanceBetweenPoints(current, current->next);
	}
	return longation;
}
