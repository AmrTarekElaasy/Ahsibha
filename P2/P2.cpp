#include <iostream>
using namespace std;

enum enQuestionsLevel { Easy = 1, Med = 2, Hard = 3, Mix = 4 };
enum enOPerationType { Add = 1, Sub = 2, Mul = 3, Div = 4,Mod=5,Max=6 };
enum enPassOrNot { Pass = 1, NotPass = 2 };
struct stRoundInfo
{
	enQuestionsLevel QuestionsLevel;
	enOPerationType OPerationType;
	enPassOrNot PassOrNot;
	int HowManyQuestions;
	int Pass = 0;
	int Failed = 0;
	int Tour = 1;
};

struct stArrays
{
	float arr1[100];
	float arr2[100];
	float FinelArray[100];
	char RandomOperation[100];
};
void IsNumber(float& num)
{
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "\nInvalid Number, Enter a valid one:" << endl;
		cin >> num;
	}
}
int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

void PrintArray(float arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
		cout << arr[i] << " ";
	cout << "\n";
}

float ReadNumberFromTo(int from, int to, string messege)
{
	float num;
	cout << messege;
	cin >> num;
	while (num<from || num>to)
	{
		cout << "Enter number from " << from << " to " << to << " ? ";
		cin >> num;
		IsNumber(num);
	}
	return num;
}
int ReadHowManyQuestions()
{
	int HowManyQuestions;
	cout << "How Many Questions do you want to answer ? ";
	HowManyQuestions = ReadNumberFromTo(1, 100, "");
	return HowManyQuestions;

}
enQuestionsLevel ReadQuestionsLevel()
{
	int readQuestionsLevel;
	cout << "Enter Questions  Level [1] Easy, [2] Med, [3] Hard, [4] Mix ? ";
	readQuestionsLevel = ReadNumberFromTo(1, 4, "");
	return (enQuestionsLevel)readQuestionsLevel;

}
enOPerationType ReadOperationType()
{
	int OperationType;
	cout << "Enter Operation Type [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mod, [6] Mix ? ";
	OperationType = ReadNumberFromTo(1, 6, "");
	return (enOPerationType)OperationType;
}
void ReadTheMainTitle(stRoundInfo& RoundInfo)
{
	RoundInfo.HowManyQuestions = ReadHowManyQuestions();
	RoundInfo.QuestionsLevel = ReadQuestionsLevel();
	RoundInfo.OPerationType = ReadOperationType();
}
void FillArrayWithRandomNumberFromTo(stRoundInfo RoundInfo, float arr[100], int RandomFrom, int RandomTo)
{
	for (int i = 0; i < RoundInfo.HowManyQuestions; i++)
	{
		arr[i] = RandomNumber(RandomFrom, RandomTo);
	}
}
void FillArrWithSetDifficultyLevel(stRoundInfo RoundInfo, float arr[100])
{
	if (RoundInfo.QuestionsLevel == enQuestionsLevel::Easy)
	{
		FillArrayWithRandomNumberFromTo(RoundInfo, arr, 1, 10);
	}
	else if (RoundInfo.QuestionsLevel == enQuestionsLevel::Med)
	{
		FillArrayWithRandomNumberFromTo(RoundInfo, arr, 10, 50);
	}
	else if (RoundInfo.QuestionsLevel == enQuestionsLevel::Hard)
	{
		FillArrayWithRandomNumberFromTo(RoundInfo, arr, 50, 100);
	}
	else if(RoundInfo.QuestionsLevel == enQuestionsLevel::Mix)
	{
		FillArrayWithRandomNumberFromTo(RoundInfo, arr, 1, 100);
	}

}

void SumTwoArray(stRoundInfo RoundInfo, stArrays& Arrays)
{
	for (int i = 0; i < RoundInfo.HowManyQuestions; i++)
	{
		Arrays.FinelArray[i] = Arrays.arr1[i] + Arrays.arr2[i];
	}
}
void SubTwoArray(stRoundInfo RoundInfo, stArrays& Arrays)
{
	for (int i = 0; i < RoundInfo.HowManyQuestions; i++)
	{
		Arrays.FinelArray[i] = Arrays.arr1[i] - Arrays.arr2[i];
	}
}
void MulTwoArray(stRoundInfo RoundInfo, stArrays& Arrays)
{
	for (int i = 0; i < RoundInfo.HowManyQuestions; i++)
	{
		Arrays.FinelArray[i] = Arrays.arr1[i] * Arrays.arr2[i];
	}
}

enOPerationType RandomOPerationType()
{
	int RandomOperation = RandomNumber(1, 5);
	if (RandomOperation == enOPerationType::Add)
		return enOPerationType::Add;
	else if (RandomOperation == enOPerationType::Sub)
		return enOPerationType::Sub;
	else if (RandomOperation == enOPerationType::Mul)
		return enOPerationType::Mul;
	else if(RandomOperation == enOPerationType::Div)
		return enOPerationType::Div;
	else if(RandomOperation == enOPerationType::Mod)
		return enOPerationType::Mod;
}
void DivTwoArray(stRoundInfo RoundInfo, stArrays& Arrays)
{
	for (int i = 0; i < RoundInfo.HowManyQuestions; i++)
	{
		Arrays.FinelArray[i] =round( Arrays.arr1[i] / Arrays.arr2[i]);
	}
}
void ModTwoArray(stRoundInfo RoundInfo, stArrays& Arrays)
{
	for (int i = 0; i < RoundInfo.HowManyQuestions; i++)
	{
		Arrays.FinelArray[i] = round(int(Arrays.arr1[i]) % int(Arrays.arr2[i]));
	}
}
void MixTwoArray(stRoundInfo RoundInfo, stArrays& Arrays)
{
	for (int i = 0; i < RoundInfo.HowManyQuestions; i++)
	{
		enOPerationType RandomOPeration = RandomOPerationType();
		if (RandomOPeration == enOPerationType::Add)
		{
			Arrays.FinelArray[i] = Arrays.arr1[i] + Arrays.arr2[i];
			Arrays.RandomOperation[i] = '+';
		}
		else if (RandomOPeration == enOPerationType::Sub)
		{
			Arrays.FinelArray[i] = Arrays.arr1[i] - Arrays.arr2[i];
			Arrays.RandomOperation[i] = '-';
		}
		else if (RandomOPeration == enOPerationType::Mul)
		{
			Arrays.FinelArray[i] = Arrays.arr1[i] * Arrays.arr2[i];
			Arrays.RandomOperation[i] = '*';
		}
		else if (RandomOPeration == enOPerationType::Div)
		{
			Arrays.FinelArray[i] = Arrays.arr1[i] / Arrays.arr2[i];
			Arrays.RandomOperation[i] = '/';
		}
		else if (RandomOPeration == enOPerationType::Mod)
		{
			Arrays.FinelArray[i] = (int)Arrays.arr1[i] % (int)Arrays.arr2[i];
			Arrays.RandomOperation[i] = '%';
		}


	}
}
void TheOperations(stRoundInfo& RoundInfo, stArrays& Arrays)
{
	if (RoundInfo.OPerationType == enOPerationType::Add)
	{
		SumTwoArray(RoundInfo, Arrays);
	}
	else if (RoundInfo.OPerationType == enOPerationType::Sub)
	{
		SubTwoArray(RoundInfo, Arrays);
	}
	else if (RoundInfo.OPerationType == enOPerationType::Mul)
	{
		MulTwoArray(RoundInfo, Arrays);
	}
	else if (RoundInfo.OPerationType == enOPerationType::Div)
	{
		DivTwoArray(RoundInfo, Arrays);
	}
	else if(RoundInfo.OPerationType == enOPerationType::Mod)
	{
		ModTwoArray(RoundInfo, Arrays);

	}
	else if(RoundInfo.OPerationType == enOPerationType::Max)
	{
		MixTwoArray(RoundInfo, Arrays);
	}


}
char TypeOfOperation(stRoundInfo RoundInfo)
{
	if (RoundInfo.OPerationType == enOPerationType::Add)
		return '+';
	else if (RoundInfo.OPerationType == enOPerationType::Sub)
		return '-';
	else if (RoundInfo.OPerationType == enOPerationType::Mul)
		return '*';
	else if (RoundInfo.OPerationType == enOPerationType::Div)
		return '/';
	else if (RoundInfo.OPerationType == enOPerationType::Mod)
		return '%';
}
void PrintTheResult(int test, int truth, stRoundInfo& RoundInfo)
{
	if (test == truth)
	{
		cout << "Right Answer :-)\n";
		cout << "----------------------\n";
		system("color 2f");
		RoundInfo.Pass++;
	}
	else
	{
		cout << "Worng Answer :-(\n";
		cout << "The right answer is : " << truth << endl;
		cout << "----------------------\n";
		cout << "\a";
		system("color 4f");
		RoundInfo.Failed++;

	}

}
void Test(stRoundInfo& RoundInfo, stArrays& Arrays)
{
	int test;

	cout << "\n";
	if (RoundInfo.OPerationType == enOPerationType::Max)
	{
		for (int i = 0; i < RoundInfo.HowManyQuestions; i++)
		{
			cout << "Questions [" << RoundInfo.Tour << "/" << RoundInfo.HowManyQuestions << "]\n";
			cout << Arrays.arr1[i] << Arrays.RandomOperation[i] << Arrays.arr2[i] << " ? ";

			cin >> test;
			float FloatTest = (float(test));
			IsNumber(FloatTest);
			PrintTheResult(test, Arrays.FinelArray[i], RoundInfo);

			RoundInfo.Tour++;
		}

	}
	else
	{
		for (int i = 0; i < RoundInfo.HowManyQuestions; i++)
		{
			cout << "Questions [" << RoundInfo.Tour << "/" << RoundInfo.HowManyQuestions << "]\n";
			cout << Arrays.arr1[i] << TypeOfOperation(RoundInfo) << Arrays.arr2[i] << " ? ";
			cin >> test;
			float FloatTest = (float(test));
			IsNumber(FloatTest);
			PrintTheResult(test, Arrays.FinelArray[i], RoundInfo);
			RoundInfo.Tour++;
		}
	}


}
string stringQuestionsLevel(int level)
{
	if (level == enQuestionsLevel::Easy)
		return "Easy";
	else if (level == enQuestionsLevel::Med)
		return "Med";
	else if (level == enQuestionsLevel::Hard)
		return "Hard";
	else if (level == enQuestionsLevel::Mix)
	{
		return "Mix";
	}
}
string NameOfOpType(stRoundInfo RoundInfo)
{
	if (RoundInfo.OPerationType == enOPerationType::Add)
		return "Add";
	else if (RoundInfo.OPerationType == enOPerationType::Sub)
		return "Sub";
	else if (RoundInfo.OPerationType == enOPerationType::Mul)
		return "Mul";
	else if (RoundInfo.OPerationType == enOPerationType::Div)
		return "Div";
	else if (RoundInfo.OPerationType == enOPerationType::Mod)
		return "Mod";
	else if (RoundInfo.OPerationType == enOPerationType::Max)
		return "Mix";


}
string IsPass(int Pass, int Failed)
{
	if (Pass >= Failed)
	{
		system("color 2f");
		return "Pass";
	}
	else
	{
		system("color 4f");
		cout << "\a";
		return "Failed";
	}
}
void PrintFinalBox(stRoundInfo RoundInfo)
{
	int x;
	cout << "________________________________________\n";
	cout << "Number Of Questions : " << RoundInfo.HowManyQuestions << endl;
	cout << "Questions Level : " << stringQuestionsLevel(RoundInfo.QuestionsLevel) << endl;
	cout << "OpType : " << NameOfOpType(RoundInfo) << endl;
	cout << "You Are " << IsPass(RoundInfo.Pass, RoundInfo.Failed) << endl;
	cout << "Number Of Right Answers : " << RoundInfo.Pass << endl;
	cout << "Number Of Wrong Answers : " << RoundInfo.Failed << endl;
	cout << "________________________________________\n";

}

void Game()
{
	stRoundInfo RoundInfo;
	stArrays Arrays;
	ReadTheMainTitle(RoundInfo);
	FillArrWithSetDifficultyLevel(RoundInfo, Arrays.arr1);
	FillArrWithSetDifficultyLevel(RoundInfo, Arrays.arr2);
	TheOperations(RoundInfo, Arrays);
	Test(RoundInfo, Arrays);


	PrintFinalBox(RoundInfo);


}
void Clean()
{
	system("cls");
	system("color f");
}
void StartGame()
{
	char playAgain = 'y';
	do
	{
		Clean();
		Game();
		cout << "Do You Want Play Again Y/N ? ";
		cin >> playAgain;
		
	} while (playAgain == 'y'|| playAgain=='Y');

}
int main()
{
	srand((unsigned)time(NULL));
	StartGame();
	return 0;
}
