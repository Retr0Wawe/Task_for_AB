#include <tinyxml2.h>

using namespace tinyxml2;

class XMLtree 
{
private:
	XMLtree() = default;
	~XMLtree() = default;
public:
	XMLtree(const XMLtree&) = delete;
	XMLtree(const XMLtree&&) = delete;

	XMLtree& operator=(const XMLtree&) = delete;
	XMLtree& operator=(const XMLtree&&) = delete;
public:
	bool Initialize(const char* _file_path) noexcept;

	void AddElement() noexcept;

	void DeleteElement() noexcept;

	void PrintTree() const noexcept;

	static XMLtree& GetInstance() noexcept { static XMLtree obj;  return obj; };
protected:
	XMLDocument doc;
};