#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

class String
{
private:
    char* str;
public:
    String() : str(NULL) {}

    // ���ڿ��� �޴� ������
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

    // ���� ������
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

    //���ڿ� �˻� �Լ�(ã��)
    bool search(const char* searchstr) {
        if (str != NULL && searchstr != NULL) {
            return strstr(str, searchstr) != NULL;
       }
        return false;
    }

    //���ڿ� �ڸ��� �Լ�
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
    printf("%s\n", s4);     //'+' ���

    std::cout << s4 << std::endl;   //'<<' ���

    //!=���(�ٸ� ���)
    if (s1 != s2) { 
        printf("Not equal.\n");
    }
    else {
        printf("Equal.\n");
    }

    //!=���(���� ���)
    if (s1 != s3) {
        printf("Not equal.\n");
    }
    else {
        printf("Equal.\n");
    }

    //==���(�ٸ� ���)
    if (s1 == s2) {
        printf("Not equal.\n");
    }
    else {
        printf("Equal.\n");
    }

    //==���(���� ���)
    if (s1 == s3) {
        printf("Not equal.\n");
    }
    else {
        printf("Equal.\n");
    }

    s1 += s2;
    printf("%s\n", s1);         //'+='���

    //���ڿ� ã��(s4�� "rin"�̶�� ���ڿ��� �ִ��� �˻�)
    const char* searchStr = "rin";
    if (s4.search(searchStr)) {
        printf("ã�� ���ڿ�: %s\n", searchStr);
    }
    else {
        printf("ã�� ���ڿ� ����.");
    }

    //���ڿ� �ڸ���
    String s5 = "Hi, I'm darin";
    size_t startcut = 7;        //�ڸ��� ���� ��ġ
    size_t len = 6;             //'6'���̸�ŭ �ڸ�
    String cutStr = s5.cutstr(startcut, len);
    printf("%s\n", startcut, len, cutStr);
}
