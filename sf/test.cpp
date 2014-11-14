#pragma execution_character_set("utf-8")
#include <stdio.h>
#include <msxml.h>
#include <comutil.h>
#pragma comment(lib, "comsuppwd.lib") 

void main()
{
	IXMLDOMDocument.get_url("./data/s.xml");

	printf("a");
	getchar();
}