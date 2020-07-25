#include "Name.h"
#include<string>

Name::Name()
{
	pr_fname = nullptr;
	pr_lname = nullptr;
}

Name::Name(const char* fname, const char* lname)
{
	pr_fname = new char[strlen(fname) + 1];
	for (int i = 0; fname[i] != '\0'; i++)
	{
		pr_fname[i] = fname[i];
	}
	pr_fname[strlen(fname)] = '\0';

	pr_lname = new char[strlen(lname) + 1];
	for (int i = 0; lname[i] != '\0'; i++)
	{
		pr_lname[i] = lname[i];
	}
	pr_lname[strlen(lname)] = '\0';
}

Name::Name(Name& obj_in)
{
	int size = 0;

	if (obj_in.pr_fname != nullptr)
	{
		for (int i = 0; obj_in.pr_fname[i] != '\0'; i++)
		{
			size++;
		}
		pr_fname = new char[(size) + 1];
		for (int i = 0; i < size; i++)
		{
			pr_fname[i] = obj_in.pr_fname[i];
		}
		pr_fname[size] = '\0';
	}
	else
	{
		pr_fname = nullptr;
	}

	size = 0;

	if (obj_in.pr_lname != nullptr)
	{
		for (int i = 0; obj_in.pr_lname[i] != '\0'; i++)
		{
			size++;
		}
		pr_lname = new char[(size) + 1];
		for (int i = 0; i < size; i++)
		{
			pr_lname[i] = obj_in.pr_lname[i];
		}
		pr_lname[size] = '\0';
	}
	else
	{
		pr_lname = nullptr;
	}
}

void Name::Set_person_name(const char* fname, const char*lname)
{

	pr_fname = new char[strlen(fname) + 1];
	for (int i = 0; fname[i] != '\0'; i++)
	{
		pr_fname[i] = fname[i];
	}
	pr_fname[strlen(fname)] = '\0';

	pr_lname = new char[strlen(lname) + 1];
	for (int i = 0; lname[i] != '\0'; i++)
	{
		pr_lname[i] = lname[i];
	}
	pr_lname[strlen(lname)] = '\0';
}

void Name::Set_fname(const char* fname)
{
	pr_fname = new char[strlen(fname) + 1];
	for (int i = 0; fname[i] != '\0'; i++)
	{
		pr_fname[i] = fname[i];
	}
	pr_fname[strlen(fname)] = '\0';
}

void Name::Set_lname(const char* lname)
{
	pr_lname = new char[strlen(lname) + 1];
	for (int i = 0; lname[i] != '\0'; i++)
	{
		pr_lname[i] = lname[i];
	}
	pr_lname[strlen(lname)] = '\0';
}

void Name::CopyName(Name& obj_in)
{
	int size = 0;

	if (obj_in.pr_fname != nullptr)
	{
		for (int i = 0; obj_in.pr_fname[i] != '\0'; i++)
		{
			size++;
		}
		pr_fname = new char[(size)+1];
		for (int i = 0; i < size; i++)
		{
			pr_fname[i] = obj_in.pr_fname[i];
		}

		pr_fname[size] = '\0';
	}
	else
	{
		pr_fname = nullptr;
	}

	size = 0;

	if (obj_in.pr_lname != nullptr)
	{
		for (int i = 0; obj_in.pr_lname[i] != '\0'; i++)
		{
			size++;
		}
		pr_lname = new char[(size)+1];
		for (int i = 0; i < size; i++)
		{
			pr_lname[i] = obj_in.pr_lname[i];
		}

		pr_lname[size] = '\0';
	}
	else
	{
		pr_lname = nullptr;
	}
}

const char* Name::Get_fname()
{
	return pr_fname;
}

const char* Name::Get_lname()
{
	return pr_lname;
}

ostream& operator<<(ostream& out, Name& obj_in)
{
	if (obj_in.pr_fname != nullptr && obj_in.pr_lname != nullptr)
	{
		out << obj_in.pr_fname << " " << obj_in.pr_lname << endl;
	}
	return out;
}

Name::~Name()
{
	if (pr_fname != nullptr)
	{
		delete[]pr_fname;
	}

	if (pr_lname != nullptr)
	{
		delete[]pr_lname;
	}
}
