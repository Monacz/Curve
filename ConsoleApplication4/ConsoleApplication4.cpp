#include <iostream>
#include <vector>

#include "List.h"


List& pointsDeleter(List& curve)
{
	std::vector<Elem*> positions;

	for (size_t i = 1; i <= curve.getCount() - 2; ++i)
	{
		if (curve.distanceBetweenPoints(curve.getElem(i), curve.getElem(i + 1)) +
			curve.distanceBetweenPoints(curve.getElem(i), curve.getElem(i - 1)) <= 
			curve.distanceBetweenPoints(curve.getElem(i - 1), curve.getElem(i + 1)) * 1.2)
		{
			positions.emplace_back(curve.getElem(i));
		}
	}

	for (const auto& i : positions)
	{
		curve.del(i);
	}

	return curve;
}

int main()
{
	List* curve = new List{ {-93, -81}, {-40, 82}, {31, -57}, {-29, -33}, {-9, 45}, {-7, -19}, {37, -45} };
	
	std::vector<List> curves;
	/*curves.push_back(List({ {-83, 22}, {-77, -32}, {-11, -49}, {27, -12}, {85, -32} }));*/

	std::cout << "List L:\n";
	curve->print();

	pointsDeleter(*curve);

	std::cout << "NEW List L:\n";
	curve->print();

	delete curve;

	std::cout << std::endl;
}