#include<iostream>
#include<fstream>
#include<map>
#include<list>
using namespace std;

#define delimiter "\n------------------------------------------\n"

const std::map<int, std::string> VIOLATIONS =
{
	{0, "N/A"},
	{1, "Парковка в неположенном месте"},
	{2, "Непристегнутый ремень безопасности"},
	{3, "Пересечение сплошной"},
	{4, "Превышение скорости"},
	{5, "Проезд на красный"},
	{6, "Выезд на встречную полосу"},
	{7, "Езда в нетрезвом виде"},
	{8, "Оскорбление офицера"},

};

class Crime
{
	int violation;
	std::string place;
public:
	int get_violation() const
	{
		return violation;
	}
	const std::string& get_place()const
	{
		return place;
	}
	void set_violation(int violation)
	{
		this->violation = violation;
	}
	void set_place( const std::string& place)
	{
		this->place = place;
	}
	Crime(int violation, const std::string& place)
	{
		set_violation( violation);
		set_place(place);
	}
};

std::ostream& operator<<(std::ostream& os, const Crime& obj)
{
	os.width(44);
	os << std::left;
	return os << VIOLATIONS.at(obj.get_violation()) << obj.get_place();
}

void print(const std::map<std::string, std::list<Crime>>& base);
void save(const std::map<std::string, std::list<Crime>>& base, const std::string& filename);

void main()
{
	setlocale(LC_ALL, "");
	std::map<std::string, std::list<Crime>> base =
	{
		{"А777АА", {Crime(4, "Lenina street 3"), Crime (5, "Lenina street"), Crime(7, "Entuziastov street"), Crime(8, "Entuziastov street")}},
		{"А123BB", {Crime(2, "Proletarskaya street"), Crime(7, "Vatutina street")}},
		{"А001EB", {Crime(5, "Octyabrskaya street"), Crime(7, "Space street")}}
	
	};
	print(base);
	save(base, "base.txt");
}

void print(const std::map<std::string, std::list<Crime>>& base)
{
	for (std::map<std::string, std::list<Crime>>::const_iterator plate = base.begin(); plate != base.end(); ++plate)
	{
		cout << plate->first << ":\n";
		for (std::list<Crime>::const_iterator violation = plate->second.begin(); violation != plate->second.end(); ++violation)
		{
			cout << "\t" << *violation << endl;
		}
		cout << delimiter << endl;
	}
}

void save(const std::map<std::string, std::list<Crime>>& base, const std::string& filename)
{
	std::ofstream fout(filename);
	for (std::map<std::string, std::list<Crime>>::const_iterator plate = base.begin(); plate != base.end(); ++plate)
	{
		fout << plate->first << ":\n";
		for (std::list<Crime>::const_iterator violation = plate->second.begin(); violation != plate->second.end(); ++violation)
		{
			fout << "\t" << *violation << endl;
		}
		fout << delimiter << endl;
	}
	fout.close();
	std::string cmd = "notepad ";
	cmd += filename;
	system(cmd.c_str());
}