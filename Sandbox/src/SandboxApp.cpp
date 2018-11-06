#include <JMint.h>

class Sandbox : public JMint::Application {
public:
	Sandbox() {

	}
	~Sandbox() {

	}
};
JMint::Application* JMint::CreateApplication() {
	return new Sandbox();
}
