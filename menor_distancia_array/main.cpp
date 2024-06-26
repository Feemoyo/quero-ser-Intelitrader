#include <iostream>
#include <climits>

int main()
{
	int	array1[] = {424, 258, 60, 114, 329, 432, 141, 778, 744, 666, -72, 274, 250, 947, 213, 166, 412, -7, 153, 132, 565, 64, 850, 728, 24};
	int array2[] = {861, 283, 445, 621, 467, 270, -43, 178, 150, 563, 765, 897, 609, 597, 875, 369, 865, 618, 682, 334, 570, 739, 670, 809, 799};

	int size1 = sizeof(array1) / sizeof(array1[0]);
	int size2 = sizeof(array2) / sizeof(array2[0]);

	unsigned long	auxDistancia = 0;
	size_t 			menorDistancia = SIZE_MAX;

	for (int i = 0; i < size1; i++)
	{
		for (int j = 0; j < size2; j++)
		{
			if (array1[i] > array2[j])
			{
				auxDistancia = array1[i] - array2[j];
			}
			else
			{
				auxDistancia = array2[j] - array1[i];
			}
			if (auxDistancia < menorDistancia)
			{
				menorDistancia = auxDistancia;
			}
		}
	}
	std::cout << "A menor distancia é: " << menorDistancia << std::endl;
}