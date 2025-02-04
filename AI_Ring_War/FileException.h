#pragma once
#include <string>
struct FileException { //파일의 이름과 열기모드를 데이터 멤버로 갖습니다.
	string filename;
	bool bRead;
	FileException(string name, bool b) : filename(name), bRead(b) {}
};