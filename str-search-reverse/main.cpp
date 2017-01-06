#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void write_char(char c) {cout << c;}

void main()
{
	setlocale(LC_ALL, "rus");
	char chars[] = "assembler";
	char c;
	int len = strlen(chars) - 1;
	//int i = -1;
	cout << "Строка:" << chars << endl << "Введите символ:";
	cin >> c;
	_asm
	{
		mov al, c
		mov esi, -1
		mov edi, len

		find_char:
		inc esi
		cmp chars[esi], al
		jne find_char

		//т.к. за заданным, а не с него, еще +1
		inc esi

		cmp esi, edi
		//если больше или равно
		jge out_chars

		replace:
		mov dl, chars[esi]
		mov bl, chars[edi]

		mov chars[esi], bl
		mov chars[edi], dl

		inc esi
		dec edi

		cmp esi, edi
		//если меньше и не равно
		jl replace

		out_chars:
		mov esi, -1
		mov edi, len

		write_c:
		inc esi
		mov al, chars[esi]
		push ax
		call write_char
		pop ax
		cmp esi, edi
		jne write_c
	}
	cout << endl;
	system("pause");
}