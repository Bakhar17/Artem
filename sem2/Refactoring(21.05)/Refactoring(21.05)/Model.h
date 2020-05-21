#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>

using std::vector;
using std::string;

class Model
{
public:
	Model();
	Model(const vector<string>&);
	void SetData(const vector<string>&);
	const vector<string> GetData()const;
	void DownloadData();
	bool IsValid()const;
	~Model();
private:
	vector<string> data_;
};

