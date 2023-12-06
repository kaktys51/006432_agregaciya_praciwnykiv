/*
  Допишіть код програми, щоб вона без помилок виводила повідомлення про те,
  що працівники продовжуть працювати навіть після того, як відділ де вони працювали раніше, розформовано.
  Підказка: Використовуйте std::vector для зберігання працівників у відділі.
 На додаткову оцінку можна реалізувати переведення працівника з одного відділа в інший.
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
	bool isworking; //змінна показуе чи працюе працівник чи ні
public:
	Worker(std::string n) : name(n) { isworking = false; }
	std::string getName() { return name; }
	void hired() { isworking = true; }
	void fired() { isworking = false; }
	void status()
	{
		if (isworking == true)
			cout << name << " досі працює!" << std::endl;
		else if (isworking == false) 
			cout << name << " не працює!" << std::endl;
	}
};

class Department
{
protected:
	std::vector<std::shared_ptr<Worker>> staff;
public:
	void add(const std::shared_ptr<Worker>& work) //наймання на роботу працівника
	{
		staff.push_back(work);
		work->hired();
	}
	void print()
	{
		for (int i = 0; i < staff.size(); ++i)
		{
			cout << "Робітник " << i + 1 << ": " << staff[i]->getName() << std::endl;
		}
	}
	void fireWorker(const std::shared_ptr<Worker>& work) //звільнення робітника
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

	// Створюємо Працівників поза областю видимості класу Department
	auto w1 = std::make_shared<Worker>("Антін");
	auto w2 = std::make_shared<Worker>("Івасик");
	auto w3 = std::make_shared<Worker>("Євген");
	auto w4 = std::make_shared<Worker>("Їржик");
	{
		// Створюємо Відділ і передаємо Працівників як параметри конструктора
		Department department; // створюємо пустий Відділ
		department.add(w1);
		department.add(w2);
		department.add(w3);

		department.print();

	} // department виходить з області видимості і знищується тут

	cout << std::endl;
	//Досі працюють бо їх не було звільнено, лише розформованно відділ
	w1->status();
	w2->status();
	w3->status();
	//Не працюе, бо і не працював
	w4->status();

	return 0;
}