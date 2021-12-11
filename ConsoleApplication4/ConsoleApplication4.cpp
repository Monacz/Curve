#include <iostream>
#include <vector>
#include <algorithm>

#include "Curve.h"


Curve& pointsDeleter(Curve& curve);

int main()
{
	std::vector<Curve> curves;

	curves.emplace_back(Curve{ {-93, -81}, {-40, 82}, {31, -57}, {-29, -33}, {-9, 45}, {-7, -19}, {37, -45} });
	curves.emplace_back(Curve{{ -51, -5 }, { -30, 41 }, { 27, 21 }});
	curves.emplace_back(Curve{ {-83, 22}, {-77, -32}, {-11, -49}, {27, -12}, {85, -32} });

	std::cout << "Curves:\n";
	curves[0].print();
	std::cout << std::endl;
	curves[1].print();
	std::cout << std::endl;
	curves[2].print();
	std::cout << std::endl;

	pointsDeleter(curves[0]);
	pointsDeleter(curves[1]);
	pointsDeleter(curves[2]);


	std::cout << "NEW Curves:\n";
	curves[0].print();
	std::cout << std::endl;
	curves[1].print();
	std::cout << std::endl;
	curves[2].print();
	std::cout << std::endl;

	std::sort(curves.begin(), curves.end());

	std::cout << "Sorted Curves:\n";
	curves[0].print();
	std::cout << std::endl;
	curves[1].print();
	std::cout << std::endl;
	curves[2].print();
	std::cout << std::endl;
}

Curve& pointsDeleter(Curve& curve)
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