#include<iostream>
#include<string>
#include<limits>
#include<cctype>
using namespace std;

class CosmicNumber
{
private:
	int number;  // store user input number
	string word;  // Converted user input number 
	int count;  // store character count of word (not spaces/hyphens)

public:
	// Constructor to initialize
	CosmicNumber() { number = 0; word = "unknown"; count = 0; }
	CosmicNumber(int n)
	{
		number = n;
		word = setWord(n);
		count = setCount(word);
	}

	string setWord(int n);
	int setCount(const string& str);
	void display();
	int setNumber();
	void CosmicSequence();
};

// Function to convert number to words without "and"
string CosmicNumber::setWord(int n) {
	if (n == 0)
		return "zero";

	string words = "";
	if (n == 1000000)
		return "one million";

	// Arrays to store words for numbers
	string thousands[] = { "", "thousand", "million" };
	string hundreds[] = { "", "one hundred", "two hundred", "three hundred", "four hundred",
						  "five hundred", "six hundred", "seven hundred", "eight hundred", "nine hundred" };
	string tens[] = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy",
					  "eighty", "ninety" };
	string teens[] = { "ten", "eleven", "twelve", "thirteen", "fourteen",
					   "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
	string units[] = { "", "one", "two", "three", "four", "five", "six", "seven",
					   "eight", "nine" };

	int num = n;
	int thousandCounter = 0;

	while (num > 0) {
		int chunk = num % 1000;  // Process three digits at a time
		if (chunk != 0) {
			string chunkWords = "";

			// Process hundreds place
			if (chunk / 100 > 0) {
				chunkWords += hundreds[chunk / 100] + " ";
			}

			// Process tens and units place
			int remainder = chunk % 100;
			if (remainder >= 20) {
				chunkWords += tens[remainder / 10] + " ";
				if (remainder % 10 > 0) {
					chunkWords += units[remainder % 10] + " ";
				}
			}
			else if (remainder >= 10) {
				chunkWords += teens[remainder % 10] + " ";
			}
			else if (remainder > 0) {
				chunkWords += units[remainder] + " ";
			}

			// Add thousands place if necessary
			if (thousands[thousandCounter] != "") {
				chunkWords += thousands[thousandCounter] + " ";
			}

			words = chunkWords + words;
		}
		num /= 1000;
		thousandCounter++;
	}

	// Remove any trailing spaces
	if (words[words.length() - 1] == ' ')
		words = words.substr(0, words.length() - 1);

	return words;
}

// Function to count characters excluding spaces and hyphens
int CosmicNumber::setCount(const string& str) {
	int charCount = 0;
	for (char c : str) {
		if (!isspace(c) && c != '-') {
			charCount++;
		}
	}
	return charCount;
}

// Function to display the cosmic sequence
void CosmicNumber::CosmicSequence() {
	string currentWord = word;
	int currentCount = count;

	while (true) {
		cout << currentWord << " is ";
		currentCount = setCount(currentWord);
		string countWord = setWord(currentCount);

		// Check if we have reached "four"
		if (currentWord == "four") {
			cout << "cosmic.";
			break;
		}
		else {
			cout << countWord;
			// Prepare for next iteration
			currentWord = countWord;
			// If the next word is "four", decide whether to end with a period or comma
			if (currentWord == "four") {
				cout << ",";
			}
			else {
				cout << ",";
			}
			cout << endl;
		}
	}
	cout << endl;
}

// Function to display the number, word, and character count
void CosmicNumber::display() {
	cout << "Number: " << number << ", Word: " << word << ", Character Count: " << count << endl;
}

// Function to get a number and validate
int CosmicNumber::setNumber()
{
	int num = 0;
	bool valid = false;
	while (!valid)
	{
		cout << "Enter number [0-1000000]: ";
		cin >> num;
		if (cin.fail() || num < 0 || num > 1000000)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n - Try Again : \n - The Number Has To Be Between 0 and 1000000\n\n";
			valid = false;
		}
		else
			valid = true;
	}
	number = num;
	word = setWord(num);
	count = setCount(word);
	return num;
}

int main()
{
	char choice = ' ';
	do {
		CosmicNumber userNumber;
		userNumber.setNumber();
		userNumber.CosmicSequence();

		cout << "Run Again (Y/N): ";
		cin >> choice;
		choice = toupper(choice);
		while(cin.fail() || choice != 'Y' && choice!= 'N')
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n - Try Again : \n - 'Y' For Yes: 'N' For No: \n\n";
			cout << "Run Again (Y/N): ";
			cin >> choice;
			choice = toupper(choice);
			
		}
		
	} while (choice == 'Y');

	return 0;
}