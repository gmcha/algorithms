#include <iostream>
#include <string>
using namespace std;

int main() {
    string keyword, result = "";
    string data = "사랑,프로그래밍,의자,사랑의바보,영통역,천년의사랑,냉장고,객체지향";
    cout << "키워드 : ";
    cin >> keyword;

    int index = 0, nextcomma = 0, prevcomma = 0;
    
    do {
        index = data.find(keyword, nextcomma); // index 찾기
        for (int i = index; i >= 0; i--) { // prevcomma 찾기
            if (data.at(i) == ',') {
                prevcomma = i;
                break;
            }
        }
        nextcomma = data.find(",", index); // nextcomma 찾기
        int start;
        if (prevcomma == 0) {
            start = 0;
        }
        else {
            start = prevcomma + 1;
        }
        result = result + "\t" + data.substr(start, (nextcomma - start));


    } while (nextcomma <= data.rfind(keyword));
    
    
    cout << "검색결과 : " << result << "\n";

}
