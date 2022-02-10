#include <tinyxml2.h>
#include <string>

using namespace tinyxml2;

class XMLtree 
{
private:
	XMLtree();
	~XMLtree();
public:
	XMLtree(const XMLtree&) = delete;
	XMLtree(const XMLtree&&) = delete;

	XMLtree& operator=(const XMLtree&) = delete;
	XMLtree& operator=(const XMLtree&&) = delete;
private:
	std::string GetStrFromChild(const XMLElement* _elem, const char* _child_name) const;
public:
	bool Initialize(const char* _file_path);

	void AddElement(const char ch) noexcept;

	void ChangeElement() noexcept;

	void DeleteElement() noexcept;

	void PrintTree() const noexcept;

	static XMLtree& GetInstance() noexcept { static XMLtree obj;  return obj; };
private:
	XMLDocument doc;
	const char* file_path;
};