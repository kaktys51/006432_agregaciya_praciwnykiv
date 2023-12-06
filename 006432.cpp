/*
  �������� ��� ��������, ��� ���� ��� ������� �������� ����������� ��� ��,
  �� ���������� ���������� ��������� ����� ���� ����, �� ���� �� ���� ��������� �����, ������������.
  ϳ������: �������������� std::vector ��� ��������� ���������� � ����.
 �� ��������� ������ ����� ���������� ����������� ���������� � ������ ����� � �����.
*/

#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::cin;

class Worker
{
protected:
	std::string name;
	bool isworking; //����� ������� �� ������ ��������� �� �
public:
	Worker(std::string n) : name(n) { isworking = false; }
	std::string getName() { return name; }
	void hired() { isworking = true; }
	void fired() { isworking = false; }
	void status()
	{
		if (isworking == true)
			cout << name << " ��� ������!" << std::endl;
		else if (isworking == false) 
			cout << name << " �� ������!" << std::endl;
	}
};

class Department
{
protected:
	std::vector<std::shared_ptr<Worker>> staff;
public:
	void add(const std::shared_ptr<Worker>& work) //�������� �� ������ ����������
	{
		staff.push_back(work);
		work->hired();
	}
	void print()
	{
		for (int i = 0; i < staff.size(); ++i)
		{
			cout << "������� " << i + 1 << ": " << staff[i]->getName() << std::endl;
		}
	}
	void fireWorker(const std::shared_ptr<Worker>& work) //��������� ��������
	{
		for (int i = 0; i < staff.size(); ++i)
		{
			if (staff[i] == work)
			{
				staff[i]->fired();
				staff.erase(staff.begin() + i);
				break;
			}
		}
	}
};
int main()
{
	system("chcp 1251>nul");

	// ��������� ���������� ���� ������� �������� ����� Department
	auto w1 = std::make_shared<Worker>("����");
	auto w2 = std::make_shared<Worker>("������");
	auto w3 = std::make_shared<Worker>("�����");
	auto w4 = std::make_shared<Worker>("�����");
	{
		// ��������� ³��� � �������� ���������� �� ��������� ������������
		Department department; // ��������� ������ ³���
		department.add(w1);
		department.add(w2);
		department.add(w3);

		department.print();

	} // department �������� � ������ �������� � ��������� ���

	cout << std::endl;
	//��� �������� �� �� �� ���� ��������, ���� ������������� ����
	w1->status();
	w2->status();
	w3->status();
	//�� ������, �� � �� ��������
	w4->status();

	return 0;
}