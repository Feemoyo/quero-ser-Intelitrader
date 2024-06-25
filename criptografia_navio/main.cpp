#include <iostream>
#include <string>
#include <algorithm>
#include <bitset>

#define MESSAGE "10010110 11110111 01010110 00000001 00010111 00100110 01010111 00000001 00010111 01110110 01010111 00110110 11110111 11010111 01010111 00000011"

class Enigma
{
private:
    std::string message;

    void everyFourBits(std::string &byte);
    void everyEightBits(std::string &byte);

public:
    Enigma();
    ~Enigma();

    void setMessage(std::string message);
    std::string printMessage();
    void decrypt();
};

Enigma::Enigma()
{
    this->message = MESSAGE;
}

Enigma::~Enigma()
{
}

void Enigma::setMessage(std::string message)
{
    message.erase(std::remove(message.begin(), message.end(), ' '), message.end());
    this->message = message;
}

std::string Enigma::printMessage()
{
    std::cout << "Message: " << this->message << std::endl;
    return this->message;
}

void Enigma::decrypt()
{
    std::string auxMessage = this->message;
    this->message.clear();
    while (auxMessage.size() >= 8)
    {
        std::string auxChar = auxMessage.substr(0, 8);
        auxMessage.erase(0, 8);
        everyEightBits(auxChar);
        everyFourBits(auxChar);

		std::bitset<8> auxByte(auxChar);
        this->message += static_cast<char>(auxByte.to_ulong());
    }
}

void Enigma::everyFourBits(std::string &byte)
{
    std::string auxByte = byte;
    for (int i = 0; i < 4; i++)
    {
        byte[i] = auxByte[i + 4];
        byte[i + 4] = auxByte[i];
    }
}

void Enigma::everyEightBits(std::string &byte)
{
	for (int i = 6; i < 8; i++)
	{
		if (byte[i] == '0')
		{
			byte[i] = '1';
		}
		else if (byte[i] == '1')
		{
			byte[i] = '0';
		}
	}
}

int main()
{
    Enigma enigma;
    enigma.setMessage(MESSAGE);
    enigma.decrypt();
    enigma.printMessage();

    return 0;
}
