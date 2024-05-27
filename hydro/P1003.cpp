#include "cstdio"
using namespace std;

class Carpet {
    public:
    int id;         // 地毯编号
    int x1, y1;     // 地毯左下角
    int x2, y2;     // 地毯右上角

    bool is_inside(int x, int y) {
        /**
         * 判断点(x, y)是否在地毯范围内，输出true或false
        */
        return (x1 <= x && x <= x2) && (y1 <= y && y <= y2);
    }
};

int main() {
    int n;              // n张地毯
    int x, y;           // 需要判断的点坐标
    scanf("%d", &n);
    Carpet carpets[n];  // 地毯数组
    for (int i = 0; i < n; i++) {
        int width, height;
        scanf("%d %d %d %d", &carpets[i].x1, &carpets[i].y1, &width, &height);
        carpets[i].x2 = carpets[i].x1 + width;
        carpets[i].y2 = carpets[i].y1 + height;
        carpets[i].id = i + 1;
    }
    scanf("%d %d", &x, &y);

    int cover = -1;     // 覆盖点(x, y)的地毯编号, 初始为-1

    // 从最后一张地毯开始判断
    for (int i = n - 1; i >= 0; i--) {
        // 如果点(x, y)在地毯i范围内，则地毯i覆盖点(x, y)，并且这张地毯一定在最上方，可以跳出循环
        if (carpets[i].is_inside(x, y)) {
            cover = carpets[i].id;
            break;
        }
    }

    printf("%d\n", cover);
    return 0;
}