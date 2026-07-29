#include <iostream>
using namespace std;

// Fizz jak wielokrotnosc 3
// Buzz jak wielokrotnosc 5
// FizzBuzz jak jedno i drugie np 15

// Nested loops example
// Iteration number
// End range

int main() {
	size_t numsOfTests = 0;
	size_t endRange = 0;
    cout << "Ilosc iteracji:> ";
	cin >> numsOfTests;
	for(size_t i = 1; i <= numsOfTests; i++)
	{
        cout << "Iteracja: " << i << endl;
        cout << "Zakres Koncowy Zamkniety:> ";
		cin >> endRange;
		for(size_t j = 1; j <= endRange; j++)
		{
			if ((j % 3) == 0 && (j % 5) == 0)
				cout << "FizzBuzz" << endl;
			else if((j % 3) == 0)
				cout << "Fizz" << endl;
			else if((j % 5) == 0)
				cout << "Buzz" << endl;
			else
				cout << j << endl;
		}
	}
}

// Nested loops example
// Iteration number
// Start range
// End range

// int main() {
// 	size_t numsOfTests = 0;
// 	size_t startRange = 0;
//     size_t endRange = 0;
//     cout << "Ilosc iteracji:> ";
// 	cin >> numsOfTests;
// 	for(size_t i = 1; i <= numsOfTests; i++)
// 	{
//         cout << "Iteracja: " << i << endl;
//         cout << "Zakres Startowy Zamkniety:> ";
// 		cin >> startRange;
//         cout << "Zakres Koncowy Zamkniety:> ";
// 		cin >> endRange;
// 		for(size_t j = startRange; j <= endRange; j++)
// 		{
// 			if ((j % 3) == 0 && (j % 5) == 0)
// 				cout << "FizzBuzz" << endl;
// 			else if((j % 3) == 0)
// 				cout << "Fizz" << endl;
// 			else if((j % 5) == 0)
// 				cout << "Buzz" << endl;
// 			else
// 				cout << j << endl;
// 		}
// 	}
// }

// Ssolution from LeetCode
// class Solution {
// public:
//     vector<string> fizzBuzz(int n) {
//     vector<string> answer;

//     for(int i = 1; i <= n; i++)
//     {
//         bool divisbleBy3 = i % 3 == 0;
//         bool divisbleBy5 = i % 5 == 0;

//         string currentStr = "";

//         if(divisbleBy3)
//         {
//             currentStr += "Fizz";
//         }
//         if(divisbleBy5)
//         {
//             currentStr += "Buzz";
//         }
//         if(currentStr.empty())
//         {
//             currentStr += std::to_string(i);
//         }
//         answer.push_back(currentStr);
//     }
//     return answer;
//     }
// };