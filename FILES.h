
#include <fstream>
void to_file(node*top,int * arr)
{
	ofstream toqafile("t1.txt");
	while (top != NULL)
	{
		toqafile << top->id << endl << top->name << endl << top->gender << endl << top->age << endl;
		top = top->next;
	}
	toqafile.close();
	toqafile.open("t2.txt");
	for (int i = 0; i < 6; i++)
	{
		toqafile << arr[i] << endl;
	}
	toqafile.close();
}
void from_file(patient *temp,int*arr )
{
	int age, id;
	string name, gender;
	ifstream toqafile("t1.txt");
	if (toqafile)
	{
		while (toqafile.peek() != ifstream::traits_type::eof())
		{
			toqafile >> id >> name >> gender >> age;
			toqafile.seekg(2,ios::cur);
			(*temp).create_new_node(id, name, gender, age);
		}
	}
	toqafile.close(); 
	toqafile.open("t2.txt");
	if (toqafile)
	{
		for (int i = 0; i < 6; i++)
		{
			toqafile >> arr[i] ;
		}
	}
	toqafile.close();
}
