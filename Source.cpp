#define _CRT_SECURE_NO_WARNINGS
#include<windows.h>
#include<stdio.h>
#include<iostream>
#include<conio.h>
#include<string>
#include<string.h>

using namespace std;
int i=0;

void file (int a)
{
	if ((a % 100 == 11) || (a % 100 == 12) || (a % 100 == 13) || (a % 100 == 14)) cout << "файлов будет удалено безвозвратно.\n";
	else if ((a % 10 == 0) || (a % 10 == 5) || (a % 10 == 6) || (a % 10 == 7) || (a % 10 == 8) || (a % 10 == 9)) cout << "файлов будет удалено безвозвратно.\n";
	else if (a % 10 == 1) cout << "файл будет удалён безвозвратно.\n";
	else if ((a % 10 == 2) || (a % 10 == 3) || (a % 10 == 4))cout << "файла будет удалено безвозвратно.\n";
}

int deleteFileRand(FILE* file, size_t size)
{
	if (file == NULL) return 0;
	HCRYPTPROV hProv;
	unsigned char c;
	BOOL a;
	int b;
	a = CryptAcquireContext(&hProv, 0, 0, PROV_RSA_FULL, 0);
	if (a == 0)
	{
		cout << "  deleteFileRand_CryptAqureContext_ERROR\n";
		return 0;
	}
	a = CryptGenRandom(hProv, 1, &c);
	if (a == 0)
	{
		cout << "  deleteFileRand_CryptGenRandom_ERROR\n";
		return 0;
	}
	a = CryptReleaseContext(hProv, 0);
	if (a == 0)
	{
		cout << "  deleteFileRand_CryptReleaseContext_ERROR\n";
		return 0;
	}
	for (int t = 0; t < size; t++)
	{
		b = fprintf(file,"%c", c);
		if (b < 0)
		{
			cout << "  deleteFileRand_fprintf_ERROR\n";
			return 0;
		}
	}
	b = fseek(file, 0, SEEK_SET);
	if (b != 0)
	{
		cout << "  deleteFileRand_fseek_ERROR\n";
		return 0;
	}
	return 1;
}

int deleteFile(FILE* file, size_t size, char a, char b, char c)
{
	if (file == NULL) return 0;
	int t = 0, d = 0;
	while(1)
	{
		d = fprintf(file,"%c",a);
		if (d < 0)
		{
			cout << "  deleteFile_fprintf_ERROR\n";
			return 0;
		}
		t++;
		if (t == size) break;
		d = fprintf(file, "%c", b);
		if (d < 0)
		{
			cout << "  deleteFile_fprintf_ERROR\n";
			return 0;
		}
		t++;
		if (t == size) break;
		d = fprintf(file, "%c", c);
		if (d < 0)
		{
			cout << "  deleteFile_fprintf_ERROR\n";
			return 0;
		}
		t++;
		if (t == size) break;
	}
	d = fseek(file, 0, SEEK_SET);
	if (d != 0)
	{
		cout << "  deleteFile_fseek_ERROR\n";
		return 0;
	}
	return 1;
}

void algorithm(string str,size_t size)
{
	int t = 0;
	cout << "  - " << str;
	FILE* file = fopen(str.c_str(), "wb");
	cout << "  [       ]";
	if (file == NULL)
	{
		cout << "  algorithm_fopen_ERROR\n";
		return;
	}
	for(int i=0;i<4;i++)
	{
		t = deleteFileRand(file,size);
		if (t == 0) return;
	}
	t = deleteFile(file, size, 85, 85, 85);
	if (t == 0) return;
	for (t = 0; t<9; t++) cout << "\b";
	cout << "[•      ]";
	t = deleteFile(file, size, 170, 170, 170);
	if (t == 0) return;
	t = deleteFile(file, size, 146, 73, 36);
	if (t == 0) return;
	t = deleteFile(file, size, 73, 36, 146);
	if (t == 0) return;
	t = deleteFile(file, size, 36, 146, 73);
	if (t == 0) return;
	t = deleteFile(file, size, 0, 0, 0);
	if (t == 0) return;
	for (t = 0; t<9; t++) cout << "\b";
	cout << "[••     ]";
	t = deleteFile(file, size, 17, 17, 17);
	if (t == 0) return;
	t = deleteFile(file, size, 34, 34, 34);
	if (t == 0) return;
	t = deleteFile(file, size, 51, 51, 51);
	if (t == 0) return;
	t = deleteFile(file, size, 68, 68, 68);
	if (t == 0) return;
	t = deleteFile(file, size, 85, 85, 85);
	if (t == 0) return;
	for (t = 0; t<9; t++) cout << "\b";
	cout << "[•••    ]";
	t = deleteFile(file, size, 102, 102, 102);
	if (t == 0) return;
	t = deleteFile(file, size, 119, 119, 119);
	if (t == 0) return;
	t = deleteFile(file, size, 136, 136, 136);
	if (t == 0) return;
	t = deleteFile(file, size, 153, 153, 153);
	if (t == 0) return;
	t = deleteFile(file, size, 170, 170, 170);
	if (t == 0) return;
	for (t = 0; t<9; t++) cout << "\b";
	cout << "[••••   ]";
	t = deleteFile(file, size, 187, 187, 187);
	if (t == 0) return;
	t = deleteFile(file, size, 204, 204, 204);
	if (t == 0) return;
	t = deleteFile(file, size, 221, 221, 221);
	if (t == 0) return;
	t = deleteFile(file, size, 238, 238, 238);
	if (t == 0) return;
	t = deleteFile(file, size, 255, 255, 255);
	if (t == 0) return;
	for (t = 0; t<9; t++) cout << "\b";
	cout << "[•••••  ]";
	t = deleteFile(file, size, 146, 73, 36);
	if (t == 0) return;
	t = deleteFile(file, size, 73, 36, 146);
	if (t == 0) return;
	t = deleteFile(file, size, 36, 146, 73);
	if (t == 0) return;
	t = deleteFile(file, size, 109, 182, 219);
	if (t == 0) return;
	t = deleteFile(file, size, 182, 219, 109);
	if (t == 0) return;
	for (t = 0; t<9; t++) cout << "\b";
	cout << "[•••••• ]";
	t = deleteFile(file, size, 219, 109, 182);
	if (t == 0) return;
	for (int i = 0; i<4; i++)
	{
		t = deleteFileRand(file, size);
		if (t == 0) return;
	}
	for (t = 0; t<9; t++) cout << "\b";
	cout << "[•••••••]\n";
	t = fclose(file);
	if (t == EOF)
	{
		cout << "  algorithm_fopen_ERROR\n";
		return;
	}
}

int recursion(string str, int p)
{
	int t = 0;
	size_t size = 0;
	setlocale(LC_ALL, "Russian");
	WIN32_FIND_DATA FindFileData;
	HANDLE hf=FindFirstFile((str + "\\*.*").c_str(), &FindFileData);
	if (hf != INVALID_HANDLE_VALUE)
	{
		do
		{
			string name = FindFileData.cFileName;
			if (name != "." && name != "..")
			{
				if (p == 1)
				{
					if ((FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0)
					{
						t = recursion(str + "\\" + name, 1);
						if (t == 0)
						{
							cout << "  recursion_1_ERROR";
							return 0;
						}

					}
					else
					{
						cout <<"  - "<< str + "\\" + FindFileData.cFileName << " " << FindFileData.nFileSizeLow << " байт" << "\n";
						i++;
					}
				}
				if (p == 2)
				{
					if ((FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0)
					{
						t = recursion(str + "\\" + name, 2);
						if (t == 0)
						{
							cout << "  recursion_2_ERROR";
							return 0;
						}
					}
					else
					{
						size = FindFileData.nFileSizeLow;
						if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_READONLY)
						{
							FindFileData.dwFileAttributes &= ~FILE_ATTRIBUTE_READONLY;
							t = SetFileAttributes((str + "\\" + name).c_str(), FindFileData.dwFileAttributes);
							if (t == 0) return 0;
						}
						algorithm(str + "\\" + name, size);
						t = remove((str + "\\" + name).c_str());
						if (t != 0)
						{
							cout << "  recursion_remove_ERROR";
							return 0;
						}
					}
				}
			}
		} while (FindNextFile(hf, &FindFileData) != 0);
		if (p == 2)
		{
			if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_READONLY)
			{
				FindFileData.dwFileAttributes &= ~FILE_ATTRIBUTE_READONLY;
				t = SetFileAttributes(str.c_str(), FindFileData.dwFileAttributes);
				if (t == 0) return 0;
			}
			t = RemoveDirectory(str.c_str());
			if (t == 0)
			{
				cout << "  recursion_Directory_ERROR";
				return 0;
			}
		}
	}
	else
	{
		hf = FindFirstFile((str).c_str(), &FindFileData);
		if (hf == INVALID_HANDLE_VALUE)
		{
			cout << "  Файл не был найден, попробуйте ещё раз.\n";
			return 0;
		}
		if (p == 1)
		{
			cout <<"  -"<< str << " " << FindFileData.nFileSizeLow << " байт" << "\n";
			i++;
		}
		if (p == 2)
		{
			size = FindFileData.nFileSizeLow;
			if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_READONLY)
			{
				FindFileData.dwFileAttributes &= ~FILE_ATTRIBUTE_READONLY;
				t = SetFileAttributes(str.c_str(), FindFileData.dwFileAttributes);
				if (t == 0) return 0;
			}
			algorithm(str, size);
			t = remove((str).c_str());
			if (t != 0)
			{
				cout << "  recursion_remove_ERROR";
				return 0;
			}
		}
	}
	t = FindClose(hf);
	if (t == 0)
	{
		cout << " recursion_FindClose_ERROR";
		return 0;
	}
	return 1;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int t = 0;
	string str;
	while (t != 1)
	{
		cout << "  Введите путь к файлу (C:\\Users\\Admin\\examle\\example.txt) или папке (C:\\Users\\Admin\\examle)\n->";
		getline(cin, str);
		if(strlen(str.c_str())>0)t = recursion(str,1);
		else cout << "  Файл не был найден, попробуйте ещё раз.\n";
	}
	cout << "  " << i << " ";
	file(i);
	string k;
	while ((k != "Y") || (k != "y") || (k != "N") || (k != "n"))
	{
		cout << "  Вы уверены? (Y/N)\n->";
		getline(cin, k);
		if ((k == "Y") || (k == "y"))
		{
			cout << "  Вы точно уверены? (Y/N)\n->";
			cin >> k;
			if ((k == "Y") || (k == "y"))
			{
				cout << "  Ждите...\n";
				t = recursion(str, 2);
				if (t == 0)
				{
					_getch();
					return 0;
				}
				cout << "  Успешно.";
				break;
			}
			else if ((k == "N") || (k == "n"))
			{
				cout << "  Отмена.";
				break;
			}
		}
		else if ((k == "N") || (k == "n"))
		{
			cout << "  Отмена.";
			break;
		}
		cout << "  Некорректно введены данные, попробуйте ещё раз.\n";
	}
	_getch();
}