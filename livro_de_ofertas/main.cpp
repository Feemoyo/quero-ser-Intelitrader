#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <exception>

typedef struct s_oferta
{
	int quantidade;
	double valor;
}	t_oferta;

class Ofertas
{
	private:
		std::vector<t_oferta> ofertas;

	public:
		Ofertas();
		~Ofertas();

		void	setInput(std::string);
		void	setInVector(int index, int operacao, t_oferta aux);
		void	printOutput();

		class tipoInvalido: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
		class operacaoInvalida: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
		class inputNegativo: public std::exception
        {
            public:
                virtual const char* what() const throw();
        };

		
};

const char *Ofertas::tipoInvalido::what() const throw()
{
    return ("Tipo inválido");
}

const char *Ofertas::operacaoInvalida::what() const throw()
{
    return ("Operação inválida");
}

const char *Ofertas::inputNegativo::what() const throw()
{
    return ("Input negativo");
}

void	Ofertas::setInput(std::string input)
{
	std::stringstream	ss(input);
	std::stringstream	ssTemp;
	std::string			temp;
	t_oferta			aux;
	int					index;
	int					operacao;
	
	size_t				qtdOcorrencias = 0;


	while (std::getline(ss, temp, ',') && qtdOcorrencias < 4)
	{
		ssTemp.str(temp);
		if (ssTemp >> aux.quantidade && ssTemp.eof())
		{
			if (qtdOcorrencias == 0)
				index = aux.quantidade;
			if (qtdOcorrencias == 1)
				operacao = aux.quantidade;
		}
		else if (ssTemp >> aux.valor && ssTemp.eof())
		{
			aux.valor = aux.quantidade + aux.valor;
		}
		else
		{
			throw (tipoInvalido());
		}

		qtdOcorrencias++;
		ssTemp.clear();
	}
	this->setInVector(index, operacao, aux);
}

void	Ofertas::setInVector(int index, int operacao, t_oferta aux)
{
	if (index < 0 || index > this->ofertas.size() + 1)
	{
		throw (operacaoInvalida());
	}
	if (operacao < 0 || operacao > 2 || aux.quantidade < 0 || aux.valor < 0)
	{
		throw (operacaoInvalida());
	}
	if (operacao == 0)
	{
		this->ofertas.insert(this->ofertas.begin() + index - 1, aux);
	}
	else if (operacao == 1)
	{
		this->ofertas[index - 1] = aux;
	}
	else if (operacao == 2)
	{
		this->ofertas.erase(this->ofertas.begin() + index - 1);
	}
	else
	{
		throw (operacaoInvalida());
	}
}

void	Ofertas::printOutput()
{
	for (size_t i = 0; i < this->ofertas.size(); i++)
	{
		std::cout << i + 1 << "," << this->ofertas[i].valor << "," << this->ofertas[i].quantidade << std::endl;
	}
}

Ofertas::Ofertas()
{
	return ;
}

Ofertas::~Ofertas()
{
	return ;
}

int main()
{
	Ofertas 			ofertas;
	std::string 		input;
	std::stringstream 	ssInput;
	int					firstInput;

	std::getline(std::cin, input);
	ssInput.str(input);
	if (ssInput >> firstInput && ssInput.eof())
	{
		for (int i = 0; i < firstInput; i++)
		{
			std::getline(std::cin, input);
			try
			{
				ofertas.setInput(input);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
				return 1;
			}
		}
	}
	else
	{
		std::cerr << "Primeiro input não é um inteiro" << std::endl;
	}
	ofertas.printOutput();

	return 0;
}