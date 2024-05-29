#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<typename T>
T getRandomFrom(vector<T>& values)
{
	return values[rand() % values.size()];
}
void game();

vector<string> words = { "programlama", "adamasmaca", "okanmentes" };
string hangmans[7] = {
	" +---+\n"
	" |   |\n"
	"     |\n"
	"     |\n"
	"     |\n"
	"     |\n"
	"==========",
	" +---+\n"
	" |   |\n"
	" O   |\n"
	"     |\n"
	"     |\n"
	"     |\n"
	"==========",
	" +---+\n"
	" |   |\n"
	" O   |\n"
	" |   |\n"
	"     |\n"
	"     |\n"
	"==========",
	" +---+\n"
	" |   |\n"
	" O   |\n"
	"/|   |\n"
	"     |\n"
	"     |\n"
	"==========",
	" +---+\n"
	" |   |\n"
	" O   |\n"
	"/|\\  |\n"
	"     |\n"
	"     |\n"
	"==========",
	" +---+\n"
	" |   |\n"
	" O   |\n"
	"/|\\  |\n"
	"/    |\n"
	"     |\n"
	"==========",
	" +---+\n"
	" |   |\n"
	" O   |\n"
	"/|\\  |\n"
	"/ \\  |\n"
	"     |\n"
	"=========="
};

int main()
{
	srand(time(nullptr));
	setlocale(LC_ALL, "tr");

	cout << "Adam asmacaya hoþgeldiniz.\n";
	game();

	return 0;
}

void game()
{
	string secretWord = getRandomFrom(words);
	string guessWord = secretWord;
	for (int i = 0; i < secretWord.length(); ++i)
	{
		guessWord[i] = '_';
	}
	int tryNumber = 0;
	char guess;

	while (true)
	{
		cout << hangmans[tryNumber] << "\n";
		cout << guessWord << "\n";
		cout << "Tahmin giriniz (yazý veya karakter):\n";
		cin >> guess;

		if (secretWord.find(guess) != string::npos)
		{
			for (int i = 0; i < guessWord.length(); ++i)
			{
				if (secretWord[i] == guess)
				{
					guessWord[i] = guess;
				}
			}
			if (secretWord == guessWord)
			{
				cout << hangmans[tryNumber] << "\n";
				cout << guessWord << "\n";
				cout << "You win! The word was " << secretWord << "\n";
				break;
			}
		}
		else {
			++tryNumber;
		}
		if (tryNumber >= 6)
		{
			cout << hangmans[tryNumber] << "\n";
			cout << guessWord << "\n";
			cout << "You lost! The word was " << secretWord << "\n";
			break;
		}
	}
}


