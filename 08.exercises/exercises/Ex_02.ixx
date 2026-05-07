// Design and implement a Name_pairs class holding (name,age) pairs where name is a string and age is a double. 
// Represent that as a vector<string> (called name) and a vector<double> (called age) member. 
// Provide an input operation read_names() that reads a series of names. 
// Provide a read_ages() operation that prompts the user for an age for each name. 
// Provide a print() operation that prints out the (name[i],age[i]) pairs (one per line) in the order determined by the name vector. 
// Provide a sort() operation that sorts the name vector in alphabetical order and reorganizes the age vector to match. 
// Implement all “operations” as member functions. 
// Test the class (of course: test early and often).

export module Ex_02;

import PPP;
import functions;
using namespace std;

export void Ex_02();
//export class Name_pairs;

export class Name_pairs
{
public:
	void read_names();			// read a series of names
	void read_ages();			// 给每个名字输入年龄
	void print() const;			// 输出所有配对
	void sort();				// 重新排序
	const vector<string>& get_name() const{ return name; }
	const vector<double>& get_age() const{ return age; }
private:
	vector<string> name;
	vector<double> age;
};

void Name_pairs::read_names()
{
	string iname = "exercises/Ex_02.txt";
	ifstream ifs{ iname };
	if (!ifs)
		PPP::error("can't open input file", iname);
	ifs.exceptions(ifs.exceptions() | ios::badbit);		// throw for bad()

	while (true)
	{
		string n;
		if (!(ifs >> n))
			break;
		name.push_back(n);
	}
}

double get_age_of_name(const string& name);

void Name_pairs::read_ages()
{
	if (name.size() == 0)
		PPP::error("empty name");
	for (const string& x : name)
	{
		double num = get_age_of_name(x);
		age.push_back(num);
	}
}

bool vector_match(const vector<string>&, const vector<double>&);

void Name_pairs::print() const
{
	if (!vector_match(name, age))
		PPP::error("name and age have different sizes");
	size_t v_size = name.size();
	for (size_t i = 0; i < v_size; ++i)
	{
		cout << name[i] << '\t' << age[i] << '\n';
	}
}

void Name_pairs::sort()
{
	if (name.size() == 0)
		PPP::error("empty name");
	if (!vector_match(name, age))
		PPP::error("name and age have different sizes");
	
	vector<string> name_copy = name;
	vector<double> age_match;

	ranges::sort(name);

	size_t name_size = name.size();
	for (const string& x : name)
	{
		size_t i = 0;
		for (; i < name_size; ++i)
		{
			if (name_copy[i] == x)
			{
				age_match.push_back(age[i]);
				break;
			}
		}
		if (i == name_size)
			PPP::error("Unable to find a match name");
	}

	if (!vector_match(name, age_match))
		PPP::error("name and age have different sizes");
	age = age_match;
}

bool vector_match(const vector<string>& v1, const vector<double>& v2)
{
	if (v1.size() != v2.size())
		return false;
	return true;
}

double get_age_of_name(const string& name)
{
	cout << "Please enter the age of " << name << '\n';
	while (true)
	{
		double age = get_double();
		if (age > 0)
			return age;
		cout << "Sorry, age should be greater than 0; please try again " << '\n';
	}
}

void Ex_02()
{
	Name_pairs nps;
	nps.read_names();			// there are some default names defined in nps.name vector.
	nps.read_ages();
	nps.print();
	nps.sort();
	cout << "Name_pairs after sort: " << '\n';
	nps.print();
}
