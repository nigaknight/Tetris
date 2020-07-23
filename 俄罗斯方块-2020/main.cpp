#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>

using namespace sf;

// 七种俄罗斯方块的表示
int block[7][4] = {
	1, 3, 5, 7,
	2, 4, 5, 7,
	3, 5, 4, 6,
	3, 5, 4, 7,
	2, 3, 5, 7,
	3, 5, 7, 6,
	2, 3, 4, 5,
};

// 俄罗斯方块在图形中的坐标
struct Point {
	int x;
	int y;
} curBlock [4];

// 当前方块的种类
int blockIndex;

// 生成一个新方块
void newBlock() {
	blockIndex = rand() % 7 + 1;
	int n = blockIndex - 1;
	for (int i = 0; i < 4; i++) {
		curBlock[i].x = block[n][i] % 2;
		curBlock[i].y = block[n][i] / 2;
	}
}

int main() {

	// 生成随机数种子
	srand(time(0));

	// 设置界面
	RenderWindow window(VideoMode(340, 409), "Wjy-2020");

	// 加载背景图片并绘制
	Texture t1;
	t1.loadFromFile("Image/background.jpg");
	Sprite spriteBg(t1);
	window.draw(spriteBg);

	// 显示界面
	window.display();

	system("pause");
	return 0;
}