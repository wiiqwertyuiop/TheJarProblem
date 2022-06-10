#include <iostream>

int main() {
    int jars[] = {5, 30, 99, 60, 5, 10};
    int sz = sizeof(jars) / sizeof(jars[0]) - 1;

    // Start from back, and choose highest number
    // Jump to valid grouping:
    //  - If the middle is the biggest use that
    //  - Otherwise add he middle ends
    //  Jump accordingly
    // If at the end, output result

    int output = 0;
    for (int i = sz; i >= -1; i -= 3) {
        int r = i + 1 < sz ? jars[i+1] : 0;
        int m = i >= 0 ? jars[i] : 0;
        int l = i - 1 >= 0 ? jars[i-1] : 0;

        if (m >= l && m >= r) {
            output += m;
        } else {
            output += l + r;
            i--;
        }
        //std::cout << l << " " << m << " " << r << std::endl;
    }

    std::cout << output;
    return 0;
}
