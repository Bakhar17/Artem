#include <windows.h>
#include "resource.h"
#include "Question.h"
#include <string>
#include <sstream>
#include <fstream>
#include <vector>


int InitQuest(std::ifstream&, std::vector<Question>&);
int InitAns(std::ifstream&, std::vector<int>&);
int atnum = 0;//alternative question number

int CheckAns(const std::vector<int>&, const std::vector<int>&);//number of right answers
int GetAnswerA(HWND, int); //int — RadioButton code
int GetAnswerW(HWND, int); //int — RadioButton code
INT_PTR CALLBACK DLG(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, PSTR pCmdLine, int nCmdShow)
{
	MessageBox(0, pCmdLine, "Question list", MB_OK);
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DLG);
	return 0;
}
INT_PTR CALLBACK DLG(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	static std::vector<Question> questions;
	std::ifstream finA("Answer.txt");
	std::ifstream fin("Tasks.txt");
	std::string text;
	static std::vector<int> right_answer;
	static std::vector<std::string> answers;
	static std::vector<int> user_answer;
	int k;
	switch (message)
	{
	case WM_CLOSE:
		EndDialog(hDlg, 0);
		return (INT_PTR)TRUE;
	case WM_INITDIALOG:
		if (InitQuest(fin, questions)&&InitAns(finA,right_answer)&& questions.size()==right_answer.size()) {
			//уравнять размеры вектора с правильными ответами и ответами, которые будут заполнены тестируемым 
			for (size_t i = 0; i < right_answer.size(); i++)
			{
				user_answer.push_back(0);
			}

		ShowWindow((GetDlgItem(hDlg, IDC_BACK)), SW_HIDE);
		ShowWindow((GetDlgItem(hDlg, IDC_NEXT)), SW_HIDE);
		SetDlgItemText(hDlg, IDC_STATIC_MY1, "Нажмите кнопку \"ОК\" для начала теста.");
		for (int i = 0; i < 3; i++)
		{
			ShowWindow(GetDlgItem(hDlg, IDC_RADIO1 + i), SW_HIDE);
		}
		for (int i = 0; i < 4; i++)
		{
			ShowWindow(GetDlgItem(hDlg, IDC_CHECK2 + i), SW_HIDE);
		}
		}
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
			case IDOK:
				ShowWindow((GetDlgItem(hDlg, IDOK)), SW_HIDE);
				ShowWindow((GetDlgItem(hDlg, IDC_NEXT)), SW_SHOW);
				text = questions[0].GetQuestion();
				k = questions[0].GetNumber();
				SetDlgItemText(hDlg, IDC_STATIC_MY1, text.c_str());
				for (int i = 0; i < k; i++)
				{
					text = questions[0].GetAnswers()[i];
					SetDlgItemText(hDlg, IDC_RADIO1 + i, text.c_str());
					ShowWindow(GetDlgItem(hDlg, IDC_RADIO1 + i), SW_SHOW);
				}
				break;
			case IDC_NEXT:
			{
				atnum++;

				//запись ответов на предыдущий вопрос 
				if (!questions[atnum - 1].GetType()) {
					k = GetAnswerA(hDlg, IDC_RADIO1);
					if (k != 0) SendDlgItemMessage(hDlg, IDC_RADIO1 + k - 1, BM_SETCHECK, 0, 0);
					user_answer[atnum - 1] = k;
				}
				else {
					k = GetAnswerW(hDlg, IDC_CHECK2);
					if (k != 0) {
						int k1(k), tmp;
						while (k1) {
							tmp = k1 % 10;
							k1 /= 10;
							SendDlgItemMessage(hDlg, IDC_CHECK2 + tmp - 1, BM_SETCHECK, 0, 0);
						}

					}
					user_answer[atnum - 1] = k;
				}

				if (atnum == questions.size()) {
					k = CheckAns(user_answer,right_answer);
					char buffer[100];
					sprintf_s(buffer, "Вы ответили на все вопросы!\nВерно %i/%i", k, right_answer.size());
					MessageBox(hDlg, buffer, "Результат", MB_OK);
					EndDialog(hDlg, LOWORD(wParam));
					return (INT_PTR)TRUE;
				}

				text = questions[atnum].GetQuestion();
				SetDlgItemText(hDlg, IDC_STATIC_MY1, text.c_str());
				if (atnum == questions.size() - 1) SetDlgItemText(hDlg, IDC_NEXT, "Finish");
				ShowWindow((GetDlgItem(hDlg, IDC_BACK)), SW_SHOW);


				answers = questions[atnum].GetAnswers();
				k = questions[atnum].GetNumber();
				for (int i = 0; i < 3; i++)
				{
					ShowWindow(GetDlgItem(hDlg, IDC_RADIO1 + i), SW_HIDE);
				}
				for (int i = 0; i < 4; i++)
				{
					ShowWindow(GetDlgItem(hDlg, IDC_CHECK2 + i), SW_HIDE);
				}

				//вывод ответов
				if (!questions[atnum].GetType()) {
					for (int i = 0; i < k; i++)
					{
						text = answers[i];
						SetDlgItemText(hDlg, IDC_RADIO1 + i, text.c_str());
						ShowWindow(GetDlgItem(hDlg, IDC_RADIO1 + i), SW_SHOW);
					}
				}
				else {
				for (int i = 0; i < k; i++)
				{
					text = answers[i];
					SetDlgItemText(hDlg, IDC_CHECK2 + i, text.c_str());
					ShowWindow(GetDlgItem(hDlg, IDC_CHECK2 + i), SW_SHOW);
				}
				}





				//случай, когда на следующий вопрос уже записан ответ
				k = user_answer[atnum];
				if (k != 0) {
					if (!questions[atnum].GetType()) {
						SendDlgItemMessage(hDlg, IDC_RADIO1 + k - 1, BM_SETCHECK, 1, 0);
					}
					else {
						int k1(k), tmp;
						while (k1) {
							tmp = k1 % 10;
							k1 /= 10;
							SendDlgItemMessage(hDlg, IDC_CHECK2 + tmp - 1, BM_SETCHECK, 1, 0);
						}
					}
				}
				
				break;
			}
			case IDC_BACK:
			{

				SetDlgItemText(hDlg, IDC_NEXT, "Next");
				//запись ответов
				if (!questions[atnum].GetType()) {
					k = GetAnswerA(hDlg, IDC_RADIO1);
					if (k != 0) SendDlgItemMessage(hDlg, IDC_RADIO1 + k - 1, BM_SETCHECK, 0, 0);
					user_answer[atnum ] = k;
				}
				else {
					k = GetAnswerW(hDlg, IDC_CHECK2);
					if (k != 0) {
						int k1(k), tmp;
						while (k1) {
							tmp = k1 % 10;
							k1 /= 10;
							SendDlgItemMessage(hDlg, IDC_CHECK2 + tmp - 1, BM_SETCHECK, 0, 0);
						}

					}
					user_answer[atnum ] = k;
				}


				atnum--;
				//вывод вопроса
				text = questions[atnum].GetQuestion();
				SetDlgItemText(hDlg, IDC_STATIC_MY1, text.c_str());

				answers = questions[atnum].GetAnswers();
				k = questions[atnum].GetNumber();
				for (int i = 0; i < 3; i++)
				{
					ShowWindow(GetDlgItem(hDlg, IDC_RADIO1 + i), SW_HIDE);
				}
				for (int i = 0; i < 4; i++)
				{
					ShowWindow(GetDlgItem(hDlg, IDC_CHECK2 + i), SW_HIDE);
				}

				//вывод ответов 
				if (!questions[atnum].GetType()) {
					for (int i = 0; i < k; i++)
					{
						text = answers[i];
						SetDlgItemText(hDlg, IDC_RADIO1 + i, text.c_str());
						ShowWindow(GetDlgItem(hDlg, IDC_RADIO1 + i), SW_SHOW);
					}
				}
				else {
					for (int i = 0; i < k; i++)
					{
						text = answers[i];
						SetDlgItemText(hDlg, IDC_CHECK2 + i, text.c_str());
						ShowWindow(GetDlgItem(hDlg, IDC_CHECK2 + i), SW_SHOW);
					}
				}


				if (atnum == 0) {
					ShowWindow((GetDlgItem(hDlg, IDC_BACK)), SW_HIDE);
				}

				///случай, когда ответы уже записаны
				k = user_answer[atnum];
				if (k != 0) {
					if(!questions[atnum].GetType())
					SendDlgItemMessage(hDlg, IDC_RADIO1 + k - 1, BM_CLICK,1, 0);
					else {
						int k1(k), tmp;
						while (k1) {
							tmp = k1 % 10;
							k1 /= 10;
							SendDlgItemMessage(hDlg, IDC_CHECK2 + tmp - 1, BM_SETCHECK, 1, 0);
						}
					}
				}

				break;
			}
		}
	}
	return (INT_PTR)FALSE;
}


int CheckAns(const std::vector<int>& user,const std::vector<int>& answer) {
	int k = 0;
	for (size_t d = 0; d < answer.size(); d++)
	{
		if (user[d] == answer[d]) ++k;
	}
	return k;
}

int GetAnswerA(HWND hDlg, int radio) {
	for (int i = 0; i < 3; i++)
	{
		if (SendDlgItemMessage(hDlg, radio + i, BM_GETCHECK, 0, 0)) {
			return (i + 1);
		}
	}
	return 0;
}
int GetAnswerW(HWND hDlg, int check) {
	int answer = 0;
	for (int i = 0; i < 4; i++)
	{
		if (SendDlgItemMessage(hDlg, check + i, BM_GETCHECK, 0, 0)) {
			answer += (i + 1);
			answer *= 10;
		}
	}
	if (answer != 0) return (answer / 10);
	return 0;
}

int InitQuest(std::ifstream& fin, std::vector<Question>& question) {
	if (fin.is_open()) {
		std::string quest;
		std::string temp;
		int k;
		bool type;

	while (!fin.eof()) {
		std::vector<std::string> answer;
		getline(fin, quest);
		getline(fin, temp);
		k = std::stoi(temp);
		getline(fin, temp);
		type= std::stoi(temp);
		for (int i = 0; i < k; i++)
		{
			getline(fin, temp);
			answer.push_back(temp);
		}
		Question quest(quest, k, type, answer);
		question.push_back(quest);
	}
	return 1;
	}
	return 0;
}

int InitAns(std::ifstream& fin, std::vector<int>& answer) {
	if (fin.is_open()) {
		std::string temp;
		int k;

		while (!fin.eof()) {
			getline(fin, temp);
			k = std::stoi(temp);
			answer.push_back(k);
		}
		return 1;
	}
	return 0;
}
