#include <iostream>
#include <algorithm>
#include <Windows.h>
#include <array>
using namespace std;

class SpecialCharacters
{

	char value;
	static const array<int, 38> special_characters_codes;

public:

	SpecialCharacters() :value(' ') {}
	SpecialCharacters(char value) { this->value = value; }

	friend istream& operator >> (istream& is, SpecialCharacters& object) { return is >> object.value; }
	friend ostream& operator << (ostream& os, SpecialCharacters& object) { return os << object.value; }

	char operator = (char new_value) { return value = new_value; }
	operator int() { return int(value); }

	bool operator != (char compared_value) { return !operator == (compared_value); }
	bool operator != (const SpecialCharacters& compared_object) { return !operator == (compared_object); }

	bool operator == (const SpecialCharacters& compared_object) { return operator==(compared_object.value); }

	bool operator == (char compared_value)
	{
		array<int, 38>::const_iterator compared_value_it, this_value_it;

		compared_value_it = find(special_characters_codes.begin(), special_characters_codes.end(), int(compared_value));
		this_value_it = find(special_characters_codes.begin(), special_characters_codes.end(), int(value));

		if (compared_value_it == special_characters_codes.end() || this_value_it == special_characters_codes.end())
			return value == compared_value;

		else
		{
			int compared_value_id, this_value_id;

			compared_value_id = compared_value_it - special_characters_codes.begin();
			this_value_id = this_value_it - special_characters_codes.begin();

			if (compared_value_id % 2 == 0 && this_value_id % 2 != 0)
				return this_value_id - compared_value_id == 1;
			

			else if (compared_value_id % 2 != 0 && this_value_id % 2 == 0)
				return compared_value_id - this_value_id == 1;

			else
				return value == compared_value;
		}
	}
};

const array<int, 38> SpecialCharacters::special_characters_codes
{
/* O */ 79, -50,
/* o */	111, -18,
/* A */	65, -64,
/* a */	97, -32,
/* I */	73, -78,
/* i */	105, -77,
/* E */	69, -59,
/* e */ 101, -27,
/* H */	72, -51,
/* C */	67, -47,
/* c */	99, -15,
/* B */	66, -62,
/* K */	75, -54,
/* P */	80, -48,
/* p */	112, -16,
/* X */	88, -43,
/* x */	120, -11,
/* T */	84, -46,
/* M */	77, -52
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	SpecialCharacters first_character, second_character;
	while (true)
	{
		system("cls");
		cout << "порівняння символів\nвведіть перший символ -> ";
		cin >> first_character;
		cout << "введіть другий символ -> ";
		cin >> second_character;
		cout << first_character <<
			" (" << int(first_character) << ")" << 
			(first_character == second_character ? " == " : " != ") <<
			second_character <<
			" (" << int(second_character) << ")" << endl;
		system("pause");
	}
}