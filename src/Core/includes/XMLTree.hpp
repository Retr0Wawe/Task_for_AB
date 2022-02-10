#include <tinyxml2.h>
#include <string>

using namespace tinyxml2;

class XMLtree 
{
private:
	XMLtree();
	~XMLtree() = default;
public:
	XMLtree(const XMLtree&) = delete;
	XMLtree(const XMLtree&&) = delete;

	XMLtree& operator=(const XMLtree&) = delete;
	XMLtree& operator=(const XMLtree&&) = delete;
private:
	std::string GetStrFromChild(const XMLElement* _elem, const char* _child_name) const;
public:
	bool Initialize(const char* _file_path);

	void AddElement(const char* _name) noexcept;

	void ChangeElement() noexcept;

	void DeleteElement() noexcept;

	void PrintTree() const noexcept;

	static XMLtree& GetInstance() noexcept { static XMLtree obj;  return obj; };
private:
	XMLDocument doc;
};