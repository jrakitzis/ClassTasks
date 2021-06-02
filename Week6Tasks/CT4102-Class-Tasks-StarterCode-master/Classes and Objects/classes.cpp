#include <iostream>
#include <string>
using namespace std;

class FirstClass{
	public:
		void setName(string x) {
			name = x;
		}
		string getName()
		{
			return name;
		}
	private:
		string name;
		
};


int main()
{
	FirstClass jo;
	jo.setName("Jonathan Rakitzis");
	cout << jo.getName();

	return 0;
}