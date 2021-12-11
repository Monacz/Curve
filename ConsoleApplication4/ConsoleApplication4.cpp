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
	List curve1{ {-93, -81}, {-40, 82}, {31, -57}, {-29, -33}, {-9, 45}, {-7, -19}, {37, -45} };
	List curve2{ {-51, -5}, {-30, 41}, {27, 21} };
	List curve3{ {-83, 22}, {-77, -32}, {-11, -49}, {27, -12}, {85, -32} };

	std::vector<List> curves;

	std::cout << "Curves:\n";
	curve1.print();
	std::cout << std::endl;
	curve2.print();
	std::cout << std::endl;
	curve3.print();
	std::cout << std::endl;

	//pointsDeleter(curve1);
	//pointsDeleter(curve2);
	//pointsDeleter(curve3);


	std::cout << "NEW Curves:\n";
	curve1.print();
	std::cout << std::endl;
	curve2.print();
	std::cout << std::endl;
	curve3.print();
	std::cout << std::endl;

	curves.push_back(curve2);
	std::cout << curves[0].head->data.X << " " << curves[0].head->data.Y;
}