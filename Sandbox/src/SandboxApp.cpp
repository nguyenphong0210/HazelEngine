#include <Hazel.h>

class Sandbox : public Hazel::Application
{
public:
	Sandbox(){}
	~Sandbox(){}

private:

};

int main()
{
	Sandbox* sanbox = new Sandbox();
	sanbox->Run();
	delete sanbox;
}