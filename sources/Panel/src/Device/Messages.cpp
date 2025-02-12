// 2025/02/12 10:23:20 (c) Aleksandr Shevchenko e-mail : Sasha7b9@tut.by
#include "defines.h"
#include "Device/Messages.h"
#include <cstring>


namespace Messages
{
    static const int SIZE_BUFFER = 1024 * 10;
    static char buffer[SIZE_BUFFER];

    // ¬озвращает количество свободной пам€ти
    static int GetEmptySpace();

    static char *FirstEmpbyByte();

    static char *GetMessage(int i);
}


void Messages::Init()
{
    for (int i = 0; i < SIZE_BUFFER; i++)
    {
        buffer[i] = (char)0xFF;
    }
}


void Messages::AppendMessage(pchar message)
{
    if (GetEmptySpace() >= (int)std::strlen(message) + 1)
    {
        std::strcpy(FirstEmpbyByte(), message);
    }
}


int Messages::GetCountMessages()
{
    int first_empty = 0;

    for (int i = 0; i < SIZE_BUFFER; i++)
    {
        if (buffer[i] == -1)
        {
            first_empty = i;
        }
    }

    int counter = 0;

    for (int i = 0; i < first_empty; i++)
    {
        if (buffer[i] == '\0')
        {
            counter++;
        }
    }

    return counter;
}


int Messages::GetMessage(int i, char *message)
{
    if (message == nullptr)
    {
        return (int)std::strlen(GetMessage(i));
    }

    char *string = GetMessage(i);

    std::strcpy(message, string);

    return (int)std::strlen(string);
}


int Messages::GetEmptySpace()
{
    for (int i = 0; i < SIZE_BUFFER; i++)
    {
        if (buffer[i] == -1)
        {
            return SIZE_BUFFER - i;
        }
    }

    return 0;
}

char *Messages::FirstEmpbyByte()
{
    for (int i = 0; i < SIZE_BUFFER; i++)
    {
        if (buffer[i] == -1)
        {
            return &buffer[i];
        }
    }

    return nullptr;
}


char *Messages::GetMessage(int i)
{
    if (i == 0)
    {
        return (buffer[0] == -1) ? nullptr : buffer;
    }

    for (int byte = 0; byte < SIZE_BUFFER; byte++)
    {
        if (buffer[byte] == -1)
        {
            return nullptr;
        }

        if (buffer[byte] == '\0')
        {
            i--;

            if (i == 0)
            {
                return (buffer[byte + 1] == -1) ? nullptr : &buffer[byte + 1];
            }
        }
    }

    return nullptr;
}
