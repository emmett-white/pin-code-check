#include <iostream>
#include <conio.h>
#include <ctime>

int trenutniBroj = 1, vrednostBroja[6], pinKod[6], pinKodTacan;
char key, buffer[128];

void printInfo()
{
    #ifdef linux
        system("clear");
    #elif _WIN32
        system("cls");
    #endif

    std::cout << "Press SPACE to change number, press ESC to select next number, press TAB to submit\n";
    std::cout << "Enter this pin: ";

    for (int i = 0; i < 6; i++)
    {
         sprintf(buffer, "%d", pinKod[i]);
         std::cout << buffer;
    }

    std::cout << std::endl;
    std::cout << "----------------------------------\n";
    sprintf(buffer, "[%d] [%d] [%d] [%d] [%d] [%d]\n", vrednostBroja[0], vrednostBroja[1], vrednostBroja[2], vrednostBroja[3], vrednostBroja[4], vrednostBroja[5]);
    std::cout << buffer;
    std::cout << "----------------------------------\n";
}

int main()
{
    std::srand(std::time(nullptr));
    for (int i = 0; i < 6; i++)
        pinKod[i] = std::rand() % 10;

    printInfo();

    // Reset array values
    for (int i = 0; i < 6; i++)
        vrednostBroja[i] = 0;

    while (key != 0x71)
    {
        for (int i = 0; i < 6; i++)
        {
            if (trenutniBroj == i + 1 && key == 0x20)
            {
                vrednostBroja[i]++;

                if (vrednostBroja[i] == 10)
                    vrednostBroja[i] = 0;

                printInfo();
            }
        }

        if (key == 0x1B)
        {
            trenutniBroj++;

            if (trenutniBroj == 7)
                trenutniBroj = 1;
        }

        else if (key == 0x09)
        {
            std::cout << "\n";
            std::string tacanKod;

            for (int i = 0; i < 6; i++)
                pinKodTacan = vrednostBroja[i] == pinKod[i] ? 1 : 0;

            tacanKod = pinKodTacan ? "\n\n\tUneli ste tacan pin kod!\n": "\n\n\tNiste uneli tacan pin kod!\n";
            std::cout << tacanKod;
        }

        key = getche();
    }
}
