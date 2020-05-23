#include "Array.h"
#include <iostream>
int main()
{
	Array<int> intArray(12);
	Array<double> doubleArray(12);
    Array<int> intArray2(12);
	for (int count{ 0 }; count < intArray.getLength(); ++count)
	{
		intArray[count] = count;
		doubleArray[count] = count + 0.5;
		intArray2[count]=count+5;
	}

	for (int count{ intArray.getLength() - 1 }; count >= 0; --count)
		std::cout << intArray[count] << '\t' << intArray2[count] << '\n';
    Array<int> c(12);
    c=intArray2+intArray;
    Array<int> d(12);d=intArray2-intArray;
    Array<int> e(12);e=intArray2*intArray;
    Array<int> f(12);f=intArray2*7;
    std::cout<<"Tong, hieu, tich va gia tri cua intArray2 * 7: \n";
    for (int count{c.getLength() - 1 }; count >= 0; --count)
    {
        std::cout<<c[count] << "\t"<<d[count]<<"\t"<<e[count]<<"\t"<<f[count]<<"\n";
    }
	return 0;
}
