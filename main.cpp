#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

int main()
{
    int countDay = 0;
    list<int> anchous = {3, 4, 3, 1, 2};
    int minElement = 10;

    int countMin = 0;

    while (countDay < 80) {
        list<int>::iterator p = anchous.begin();
        while (p != anchous.end()) {
            if (minElement > *p) {
                minElement = *p;
                countMin = 0;
            }
            if (minElement == *p) {
                countMin++;
            }
            p++;
        }

        p = anchous.begin();
        if (minElement == 0) {
            while (p != anchous.end()) {
                *p -= 1;
                if (*p < 0) {
                    *p = 6;
                }
                p++;
            }
        } else
            while (p != anchous.end()) {
                *p -= minElement;
                p++;
            }

        if (minElement == 0) {
            countDay++;
            for (int i = 0; i < countMin; i++) {
                anchous.push_back(8);
            }
        } else {
            countDay += minElement;
        }

        minElement = 10;
        countMin = 0;
    }

    cout << "count anchouses after 80 days = " << (int) anchous.size() << endl;
    return 0;
}
