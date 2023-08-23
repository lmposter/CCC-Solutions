#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int X, Y;
    cin >> X;

    unordered_map<string, string> sameGroup;
    for (int i = 0; i < X; ++i) {
        string name1, name2;
        cin >> name1 >> name2;
        sameGroup[name1] = name2;
        sameGroup[name2] = name1;
    }

    cin >> Y;

    unordered_set<string> notSameGroup;
    for (int i = 0; i < Y; ++i) {
        string name1, name2;
        cin >> name1 >> name2;
        notSameGroup.insert(name1 + name2);
        notSameGroup.insert(name2 + name1);
    }

    int G;
    cin >> G;

    int violations = 0;
    for (int i = 0; i < G; ++i) {
        string name1, name2, name3;
        cin >> name1 >> name2 >> name3;

        if (sameGroup.count(name1) && (sameGroup[name1] != name2 && sameGroup[name1] != name3))
            ++violations;
        if (sameGroup.count(name2) && (sameGroup[name2] != name1 && sameGroup[name2] != name3))
            ++violations;
        if (sameGroup.count(name3) && (sameGroup[name3] != name1 && sameGroup[name3] != name2))
            ++violations;

        if (notSameGroup.count(name1 + name2) || notSameGroup.count(name2 + name1))
            ++violations;
        if (notSameGroup.count(name1 + name3) || notSameGroup.count(name3 + name1))
            ++violations;
        if (notSameGroup.count(name2 + name3) || notSameGroup.count(name3 + name2))
            ++violations;
    }

    cout << violations << endl;

    return 0;
}