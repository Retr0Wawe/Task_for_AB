#include <tinyxml2.h>

using namespace tinyxml2;

class XMLtree //make like singlton!!!!
{
public:
	XMLtree(const char* _filename);

	~XMLtree();
public:
	void AddElement() noexcept;

	void DeleteElement() noexcept;

	const XMLDocument& GetDocument() const noexcept { return doc; }
protected:
	XMLDocument doc;
	bool IsInit;
};