#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

class String
{
private:
    char* str;
public:
    String() : str(NULL) {}

    // 문자열을 받는 생성자
    String(const char* s) {
        if (s != NULL) {
            size_t len = strlen(s) + 1;
            str = new char[len];
            strcpy(str, s);
        }
        else {
            str = NULL;
        }
    }

    ~String() {
        delete[] str;
    }

    // 복사 생성자
    String(const String& other) {
        if (other.str != NULL) {
            size_t len = strlen(other.str) + 1;
            str = new char[len];
            strcpy(str, other.str);
        }
        else {
            str = NULL;
        }
    }

    String operator+(const String& other) const {
        String result;
        if (str != NULL && other.str != NULL) {
            size_t len = strlen(str) + strlen(other.str) + 1;
            result.str = new char[len];
            strcpy(result.str, str);
            strcat(result.str, other.str);
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const String& obj) {
        if (obj.str != NULL) {
            os << obj.str;
        }
        return os;
    }

    bool operator!=(const String& other) const {
        return strcmp(str, other.str) != 0;
    }

    bool operator==(const String& other) const {
        return strcmp(str, other.str) == 0;
    }

    String& operator+=(const String& other) {
        if (other.str != NULL) {
            size_t len = strlen(str) + strlen(other.str) + 1;
            char* temp = new char[len];
            strcpy(temp, str);
            strcat(temp, other.str);

            delete[] str;
            str = temp;
        }
        return *this;
    }

    //문자열 검색 함수(찾기)
    bool search(const char* searchstr) {
        if (str != NULL && searchstr != NULL) {
            return strstr(str, searchstr) != NULL;
       }
        return false;
    }

    //문자열 자르기 함수
    String cutstr(size_t startcut, size_t len) {
        if (str != NULL && startcut < strlen(str)) {
            char* cutstr = new char[len + 1];
            strncpy(cutstr, str + startcut, len);
            cutstr[len] = '\0';

            String result(cutstr);
            delete[] cutstr;
            return result;
        }
        return String();
    }
};

int main()
{
    String s1("Kim");
    String s2(" Darin");
    String s3("Kim");

    String s4 = s1 + s2;
    printf("%s\n", s4);     //'+' 출력

    std::cout << s4 << std::endl;   //'<<' 출력

    //!=출력(다른 경우)
    if (s1 != s2) { 
        printf("Not equal.\n");
    }
    else {
        printf("Equal.\n");
    }

    //!=출력(같은 경우)
    if (s1 != s3) {
        printf("Not equal.\n");
    }
    else {
        printf("Equal.\n");
    }

    //==출력(다른 경우)
    if (s1 == s2) {
        printf("Not equal.\n");
    }
    else {
        printf("Equal.\n");
    }

    //==출력(같은 경우)
    if (s1 == s3) {
        printf("Not equal.\n");
    }
    else {
        printf("Equal.\n");
    }

    s1 += s2;
    printf("%s\n", s1);         //'+='출력

    //문자열 찾기(s4에 "rin"이라는 문자열이 있는지 검색)
    const char* searchStr = "rin";
    if (s4.search(searchStr)) {
        printf("찾은 문자열: %s\n", searchStr);
    }
    else {
        printf("찾는 문자열 없음.");
    }

    //문자열 자르기
    String s5 = "Hi, I'm darin";
    size_t startcut = 7;        //자르기 시작 위치
    size_t len = 6;             //'6'길이만큼 자름
    String cutStr = s5.cutstr(startcut, len);
    printf("%s\n", startcut, len, cutStr);
}
