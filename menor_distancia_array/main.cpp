#include <iostream>
#include <climits>

size_t menorDistancia(int array1[], int array2[], size_t size1, size_t size2);
void printOutput(size_t menorDistancia);

void testPadrao()
{
    int array1[] = {424, 258, 60, 114, 329, 432, 141, 778, 744, 666, -72, 274, 250, 947, 213, 166, 412, -7, 153, 132, 565, 64, 850, 728, 24};
    int array2[] = {861, 283, 445, 621, 467, 270, -43, 178, 150, 563, 765, 897, 609, 597, 875, 369, 865, 618, 682, 334, 570, 739, 670, 809, 799};
    
    size_t size1 = sizeof(array1) / sizeof(array1[0]);
    size_t size2 = sizeof(array2) / sizeof(array2[0]);

    size_t dist = menorDistancia(array1, array2, size1, size2);
    printOutput(dist);
}

void testeNegativo()
{
    int array1[] = {-10, -20, -30, -40, -50};
    int array2[] = {-60, -70, -80, -15, -100};

    size_t size1 = sizeof(array1) / sizeof(array1[0]);
    size_t size2 = sizeof(array2) / sizeof(array2[0]);

    size_t dist = menorDistancia(array1, array2, size1, size2);
    printOutput(dist);
}

void testeZero()
{
	int array1[] = {0, 0, 0, 0, 0};
	int array2[] = {0, 0, 0, 0, 0};

	size_t size1 = sizeof(array1) / sizeof(array1[0]);
	size_t size2 = sizeof(array2) / sizeof(array2[0]);

	size_t dist = menorDistancia(array1, array2, size1, size2);
	printOutput(dist);
}

int main()
{
    {
	std::cout << "00 - Teste Padrão" << std::endl;
    testPadrao();
    std::cout << std::endl;
	}
    
	{
    std::cout << "01 - Teste Negativo" << std::endl;
    testeNegativo();
    std::cout << std::endl;
	}

	{
	std::cout << "02 - Teste Zero" << std::endl;
	testeZero();
	std::cout << std::endl;
	}

    return 0;
}

size_t menorDistancia(int array1[], int array2[], size_t size1, size_t size2)
{
    unsigned long auxDistancia = 0;
    size_t menorDistancia = SIZE_MAX;

    for (size_t i = 0; i < size1; i++)
    {
        for (size_t j = 0; j < size2; j++)
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
    return menorDistancia;
}

void printOutput(size_t menorDistancia)
{
    std::cout << "A menor distância entre o array1 e array2 é: " << menorDistancia << std::endl;
}
